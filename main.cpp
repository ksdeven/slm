#include "kgram.h"
#include "generator.h"
#include <string>
#include <iostream>
#include <fstream>


int main(int argc, char* argv[]){

    if (argc != 4){
        std::cout<< "Usage: ./a.out <k-gram size> <filename> <char limit>\n";
        return 1;
    }

    int k= atoi(argv[1]);
    std::string filename = argv[2]; 
    int c_out= atoi(argv[3]);
    
    Kgramz kg(k);
    
    kg.checkfile(filename);

    Generator word(k, kg.getFreq(), kg.getnextmap());
    std::cout<<word.generate(c_out)<<std::endl;


}