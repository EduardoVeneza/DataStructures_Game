#include "BinaryTree.hpp"


Node *BinaryTree::insert(Node *raiz, int data)
{
    if(raiz == nullptr)
    {
        // Se for o primeiro valor da arvore
        Node * aux = new Node;
        aux->data = data;
        aux->esq = nullptr;
        aux->dir = nullptr;
        return aux;
    } else {
        if (data < raiz->data){
            raiz->esq = insert(raiz->esq, data);
        } else {
            raiz->dir = insert(raiz->dir, data);
        }
        return raiz;
    }
}

Node *BinaryTree::search(Node *raiz, int data)
{
    if (raiz != nullptr)
    {
        if (data == raiz->data)
        {
            return raiz;
        } else if (data < raiz->data){
            return search(raiz->esq, data);
        } else {
            return search(raiz->dir, data);
        }
    }
    return nullptr;
}

Node *BinaryTree::remover(Node *raiz, int value)
{
    if (raiz == nullptr)
    {
        std::cout << "Valor não econtrado!\n";
        return nullptr;
    } else {
        if (raiz->data == value) // Se for o valor
        {
            if (raiz->esq == nullptr && raiz->dir == nullptr) // Se for uma folha
            {
                delete raiz;
                std::cout << "Elemento folha removido!\n";
                return nullptr;
            }
            else {
                if (raiz->esq != nullptr && raiz->dir != nullptr)
                {
                    Node * aux = raiz->esq;
                    while (aux != nullptr)
                        aux = aux->dir;
                    raiz->data = aux->data;
                    aux->data = value;
                    raiz->esq = remover(raiz->esq, value);
                    return raiz;
                }
                else {
                    Node * aux;
                    if (raiz->esq != nullptr)
                        aux = raiz->esq;
                    else 
                        aux = raiz->dir;
                    delete raiz;
                    return aux;
                }
                
            }
        } else {
            if (value < raiz->data)
            {
                raiz->esq = remover(raiz->esq, value);
            }
            else {
                raiz->dir = remover(raiz->dir, value);
            }
            return raiz;
        }
    }
}

Node *BinaryTree::remover_folha(Node *raiz)
{
    if (raiz == nullptr)
        return 0;

    if (raiz->esq == nullptr && raiz->dir == nullptr){
        delete raiz;
        return nullptr;
    }
    
    raiz->esq = remover_folha(raiz->esq);
    raiz->dir = remover_folha(raiz->dir);
    return raiz;
}

Node *BinaryTree::iguala_folhas(Node *raiz)
{
    if (raiz == nullptr)
        return 0;

    if (raiz->esq == nullptr && raiz->dir == nullptr)
        return 0;
    
    int qtd_folhas_esq = quantidade_folhas(raiz->esq);
    int qtd_folhas_dir = quantidade_folhas(raiz->dir);

    while (qtd_folhas_esq != qtd_folhas_dir)
    {
        if(qtd_folhas_esq > qtd_folhas_dir)
        {
            remover_folha(raiz->esq);
        }

        if(qtd_folhas_esq < qtd_folhas_dir)
        {
            remover_folha(raiz->dir);
        }

        qtd_folhas_esq = quantidade_folhas(raiz->esq);
        qtd_folhas_dir = quantidade_folhas(raiz->dir);
    }
}

int BinaryTree::getAltura(Node *raiz)
{
    if (raiz == nullptr)
    {
        return -1;
    } else {
        int esq = getAltura(raiz->esq);
        int dir = getAltura(raiz->dir);
        if (esq > dir)
            return esq + 1;
         else 
            return dir + 1;  
    }
}

void BinaryTree::print_preOrdem(Node * raiz) // Pré Ordem
{
    if (raiz != nullptr)
    {
        std::cout << raiz->data << "\t";
        print_preOrdem(raiz->esq);
        print_preOrdem(raiz->dir);
    }
    
}

void BinaryTree::print_emOrdem(Node *raiz)
{
    if (raiz != nullptr)
    {
        print_emOrdem(raiz->esq);
        std::cout << raiz->data << "\t";
        print_emOrdem(raiz->dir);
    }
}

void BinaryTree::print_posOrdem(Node *raiz)
{
    if (raiz != nullptr)
    {
        print_posOrdem(raiz->esq);
        print_posOrdem(raiz->dir);
        std::cout << raiz->data << "\t";
    }
}

void BinaryTree::getQTD(Node *raiz, int * count)
{
    if (raiz != nullptr)
    {
        getQTD(raiz->esq, count);
        (*count) = (*count) + 1;
        getQTD(raiz->dir, count);
    }
    
}

int BinaryTree::quantidade_nos(Node *raiz)
{
    if (raiz == nullptr)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esq) + quantidade_nos(raiz->dir);
}

int BinaryTree::quantidade_folhas(Node *raiz)
{
    if (raiz == nullptr)
        return 0;
    else if (raiz->esq == nullptr && raiz->dir == nullptr) 
        return 1;
    else 
        return quantidade_folhas(raiz->esq) + quantidade_folhas(raiz->dir);
}