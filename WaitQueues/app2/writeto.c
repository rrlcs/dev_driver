#include"header.h"
#include"declaration.h"
int writeto(int wfd)
{
	int len, ret;
	char ubuff[]="From Application 2 Writing to Device Driver written by me that is Ravi Raja in Emblogic with the help of my friends";
	len = strlen(ubuff);
	printf("\nlen = %d bytes\n",len);
	ret = write(wfd, ubuff, len);
	printf("\n%s Wrote %d bytes\n", __FILE__, ret);
	return 0;
}
