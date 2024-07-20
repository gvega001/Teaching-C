#ifndef HANGMAN_H
#define HANGMAN_H

#define MAX_TRIES 6
#define WIN_THRESHOLD 3
#define LOSE_THRESHOLD 3

extern const char* phrases[];
extern const char* hangman_stages[];

// Function prototypes
void printWord(char* word, int length);
void updateWord(char* word, const char* phrase, char guess);
int isWordGuessed(char* word, int length);
int playGame(const char* phrase);
void printHangman(int stage);
void printGuessedLetters(char* guessedChars, int guessedCount);
int isAlreadyGuessed(char guess, char* guessedChars, int guessedCount);

#endif // HANGMAN_H
