#include <iostream>
#include <string>
using namespace std;
class LIST
{
public:
int info;
LIST *next;
};
class LINKED_LIST
{
LIST *head;
int count;
public:
LINKED_LIST()
{
head = NULL;
count=0;
}
void InsertF();
void DeleteF();
void Delatpos();
void Display_List();
void Addatpos();
};
void LINKED_LIST::InsertF()
{
LIST *temp;
int item;
cout << "Enter the data: ";
cin >> item; cout << endl;
temp = new LIST;
temp->info = item;
temp->next = NULL;
if(head == NULL)
{
    head = temp;
    count++;
    
}
else
{
    temp->next = head;
head = temp;
count++;
}
    
}
void LINKED_LIST::Addatpos()
{
LIST *n;
int p;
cout<<endl<<"Enter position:";
cin>>p;
n=new LIST;
n->next=NULL;
cout<<endl<<"Enter data:";
cin>>n->info;
if(p==1)
{
n->next=head;
head=n;
count++;
}
else
{
int i=1;
LIST *temp;
temp=head;
while(i<=p-2)
{
temp=temp->next;
i++;
}
n->next=temp->next;
temp->next=n;
count++;
}
return;
}


void LINKED_LIST::DeleteF()
{
LIST *temp;
if(head == NULL)
cout << "No data is present to delete" << endl;
else
{
temp = head;
head = head->next;
cout << "The deleted data is: " << temp->info << endl;
delete temp;
count--;
}
}
void LINKED_LIST::Delatpos()
{
LIST *temp;
int i,p;
cout<<endl<<"Enter position:";
cin>>p;
if(count<p)
cout<<"Linked list does not have "<<p<<" position";
if(p==1)
{
    temp=head;
head=head->next;
delete temp;
count--;
return;
}

temp=head;
i=1;
while(i<p && temp!=NULL)
{
temp=temp->next;
i++;
}
temp->next=temp->next->next;
count--;
return;
}
void LINKED_LIST::Display_List()
{
if(head == NULL)
cout << "No data is present to dis[play" << endl;
else
{
    cout<<"\n count"<<count<<endl;
for(LIST *temp = head; temp != NULL; temp =temp->next)
cout << temp->info << "->";
cout<<"NULL";
}
}
int main()
{
LINKED_LIST s1;

int ch=1;
while(ch)
{
cout << "\n1 Insert_front\n2.Addatpos\n3 Delete_front\n4.Delatpos\n5.Display List\n0 Exit\n";
cin >> ch;
switch(ch)
{
case 1 : s1.InsertF();break;
case 2 :s1.Addatpos();s1.Display_List();break;
case 3: s1.DeleteF();s1.Display_List();break;
case 4 :s1.Delatpos();s1.Display_List();break;
case 5 : s1.Display_List();break;
default: cout << "Wrong choice!" << endl;
cout << "Enter the choice again, with 0 to quit" <<endl;
cin >> ch;
}//end switch
} //end while(ch)
return 0;
}//end main()