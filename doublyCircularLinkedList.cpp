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

class doublyCircularLinkedList{
	public :
	node* head;
	doublyCircularLinkedList() {
		head=NULL;
	}

	doublyCircularLinkedList(int keyOfNode,int dataOfNode) {
		head = new node(keyOfNode,dataOfNode);
	}

	bool nodeExists(int keyOfNode) {
		node *ptr=head;
		if(ptr==NULL) return false;

		do { 
			if(ptr->key==keyOfNode)
				return true;
			ptr=ptr->next;

		}while(ptr!=head);
		return false;
	}

	node* getLastNode() {
		node *ptr = head;

		if(ptr==NULL) return NULL;

		while(ptr->next!=head) {
			ptr=ptr->next;
		}

		return ptr;
	}

	node* getRequiredNode(int targetKey) {
        node *ptr = head;

          do {
             if(ptr->key==targetKey) break;
             ptr=ptr->next;
          }while(ptr!=head);

		return ptr;
	}

	void addNode(int keyOfNode,int dataOfNode) {
		if(nodeExists(keyOfNode))
		{
			 cout<<"Node with key exists..!"<<endl;
			 return;
		}


	node *temp = new node(keyOfNode,dataOfNode);
	if(head==NULL) {
		head = temp;
		head->next=temp;
		head->prev=temp;
		cout<<"head added"<<endl;
	}else {
		node *lastNode = getLastNode();
		lastNode->next = temp;
		temp->prev = lastNode;
		temp->next = head;
		head->prev = temp;
    // cout<<"Node added";
	}

}

void prependNode(int keyOfNode,int dataOfNode) {
	if(nodeExists(keyOfNode))
		{
			 cout<<"Node with key exists..!"<<endl;
			 return;
		}

	node *temp = new node(keyOfNode,dataOfNode);
	
	if(head==NULL) {
		head = temp;
		head->next=temp;
		head->prev=temp;
		cout<<"head added"<<endl;
	}else {
		node *lastNode = getLastNode();
		lastNode->next = temp;
		temp->prev = lastNode;
		temp->next= head;
		head->prev=temp;
		head=temp;
    cout<<"Node added";
	}
}

void insertAfter(int targetKey,int keyOfNode,int dataOfNode) {
	if(!nodeExists(targetKey)) {
		cout<<"Node with key"<<targetKey<<" not exists..!"<<endl;
		return;
	}

	if(nodeExists(keyOfNode)) {
		cout<<"Node with key already exists"<<endl;
		return;
	}
    else {
          node *targetNode = getRequiredNode(targetKey);
         node *nextNode = targetNode->next;
         node *temp = new node(keyOfNode,dataOfNode);
         targetNode->next = temp;
         temp->prev = targetNode;

         temp->next=nextNode;
         nextNode->prev=temp;
         cout<<endl<<"Node inserted after";
    }
}

void deleteNode(int targetKey) {
   if(!nodeExists(targetKey)) {
   	cout<<endl<<"Node with key does not exists..!";
    return;
   } 

   node *ptr = getRequiredNode(targetKey);

   if(head->key==targetKey && head->next==head && head->prev==head){
   	cout<<endl<<"head unlinked..LinkedList is empty";
   }
   else{
       
       node *currentNode = ptr;
       node *nextNode = currentNode->next;
       node *prevNode = currentNode->prev;


       nextNode->prev = prevNode;
       prevNode->next=nextNode;
       delete currentNode;
       cout<<"Node deleted..";
                      
   }
   
}

void updateNode(int keyOfNode,int dataOfNode) {
   node* ptr=head;
          do {
             if(ptr->key==keyOfNode){
             	ptr->data = dataOfNode;
             	cout<<endl<<"updated";
             	return;
             }
             ptr=ptr->next;
          }while(ptr!=head);

}
void printList() {
	node *ptr=head;
	do {
		cout<<endl<<ptr->key<<" : "<<ptr->data;
		ptr=ptr->next;	
	}while(ptr!=head);
}
};
int main() {
	doublyCircularLinkedList dcl;
	dcl.addNode(1,2);
	dcl.addNode(2,3);

	dcl.addNode(3,4);

	dcl.printList();
// dcl.prependNode(5,6);
	// dcl.insertAfter(2,5,6);
	// dcl.insertAfter(3,5,6);
	// dcl.deleteNode(2);
	dcl.updateNode(2,5);
	dcl.printList();

	return 0;
}