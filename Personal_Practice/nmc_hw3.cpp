
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

typedef struct Node
{
	char value[1024];
	struct Node *prev;
	struct Node *next;
}Node;

Node *head;
Node *tail;


void init()
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	

	head->prev = NULL;
	head->next = tail;
	tail->next = NULL;
	tail->prev = head;
}


void Insert(char *data)
{
	Node *New = (Node*)malloc(sizeof(Node));
	strcpy(New->value, data);
	tail->prev->next = New;
	New->prev = tail->prev;

	
	New->next = tail;
	tail->prev = New;
}

void Print_Reverse()
{
	Node *Back = tail->prev;

	while (Back != head) {
		printf("%s\n", Back->value);
		Back = Back->prev;
	}
}


int main()
{
	init();
	char *line[MAX_LEN] = {"Geoffrey", "Yoshua", "Yann", "Cho", "Alex"};
	printf("Original Data:\n");

	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", line[i]);
		Insert(line[i]);
	}
	printf("\nReversed Order:\n");

	Print_Reverse();

	return 0;
}
