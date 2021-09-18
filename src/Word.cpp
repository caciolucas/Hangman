#include "../include/Word.h"

Word::Word(string word){
    pair<char, int> letter;
    for(auto c : word){
        letter.first = c;
        letter.second = false;

        this->_letters.push_back(letter);
    }
    
}

vector<pair<char, bool>> Word::getWord(){
    return this->_letters;
}
string Word::getFullWord(){
    string word;
    for(auto letter : this->_letters)
        word += letter.first;
    return word;
}

string Word::getVisibleWord(){
    string word;
    for(auto letter : this->_letters){
        word += letter.second ? letter.first : '_';
        word += ' ';
    }
    return word;
}

void Word::setLetterVisible(int index, bool visible){
    this->_letters[index].second = visible;
}

bool Word::wordCompleted(){
    for(auto letter : this->_letters)
        if(!letter.second)
            return false;
    return true;
}