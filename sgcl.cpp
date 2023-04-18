// Singly Circular Linkedlist

# include<iostream>
using namespace std;

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

class DoublyLL
{
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
DoublyLL:: DoublyLL()
{
    First = NULL;
    Last = NULL;
}
void DoublyLL:: InsertFirst(int no)
{
  PNODE newn = new (NODE);
  newn ->data = no;
  newn ->next = NULL;
  newn -> prev = NULL;

  if((First) == NULL && (Last) == NULL)
  {
    (First) = (Last) = newn;
    (Last) ->next = First;
  }  
  else
  {
    newn ->next = First;
    (First) ->prev = newn;
    First = newn;
     (Last) ->next = First;
  }
   
}

void DoublyLL:: InsertLast(int no)
{
    PNODE newn = new (NODE);
  newn ->data = no;
  newn ->next = NULL;
  newn -> prev = NULL;

  if((First) == NULL && (Last) == NULL)
  {
    (First) = (Last) = newn;
    (Last) ->next = First;
  }  

  else
  {
    PNODE Temp = First;
    PNODE temp1 = NULL;
    do
    {
      Temp = Temp ->next;
    }while(Temp != (Last)->next);
    (Last) ->next = newn;
    newn ->prev = Last;
    Last = (Last)->next ;
    (Last)->next = First;
  }
}
void DoublyLL:: Display()
{
    PNODE Temp = First;
    do
    {
        cout<<"|"<<Temp->data<<"|<->";
        Temp = Temp ->next;
    }while(Temp != Last->next);
    cout<<endl;
}

void DoublyLL:: DeleteFirst()
{
    if(First == NULL || Last == NULL)
    {
       cout<<"Empty LinkedList \n";
        return;
    }
    else if((First) ->next == NULL)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        PNODE Temp = First;
        First = (First)->next;
        (First) ->prev = NULL;
        delete(Temp);
        (Last)->next = First;
    }
}

void DoublyLL:: DeleteLast()
{
    if(First == NULL || Last == NULL)
    {
       cout<<"Empty LinkedList \n";
        return;
    }
    else if((First) ->next == NULL)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        PNODE temp = Last;
        Last = (Last) ->prev;
        delete(temp);
        (Last) ->next =First;
    }
}


int DoublyLL::Count ()
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
void DoublyLL:: InsertAtPos(int no,int iPos)
{
    int iCount = Count();

    PNODE newn = new (NODE);
    newn ->data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(iPos < 1 || iPos > iCount+1)
    {   
        cout<<"intvalid Postion";
        return;
    } 
    else if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE temp = First;
        int no = 0;
        do
        {
            no++;
            temp = temp->next;
        }while(no != iPos-1);
    PNODE Temp1 = temp ->next;
    newn ->next = Temp1;
    newn ->prev = temp;
    (Last)->next = First;
    }
}

void DoublyLL:: DeleteAtPose(int iPos)
{
    int iCount = Count();
    if(iPos < 1 || iPos > iCount+1)
    {   
        cout<<"intvalid Postion \n";
        return;
    } 
    else if(iPos == 1)
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
        for(int i = 0;i<iPos-2;i++)
        {
            temp = temp -> next;
        }
        PNODE Temp1 = temp->next;
        temp ->next = Temp1->next;
        Temp1 ->next ->prev = temp;
       delete(Temp1);
        (Last)->next = First;      
    }
}
int main()
{
   DoublyLL sobj;

   sobj.InsertFirst(51);
   sobj.InsertFirst(21);
   sobj.InsertFirst(11);
   sobj.Display();

   sobj.InsertLast(101);
   sobj.InsertLast(111);
   sobj.InsertLast(121);
  sobj. Display();

   sobj.InsertAtPos(105,4);
   sobj.Display();

   sobj.DeleteAtPose(4);
   sobj.Display();

    return 0;
}