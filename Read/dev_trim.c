#include"header.h"
#include"declaration.h"

int dev_trim(struct Dev *fdev)
{
	struct Qset * lsqset, *slqset;
	int l;
	printk(KERN_INFO "BEGIN: %s", __func__);
	if(!fdev)
		printk(KERN_ERR "ERROR: Device Not Found");
	slqset =lsqset= NULL;
	while(lsqset)
	{
		slqset = lsqset = NULL;
		lsqset = fdev->firstqs;
		while(lsqset->next)
		{
			slqset = lsqset;
			lsqset = lsqset->next;
		}
		if(lsqset)
		{
			for(l=qsetsize-1; l>=0; l--)
			{
				if(lsqset->data[l]!=NULL)
				{
					kfree(lsqset->data[l]);
					lsqset->data[l] = NULL;
				}
			}
			
			kfree(lsqset->data);
			lsqset->data = NULL;
			kfree(lsqset);
			lsqset = NULL;
		}
		if(slqset)
		{
			slqset->next = NULL;
			lsqset = slqset;
		}
		else if(!slqset)
		{
			fdev->firstqs = NULL;
		}
	}
	
	printk(KERN_INFO "END: %s", __func__);
	return 0;
}
