#include <iostream>
using namespace std;
class Node{
    private:
    int key;
    Node* prev;
    Node* next;
    public:
    Node(){
        key = 0;
        prev = NULL;
        next = NULL;
    }
    ~Node(){
        delete[] prev;
        delete[] next;
    }
}
class Double_linkedList{
    private:
    Node* head;
    int length;
    public:
    Double_linkedList(){
        head = NULL;
        length++;
    }
    ~Double_linkedList(){
        delete[] head;
    }
    void insert(int);
    void delete(int,int);
    void printList();
}
void Double_linkedList:: insert(int data){
    Node* temp = NULL;
    Node* newnode = new Node(data);
    if (head == NULL){
        head = newnode;
    }
    temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    new->prev = temp;
}
void Double_linkedList::delete(int offSet,int op){
    Node* temp1 = head,Node* temp2 = NULL;
    if (op == 1){
        temp2 = temp1->next;
        temp2->prev = NULL;
        head =  temp2;
    }
    else  if (op == 2){
        while(temp1->next != NULL){
            temp1 = temp->next;
            length++;
    }
    delete temp1;
    }  
    else {
        while(temp1->key != offSet){
            temp1 = temp1->next;
        }
        temp2 = temp1.prev;
        delete temp1;
    }
}
void Double_linkedList::printList(){
    Node* temp =  head;
    while(temp->next !=  NULL){
        temp = temp->next
        length++;
    }
    int* arr =  new int[length];
    temp =  head;
    while(length--> 0){
         if(length == 1){
            cout << temp->key << endl
         }
         else cout<< temp->key << " ";
    }
}
int main(){
    return 0;
}