#include "Game.hpp"

Game::Game()
{
    this->isRunning = true;
}

void Game::run()
{
    while (isRunning)
    {
        system("clear");
        std::string input;
        show_menu();
        std::cin >> input;

        // Tenta converter para inteiro
        try
        {
            this->userOption = std::stoi(input);
        }
        catch (std::invalid_argument &)
        {
            std::cout << "Entrada inválida! Digite um número de 1 a 5.\n";
            continue;
        }

        // Agora você pode verificar se está no intervalo permitido
        if (!verifyUserInput(this->userOption))
        {
            std::cout << "Opção fora do intervalo! Digite um número de 1 a 5.\n";
            continue;
        }

        switch (this->userOption)
        {
        case 1: // OPÇÃO 1
        {
            this->showHistory();
            break;
        }
        case 2: // OPÇÃO 2
        {
            this->rules();
            break;
        }
        case 3: // OPÇÃO 3
        {
            this->play();
            break;
        }
        case 4: // OPÇÃO 4
        {
            this->verifyScore();
            break;
        }

        case 5: // OPÇÃO 5
        {
            this->isRunning = false;
            break;
        }

        default:
            break;
        }
    }
}

bool Game::verifyUserInput(const int &option) const
{
    if (option > 5 || option < 1)
    {
        return false;
    }
    return true;
}

void Game::play() // Implementar
{
    std::string nome;
    std::cout << "Digite o nome do(a) jogador(a): ";
    std::cin >> nome;

    std::cin.ignore(); // limpa buffer
    system("clear");
    
    std::cout << "A Jornada de " << nome << ", o Escolhido de Odin\n\n";
    
    std::string path = this->jogo.traverse(); // Passa pelo jogo
    std::cout << path << std::endl;
    Stats stats = {nome, 0, 0, 0};
    this->StatsList.insert(stats);
    pause();
}

void Game::showHistory()
{
    system("clear");
    std::cout << "Na era dos mitos, quando os nove reinos estavam conectados pelos galhos de Yggdrasil,\n";
    std::cout << "o equilíbrio do mundo era mantido por artefatos sagrados dos deuses. Um deles, a Lança de Gungnir,\n";
    std::cout << "foi roubada durante o Ragnarök e lançada nas profundezas da terra. Agora, séculos depois,\n";
    std::cout << "Odin envia um de seus corvos à terra dos homens. O escolhido é você, um jovem guerreiro(a) de Midgard,\n";
    std::cout << "descendente dos antigos völvas (xamãs). Sua missão: recuperar Gungnir antes que ela caia nas mãos dos\n";
    std::cout << "Jotuns (gigantes do gelo) e a guerra recomece.\n\n";
    this->pause();
}

void Game::verifyScore()
{
    system("clear");
    this->StatsList.printList();
    this->pause();
}

void Game::rules()
{
    system("clear");
    std::cout << "Regras do Jogo:\n";
    std::cout << "1. Você será apresentado(a) a uma história com situações de escolha binária (duas opções).\n";
    std::cout << "2. Cada escolha influencia o rumo da narrativa e pode levar a diferentes finais.\n";
    std::cout << "3. Existem finais bons, ruins e neutros, dependendo das decisões tomadas ao longo do jogo.\n";
    std::cout << "4. Leia atentamente cada situação antes de escolher, pois algumas decisões podem ter consequências inesperadas.\n";
    std::cout << "5. Para escolher, digite o número correspondente à opção desejada e pressione Enter.\n";
    std::cout << "6. Boa sorte! Suas escolhas definirão o destino do personagem.\n\n";
    this->pause();
}

void Game::pause()
{
    std::cout << "Pressione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

void Game::show_menu()
{
    std::cout << "\t1 - Conhecer a História do Jogo\n";
    std::cout << "\t2 - Regras do Jogo\n";
    std::cout << "\t3 - Jogar\n";
    std::cout << "\t4 - Verificar o Score do jogo\n";
    std::cout << "\t5 - Sair.\n\n";
    std::cout << "\tOpção: ";
}
