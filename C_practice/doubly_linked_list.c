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

DListNode* head = NULL;
DListNode* tail = NULL;

// 초기화

DListNode *ll_search(DListNode *head,element value)
{
    DListNode *temp;
    temp = head;
    while (temp != tail)
    {
        if(temp->ID == value){
            return temp;
        }
        temp = temp->next;
    }
    return head;
}
DListNode *ll_search_rev(DListNode *tail, DListNode *head, element value)
{
    DListNode *temp;
    temp = tail;
    while (temp != head)
    {
        if (temp->ID == value)
        {
            return temp;
        }
        temp = temp->prev;
    }
    return tail;
}

void ll_print_rev(DListNode *head, DListNode *tail)
{
    DListNode* p;
    for (p = tail->prev; p!= head; p = p->prev){
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
void ll_print(DListNode *head, DListNode *tail)
{
    DListNode *p;
    for (p = head->next; p != tail; p = p->next)
    {
        printf(" < = |ID :%d|Data:%d| => ", p->ID, p->data);
    }
    printf("\n");
}
void ll_delete(DListNode *head, DListNode *tail,DListNode *removed)
{
    if (removed == head || removed == tail)
    {
        return;
    }
    removed->prev->next = removed->next;
    removed->next->prev = removed->prev;
    free(removed);
}
void ll_update(DListNode *changed,element input){

    DListNode *temp;
    temp = changed;
    temp->data = input;
    return;
}
void ll_delete_all(DListNode *head, DListNode *tail)
{
    DListNode *temp;
    for (temp = head->next;temp != tail;temp = temp->next){
        free(temp);
    }
}

int main(void)
{
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    DListNode *tail = (DListNode *)malloc(sizeof(DListNode));
    head->next = tail;
    tail->prev = head;
    int order;
    int input_ID,input_data,P_ID;

    input_data = 1;
    input_ID = 1;
    P_ID = 1;
    order = 1;

    while (order != 0)
    {
        printf("1. input 2. input_rev 3. print 4. print_rev 5. update 6. delete 0. exit \n");
        printf("\n");
        scanf("%d", &order);
        if(order == 1){
            printf("노드의 위치 ID,Data,ID를 입력하시오: ");
            scanf("%d %d %d",&P_ID,&input_ID,&input_data);
            ll_input(ll_search(head, P_ID), input_data, input_ID);
        }
        else if(order == 2){
            printf("노드의 위치 ID,Data,ID를 입력하시오: ");
            scanf("%d %d %d", &P_ID, &input_ID, &input_data);
            ll_input(ll_search_rev(tail,head,P_ID), input_ID, input_data);
        }
        else if(order == 3){
            ll_print(head,tail);
        }
        else if (order == 4)
        {
            ll_print_rev(head,tail);
        }
        else if (order == 5)
        {   
            printf("ID와 변경할 값을 입력하시오:");
            scanf("%d %d",&P_ID,&input_data);
            ll_update(ll_search(head,P_ID),input_data);
        }
        else if (order == 6)
        {
            printf("ID를 입력하시오:");
            scanf("%d", &P_ID);
            ll_delete(head,tail,ll_search(head,P_ID));
        }
        else if(order == 0 ){

            ll_delete_all(head,tail);
        }
    }
    return 0;
}

