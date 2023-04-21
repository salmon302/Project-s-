#include <iostream>
#include <iterator>

/**
 *         char remainingLetters[26]{
            'a','b','c',
            'd','e','f',
            'g','h','i',
            'j','k','l',
            'm','n','o',
            'p','q', 'r',
            's', 't', 'u',
            'v', 'w', 'x',
            'y', 'z'
        };
 * @return
 */
int winCondition();
void printAll(int remainingGuesses, char *correctList, char *incorrectList);

int main() {
    std::string wordPool[26] = {
                {"accumulation"},
                {"breathe"},
                { "clothes" },
                { "dwarves" },
                { "espionage" },
                { "fishhook" },
                { "galvanize" },
                { "haphazard" },
                { "icebox" },
                { "jazzy" },
                { "kayak" },
                { "lineage" },
                { "message" },
                { "need" },
                { "overall" },
                { "prescription" },
                { "quest" },
                { "rescue" },
                { "strike" },
                { "terminal" },
                { "unknown" },
                { "vaporize" },
                { "walkway" },
                { "xylophone" },
                { "zodiac" },
                { "triphthong" }
        };
    //declarations
        int letterCount,  guesses = 8;
        int correctCount = -1, incorrectCount = -1;
        std::string word, response;
        int promptSentinel = 1;
        // Providing a seed value
        srand((unsigned) time(NULL));

        std::cout << "Selecting word...\n" << std::endl;
        int randIndex = rand() % 25;
        word = wordPool[randIndex];
        std::cout <<"Word is " << word << std::endl;
        letterCount = word.length();
        char correctLetters[22];
        char incorrectLetters[26];
        char arr[26];
        std::cout << "You have '"<< guesses << "' guesses remaining\n";

        while(promptSentinel==1){
            std::cout << "\nGuess the word or a letter of the word: ";
            std::cin >> response;
            if (response==word){
                std::cout << "Word match; You win \n";
                winCondition;
                promptSentinel = 0;
            }
            else if (word.find(response) != std::string::npos){
                std::cout << "You entered '"<< response << "' and you are Correct\n";
                correctCount++;

                char arr[response.length() + 1];
                for (int x = 0; x < sizeof(arr); x++) {
                    arr[x] = response[x];
                }

                correctLetters[correctCount] = arr[0];
                printAll(guesses,correctLetters,incorrectLetters);

            }
            else{
                std::cout << "You entered '"<< response << "' and you are incorrect\n";
                incorrectCount++;

                char arr[1] = {0};
                for (int x = 0; x < sizeof(arr); x++) {
                    arr[x] = response[x];
                }

                incorrectLetters[incorrectCount] = arr[0];
                guesses--;
                printAll(guesses,correctLetters,incorrectLetters);
            }
        }

        std::cout <<"Word is " << word << std::endl;
        std::cout <<"\nWord count is " << letterCount;




    return 0;
}
void printAll(int remainingGuesses, char* correctList, char* incorrectList){
    std::cout << "\nYou have '"<< remainingGuesses << "' guesses remaining\n";
    std::cout << "All correct letters: ";

    // loop through the array elements
    size_t n = sizeof(correctList)/sizeof(correctList[0]);

    // loop through the array elements
    for (size_t i = 0; i < n; i++) {
        std::cout << correctList[i] << ' ';
    }
    std::cout << "All incorrect letters: ";
    // loop through the array elements
    size_t m = sizeof(incorrectList)/sizeof(incorrectList[0]);

    // loop through the array elements
    for (size_t i = 0; i < m; i++) {
        std::cout << incorrectList[i] << ' ';
    }

    std::cout << "\n";
}