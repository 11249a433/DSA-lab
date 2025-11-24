#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Insert at top
void insertAtTop(Node* &head, int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(Node* &head, int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Insert in middle (position)
void insertAtMiddle(Node* &head, int value, int position) {
    if (position <= 1 || head == nullptr) {
        insertAtTop(head, value);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (temp->next != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    Node *newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at top
void deleteAtTop(Node* &head) {
    if (head == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

// Delete at end
void deleteAtEnd(Node* &head) {
    if (head == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;

    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == nullptr)
        head = nullptr;
    else
        prev->next = nullptr;

    delete temp;
}

// Delete at middle
void deleteAtMiddle(Node* &head, int position) {
    if (head == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }

    if (position == 1) {
        deleteAtTop(head);
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;
    int count = 1;

    while (temp != nullptr && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}

// Search element
int search(Node *head, int value) {
    int position = 1;
    while (head != nullptr) {
        if (head->data == value)
            return position;

        head = head->next;
        position++;
    }
    return -1;
}

// Traverse
void traverse(Node *head) {
    cout << "Stack (top to bottom): ";
    Node *temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Main
int main() {
    Node *stack = nullptr;

    insertAtTop(stack, 10);
    insertAtTop(stack, 20);
    insertAtTop(stack, 5);
    insertAtMiddle(stack, 15, 2);

    traverse(stack);

    cout << "Position of 15: " << search(stack, 15) << endl;
    cout << "Position of 100: " << search(stack, 100) << endl;

    deleteAtTop(stack);
    traverse(stack);

    deleteAtEnd(stack);
    traverse(stack);

    deleteAtMiddle(stack, 2);
    traverse(stack);

    return 0;
}