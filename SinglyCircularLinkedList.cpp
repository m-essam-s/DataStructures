#include<iostream>
using namespace std;

class SinglyCircularLinkedList{
private:
    class Node{
    public:
        int Data;
        Node* Next;
    };

    Node *Head;
    Node *Tail;
    int Length;

public:    
    SinglyCircularLinkedList(){
        Head = Tail = NULL;
        Length = 0;
    }

    void insertFirst(int element){
        Node *newNode = new Node;  
        newNode->Data = element; 
        if (Head == NULL){
            Head = newNode;
            Tail = newNode; // Update Tail to point to the new node
            newNode->Next = Head;
        } else {
            newNode->Next = Head;
            Tail->Next = newNode;
            Head = newNode;
        }
        Length++;
    }

    void insertLast(int element){

        Node *newNode = new Node;  
        newNode->Data = element; 
        if (Head == NULL){
            Head = newNode;
            Tail = newNode; // Update Tail to point to the new node
            newNode->Next = Head;
        } else {
            newNode->Next = Head;
            Tail->Next = newNode;
            Tail = newNode;
        }
        Length++;
    }

    void insertAtPos(int element, int Pos){
        if (Pos == 0){
            insertFirst(element);
        } else if (Pos == Length) {
            insertLast(element);
        } else if (Pos > Length){
            cout << "Position out of range" << endl;
        } else {
            Pos--; // Adjusting position to match zero-based indexing
            Node *newNode = new Node;
            newNode->Data = element;

            Node *Temp = Head;
            while (Pos--) { // Change to while (Pos--) to decrement Pos once per iteration
                Temp = Temp->Next;
            }
            newNode->Next = Temp->Next;
            Temp->Next = newNode;

            Length++;
        }         
    }

    void removeFirst() {
        if (Head == NULL) {
            cout << "The list is already empty\n";
        } else if (Head == Tail) {
            delete Head;
            Head = Tail = NULL;
            Length--;
        } else {
            Tail->Next = Head->Next;
            delete Head;
            Head = Tail->Next;

            Length--;
        }
    }

    void removeLast(){
        if (Tail == NULL){
            cout << "The list is already empty\n";
        } else if (Tail == Head){
            delete Tail;
            Tail = Head = NULL;
            Length--;
        } else {
            Node *Temp = Head;
            while (Temp->Next != Tail){
                Temp = Temp->Next;
            }

            delete Tail;
            Tail = Temp;
            Tail->Next = Head; // Update the new last node's Next pointer to point to Head

            Length--;
        }
    }
    
        void removeAtPos(int Pos){
        if (Pos == 0){
            removeFirst();
        } else if (Pos == Length - 1) {
            removeLast();
        } else if (Pos >= Length){
            cout << "Position out of range" << endl;
        } else {
            Pos--; // Adjusting position to match zero-based indexing

            Node *Temp = Head;
            while (Pos--) { // Change to while (Pos--) to decrement Pos once per iteration
                Temp = Temp->Next;
            }
            Node *ToDelete = Temp->Next;
            Temp->Next = Temp->Next->Next;
            delete ToDelete;
            Length--;
        }        
    }

    int getLength() {
        if (Head == NULL) {
            return 0; // Empty list
        }

        int len = 0;
        Node *currentNode = Head;
        do {
            len++;
            currentNode = currentNode->Next;
        } while (currentNode != Head);

        return len;
    }

    void atPos(int Pos){
        if (Pos == 0){
            cout << Head->Data << endl; 
        } else if (Pos == this->getLength()) {
            cout << Tail->Data << endl;
        } else if (Pos >= this->getLength()) {
            cout << "Position out of range" << endl;
        } else {
            Node *Temp = Head;
            while (Pos--) {
                Temp = Temp->Next;
            }
            cout << Temp->Data << endl;
        }
    }

    int find(int element){
        Node *Temp = Head;
        int index = 0;
        do {
            if (Temp->Data == element) {
                return index; 
            }
            Temp = Temp->Next;
            index++;
        } while (Temp != Head); // Loop until we reach the Head again, completing a full traversal
        return -1;
    }

    void reverse() {
        int len = getLength();
        if (len == 0) {
            cout << "Empty list" << endl;
        } else if (len == 1) {
            cout << "List has only one element (Already reversed)" << endl;
        } else {
            Node *current = Head;
            Node *pre = NULL;
            Node *next = NULL;
            while (current != NULL) {
                next = current->Next;
                current->Next = pre;
                pre = current;
                current = next;
            }
            Tail = Head; // Update Tail to the previous Head
            Head = pre; // Set the new Head
        }
    }

    void traverse() {
        if (Head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *currentNode = Head;
        do {
            cout << currentNode->Data << " -> ";
            currentNode = currentNode->Next;
        } while (currentNode != Tail);
        cout << Tail->Data << endl;
        
}
};

int main(){
    SinglyCircularLinkedList list;
    
    int x=10;
    while (x--){
        list.insertFirst(x);
    }
    
    list.traverse();
    list.removeFirst();
    list.removeLast();
    list.insertFirst(0);
    list.insertLast(9);
    list.removeAtPos(3);
    list.insertAtPos(3,3);
    list.traverse();
    list.atPos(3);
    cout<<list.getLength()<<endl;
    cout<<list.find(9)<<endl;
    cout<<list.find(10)<<endl;
    
    return 0;
}