#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
List Read(){
    PtrToLNode head = NULL;
    PtrToLNode tail = NULL;
    
    ElementType x;
    while(scanf("%d", &x) == 1 && x != -1) {
        List node = (PtrToLNode)malloc(sizeof(struct LNode));
        node->Data = x;
        node->Next = NULL;

        if(head == NULL) {
            head = tail = node;
        } else {
            tail->Next = node;
            tail = node;
        }
    }

    return head;
}
ElementType FindKth( List L, int K ) {
    List search = NULL;

    if(K <= 0) return ERROR;

    while (K--) {
        if (search == NULL) search = L;
        else search = search->Next;
        if (search == NULL) return ERROR;
    }

    return search->Data;
}