// Doubly circular LinkedList

# include<stdio.h>
using namespace std;
struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class DoublyCL
{
    public:
        public:
        PNODE First;
        PNODE Last;

        DoublyLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPose(int iPos);
        void Display();
        int Count();

};

DoublyCL::DoublyCL()
{
    First = NULL;
    Last = NULL;
}
void DoublyCL:: InsertFirst(int no)
{
    PNODE newn = new (NODE);
    newn -> data = no;
    newn ->next = NULL;
    newn ->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = Last = newn;
        (Last) ->next = First;
        (First)->prev = Last;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn; 
        First = newn;
        (Last) ->next = First;
        (First)->prev = Last;
    }
}
void DoublyCL:: Display()
{
    PNODE temp = First;
    do
    {
        cout<<"| "<<temp->data<< "|<=>";
        temp = temp->next;
    }while(temp!= Last->next);
   cout<<endl;
}

void DoublyCL:: InsertLast(int no)
{
    PNODE newn = new NODE;
    newn -> data = no;
    newn ->next = NULL;
    newn ->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = Last = newn;
        (Last) ->next = First;
        (First)->prev = Last;
    }
    else
    {
        (Last) ->next = newn;
        newn ->prev = Last;
        Last = (Last) ->next;
        (Last) ->next = First;
        (First)->prev = Last;
    } 
}
void DoublyCL:: DeleteFirst()
{
    if(First == NULL || Last == NULL)
    {
        return;
    }
    else if((First) ->next == NULL)
    {
        free(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        PNODE Temp = *First;
        First = (First) ->next;
        free(Temp);
        (Last) ->next = First;
        (First)->prev = Last;

    }
}
void DoublyCL:: DeleteLast()
{
     if(First == NULL || Last == NULL)
    {
        return;
    }
    else if((First) ->next == NULL)
    {
        free(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
      PNODE temp = Last;
      Last =  (Last)->prev;
      delete(temp);
        (Last) ->next = First;
        (First)->prev = Last;
    }
}
int DoublyCL:: Count()
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
void  DoublyCL::InsertAtPos(int no,int iPos)
{
    int iCount = Count(First,Last);

     PNODE newn = new (NODE);
    newn -> data = no;
    newn ->next = NULL;
    newn ->prev = NULL;

    if(iPos<1 || iPos >iCount)
    {
        count<<"Invalid Position \n";
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
        (Last) ->next = First;
        (First)->prev = Last;
    }
}
void DoublyCL:: DeleteAtPose(int iPos)
{
    int iCount = Count(First,Last);
    if(iPos<1 || iPos >iCount)
    {
        cout<<"Invalid Position \n";
        return;
    }
    else if(iPos  == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
         PNODE temp = First;

        for(int i = 1;i<iPos-1;i++)
        {
            temp = temp ->next;
        }
        PNODE temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        delete(temp1);
        (Last) ->next = First;
        (First)->prev = Last;
    }
}
int main()
{   
    DoublyCL dobj;
    dobj.InsertFirst(51);
    dobj.InsertFirst(51);
    dobj.InsertFirst(51);
    dobj.Display();

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    dobj.Display();

    dobj.DeleteFirst();
    dobj.Display();

    dobj.DeleteLast();
    dobj.Display();

    dobj.InsertAtPos(105,4);
    Display();
    dobj.DeleteAtPos(4);
    Display();

    return 0;

}