#include<iostream>
using namespace std;

class node{
	int data;
	node* next;
	public:
	node(int data,node* ptr=NULL){
		this->data=data;
		next=ptr;
	}
	friend class SLL;
};
class SLL{
	node* head;
	public:
	SLL(){
		head=0;
	}
	bool isempty(){
		return (head==0);
	}
	void addToHead(int el){
		node* temp=head;
		head=new node(el);
		head->next=temp;
	}
	void print(){
		if (isempty()){
			cout<<"Empty"<<endl;
		}
		else{
			node* ptr=head;
			while(ptr!=NULL){
				cout<<ptr->data<<" -> ";
				ptr=ptr->next;
			}
			cout<<"NULL";
		}
	}
	void removeFromBeginning(){
		if (isempty()){
			cout<<"Empty"<<endl;
		}
		else{
			node* temp=head->next;
			delete head;
			head=temp;
		}
	}
	void searching(int el){
		node* ptr=head;
		while(ptr!=0){
			if(ptr->data==el){
				cout<<"Found";
				return;
			}
			ptr=ptr->next;
		}
		cout<<"Not Found";
	}
	void insertAfter(int val,int el){
		node* ptr=new node(val);
		node* temp=head;
		while(temp!=0){
			if (temp->data==el){
				ptr->next=temp->next;
				temp->next=ptr;
				return;
			}
			temp=temp->next;
		}
		cout<<"Value successfully inserted"<<endl;
	}
	void deleteFromEnd(){
		node* temp=head;
		node* ptr;
		cout<<"sdf";
		while(temp->next->next!=0){
			temp=temp->next;
		}
		cout<<"fag";
		delete temp->next;
		temp->next=0;
		cout<<"deleted";
	}
	void deleteFromBeginning(){
		node* ptr=head;
		head=head->next;
		delete ptr;
	}
	
	
	
	void palindrome(){
		void pushStack(int val){
			arr[++tos]=val;
		}
		int popStack(){
			return (arr[tos--]);
		}
		node* ptr=head;
		int count=0;
		while (ptr!=0){
			count++;
			ptr=ptr->next;
		}
		int arr=new int[count];
		
		if (head){
			if (head->next==0){
				cout<<"Single Element Linked List";
				return;
			}
			else{
				int flag=0;
			 	node* temp=head;
				while (temp!=0){
					pushStack(temp->data);
					temp=temp->next;
				}
				node* temp2=head;
				while (temp!=0){
					if (temp->data==popStack()){
						flag=1;
					}
					temp=temp->next;
				}
				if (flag==1){
					cout<<"palindrome";
				}
				else{
					cout<<"not a palindrome";
				}	
			}
		}
	}	
};
int main(){
	SLL s;
	cout<<"1.Add to Head"<<endl;
	cout<<"2.Display"<<endl;
	cout<<"3.Remove From Beginning"<<endl;
	cout<<"4.Searching for an Element"<<endl;
	cout<<"5.Inserting an Element after a Particular Value"<<endl;
	cout<<"6.Delete from end"<<endl;
	cout<<"7.Delete from Beginning"<<endl;
	cout<<"8.End"<<endl;
	cout<<"9.palindrome"<<endl;
	char ans='y';
	while (ans){
	
	cout<<"\nEnter your choice : ";
	int choice;
	cin>>choice;
	switch (choice){
		case 1: int val;
				cout<<"Enter value to be inserted at Head : ";
				cin>>val;
				s.addToHead(val);
				break;
		case 2: s.print();
				break;
		case 3:	s.removeFromBeginning();
				break;
		case 4:	int v;
				cout<<"Enter value to be searched : ";
				cin>>v;
				s.searching(v);
				break;
		case 5: int value;
				cout<<"Enter value to be inserted : ";
				cin>>value;
				int element;
				cout<<"Enter the element after which the value is to be inserted : ";
				cin>>element;
				s.insertAfter(value,element);
				break;
		case 6: s.deleteFromEnd();
				break;
		case 7: s.deleteFromBeginning();
				break;
		case 8: exit(100);
				break;
		case 9: palindrome();
		default: cout<<"May be the entered choice is wrong.";
		}
	}
}
