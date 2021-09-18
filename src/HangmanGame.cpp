#include "../include/HangmanGame.h"

HangmanGame::HangmanGame(string wordsFilePath) {
    this->_lives = 6;
    this->_score = 0;
    this->_status = RUNNING;
    
    
    ifstream wordsFile(wordsFilePath);
    string word_string;
    
    while (getline(wordsFile, word_string)) {
        Word word = Word(word_string);
        this->_words.push_back(word);
    }
        
};

Word* HangmanGame::currentWord() {
    return &(this->_words[this->_currentWordIndex]);
}

void HangmanGame::pickWord() {
    cout << "==========================================================" << endl;
    cout << "================ NOVA PALAVRA SELECIONADA ================" << endl;
    srand(time(NULL));
    this->_currentWordIndex = rand() % this->_words.size();
    while(find(this->_playedWords.begin(), this->_playedWords.end(),   this->_currentWordIndex) != this->_playedWords.end())
        this->_currentWordIndex = rand() % this->_words.size();

    this->_playedWords.push_back(this->_currentWordIndex);
}

void HangmanGame::guessLetter(char letter){
    bool found = false;
    int i = 0;

    for (auto c : this->currentWord()->getWord()) {
        if (tolower(c.first) == tolower(letter)) {
            found = true;
            if (c.second == false) {
                this->_score++;
                this->currentWord()->setLetterVisible(i, true);
            }
        }
        i++;
    }
    if(!found)
    {
        this->_lives--;
        this->_score--;
    }
    this->_guessedLetters.push_back(toupper(letter));
}

bool HangmanGame::guessedAlready(char letter){
    if(find(this->_guessedLetters.begin(), this->_guessedLetters.end(), toupper(letter)) != this->_guessedLetters.end()){
        cout << "Você já chutou essa letra, que tal tentar outra?" << endl;
        return true;
    }
    return false;
}

void HangmanGame::cleanGuessedLetters(){
    this->_guessedLetters.clear();
}

void HangmanGame::verifyState() {
    if (this->currentWord()->wordCompleted()) {
        this->_score+=2;
        if (this->_lives == 6)
            this->_score+=1;
        this->_status = WON;
        this->addWordFound(this->currentWord()->getFullWord());
    }
    else {
        if (this->_lives == 0)
            this->_status = LOST;
    }
}

void HangmanGame::printGame() {
    cout << "==========================================================" << endl;
    cout << "Pontuação: " << this->_score << endl;
    switch (this->_lives) {
        
        case 6:
            cout << "+---+ \n"
                "|   |  \n"
                "|      \n"
                "|    \n"
                "|    \n"
                "|         \n" << endl;
            break;
        case 5:
            cout << "+---+ \n"
               "|   |  \n"
               "|   O  \n"
               "|      \n"
               "|      \n"
               "|         \n" << endl;
            break;
        case 4:
            cout << "+---+ \n"
               "|   |  \n"
               "|   O  \n"
               "|   |\n"
               "|    \n"
               "|         \n" << endl;
            break;
        case 3:
            cout << "+---+ \n"
               "|   |  \n"
               "|   O  \n"
               "|  /|\n"
               "|   \n"
               "|         \n" << endl;
            break;
        case 2:
            cout << "+---+ \n"
               "|   |  \n"
               "|   O  \n"
               "|  /|\\\n"
               "|    \n"
               "|         \n" << endl;
            break;
        case 1:
            cout << "+---+ \n"
               "|   |  \n"
               "|   O  \n"
               "|  /|\\\n"
               "|    \\\n"
               "|         \n" << endl;
            break;
        case 0:
            cout << "+---+ \n"
               "|   |  \n"
               "|   😵  \n"
               "|  /|\\\n"
               "|  / \\\n"
               "|         \n" << endl;
            break;
        
        default:
            break;
        
    }
    cout << this->getGuessedLetters() << endl << endl;
    cout << this->currentWord()->getVisibleWord() << endl;
    // cout << this->currentWord()->getFullWord() << endl; // Just for debugging purposes

}

void HangmanGame::askForContinue() {
    int keepPlaying;
    char answer;
    cout << "PARABÉNS VOCÊ GANHOU!!!" << endl;            
    if(this->_playedWords.size() == this->_words.size()){
        cout << "WOOW, VOCÊ JÁ JOGOU TODAS AS PALAVRAS!!!" << endl;
        this->_status = NO_WORDS;
    }
    else{
        while (tolower(answer) != 's' && tolower(answer) != 'n') {
        {
            cout << "Deseja continuar jogando? (s/n) " ;
            cin >> answer;
        }
        
        keepPlaying = tolower(answer) == 's';
        if(keepPlaying){
            this->_status = RUNNING;
            this->_lives = 6;
            this->cleanGuessedLetters();
        }
        else
            this->_status = WON;
        }
    }
}


void HangmanGame::gameOver() {
    cout << "Que pena, suas chances acabaram!" << endl;
}


GameState HangmanGame::getStatus() {
    return this->_status;
}

void HangmanGame::setPlayerName(std::string name){
    this->_player = name;
}
void HangmanGame::addWordFound(std::string word){
    this->_wordsFound.push_back(word);
}

void HangmanGame::appendScoreToFile() {
    ofstream scoreFile;
    scoreFile.open("scores.txt", ios::app);
    scoreFile << this->_player << ": " << this->_score << " pontos" << endl;
    scoreFile << "( ";
    for(auto word : this->_wordsFound){
        scoreFile << word << " ";
    }
    scoreFile << ")" << endl;
    scoreFile.close();
}

string HangmanGame::getGuessedLetters(){
    string guessedLetters = "";
    for(auto letter : this->_guessedLetters){
        guessedLetters += letter;
        guessedLetters += " ";
    }
    return guessedLetters;
}