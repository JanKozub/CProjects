#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <clocale>

int getAmountOfWords(char string[]) {
    int wordsAmount = 1;
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == ' ') {
            wordsAmount++;
        }
    }
    return wordsAmount;
}

int getMaxLen(int wordsAmount, const int indexArr[]) {
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
    indexArr[counter] = (int) strlen(string);

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

    int currentIndex, currentChar, inputChar, lastIndex = 0, timeoutCounter = 0;
    double is = 0, ie = wordsAmount - 1;

    while (1) {
        currentIndex = (int) (is + floor((ie - is) / 2));

        if (currentIndex == lastIndex) {
            timeoutCounter++;
            if (timeoutCounter == 3) {
                return -1;
            }
        }
        lastIndex = currentIndex;

        printf("sprawdzam: %s == %s\n", words[currentIndex], input);
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
    system("chcp 1250");
    setlocale(LC_ALL, "Polish");

    char stringIn[] = "ananas bąba     banan cytryna drewno ewa framuga gigant kiwi marchew truskawka rozkaz wiatr woda yeti";
    char input[] = "ananas";

    int counter = 0;
    for (int i = 0; i < strlen(stringIn); ++i) {
        if (stringIn[i] == ' ' && stringIn[i + 1] != ' ') {
            counter++;
        }
    }

    int len = strlen(stringIn);
    char string[len];

    counter = 0;
    for (int i = 0; i < strlen(stringIn); ++i) {
        if(i == 0) {
            if(stringIn[0] != ' ') {
                string[counter] = stringIn[i];
                counter++;
            }
        } else{
            if (stringIn[i] == ' ' && stringIn[i + 1] != ' ' && counter != 0) {
                string[counter] = stringIn[i];
                counter++;
            } else if (stringIn[i] != ' ') {
                string[counter] = stringIn[i];
                counter++;
            }
        }
    }
    string[len] = '\0';
    printf("%s", string);


    int index = getIndexOfWord(string, input);

    if (index == -1) {
        printf("Slowa nie znaleziono");
    } else {
        printf("indeks slowa to: %i", index);
    }

    //CHCP1250
    return 0;
}
