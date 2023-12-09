#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int search(struct Node *head, int x)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
};

int main()
{
    struct Node *head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;
    return 0;

    struct Node *second = NULL;
    second = (struct Node*) malloc(sizeof(struct Node));
    second -> data = 2;
    second -> next = NULL;
    head -> next = second;
    printf( " 1 is %d ",(search(head,1)));
}