#include<iostream>
using namespace std;
class node {
	public : 
	int key;
	int data;
	node* next;

	node() {
		key =0 ;
		data = 0;
		next = NULL;
	}
	node(int keyOfNode,int dataOfNode) {
		key = keyOfNode;
		data = dataOfNode;
		next = NULL;
	}
};

class circularLinkedList {
public:

	node* head;

	circularLinkedList() {
		head = NULL;
	}

	circularLinkedList(node* newNode ) {
		head = newNode;
	}

	node* createNode(int keyOfNode,int dataOfNode) {
		node* temp = new node(keyOfNode,dataOfNode);
		return temp;
	}

	bool nodeExists(int keyOfNode) {
		node* ptr = head;

		if(head==NULL) return false;
		
		do {
			if(ptr->key==keyOfNode) return true;
			ptr=ptr->next;

		}while(ptr!=head);

		return false;
	}

	void appendNode(int keyOfNode,int dataOfNode) {
		node* temp = new node(keyOfNode,dataOfNode);

		if(nodeExists(keyOfNode)){ 

			cout<<"Element with given key : "<<keyOfNode<<" already exists";
			return;
		}
		cout<<"new node created"<<endl;

		if(head==NULL)
		{
			head=temp;
			temp->next=head;
			cout<<"node added ...!"<<endl;

		}
		else 
		{
			node *ptr = head;
			while(ptr->next!=head) {
				ptr = ptr->next;
			}
			ptr->next = temp;
			temp->next = head;
			cout<<"node added ...!"<<endl;
		}

	}

	node* getLastNode() {

		node* ptr = head;

		if(head==NULL) return NULL;
		
		while(ptr->next!=head) {
			ptr=ptr->next;
		}
		
		return ptr;
	}
	void displayAllNodes() {
		node* ptr=head;
		do {
			cout<<endl<<"key :"<<ptr->key<<" data: "<<ptr->data;
			ptr=ptr->next;

		}while(ptr!=head);
		

	}


	void prependNode(int keyOfNode,int dataOfNode) {

		node* temp = new node(keyOfNode,dataOfNode);
		node* lastNode=getLastNode();
		if(nodeExists(keyOfNode)){ 

			cout<<"Element with given key : "<<keyOfNode<<" already exists";
			return;
		}

		if(head==NULL)
		{
			head=temp;
			temp->next=head;
			cout<<"node added ...!"<<endl;

		}
		else 
		{
			// node *ptr = head;
			temp->next = head;
			head=temp;
			lastNode->next=head;
		}

		 // cout<<"---"<<lastNode->key<<endl;
		 // cout<<"---"<<lastNode->next->key<<endl;
		 // cout<<"---"<<head->key<<endl;

	}

	void insertAfterNode(int targetKey,int keyOfNode,int dataOfNode) {
        //target key is the key of node after which we are inserting the node
		node* temp = new node(keyOfNode,dataOfNode);
		if(!nodeExists(targetKey)) {
			cout<<"Node with key "<<targetKey<<" does not exists..!So we cant insert after it"<<endl;
			return;
		}

		if(nodeExists(keyOfNode)) {
			cout<<"Node with key "<<keyOfNode<<" already exists..!"<<endl;
			return;
		}

		node* target,*ptr,*nextOne;

		ptr=head;
		do {
			if(ptr->key==targetKey) {
				target = ptr;
				nextOne = ptr->next;
			}
			ptr=ptr->next;
		}while(ptr!=head);

		target->next = temp;
		temp->next = nextOne;

	}

	void deleteNode(int targetKey) {
     // target key is the key of node to be deleted..!
		node* temp,*previous;
		node *ptr;

		if(!nodeExists(targetKey)) {
			cout<<"Node with key "<<targetKey<<" does not exists..!So we cant insert after it"<<endl;
			return;
		}

		if(head->key==targetKey && head->next !=head) {
			node *ptr = head;
			node *nextNode = ptr->next;
			node *lastNode = getLastNode();
			lastNode->next = nextNode;
			head=nextNode;

			delete ptr;

		} else if(head->key==targetKey && head->next==head && head==getLastNode()) { 

			head=NULL;
			cout<<"Only head exists in circularLinkedList so we deleted it now it is empty"<<endl;

		}else{

			do
			{
				if(ptr->key==targetKey) 
				{
					break;
				}
				previous=ptr;
				ptr=ptr->next;  
			}while(ptr!=head);


			if(ptr->next==head) {
				previous->next=head;
				delete ptr;
			}
			else {
				previous->next=ptr->next;
				delete ptr;

			}
		}

// cout<<"Head is"<<head->key<<head->data<<endl;
	}

	void updateNode(int keyOfNode,int dataOfNode) {
		//keyOfNode is the targetKey of Node and dataOfNode is the new Key
		node* ptr = head;
		do{
			if(ptr->key==keyOfNode) {
				ptr->data = dataOfNode;
				cout<<"updated..!"<<endl;
				
			}
			ptr=ptr->next;
		}while(ptr!=head);
	}


	
};
int main() {
	circularLinkedList list;
	list.appendNode(1,2);
	list.appendNode(2,3);
	list.appendNode(3,4);
	list.appendNode(4,5);
	list.displayAllNodes();
	// cout<<"after prepending"<<endl;
	 // list.prependNode(4,5);
	// cout<<"Inserting after ..!"<<endl;
	// list.insertAfterNode(2,5,6);
	// cout<<"deleting node"<<endl;
	// list.deleteNode(1);
	list.updateNode(2,5);
	list.displayAllNodes();
	return 0;
}