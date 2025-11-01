#include "generator.h"
#include <iostream>
#include <vector>
#include <random>

Generator::Generator(int k, 
        const std::map<std::string, float> &freq, 
        const std::map<std::string, std::map<char, float>> &nextmap ): 
        k(k), freq(freq), nextmap(nextmap){}

std::string Generator::generate(int c_out) {
    if (freq.empty()) return "";

    std::vector<std::string> words;
    std::vector<float> freqs;

    //store the freq and kgram from freq
    for (auto &p: freq){
        words.push_back(p.first);
        freqs.push_back(p.second);
    }
    //Generate a random starting word
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> startDist(freqs.begin(), freqs.end());
    
    std::string current = words[startDist(gen)];
    std::string out = current;

    //next char and prob from nextmap 
    while((int)out.size()<c_out){
        auto it = nextmap.find(current);
        if (it == nextmap.end() || it->second.empty()) break;
        
        //store the freq and nextchar from nextmap
        std::vector<char> chars;
        std::vector<float> charFreqs;

        for(auto &p: it->second){
            chars.push_back(p.first);
            charFreqs.push_back(p.second);
        }

        std::discrete_distribution<> charDist(charFreqs.begin(), charFreqs.end());
        char next = chars[charDist(gen)];
        out += next;

        current =current.substr(1)+next;
    }
    return out;
}

