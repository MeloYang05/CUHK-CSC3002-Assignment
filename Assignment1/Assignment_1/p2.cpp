/*
 * File: p2.cpp
 * -------------
 * This file implements the p2.h internface.
 */

#include "p2.h"
#include <iostream>
#include <string>
using namespace std;

/*
 * Implementation notes: transform
 * --------------------------------
 * This function use for loop to check every character
 * in a string, if the string meet the DNA structure, it
 * will transform and return the string of the attaching
 * DNA strand.
 */

string transform(string str) {
    for (unsigned int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case 'A':
			str[i] = 'T';
			break;
		case 'T':
			str[i] = 'A';
			break;
		case 'C':
			str[i] = 'G';
			break;
		case 'G':
			str[i] = 'C';
			break;
		}
	}
	return str;
}

/*
 * Implementation notes: findDNAMatch
 * -----------------------------------
 * This function firstly use transform function to get
 * the attaching DNA strand of s2, then it can conveniently
 * use find method defined in string type to return the
 * first position at whick strand s1 can attach to
 * the s2, if there's no match, then return -1.
 */

int findDNAMatch(string s1, string s2, int start) {
    s1 = transform(s1);
    return int(s2.find(s1, unsigned(start)));
}

/*
 * Implementation notes: isDNAStructure
 * -------------------------------------
 * This function check whether a string is in
 * DNA structure by using for loop check if
 * every character is 'A' or 'T' or 'G' or 'C'.
 * If there exists some characters don't meet the
 * requirement, the function will return true, else
 * return false.
 */

bool isDNAStructure(string str){
    for (unsigned int i=0;i<str.length();i++){
        if (!(str[i]=='A' || str[i]=='T' || str[i]=='G' ||str[i]=='C')){
            return false;
    }
    }
    return true;
}

/*
 * Implementaion notes: p2
 * -----------------------
 * The function firstly ask the user to input long DNA
 * strand and short DNA strand, meanwhile using isDNAStructure
 * function to check the input legality. If the input is illegl,
 * the it will ask the user to input again until legal.
 * Then it use findDNAMatch function to check if there's
 * attaching position, if there's no, it will give special
 * notice. Else, it will use while loop to find all the other
 * positions. The loop will terminate until there's no more
 * position. At last, the function will present all the attaching
 * position to user.
 */

void p2() {
	string long_DNA_strand;
	string short_DNA_strand;
	cout << "Please input the longer DNA strand:";
	cin >> long_DNA_strand;
    /*Check the legality of long_DNA_strand*/
    while (!isDNAStructure(long_DNA_strand)){
        cout<<"Your input is wrong, please try again:";
        cin>>long_DNA_strand;
    }
	cout << "Please input the shorter DNA strand:";
	cin >> short_DNA_strand;
    /*Check the legality of short_DNA_strand*/
    while (!isDNAStructure(short_DNA_strand)){
        cout<<"Your input is wrong, please try again:";
        cin>>short_DNA_strand;
    }
    switch (findDNAMatch(short_DNA_strand, long_DNA_strand)) {
    /*The situation that doesn't find matching, give special notice.*/
    case -1:
		cout << "There is no matching structure."<<endl;
        break;
	default:
        cout << "The matching positions should be " << findDNAMatch(short_DNA_strand, long_DNA_strand);
        /*Set new_start on the next position*/
        int new_start = findDNAMatch(short_DNA_strand, long_DNA_strand)+1;
        /*Using while loop to find all the attaching positions,If can't find, the loop will break*/
        while (!(findDNAMatch(short_DNA_strand, long_DNA_strand, new_start) == -1)) {
            /*Finding begin with new_start*/
            cout << ", " << findDNAMatch(short_DNA_strand, long_DNA_strand, new_start);
            /*Set new_start on the next position*/
            new_start = findDNAMatch(short_DNA_strand, long_DNA_strand, new_start) + 1;
            }
        break;}
	}
