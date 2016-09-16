#include"header.h"
#include"declaration.h"

int mainmenu()
{
	int choice;
	printf("____MAIN___MENU____");
	printf("1: Open For Read from File");
	printf("2: Read from File");
	printf("3: Open For Write to File");
	printf("4: Write to File");
	printf("0: EXIT");
	scanf("%d", &choice);
	
	return choice;
}
