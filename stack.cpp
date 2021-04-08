#include<iostream>
using namespace std;
#define max 20
class stack {
public:
	int arr[max];
	int top;

	stack() {
		arr[max] = {0};
		top=-1;
	}

	int push(int value) {
      if(isFull()) {
      	cout<<"Stack Overflow"<<endl;
        return 0;
      }
      arr[++top] = value;
      return top;
	}

	bool isFull() {
		return (top==max-1);
	}

	int pop() {
		if(isEmpty()){
		 cout<<"stack Underflow"<<endl;
		return 0;
	}
		return arr[top--];
	}

	bool isEmpty() {
		return (top<0);
	}

	void displayArr() {
		for(int i=0;i<max;i++) {
			cout<<endl<<arr[i];
		}
	}

	int size() {
		return isEmpty() ? 0 : (top+1);
	}
};
int main() {
	stack st;
	// st.push(1);
	// st.push(2);
	// st.push(3);
	// st.push(4);
	// st.push(5);
	// st.push(6);
	// st.push(1);
	// st.push(2);
	// st.push(3);
	// st.push(4);
	// st.push(5);
	// st.push(6);
	// st.push(1);
	// st.push(2);
	// st.push(3);
	// st.push(4);
	// st.push(5);
	// st.push(6);
	// st.push(1);
	// st.push(2);
	// cout<<st.size();
	// cout<<st.pop();
	// cout<<st.pop();
 //    cout<<st.pop();
	// cout<<st.pop();
	// cout<<st.pop();
	// cout<<st.pop();
	// cout<<st.pop();

	// cout<<st.pop();
	// cout<<st.pop();
	// cout<<st.pop();
	// cout<<st.pop();
	// cout<<st.pop();
	// cout<<st.pop();

	// cout<<st.pop();
	// cout<<st.pop();
	// cout<<st.pop();
	// cout<<st.pop();

	// cout<<st.pop();
	// cout<<st.pop();
	// cout<<st.pop();
	// st.pop();
	// cout<<st.size();
 //    // st.displayArr();


	return 0;
}