#include"header.h"
#include"declaration.h"

loff_t dev_lseek(struct file * filep, loff_t loff, int seek)
{
	printk(KERN_INFO "BEGIN: %s", __func__);
	printk(KERN_INFO "END: %s", __func__);
	return 0;
}
