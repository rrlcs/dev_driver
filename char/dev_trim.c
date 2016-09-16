#include"header.h"
#include"declaration.h"

int dev_trim(struct Dev *fdev)
{
	printk(KERN_INFO "BEGIN: %s", __func__);
	if(!fdev->firstqs)
		printk(KERN_ERR "ERROR: Device Not Found");

	
	printk(KERN_INFO "END: %s", __func__);
	return 0;
}
