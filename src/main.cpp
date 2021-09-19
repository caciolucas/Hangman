
#include <iostream>
#include "../include/HangmanGame.h"
int main(int argc, char const *argv[])
{
    if (argc < 2){
        std::cout << "Por favor, informe o arquivo com as palavras" << std::endl;
        return 1;
    }

    int opcao;
    std::cout << "Selecione uma opção:" << std::endl;
    std::cout << "[0] - Sair" << std::endl;
    std::cout << "[1] - Iniciar um jogo" << std::endl;
    std::cout << "[2] - Visualizar as pontuações" << std::endl << std::endl;
    std::cout << "Opção: ";
    std::cin >> opcao;
    
    if (opcao == 0 ){
        std::cout << "Até mais!" << std::endl;
        return 0;
    }
    else if (opcao == 1){
        HangmanGame game(argv[1]);
        char letter_guess;
        game.pickWord();
        while(game.getStatus() == RUNNING){
            game.clearScreen();
            game.printGame();            
            
            do{
                cout << "Digite uma letra: ";
                cin >> letter_guess;
            } while (game.guessedAlready(letter_guess));
            
            game.guessLetter(letter_guess);
            game.verifyState();
            GameState current_status = game.getStatus();


            if (current_status == WON){
                game.clearScreen();
                game.printGame();
                game.askForContinue();
                if (game.getStatus() == RUNNING)
                    game.pickWord();
                
            }
            else if (current_status == LOST){
                game.clearScreen();
                game.printGame();            
                game.gameOver();
            }
        }
        string player_name;
        cout << "Qual seu nome para salvar sua pontuação?" << endl;
        cin >> player_name;
        game.setPlayerName(player_name);
        game.appendScoreToFile();
    }
    else if (opcao == 2){
        HangmanGame game(argv[1]);
        game.clearScreen();
        game.printScoreFile();
    }
    

    return 0;
}
