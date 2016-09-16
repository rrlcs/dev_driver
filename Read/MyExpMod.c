#include"header.h"
#include"declaration.h"

int MyExpMod()
{
	printk(KERN_INFO "BEGIN: %s", __func__);
	printk(KERN_INFO "END: %s", __func__);
	return 0;
}
