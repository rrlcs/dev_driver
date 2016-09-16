#include"header.h"
#include"declaration.h"
//#include"fops.h"

static void __exit func_name(void)
{
	printk(KERN_INFO "Bye kernel , We will back\n");

	cdev_del(&quant->c_dev);
	kfree(quant);
/*	if(!(kfree(quant)))
	{
		printk(KERN_INFO "ERROR: Deallocation of memory Failed.\n");
	}
	else
	{
		printk(KERN_INFO "Memory successfully Deallocated");
	}
*/
	unregister_chrdev_region(dev, NOD);
};
module_exit(func_name);
