#include<iostream>
using namespace std;

//Creating the structure for LL
struct doubleLinkedList{
	int val;
	struct doubleLinkedList* next;
	struct doubleLinkedList* prev;
}

 
// Creating three list for having
// head, a temporarily list and
// a list for tail
struct doublelinkedlist* head;
struct doublelinkedlist* tail;
struct doublelinkedlist* temp;

int status;

//Function to add new node
//In the list

int AddNode(int value){
	//if head is null
	if(!head) {
	head = (struct doubleLinkedList*)malloc(sizeof(struct doubleLinkedList));

		if(!head) {
			cout<<"Unable to retrieve space\n";
			return -2; //
		}
		head->val = value;
		tail = head;
		head->prev = NULL;
	}
	else{
		temp = tail;
		temp->next = (struct doublelinkedlist*)malloc(
            sizeof(struct doublelinkedlist));
		 if (tail->next == NULL) {
            cout << "Unable to allocate space\n";
            return -2;
        }
 
        tail->next->val = value;
        tail = tail->next;
        tail->prev = temp;
    }
    tail->next = NULL;
 
    return 0;
}

//Function to print the LL
int printCache(void){
	if(!head){
		cout << "Add a node first\n";
        return -2;
	}
	else {
        temp = head;
        while (temp != NULL) {
            cout << "[" << temp->val<<"]->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    return 0;
}

//Function to search if the element is 
//already present in the list or not

int GetKey(int value)
{
    if (head == NULL) {
        cout << "Add a node first\n";
        return -1;
    }
 
    // Store head temporarily.
    temp = head;
 
    // Traverse Double Linked List.
    while (temp != NULL)
 
    {
        // If value in list
        // matches with given value.
        if (temp->val == value)
 
        {
            // Shift all values before
            // the found value to the right.
            while (temp != head) {
                temp->val = temp->prev->val;
                temp = temp->prev;
            }
 
            // Place the found
            // value at the head.
            head->val = value;
            return 0;
        }
 
        // Keep iterating the loop.
        temp = temp->next;
    }
 
    // For new elements.
    temp = tail->prev;
 
    // Shift all value to the
    // right and over-write
    // the last value.
    while (temp != NULL) {
        temp->next->val = temp->val;
        temp = temp->prev;
    }
 
    // Place new value at head.
    head->val = value;
    return 0;
}
 
// Initializing function
// that will create the
// list with values 0 in it.
int NodesInLRU(int number)
{
    static int i = 0;
    for (i = 0; i < number; i += 1) {
        status = AddNode(0);
 
        // if status is 0 then
        // it will return
        if (status < 0) {
            cout << "Could not assign node\n";
            return status;
        }
    }
    return 0;
}
 
// Function to perform LRU
// operations
void LRUOperations(int arr[], int n)
{
 
    // Iterating through the
    // elements so that LRU
    // operation can take place
    for (int i = 0; i < n; ++i) {
 
        GetKey(arr[i]);
 
        // If the status is -ve
        // then return
        if (status < 0) {
            exit(1);
        }
 
        // Printing it every time
        status = PrintCache();
    }
}
 
// Driver Code
int main(void)
{
    // Pre defining the
    // size of the cache
    int CAPACITY = 5;
    status = NodesInLRU(CAPACITY);
 
    // Number of elements
    // to be added in LRU List.
    int n = 10;
 
    // The Numbers to be
    // added in LRU List.
    int arr[] = { 1, 2, 3, 4, 5, 2, 10, 7, 11, 1 };
 
    LRUOperations(arr, n);
    return 0;
}