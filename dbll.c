// Singly Circular Linkedlist

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
  newn ->data = no;
  newn ->next = NULL;
  newn -> prev = NULL;

  if((*First) == NULL && (*Last) == NULL)
  {
    (*First) = (*Last) = newn;
    (*Last) ->next = *First;
  }  
  else
  {
    newn ->next = *First;
    (*First) ->prev = newn;
    *First = newn;
     (*Last) ->next = *First;
  }
   
}

void InsertLast(PPNODE First,PPNODE Last,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
  newn ->data = no;
  newn ->next = NULL;
  newn -> prev = NULL;

  if((*First) == NULL && (*Last) == NULL)
  {
    (*First) = (*Last) = newn;
    (*Last) ->next = *First;
  }  

  else
  {
    PNODE Temp = *First;
    PNODE temp1 = NULL;
    do
    {
      Temp = Temp ->next;
    }while(Temp != (*Last)->next);
    (*Last) ->next = newn;
    newn ->prev = *Last;
    *Last = (*Last)->next ;
    (*Last)->next = *First;
  }
}
void Display(PNODE First,PNODE Last)
{
    PNODE Temp = First;
    do
    {
        printf("|%d|<=>",Temp->data);
        Temp = Temp ->next;
    }while(Temp != Last->next);
    printf("    \n");
}

void DeleteFirst(PPNODE First,PPNODE Last)
{
    if(*First == NULL || *Last == NULL)
    {
        printf("Empty LinkedList \n");
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
        *First = (*First)->next;
        (*First) ->prev = NULL;
        free(Temp);
        (*Last)->next = *First;
    }
}
void DeleteLast(PPNODE First,PPNODE Last)
{
    if(*First == NULL || *Last == NULL)
    {
        printf("Empty LinkedList \n");
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
        *Last = (*Last) ->prev;
        free(temp);
        (*Last) ->next =*First;
    }
}

int Count (PNODE First,PNODE Last)
{
    int iCnt = 0;
    PNODE temp = First;
    do
    {
    
        iCnt++;
        temp = temp->next;
    }while(temp != Last->next);
    return iCnt;
}
void InsertAtPos(PPNODE First,PPNODE Last,int no,int iPos)
{
    int iCount = Count(*First,*Last);

    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn ->data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(iPos < 1 || iPos > iCount+1)
    {   
        printf("intvalid Postion");
        return;
    } 
    else if(iPos == 1)
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
        int no = 0;
        do
        {
            no++;
            temp = temp->next;
        }while(no != iPos-1);
    PNODE Temp1 = temp ->next;
    newn ->next = Temp1;
    newn ->prev = temp;
    (*Last)->next = *First;
    }
}

void DeleteAtPose(PPNODE First,PPNODE Last,int iPos)
{
    int iCount = Count(*First,*Last);
    if(iPos < 1 || iPos > iCount+1)
    {   
        printf("intvalid Postion");
        return;
    } 
    else if(iPos == 1)
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
        for(int i = 0;i<iPos-2;i++)
        {
            temp = temp -> next;
        }
        PNODE Temp1 = temp->next;
        temp ->next = Temp1->next;
        Temp1 ->next ->prev = temp;
        free(Temp1);
        (*Last)->next = *First;      
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
    InsertLast(&Head,&Tail,121);
    Display(Head,Tail);

    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);

    DeleteLast(&Head,&Tail);
    Display(Head,Tail);

    InsertAtPos(&Head,&Tail,105,5);
    Display(Head,Tail);
    DeleteAtPose(&Head,&Tail,2);
    Display(Head,Tail);

    return 0;
}