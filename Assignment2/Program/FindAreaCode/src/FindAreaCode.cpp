/*
 * File: FindAreaCode.cpp
 * ----------------------
 * This program looks up a numeric area codes for the United States
 * and Canada.  The program works in both directions.  If the user
 * enters a number, the program prints out the state or province to
 * which that code is assigned.  If the user enters a name, it prints
 * out all the area codes assigned to that name.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "error.h"
#include "map.h"
#include "simpio.h"
#include "strlib.h"
#include "console.h"
#include <cctype>
using namespace std;

/* Function prototypes */

void readCodeFile(string filename, Map<int,string> & map);

/* Main program */

int main() {
   Map<int,string> areaCodeToState;
   readCodeFile("AreaCodes.txt", areaCodeToState);
   string user_input;
   while (true) {
       cout<<"Enter area code or state name:";
       getline(cin,user_input);
       if (isdigit(user_input[0])){//cheack whether user input the code or arae
           if (areaCodeToState.containsKey(stringToInteger(user_input))){
               cout<<areaCodeToState.get(stringToInteger(user_input))<<endl;//output the corresponding area
           } else {
               cout<<"There is no such area code."<<endl;
           }
       } else if (isalpha(user_input[0])){
           Map<int, string> :: iterator iter;//using interator of the map to do the inverse searching
           for (iter=areaCodeToState.begin();iter!=areaCodeToState.end();iter++){
               if (areaCodeToState.get(*iter)==user_input){
                   cout<<*iter<<endl;
               }
           }
       }
   }
   return 0;
}

/*
 * Function: readCodeFile
 * Usage: readCodeFile(filename, map);
 * -----------------------------------
 * Reads a data file representing area codes and locations into the map,
 * which must be declared by the client.  Each line must consist of the
 * area code, a hyphen, and the name of the state/province.
 */

void readCodeFile(string filename, Map<int,string> & map) {
    ifstream infile;
    infile.open(filename);
    string line;
    while (getline(infile,line)){
        string code, area;
        for (unsigned int i=0; i<line.length(); i++) {
            if (isdigit(line[i])) {
                code+=line[i];
            }else if (isalpha(line[i]) || line[i]==' ') {
                area+=line[i];
            }
        }
        map.put(stringToInteger(code),area);
    }
}
