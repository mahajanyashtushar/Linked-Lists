// doubly Linear Linked list in java

import java.util.*;

class dbll 
{
    public static void main(String arg[])
    {
        doublyLL dobj = new doublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);
        dobj.Display();

        dobj.InsertLast(101);
        dobj.InsertLast(111);
        dobj.InsertLast(121);
        dobj.Display();

        dobj.DeleteFirst();
        dobj.Display();

        dobj.DeleteLast();
        dobj.Display();

    }
}
class Node
{
    public int data;
    public Node next;
    public Node prev;

    public Node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}
class doublyLL
{
    private int Count;
    private Node Head;
    private Node Tail;

    public doublyLL()
    {
        this.Count = 0;
        this.Head = null;
        this.Tail = null; 
    }

    public void InsertFirst(int no)
    {
        Node newn = new Node(no);

        if(Head == null && Tail == null)
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            newn.next = Head;
            Head.prev = newn;
            Head = newn;
        }
        this.Count++;
    }
    public void InsertLast(int no)
    {
        Node newn = new Node(no);

        if(Head == null && Tail == null)
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail.next = newn;
            newn.prev = Tail;
            Tail= Tail.next;
        }
        this.Count++;
    }
    public void InsertAtPos(int no, int iPos)
    {
        Node newn = new Node(no);
        if(iPos <1 || iPos > Count+1)
        {
            return;
        }
        else if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos>Count)
        {
            InsertLast(no);
        }
        else
        {
            Node temp = Head;
            for(int i =1;i<iPos-1;i++)
            {
                temp = temp.next;
            }
            Node temp1 = temp.next;
            newn.next = temp1;
            temp1.prev = newn;
            temp.next = newn;
            newn.prev = temp;
        }
        this.Count++;
    }
    public void DeleteFirst()
    {
        if(Count ==0)
        {
            return;
        }
        else if(Count == 1)
        {
            Head = null;
            Tail = null;
        }
        else
        {
            Head = Head.next;
            Head.prev = null;
        }
        this.Count--;
    }
    public void DeleteLast()
    {
        if(Count ==0)
        {
            return;
        }
        else if(Count == 1)
        {
            Head = null;
            Tail = null;
        }
        else
        {
            Node temp = Head;
        Tail=Tail.prev;
        Tail.next= null;
        this.Count--;
        }
        
    }
    public void DeleteAtPos(int iPos)
    {
        if(iPos <0 || iPos>Count)
        {
            return;
        }
        else if(iPos == 1)
        {
            DeleteFirst();
        }
        else if (iPos == Count)
        {
            DeleteLast();
        }
        else
        {
            Node temp = Head;
            for(int i=1;i<iPos-1;iPos++)
            {
                temp = temp.next;
            }
            Node temp1 = temp.next;
            temp.next=temp1.next;
            temp1.next.prev = temp;
            this.Count--;
        }
    }
    public void Display()
    {
        Node temp =Head;
        while(temp != null)
        {
            System.out.print("|"+temp.data+"|->");
            temp=temp.next;
        }
        System.out.println("null");
    }
    public int count()
    {
        return this.Count;
    }
}
