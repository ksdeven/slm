#include "kgram.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>


int main(int argc, char* argv[]){

    if (argc != 4){
        std::cout<< "Usage: ./a.out <k-gram size> <filename> <char limit>\n";
        return 1;
    }

    int k= atoi(argv[1]);
    std::string filename = argv[2]; 
    //int c_out= atoi(argv[3]);
    
    kgramz kg(k);
    
    if (!kg.checkfile(filename)) {return 1;}

    std::cout << "K-gram frequencies:\n" << kg;
    std::cout << "\nNext-character frequencies:\n";
    kg.get_nextmap();
}