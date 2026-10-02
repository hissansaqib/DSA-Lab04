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

    int CountNodes(){
        int count = 0;
        node* curr = head;
        while(curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    void PrintList(){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        node* curr = head;
        cout << "List: ";
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
    int n, val;

    cout << "Enter a non-negative number of nodes to append: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        cout << "Enter value " << i + 1 << ": ";
        cin >> val;
        myList.AddNode(val);
    }

    myList.PrintList();
    cout << "Total number of nodes: " << myList.CountNodes() << endl;

    myList.ClearList();
    return 0;
}