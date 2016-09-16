#include"header.h"
#include"declaration.h"

int mainmenu()
{
	int choice;
	printf("____MAIN___MENU____\n");
	printf("1: Open For Read from File\n");
	printf("2: Read from File\n");
	printf("3: Open For Write to File\n");
	printf("4: Write to File\n");
	printf("5: Do lseek\n");
	printf("6: Close File\n");
	printf("0: EXIT\n");
	scanf("%d", &choice);
	
	return choice;
}
