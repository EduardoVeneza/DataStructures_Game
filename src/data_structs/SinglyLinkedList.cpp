#include "SinglyLinkedList.hpp"

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

void SinglyLinkedList::clear() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

void SinglyLinkedList::insertAtEnd(const std::string& value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void SinglyLinkedList::printList() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

void SinglyLinkedList::fillFromTree(BNode* root) {
    clear(); // limpa a lista antes de preencher novamente
    fillFromTreeHelper(root);
}

void SinglyLinkedList::fillFromTreeHelper(BNode* root) {
    if (!root) return;

    fillFromTreeHelper(root->esq);          // Visita esquerda
    if (!root->data.empty())                // Adiciona dados válidos
        insertAtEnd(root->data);           
    fillFromTreeHelper(root->dir);          // Visita direita
}
