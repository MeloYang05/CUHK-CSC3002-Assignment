/*
 * File: Calendar.cpp
 * ------------------
 * This file implements the Calendar.h interface
 */

#include "calendar.h"
using namespace std;

/*
 * Implementation notes: daysInMonth
 * ---------------------------------
 * This function uses switch function to judge the
 * input is which month and return the corresponding
 * days. There is a special judgement for FEBRUARY.
 * We use isLeapYear function to judge whether the
 * input year is leap year. If it is true, then case
 * FEBRUARY will return 29, else 28.
 */
int daysInMonth(Month month, int year) {
	switch (month) {
	case APRIL:
	case JUNE:
	case SEPTEMBER:
	case NOVEMBER:
		return 30;
	case FEBRUARY:
		return (isLeapYear(year)) ? 29 : 28;
	default:
		return 31;
	}
}

/*
 * Implementation notes: isLeapYear
 * ---------------------------------
 * This function judges whether a year is a leap
 * year by following conditions: a year is a leap
 * year if the remainder of it devided by 400
 * equals 0 or the remainder of it devided by 4
 * equals 0 but it is not a multiple of 100.
 */

bool isLeapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

/*
 * Implementation notes: monthToString
 * -----------------------------------
 * Input should be a value of Month
 * type defined in enumeration in Calendar.h.
 * The function use switch methods to judge
 * certain months and return a string of the name
 * of the month.
 */

string monthToString(Month month) {
	switch (month) {
	case JANUARY: return "JANUARY";
	case FEBRUARY: return "FEBRUARY";
	case MARCH: return "MARCH";
	case APRIL: return "APRIL";
	case MAY: return "MAY";
	case JUNE: return "JUNE";
	case JULY: return "JULY";
	case AUGUST: return "AUGUST";
	case SEPTEMBER: return "SEPETEMBER";
	case OCTOBER: return "OCTOBER";
	case NOVEMBER: return "NOVEMBER";
	case DECEMBER: return "DECEMBER";
	}
}
