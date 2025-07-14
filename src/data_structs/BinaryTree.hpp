#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <iostream>

struct Node
{
    int data;
    Node * esq, * dir;
};

class BinaryTree
{
    public:
        Node * raiz;
        // Função que insere em uma árvore (Recursiva):
        Node * insert(Node * raiz, int data);

        // Função de busca em uma árvore (Recursiva):
        Node * search(Node * raiz, int data);

        // Função para remover
        Node * remover(Node * raiz, int value);

        Node * remover_folha(Node * raiz);

        Node * iguala_folhas(Node * raiz);

        // Função que calcula e retorna a altura de uma árvore (Recursiva):
        int getAltura(Node * raiz);

        // Funções que imprimem a árvore (Recursivas):
        void print_preOrdem(Node * raiz);
        void print_emOrdem(Node * raiz);
        void print_posOrdem(Node * raiz);

        // Incrementa em count a quantidade de nós
        void getQTD(Node * raiz, int * count);

        // Retorna a quantidade de nós
        int quantidade_nos(Node * raiz);

        // Retorna a quantidade de folhas
        int quantidade_folhas(Node * raiz);
};

#endif