#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int pos, int value);

    bool removeByValue(int value);
    bool removeByPosition(int pos);

    void sort();
    bool search(int value);
    int getSize() const;
    void display();
};

#endif // SINGLY_LINKED_LIST_HPP
