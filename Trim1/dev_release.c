#include"header.h"
#include"declaration.h"

int dev_release(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "BEGIN: %s", __func__);
	printk(KERN_INFO "END: %s", __func__);
	return 0;
}

