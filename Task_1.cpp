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

    void CreateThreeNodes(){
        int val1, val2, val3;
        cout << "Enter first integer: ";
        cin >> val1;
        cout << "Enter second integer: ";
        cin >> val2;
        cout << "Enter third integer: ";
        cin >> val3;

        node* n1 = new node;
        n1->data = val1;
        n1->next = nullptr;
        head = n1;

        node* n2 = new node;
        n2->data = val2;
        n2->next = nullptr;
        head->next = n2;

        node* n3 = new node;
        n3->data = val3;
        n3->next = nullptr;
        head->next->next = n3;
    }

    void PrintList(){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        node* curr = head;
        cout << "List contents: ";
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void ClearList(){
        node* curr = head;
        while (curr != nullptr) {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
    }
};

int main(){
    List myList;
    
    cout << "Testing PrintList before creation:" << endl;
    myList.PrintList();
    
    cout << "\nCreating list (please enter 10, 20, and 30):" << endl;
    myList.CreateThreeNodes();
    
    cout << "\nTesting PrintList after creation:" << endl;
    myList.PrintList();
    
    myList.ClearList();
    return 0;
}