#ifndef GENERATOR_H
#define GENERATOR_H
#include <map>
#include <string>


class Generator{
    private:
    int k, c_out;
    const std::map<std::string, float> &freq;
    const std::map<std::string, std::map<char, float>> &nextmap;

    public:

    //Constructor
    Generator(int k,
        const std::map<std::string, float> &freq, 
        const std::map<std::string, std::map<char, float>> &nextmap );

    //Generate Text of c_out length
    
    std::string generate(int c_out);

};


#endif