#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <string>

struct BNode {
    std::string data;
    BNode* esq;
    BNode* dir;
};

class BinaryTree {
private:
    BNode* root;

    void insert(BNode*& node, const std::string& value);
    void printInOrder(BNode* node);
    void destroy(BNode* node);

public:
    BinaryTree();
    ~BinaryTree();

    void insert(const std::string& value);
    void printInOrder();
};

#endif // BINARY_TREE_HPP
