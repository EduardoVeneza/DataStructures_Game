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
    insertPath("", "Você está na vila de Midgard. Um corvo negro pousa à sua frente, deixando cair uma runa brilhante.\n1 - Seguir o corvo pela floresta sagrada\n2 - Ignora o presságio e vai para o mar");
    insertPath("1", "Você segue o corvo pela floresta e encontra um elfo ferido com uma flecha envenenada.\n1 - Ajudar\n2 - Ignorar");
    insertPath("2", "Você foi em direção ao mar, o céu escurece, forma-se uma tempestade...\n1 - Enfrenta o mar\n2 - Volta à vila");

    // Elfo
    insertPath("11","O elfo se vê agradecido ele revela que planejava lhe roubar, mas por sua bondade, acaba lhe poupando... De repente a serpente de nilfheim aparece!. \n1- Enfrenta a serpente\n2 - Corre");
    insertPath("12","Você ignora o elfo, ele se revela um impostor que trabalhava para os trolls bandidos das montanhas! Você foi capturado(a)\n1 - Luta\n2 - Negocia");
    insertPath("111","Você, ao enfrentar a serpente, mostra coragem a odin, que lhe concede força para derrota-la, porém, perde sua espada no processo. Você encontra uma caverna\n1 - Entra desarmado\n2 - Recua"); 
    insertPath("112","Você corre loucamente da serpente gigante, e acaba chegando em um pântano suspeito... Lá, você ouve sussuros!\n1 - Segue\n2 - Aguarda"); 
    
    insertPath("121", "Você consegue lutar e fugir, mas sai gravemente ferido!\n1 - Continua\n2 - Volta");
    insertPath("122", "[FINAL RUIM] Eles tomam a runa do corvo, você fica indefeso. E aos poucos morre de frio");

    insertPath("1211","[FINAL RUIM] Prossegue em estado crítico, você encontra uma caverna e assim, vive escondido sem glória");
    insertPath("1212","[FINAL RUIM] Sem esperança, você volta triste e derrotado para a vila!");

    insertPath("1121", "Os sussuros eram espíritos do bem! Eles te oferecem ajuda\n1 - Aceita ajuda dos espíritos\n2 - Ignora os espíritos");
    insertPath("1122", "[FINAL RUIM] Você enlouquece com os sussuros e vive agora vagando sozinho no pântano.");

    insertPath("11211", "[FINAL RUIM] Chega à caverna da lança, mas os espíritos levaram sua voz como cobrança, e agora, você não consegue responder os enigmas de odin");
    insertPath("11212", "[FINAL RUIM] Fica preso em ilusão eterna");

    insertPath("1111","Você por sorte, entrou na lendária caverna da lança, lá dentro observa um encaixe perfeito para a runa que o corvo deixou cair...\n1 - Usa a runa\n2 - Usa a força bruta");
    insertPath("1112", "[FINAL RUIM] Você se vê desarmado e sem esperanças, decide então voltar para casa e vendar a runa.");
    
    insertPath("11111", "[FINAL BOM] Você segura a lança e sente um poder imensurável! Você agora é o novo guardião de asgard!");
    insertPath("11112", "[FINAL RUIM] Você ativa as armadilhas, e morre no local, agora você será história para o próximo escolhido.");

    // Mar
    insertPath("21","Seu barco não aguentou as ondas, e naufraga! Mas você escuta um sussuro suspeito no fundo do oceâno...\n1 - Seguir sussuro\n2 - Lutar contra as ondas");
    insertPath("22","Era um teste... Odin lhe julga covarde e você é amaldiçoado! Mas... você vê algo brilhante no horizonte\n1 - Seguir Luz\n2 - Voltar para a vila em busca da cura");

    insertPath("221", "Odin envia um portal rúnico para asgard, e lá ele te propôe um enigma!\n1 - Aceita\n2 - Recusa");
    insertPath("222", "[FINAL RUIM] Você é consumido pela doença e morre.");

    insertPath("2211", "Você então segue para a última prova, o enigma é o seguinte: \nEnigma: Faço parte de tudo e estou no final do espaço e do tempo. Quem sou eu?\n1 - Você: A letra O.\n2 - Você: O senhor Odin! Todo poderoso!");
    insertPath("2212", "[FINAL RUIM] Odin lhe julga estupido, e decide lhe banir para o reino dos mortos!");

    insertPath("22111", "[FINAL BOM] Odin: HaHaHa, você está certo, lhe concedo, o titulo de novo guardião de Asgard!");
    insertPath("22112", "[FINAL RUIM] Odin: Você é apenas um bajulador barato! Volte a midgard e nunca mais volte aqui!");

    insertPath("211","Você é resgatado pelas valquírias! Elas estão te levando para um lugar esquisito...\n1 - Aceita ajuda\n2 - Foge");
    insertPath("212","[FINAL RUIM] -> Você morreu afogado nos mares de midgard..."); // Final Ruim

    insertPath("2111", "Você é levado aos salões de Asgard. Odin propõe um enigma! \n1 - Aceita\n2 - Recusa");
    insertPath("2112", "Cai em um penhasco e acorda em Helheim Lá você encontra Hela! Ela te propõe um pacto! \n1 - Sacrifica memória\n2 - Recusa");

    insertPath("21121", "[FINAL RUIM] Escapa, mas nunca mais lembra quem é");
    insertPath("21122", "[FINAL RUIM] Você fica preso em Helheim eternamente");

    insertPath("21111", "Você então segue para a última prova, o enigma é o seguinte: \nEnigma: Faço parte de tudo e estou no final do espaço e do tempo. Quem sou eu?\n1 - Você: A letra O.\n2 - Você: O senhor Odin! Todo poderoso!");
    insertPath("21112", "[FINAL RUIM] Odin lhe julga estupido, e decide lhe banir para o reino dos mortos!");

    insertPath("211111", "[FINAL BOM] Odin: HaHaHa, você está certo, lhe concedo, o titulo de novo guardião de Asgard!");
    insertPath("211112", "[FINAL RUIM] Odin: Você é apenas um bajulador barato! Volte a midgard e nunca mais volte aqui!");
}
