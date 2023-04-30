#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <cstdlib>
#include <ctime>

std::string generateText(int NPREF, int MAXGEN,
    std::deque<std::string> intitalPref,
    std::map<std::deque<std::string>,
    std::vector<std::string>> statetab);
std::map<std::deque<std::string>, std::vector<std::string>>
generateMarkov(int NPREF, std::string filename);
