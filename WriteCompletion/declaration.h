extern dev_t dev, newdev;
extern int nod, majorno, minorno, noi, noq, qsetsize, quantumsize, devicesize, datasize;

struct Qset
{
	struct Qset *next;
	void ** data;
};

struct Dev
{
	struct Qset *firstqs;
	struct cdev c_dev;
	int qsetsize;
	int quantumsize;
	int devicesize;
	int datasize;
	struct semaphore sem;
	struct completion my_completion;
	spinlock_t my_lock;
};
//extern struct cdev c_dev;
extern struct Dev *quant;
int MyExpMod(void); 
int dev_open(struct inode *, struct file *);
int dev_release(struct inode *, struct file *);
ssize_t dev_write(struct file *, const char __user *, size_t, loff_t *);
ssize_t dev_read(struct file *, char __user *, size_t, loff_t *);
int dev_trim(struct Dev *);
loff_t dev_lseek(struct file *, loff_t, int);
struct Qset * create_scull(int);
