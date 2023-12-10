#include <stdio.h>
#include <stdlib.h>

typedef int element;
// 이중 연결리스트 노드 타입
typedef struct DListNode
{
    element data;
    struct DListNode *llink;
    struct DListNode *rlink;
} DListNode;
// 이중 연결리스트 초기화
void init(DListNode *phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}
// 이중 연결리스트 상태 출력
void print_dlist(DListNode *phead)
{
    DListNode *p;
    for (p = phead->rlink; p != phead; p = p->rlink)
    {
        printf("<-| |%d| |-> ", p->data);
    }
    printf("\n");
}
// 새로운 데이터를 노드 before의 오른쪽에 삽입
void dinsert(DListNode *before, element data)
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}
// 노드 removed를 삭제
void ddelete(DListNode *head, DListNode *removed)
{
    if (removed == head)
        return;
    head->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}
// 메인
int main(void)
{
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    printf("추가 단계\n");
    for (int i = 0; i < 5; i++)
    {
        dinsert(head, i);
        printDlist(head);
    }
    printf("\n삭제 단계\n");
    for (int i = 0; i < 5; i++)
    {
        printDlist(head);
        ddelete(head, head->rlink);
    }
    free(head);
    return 0;
}

/* 실행결과
삽입 단계
<-| |0| |->
<-| |1| |-> <-| |0| |->
<-| |2| |-> <-| |1| |-> <-| |0| |->
<-| |3| |-> <-| |2| |-> <-| |1| |-> <-| |0| |->
<-| |4| |-> <-| |3| |-> <-| |2| |-> <-| |1| |-> <-| |0| |->

삭제 단계
<-| |4| |-> <-| |3| |-> <-| |2| |-> <-| |1| |-> <-| |0| |->
<-| |3| |-> <-| |2| |-> <-| |1| |-> <-| |0| |->
<-| |2| |-> <-| |1| |-> <-| |0| |->
<-| |1| |-> <-| |0| |->
<-| |0| |->
*/