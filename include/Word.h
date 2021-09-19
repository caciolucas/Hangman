#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;
class Word{
    public:
        Word(string word);

        vector<pair<char, bool>> getWord();
        string getVisibleWord();
        string getFullWord();
        void setLetterVisible(int index, bool visible);
        
        vector<pair<char, bool>> getLetters();
        bool wordCompleted();
    private:
        vector<pair<char, bool>> _letters; 
};

#endif