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
        std::stringstream ss(S);

        string temp;
        int sum = 0;

        /*
            > Solution Detail

                & (1) For any string 10......01, the sum of its values is 2 * summation(i=1,i=n/2){i * i+1 / 2} where n is the number of 0s
                        ? For odd values of n, add (1 + n/2)
                & (2.1) For any string 0....01, the sum of its values is n * 1+n / 2 where n is the number of 0s
                & (2.2) For any string 10...0, (2.1) holds true.

                !_Proof

                $ Let N be the number of 0s in a string lke 0...01
                $ Since the right hand 1 is the closest 1 for all 0s, the ith 0 from 
                $ the right will also have a value of i by definition. 
                $ Thus the summation will look like:

                        := 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + ... + n = n * n+1 /2

                $ This is a well-known equation for an increasing algebraic sequence of common difference 1.
                $ Now given any string 0...010...010...0, we can reduce to 0...01 + 0...0 + 10...0
                $ The left and right strings can be computed straight-forward. The middle string requires another
                $ equation. Since this string is surronded by 1s on each side, their values look like:

                        := 1 + 2 + 3 + ... + n/2 + n/2 -1 + n/2 -2 + ... + n/2-(n/2 -1)
                        := 2 * (1 + 2 + 3 + ... + n/2) = 2 * (n/2 * 1 + n/2 / 2) = n/2 * (1 + n/2)
                    
                $ This is for an even sequence. For an odd sequence, there exists a middle value wich is only computer 
                $ once and is equdistant from either 1. Thus its distance is | a - b | where a = N and b = the index of the middle
                $ If a sequence is odd, its summation looks like

                        := (1 + n/2) ^ 2

        */
        while(getline(ss,temp,'1')) {
            int len = temp.length();
            if (len == 0)
                continue;


            int tsum = (len/2)*(1+(len/2));
            if (len % 2 == 1)
                tsum += 1+(len/2);
            sum += tsum;
        }

        int x = sum;

        
        std::cout << "Case #" << t << ": " << x << std::endl;
    }

    sclose(std::cin);  // Don't Touch
    return 0;
}
