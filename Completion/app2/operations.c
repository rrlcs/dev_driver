#include"header.h"
#include"declaration.h"
int wfd, rfd;
int operations(int choice)
{
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
			{	lseek(rfd, 8, SEEK_SET);} 
			else if( opt == 'w')
			{	lseek(wfd, SEEK_SET, 8);}
			else
			{	printf("Invalid Options");}
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
