#include <iostream>
using namespace std;

class queuefunctions
{
	private:
	int *queue;
	int n;
	int front;
    	int rear;

	public:
	queuefunctions(int *a, int size)
	{
		queue = a;
		n = size;
        	front = rear = -1;
	}
	bool isfull()
	{
		if(rear==n-1)
		{
			cout<<"Queue is full"<<endl;
			return true;
		}
		cout<<"Queue is not full"<<endl;
		return false;
	}
	bool isempty()
	{
		if(front==-1 || front>rear)
		{
			cout<<"Queue is empty"<<endl;
			return true;
		}
		cout<<"Queue is not empty"<<endl;
		return false;
	}
	void enqueue(int val)
	{
		if(isfull())
		{
			cout<<"Queue Overflow"<<endl;
		}
		else
		{
			cout<<"Element Inserted"<<endl;
            		if (front == -1)
            		{
                		front = 0;
            		}
			rear++;
			queue[rear]=val;
		}	
	}
	void dequeue()
	{
		if(isempty())
		{
			cout<<"Queue Underflow"<<endl;
			front = rear = -1;

		}
		else
		{
			cout<<"The element deleted is "<<queue[front]<<endl;
			front++;
		}
	}
	void display()
	{
		if(isempty())
		{
			front = rear = -1;
        	}
        	else
        	{
			cout<<"Queue elements are : ";
			for(int i=front; i<=rear;i++)
			{
				cout<<queue[i]<<" ";
			}
			cout<<endl;
		}
	}
};

int main()
{
	cout<<"Enter the size of the queue : ";
	int size;
	cin>> size;
	int val;
	int queue[size];
	queuefunctions ob(queue, size);
	char choice;
	do
	{
		cout<<""<<endl;
		cout<<"Enter 1 to Insert element in queue"<<endl;
		cout<<"Enter 2 to Delete element from queue"<<endl;
		cout<<"Enter 3 to Display elements of the queue"<<endl;
		cout<<"Enter 4 to check if the queue is full"<<endl;
		cout<<"Enter 5 to check if the queue is empty"<<endl;
		cout<<"Enter 0 to exit"<<endl;
		cout<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case '1':
			{
				cout<<"Enter value to be inserted : ";
				cin>>val;
				ob.enqueue(val);
				break;
			}
			case '2':
			{
				ob.dequeue();
				break;
			}
			case '3':
			{
				ob.display();
				break;
			}
			case '4':
			{
				ob.isfull();
				break;
			}
			case '5':
			{
				ob.isempty();
				break;
			}
			case '0':
			{
				cout<<"Program exited"<<endl;
				break;
			}
			default:
			{
				cout<<"Invalid Choice"<<endl;
				break;
			}
		}
	}while(choice!='0');
	return 0;
} 
