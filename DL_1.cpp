#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *nxt,*prev; //two pointers pointing to the next and previous node
	Node() //default class constructor
	{
		nxt=NULL; //making both the pointers initially null
		prev=NULL;
	}
};

class DLinkedL//our double limked list class
{
	public:
	Node *head=NULL; //location of first node
	Node *last;//location of last node
	
	void insert(int a)
	{
		Node *temp=new Node;
		temp->data=a;
		if(head==NULL)//insert function
		{
			head=temp;
			temp->prev=NULL;
		}
		else
		{
			last->nxt=temp;
			temp->prev=last;
		}
		last=temp;
		temp->nxt=NULL;
	}
				
	void Display()
	{
		Node *current=head;
		while(current!=NULL)
		{
			cout<<current->data<<"->";
			current=current->nxt;
		}
		cout<<"NULL";
		cout<<"\nin reverse order:";
		current=last;
		while(current!=NULL)
		{
       cout <<current->data<< "->";
       // Move backwards 
       current= current->prev;
     }
     cout <<"NULL"<<endl; 
	}
	//insertAT
	void insertAt(int pos,int value)
	{
		Node *temp=new Node;// dynamically creating the memory for new node
		temp->data=value;//storing value in the new node
		if(pos >1)//if position is not at the first position
		{
			int i=1; //control variable
			Node *current=head;
			while(i<pos-1)//loop acessing each element
			{
				current=current->nxt;//acessing the next element
				if(current==NULL)
				{
					cout<<"\nThat many elements are not present in the linked list\n";
					break;
				}
				i++;//increamenting i
				
			}
			if(current!=NULL)
			{
				temp->nxt=current->nxt;//storing the adress of (pos+1)th element in the new node
				temp->prev=current; //previous of new node is the n-1th snode
				current->nxt->prev=temp;//previous of nth node of old linked list is the newly added node 
				current->nxt=temp;//storing the address of new node in (pos-1)th position
				if(temp->nxt==NULL)
				{
					last=temp;//if it is added at the last
				}
			}
		}
		
		else //if the new node is added in the first position
		{
			temp->nxt=head; //address of first assin to pointer of new first
			temp->prev=NULL;//assinging null to the prev of first location
			head->prev=temp; // previous of the first node is the newly added node
			head=temp; //modifing head head
		}
	}
	void Delete() //deleting the last elemnt
	{
		last->prev->nxt=NULL;
		Node *temp=last->prev;
		delete last;
		last=temp;
	}
	void DeleteAt(int pos)//delete At
	{
		if(pos==1) //if the first node is deleted
		{
			Node *temp=head; //new variable temp for deleting the first location
			head=head->nxt; //assinging the new head
			temp->nxt->prev=NULL; //making the prev of 2nd null
			delete temp;
		}
		else
		{
			Node *current,*temp; //new variable for traversing
			int i=1;// i used to get to the posth element
			current=head;
			while(i<pos-1) //loop to rach the pos-1 th element
			{
				current=current->nxt;// modifing current
				i++;
			}
			current->nxt=current->nxt->nxt;// modfing nxt of teh n-1 th elemnt
			current->nxt->prev=current;// pointing the prev of n+1 th element to n-1 th element 
		}
	}
int countItems()
	{
		int i=0;
		Node*current=head;
		while(current!=NULL)
		{
			current=current->nxt;
			i++;
		}
		return i;
}
};


int main()
{
	DLinkedL A;
	A.insert(56);
	A.insert(78);
	A.insert(23);
	A.insert(34);
	A.insert(89);
	A.Delete();
	A.insertAt(3,7);
	A.Display();
	A.DeleteAt(3);
	A.Display();
	cout<<A.countItems();
	return 0;
}
