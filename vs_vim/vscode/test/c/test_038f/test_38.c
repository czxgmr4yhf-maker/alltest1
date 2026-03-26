#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
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
int Length( List L ) {
    int length = 0;
    List p = L;
    while(p != NULL) {
        length++;
        p = p->Next;
    }
    return length;
}