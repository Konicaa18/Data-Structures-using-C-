#include<iostream>
using namespace std;


class queue{
public:
	int front;
	int rear;
	int n;
	int size;
	int *arr;

	public:

	queue(int cap){
		front=-1;
	 	rear=-1;
		size=0;
		n=cap;
	 	arr=new int[cap];
	}

	void enqueue(int x){
		if((rear+1)%n == front){              //full condition
            cout<<"overflow"<<endl;
			return;
		}
    	if(front== -1){
        	front++;
    	}
    	rear = (rear+1)%n;           //
		arr[rear] = x;
		size++;
	}
	void dequeue(){
		if(isempty()){
			cout<<"underflow"<<endl;
			return ;
		}
		if(rear==front){
            rear=front= -1;
			}
		else{
		    front = (front+1)%n;
		    cout<<"dequed"<<endl;
			}
		size--;
	}
	int frontEl(){
		if(isempty()){
                cout<<"stack is empty"<<endl;
				return -1;
			}
		return arr[front];
	}
	int sizex(){
		return size;
	}
	int isempty(){
		return (size==0);
	}
};

int main(){
	int k;
	cout<<"please enter the size of array :";
	cin>>k;
	
	queue obj(k);
	int x=12;;
	while(x!=0){
		cout<<" 1.Enqueue :"<<endl;
		cout<<" 2.dequeue :"<<endl;
		cout<<" 3.size :"<<endl;
		cout<<" 4.isempty :"<<endl;
		cout<<" 5.front element "<<endl;
		cout<<" 6.details "<<endl;
		cout<<" 0.exit"<<endl;

		int n ;
		cout<<"Enter a choice"<<endl;
		cin>>n;
		
	switch(n){
		case 1:cout<<"enter the element to enqueued : ";
				int p;
				cin>>p;
				obj.enqueue(p);
				break;
		case 2:

			obj.dequeue();

			break;

		case 3:
		     cout<< "size is "<< obj.sizex()<<endl;
			 break;

		case 4:cout<<"RESULT : ";
		 	  cout<<obj.isempty()<<endl;
			   break;
		case 5:
		      cout<<"front element is "<<obj.frontEl();
		      cout<<endl;
		      break;
		case 6 :
              cout<<"front : "<<obj.front<<endl;
              cout<<"rear : "<<obj.rear<<endl;
              cout<<"size : "<<obj.size<<endl;
        case 0:cout<<"ending"<<endl;
              n=0;

		default:
		  	cout<<"wrong input"<<endl;
		  	break;
		}
	}
	return 0;
}
