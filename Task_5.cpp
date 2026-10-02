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

    void AddNode(int addData){
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr){
            head = newNode;
        }
        else {
            node* curr = head;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void DeleteNode(int delData){
        if(head == nullptr){
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        
        if (head->data == delData){
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* curr = head;
        node* prev = nullptr;
        
        while(curr != nullptr && curr->data != delData){
            prev = curr;
            curr = curr->next;
        }

        if(curr == nullptr){
            cout << "Value " << delData << " not found in the list." << endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
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

    cout << "--- Testing delete on empty list ---" << endl;
    myList.DeleteNode(10);

    cout << "\n--- Testing delete of the only node ---" << endl;
    myList.AddNode(50);
    cout << "List before: ";
    myList.PrintList();
    myList.DeleteNode(50);
    cout << "List after deleting 50: ";
    myList.PrintList();

    cout << "\n--- Setup main test case: 10, 20, 20, 30 ---" << endl;
    myList.AddNode(10);
    myList.AddNode(20);
    myList.AddNode(20);
    myList.AddNode(30);
    cout << "Current List: ";
    myList.PrintList();

    cout << "Deleting first node (10):" << endl;
    myList.DeleteNode(10);
    myList.PrintList();

    cout << "Deleting middle node (first 20):" << endl;
    myList.DeleteNode(20);
    myList.PrintList();

    cout << "Deleting last node (30):" << endl;
    myList.DeleteNode(30);
    myList.PrintList();

    cout << "Deleting a missing value (99):" << endl;
    myList.DeleteNode(99);
    myList.PrintList();

    myList.ClearList();
    return 0;
}