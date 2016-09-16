#include"header.h"
#include"declaration.h"

int dev_trim(struct Dev *fdev)
{
	struct Qset * lsqset, *slqset;
	int l, i;
	printk(KERN_INFO "BEGIN: %s", __func__);
	if(!fdev)
		printk(KERN_ERR "ERROR: Device Not Found");
	lsqset = fdev->firstqs->next;
	slqset = lsqset;	
	while(lsqset)
	{
	/*	if(!lsqset->next)
		{
			printk(KERN_INFO "INFO: kfree successful");
			kfree(slqset);
			slqset = NULL;
		}
	*/	while(lsqset->next)
		{
			slqset = lsqset;
			lsqset = lsqset->next;
			if(!lsqset)
				goto OUT1;
		}
		i = 0;
		for(l=noq-1; l>=0; l--)
		{
			if(lsqset->data[i])
			{
				kfree(lsqset->data[i]);
				if(lsqset->data[i])
					goto OUT2;
				lsqset->data[i] = NULL;
			}
			if(i == qsetsize-1)
			{
				kfree(lsqset->data);
				if(lsqset->data)
					goto OUT3;
				lsqset->data = NULL;

				kfree(slqset->next);
				if(slqset->next)
					goto OUT4;
				slqset->next = NULL;
				lsqset = slqset;
			}
			else
			{
				i++;
			}
			
		}


		if(!slqset->next)
		{
			kfree(slqset);
			if(slqset)
				goto OUT5;
			slqset = NULL;		
		}
	}
	
	printk(KERN_INFO "END: %s", __func__);
	return 0;
OUT1:
	printk(KERN_ERR "ERROR: OUT1");
	return 0;
OUT2:
	printk(KERN_ERR "ERROR: OUT2");
	return 0;
OUT3:
	printk(KERN_ERR "ERROR: OUT3");
	return 0;
OUT4:
	printk(KERN_ERR "ERROR: OUT4");
	return 0;
OUT5:
	printk(KERN_ERR "ERROR: OUT5");
	return 0;
}
