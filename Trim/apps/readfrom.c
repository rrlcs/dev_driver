#include"header.h"
#include"declaration.h"
int readfrom(int rfd)
{
	int len, ret;
	char rbuff[100];
	ret = read(rfd, rbuff, 100);
	if(ret == 0 && ret == -1)
		goto OUT;
	printf("\n%s Read %d bytes\n", __FILE__, ret);
	return 0;
OUT:
	printf("Read From Node Failed\n");
	return 0;
}
