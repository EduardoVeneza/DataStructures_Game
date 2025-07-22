#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <string>

struct BNode {
    std::string data;
    BNode* esq;
    BNode* dir;

    BNode(const std::string& text) : data(text), esq(nullptr), dir(nullptr) {}
};

class BinaryTree {
private:
    BNode* root;

    void destroy(BNode* node);
    void insertPathRecursive(BNode*& node, const std::string& path, size_t index, const std::string& text);
    std::string traverseRecursive(BNode* node);
    std::string pathAtual;
    void carregarHistoria(); // <- método que carrega os insertPath

public:
    BinaryTree();
    ~BinaryTree();

    void insertPath(const std::string& path, const std::string& text);
    std::string traverse();
};

#endif // BINARY_TREE_HPP
