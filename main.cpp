#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

void kgramz(int k,std::string &filename,  int c_out){

    std::ifstream file(filename);

    if(!file.is_open()){
       std::cout<<"File Error: Couldn't Open";
       return;
    }
    
    std::string line;
    std::map<std::string, int> freq;
    std::map<std::string, std::map<char, int>> nextmap;

    while(std::getline(file, line)){
        for (size_t i = 0; i+k <line.length(); ++i){
            std::string kg = line.substr(i, k);
            char nextc = line[i+k];  

            freq[kg]++;
            nextmap[kg][nextc]++;

            }         
    }file.close();
    
    for(const auto &p : freq) {std::cout<< p.first<<":"<<p.second<<"\n";}

    for(const auto &p : nextmap) {
        for (auto &w : p.second ) std::cout << p.first<<":" << w.first<<"::"<<w.second<<"\n";
    }
}


int main(int argc, char* argv[]){

    if (argc != 4){
        std::cout<< "Usage: ./a.out <k-gram size> <filename> <char limit>\n";
        return 1;
    }

    int k= atoi(argv[1]);
    std::string filename = argv[2]; 
    int c_out= atoi(argv[3]);

    kgramz(k, filename, c_out);
    
}