import java.util.*;

class sgll
{
    public static void main(String arg[])
    {
        SinglyLL sobj = new SinglyLL();
        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);
        sobj.Display();

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);
        sobj.Display();

        sobj.InsertAtPos(105,4);
        sobj.Display();

        sobj.DeleteAtPos(4);
        sobj.Display();
    }

}
class Node
{
    public int data;
    public Node next;

    public Node(int no)
    {
        data = no;
        next = null;
    }
}
class SinglyLL
{
    private Node Head;
    private int Count;

    public  SinglyLL()
    {
        this.Head = null;
        this.Count = 0;
    }

    protected void finalize()
    {

    }

    public void InsertFirst(int no)
    {
        Node newn = new Node(no);
        if(this.Head == null)
        {   
            Head = newn;
        }
        else
        {
            newn.next = Head;
            this.Head = newn;
        }
        this.Count++;
    }
    public void InsertLast(int no)
    {
        Node newn = new Node(no);
        if(this.Head == null)
        {   
            Head = newn;
        }
        else
        {
            Node Temp = this.Head;
            while(Temp.next!= null)
            {
                
                Temp= Temp.next;
            }
            Temp.next = newn;
        }
        this.Count++;
    }
    public void InsertAtPos(int no,int iPos)
    {
        Node newn = new Node(no);
        if(iPos < 1 || iPos > Count+1)
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(iPos ==1)
        {
            InsertFirst(no);
        }
        else if(iPos >Count)
        {
            InsertLast(no);
        }
        else
        {
            Node Temp = this.Head;

            for(int i = 1;i<iPos-1;i++)
            {
               Temp = Temp.next; 
            }
            Node Temp1= Temp.next;
            newn.next = Temp1;
            Temp.next = newn;
        }
        this.Count++;
    }
    public void DeleteFirst()
    {
        if(Head == null)
        {
            System.out.println("The Linked List is empty");
            return;
        }
        else if(Head.next ==null)
        {
            Head = null;
        }
        else
        {
            Head = Head.next;
        }
        this.Count--;
    }
    public void DeleteLast()
    {
        if(Head == null)
        {
            System.out.println("The Linked List is empty");
            return;
        }
        else if(Head.next == null)
        {
            Head = null;
        }
        else
        {
            Node Temp = this.Head;
            while(Temp.next.next != null)
            {
                Temp = Temp.next;
            }
           Temp.next = null;
            
        }
         this.Count--;
    }
    public void DeleteAtPos(int iPos)
    {
        if(this.Count == 0)
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(iPos==1)
        {
            DeleteFirst();
        }
        else if(iPos == Count)
        {
            DeleteLast();
        }
        else
        {
            Node Temp = this.Head;
            for(int i =1;i<iPos-1;i++)
            {
                Temp = Temp.next;
            }
            Node Temp1 = Temp.next;
            Temp.next = Temp1.next;
        }
        this.Count--;
    }  
    public void Display()
    {
        Node temp = this.Head;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" |->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }
    public int Count()
    {
        return this.Count;
    }
}
