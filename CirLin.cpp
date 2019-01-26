#include<iostream>
using namespace std;
class Node // each circles
{
	public:
	//data
	int data;
	//pointer to point ot next element
	Node *nxt;
	Node()
	{
		nxt=NULL;
	}
};

class LinkedList
{
	public:
	//head
	Node *head;
	Node *last;
	LinkedList()
	{
		head=NULL;
		last=NULL;
	}
	//insert
	void insert(int value)
	{
		//creating the new object
		Node *temp=new Node;
		//assinging the value to the new memory location
		temp->data=value;  
		//we need to assingn the pointing variable of last to the new object created
		//if it is the first element 
		if(head==NULL)
		{
			head=temp; //modifing head
			temp->nxt=temp;//modifing the pointer of temp
		}
		else
		{
			last->nxt=temp;
			temp->nxt=head;
		}
		last=temp;
	}
	//display
	void display()
	{
		Node *current;//current stores the address of the current node
		if(head!=NULL) //condition to check whether the Circular linked list is empty or not
		{
			current = head->nxt;      //initializing current
			cout<<endl<<head->data<<"->";//printing the first element

			while(current->data!=head->data)// loop to swipe throughj the link list 
			{
				cout<<current->data<<"-> ";//printing the data in each
				current=current->nxt;//modifing the current node
			}
		cout<<"then the last element again points to the first"<<endl;
		}
		else
		cout<<"NULL";
	}
	//insertAT
	void insertAt(int pos,int value)
	{
		Node *temp=new Node;// dynamically creating the memory for new node
		temp->data=value;//storing value in the new node
		if(pos >1)//if insertion is not at the first position
		{
			int i=1; //control variable
			Node *current=head;
			while(i<pos-1)//loop acessing each element
			{
				current=current->nxt;//acessing the next element
				
				if(current->data==head->data)// condition to remind the user that the given position will again go to the beging of the circular linked list
				{
					cout<<"\nThat many elements are not present in the circular linked list. the given number will again go to the beging of the circular linked list"<<endl;
				}
				i++;//increamenting i
						
			}
			if(current->data!=head->data)
			{
				temp->nxt=current->nxt;//storing the adress of (pos+1)th element in the new node
				current->nxt=temp;//storing the address of new node in (pos-1)th position
		
				if(temp->nxt==head)
				{
					last=temp;
				}
			}
		}
		
		else
		{
			temp->nxt=head;
			head=temp;
		}
	}
	//delete
	void Delete()
	{
		Node *current=head; //curent acceces each node
		while(current->nxt->nxt!=head)//loop to search for end of circularlinklist
		{
			current=current->nxt;//going to the next element
		}	
		current->nxt=head;//making the current element point to the first 
		delete last;//delete last element
		last=current;// modifing last to the now location
	}
	void DeleteAt(int pos)
	{
		if(pos==1)
		{
			Node *D=head;
			head=head->nxt;
			delete D;
		}
		else
		{
			Node *current,*temp;
			int i=1;
			current=head;
			while(i<pos-1)
			{
				if(current==head)
				{
					cout<<"That many elements are not present in the circular linkd list";
					break;
				}
				current=current->nxt;
				i++;
			}
			temp=current;
			delete current->nxt;
			current->nxt=temp->nxt->nxt;
		}
	}
	int countItems()
	{
		int i=0;
		Node*current=head;
		if(head==NULL)
			return 0;
		else
		{
			current=current->nxt;
			i++;
			while(current!=head)
			{
				current=current->nxt;
				i++;
			}
			return i;
		}
	}
	void displayrevM()//primary function because we need the value of head 
	{
		displayrev(head);//calling the reversing fuction with the value of head
	}
	void displayrev(Node* start) //recursieve function starting from head
	{
		if(start->nxt==head) //condition checking (is the current is null) and thereby acess the last node
		{
			cout<<"<-"<<start->data;//once last element is reached print the data
			return ;//going back to the previous function
		}
		else
		displayrev(start->nxt);//if the current node is nit the last one calling the fucntion again to acess the next node
		
		cout<<"<-"<<start->data;//once the above conditons are checked starts printing the data part of each node
	}
	void revLLM()//main function
	{
		Node*temp=head;//creating a node pointer to point to the head
		last=temp;										
		temp->nxt=revLL(head);//calling the function which reverses the string//once the string is reversed the position pointed by temp becomes the last position
	}
	Node* revLL(Node *current)
	{
		//we need to go through each node
		if(current==NULL) return NULL;//control condition
		else if(current->nxt==head)  //to check whether current have reached again to the head
		{
			head=current;//current will be the last element in the list pointinghead to this position
			return	current;//returning the value of last position
		}
		else
		{
			Node *x=revLL(current->nxt);//if it at any position before the last position then calling the function again 
			current->nxt->nxt=current;//revesing the pointing
			return x;//returning the value of the last position
		}
	}	
};
int main()
{
	LinkedList A;
	A.insert(4);
	
	A.insert(45);
	A.insert(89);
	A.insert(67);
	A.insert(78);
	A.insertAt(8,11);
	A.display();
	A.insert(23);
	A.display();
	A.Delete();
	A.display();
	cout<<endl;
	cout<<A.countItems();
	cout<<endl;
	A.insertAt(5,55);
	A.insert(6);
	A.display();
	cout<<endl;
	cout<<A.countItems();
	cout<<endl;
	A. displayrevM();
	A.insert(73);
	A.insert(109);
	A.display();
	A.revLLM();
	A.display();
	A.insert(67);
	A.display();
	A.insertAt(4,1045);
	A.display();
	return 0;
}
