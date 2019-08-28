/*
 * File: p1.h
 * ----------
 * This internface provide a function p1() to
 * ask the user to input a year and then print
 * the number of days in each month of the year,
 * and a function isInteger(string str) to check
 * the input legality.
 */

#ifndef _p1_h
#define _p1_h

#include <string>

/*
 * Function: isInteger
 * Usage: bool isInteger(string str);
 * ----------------------------------
 * Check whether a string is in integer format
 */

bool isInteger(std::string str);

/*
 * Function: p1
 * Usage: p1();
 * ---------------
 * This function ask the user to input a year
 * and then print the number of days in each month
 * of the year.
 */

void p1();

#endif

