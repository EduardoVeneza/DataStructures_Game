#include "DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::clear() {
    DNode* current = head;
    while (current) {
        DNode* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}

void DoublyLinkedList::insert(const Stats& value) {
    insertOrdered(value);
}

void DoublyLinkedList::insertOrdered(const Stats& value) {
    DNode* newNode = new DNode{value, nullptr, nullptr};

    if (!head || value.jogosGanhos > head->data.jogosGanhos) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
    } else {
        DNode* current = head;
        while (current->next && current->next->data.jogosGanhos >= value.jogosGanhos) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next) current->next->prev = newNode;
        newNode->prev = current;
        current->next = newNode;
    }
    size++;
}

void DoublyLinkedList::printList() const {
    DNode* current = head;
    while (current) {
        const Stats& s = current->data;
        std::cout << "Nome: " << s.name
                  << ", Jogos: " << s.jogosTotais
                  << ", Vitórias: " << s.jogosGanhos
                  << ", Derrotas: " << s.jogosPerdidos << std::endl;
        current = current->next;
    }
}

DNode* DoublyLinkedList::searchByName(const std::string& name) const {
    DNode* current = head;
    while (current) {
        if (current->data.name == name)
            return current;
        current = current->next;
    }
    return nullptr;
}

bool DoublyLinkedList::removeByName(const std::string& name) {
    DNode* target = searchByName(name);
    if (!target) return false;

    if (target->prev) target->prev->next = target->next;
    else head = target->next;

    if (target->next) target->next->prev = target->prev;

    delete target;
    size--;
    return true;
}
