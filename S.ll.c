# include<stdio.h>
# include <stdlib.h>
# pragma pack(1)
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE First,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn ->next = NULL;
    newn ->data = no;

    if(*First == NULL)
    {
        *First = newn;
    } 
    else
    {
        newn ->next = *First;
        *First = newn;
    }
}

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("|%d|->",First->data);
        First = First->next;
    }
    printf("NULL \n");
}
void InsertLast(PPNODE First,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn ->next = NULL;
    newn ->data = no;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        PNODE Temp = *First;
        while(Temp ->next != NULL)
        {
            Temp = Temp ->next;
        }
        Temp ->next = newn;
    }
}
int Count(PNODE First)
{
    int iCnt = 0;
    while(First != NULL)
    {
        iCnt++;
        First = First->next;
    }

    return iCnt;
}
void InsertAtPos(PPNODE First,int no,int iPos)
{
    int iCount = Count(*First);

    if(iPos < 1 || iPos > iCount+1)
    {
        printf("invalid position \n");
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(First,no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(First,no);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn ->next = NULL;
        newn ->data = no;

        PNODE Temp = *First;
        for(int i = 0;i<iPos-1;i++)
        {
            Temp = Temp ->next;
        }
        PNODE Temp1 = Temp ->next;
        Temp ->next = newn;
        Temp->next -> next = Temp1;
        
    }
}

void DeleteFirst(PPNODE First)
    {
        if(*First == NULL)
        {
            printf("The the linked list is empty...\n");
            return;
        }
        else if((*First) ->next  == NULL)
        {
            free(*First);
            *First = NULL;
        }
        else
        {
            PNODE Temp = NULL;
            Temp = *First;
            
            *First = (*First)->next;
            free (Temp);

        }
    }

void DeleteLast(PPNODE First)
{
    if(*First == NULL)
    {   
        printf("List is empty....");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else 
    {
        PNODE Temp = *First;
        PNODE Temp1 = NULL;
        while((Temp)->next->next!= NULL)
        {
            Temp = Temp ->next;
        }
        Temp->next = Temp1;
        free(Temp1);
        Temp->next = NULL; 
    }
}

void DeleteAtPose(PPNODE First,int iPos)
{
    int iCount = Count(*First);

    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid Position...");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst(First);
    }
    else if(iPos == iCount)
    {
        DeleteLast(First);
    }
    else 
    {
        PNODE Temp = *First;
        PNODE Temp1 = NULL;
        for(int i = 0;i<iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Temp1 = Temp->next;
        Temp ->next = Temp1 ->next;
        free(Temp1);     

    }
}
int main()
{
    PNODE Head = NULL;
    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);
    Display(Head);
    int iRet = Count(Head);
    printf("THe no of nodes are %d \t \n",iRet);
    
    InsertLast(&Head,101);
    InsertLast(&Head,111);
    InsertLast(&Head,121);
    Display(Head);
    iRet = Count(Head);
    printf("THe no of nodes are %d \t \n",iRet);

    InsertAtPos(&Head,105,4);
    Display(Head);
    iRet = Count(Head);
    printf("THe no of nodes are %d \t \n",iRet);

    DeleteFirst(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("THe no of nodes are %d \t \n",iRet);

    DeleteLast(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("THe no of nodes are %d \t \n",iRet);

    DeleteAtPose(&Head,4);
    Display(Head);
    iRet = Count(Head);
    printf("THe no of nodes are %d \t \n",iRet);

    return 0;
}