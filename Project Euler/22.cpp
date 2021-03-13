#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "gmacro.h"
int alpha_score(std::string word)
{
    int score = 0;
    for (auto c : word)
        score += c - 64;
    return score;
}

int main()
{
    std::vector<std::string> names;
    long long total_score = 0;
    std::fstream file;
    file.open(R"x(Source Files/22.txt)x");
    std::string word;
    while (std::getline(file, word, ','))
        names.push_back(word.substr(1, word.length() - 2));
    
    auto string_compare =  [](const char* s1, const char* s2) {
        //return strcmp(s1,s2) < 0;
    };
    std::sort(names.begin(), names.end());
    
    for (size_t i = 0; i < names.size(); ++i)
    {
        auto word_length = alpha_score(names.at(i));
        total_score += word_length * (i + 1);
        log(word_length);
    }
    std::cout << "Total Score: " << total_score;
    return 0;
}