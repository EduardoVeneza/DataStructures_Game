#include "BinaryTree.hpp"
#include <iostream>

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    destroy(root);
}

void BinaryTree::destroy(BNode* node) {
    if (node) {
        destroy(node->esq);
        destroy(node->dir);
        delete node;
    }
}

void BinaryTree::insert(const std::string& value) {
    insert(root, value);
}

void BinaryTree::insert(BNode*& node, const std::string& value) {
    if (node == nullptr) {
        node = new BNode{value, nullptr, nullptr};
    } else if (value < node->data) {
        insert(node->esq, value);
    } else {
        insert(node->dir, value);
    }
}

void BinaryTree::printInOrder() {
    printInOrder(root);
    std::cout << std::endl;
}

void BinaryTree::printInOrder(BNode* node) {
    if (node) {
        printInOrder(node->esq);
        std::cout << node->data << " ";
        printInOrder(node->dir);
    }
}
