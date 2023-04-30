// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(TestCaseName, TestName) {
        const int NPREF = 2;
        std::string filename = "input.txt";
        typedef std::deque<std::string> prefix;
        std::map<prefix, std::vector<std::string>> statetab
	= generateMarkov(NPREF, filename);
        prefix pref = statetab.begin()->first;
        int result = pref.size();
        EXPECT_EQ(result, NPREF);
}
TEST(TestCaseName2, TestName2) {
        const int NPREF = 2;
        const int MAXGEN = 10;
        std::string filename = "input.txt";
        typedef std::deque<std::string> prefix;
        std::map<prefix, std::vector<std::string>> statetab
	= generateMarkov(NPREF, filename);
        prefix intitalPref;
        intitalPref.push_back("was");
        intitalPref.push_back("wondering");
        std::string text = generateText(NPREF, MAXGEN, intitalPref, statetab);
        std::string expected = "if after all ";
        EXPECT_EQ(text, expected);
}
TEST(TestCaseName3, TestName3) {
        const int NPREF = 2;
        const int MAXGEN = 10;
        std::string filename = "input.txt";
        typedef std::deque<std::string> prefix;
        std::map<prefix, std::vector<std::string>> statetab
	= generateMarkov(NPREF, filename);
        prefix pref;
        pref.push_back("was");
        pref.push_back("wondering");
        std::string result = statetab[pref][0];
        std::string expected = "if";
        EXPECT_EQ(result, expected);
}
TEST(TestCaseName4, TestName4) {
        const int NPREF = 2;
        const int MAXGEN = 10;
        std::string filename = "input.txt";
        typedef std::deque<std::string> prefix;
        std::map<prefix, std::vector<std::string>> statetab
	= generateMarkov(NPREF, filename);
        prefix pref;
        pref.push_back("from");
        pref.push_back("the");
        EXPECT_EQ(statetab[pref][0], "other");
        EXPECT_EQ(statetab[pref][1], "outside");
}
TEST(TestCaseName5, TestName5) {
        const int NPREF = 2;
        const int MAXGEN = 1000;
        std::string filename = "input.txt";
        typedef std::deque<std::string> prefix;
        std::map<prefix, std::vector<std::string>> statetab
	= generateMarkov(NPREF, filename);
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
        int index = rand_r() % start_words.size();
        for (int i = 0; i < NPREF; i++) {
                intitalPref.push_back(start_words[index + i]);
        }
        std::string text = generateText(NPREF, MAXGEN, intitalPref, statetab);
        int count = 0;
        if (text.size() >= MAXGEN) count = MAXGEN;
        EXPECT_EQ(count, MAXGEN);
}
