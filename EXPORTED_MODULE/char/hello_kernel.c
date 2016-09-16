#include"header.h"
#include"declaration.h"
#include"fops.h"

dev_t dev;
int nod, majorno, minorno, ret;
struct Dev *quant;
struct cdev c_dev;
module_param(nod, int, S_IRUGO);

static int __init func_name(void)
{

	printk(KERN_INFO "Hello Kernel , My Driver is getting registered\n");

	ret = alloc_chrdev_region( &dev, MAJORNO, nod, NAME );


	if(ret == -1)
	{
		printk(KERN_INFO "ERROR: alloc_chrdev_region FAILED");
	}

	majorno = MAJOR(dev);
	minorno = MINOR(dev);
	dev = MKDEV(majorno, minorno);
	printk(KERN_INFO "majorno = %d\n", majorno);
	printk(KERN_INFO "minorno = %d\n", minorno);

	if(!(quant = (struct Dev *)kmalloc(sizeof(struct Dev)*nod, GFP_KERNEL)))
	{
		printk(KERN_INFO "ERROR: kmalloc Failed.");
	}
	else
	{
		printk(KERN_INFO "Memory allocation Successful!");
	}
	memset(quant, '\0', sizeof(struct Dev *)*nod);
	cdev_init(&quant->c_dev, &fops);
	quant->c_dev.owner = THIS_MODULE;
	quant->c_dev.ops = &fops;
	
	printk(KERN_INFO "cdev initialization Successful!");

	cdev_add(&quant->c_dev, dev, majorno);
	printk(KERN_INFO "CDEV Added");
	
	return 0;
}
module_init(func_name);
