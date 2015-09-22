#include <iostream>
#include <string> 

using namespace std;

struct Node {
    int key;
    string value;
    Node* next;
}; 

// Pre-condition: The head of a linked list is provided and a key-value 
// pair to insert.
// Post-condition: The linked list now contains that element at the front.
void insert( Node*& head, int key, string value) {

    Node * temp;
    temp = new Node;
    temp->key = key;
    temp->value = value;

    temp->next = head;
    head = temp;
    
}

// Pre-condition: A linked list is provided.
// Post-condition: The linked list is printed to standard output.
void print( Node* head ) {
    Node* temp = head;
    while( temp != NULL ) {
	cout << "key: " << temp->key << " value: " << temp->value << endl;
        temp = temp->next;
    }
	cout<<endl;
}

// Pre-condition: The head of a linked list is provided.
// Post-condition: The last element of that linked list has been removed.
void delete_last_element( Node*& head )
{
    Node* temp = head;
    
    // empty list - do nothing
    
    if (temp != NULL){
        
        if (temp->next == NULL) { //one item
            delete head;
            head = NULL;
        }
        else {
            while (temp->next->next != NULL) { //more than one
                temp= temp->next;
            }
        
            delete temp->next;
            temp->next = NULL;
        }
    }
}


// Pre-condition: The head of a linked list is provided, and a key-value
// pair to insert after the indicated key.
// Post-condition: The linked list now contains that element.
void insert_after( Node*& head, int key, int newKey, string value )
{
     Node* n = head;
    
    if (n != NULL) {
        
        Node* temp = new Node;
        temp->key = newKey;
        temp->value = value;
        
        while (n->key != key) { //search through list
            if (n->next != NULL) {
                n = n->next;
            } else break;
        }
        
        if (n->key == key) { //what if not in list?
        temp->next = n->next;
        n->next = temp;
        }
    }
}

// Pre-condition: Two linked lists are provided.
// Post-condition: A linked list is returned that is the result of
// interleaving the elements from each list provided (e.g. {1, 2, 3} &
// { 4, 5, 6} would return {1, 4, 2, 5, 3, 6}

// Assume lists are of the same length?

Node* interleave( Node*& list1, Node*& list2 )
{
    Node* l1 = list1;
    Node* l2 = list2;
    
    Node* ptr = NULL;
    
    if (l1 == NULL) {
        return l2;
    }
    else if (l2 == NULL) {
        return l1;
    }
    else if (l1 != NULL && l2 != NULL) {
        
        if (l1->next == NULL && l2->next == NULL) { //one element each
            l1->next = l2;
            return list1;
        }
        else if (l1->next != NULL && l2->next != NULL) {
            while (l1->next != NULL) {
                ptr = l1->next;
                l1->next = l2;
                l2 = ptr;
                l1 = l1->next;
            }
            
            l1->next = l2;
            return list1;
        }
    }
    
    return NULL;
}

int main() {

    Node * list1 = NULL;
    Node * list2 = NULL;
	Node * list3 = NULL;
	Node * list4 = NULL;
    Node * list5 = NULL;
    Node * list6 = NULL;
    Node * list7 = NULL;
    Node * list8 = NULL;
    
    

    insert( list1, 1, "one");
    insert( list1, 2, "two");
    
    cout << "<1> Linked List 1..." << endl;
    print(list1); // list1 is 2,1
    
    insert( list2, 10, "ten");
    insert( list2, 9, "nine");
    insert( list2, 8, "eight");
    insert( list2, 7, "seven");
    insert( list2, 6, "six");

    cout << "<2> Linked List 2..." << endl;
    print( list2 ); // list2 is 6,7,8,9,10
    
	delete_last_element( list1 ); //list1 is 2
    
    cout << "<3> Linked List 1..." << endl;
	print( list1 ); //list1 is empty

	delete_last_element( list1 ); //list1 is 2, 6,
    delete_last_element( list1 );
    delete_last_element( list1 );
    
    cout << "<4> Linked List 1..." << endl;
	print( list1 ); //list1 is empty

	delete_last_element( list1 ); //list1 is empty
    cout << "<5> Linked List 1..." << endl;
	print( list1 );

	insert(list1, 11, "eleven");
	insert_after(list1, 11, 12, "twelve"); //list1 is 11,12
    cout << "<6> Linked List 1..." << endl;
	print( list1 );
    
	insert_after(list1, 13, 14, "fourteen"); //list1 is 11,12
    cout << "<7> Linked List 1..." << endl;
	print( list1 );

	list4 = interleave(list1, list2); //11, 6, 12, 7, 8 , 9, 10
    cout << "<8> Linked List 4..." << endl;
	print( list4 );

	list4 = interleave(list1, list3); //list4 = ^
    cout << "<9> Linked List 4..." << endl;
	print( list4 );

	list4 = interleave(list3, list3); //list4 = empty (no list 3)
    cout << "<10> Linked List 4..." << endl;
	print( list4 );
    
    insert(list6, 1, "one");
    insert(list7, 2, "two");
    list8 = interleave(list6, list7);
    cout << "<0> Linked List 8..." << endl;
    print(list8);
    
    insert( list1, 1, "one");
    insert( list1, 2, "two"); // list1 is 2,1
    
    cout << "<11> Linked List 1..." << endl;
    print(list1);
    
    insert(list5, 3, "three"); // list 5 is 6, 3
    insert(list5, 6, "six");
    
    list4 = interleave(list1, list5);
    cout << "<12> Linked List 4..." << endl;
    print (list4);

    return 0;
}
