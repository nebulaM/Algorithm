// linked_list.cc -- functions for linked_list lab (cs221) 
#include <iostream>
#include <vector> 
struct Node {
  int key;
  Node* next;
}; 

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */ 
void insert( Node*& head, int newKey) {
  Node * curr = new Node;
  curr->key  = newKey;
  curr->next = head;
  head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
void print( Node* head ) {
  std::cout << "[";
  for (Node* curr = head; curr != NULL; curr = curr->next ){ 
    std::cout << curr->key;
    if( curr->next != NULL ) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
int size( Node* head ){ 
  if (! head) return 0; 
  return 1 + size( head->next ); 
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */ 
std::vector<int>* to_vector(Node* head){ 
  std::vector<int>* result = new std::vector<int>(); 
  for (Node* curr = head; curr != NULL; curr = curr->next ){ 
    result->push_back( curr->key ); 
  }
  return result; 
}

/** 
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed 
 */
 /*
 side note on *& (http://stackoverflow.com/questions/5789806/meaning-of-and-in-c)
 void nochange( int* pointer ) //passed by value
 {
 pointer++; // change will be discarded once function returns
 }

 void change( int*& pointer ) //passed by reference
 {
 pointer++; // change will persist when function returns
 }
 */
void delete_last_element( Node*& head ){
	//delete a node only if list is not empty
	if (head) {
		if (!head->next) {
			//std::cout << "only one node" << std::endl;
			delete head;
			//necessary to let head=NULL
			head = NULL;
		}
		else {
			//std::cout << "at least 2 nodes" << std:: endl;
			Node *prev = head, *ptr = head->next;
			while (ptr->next) {
				prev = ptr;
				ptr = ptr->next;
			}
			delete ptr;
			//old second last node now has next node = NULL
			prev->next = NULL;
		}
	}
}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list. 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value of the key in the Node to be removed 
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed 
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 */ 
void remove( Node*& head, int oldKey) {
	if (head) {
		if (!head->next) {
			if (head->key == oldKey) {
				delete head;
				head = NULL;
			}
		}
		else {
			Node *prev = head, * ptr = head->next;
			while(ptr) {
				if (ptr->key == oldKey) {
					prev->next = ptr->next;
					delete ptr;
					ptr = NULL;
					break;
				}
				prev = ptr;
				ptr = ptr->next;
			}
		}
	}
}

void insert_btw(Node*& prev, Node*& next, int newKey) {
	Node * curr = new Node;
	curr->key = newKey;
	curr->next = next;
	prev->next = curr;
}


/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value to look for (in the key of an existing Node)  
 * PRE: newKey is the value of the key in the new Node (that might be inserted) 
 * POST: If no Node with key=oldKey was found, then the linked_list has not changed 
 * POST: Else a new Node (with key=newKey) is right after the Node with key = oldKey. 
 */
void insert_after( Node* head, int oldKey, int newKey ){
	if (head) {
		while (head) {
			if (head->key == oldKey) {
				Node * curr = new Node;
				curr->key = newKey;
				curr->next = head->next;
				head->next = curr;
			}	
			head = head->next;
		}
	}
}
void interleavInsert(Node*& head, int newKey) {
	Node * curr = new Node;
	curr->key = newKey;
	curr->next = NULL;
	while (head->next) {
		head = head->next;
	}
	head->next = curr;
	head = head->next;
}
/** 
 * Create a new linked_list by merging two existing linked_lists. 
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from 
 * the Nodes in list1 and list2, starting with the key of the first Node of list1, 
 * then the key of the first Node of list2, etc. 
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node* interleave( Node* list1, Node* list2 ){
	Node head;
	head.next = NULL;
	Node *ptr = &head;
	while (list1&&list2) {
		if (list1) {
			/*the following code leads to infinite loop
				ptr->next=list1;
				list1=list1->next;
				ptr=ptr->next;
			*/
			interleavInsert(ptr, list1->key);
			list1 = list1->next;
			
		}
		if (list2) {
			interleavInsert(ptr, list2->key);
			list2 = list2->next;
		}
	}
	ptr->next=(list1)? list1 : list2;
	return head.next;
}

