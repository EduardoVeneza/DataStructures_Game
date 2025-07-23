#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "data_structs/BinaryTree.hpp"
#include "data_structs/DoublyLinkedList.hpp"
#include "data_structs/SinglyLinkedList.hpp"
#include "data_structs/Stats.hpp"

class Game
{
public:
    Game();
    void run();

private:
    bool verifyUserInput(const int &option) const;

    void play();

    void showHistory();

    void verifyScore();

    void menuTecnico();

    void rules();

    void pause();

    void updateStats(const int &path, const std::string &nome);

    void show_menu();

    DoublyLinkedList StatsList;
    BinaryTree jogo;
    SinglyLinkedList jogo_em_lista;
    int userOption;
    bool isRunning;
};

#endif