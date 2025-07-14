#include "SinglyLinkedList.hpp"
#include <iostream>
#include <utility> // para std::swap

SinglyLinkedList::SinglyLinkedList() : head(nullptr), size(0) {}

SinglyLinkedList::~SinglyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void SinglyLinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    size++;
}

void SinglyLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    size++;
}

void SinglyLinkedList::insertAtPosition(int pos, int value) {
    if (pos < 0 || pos > size) return;

    if (pos == 0) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node{value, nullptr};
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

bool SinglyLinkedList::removeByValue(int value) {
    if (!head) return false;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr) {
        if (curr->data == value) {
            prev->next = curr->next;
            delete curr;
            size--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

bool SinglyLinkedList::removeByPosition(int pos) {
    if (pos < 0 || pos >= size || !head) return false;

    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    size--;
    return true;
}

void SinglyLinkedList::sort() {
    if (!head || !head->next) return;

    for (int i = 0; i < size; i++) {
        Node* curr = head;
        while (curr->next) {
            if (curr->data > curr->next->data)
                std::swap(curr->data, curr->next->data);
            curr = curr->next;
        }
    }
}

bool SinglyLinkedList::search(int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

int SinglyLinkedList::getSize() const {
    return size;
}

void SinglyLinkedList::display() {
    Node* temp = head;
    std::cout << "Lista Encadeada: ";
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}
