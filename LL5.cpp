//Single linked list
#include<iostream>
using namespace std;
class node{
    private:
    int data;
    node *next;
    public: 
    node *head=NULL;
    node *tail=NULL;
   void create();
   void display();
   int max();
   int min();
   void search(int e);
   int length();
   int sum();
   void insert_at_begin(int e);
   void insert_at_end(int e);
   void insert_at_pos(int e,int x);
   void insert_sortedList(int e);
   void delete_at_pos(int x);
   bool isSorted();
   void sort();
   void removeDuplicates_SortedList();
   void reverse_LL( );
   bool isLLloop();
};
void node::create()
{
 node *temp;

int choice,item;
while(choice!=0)
{
    temp=new node;
    cout<<"enter item: "<<endl;
    cin>>item;
    if(head==NULL)
    {
        temp->data=item;
        temp->next=NULL;
        head=temp;
        tail=temp;
    }
    else
    {
       tail->next=temp;
       temp->data=item;
       temp->next=NULL;
       tail=temp;
       }
       cout<<"choice (1/0) :";
         cin>>choice;
         }
        //  tail->next=head;
}
void node::display()
{
    cout<<"The linked list nodes' data are: "<<endl;
    node *p ;
    p=head;
    if(p==NULL){
    cout<<"List is empty"<<endl;
    }
    else{
   do {
      cout<<p->data<<" ";
         p=p->next;
    }while(p!=NULL);
     }
     cout<<endl;
}
int node::max()
{
    int max;
    node *temp;
    temp=head;
    max=INT32_MIN;
    int i=0;
   if(temp==NULL)
   return -3214;
   else
   {
    while(temp!=NULL)
    {
         
        if(max<temp->data)
        {
            max=temp->data;
            
        }
        temp=temp->next;
     }
    return max;
   }
    
}
int node::min()
{
    int min;
    node *temp;
    temp=head;
    min=INT16_MAX;
    int i=0;
    if(temp==NULL)
    return -3214;
    else{
    while(temp!=NULL)
    {
         if(min>temp->data)
        {
           min=temp->data;
        }
        temp=temp->next;
        }
    return min;
    }
    
}
void node::search(int e)
{
    node *p,*temp;
    node *q=NULL;
    p=head;
    temp=head;
    int i=0,f=0;
    while(p!=NULL)
    {
        if(p->data==e)
        {
            cout<<"Element found at index :"<<i+1<<endl;
            if(p==head)
            {
                 f++;
                break;
            }
            q->next=p->next;
            p->next=temp;
            head=p;
            f++;
            break;

        }
         q=p;
        p=p->next;
        i++;
    }
    if(f==0)
    cout<<"Invalid position !"<<endl;

}
int node::length()
{
    node *p=head;
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;

}
int node::sum()
{
    node *p=head;
    int sum=0;
    while(p!=NULL)
    {
   sum+=p->data;
   p=p->next;
    }
    return sum;
}
void node::insert_at_begin(int e)
{
    node *p;
   
    if(head==NULL)
    {
        cout<<"List is empty "<<endl;
         head=new node;
         head->data=e;
         head->next=NULL;

    }
    else{
    p=new node;
    p->data=e;
    p->next=head;
    head=p;
    }

    
}
void node::insert_at_end(int e)
{
    node *p;
 
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
           head=new node;
           head->data=e;
           head->next=NULL;
           tail=head;

    }
    else{
        p=new node;
    tail->next=p;
    p->data=e;
    p->next=NULL;
    tail=p;
    }

    
}
void node::insert_at_pos(int e,int x)
{
    node *p,*temp;
    p=head;
    temp=new node;
     temp->data=e;

    int i=0;
    int l=length();
    cout<<l<<endl;
    if(x<=0 && x>l)
    cout<<"Invalid Position! "<<endl;
    else
    {
    while(i<x-1)
    {
        cout<<x-1<<" "<<i<<endl;
        p=p->next;
        i++;
    }
  temp->next=p->next;
  p->next=temp;
    }
}
    void node::insert_sortedList(int e)
    {
        node *p,*q,*temp;
        p=head;
        int l=length();
        for(int i=1;i<=l;i++)
        {
           if(p->data>e)
           {
             temp=new node;
             temp->next=p->next;
             temp->data=e;
             q->next=temp;

             
           }
           q=p;
           p=p->next;

        }
    }
