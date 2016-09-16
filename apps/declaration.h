extern dev_t dev;
extern int nod, majorno, minorno;

struct Qset
{
	struct Qset *next;
	void ** data;
};

struct Dev
{
	struct Qset *first;
	struct cdev c_dev;
};
//extern struct cdev c_dev;
extern struct Dev *quant;
int MyExpMod(void); 
int wfd;
