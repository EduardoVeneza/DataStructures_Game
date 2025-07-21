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
    system("clear");

    std::string nome;
    std::cout << "Digite o nome do(a) jogador(a): ";
    std::cin >> nome;

    std::cin.ignore(); // Limpa o buffer
    system("clear");

    std::cout << "A Jornada de " << nome << ", o Escolhido de Odin\n\n";
    std::cout << "Na era dos mitos, os nove reinos estavam conectados pelos galhos de Yggdrasil,
    o equilíbrio do mundo era mantido por artefatos sagrados dos deuses. 
    Um deles, a Lança de Gungnir, foi roubada durante o Ragnarök e lançada nas profundezas da terra.\n";
    std::cout << "Sua missão: recuperar Gungnir antes que ela caia nas mãos dos Jotuns (gigantes do gelo) e a guerra recomece.\n\n";
    pause();

    int escolha;

    // NÍVEL 1
    system("clear");
    std::cout << "Você está na vila de Midgard. Um corvo negro pousa à sua frente, deixando cair uma runa brilhante.\n";
    std::cout << "1 - Seguir o corvo pela floresta sagrada\n";
    std::cout << "2 - Ignorar o presságio e ir para o mar\n";
    std::cout << "Escolha: ";
    std::cin >> escolha;

    if (escolha == 1)
    {
        // NÍVEL 2 - elfo
        system("clear");
        std::cout << "Você encontra um elfo ferido com uma flecha envenenada.\n";
        std::cout << "1 - Ajudar\n";
        std::cout << "2 - Ignorar\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        bool temRuna = false;
        if (escolha == 1)
            temRuna = true;

        // NÍVEL 3
        system("clear");
        if (temRuna)
        {
            std::cout << "O elfo te recompensa com uma runa sagrada e te alerta sobre a Serpente de Niflheim.\n";
            std::cout << "1 - Enfrentar a serpente\n";
            std::cout << "2 - Desviar para o pântano\n";
            std::cout << "Escolha: ";
            std::cin >> escolha;

            if (escolha == 1)
            {
                if (temRuna)
                {
                    // Vence a serpente
                    std::cout << "Você vence a serpente, mas perde sua espada.\n";
                    std::cout << "1 - Entrar desarmado na caverna\n";
                    std::cout << "2 - Recusar e voltar\n";
                    std::cout << "Escolha: ";
                    std::cin >> escolha;

                    if (escolha == 1)
                    {
                        // Última escolha
                        system("clear");
                        std::cout << "Você chegou à caverna da lança.\n";
                        std::cout << "1 - Usar a runa do elfo\n";
                        std::cout << "2 - Usar força bruta\n";
                        std::cout << "Escolha: ";
                        std::cin >> escolha;

                        if (escolha == 1)
                        {
                            std::cout << "\n Você ativou a passagem e encontrou Gungnir! Final verdadeiro!\n";
                        }
                        else
                        {
                            std::cout << "\n Você acionou uma armadilha e morreu. Final ruim.\n";
                        }
                    }
                    else
                    {
                        std::cout << "\n Você desistiu da jornada. Final ruim.\n";
                    }
                }
            }
            else
            {
                // Caminho do pântano
                std::cout << "Você está no pântano amaldiçoado.\n";
                std::cout << "1 - Atravessar\n";
                std::cout << "2 - Esperar\n";
                std::cout << "Escolha: ";
                std::cin >> escolha;

                if (escolha == 1)
                {
                    // Última escolha no pântano
                    std::cout << "Os espíritos oferecem ajuda.\n";
                    std::cout << "1 - Aceitar ajuda\n";
                    std::cout << "2 - Ignorar os espíritos\n";
                    std::cout << "Escolha: ";
                    std::cin >> escolha;

                    if (escolha == 1)
                        std::cout << "\n Você alcança a lança, mas perde a voz. Final neutro.\n";
                    else
                        std::cout << "\n Você fica preso em uma ilusão eterna. Final ruim.\n";
                }
                else
                {
                    std::cout << "\n Você enlouqueceu com os sussurros. Final ruim.\n";
                }
            }
        }
        else
        {
            // Ignorou o elfo => trolls
            std::cout << "Você foi capturado por trolls.\n";
            std::cout << "1 - Lutar\n";
            std::cout << "2 - Negociar\n";
            std::cout << "Escolha: ";
            std::cin >> escolha;

            if (escolha == 1)
            {
                std::cout << "Você venceu ferido. Deseja continuar ou voltar?\n";
                std::cout << "1 - Continuar\n";
                std::cout << "2 - Voltar\n";
                std::cout << "Escolha: ";
                std::cin >> escolha;

                if (escolha == 1)
                    std::cout << "\n Você caiu ferido e morreu no caminho. Final ruim.\n";
                else
                    std::cout << "\n Você desistiu. Final ruim.\n";
            }
            else
            {
                std::cout << "Os trolls pedem a runa. Você...\n";
                std::cout << "1 - Entrega\n";
                std::cout << "2 - Tenta enganar\n";
                std::cout << "Escolha: ";
                std::cin >> escolha;

                if (escolha == 1)
                    std::cout << "\n Você vive escondido, mas sem glória. Final neutro.\n";
                else
                    std::cout << "\n Você foi descoberto e devorado. Final ruim.\n";
            }
        }
    }
    else
    {
        // Foi ao mar
        std::cout << "Uma tempestade se forma.\n";
        std::cout << "1 - Enfrentar o mar\n";
        std::cout << "2 - Voltar à vila\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        if (escolha == 1)
        {
            std::cout << "Você naufragou. As valquírias aparecem.\n";
            std::cout << "1 - Aceitar ajuda\n";
            std::cout << "2 - Fugir\n";
            std::cout << "Escolha: ";
            std::cin >> escolha;

            if (escolha == 1)
            {
                std::cout << "Odin propõe um enigma. Você...\n";
                std::cout << "1 - Fala a verdade\n";
                std::cout << "2 - Mente\n";
                std::cout << "Escolha: ";
                std::cin >> escolha;

                if (escolha == 1)
                    std::cout << "\n Odin o abençoa. Você encontra Gungnir. Final verdadeiro!\n";
                else
                    std::cout << "\n Odin o amaldiçoa. Final ruim.\n";
            }
            else
            {
                std::cout << "\n Você caiu de um penhasco e morreu. Final ruim.\n";
            }
        }
        else
        {
            std::cout << "Odin te amaldiçoa.\n";
            std::cout << "1 - Vai ao templo\n";
            std::cout << "2 - Ignora\n";
            std::cout << "Escolha: ";
            std::cin >> escolha;

            if (escolha == 1)
            {
                std::cout << "O portal rúnico se abre.\n";
                std::cout << "1 - Entra\n";
                std::cout << "2 - Hesita\n";
                std::cout << "Escolha: ";
                std::cin >> escolha;

                if (escolha == 1)
                    std::cout << "\n Você chegou à lança e completou a missão. Final verdadeiro!\n";
                else
                    std::cout << "\n Você se perdeu na floresta. Final ruim.\n";
            }
            else
            {
                std::cout << "\n Uma doença mágica te consome. Final ruim.\n";
            }
        }
    }

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
    std::cout << "Score Here...\n\n";
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
