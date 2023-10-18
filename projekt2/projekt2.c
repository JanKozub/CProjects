#include <stdio.h>
#include <string.h>
#include <math.h>

int getAmountOfWords(char string[]) {
    int wordsAmount = 1;
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == ' ') {
            wordsAmount++;
        }
    }
    return wordsAmount;
}

int getMaxLen(int wordsAmount, int indexArr[]) {
    int maxLen = 0;
    for (int i = 0; i < wordsAmount; ++i) {
        int wordLen = indexArr[i + 1] - indexArr[i] - 1;
        if (wordLen > maxLen) {
            maxLen = wordLen;
        }
    }
    return maxLen;
}

int getIndexOfWord(char string[], char input[]) {
    int wordsAmount = getAmountOfWords(string);
    printf("Amount of words: %i\n", wordsAmount);
    int counter = 1;

    int indexArr[wordsAmount];
    indexArr[0] = 0;

    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == ' ') {
            indexArr[counter] = i + 1;
            counter++;
        }
    }
    indexArr[counter] = strlen(string);

    char words[wordsAmount][getMaxLen(wordsAmount, indexArr) + 3];

    for (int i = 0; i < wordsAmount; ++i) {
        int wordLen = indexArr[i + 1] - indexArr[i] - 1;
        char word[wordLen];

        for (int j = 0; j <= wordLen + 1; ++j) {
            word[j] = string[indexArr[i] + j];
        }
        word[wordLen] = '\0';

        strcpy(words[i], word);
    }

    int is = 0, ie = wordsAmount - 1, currentIndex, currentChar, inputChar, lastIndex = 0, timeoutCounter = 0;

    while (1) {
        currentIndex = (int) (is + floor((ie - is) / 2));

        if(currentIndex == lastIndex) {
            timeoutCounter++;
            if(timeoutCounter == 3) {
                return -1;
            }
        }
        lastIndex = currentIndex;

//        printf("%s == %s\n", words[currentIndex], input);
        if (strcmp(words[currentIndex], input) == 0) {
            return currentIndex;
        }

        int i = -1;
        do {
            i++;
            inputChar = (int) input[i];
            currentChar = (int) words[currentIndex][i];
        } while (inputChar == currentChar);

        if (inputChar > currentChar) {
            is = currentIndex;
        } else {
            ie = currentIndex;
        }
    }
}

int main() {
    char string[] = "ananas baba banan cytryna drewno ewa framuga gigant kiwi marchew truskawka rozkaz wiatr woda yeti";
    char input[] = "drr";

    int index = getIndexOfWord(string, input);

    if(index == -1) {
        printf("Slowa nie znaleziono");
    } else {
        printf("indeks slowa to: %i", index);
    }


    return 0;
}
