#include"header.h"
#include"declaration.h"
int rfd;
int open_read()
{
	printf("\nBEGIN: Function: %s\n", __func__);
	rfd = open("node", O_RDONLY);
	printf("END: Function: %s\n", __func__);
	return rfd;
}
