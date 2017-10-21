/*
Name      : Elizabeth Wanic
Date      : 20 November 2016
File Name : WanicHomework2.cpp
Task      : As per Home Assignment 2 instructions:
        Write a struct Node declaration defining a node type for a doubly 
        linked list with links to the successor and predecessor nodes.
        Assume that the data field is of type int. Define a 
        class DblList with the following public member functions:
        normal constructor
        destructor
        copy constructor
        int length()
        void add_begin(int new_val)
        void add_end(int new_val)
        void print_list()
        void print_reverse()
        int pop_begin()
        int pop_end()
		
        Create a main() function that does the following:
		a) Create a doubly linked list Q1 with three nodes using 
		add_begin() function, add one more element at the end using 
		add_end() function. Print length of the list and the list 
		contents after each operation.
		b) Print the list in reverse order.
		c) Delete the first and the last nodes of the list, and 
		print the length of the list and list contents after each
		operation.
		d) Declare another variable Q2 of the DblList type and 
		initialize it with the previous list (DblList Q2 = Q1) to 
		demonstrate that copy constructor works, print Q2 after the 
		initialization.  */

#include <iostream>
using namespace std;

// Creation of Node type
struct Node {
    int data;
    Node * next;
    Node * previous;
};

// Creation of class DblList
class DblList {
    Node *head;
    Node *tail;
    int len;

// Creation of public class functions
public:
    // constructor
    DblList() {

        head = NULL;
        tail = NULL;
        len = 0;
    }

    // destructor
    ~DblList() {

        while (head != NULL) {
            Node *nextNode = head->next;
            delete head;
            head = nextNode;

        }
    }

    // copy constructor
    DblList(const DblList &ob) {

        if (!ob.head)
            *this = ob;

        else {
            head = new Node;
            *head = *ob.head;

            Node *prev = head;
            Node *oldtemp = ob.head;
            Node *newtemp = head;

            while (oldtemp->next) {
                // create a copy of node
                oldtemp = oldtemp->next;
                newtemp = new Node;
                *newtemp = *oldtemp;

                // connect the previous with this one
                prev->next = newtemp;
                newtemp->previous = prev;
                prev = newtemp;

            } // end while

            tail = newtemp;
            len = ob.len;
        }// end else
    }

    // get the length
    int length() {

        return len;
    }

    // add an element to the beginning
    void add_begin(int new_val) {

        Node *n = new Node;
        n->data = new_val;
        n->next = head;
        n->previous = NULL;

        if (len == 0){
            head = n;
            tail = n;
            len++;
        }else{
            head->previous = n;
            head = n;
            len++;
        }

    }

    // add an element to the end
    void add_end(int new_val) {

        Node *n = new Node;
        n->data = new_val;
        n->next = NULL;
        n->previous = tail;

        if (len == 0){
            tail = n;
            head = n;
            len++;

        } else {
            tail->next = n;
            tail = n;
            len++;
        }

    }

    // print the list from front to back
    void print_list() {

        if (len == 0)
            return;

        Node *printNode = head;

        while (printNode != NULL) {
            cout << printNode->data << ' ';
            printNode = printNode->next;
        }

        cout << endl;
    }

    // print the list from back to front
    void print_reverse() {

        if (len == 0)
            return;

        Node *printNode = tail;

        while (printNode != NULL) {
            cout << printNode->data << ' ';
            printNode = printNode->previous;
        }

        cout << endl;
    }

    // delete a node at the beginning of list and return the value stored in that node
    // if the list is empty, print a message and return 0
    int pop_begin() {

        if (len == 0) {
            cout << "The list is empty.\n" << endl;
            return 0;

        } else {
            Node *beginning = head;
            int value = beginning->data;
            head = beginning->next;
            delete beginning;
            head->previous = NULL;
            len--;
            return value;
        }

    }

    // delete a node at the end of list and return the value stored in that node
    // if the list is empty, print a message and return 0
    int pop_end() {

        if (len == 0) {
            cout << "The list is empty.\n" << endl;
            return 0;

        } else {
            Node *end = tail;
            int value = end->data;
            tail = end->previous;
            delete end;
            tail->next = NULL;
            len--;
            return value;
        }

    }
};

int main(){

    // create a DblList Q1
    DblList Q1;

    // use add_begin to add three nodes
    // print length and list contents after each operation
    Q1.add_begin(3);
    cout << "\nPrinting the list after adding one element" << endl;
    Q1.print_list();
    cout << "The length is " << Q1.length() << endl;

    Q1.add_begin(2);
    cout << "\nPrinting the list after adding two elements" << endl;
    Q1.print_list();
    cout << "The length is " << Q1.length() << endl;

    Q1.add_begin(1);
    cout << "\nPrinting the list after adding three elements" << endl;
    Q1.print_list();
    cout << "The length is " << Q1.length() << endl;

    // use add_end to add another node
    // print length and list contents
    Q1.add_end(4);
    cout << "\nPrinting the list after adding an element at the end" << endl;
    Q1.print_list();
    cout << "The length is " << Q1.length() << endl;

    // print the list in reverse order
    cout << "\nPrinting the list in reverse order" << endl;
    Q1.print_reverse();

    // delete the first and the last nodes of the list
    // print length and list contents after each operation
    Q1.pop_begin();
    cout << "\nPrinting the list after deleting the first element" << endl;
    Q1.print_list();
    cout << "The length is " << Q1.length() << endl;

    Q1.pop_end();
    cout << "\nPrinting the list after deleting the last element" << endl;
    Q1.print_list();
    cout << "The length is " << Q1.length() << endl;

    // declare another variable Q2 of the DblList type and initialize it with the previous list
    DblList Q2 = Q1;

    // To demonstrate that copy constructor works, print Q2 after the initialization
    cout << "\nPrinting Q2" << endl;
    Q2.print_list();



    return 0;
}


