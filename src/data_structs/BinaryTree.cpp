#include "BinaryTree.hpp"
#include <iostream>

BinaryTree::BinaryTree() : root(nullptr) {
    carregarHistoria(); // <- carrega todos os caminhos da história
}

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

void BinaryTree::insertPath(const std::string& path, const std::string& text) {
    insertPathRecursive(root, path, 0, text);
}

void BinaryTree::insertPathRecursive(BNode*& node, const std::string& path, size_t index, const std::string& text) {
    if (!node)
        node = new BNode("");

    if (index == path.length()) {
        node->data = text;
        return;
    }

    if (path[index] == '1') {
        insertPathRecursive(node->esq, path, index + 1, text);
    } else if (path[index] == '2') {
        insertPathRecursive(node->dir, path, index + 1, text);
    }
}

std::string BinaryTree::traverse() {
    pathAtual.clear(); // garante que está limpo
    return traverseRecursive(root);
}

std::string BinaryTree::traverseRecursive(BNode* node) {
    if (!node) return "";

    std::cout << "\n" << node->data << "\n";

    if (node->esq || node->dir) {
        int escolha;
        std::cout << "\nEscolha (1 ou 2): ";
        std::cin >> escolha;

        if (escolha == 1) {
            pathAtual += '1';
            return "1" + traverseRecursive(node->esq);
        } else if (escolha == 2) {
            pathAtual += '2';
            return "2" + traverseRecursive(node->dir);
        } else {
            std::cout << "Escolha inválida!\n";
            return traverseRecursive(node); // repete a pergunta
        }
    } else {
        return ""; // nó final
    }
}

void BinaryTree::carregarHistoria() {
    insertPath("", "Sua missão: recuperar Gungnir antes que ela caia nas mãos dos Jotuns. Digite 1 para começar!");

    insertPath("1", "Você está na vila de Midgard. Um corvo negro pousa à sua frente, deixando cair uma runa brilhante.\n1 - Seguir o corvo\n2 - Ir para o mar");
    insertPath("11", "Você encontra um elfo ferido com uma flecha envenenada.\n1 - Ajudar\n2 - Ignorar");
    insertPath("111", "O elfo te recompensa com uma runa sagrada. Você chega à Serpente de Niflheim.\n1 - Enfrentar\n2 - Desviar");
    insertPath("1111", "Você vence a serpente, mas perde sua espada.\n1 - Entrar desarmado na caverna\n2 - Recusar e voltar");
    insertPath("11111", "Você chegou à caverna da lança.\n1 - Usar a runa\n2 - Usar força bruta");
    insertPath("111111", "Você ativou a passagem e encontrou Gungnir! Final verdadeiro!");
    insertPath("111112", "Você acionou uma armadilha e morreu. Final ruim.");
    insertPath("1112", "Você está no pântano amaldiçoado.\n1 - Atravessar\n2 - Esperar");
    insertPath("11121", "Os espíritos oferecem ajuda.\n1 - Aceitar ajuda\n2 - Ignorar");
    insertPath("111211", "Você alcança a lança, mas perde a voz. Final neutro.");
    insertPath("111212", "Você fica preso em uma ilusão eterna. Final ruim.");
    insertPath("11122", "Você enlouqueceu com os sussurros. Final ruim.");

    insertPath("112", "Você foi capturado por trolls.\n1 - Lutar\n2 - Negociar");
    insertPath("1121", "Você venceu ferido.\n1 - Continuar\n2 - Voltar");
    insertPath("11211", "Você caiu ferido e morreu no caminho. Final ruim.");
    insertPath("11212", "Você desistiu. Final ruim.");
    insertPath("1122", "Os trolls pedem a runa.\n1 - Entregar\n2 - Tentar enganar");
    insertPath("11221", "Você vive escondido, mas sem glória. Final neutro.");
    insertPath("11222", "Você foi descoberto e devorado. Final ruim.");

    insertPath("12", "Você foi para o mar direto. (Inexistente na história?)"); // talvez inútil

    insertPath("21", "Você naufragou. As valquírias aparecem.\n1 - Aceitar ajuda\n2 - Fugir");
    insertPath("211", "Odin propõe um enigma.\n1 - Falar a verdade\n2 - Mentir");
    insertPath("2111", "Odin o abençoa. Você encontra Gungnir. Final verdadeiro!");
    insertPath("2112", "Odin o amaldiçoa. Final ruim.");
    insertPath("212", "Você caiu de um penhasco e morreu. Final ruim.");

    insertPath("22", "Odin te amaldiçoa.\n1 - Ir ao templo\n2 - Ignorar");
    insertPath("221", "O portal rúnico se abre.\n1 - Entrar\n2 - Hesitar");
    insertPath("2211", "Você chegou à lança e completou a missão. Final verdadeiro!");
    insertPath("2212", "Você se perdeu na floresta. Final ruim.");
    insertPath("222", "Uma doença mágica te consome. Final ruim.");
}
