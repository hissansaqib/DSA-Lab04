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
        cout << "Inserted " << addData << " at the beginning." << endl;
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
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        cout << "Inserted " << addData << " at the end." << endl;
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

    void DeleteNode(int delData){
        if(head == nullptr){
            cout << "List is empty, cannot delete." << endl;
            return;
        }
        if (head->data == delData){
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << delData << " from the list." << endl;
            return;
        }
        
        node* curr = head;
        node* prev = nullptr;
        while(curr != nullptr && curr->data != delData){
            prev = curr;
            curr = curr->next;
        }
        
        if(curr == nullptr){
            cout << "Value not found." << endl;
            return;
        }
        
        prev->next = curr->next;
        delete curr;
        cout << "Deleted " << delData << " from the list." << endl;
    }

    void PrintList(){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        node* curr = head;
        cout << "Nodes in list: ";
        while (curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void CountNodes(){
        int count = 0;
        node* curr = head;
        while(curr != nullptr){
            count++;
            curr = curr->next;
        }
        cout << "Total number of nodes: " << count << endl;
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
        while (curr != nullptr){
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
    }
};

int main(){
    List myList;
    int choice = 0;
    int value;

    while(choice != 8){
        cout << "\n--- Linked List Application Menu ---" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Search by value" << endl;
        cout << "4. Delete by value" << endl;
        cout << "5. Display all nodes" << endl;
        cout << "6. Count nodes" << endl;
        cout << "7. Display second node" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1){
            cout << "Enter value to insert: ";
            cin >> value;
            myList.InsertAtBeginning(value);
        }
        else if (choice == 2){
            cout << "Enter value to insert: ";
            cin >> value;
            myList.AddNode(value);
        }
        else if(choice == 3){
            cout << "Enter value to search: ";
            cin >> value;
            myList.SearchNode(value);
        }
        else if (choice == 4){
            cout << "Enter value to delete: ";
            cin >> value;
            myList.DeleteNode(value);
        }
        else if(choice == 5){
            myList.PrintList();
        }
        else if(choice == 6){
            myList.CountNodes();
        }
        else if (choice == 7){
            myList.PrintSecondNode();
        }
        else if(choice == 8){
            cout << "Exiting program and clearing memory..." << endl;
            myList.ClearList();
        }
        else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    return 0;
}