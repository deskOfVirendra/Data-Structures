#include<iostream>
using namespace std;
class node {
	public : 
	int key;
	int data;
	node* next;
	node* prev;

	node() {
		key =0 ;
		data = 0;
		next = NULL;
		prev=NULL;
	}
	node(int keyOfNode,int dataOfNode) {
		key = keyOfNode;
		data = dataOfNode;
		next = NULL;
		prev=NULL;
	}
};

class doublyLinkedList {
public:

	node* head;
	
	doublyLinkedList() {
		head=NULL;

	}

	doublyLinkedList(node* newNode) {
		head=newNode;
	}

	bool nodeExists(int keyOfNode) {
		node* ptr=head;
		while(ptr!=NULL) {
			if(ptr->key == keyOfNode) {
				return true;
			}
			ptr=ptr->next;
		}
		return false;
	}

	void appendNode(int keyOfNode,int dataOfNode){
		if(nodeExists(keyOfNode)) {
			cout<<"Node with key already exists";
		}
		
		node* temp = new node(keyOfNode,dataOfNode);
		
		if(head==NULL) {
			head=temp;
		}
		else {
			node *ptr = head;
			while(ptr->next!=NULL) {
				ptr=ptr->next;
			}
			ptr->next = temp;
			temp->prev = ptr;
    	// cout<<"Node added "<<endl;
		}
		
	}

	void prependNode(int keyOfNode,int dataOfNode) {
		if(nodeExists(keyOfNode)) {
			cout<<"Node with key already exists";
		}
		
		node* temp = new node(keyOfNode,dataOfNode);
		
		if(head==NULL) {
			head=temp;
		}
		else {
			node* ptr=head;
			temp->next=ptr;
			ptr->prev=temp;
			head=temp;
    	// cout<<"Node prepended"<<endl;
		}
	}

	void insertAfter(int targetKey,int keyOfNode,int dataOfNode) {
		if(!nodeExists(targetKey)) {
			cout<<"node with key"<<targetKey<<" does not exists..!";
		}
		if(nodeExists(keyOfNode)) {
			cout<<"Node with key already exists";
		}
		node* temp = new node(keyOfNode,dataOfNode);
		node* current,*nextNode;
		if(head==NULL) {
			head=temp;
		}
		else {
			node* ptr = head;
			while(ptr->next!=NULL){
				if(ptr->key==targetKey) {
					break;
				}
				ptr=ptr->next;
			}
    nextNode = ptr->next; //storing the address of next node of target node....
    ptr->next=temp;
    temp->prev=ptr;
    nextNode->prev=temp;
    temp->next=nextNode;
}


}

void deleteNode(int targetKey) {

	if(!nodeExists(targetKey)) {
		cout<<"node with key"<<targetKey<<" does not exists..!";

	}
	else {

		if(head->key==targetKey) {
			node *ptr = head;
			head = ptr->next;
			delete ptr;
		}
		else {

			node *prevNode,*nextNode;
			node* ptr = head;
			while(ptr!=NULL){
				if(ptr->key==targetKey) break;
				ptr=ptr->next;
			}
			nextNode = ptr->next;
			prevNode = ptr->prev;

			nextNode->prev = prevNode;
			prevNode->next = nextNode;
			delete ptr;

		}
	}

}

void updateNode(int targetKey,int dataOfNode) {
	if(!nodeExists(targetKey)) {
		cout<<"node with key"<<targetKey<<" does not exists..!";
	}
	else {
		node *ptr = head;
		while(ptr!=NULL) {
			if(ptr->key == targetKey) {
				ptr->data = dataOfNode;
				cout<<"updated"<<endl;
			}
			ptr=ptr->next;
		}
	}
} 

void printList() {
	node* ptr=head;
	while(ptr!=NULL) {
		cout<<endl<<"Key : "<<ptr->key<<" value:"<<ptr->data;
		ptr=ptr->next;
	}
}

void reversePrintList() {
	node* ptr = head;
	while(ptr->next!=NULL) {
		ptr=ptr->next;
	}

	while(ptr!=NULL) {
		cout<<endl<<"KEy : "<<ptr->key<<" value:"<<ptr->data;
		ptr=ptr->prev;
	}
}


};
int main() {
	doublyLinkedList dl;
	dl.appendNode(1,2);
	dl.appendNode(2,3);
	dl.appendNode(3,4);
	dl.appendNode(4,5);
	dl.printList();
// cout<<"\nreverse Printing of doublyLinkedList";
// dl.reversePrintList();
// dl.prependNode(5,6);
// dl.printList();
// dl.prependNode(7,8);
// cout<<endl<<"--------------------------";
// dl.insertAfter(2,8,9);
	// dl.insertAfter(8,0,1);
// dl.printList();
	cout<<endl<<"--------------------------";
// dl.deleteNode(1);
// dl.updateNode(1,0);
	dl.printList();

	return 0;

}