#include<iostream>
using namespace std;

class Node
{
	public:
	int info;
	Node *next;
	Node(int value)
	{
		info=value;
		next=NULL;
	}
};
class LinkedList
{
	public:
	Node *start;
	LinkedList()
	{
		start=NULL;
	}
	void create_LinkedList();
	void displayList();t
	void add_In_Begining();
	void add_AtTheEnd();
	void add_AfterTheSpecifiedPosition(int val, int pos);
	void delete_FromBegining();
	void delete_FromEnd();
	void delete_SpecifiedNode(int nodeNumer);
	int countNode();
	void search_In_list(int val);
};
void LinkedList::create_LinkedList()
{
	Node *temp;
	temp=start;
	int value;
	cout<<"Enter value of Newnode: ";
	cin>>value;
	Node *Newnode=new Node(value);
	if(start==NULL)
	{
		start=Newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}

		temp->next=Newnode;
	}
	cout<<"Newnode has been added at the end of the list"<<endl;
}
void LinkedList::displayList()
{
	Node *temp=start;
	if(start==NULL)
	{
		cout<<"Linked list is empty, there is no Node"<<endl;
	}
	else
	{
	    cout<<"Elements in the list are as follows: ";
		while(temp!=NULL)
		{
		cout<<temp->info<<"\t";
		temp=temp->next;
		}
        cout<<endl;
	}

}
int LinkedList::countNode()
{
	Node *temp=start;
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}
void LinkedList::add_In_Begining()
{
	int value;
	cout<<"Enter value of new node :";
	cin>>value;
	Node *Newnode= new Node(value);
	Newnode->next=start;
	start=Newnode;
	cout<<"Newnode has been added at the begining of the list"<<endl;
}
void LinkedList::add_AtTheEnd()
{
	Node *temp;
	temp=start;
	int value;
	cout<<"Enter value of Newnode: ";
	cin>>value;
	Node *Newnode=new Node(value);
	if(start==NULL)
	{
		start=Newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}

		temp->next=Newnode;
	}
	cout<<"Newnode has been added at end of the list"<<endl;
}
void LinkedList::add_AfterTheSpecifiedPosition(int val, int pos)
{
	Node *temp=start;
	Node *Newnode=new Node(val);
	int count=countNode();
	if(pos>count)
	{
		cout<<"This is the invalid position to insert the node"<<endl;
	}
	else
	{
		if(start==NULL)
		{
			start=Newnode;
		}
		else if(pos==0)
		{
			Newnode->next=start;
			start=Newnode;
		}
		else
		{
			for(int i=1;i<pos;i++)
			{
				temp=temp->next;
			}
			Newnode->next=temp->next;
			temp->next=Newnode;
		}
		if(pos==0)
		{
			cout<<"Newnode has been added in the begining of list as 1st node "<<endl;
		}
		else
		{
			cout<<"Newnode has been added after node "<<pos<<endl;
		}
	}

}
void LinkedList::delete_FromBegining()
{
	Node *temp=start;
	int data;
	if(start==NULL)
	{
		cout<<"List is empty, there is no Node to delete"<<endl;
	}
	else
	{
		start=start->next;
		data=temp->info;
		delete(temp);
		cout<<data<<" has been deleted"<<endl;
		cout<<"List after deletion : ";
		displayList();
	}
}
void LinkedList::delete_FromEnd()
{
	Node *temp;
	Node *temp1;
	int data;
	if(start==NULL)
	{
		cout<<"List is empty, there is no Node to delete"<<endl;
	}
	else if(start->next==NULL)
	{
		temp=start;
		start=NULL;
		data=temp->info;
		delete(temp);
		cout<<data<<" has been deleted"<<endl;
		cout<<"List after deletion : ";
		displayList();
	}
	else
	{
		temp=start;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		data=temp1->info;
		delete(temp1);=
		temp->next=NULL;
		cout<<data<<" has been deleted "<<endl;
		cout<<"List after deletion : ";
		displayList();
	}
}
void LinkedList::delete_SpecifiedNode(int nodeNumer)
{
	Node *temp;
	Node *temp1;
	int data;
	int count=countNode();
	if(nodeNumer>count)
	{
		cout<<"Invalid request"<<<endl;
		
	}
	else if(start==NULL)
	{
		cout<<"List is empty, there is no NODE to delete"<<endl;
	
	}
	else
	{
		if(nodeNumer==1)
		{
			temp=start;
			start=start->next;
			data=temp->info;
			delete(temp);
			cout<<data<<" has been deleted "<<endl;
		}
		else if(nodeNumer>=2&&nodeNumer==count)
		{
			temp=start;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			temp1=temp->next;
			temp->next=NULL;
			data=temp1->info;
			delete(temp1);
			cout<<data<<" has been deleted "<<endl;
		}
		else if(nodeNumer>=2 && nodeNumer<count)
		{
			temp=start;
			for(int i=1;i<nodeNumer-1;i++)
			{
				temp=temp->next;
			}
			temp1=temp->next;
			temp->next=temp1->next;
			data=temp1->info;
			delete(temp1);
			cout<<data<<" has been deleted "<<endl;
		}
	}
}
void LinkedList::search_In_list(int val)
{
	Node *temp=start;
	int count=0,flag=0;
	if(start==NULL)
	{
		cout<<val<<"not found,list is empty"<<endl;
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
			cout<<val<<"  found in node "<<count<<endl;
		}
		else
		{
			cout<<val<<"  not found, in the whole linkedlist";
		}
	}
}
int main()
{
	char choice;
	int n;
	int val,pos,se;
	int nodeNumer;
	LinkedList L1; //of bject of LinkedList clas
	do
	{
		cout<<"\n\n-------Menu options--------"<<endl;
		cout<<"Enter 1 to create linked list "<<endl;
		cout<<"press 2. to display linked list "<<endl;
		cout<<"press 3. to add node in the Begining of the list"<<endl;
		cout<<"press 4. to add node at the End of the list"<<endl;
		cout<<"press 5. to add node at the specified position in the list"<<endl;
		cout<<"press 6. to Delete the node from the Begining of the list"<<endl;
		cout<<"press 7. to Delete the node from the End of the list";
		cout<<"press 8. to Delete the node from the specified position in the list"<<endl;
		cout<<"press 9. to search the element in the linked list"<<endl;
		cout<<"press 0. to exit"<<endl;
        cout<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
        cout<<endl;
		switch(choice)
		{
			case '1':
				cout<<"How many nodes you want to create and add in the List: ";
				cin>>n;
				for(int i=1;i<=n;i++)
				{
					L1.create_LinkedList();
				}
				break;
			case '2':
				L1.displayList();
				break;
			case '3':
				L1.add_In_Begining();
				break;
			case '4':
				L1.add_AtTheEnd();
				break;
			case '5':
				cout<<"Enter value of node to be inserted: ";
				cin>>val;
				cout<<"Enter position after which node should be inserted: ";
				cin>>pos;
				L1.add_AfterTheSpecifiedPosition(val,pos);
				break;
			case '6':
				L1.delete_FromBegining();
				break;
			case '7':
				L1.delete_FromEnd();
				break;
			case '8':
				cout<<"Enter the Node number which you want to delete: ";
				cin>>nodeNumer;
				L1.delete_SpecifiedNode(nodeNumer);
				break;
			case '9':
				cout<<"Enter value which you want to search in the list: ";
				cin>>se;
				L1.search_In_list(se);
				break;
			case '0':
				cout<<"Program Terminated";
				break;
			default:
				cout<<"Invalid Entry";
		}
	}
	while(choice!='0');
}