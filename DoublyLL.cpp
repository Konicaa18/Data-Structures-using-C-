#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		
		node(){
			next=0;
			prev=0;
		}
		node(int val,node* ptr=0,node* ptr1=0){
			next=ptr1;
			prev=ptr;
			data=val;
		}
		friend class DLL;
};
class DLL{
	node* header;
	node* trailer;
	public:
		DLL(){
			header=new node();
			trailer=new node();
			header->next=trailer;
			trailer->prev=header;
		}
		bool isempty(){
			return(header->next==trailer);
		}
		void add(node* v,int el){
			node* temp;
			temp=new node(el);
			temp->next=v;
			temp->prev=v->prev;
			v->prev->next=temp;
			v->prev=temp;
		}
		void addToFront(int el){
			add(header->next,el);
		}
		void addToBack(int el){
			add(trailer,el);
		}
		int search(int el){
			node* temp=header->next;
			while(temp!=trailer){
				if (temp->data==el)
					return 1;
				temp=temp->next;
			}
			return 0;
		}
		int front(){
			return header->next->data;
		}
		int back(){
			return trailer->prev->data;
		}
		
		void print(){
			if (isempty())
				cout<<"Empty Linked List";
			else{
			node* temp=header->next;
			while(temp!=trailer){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		}
};
int main(){
	DLL l;
	cout << "menu: " << endl;
	cout << "1. add to head\n";
	cout << "2. add to back\n";
	cout << "3. search an element\n";
	cout << "4. front element\n";
	cout << "5. end element\n";
	cout << "6. display all the elements\n";
	cout << "7. exit\n";

	bool flag = true;
	
	while(flag){
		cout << "\nMake choice: ";
	    int ch;
	    cin >> ch;
	    
	  switch(ch){
	  	case 1: cout << "Enter the element to add: ";
	  	        int el;
	  	        cin >> el;
	  	        l.addToFront(el);
	  	        break;
	  	
		case 2: cout << "Enter the element to add: ";
	  	        int el1;
	  	        cin >> el1;
				l.addToBack(el1);
	  	        break;
		
		case 3: cout << "Enter the element to search: ";
	  	        int el2;
	  	        cin >> el2;
	  	        if (l.isempty())
	  	        	cout << "List is empty\n";			
	  	        else
	  	        	if (l.search(el2))
	  	        		cout<<"found";
	  	        	else
	  	        		cout<<"not found";
	  	        break; 
				  
		case 4: if (l.isempty())
					cout << "List is empty\n";
	  	        else
	  	        	cout << l.front() << endl;
	  	        break;
				 
		case 5: if (l.isempty())
					cout << "List is empty\n";
	  	        else
	  	        	cout << l.back() << endl;
	  	        break;
				  
		case 6: l.print();
				break;
				
		case 7: flag = false;
		         break;
				 
		default: cout << "Invalid choice";
		         break;	  	
	  }
	}
	return 0;
}
