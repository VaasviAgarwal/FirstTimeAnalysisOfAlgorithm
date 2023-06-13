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

class Circular_LinkedList
{
	public:
	Node *start;
	Node *end;
	Circular_LinkedList()
	{
		start=NULL;
		end=NULL;
	}

	void create_CircularLinkedList();
	void display_CircularList();=
	void add_In_Begining();
	void add_AtTheEnd();
	void add_AfterTheSpecifiedPosition(int val, int pos);
	void delete_FromBegining();
	void delete_FromEnd();
	void delete_SpecifiedNode(int nodeNumer);
	int countNode();
	void search_In_list(int val);
};

void Circular_LinkedList::create_CircularLinkedList()
{
	int value;
	cout<<"Enter value of Newnode: ";
	cin>>value;
	Node *Newnode=new Node(value);
	if(start==NULL)
	{
		start=Newnode;
		Newnode->next=start;
		end=Newnode;
	}
	else
	{
		Newnode->next=start;
		end->next=Newnode;
		end=Newnode;
	}
	cout<<"Newnode has been added at the end of the list"<<endl;
}

void Circular_LinkedList::display_CircularList()
{
	Node *temp=start;
	if(start==NULL)
	{
		cout<<"Linked list is empty, there is no Node"<<endl;
	}
	else
	{
	    cout<<"Elements in the list are as follows: ";
		while(temp!=end)
		{
			cout<<temp->info<<"\t";
			temp=temp->next;
		}
		cout<<temp->info<<endl;
	}
}

int Circular_LinkedList::countNode()
{
	Node *temp=start;
	int count=0;
	if(start==NULL)
	{
		return count;
	}
	else
	{
		while(temp!=end)
		{
			count++;
			temp=temp->next;
		}
		count++;
		return count;
	}
}

void Circular_LinkedList::add_In_Begining()
{
	int value;
	cout<<"Enter value of new node : ";
	cin>>value;
	Node *Newnode= new Node(value);
	if(start==NULL)
	{
		start=Newnode;
		Newnode->next=start;
		end=Newnode;
	}
	else
	{
		Newnode->next=start;
		start=Newnode;
		end->next=start;
	}
	cout<<"Newnode has been added at the begining of the list"<<endl;
}

void Circular_LinkedList::add_AtTheEnd()
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
		Newnode->next=start;
		end=Newnode;
	}
	else
	{
		end->next=Newnode;
		Newnode->next=start;
		end=Newnode;
	}
	cout<<"New node has been added at the end of the list"<<endl;
}

void Circular_LinkedList::add_AfterTheSpecifiedPosition(int val, int pos)
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
		else if(pos=countNode())
		{
			end->next=Newnode;
			Newnode->next=start;
			end=Newnode;
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

void Circular_LinkedList::delete_FromBegining()
{
	Node *temp;
	int data;
	if(start==NULL)
	{
		cout<<"List is empty, there is no Node to delete"<<endl;
	}
	else
	{
		temp=start;
		start=start->next;
		end->next=start;
		data=temp->info;
		delete(temp);
		cout<<data<<" has been deleted"<<endl;
		cout<<"List after deletion : ";
		display_CircularList();
	}
}

void Circular_LinkedList::delete_FromEnd()
{
	Node *temp;
	Node *temp1;
	int data;
	if(start==NULL)
	{
		cout<<"List is empty, there is no Node to delete";
	}
	else if(start->next==start)
	{
		temp=start;
		start=NULL;
		end=NULL;
		data=temp->info;
		delete(temp);
		cout<<data<<" has been deleted"<<endl;
		cout<<"List after deletion : ";
		display_CircularList();
	}
	else
	{
		temp=start;
		while(temp->next!=end)
		{
			temp=temp->next;
		}
		temp1=end;
		end=temp;
		end->next=start;
		data=temp1->info;
		delete(temp1);
		cout<<data<<" has been deleted"<<endl;
		cout<<"List after deletion : ";
		display_CircularList();
	}
}

void Circular_LinkedList::delete_SpecifiedNode(int nodeNumer)
{
	Node *temp;
	Node *temp1;
	int data;
	int count=countNode();
	if(nodeNumer>count)
	{
		cout<<"Illegal request or list is empty,so request is not accepted";

	}
	else if(start==NULL)
	{
		cout<<"List is empty, there is no NODE to delete";

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

void Circular_LinkedList::search_In_list(int val)
{
	Node *temp=start;
	int count=0,flag=0;
	if(start==NULL)
	{
		cout<<val<<" not found,list is empty"<<endl;
	}
	else
	{
		while(temp!=end)
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
		else if(temp->info==val)
		{
			cout<<val<<"  found in node "<<count+1<<endl;
		}
		else
		{
			cout<<val<<"  not found, in the whole linkedlist"<<endl;
		}

	}
}

int main()
{
	char choice;
	int n;
	int val,pos,se;
	int nodeNumer;
	Circular_LinkedList L1;
	do
	{
		cout<<"\n\n-------Menu options--------"<<endl;
		cout<<"Enter 1 to create circular linked list "<<endl;
		cout<<"Enter 2 to display circular linked list "<<endl;
		cout<<"Enter 3 to add node in the Begining of the circular list"<<endl;
		cout<<"Enter 4 to add node at the End of the circular list"<<endl;
		cout<<"Enter 5 to add node at the specified position in the circular list"<<endl;
		cout<<"Enter 6 to Delete the node from the Begining of the circular list"<<endl;
		cout<<"Enter 7 to Delete the node from the End of the circular list"<<endl;
		cout<<"Enter 8 to Delete the node from the specified position in the circular list"<<endl;
		cout<<"Enter 9 to search the element in the circular linked list "<<endl;
		cout<<"Enter 0 to exit"<<endl;
        cout<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
        cout<<endl;
		switch(choice)
		{
			case '1':
				cout<<"How many nodes you want to create and add in the List: ";
				cin>>n;
				for(int i=1;i<=n;i++)
				{
					L1.create_CircularLinkedList();
				}
				break;
			case '2':
				L1.display_CircularList();
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
                cout<<"Program Terminated"<<endl;
				break;
			default:
				cout<<"Invalid Entry"<<endl;
		}
	}while(choice!='0');
}
