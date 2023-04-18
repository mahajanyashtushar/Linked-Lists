//SiglyCL in java;

import java.util.*;

class sgcl
{
    public static void main(String arg[])
    {
        SiglyCL sobj = new SiglyCL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);
        sobj.Display();
       
        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);
        sobj.Display();
 
        sobj.DeleteFirst();
        sobj.Display();

        //sobj.DeleteLast();
        sobj.Display();
    
    }
}
class Node
{
    public int data;
    public Node next;

    public Node(int no)
    {
        this.data = no;
        this.next = null; 
    }
}
class SiglyCL
{
    private Node Head;
    private Node Tail;
    private int Count;

    public SiglyCL()
    {
        this.Head = null;
        this.Tail = null;
        this.Count = 0;
    }
    public void InsertFirst(int no)
    {
         Node newn = new Node(no);
         
         if(this.Head == null && this.Tail == null)
         {
            Head = newn;
            Tail = newn;
         }
         else
         {
            newn.next = Head;
            Head = newn;
         }
         Tail.next = Head;
         this.Count++;
    }
    public void InsertLast(int no)
    {
        Node newn = new Node(no);
        if(this.Head == null && this.Tail == null)
         {
            Head = newn;
            Tail = newn;
         }
        Tail.next = newn;
        Tail = Tail.next;
        Tail.next = Head;
        this.Count++;
    }
    public void InsertAtPos(int no,int iPos)
    {
        Node newn = new Node(no);
        if(iPos <1 && iPos > Count+1)
        {
            return;
        }
        else if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos >Count)
        {
            InsertLast(no);
        }
        else
        {
            Node temp = this.Head;
            for(int i = 1;i<iPos-1;i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            Tail.next = Head;
            this.Count++;
        }
    }
    public void DeleteFirst()
    {
        if(Count== 0)
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
            Tail.next = Head;
        }
        this.Count--;
    }
    public void DeleteLast()
    {
        if(Count== 0)
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
            Node temp = this.Head;
            while(temp.next.next !=null)
            {
                temp=temp.next;
            }
            Tail = temp;
            Tail.next = Head;
        }
        this.Count--;
    }
    public void DeleteAtPos(int iPos)
    {
        if(iPos <0 || iPos >Count)
        {
            return;
        }
        else if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == Count)
        {
            DeleteLast();
        }
        else
        {
            Node temp = Head;
            for(int i = 1;i<iPos-1;i++)
            {
                temp = temp.next;
            }
            Node temp1 = temp.next;
            temp.next = temp1.next;
            Tail.next = Head;
        }
    }
    public void Display()
    {
      Node temp = Head;
      do
      {
        System.out.print("|"+temp.data+"|->");
        temp = temp.next;
      }while(temp != Tail.next);
      System.out.println();
    }
    public int count()
    {
        return this.Count;
    }

}
