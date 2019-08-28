/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */

#include <iostream>
#include <fstream>
#include "filelib.h" // promptUserForFile
#include "console.h"
using namespace std;

/* Function prototypes */

void removeComments(istream & is, ostream & os);

/* Main program */

int main() {
   ifstream infile;
   promptUserForFile(infile, "Input file: ");
   removeComments(infile, cout);
   infile.close();
   return 0;
}

/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */

void removeComments(istream & is, ostream & os) {
    int ch;
    int next_ch;
    while ((ch = is.get()) != EOF) {
        next_ch = is.get();//check the next character
        is.unget();//move back one character
        if (next_ch == EOF) break;
        if (!((ch == '/' && next_ch == '/') || (ch == '/' && next_ch == '*'))) {
            os.put(char(ch));// if not in comments, put the character into the output stream
        }
        else if (ch == '/' && next_ch == '*') {// overlook the '/*' comments until it meets "*/"
            while (true) {
                ch = is.get();
                next_ch = is.get();
                is.unget();
                if (ch == '*' && next_ch == '/') {
                    is.get();
                    break;
                }
                if (ch == EOF) break;
            }
        }
        else if (ch == '/' && next_ch == '/') {// overlook the '//' comments until the end of the sentence
            while (true) {
                ch = is.get();
                if (ch == EOF || ch == '\n') break;
            }
        }
    }
}

