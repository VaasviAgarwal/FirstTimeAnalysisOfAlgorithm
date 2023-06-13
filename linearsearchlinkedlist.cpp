#include <iostream>
using namespace std;

class Node
{
    public:
    int info;
    Node *next;
    Node(int value)
    {
        info = value;
        next = NULL;
    }
};

class LinearSearch
{
    public:
    Node *start;
    LinearSearch()
    {
        start = NULL;
    }
    void addNode();
    void displayList();
    void search(int val);
};

void LinearSearch::addNode()
{
    Node *temp=start;
    int value;
    cin>>value;
    Node *Newnode = new Node(value);
    if(start==NULL)
    {
        start = Newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next=Newnode;
    }
}

void LinearSearch::displayList()
{
    Node *temp=start;
    if(start == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        cout<<"List :  ";
        while(temp!=NULL)
        {
            cout<<temp->info<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void LinearSearch::search(int val)
{
    Node *temp=start;
    int count=0, flag=0;
    if(start==NULL)
    {
        cout<<"Element not present in list"<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            count++;
            if(temp->info==val)
            {
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==1)
        {
            cout<<"Element present at Node "<<count<<endl;
        }
        else
        {
            cout<<"Element not present in List"<<endl;
        }
    }
}

int main()
{
    LinearSearch ls;
    int n;
    cout<<"Enter number of nodes you wish to create : ";
    cin>>n;
    cout<<"Enter the nodes :"<<endl;
    for(int i=0;i<n;i++)
    {
        ls.addNode();
    }
    ls.displayList();
    cout<<"Enter element to be searched : ";
    int x;
    cin>>x;
    ls.search(x);
}