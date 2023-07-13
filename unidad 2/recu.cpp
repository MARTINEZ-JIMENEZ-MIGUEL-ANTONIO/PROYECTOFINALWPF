#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void addNode(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = 0;

    if (*head == 0) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != 0) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != 0) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    ifstream file("datos.txt");
    if (!file) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    int data;
    Node* head = 0;
    while (file >> data) {
        addNode(&head, data);
    }

    printList(head);

    return 0;
}
