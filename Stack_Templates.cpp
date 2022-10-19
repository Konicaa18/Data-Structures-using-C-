/*
Display a simple stack with using templets just using an array.
*/

#include<iostream>
using namespace std;

class Stack{
	private:
		int cp; //cp == current position
		int tos;
		int* arr;
	public:
		Stack(int n){
			tos = -1;
			cp = n;
			arr = new int[n];
		}		
		void push(int item){
			if(tos >= cp -1){
				cout<<"Overflow" << endl;
				return;
			}else{
				arr[++tos] = item;
			}
		}
		void pop(){
			if( isEmpty()){
				cout << "Underflow stack";
				return;
				
			}else{
				--tos;
			}
		}
		bool isEmpty(){
			return((bool)(tos == -1));
		}
		
		int size(){
//			cout << "current size is " << (tos++);
			return tos+1;
		}
		
		int top(){
			if(isEmpty()){
			return -1;	
			}else{
				return arr[tos];
			}
			
		}
		
};
	
	int main(){
	cout<<"Enter the size of array: ";
	int n;
	cin >> n;
	Stack s1(n);
	cout<<"Slect:\n";
	cout<<"1. to push\n";
	cout<<"2. to pop\n";
	cout<<"3. to isEmpty\n";
	cout<<"4. to Top\n";
	cout<<"5. to Exit\n";
	bool flag = false;
	while(!flag){
		int select;
		cout<<"Make choice: " << endl;
	cin >> select;
	switch(select){
		case 1:
			cout << "Enter item to push: ";
			int value;
			cin >> value;
			s1.push(value);
			break;
		case 2:
			s1.pop();
			break;
		case 3:
			//cout << "Stack is empty: "<< (bool)s1.isEmpty() << endl;
			
			if (s1.isEmpty())
			cout << "Stack is empty" << endl;
			else
			cout << "Stack is not empty" << endl;
			break;
		case 4:
			cout << "Top is "<<s1.top() << endl;
			break;
		case 5:
			flag = true;
			break;
		default:
				cout << "Invalid Value" <<endl;
							
	}
	
	}

}
