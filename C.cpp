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
    public:
    Double_linkedList(){
        head = NULL;
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
    else if(op == 2){
        while(temp1->next != NULL){
            temp1->next = temp1;'
            '
        }
    }
}
int main(){

}