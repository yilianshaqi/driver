/*************************************************************************
    > File Name: net.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年11月25日 星期五 18时55分45秒
 ************************************************************************/


#include <linux/kernel.h>

#include <linux/module.h>

#include <linux/fs.h>

#include <linux/uaccess.h>

#include <linux/netdevice.h>

#include <linux/etherdevice.h>



  struct dev_device_ops net_device_ops;
struct net_device *net_device;

static int my_probe(struct platform_device *pd){
	
	int ret=0;
	//net_device 构建
	net_device=alloc_netdev(0,"test_device",ether_setup);
	if(NULL==net_device)
	{
		printk("alloc error\n");
		return -1;
	}
	//初始化net_device 
	net_device->netdev_ops = &net_device_ops;

	//注册net_deviec
	ret = register_netdev(net_device);
	if(ret<0)
	{
		free_netdev(net_device);
		return -1;
	}
	
	printk("probe ok\n");
	return 0;
}
static int my_remove(struct platform_device *pd){
	printk("remove  ok\n");
	return 0;	
}

static struct platform_driver  my_driver={
//	.driver={
//		.name = "test_driver",
//		.owner = THIS_MODULE,
//		.of_match_table = compatible,
//	},
//	.probe = my_probe,
//	.remove =my_remove,
};


MODULE_LICENSE("GPL");
module_platform_driver(my_driver);   //宏定义实现了模块的平台的创建和卸载
