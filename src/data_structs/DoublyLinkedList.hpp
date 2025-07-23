#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP
#include <iostream>
#include "Stats.hpp"

struct DNode {
    Stats data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
private:
    DNode* head;
    int size;

    void insertOrdered(const Stats& value);

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert(const Stats& value);
    void printList() const;
    void clear();
    void searchByTotalGames(int jogosTotais) const;


    DNode* searchByName(const std::string& name) const;
    bool removeByName(const std::string& name);
};

#endif // DOUBLY_LINKED_LIST_HPP
