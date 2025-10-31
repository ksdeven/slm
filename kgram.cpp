#include "kgram.h"
#include <string>
#include <iostream>
#include <fstream>


//constructor
kgramz::kgramz(int k_size):k(k_size){}

//reading a line & Upadte the map
void kgramz::readline(const std::string &line){
    for (size_t i = 0; i+k <=line.length(); ++i){
        std::string kg = line.substr(i, k);
        freq[kg]++;
        if(i+k< line.size()){
            char nextc = line[i+k]; 
            nextmap[kg][nextc]++;
        }   
    }
}

//cehcking the file
bool kgramz::checkfile(const std::string &filename){
    std::ifstream file(filename);
    
    if(!file.is_open()){
       std::cout<<"File Error: Couldn't Open!\n";
       return false;
    }
    std::string line;
    while(std::getline(file, line)){
        for (char c : line ) {if (!isalpha(c)&& c!= ' '){return false;}}
        readline(line);
    }file.close();
    return true;
}
   

void kgramz::get_nextmap() const {

    for(const auto &p : nextmap) {
        for (auto &w : p.second ){ 
            std::cout << p.first<<":" << w.first<<"::"<<w.second<<"\n";
        }
    }
}

std::ostream& operator<<(std::ostream &out, const kgramz &kg) {
    for (const auto &p : kg.freq) {
        out << p.first << " : " << p.second << "\n";
    }
    return out;
}

