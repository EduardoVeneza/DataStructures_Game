#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "data_structs/BinaryTree.hpp"
#include "data_structs/DoublyLinkedList.hpp"
#include "data_structs/SinglyLinkedList.hpp"

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

    void rules();

    void pause();

    void show_menu();

    int userOption;
    bool isRunning;
};

#endif