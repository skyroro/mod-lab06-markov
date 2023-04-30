// Copyright 2021 GHA Test Team
#include <iostream>
#include "textgen.h"

int main() {
    const int NPREF = 2;
    const int MAXGEN = 10;
    std::string filename = "input.txt";
    //вызвать создание таблицы
    typedef std::deque<std::string> prefix;
    std::map<prefix, std::vector<std::string>> statetab
    = generateMarkov(NPREF, filename);
    //создаем начальный префикс
    std::vector<std::string> start_words;
    std::ifstream file(filename);
    if (!file.is_open()) std::cout << "no";
    int word_count = 0;
    std::string word;
    while (file >> word) {
        start_words.push_back(word);
    }
    file.close();
    prefix intitalPref;
    srand(time(NULL));
    int index = rand() % start_words.size();
    for (int i = 0; i < NPREF; i++) {
        intitalPref.push_back(start_words[index + i]);
    }
    //генерируем текст
    std::string text = generateText(NPREF, MAXGEN, intitalPref, statetab);
    std::cout << text;
    return 0;
}
