#include<iostream>
using namespace std;

class DounlyLinkedList{
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
    DounlyLinkedList(){
        Head = Tail = NULL;
        Length = 0;
    }

    void insertFirst(int element){

        Node *newNode = new Node;  
        newNode->Data = element; 

        newNode->Next = Head; 
        Head = newNode; 

        if (Tail == NULL) 
            Tail = newNode; 
        
        Length++;
    }

    void insertLast(int element){

        Node *newNode = new Node;
        newNode->Data = element;
        newNode->Next = NULL;

        if (Head == NULL){
            Head = Tail = newNode;
        } else {
            Tail->Next = newNode;
            Tail = newNode;
        }
        Length++;
    }

    void insertAtPos(int element, int Pos){
        if (Pos==0){
            insertFirst(element);
        }else if (Pos==Length) {
            insertLast(element);
        }else if (Pos>Length){
            cout<<"Position out of range"<<endl;
        }else{
            Pos--; // Adjusting position to match zero-based indexing
            Node *newNode = new Node;
            newNode->Data = element;
            
            Node *Temp = Head;
            while (Pos--){
                Temp=Temp->Next;
            }
            newNode->Next = Temp->Next;
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
        }else{
            Node *Temp = Head;
            Head = Head->Next;
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
            Node *Temp = Head;
            
            while (Temp->Next!=Tail){
                Temp=Temp->Next;
            }

            delete Tail;
            Tail=Temp;
            Tail->Next=NULL;

            Length--;
        }
    }
    
    void removeAtPos(int Pos){
       if (Pos==0){
            removeFirst();
        }else if (Pos == Length - 1) {
            removeLast();
        }else if (Pos >= Length){
            cout<<"Position out of range"<<endl;
        }else{
            Pos--; // Adjusting position to match zero-based indexing
            
            Node *Temp = Head;
            while (Pos--){
                Temp=Temp->Next;
            }
            Node *ToDelete = Temp->Next;
            Temp->Next = Temp->Next->Next;
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

    void reverse(){
        int len=getLength();
        if (len==0){
            cout << "Empty list" << endl;
        }else if (len==1){
            cout << "list has onle one element (Already reversed)" << endl;
        }else{
            Node *current = Head;
            Node *prev = NULL;
            Node *next = NULL;
            while (current != NULL) {
                next = current->Next;
                current->Next = prev;
                prev = current;
                current = next;
            }
        Tail = Head; // Updating Tail to the previous Head
        Head = prev; // Setting the new Head
        }
    }

    void traverse(){
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
};

int main(){
    DounlyLinkedList list;
    
    int x=10;
    while (x--){
        list.insertFirst(x);
    }
    
    list.traverse();
    list.insertAtPos(100,3);
    list.traverse();
    list.removeAtPos(3);
    list.traverse();
    list.atPos(8);
    
    cout<<list.getLength()<<endl;
    cout<<list.find(10)<<endl;
    cout<<list.find(0)<<endl;
    list.insertLast(5);
    list.insertLast(6);
    
    list.reverse();
    list.traverse();
    
    return 0;
}