#include"header.h"
#include"declaration.h"

ssize_t dev_read(struct file *filep, char __user *buff, size_t size, loff_t * loff)
{
	printk(KERN_INFO "BEGIN: %s", __func__);
	printk(KERN_INFO "END: %s", __func__);
	return 0;
}
