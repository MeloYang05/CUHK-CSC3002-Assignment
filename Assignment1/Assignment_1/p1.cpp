/*
 * File: p1.cpp
 * -------------
 * This file implements p1.h internface.
 */

#include <string>
#include "calendar.h"
#include "p1.h"
#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

/*
 * Implementation notes: isInteger
 * -------------------------------
 * This function check whether a string is in
 * integer format by using for loop check if
 * every character is integer. If there's one
 * character not a integer, the whole function
 * will return false, else return true.
 */

bool isInteger(string str){
    for (unsigned int i=0; i<str.length();i++){
        if (!isdigit(str[i])){
            return false;
        }
    }
    return true;
}


/*
 * Implementation notes: p1
 * ------------------------
 * This function firstly ask the user to input
 * a year, the default cin is in string format in
 * order to check the input input legality. If the
 * input is illegal, the function will ask the user
 * to input again until it is legal. Then it uses
 * for loop looping twelve times to give a list of
 * number of days in each month in that year.
 * In the process, it uses monthToString function
 * to transform the value of Month type into string,
 * and it uses daysInMonth function to determine the
 * days of the month in a certain year.
 */

void p1() {
    string string_year; /*Define a string to recieve cin for input legality check*/
	int year;
    cout << "Enter a year:";
    cin>>string_year;
    /*Input legality check*/
    while (!isInteger(string_year)){
        cout<<"Your input is wrong!please try again:";
        cin>>string_year;
    }
    /*Transfer the string type to int type and pass the value to variable year*/
    stringstream ss;
    ss<<string_year;
    ss>>year;
    /*Output the list by for loop*/
    for (int i=1; i<=12; i++){
        cout<< monthToString(Month(i))<<" has "<<daysInMonth(Month(i), year)<<" days"<<endl;
    }
}


