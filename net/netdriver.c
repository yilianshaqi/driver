/*************************************************************************
    > File Name: netdriver.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年11月25日 星期五 20时26分02秒
 ************************************************************************/
#include <linux/kernel.h>

#include <linux/module.h>

#include <linux/fs.h>

#include <linux/uaccess.h>

#include <linux/netdevice.h>

#include <linux/etherdevice.h>

int my_open(struct net_device *nd)
{
	return 0;
}
int my_close(struct net_device *nd){
	return 0;
}
struct net_device *my_device=NULL;
struct net_device_ops fops={
	.ndo_open = my_open,
	.ndo_stop = my_close,
};
int net_init(void)
{
	int ret =0;
	//建立net_driver
	my_device = alloc_netdev(0,"test_net",ether_setup);
	if(NULL==my_device){
		printk("alloc netdev error\n");
		return -1;
	}
	//初始化net_device
	my_device->netdev_ops=&fops;
	//注册设备
	ret=register_netdev(my_device);
	if(ret<0)
	{
		free_netdev(my_device);
		printk("register error\n");
		return -1;
	}
	printk("init ok\n");
	return 0;


}
void net_exit(void)
{
	unregister_netdev(my_device);
	free_netdev(my_device);
	printk("exit\n");	

}
MODULE_LICENSE("GPL");
module_init(net_init);
module_exit(net_exit);
