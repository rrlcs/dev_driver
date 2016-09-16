#include"header.h"
#include"declaration.h"
int wfd;
int open_write()
{
	printf("\nBEGIN: Function: %s\n", __func__);
	wfd = open("node", O_WRONLY);
	printf("wfd = %d\n", wfd);
	printf("END: Function: %s\n", __func__);
	return wfd;
}
