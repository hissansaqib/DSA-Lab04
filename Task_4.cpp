// Name: Muhammad Hissan Saqib
// Registration Number: 543530
// Section: BSCS-15-D

#include <iostream>
using namespace std;

class List{
private:
    struct node {
        int data;
        node* next;
    };
    node* head;

public:
    List(){
        head = nullptr;
    }

    void InsertAtBeginning(int addData){
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = head;
        head = newNode;
    }

    void AddNode(int addData){
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = nullptr;

        if(head == nullptr){
            head = newNode;
        }
        else{
            node* curr = head;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void PrintList(){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void ClearList(){
        node* curr = head;
        while(curr != nullptr){
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
    }
};

int main(){
    List myList;

    cout << "Starting with an empty list." << endl;
    myList.PrintList();

    cout << "Inserting 20 at the beginning:" << endl;
    myList.InsertAtBeginning(20);
    myList.PrintList();

    cout << "Inserting 10 at the beginning:" << endl;
    myList.InsertAtBeginning(10);
    myList.PrintList();

    cout << "Appending 30 at the end:" << endl;
    myList.AddNode(30);
    myList.PrintList();

    myList.ClearList();
    return 0;
}