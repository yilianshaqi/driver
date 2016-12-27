/*************************************************************************
    > File Name: led.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年12月26日 星期一 20时20分38秒
 ************************************************************************/

//模块初始化
//初始化设备
//注册设备
//自动添加设备
#define BASEMINOR 20 
#define COUNT 5
dev_t leddev = 0;
const char dev_name[]="led";
struct file_operations {
	.owner = THIS_MODULE;
	.open = led_open;
	.relase = led_close;
	.
}
int led_init(void)
{
	//申请设备号
	
	int ret = alloc_chrdev_region(&leddev,BASEMINOR,COUNT,dev_name);			if(!ret)
	{
		printk("led init false\n");
		return 0;
	}
	
}
void led_exit(void)
{

}
MODULE_LICENSE("GPL");
module_init(led_init);
module_exit(led_init);
