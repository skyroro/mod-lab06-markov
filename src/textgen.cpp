// Copyright 2021 GHA Test Team
#include "textgen.h"

std::map<std::deque<std::string>, std::vector<std::string>>
generateMarkov(int NPREF, std::string filename) {
    typedef std::deque<std::string> prefix;
    std::map<prefix, std::vector<std::string>> statetab;
    prefix pref;
    std::ifstream file(filename);
    if (!file.is_open()) std::cout << "no";
    int word_count = 0;
    std::string word;
    while (file >> word) {
        if (word_count > NPREF) {
            statetab[pref].push_back(word);
        }
        pref.push_back(word);
        if (pref.size() > NPREF) {
            pref.pop_front();
        }
        word_count++;
    }
    file.close();
    return statetab;
}

std::string generateText(int NPREF, int MAXGEN,
    std::deque<std::string> intitalPref,
    std::map<std::deque<std::string>,
    std::vector<std::string>> statetab) {
    std::string text = "";
    typedef std::deque<std::string> prefix;
    std::cout << std::endl;
    int count = 0;
    while (count < MAXGEN) {
        std::vector<std::string> suf = statetab[intitalPref];
        if (suf.empty()) {
            break;
        }
        int n = suf.size();
        srand(time(NULL));
        int r = std::rand() % n;
        std::string word = suf[r];
        count += word.size();
        text = text + word + " ";
        intitalPref.pop_front();
        intitalPref.push_back(word);
    }
    return text;
}
