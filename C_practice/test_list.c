#include <stdlib.h>
#include <stdio.h>

struct NODE
{
    int ID, value;
    struct NODE *prev;
    struct NODE *next;
} *head, *tail, *ptr, *ptr_t;

void del_process(del_ID)
{
    struct NODE *tmp1, *tmp2;
    tmp1 = ptr->prev;
    tmp2 = ptr->next;
    tmp1->next = tmp2;
    tmp2->prev = tmp1;
    free(ptr);
    return;
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

void ll_input()
{
    int inid, invalue;
    printf("ID, value: ");
    scanf("%d, %d", &inid, &invalue);
    ptr = (struct NODE *)malloc(sizeof(struct NODE));
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
        ptr = ptr->next;
        ptr_t = ptr_t->prev;
        if (ptr == ptr_t)
        {
            if (ptr->ID == del_ID)
            {
                del_process(del_ID);
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
                del_process(del_ID);
                return;
            }
            if (ptr_t->ID == del_ID)
            {
                ptr = ptr_t;
                del_process(del_ID);
                return;
            }
            ptr = ptr->next;
            ptr_t = ptr_t->prev;
        }
    }
}

int main()
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
            // ll_input_rev();
        }
        else if (index == 3)
        {
            ll_print();
        }
        else if (index == 4)
        {
            // ll_print_rev();
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
    return 0;
}
