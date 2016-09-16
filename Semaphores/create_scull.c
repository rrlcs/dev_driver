#include"header.h"
#include"declaration.h"
int noi, noq;
struct Qset * create_scull(int fsize)
{
	int l, qsetsize, quantumsize, i, lc1, lc2, lc3;
	struct Qset * first, *lsqset;
	noi = 0;
	lc1 = 0;
	lc2 = 0;
	lc3 = 0;
	first = lsqset = NULL;

	printk(KERN_INFO "BEGIN: %s", __func__);

	printk(KERN_INFO "fsize = %d", fsize);
	
	qsetsize = QSETSIZE;
	quantumsize = QUANTUMSIZE;

	noi = fsize / (qsetsize*quantumsize);
	if(fsize % (qsetsize*quantumsize))
		noi++;

	printk(KERN_INFO "noi = %d", noi);	
	for(l=0; l<noi; l++)
	{
		if(l == 0)
		{
			first = lsqset = (struct Qset *)kmalloc(sizeof(struct Qset), GFP_KERNEL);

			if(!first)
			{
				printk(KERN_ERR "ERROR: kmalloc(1) failed.\n");
				goto OUT;
			}
		}
		else
		{
			lsqset->next = (struct Qset *)kmalloc(sizeof(struct Qset), GFP_KERNEL);

			if(!lsqset->next)
			{
				printk(KERN_ERR "ERROR: kmalloc(2) failed.\n");
				goto OUT;
			}

			lsqset = lsqset->next;

			if(!lsqset)
			{
				printk(KERN_ERR "ERROR: kmalloc(3) failed.\n");
				goto OUT;
			}

			printk(KERN_INFO "lsqset->next = %p", lsqset);
		}

		lsqset->next = NULL;
		first->data = NULL;
		lc1++;
	}
	printk(KERN_INFO "lc1 = %d\n", lc1);
	lsqset = first;
	for(l=0; l<noi; l++)
	{
		lsqset->data = kmalloc(sizeof(char *)*qsetsize, GFP_KERNEL);
		if(!lsqset->data)
		{
			printk(KERN_ERR "ERROR: kmalloc() failed.\n");
			goto OUT;
		}
		memset(lsqset->data, '\0', sizeof(char *)*qsetsize);
		lsqset = lsqset->next;
//		if(!lsqset)
//			goto OUT;

		lc2++;
	}
	printk(KERN_INFO "lc2 = %d\n", lc2);

	noq = fsize / quantumsize;
	if(fsize % quantumsize)
		noq++;	

	lsqset = first;
	l = 0;
		for(i=0; i<noq; i++)
		{
			lsqset->data[l] =kmalloc(sizeof(char)*quantumsize, GFP_KERNEL);
			if(!lsqset->data[l])
			{
				printk(KERN_ERR "ERROR: kmalloc() failed.\n");
				goto OUT;
			}
			if(l == qsetsize - 1)
			{
				l = 0;
				lsqset = lsqset->next;
				if(!lsqset)
					goto OUT;
				//lsqset = first;
			}
			else
				l++;
		}
	

	printk(KERN_INFO "lsqset->next = %p", lsqset);
	printk(KERN_INFO "data_written = %p", (char *)lsqset->data[0]);
	printk(KERN_INFO "data_written = %p", (char *)lsqset->data[1]);
	printk(KERN_INFO "data_written = %p", (char *)lsqset->data[2]);
	printk(KERN_INFO "END: %s", __func__);
	return first;
OUT:
	printk(KERN_ERR "ERROR: scull error\n");
	return 0;
}

