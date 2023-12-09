#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct doubly_linked_list
{
    int data;
    int ID;
    struct doubly_linked_list* prev;
    struct doubly_linked_list* next;

}DListNode;

// 초기화
void init(DListNode* head) {
    head -> prev = head;
    head -> next = head;
}

void ll_print_rev(DListNode* head){
    DListNode* p;
    for (p = head->prev; p!= head; p = p->prev){
        printf(" < = |ID :%d|Data:%d| => ",p->ID , p -> data);
    }
    printf("\n");
}
void ll_input(DListNode *before, element data , element ID)
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode->ID = ID;
    newnode->data = data;
    newnode->prev = before;
    newnode->next = before->next;
    before->next->prev = newnode;
    before->next = newnode;
}
void ll_input_rev(DListNode *before, element data, element ID)
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode->ID = ID;
    newnode->data = data;
    newnode->next = before;
    newnode->prev = before->prev;
    before->prev->next = newnode;
    before->prev = newnode;
}
void ll_print(DListNode *head)
{
    DListNode *p;
    for (p = head->next; p != head; p = p->next)
    {
        printf(" < = |ID :%d|Data:%d| => ", p->ID, p->data);
    }
    printf("\n");
}
void ll_delete(DListNode *head, DListNode *removed)
{
    if (removed == head)
        return;
    head->next = removed->next;
    removed->next->prev = removed->prev;
    free(removed);
}

int main(void)
{
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    int order;
    int a,b;
    a = 0;
    b = 0;
    order = 1;
    while (order != 0)
    {
        printf("1. input 2. input_rev 3. print 4. print_rev 5. update 6. delete 0. exit \n");
        scanf("%d", &order);
        if(order == 1){
            printf("Data와 ID를 입력하시오: ");
            scanf("%d %d",&a,&b);
            ll_input(head,a,b);
        }
        else if(order == 2){
            printf("Data와 ID를 입력하시오: ");
            scanf("%d %d", &a, &b);
            ll_input_rev(head, a, b);
        }
        else if(order == 3){
            ll_print(head);
        }
        else if (order == 4)
        {
            ll_print_rev(head);
        }
        else if (order == 5)
        {
            ll_print_rev(head);
        }
        else if (order == 6)
        {
            ll_delete(head,head->next);
        }
    }
    
    free(head);
    return 0;
}

