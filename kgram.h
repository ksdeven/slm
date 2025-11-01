#ifndef KGRAM_H
#define KGRAM_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

class Kgramz{
    private:
    int k;                     //size of K-gram
    std::map<std::string, float> freq;    //freq of each K-gram
    std::map<std::string, std::map<char, float>> nextmap; //freq of each K-gram with next char


    public:
    Kgramz(int k);

    //checking the file!
    bool checkfile(const std::string &filename); 

    //read lines
    void readline(const std::string &line); 

    //freuqncy and next char of all K-gram 
    const std::map<std::string, float>& getFreq() const { return freq; }
   
    const std::map<std::string, std::map<char, float>>& getnextmap() const {return nextmap;}

    //friend std::ostream& operator<<(std::ostream &out, const Kgramz &kg);
};


#endif