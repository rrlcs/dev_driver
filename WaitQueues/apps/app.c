#include"header.h"
#include"declaration.h"

int main()
{
	int choice;
	printf("IN Function: %s", __func__);
	while(1)
	{
		choice = mainmenu();
		operations(choice);
	}
	return 0;
}
