#include"header.h"
#include"declaration.h"

int operations(int choice)
{
	printf("IN Function: %s", __func__);
	switch(choice)
	{
		case 1: 
			openr();
			break;
		case 2: 
			read();
			break;
		case 3:
			wfd = openw(); 
			break;
		case 4:
			write(); 
			break;
		default:
			exit(EXIT_SUCCESS); 
			break;
	}

	return 0;
}
