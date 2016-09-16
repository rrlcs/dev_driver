#include"header.h"
#include"declaration.h"

ssize_t dev_read(struct file *filep, char __user *buff, size_t size, loff_t * loff)
{
	struct Qset *lsqset;
	struct Dev *ldev;
	int noctr, noctr1, nocnr, bytes, j;
	printk(KERN_INFO "BEGIN: %s", __func__);
	ldev = (struct Dev*)filep->private_data;
	lsqset = ldev->firstqs;
	if(!lsqset)
		goto OUT;
	noctr = ldev->datasize;

	printk(KERN_INFO"noctr is %d\n",noctr);

	j = 0;	
	bytes = 0;

	while(noctr)
	{
		if(noctr >= quantumsize)
        	        noctr1 = quantumsize;
                else
                        noctr1 = noctr;
                nocnr = copy_to_user(buff+bytes, lsqset->data[j], noctr1);
                noctr = noctr - noctr1;
                printk(KERN_INFO "data_read = %s",buff);
                bytes = bytes + noctr1 - nocnr;
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
        ldev->datasize = ldev->datasize - bytes;

	printk(KERN_INFO "END: %s datasize = %d\n", __func__, ldev->datasize);
	printk(KERN_INFO "END: %s", __func__);
	return bytes;
OUT:
        printk(KERN_INFO "INFO: nocnr = %d\n", nocnr);
        printk(KERN_ERR "ERROR: Read Failed!\n");
        return 0;

}
