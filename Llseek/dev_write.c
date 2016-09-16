#include"header.h"
#include"declaration.h"
int bytes;
ssize_t dev_write(struct file *filep, const char __user *buff, size_t size, loff_t *loff)
{
	int noitc,  nocsnw = 0, j, q2s, b2s;
	struct Qset * lsqset;
	struct Dev * ldev;
	int noctw;

	printk(KERN_INFO "BEGIN: write()");

	ldev = (struct Dev *)filep->private_data;

        ldev->firstqs = (struct Qset *)kmalloc(sizeof(struct Qset), GFP_KERNEL);

	*loff = filep->f_pos;

	printk(KERN_ERR "FILEP->F_POR =");

	printk(KERN_INFO "LOFF = %d", (int)*loff);

	q2s = *loff/quantumsize;//quantum to skip
	b2s = *loff%quantumsize;//bytes to skip in a quantum

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
	bytes = *loff;

	printk(KERN_INFO "noi = %d", noi);
	printk(KERN_INFO "size = %d", (int)size);
	printk(KERN_INFO "loff = %d", (int)*loff);
	printk(KERN_INFO "ldev->datasize = %d\n", ldev->datasize);

	j = q2s;
	noitc = noitc - (int)*loff;

	printk(KERN_INFO "noitc = %d", noitc);

	while(noitc)
	{
		if(noitc >= quantumsize)
			noctw = quantumsize;
		else
			noctw = noitc;
		nocsnw = copy_from_user(lsqset->data[j]+b2s, buff+bytes, noctw);
		noitc = noitc - noctw;
		printk(KERN_INFO "data_written = %s",(char *)lsqset->data[j]+b2s);
		bytes = bytes + noctw - nocsnw;
		if(j == (qsetsize - 1))
		{
			j = 0;
			lsqset = lsqset->next;
			if(!lsqset)
			{
				goto OUT;
			}
		}
		else
			j++;
	}
	bytes = bytes - *loff;
	*loff = *loff + bytes;
	//filep->f_pos = 0;
	ldev->datasize = bytes;
	printk(KERN_INFO "END: ldev->datasize = %d\n", ldev->datasize);
	printk(KERN_INFO "END: write()");
	return bytes;
OUT: 
	printk(KERN_ERR "ERROR: write failed!\n");
	return 0;
}
