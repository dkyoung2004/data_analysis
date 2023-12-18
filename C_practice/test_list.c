#include <stdio.h>
#include <stdlib.h>
void ll_input(), ll_input_rev(), ll_print(), ll_print_rev(), ll_update(), ll_delete();

struct NODE
{
    int ID, value;
    struct NODE *prev;
    struct NODE *next;
} *head, *tail, *ptr, *ptr_t;

void ll_input()
{
    int inid, invalue;
    printf("ID, value: ");
    scanf("%d, %d", &inid, &invalue);
    ptr = (struct NODE *)malloc(sizeof(struct NODE));
    printf("Value is : %d" , invalue);
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        tail->next = ptr;
    }
    ptr->ID = inid;
    ptr->value = invalue;
    ptr->next = NULL;
    if (ptr == head)
    {
        ptr->prev = NULL;
    }
    else
    {
        ptr->prev = tail;
    }
    tail = ptr;
    ll_print();
}

void ll_print()
{
    ptr = head;
    printf("(ID, Values): ");
    while (ptr != NULL)
    {
        printf("(%d, %d) ", ptr->ID, ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void ll_update()
{
    int new_ID, new_value;
    printf("/tID for update: ");
    scanf("%d", &new_ID);
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->ID == new_ID)
        {
            printf("\tEnter the new value for this ID: ");
            scanf("%d", &new_value);
            ptr->value = new_value;
            ll_print();
            return;
        }
        ptr = ptr->next;
    }
}

void ll_delete()
{
    int del_ID;
    printf("\tID for delete: ");
    scanf("%d", &del_ID);
    ptr = head;
    ptr_t = tail;
    if (ptr->ID == del_ID)
    {
        head = ptr->next;
        free(ptr);
        ll_print();
        return;
    }
    else if (ptr_t->ID == del_ID)
    {
        tail = ptr->prev;
        free(ptr_t);
        ll_print();
        return;
    }
    else
    {
        struct NODE *tmp1, *tmp2;
        ptr = ptr->next;
        ptr_t = ptr_t->prev;
        if (ptr == ptr_t)
        {
            if (ptr->ID == del_ID)
            {
                tmp1 = ptr->prev;
                tmp2 = ptr->next;
                tmp1->next = tmp2;
                tmp2->prev = tmp1;
                free(ptr);
                return;
            }
            else
            {
                return;
            }
        }
        while (ptr != ptr_t)
        {
            if (ptr->ID == del_ID)
            {
                tmp1 = ptr->prev;
                tmp2 = ptr->next;
                tmp1->next = tmp2;
                tmp2->prev = tmp1;
                free(ptr);
                return;
            }
            if (ptr_t->ID == del_ID)
            {
                tmp1 = ptr_t->prev;
                tmp2 = ptr_t->next;
                tmp1->next = tmp2;
                tmp2->prev = tmp1;
                free(ptr_t);
                return;
            }
            ptr = ptr->next;
            ptr_t = ptr_t->prev;
        }
    }
}

void ll_input_rev()
{
    int inid, invalue;
    printf("ID, value: ");
    scanf("%d, %d", &inid, &invalue);
    ptr = (struct NODE *)malloc(sizeof(struct NODE));
    if (tail == NULL)
    {
        tail = ptr;
    }
    else
    {
        head->prev = ptr;
    }
    ptr->ID = inid;
    ptr->value = invalue;
    ptr->prev = NULL;
    if (ptr == tail)
    {
        ptr->next = NULL;
    }
    else
    {
        ptr->next = head;
    }
    head = ptr;
    ll_print();
}

void ll_print_rev()
{
    ptr = head;
    printf("(ID, Values): ");
    while (ptr != NULL)
    {
        printf("(%d, %d) ", ptr->ID, ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}
void main()
{
    head = NULL;
    int index, flag = 0;
    while (flag == 0)
    {
        printf("Enter [(1)Input (2)Input_rev (3)Print (4)Print_rev (5)Update (6)Delete (7)Exit] : ");
        scanf("%d", &index);
        if (index == 1)
        {
            ll_input();
        }
        else if (index == 2)
        {
            ll_input_rev();
        }
        else if (index == 3)
        {
            ll_print();
        }
        else if (index == 4)
        {
            ll_print_rev();
        }
        else if (index == 5)
        {
            ll_update();
        }
        else if (index == 6)
        {
            ll_delete();
        }
        else if (index == 7)
        {
            printf("Exit this program\n");
            flag = 1;
        }
        else
        {
            printf("Enter Again(between 1 and 7)\n");
        }
    }
    return;
}