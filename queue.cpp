#include<iostream>
using namespace std;
#define MAX 5
class queue {
	int arr[MAX];
	int front;
	int rear;

public :
 queue() {
 	front = rear = -1;
 	for(int i=0;i<MAX;i++) 
 		  arr[i]=0;
 }

bool isFull() {
	if(rear==MAX-1) {
		return true;
	}
	return false;
}

bool isEmpty() {
	if(front==-1 && rear==-1) {
		return true;
	}

   return false;
}

void enqueue(int x) {
	if(isFull()) return;
     

     if(isEmpty()) {
     	front=rear=0;
     } 
     else {
     	rear++;
     }

    arr[rear] = x;

}

int dequeue() {
	int x = 0;
	if(isEmpty()) return 0;

	if(front==rear) {
        x = arr[front];
        arr[front]=0;
        front=rear=-1;
        
	}else {
		x = arr[front];
       arr[front]=0;
       front++;
	}

	return x;
}

void display() {
	for(int i=0;i<MAX;i++) {
		cout<<"  "<<arr[i];
	}
	cout<<endl;
}

int frontValue() {
	return front;
}

};

int main() {
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

	q.display();
q.dequeue();
q.dequeue();
q.dequeue();
// cout<<endl<<q.frontValue();
// q.dequeue();
	q.display();

	return 0;
}