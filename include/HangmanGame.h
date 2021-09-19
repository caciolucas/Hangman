#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Word.h"

using namespace std;

enum GameState
{
    RUNNING,
    WON,
    LOST,
    NO_WORDS,
};

class HangmanGame {
    public:
        HangmanGame(std::string fileName);

        void pickWord();
        void printGame();
        
        bool guessedAlready(char letter);
        void guessLetter(char letter);

        void verifyState();
        void askForContinue();
        void gameOver();

        Word* currentWord();

        GameState getStatus();

        void setPlayerName(std::string name);
        void addWordFound(std::string word);

        void appendScoreToFile();
        void printScoreFile();

        string getGuessedLetters();
        void cleanGuessedLetters();

    private:
        int _lives;
        int _score;
        std::vector<Word> _words;
        int _currentWordIndex;
        std::vector<int> _playedWords;
        GameState _status;
        vector<string> _wordsFound;
        string _player;
        vector<char> _guessedLetters;
};

#endif