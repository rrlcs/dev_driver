#include"header.h"
#include"declaration.h"
int wfd, rfd;
int operations(int choice)
{
	int offset, origin;
	char opt;
	printf("IN Function: %s", __func__);
	switch(choice)
	{
		case 1: 
			rfd = open_read();
			break;
		case 2: 
			readfrom(rfd);
			break;
		case 3:
			wfd = open_write(); 
			break;
		case 4:
			writeto(wfd); 
			break;
		case 5: 
			printf("lseek: rfd or wfd?");
			scanf(" %c", &opt);
			if( opt == 'r' )
			{
				printf("Enter offset and origin for rfd");
				scanf("%d %d", &offset, &origin);
				lseek(rfd, offset, origin);
			} 
			else if( opt == 'w')
			{
				printf("Enter offset and origin for wfd");
				scanf("%d %d", &offset, &origin);
				lseek(wfd, offset, origin);
			}
			else
			{
				printf("Invalid Options");
			}
			break;
		case 6:
			printf("Closing node: rfd or wfd?");
			scanf(" %c", &opt);
			if( opt == 'r' )
			{	close(rfd);} 
			else if( opt == 'w')
			{	close(wfd);}
			else
			{	printf("Invalid Options");}
			break;
		default:
			exit(EXIT_SUCCESS); 
			break;
	}

	return 0;
}
