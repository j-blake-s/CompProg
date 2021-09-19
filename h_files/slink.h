#ifndef SLINK_H_
#define SLINK_H_
#include <iostream>
#include <fstream>

//** Globals
std::streambuf *inbuf = NULL;
std::streambuf *outbuf = NULL;
std::fstream *ifs = NULL;
std::fstream *ofs = NULL;

//** Prototypes
void sopen(std::istream&,std::string);
void sclose(std::istream&);

//** Definitions
void sopen(std::istream &is, std::string fn) {
    if (ifs != NULL) {
        std::cerr << "Close streams before opening more" << std::endl;
        return;
    } else {
        ifs = new std::fstream(fn,std::fstream::in);

        //* Check that file opened correctly
        if (ifs -> is_open()) {
            inbuf = is.rdbuf();
            is.rdbuf(ifs -> rdbuf());
        } else {
            delete ifs;
            ifs = NULL;
            std::cerr << "Failed to open file!" << std::endl;
        }
    }
}

void sclose(std::istream &is) {
    if (ifs != NULL) {
        delete ifs;
        ifs = NULL;
    } if (inbuf != NULL) {
        is.rdbuf(inbuf);
        inbuf = NULL;
    }
}

#endif  // SLINK_H_