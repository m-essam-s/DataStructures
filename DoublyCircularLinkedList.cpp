#include <iostream>
using namespace std;

class DounlyCircularLinkedList {
private:
    class Node {
    public:
        int Data;
        Node* Next;
        Node* Prev;
    };

    Node *Head;
    Node *Tail;
    int Length;

public:    
    DounlyCircularLinkedList() {
        Head = Tail = NULL;
        Length = 0; 
    }

    void insertFirst(int element) {
        Node *newNode = new Node;  
        newNode->Data = element; 
        newNode->Next = newNode->Prev = newNode;

        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            newNode->Next = Head;
            newNode->Prev = Tail;
            Head->Prev = newNode;
            Tail->Next = newNode;
            Head = newNode;
        }
        Length++;
    }

    void insertLast(int element) {
        Node *newNode = new Node;
        newNode->Data = element;
        newNode->Next = newNode->Prev = newNode;

        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            newNode->Next = Head;
            newNode->Prev = Tail;
            Tail->Next = newNode;
            Head->Prev = newNode;
            Tail = newNode;
        }
        Length++;
    }

    void insertAtPos(int element, int Pos) {
        if (Pos == 0) {
            insertFirst(element);
        } else if (Pos == Length) {
            insertLast(element);
        } else if (Pos > Length || Pos < 0) {
            cout << "Position out of range" << endl;
        } else {
            // Adjust position to match zero-based indexing
            Pos--;
            Node *newNode = new Node;
            newNode->Data = element;

            Node *Temp = Head;
            while (Pos--) {
                Temp = Temp->Next;
            }
            // Insert the new node at the specified position
            newNode->Next = Temp->Next;
            Temp->Next->Prev = newNode;
            newNode->Prev = Temp;
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
        } else {
            Node *Temp = Head;
            Head = Head->Next;
            Head->Prev = Tail;
            Tail->Next = Head;
            delete Temp;
        }
        Length--;
    }

    void removeLast() {
        if (Tail == NULL) {
            cout << "The list is already empty\n";
        } else if (Head == Tail) {
            delete Tail;
            Head = Tail = NULL;
            Length = 0;
        } else {
            Node *Temp = Tail;
            Tail = Tail->Prev;
            Tail->Next = Head;
            Head->Prev = Tail;
            delete Temp;
            Length--;
        }
    }
    
    void removeAtPos(int Pos) {
        if (Pos == 0) {
            removeFirst();
        } else if (Pos == Length - 1) {
            removeLast();
        } else if (Pos >= Length || Pos < 0) {
            cout << "Position out of range" << endl;
        } else {
            // Adjusting position to match zero-based indexing
            Pos--;

            Node *Temp = Head;
            while (Pos--) {
                Temp = Temp->Next;
            }

            Node *ToDelete = Temp->Next;
            Temp->Next = ToDelete->Next;
            ToDelete->Next->Prev = Temp;

            delete ToDelete;
            Length--;
        }
    }

    int getLength() {
        return Length;
    }

    int find(int element) {
        if (Head == NULL) {
            return -1;
        }

        Node *Temp = Head;
        int index = 0;
        do {
            if (Temp->Data == element) {
                return index;
            }
            Temp = Temp->Next;
            index++;
        } while (Temp != Head);

        return -1;
    }

    void atPos(int Pos) {
        if (Pos < 0 || Pos >= Length) {
            cout << "Position out of range" << endl;
            return;
        }

        Node *Temp = Head;
        for (int i = 0; i < Pos; i++) {
            Temp = Temp->Next;
        }
        cout << Temp->Data << endl;
    }

    void traverseForward() {
        if (Head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *currentNode = Head;
        do {
            cout << currentNode->Data << " -> ";
            currentNode = currentNode->Next;
        } while (currentNode->Next != Head);
        cout << Tail->Data << endl;
    }

    void traverseBackward() {
        if (Head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *currentNode = Tail;
        do {
            cout << currentNode->Data << " -> ";
            currentNode = currentNode->Prev;
        } while (currentNode->Prev!= Tail);
        cout << Head->Data << endl;
    }
};

int main(){
    DounlyCircularLinkedList list;
    
    int x=10;
    while (x--){
        list.insertFirst(x);
    }
    
    list.traverseForward();
    list.removeFirst();
    list.removeLast();
    list.insertFirst(0);
    list.insertLast(9);
    list.removeAtPos(3);
    list.insertAtPos(3,3);
    list.traverseForward();
    list.traverseBackward();
    list.atPos(3);
    cout<<list.getLength()<<endl;
    cout<<list.find(9)<<endl;
    cout<<list.find(10)<<endl;

    return 0;
}