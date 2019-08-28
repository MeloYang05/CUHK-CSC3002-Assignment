/*
 * File: p2.h
 * -----------
 * This file exports four functions: transform(string str),
 * findDNAMatch(string s1, string s2, int start=0), bool
 * isDNAStructure(string str), void p2() to check the attachment
 * between two DNA strands.
 */

#ifndef _p2_h
#define _p2_h
#include <string>

/*
 * Function: transform
 * Usage: string n = transform(string m);
 * -------------------------------------
 * Return the attaching DNA strand of the
 * original DNA strand. For example, if
 * the parameter is "ATCG", it will return
 * "TAGC"
 */

std::string transform (std::string str);

/*
 * Function: findDNAMatch
 * Usage: int n = findDNAMatch(string s1, string s2, int k);
 * -------------------------------------------------------
 * Return the first position at whick strand s1 can attach to
 * the s2, if there's no match, then return -1.
 */

int findDNAMatch(std::string s1, std::string s2, int start = 0);

/*
 * Function: isDNAStructure
 * Usage: bool n = isDNAStructure(string str);
 * -------------------------------------------
 * Check whether a string accord with DNAStructure.
 * If is, return true, else return false.
 */

bool isDNAStructure(std::string str);

/*
 * Function: p2
 * Usage: p2();
 * -------------
 * Ask the user two input two DNA strands, check the legality,
 * then return all the attaching positions. If there's no
 * matching, give special notice.
 */
void p2();

#endif // 
