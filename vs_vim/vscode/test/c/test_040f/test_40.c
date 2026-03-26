#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find( List L, ElementType X ) {
    List search = L;
    while (search != NULL) {
        if(search->Data == X) return search;
        else search = search->Next;
    }

    return ERROR;
}
List Insert( List L, ElementType X, Position P ) {
    List head = L;
    List tail = L;
    PtrToLNode node = (PtrToLNode)malloc(sizeof(struct LNode));
    node->Data = X;
    node->Next = P;

    if (head == P) {
        head = node;
        return head;
    }
    while(1) {
        if(head == NULL) {
            if(P == NULL) {
                head = node;
                return head;
            }
            break;
        }
        if (tail == NULL) break;

        if (tail->Next == P) {
            tail->Next = node;
            return head;
        }

        tail = tail->Next;
    }
    
    free(node);
    printf("Wrong Position for Insertion\n");
    return ERROR;
}
List Delete( List L, Position P ) {
    if(L == NULL || P == NULL) {
    printf("Wrong Position for Deletion\n");
    return ERROR;
    }

    List head = L;
    if(L == P) {
        head = head->Next;
        free(L);
        return head;
    }

    List prev = L;
    while(prev != NULL && prev->Next != P) prev = prev->Next;

    if (prev == NULL) {  // 这里只需要判断 P 不在链表中
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }

    prev->Next = P->Next;
    free(P);
    return head;
}