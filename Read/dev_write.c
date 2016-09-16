#include"header.h"
#include"declaration.h"
int bytes;
ssize_t dev_write(struct file *filep, const char __user *buff, size_t size, loff_t * loff)
{
	int noitc,  nocsnw = 0, j;
	struct Qset * lsqset;
	struct Dev * ldev;
	int noctw;
	printk(KERN_INFO "BEGIN: write()");

	ldev = (struct Dev *)filep->private_data;
        ldev->firstqs = (struct Qset *)kmalloc(sizeof(struct Qset), GFP_KERNEL);
	if(!ldev->firstqs)
        {
                printk(KERN_ERR "ERROR: kmalloc() failed.\n");
		goto OUT;
        }

	noitc = (int)size;
	lsqset = NULL;
	ldev->firstqs = create_scull(noitc);
	if(!ldev->firstqs)
	{	goto OUT;}

	lsqset = ldev->firstqs;
	bytes = 0;
	printk(KERN_INFO "noi = %d", noi);
	printk(KERN_INFO "size = %d", (int)size);
	printk(KERN_INFO "ldev->datasize = %d\n", ldev->datasize);
		j = 0;
		while(noitc)
		{
			if(noitc >= quantumsize)
				noctw = quantumsize;
			else
				noctw = noitc;
		
				nocsnw = copy_from_user(lsqset->data[j], buff+bytes, noctw);
				noitc = noitc - noctw;
				printk(KERN_INFO "data_written = %s",(char *)lsqset->data[j]);
				bytes = bytes + noctw - nocsnw;

				if(j == (qsetsize - 1))
				{
					j = 0;
					lsqset = lsqset->next;
					if(!lsqset)
					{	goto OUT;}
				}
				else
					j++;
		}
	ldev->datasize = bytes;
	printk(KERN_INFO "END: ldev->datasize = %d\n", ldev->datasize);
	printk(KERN_INFO "END: write()");
	return bytes;
OUT: 
	printk(KERN_ERR "ERROR: write failed!\n");
	return 0;
}
