#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/cdev.h>
#include<linux/delay.h>
#include<linux/moduleparam.h>
#include<linux/kernel.h>
#include<asm-generic/uaccess.h>
#include<linux/semaphore.h>
#include<linux/completion.h>
#include<linux/spinlock.h>
#include<linux/wait.h>
#include<linux/atomic.h>

MODULE_LICENSE("GPL");

#ifndef MY_DRIVER
#define NAME "MY_DRIVER"
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef MINORNO
#define MINORNO 0
#endif

#ifndef NOD
#define NOD 1
#endif

#ifndef QSETSIZE
#define QSETSIZE 8
#endif

#ifndef QUANTUMSIZE
#define QUANTUMSIZE 8
#endif

#ifndef DEVICESIZE
#define DEVICESIZE 1024
#endif

#ifndef DATASIZE
#define DATASIZE 0
#endif
