#include<iostream>
using namespace std;

class DounlyLinkedList{
private:
    class Node{
    public:
        int Data;
        Node* Next;
        Node* Prev;
    };

    Node *Head;
    Node *Tail;
    int Length;

public:    
    DounlyLinkedList(){
        Head = Tail = NULL;
        Length = 0;
    }

    void insertFirst(int element) {
        Node *newNode = new Node;  
        newNode->Data = element; 
        newNode->Next = Head;
        newNode->Prev = NULL; 
        
        if (Head != NULL) {
            Head->Prev = newNode;
        } else {
            // If the list was empty, newNode is both Head and Tail
            Tail = newNode;
        }
    
        Head = newNode; 
        Length++;
}

    void insertLast(int element) {

        Node *newNode = new Node;
        newNode->Data = element;
        newNode->Next = NULL;

        if (Head == NULL) {
            Head = Tail = newNode;
            newNode->Prev=NULL;
        } else {
            newNode->Prev=Tail;
            Tail->Next = newNode;
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
            Pos--; // Adjusting position to match zero-based indexing
            Node *newNode = new Node;
            newNode->Data = element;

            Node *Temp = Head;
            while (Pos--) {
                Temp = Temp->Next;
            }
            newNode->Next = Temp->Next;
            Temp->Next->Prev = newNode;
            newNode->Prev = Temp;
            Temp->Next = newNode;

            Length++;
        }
    }

    void removeFirst(){
        if (Head==NULL){
            cout<<"The list is aready empty\n";
        }else if (Head==Tail){
            delete Head;
            Head = Tail = NULL;

            Length--;
        }else {
            Node *Temp = Head;
            Head = Head->Next;
            if (Head != NULL) {
                Head->Prev = NULL;
            } else {
                // If Head->Next is NULL, Head is now the only node in the list
                Tail = NULL;
            }
            delete Temp;
            Length--;
        }
    }

    void removeLast(){
        if (Tail==NULL){
            cout<<"The list is aready empty\n";
        }else if (Tail==Head){
            delete Tail;
            Tail = Head = NULL;
            Length--;
        }else{
            Node *Temp = Tail;
            Tail = Tail->Prev;
            if (Tail != NULL) {
                Tail->Next = NULL;
            }else{
                // If Tail->Prev is NULL, Tail is now the only node in the list
                Head = NULL;
            }       
            delete Temp;

            Length--;
        }
    }
    
    void removeAtPos(int Pos){
       if (Pos==0){
            removeFirst();
        }else if (Pos == Length - 1) {
            removeLast();
        }else if (Pos>Length || Pos<0){
            cout<<"Position out of range"<<endl;
        }else{
            Pos--; // Adjusting position to match zero-based indexing
            
            Node *Temp = Head;
            while (Pos--){
                Temp=Temp->Next;
            }

            Node *ToDelete = Temp->Next;
            Temp->Next = Temp->Next->Next;

            if (Temp->Next != NULL) {
                Temp->Next->Prev = Temp;
            } else {
                // If the next node is NULL, the deleted node was the previous Tail
                Tail = Temp;
            }
            
            delete ToDelete;
            Length--;
        }        
    }

    int getLength(){
        int len=0;
        Node *currentNode = Head;
        while (currentNode!= NULL){
            len++;
            currentNode = currentNode->Next;
        }
        return len;
    }

    void atPos(int Pos){
        
        if (Pos==0){
            cout<<Head->Data<<endl; 
        }else if (Pos==this->getLength()-1){
            cout<<Tail->Data<<endl;
        }else if (Pos>=this->getLength()){
            cout<<"Position out of range"<<endl;
        }else{
            Node *Temp = Head;
            while (Pos--){
                Temp=Temp->Next;
            }
            cout<<Temp->Data<<endl;
        }
    }

    int find(int element){
        Node *Temp=Head;
        int index=0;
        while (Temp!=NULL){
            if (Temp->Data==element){
                return index; 
            }
            Temp=Temp->Next;
            index++;
        }
        return -1;
    }

    void traverseForward(){
        if (Head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        Node *currentNode = Head;
        while (currentNode->Next != NULL){
            cout << currentNode->Data << " -> ";
            currentNode = currentNode->Next;
        }
        cout << Tail->Data << endl;
    }

    void traverseBackward(){
        if (Head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        Node *currentNode = Tail;
        while (currentNode->Prev != NULL){
            cout << currentNode->Data << " -> ";
            currentNode = currentNode->Prev;
        }
        cout << Head->Data << endl;
    }
};

int main(){
    DounlyLinkedList list;
    
    int x=10;
    while (x--){
        list.insertFirst(x);
    }
    
    list.traverseForward();
    list.insertAtPos(100,3);
    list.traverseForward();
    list.removeAtPos(3);
    list.traverseForward();
    list.atPos(8);
    
    cout<<list.getLength()<<endl;
    cout<<list.find(10)<<endl;
    cout<<list.find(0)<<endl;
    list.insertLast(5);
    list.insertLast(6);
    
    list.traverseForward();

    list.insertFirst(5);
    list.insertFirst(6);
    list.insertFirst(7);
    list.insertFirst(3);
    list.insertLast(99);
    list.insertLast(100);
    list.removeFirst();
    list.insertFirst(3);
    list.removeLast();
    list.insertLast(99);
    list.traverseForward();
    list.traverseBackward();
    list.atPos(5);
    cout<<list.find(99)<<endl;

    
    return 0;
}