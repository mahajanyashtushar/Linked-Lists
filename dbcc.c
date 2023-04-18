// Doubly circular LinkedList

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE First,PPNODE Last,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn ->next = NULL;
    newn ->prev = NULL;

    if(*First == NULL && *Last == NULL)
    {
        *First = *Last = newn;
        (*Last) ->next = *First;
        (*First)->prev = *Last;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn; 
        *First = newn;
        (*Last) ->next = *First;
        (*First)->prev = *Last;
    }
}
void Display(PNODE First,PNODE Last)
{
    PNODE temp = First;
    do
    {
        printf("| %d |<=>",temp->data);
        temp = temp->next;
    }while(temp!= Last->next);
    printf("\n");
}

void InsertLast(PPNODE First,PPNODE Last,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn ->next = NULL;
    newn ->prev = NULL;

    if(*First == NULL && *Last == NULL)
    {
        *First = *Last = newn;
        (*Last) ->next = *First;
        (*First)->prev = *Last;
    }
    else
    {
        (*Last) ->next = newn;
        newn ->prev = *Last;
        *Last = (*Last) ->next;
        (*Last) ->next = *First;
        (*First)->prev = *Last;
    } 
}
void DeleteFirst(PPNODE First,PPNODE Last)
{
    if(*First == NULL || *Last == NULL)
    {
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
        PNODE Temp = *First;
        *First = (*First) ->next;
        free(Temp);
        (*Last) ->next = *First;
        (*First)->prev = *Last;

    }
}
void DeleteLast(PPNODE First,PPNODE Last)
{
     if(*First == NULL || *Last == NULL)
    {
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
      *Last =  (*Last)->prev;
      free(temp);
        (*Last) ->next = *First;
        (*First)->prev = *Last;
    }
}
int Count(PNODE First,PNODE Last)
{
    int iCnt = 0;
     PNODE temp = First;
    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp!= Last->next);
    return iCnt;
}
void InsertAtPos(PPNODE First,PPNODE Last,int no,int iPos)
{
    int iCount = Count(*First,*Last);

     PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn ->next = NULL;
    newn ->prev = NULL;

    if(iPos<1 || iPos >iCount)
    {
        printf("Invalid Position \n");
        return;
    }
    else if(iPos  == 1)
    {
        InsertFirst(First,Last,no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(First,Last,no);
    }
    else
    {
        PNODE temp = *First;

        for(int i = 1;i<iPos-1;i++)
        {
            temp = temp ->next;
        }
        newn ->next = temp ->next;
        temp ->next ->prev = newn;
        temp ->next = newn;
        newn ->prev = temp;
        (*Last) ->next = *First;
        (*First)->prev = *Last;
    }
}
void DeleteAtPose(PPNODE First,PPNODE Last,int iPos)
{
    int iCount = Count(*First,*Last);
    if(iPos<1 || iPos >iCount)
    {
        printf("Invalid Position \n");
        return;
    }
    else if(iPos  == 1)
    {
        DeleteFirst(First,Last);
    }
    else if(iPos == iCount+1)
    {
        DeleteLast(First,Last);
    }
    else
    {
         PNODE temp = *First;

        for(int i = 1;i<iPos-1;i++)
        {
            temp = temp ->next;
        }
        PNODE temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        free(temp1);
        (*Last) ->next = *First;
        (*First)->prev = *Last;
    }
}
int main()
{   
    PNODE Head = NULL;
    PNODE Tail = NULL;

    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);
    Display(Head,Tail);

    InsertLast(&Head,&Tail,101);
    InsertLast(&Head,&Tail,111);
    InsertLast(&Head,&Tail,151);
    Display(Head,Tail);

    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);

    DeleteLast(&Head,&Tail);
    Display(Head,Tail);

    InsertAtPos(&Head,&Tail,105,3);
    Display(Head,Tail);

    DeleteAtPose(&Head,&Tail,3);
    Display(Head,Tail);


    return 0;

}