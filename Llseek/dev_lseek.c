#include"header.h"
#include"declaration.h"

loff_t dev_lseek(struct file * filep, loff_t loff, int seek)
{
	struct Dev *ldev;
	printk(KERN_INFO "BEGIN: %s", __func__);
	ldev = filep->private_data;
	filep->f_pos = loff;	
	printk("\n%s loff_t %d \n", __FILE__, (int)loff);
	printk("\n%s seek %d\n", __FILE__, seek);
	printk(KERN_INFO "END: %s", __func__);
	return 0;
}
