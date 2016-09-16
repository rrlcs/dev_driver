#include"header.h"
#include"declaration.h"
//#include"fops.h"

static void __exit func_name(void)
{
	int l;

	for(l=0; l<nod; l++)
	{
		cdev_del(&quant[l].c_dev);
	}
	kfree(quant);
	unregister_chrdev_region(dev, nod);
	printk(KERN_INFO "Bye kernel , We will back\n");
};
module_exit(func_name);
