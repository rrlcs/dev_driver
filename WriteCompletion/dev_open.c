#include"header.h"
#include"declaration.h"

int dev_open(struct inode *inode, struct file *filep)
{
	struct Dev *ldev;
	ldev = quant;
	ldev = container_of(inode->i_cdev, struct Dev, c_dev);
	filep->private_data = ldev;
	printk(KERN_INFO "BEGIN: %s", __func__);
	if((filep->f_flags & O_ACCMODE) == O_WRONLY)
	{
		if(down_interruptible(&ldev->sem))
			return ERESTARTSYS;
		dev_trim(ldev);
		up(&ldev->sem);
	}
	printk(KERN_INFO "END: %s", __func__);
	return 0;
}

