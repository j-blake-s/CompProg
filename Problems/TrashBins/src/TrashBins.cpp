#include <iostream>
#include <string>
#include <fstream>
#include "..\..\..\include\slink.h"

using std::string;


const std::string filepath = "../data/sample.txt";
int main() {
    if (!sopen(std::cin,filepath)) return 0;  // Don't Touch

    int T,N;
    string S;

    std::cin >> T;

    for (int t = 1; t<=T;t++) {
        std::cin >> N;
        std::cin >> S;



        string x = "0";
        std::cout << "Case #" << t << ": " << x << std::endl;
    }

    sclose(std::cin);  // Don't Touch
    return 0;
}
