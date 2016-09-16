#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node * next;
	int data;
};

int main()
{
	int i = 0;
	struct node * start, *last;
	for(i=0; i<4; i++)
	{
		if(i == 0)
		{
			start = last = (struct node *)malloc(sizeof(struct node *));
			scanf("%d", &start->data);
		}
		else
		{
			last->next = (struct node *)malloc(sizeof(struct node *));
			scanf("%d", &last->next->data);
			last = last->next;
		}
	}
	last = start;
	printf("\n%d\n", last->next->data);
}
