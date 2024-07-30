// Defines the maximum number of tries a player has.   
const MAX_TRIES = 6; // Going to use an int but I could hear my college professors saying that "MAX_TRIES" should be a const.

// An array of phrases for the game
const char *phrases[] = {
    "hello world",
    "programming is fun",
    "roboblockly is amazing",
    "hangman game",
    "c language", 
    "c world",
};

// Print the current state of the word being guessed
void printWord(char *word, int length) {
    int i; 
    for (i = 0; i < length; i++) {
        if (word[i] == '\0') {
            printf(" ");
        } else {
            printf("%c", word[i]);
        }
    }
    printf("\n");
}

// Update the guessed word with the guessed letter
void updateWord(char *word, const char *phrase, char guess) {
    int i; 
    for (i = 0; phrase[i] != '\0'; i++) {
    //If guess letter is correct update current state of word
        if (phrase[i] == guess) {
            word[i] = guess;
        }
    }
}

// Function to check if the whole word has been guessed
int isWordGuessed(char *word, int length) {
    int i; 
    for (i = 0; i < length; i++) {
        if (word[i] == '_') {
            return 0;
        }
    }
    return 1;
}

// Declarations (Thi
int numPhrases = sizeof(phrases) / sizeof(phrases[0]);
int randomIndex = randint(0, numPhrases);
const char *phrase = phrases[randomIndex];
int length = strlen(phrase);
char word[length + 1];
int remainingTries = MAX_TRIES;
char guessedChars[26];
int guessedCount = 0;
int i; 

// Loop through the guessed word to fill with underscores or spaces
for (i = 0; i < length; i++) {
    if (phrase[i] == ' ') {
        word[i] = '\0';
    } else {
        word[i] = '_';
    }
}
word[length] = '\0';

printf("Welcome to Hangman Game!\n");

// Game loop
while (remainingTries > 0) {
    int i;
    // Print the phrase out the screen (initial word is with out letters)
    printf("Phrase: ");
    printWord(word, length);
    
    //Calculate the remaing guess count
    printf("Guesses remaining: %d\n", remainingTries);
    printf("Guessed letters: ");
    for (i = 0; i < guessedCount; i++) {
        printf("%c", guessedChars[i]);
    }
    printf("\n");

    //Prompt the use for guess
    printf("Enter your guess: ");
    char guess;
    scanf(" %c", &guess);

    int alreadyGuessed = 0;
    
    // Input validation (double guess check)
    for (i = 0; i < guessedCount; i++) {
        if (guessedChars[i] == guess) {
            alreadyGuessed = 1;
            break;
        }
    }
    if (alreadyGuessed) {
        printf("You have already guessed that letter. Try again.\n");
        continue;
    }
    
    // Store the char guessed & increment Guess Count by 1
    guessedChars[guessedCount++] = guess;

    int found = 0;
    
    //Loop througth each char of phrase to check guess
    for (i = 0; i < length; i++) {
        if (phrase[i] == guess) {
            word[i] = guess;
            found = 1;
        }
    }
    
    // Decrement from the number of tries when incorrect
    if (!found) {
        remainingTries--;
        printf("Wrong guess!\n");
    }
    
    // Congrats to winner if word is guess correctly
    if (isWordGuessed(word, length)) {
        printf("Congratulations! You guessed the phrase: %s\n", phrase);
        break;
    }

    // Word is not guessed correctly
    if (remainingTries == 0) {
        printf("You've run out of guesses. The phrase was: %s\n", phrase);
        printf("      _______\n");
        printf("     |      (_)\n");
        printf("     |      \\|/\n");
        printf("     |       |\n");
        printf("     |       |\n");
        printf("     |      / \\\n");
        printf("     |      \n");
        printf("    _|___   \n");
        printf(" _  \n");
        printf("| |    \n");
        printf("| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
        printf("| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
        printf("| | | | (_| | | | | (_| | | | | | | (_| | | | |\n");
        printf("|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n");
        printf("                    __/ |       \n");
        printf("                   |___/                   \n");
        printf(".................................by Mr. V!\n");
    }
    
}