void node::delete_at_pos(int x)
{
    node *p,*q;
    p=head;
    int l=length();
    if(head==NULL)
    cout<<"List is empty "<<endl;
    else if(x<0 && x>l)
    {
    cout<<"Inlvalid positon "<<endl;
    }
    else if (x==1)
    {
        head=p->next;
        free(p);
    }
    else{
        for(int i=0;i<x-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);

    }
}
bool node::isSorted()
{
    node *p;
    p=head;
    int x=INT16_MIN;
    int l=length();
    for(int i=0;i<l;i++)
    {
        if(p->data<x )
            return false;
        
        x=p->data;
        p=p->next;
    }
   
    return true;
}
void node::sort()
{
    node *p,*q;
    int temp;
    p=head->next;
    q=head;
    int l=length();
    for(int i=0;i<l-1;i++)
    {
        
            if(p->data < q->data)
            {
               temp=p->data;
               p->data=q->data;
               p->data=temp;
            }
            q=p;
            p=p->next;
        

    }

}
void node::removeDuplicates_SortedList()
{
    node *p,*q;
    q=head;
    p=head->next;
    while(p!=NULL)
    {
        if(q->data==p->data){
        q->next=p->next;
        free(p);
        p=q->next;
        
        }
        else{
        q=p;
        p=p->next;
        }
    }
}
void node::reverse_LL()
{
    //using Array Method
   /* node *p;
    p=head;
    int l=length();
    int i=0,a[l-1];
    while(p!=NULL)
    {
        a[i]=p->data;
        i++;
        p=p->next;
    }
    cout<<endl;
    p=head,i--;
    while(p!=NULL)
    {
        p->data=a[i--];
        p=p->next;
    }
    */
   //using slide pointer
   node *p,*q,*r;
   r=NULL;
   q=NULL;
   p=head;
   while(p!=NULL)
   { 
    r=q;
    q=p;
    p=p->next;
    q->next=r;
       
   }
   head=q;
   //using recursion
  /* while(p!=NULL)
   {
     reverse_LL(p->next);
     cout<<p->data<<" ";
   }*/
 }
 bool node::isLLloop()
 {
    node *p,*q;
    p=q=head;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;

    }while((p && q) && p!=q);
    if(p==q)
    return true;
    else
    return false;

 }


int main()
{
    node a;
    int choice,ele,pos;
    do{
        cout<<"\n\n1)create\n2)display\n3)Max\n4)Min\n5)Search\n6)length\n7)Sum\n8)insert at begin\n";
        cout<<"9)insert at end\n10)insert at positon\n11)Insert element in Sorted List\n";
        cout<<"12)Delete at postion\n13)isSorted\n14)Remove Duplicates in sorted list\n15)Reverse the Linked List\n16)isLLloop\n17)Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:a.create();
                    break;
            case 2: a.display();
                   break;
            case 3: cout<<"Max : "<<a.max()<<endl;
                   break;
            case 4: cout<<"Min : "<<a.min()<<endl;
                    break;
            case 5:cout<<"Enter element : ";
                  cin>>ele;
                  a.search( ele);
                  break;
            case 6:cout<<"Length: "<<a.length()<<endl;
                    break;
            case 7:cout<<"Sum : "<<a.sum()<<endl;
                   break;
            case 8:cout<<"Enter element: ";
                  cin>>ele;
                  a.insert_at_begin(ele);
                  break;
            case 9:cout<<"Enter element: ";
                  cin>>ele;
                  a.insert_at_end(ele);
                  break;
            case 10:cout<<"enter positon :";
                    cin>>pos;
                    cout<<"enter element:";
                    cin>>ele;
                    a.insert_at_pos(ele,pos);
                    break;
            case 11:cout<<"Enter element : ";
                   cin>>ele;
                   a.insert_sortedList(ele);
                   break;
            case 12:cout<<"Enter positon: ";
                    cin>>pos;
                    a.delete_at_pos(pos);
                    break;
            case 13: if(a.isSorted())
                     cout<<"List is already sorted"<<endl;
                     else
                     a.sort();
                     break;
            case 14:a.removeDuplicates_SortedList();
                    break;
            case 15:a.reverse_LL();
                    break;
            case 16:if(a.isLLloop())
                    cout<<"LL forms a loop"<<endl;
                    else
                    cout<<"Linear LL"<<endl;
                    break;
            case 17: exit(0);
                    break;
            default:cout<<"Enter valid choice !"<<endl;
                   break;
                    
        }
    }while(choice!=17);
}