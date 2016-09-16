#include"header.h"
#include"declaration.h"
int readfrom(int rfd)
{
	int len, ret;
	char rbuff[]="Reading from buffer";
	len = strlen(rbuff);
	ret = read(rfd, rbuff, len);
	printf("\n%s Read %d bytes\n", __FILE__, ret);
	return 0;
}
