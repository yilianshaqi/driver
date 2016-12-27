/*************************************************************************
    > File Name: dev.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年11月21日 星期一 19时20分30秒
 ************************************************************************/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/poll.h>
    //异步通知设定
#define DEV_MAJOR  200
#define DEV_MINOR  512
#define DEV_COUNT  1
#define BUF_SIZE   100
struct cdev  mycdev;
struct class *myclass=NULL;
struct device *mydevice=NULL;
int source_count=0;
wait_queue_head_t my_queue;
char buf[BUF_SIZE]="";
struct fasync_struct *my_fasync=NULL;





//设备操作集功能的实现
  //fcntl
int m_fasync (int fd, struct file *file, int mode)
{
	fasync_helper(fd,file,mode,&my_fasync);
	return 0;
}
  //poll
unsigned int my_poll (struct file *dfile, struct poll_table_struct *dpoll_table)
{

	unsigned int mymask=0;
	printk("come to poll\n");
	poll_wait(dfile,&my_queue,dpoll_table);//加入等待队列
	//判断是否满足请求
	if(source_count>0)
	{
		mymask=mymask |  POLLPRI | POLLRDNORM  ;
	}
	printk("bye polmymask =%d\t source_count=%d\n",mymask,source_count);
	return mymask;
}

  //open
static int my_open(struct inode *inode, struct file *file)
{
	printk("open ok\n");
	return 0;
}

  //close
static int my_close(struct inode *inode, struct file *file)
{
	printk("close file\n");
	return 0;
}

  //read
ssize_t my_read (struct file *file, char __user *to, size_t len, loff_t *pos)
{
	printk("come to read\n");
	if(file->f_flags & O_NONBLOCK )
	{
		if(source_count<=0)
		{
			return -EAGAIN;
		}
	}
	else 
	{
	//没有数据可读时阻塞
		if(source_count<=0)
		{
			printk("wait_event\n");
	//		wait_event(my_queue,source_count>0);
			wait_event_interruptible(my_queue,source_count>0);
		}
	}
	if(source_count<len)
	{
		copy_to_user(to,buf,source_count);
		source_count =0;
		return source_count;
	}
	else{
		copy_to_user(to,buf,len);
		source_count-=len;
		printk("bye read to= %s\n",to);
		return len;
	}
}

  //write
ssize_t my_write (struct file *file, const char __user *from, size_t len, loff_t *pos)
{
	printk("write ok\n");

	copy_from_user(buf,from,len);
	source_count+=len;
	//有数据可读时唤醒
	if(source_count>0)
	{
		wake_up(&my_queue);
		kill_fasync(&my_fasync,SIGIO,POLL_IN);
		printk("bye write buf=%s\t source_count=%d\n",buf,source_count);
	}
	return len;
}

	struct file_operations operate={
	.owner = THIS_MODULE,
	.open=my_open,
	.release=my_close,
	.write=my_write,
	.read=my_read,
	.poll=my_poll,
	.fasync=m_fasync,
	};
//模块加载
int dev_module_init(void)
{
	int ret;

  //驱动号申请
	ret=register_chrdev_region(MKDEV(DEV_MAJOR,DEV_MINOR),DEV_COUNT,"test_dev");
	if(ret<0)
	{
		printk("request failer\n");
		return -1;
	}
  //设备初始化
	cdev_init(&mycdev,&operate);
  //设备注册
	cdev_add(&mycdev,MKDEV(DEV_MAJOR,DEV_MINOR),DEV_COUNT);
	printk("init ok\n");

	init_waitqueue_head(&my_queue);    //阻塞链表头初始化

	//自动创建设备
	myclass=class_create(THIS_MODULE,"test_dev");
	if(IS_ERR(myclass))
	{
		ret = PTR_ERR(myclass);
		goto DEV_DESTROY;
	}
	mydevice = device_create(myclass,NULL,MKDEV(DEV_MAJOR,DEV_MINOR),NULL,"test_dev");
	if(NULL==mydevice)
	{
		printk("device create error\n");
		goto CLASS_DESTROY;
	}
	init_waitqueue_head(&my_queue);

	return 0;
	CLASS_DESTROY:
		class_destroy(myclass);
	DEV_DESTROY:
		cdev_del(&mycdev);
		unregister_chrdev_region(MKDEV(DEV_MAJOR,DEV_MINOR),DEV_COUNT);  
		return ret;  
}


//模块卸载
void dev_module_exit(void)
{
	device_destroy(myclass,MKDEV(DEV_MAJOR,DEV_MINOR));
	class_destroy(myclass);
  //设备注销
	cdev_del(&mycdev);
  //设备号注销
	unregister_chrdev_region(MKDEV(DEV_MAJOR,DEV_MINOR),DEV_COUNT);

}
MODULE_LICENSE("GPL");
module_init(dev_module_init);
module_exit(dev_module_exit);
