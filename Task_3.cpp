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

    void SearchNode(int searchData){
        int pos = 1;
        node* curr = head;
        while(curr != nullptr){
            if(curr->data == searchData){
                cout << "Value found at position " << pos << endl;
                return;
            }
            pos++;
            curr = curr->next;
        }
        cout << "Value not found" << endl;
    }

    void PrintSecondNode(){
        if(head == nullptr || head->next == nullptr){
            cout << "Fewer than two nodes exist." << endl;
        }
        else{
            cout << "Second node is: " << head->next->data << endl;
        }
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

    cout << "--- Testing empty list ---" << endl;
    myList.PrintSecondNode();
    
    cout << "\n--- Testing one-node list ---" << endl;
    myList.AddNode(10);
    myList.PrintSecondNode();

    cout << "\n--- Testing list with 10, 20, 30, 20 ---" << endl;
    myList.AddNode(20);
    myList.AddNode(30);
    myList.AddNode(20);
    
    myList.PrintSecondNode();
    
    cout << "Searching for 20: ";
    myList.SearchNode(20);
    
    cout << "Searching for 99: ";
    myList.SearchNode(99);

    myList.ClearList();
    return 0;
}