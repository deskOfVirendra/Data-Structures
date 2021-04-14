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

class linkedList {
public:

	node* head;

	linkedList() {
		head = NULL;
	}

	linkedList(node* newNode ) {
		head = newNode;
	}

	node* createNode(int keyOfNode,int dataOfNode) {
		node* temp = new node(keyOfNode,dataOfNode);
		return temp;
	}

	bool nodeExists(int keyOfNode) {
		node* ptr = head;
		while(ptr!=NULL) {
			if(ptr->key==keyOfNode)
				return true;
			ptr = ptr->next;
		}
		return false;
	}

	void appendNode(int keyOfNode,int dataOfNode) {
		node* temp = new node(keyOfNode,dataOfNode);

		if(nodeExists(keyOfNode)){ 

			cout<<"Element with given key : "<<keyOfNode<<" already exists";
			return;
		}

		if(head==NULL)
		{
			head=temp;
			cout<<"node added ...!"<<endl;

		}
		else 
		{
			node *ptr = head;
			while(ptr->next!=NULL) {
				ptr = ptr->next;
			}
			ptr->next = temp;
			cout<<"node added ...!"<<endl;
		}

	}

	void displayAllNodes() {
		node* ptr=head;

		while(ptr != NULL) {
			cout<<endl<<"key :"<<ptr->key<<" data: "<<ptr->data;
			ptr=ptr->next;
		}

	}


	void prependNode(int keyOfNode,int dataOfNode) {

        node* temp = new node(keyOfNode,dataOfNode);

		if(nodeExists(keyOfNode)){ 

			cout<<"Element with given key : "<<keyOfNode<<" already exists";
			return;
		}

		if(head==NULL)
		{
			head=temp;
			cout<<"node added ...!"<<endl;

		}
		else 
		{
			// node *ptr = head;
		    temp->next = head;
		    head=temp;
		 }

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
       while(ptr!=NULL) {
       	if(ptr->key==targetKey) {
       		target = ptr;
       		nextOne = ptr->next;
       	}
       	ptr=ptr->next;
       }
       
       target->next = temp;
       temp->next = nextOne;
 
	}

	void deleteNode(int targetKey) {
     // target key is the key of node to be deleted..!
      node* temp,*previous;
      node *ptr = head;
      while(ptr!=NULL) {
      	if(ptr->key==targetKey) {
            break;
      	}
      	previous=ptr;
        ptr=ptr->next;
      }
      temp = ptr->next;
      delete ptr;
      previous->next=temp;
 
	}

	void updateNode(int keyOfNode,int dataOfNode) {
		//keyOfNode is the targetKey of Node and dataOfNode is the new Key
		node* ptr = head;
		while(ptr!=NULL) {
			if(ptr->key==keyOfNode) {
				ptr->data = dataOfNode;
				cout<<"updated..!"<<endl;
				
			}
			ptr=ptr->next;
		}
	}
	
};
int main() {
	linkedList list;
	list.appendNode(1,2);
	list.appendNode(2,3);
	list.appendNode(3,4);
   // list.addNode(4,5);
	list.displayAllNodes();
	// cout<<"after prepending"<<endl;
	// list.prependNode(4,5);
	// cout<<"Inserting after ..!"<<endl;
	// list.insertAfterNode(2,5,6);
	// cout<<"deleting node"<<endl;
	// list.deleteNode(2);
	list.updateNode(2,5);
	list.displayAllNodes();
	return 0;
}