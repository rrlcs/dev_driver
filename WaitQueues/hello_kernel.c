#include"header.h"
#include"declaration.h"
#include"fops.h"

int MyExpMod()
{
        printk(KERN_INFO "BEGIN: %s", __func__);
        printk(KERN_INFO "END: %s", __func__);
        return 0;
}

dev_t dev, newdev;
int nod, majorno, minorno, ret;
int quantumsize, qsetsize, devicesize, datasize;
struct Dev *quant;
struct cdev c_dev;
module_param(nod, int, S_IRUGO);
EXPORT_SYMBOL(MyExpMod);

static int __init func_name(void)
{
	int l;
	printk(KERN_INFO "Hello Kernel , My Driver is getting registered\n");



	ret = alloc_chrdev_region( &dev, MAJORNO, nod, NAME );


	if(ret == -1)
	{
		printk(KERN_INFO "ERROR: alloc_chrdev_region FAILED");
	}

	majorno = MAJOR(dev);
	minorno = MINOR(dev);

	qsetsize = QSETSIZE;
	quantumsize = QUANTUMSIZE;
	devicesize = DEVICESIZE;
	datasize = DATASIZE;

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
	for(l=0; l<nod; l++)
	{
		newdev = MKDEV(majorno, l);

		minorno = MINOR(newdev);

		printk(KERN_INFO "minorno = %d\n", minorno);

		cdev_init(&quant[l].c_dev, &fops);

		quant[l].c_dev.owner = THIS_MODULE;

		quant[l].c_dev.ops = &fops;
		quant[l].qsetsize = qsetsize;
		quant[l].quantumsize = quantumsize;
		quant[l].devicesize = devicesize;
		atomic_set(&quant[l].datasize, datasize);
		sema_init(&quant[l].sem, 1);
		init_completion(&quant[l].my_completion);
		spin_lock_init(&quant[l].my_lock);
		init_waitqueue_head(&quant[l].waitQ);

		printk(KERN_INFO "cdev initialization Successful!");

		cdev_add(&quant[l].c_dev, newdev, majorno);

		printk(KERN_INFO "CDEV Added");		
	}
	MyExpMod();	
	return 0;
}
module_init(func_name);
