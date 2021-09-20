#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
        int sum = 0;

        //? Cut left part
        int lbound;
        for (int i = 0; i < S.length();i++) {
            if (S[i] == '1') {
                lbound = i;
                break;
            }
        }

        //? Cut right part
        int rbound;
        for (int j = S.length()-1;j >= 0;--j) {
            if (S[j] == '1') {
                rbound = j;
                break;
            }
        }


        string left = S.substr(0,lbound);
        string middle;
        if (lbound != rbound)
            middle = S.substr(lbound+1,rbound-lbound-1);
        string right = S.substr(rbound+1,S.length());

        int n = left.length();
        sum += n * (n+1) / 2;

        n = right.length();
        sum += n * (n+1) / 2;

        if (lbound != rbound) {
            std::stringstream SS(middle);
            string segment;
            while(getline(SS,segment,'1')) {
                n = segment.length();
                if (n%2 == 0) {
                    n = n/2;
                    sum += n * (n+1);
                } else {
                    n = n/2;
                    sum += (n+1) * (n+1);
                }
            }
        }

        int x = sum;

        
        std::cout << "Case #" << t << ": " << x << std::endl;
    }

    sclose(std::cin);  // Don't Touch
    return 0;
}
