#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <string>
#include <iostream>
#include "BinaryTree.hpp"  // Para ter acesso a BNode

struct Node {
    std::string data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

    void fillFromTreeHelper(BNode* root); // função auxiliar recursiva

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insertAtEnd(const std::string& value);
    void printList() const;
    void clear();

    void fillFromTree(BNode* root); // Função principal
};

#endif // SINGLY_LINKED_LIST_HPP
