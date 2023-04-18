// DoublyLL 

# include<stdio.h>
# include<stdlib.h>
# pragma pack(1)

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE First,PPNODE Last,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;
    newn ->prev = NULL;

    if(*First == NULL || *Last == NULL)
    {
        *First = *Last = newn;
    }
    else
    {
        newn ->next = *First;
        (*First) ->prev = newn;
        *First = newn;
    }

}
void Display(PNODE First,PNODE Last)
{
    PNODE temp = First;
    while(temp != NULL)
    {
        printf("|%d|<->",temp->data);
        temp = temp ->next;

    }
    printf("NULL \n");
}
void InsertLast(PPNODE First,PPNODE Last,int no)
{
     PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;
    newn ->prev = NULL;

    if(*First == NULL || *Last == NULL)
    {
        *First = *Last = newn;
    }
    else
    {
        (*Last) ->next = newn;
        newn ->prev = *Last;
        *Last = (*Last)->next; 
    }
}
void DeleteFirst(PPNODE First,PPNODE Last)
{
    if(*First == NULL || *Last == NULL)
    {
        printf("The LinkedList is empty\n");
        return;
    }
    else if((*First) ->next == NULL)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }

    else
    {
        PNODE temp = *First;
        *First = (*First) ->next;
        (*First) ->prev = NULL;
        free(temp);
    }

}
void DeleteLast(PPNODE First,PPNODE Last)
{
    if(*First == NULL || *Last == NULL)
    {
        printf("The LinkedList is empty\n");
        return;
    }
    else if((*First) ->next == NULL)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        PNODE temp = *Last;
        *Last = (*Last)->prev;
        (*Last) ->next = NULL;
        free(temp);
    }
}
int Count(PNODE First,PNODE Last)
{
    int iCnt = 0;
    while(First != NULL)
    {
        iCnt++;
        First =First->next;
    }
    return iCnt;
}
void InsertAtPos(PPNODE First,PPNODE Last,int no,int iPos)
{
    int iCount = Count(*First,*Last);

    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;
    newn ->prev = NULL;

    if(iPos <1 || iPos >iCount)
    {
        printf("Invalid Position \n");
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(First,Last,no);
    }
    else if(iPos == iCount)
    {
        InsertLast(First,Last,no);
    }
    else
    {
        PNODE temp = *First;
        for(int i =0;i<iPos-1;i++)
        {
            temp = temp ->next;
        }
        PNODE temp1 = temp ->next;
        newn ->next = temp1;
        temp1-> prev = newn;
        temp->next = newn;
        newn ->prev = temp;

    }
}
void DeleteAtPose(PPNODE First,PPNODE Last,int iPos)
{
    int iCount = Count(*First,*Last);

    if(iPos <1 || iPos >iCount)
    {
        printf("Invalid Position \n");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst(First,Last);
    }
    else if(iPos == iCount)
    {
        DeleteLast(First,Last);
    }

    else
    {
        PNODE Temp = *First;
        for(int i = 0;i<iPos-2;i++)
        {
            Temp = Temp->next;
        }
        PNODE temp1 = Temp ->next;
        Temp ->next =temp1->next;
        temp1->prev = Temp;
        free(temp1);
    }
}
int main()
{
    PNODE Head= NULL;
    PNODE Tail = NULL;

    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);
    Display(Head,Tail);

    InsertLast(&Head,&Tail,111);
    InsertLast(&Head,&Tail,121);
    InsertLast(&Head,&Tail,151);
    Display(Head,Tail);

    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);

    DeleteLast(&Head,&Tail);
    Display(Head,Tail);

    InsertAtPos(&Head,&Tail,105,5);
    Display(Head,Tail);

    DeleteAtPose(&Head,&Tail,3);
    Display(Head,Tail);

    return 0;
}