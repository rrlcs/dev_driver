#include"header.h"
#include"declaration.h"

ssize_t dev_read(struct file *filep, char __user *buff, size_t size, loff_t * loff)
{
	struct Qset *lsqset;
	struct Dev *ldev;
	int noctr, noctr1, nocnr, bytes, j, q2s, b2s;
	printk(KERN_INFO "BEGIN: %s", __func__);
	printk(KERN_INFO "OFFSET: %d",(int)*loff);

	ldev = (struct Dev*)filep->private_data;
	printk(KERN_INFO "Waiting For Completion\n");
//	wait_for_completion(&ldev->my_completion);

	//*loff = filep->f_pos;

	printk(KERN_INFO "OFFSET: %d",(int)*loff);
	printk(KERN_INFO "OFFSET: %d",(int)filep->f_pos);

	q2s = *loff/quantumsize;
	b2s = *loff%quantumsize;

	lsqset = ldev->firstqs;

	if(!lsqset)
	{
		goto OUT;
	}
	noctr = ldev->datasize - *loff;

	printk(KERN_INFO"noctr is %d\n",noctr);

	j = q2s;	

	bytes = 0;


	if(down_interruptible(&ldev->sem))
		return ERESTARTSYS;	
	while(noctr)
	{
		if(noctr >= quantumsize)
                        noctr1 = quantumsize;
                else
                        noctr1 = noctr;

                nocnr = copy_to_user(buff+bytes, lsqset->data[j]+b2s, noctr1);
                noctr = noctr - noctr1;
                printk(KERN_INFO "data_read = %s",(char *)lsqset->data[j]+b2s);
                bytes = bytes + noctr1 - nocnr;
		*loff = *loff + (noctr1 -nocnr); 
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
	up(&ldev->sem);
	complete(&ldev->my_completion);
        ldev->datasize = ldev->datasize - bytes;
	printk(KERN_INFO "END: %s datasize = %d\n", __func__, ldev->datasize);
	printk(KERN_INFO "END: %s", __func__);
	return bytes;
OUT:
        printk(KERN_INFO "INFO: nocnr = %d\n", nocnr);
        printk(KERN_ERR "ERROR: Read Failed!\n");
	up(&ldev->sem);
        return 0;

}
