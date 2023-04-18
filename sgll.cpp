# include<iostream>
# pragma pack(1)
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyLL
{
  public:
    PNODE First; 
    SinglyLL();
    void InsertFirst(int no);
    void InsertLast(int no);
    void InsertatPos(int no,int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void Display();
    int Count();
};

SinglyLL::SinglyLL()
{
  First = NULL;
}
void SinglyLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn ->data = no;
    newn ->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}
void SinglyLL:: InsertLast(int no)
{
    PNODE newn = new NODE;
    newn ->data = no;
    newn ->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void SinglyLL:: DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"The Linked List is Empty ...\n";
        return;
    }
    else if(First ->next == NULL)
    {
        delete(First);
        First = NULL;
    }
    else 
    {
        PNODE temp = First;
        First = First ->next;
        delete(temp);
    }
}
void SinglyLL:: DeleteLast()
{
     if(First == NULL)
    {
        cout<<"The Linked List is Empty ...\n";
        return;
    }
    else if(First ->next == NULL)
    {
        delete(First);
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        while(temp ->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete(temp->next);

    }
}

void SinglyLL:: Display()
{
    PNODE temp = First;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp ->next;
    }
   cout<<"NULL \n";
}

int  SinglyLL :: Count()
{
    PNODE temp = First;
    int icnt= 0;
    while(temp != NULL)
    {
        icnt++;
        temp = temp ->next;
    }
    return icnt;
}
void SinglyLL :: InsertatPos(int no,int iPos)
{
    int iCount = Count();
    PNODE newn = new NODE;
    newn ->data = no;
    newn ->next = NULL;
    if(iPos <1 || iPos > iCount)
    {
        cout<<"Invalid position \n";
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
        for(int i = 1;i<iPos-1;i++)
        {       
            temp = temp ->next;
        }
        PNODE temp1 = temp->next;
        newn->next = temp1;
        temp->next = newn;
    }
}

void SinglyLL ::DeleteAtPos(int iPos)
{
     int iCount = Count();

    if(iPos <1 || iPos > iCount)
    {
        cout<<"Invalid position \n";
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
        for(int i = 1;i<iPos-2;i++)
        {       
            temp = temp ->next;
        }
        PNODE temp1 = temp->next;
        temp->next = temp1 ->next;
        delete(temp1);
    }
}

int main()
{
   SinglyLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();

    obj.InsertatPos(105,4);
    obj.Display();

    obj.DeleteAtPos(4);
    obj.Display();



    return 0;
}