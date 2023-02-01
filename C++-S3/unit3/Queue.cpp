#include<iostream>
using namespace std;
class queue
{
    public:
    int f,r,n;
    int *a;
    queue()
    {
        
    }
    queue(int s)
    {
        f=-1;
        r=-1;
        n=s;
        a=new int[n];
    }
    void enqueue(int item)
    {
        if((r+1)%n==f)
        {
        cout<<"queue is full";
        }
        else if(f==-1 && r==-1)
        {
            f=r=0;
            a[r]=item;
        }
        else
        r=(r+1)%n;
        a[r]=item;
    }
    int dequeue()
    {
        if(f==r==-1){
        cout<<"queue is empty";
        }
        int res=a[f];
        if(r==f)//only when 1 element is there
        {
            r=f=-1;
        }
        else
        {
        f=(f+1)%n;
        }
        return res;
    }
    void display()
    {
        int i=f;
        if(f==-1 || r==-1)
        {
        cout<<"no elements to display";
        }
        else
        {
        cout<<"queue is";
        while(i!=r)
        {
        cout<<a[i];
        i=(i+1)%n;
        }
        cout<<a[r];
    }
    }
};
int main()
{
    int n;
    cout<<"enter array size:";
    cin>>n;
    queue q(n);
    int ch,e=1;
    int x;
    do
    {
        cout<<"\n1.enqueue\n2.dequeue\n3.display\n";
        cout<<"enter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"enter element to add:";
            cin>>x;
            q.enqueue(x);break;
            case 2:q.dequeue();break;
            case 3:q.display();break;
            default:e=0;break;
        }
    }
    while(e);
}