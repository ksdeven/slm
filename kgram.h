#ifndef KGRAM_H
#define KGRAM_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

class kgramz{
    private:
    int k;                     //size of K-gram
    std::map<std::string, int> freq;    //freq of each K-gram
    std::map<std::string, std::map<char, int>> nextmap; //freq of each K-gram with next char


    public:
    //constructor: Size
    kgramz(int k_size);

    //read the line and update the map!
    void readline(const std::string &line);

    //checking the file!
    bool checkfile(const std::string &filename); 

    //freuqncy and next char of all K-gram 
    void get_nextmap() const;

    friend std::ostream& operator<<(std::ostream &out, const kgramz &kg);
};


#endif