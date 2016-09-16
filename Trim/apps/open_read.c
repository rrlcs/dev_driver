#include"header.h"
#include"declaration.h"
int rfd;
int open_read()
{
	printf("\nBEGIN: Function: %s\n", __func__);
	rfd = open("node", O_RDONLY);

	if(rfd == -1)
		goto OUT;

	printf("END: Function: %s\n", __func__);
	return rfd;
OUT:
	printf("Open for Read Failed!\n");
	return 0;
}
