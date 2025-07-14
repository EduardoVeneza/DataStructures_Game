#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>

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