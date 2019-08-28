/*
 * File: Calendar.h
 * ----------------
 * This internface exports an enumerated type called
 * Month whose elements are the twelve months.
 * It also includes three functions: daysinMonth,
 * isLeapYear, MonthToString, which would be used
 * to write out the days of ench month in a certain year.
 */

#ifndef _calendar_h
#define _calendar_h

#include <string>

/*
 * Type: Month
 * ------------
 * This enumerated type is used to represent the twelve months,
 * and it gives them the corresponding value from 1 to 12.
 */

enum Month { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

/*
 * Function: daysInMonth
 * Usage: int p = daysInMonth(m,k);
 * --------------------------------
 * Note: m should be a value of Month type defined in
 * enumeration before, k should be a positive
 * integer to represent a year.
 * -----------------------------
 * Return the days of a certain monthe in a certain year
 */
int daysInMonth(Month month, int year);

/*
 * Function: isLeapYear
 * Usage: bool p = isLeapYear(int n);
 * ---------------------------------
 * Note: n should be a positive integer to
 * represent a certain year.
 * --------------------------
 * Return a bool result (true or false) to
 * judge wheather a year is leap year.
 */

bool isLeapYear(int year);

/*
 * Function: monthToString
 * Usage: string p = monthToString(m);
 * -----------------------------------
 * Note: m should be a value of Month
 * type defined in enumeration before.
 * ------------------------------------
 * Return a string of the name of a month.
 */

std::string monthToString(Month month);

#endif // !


