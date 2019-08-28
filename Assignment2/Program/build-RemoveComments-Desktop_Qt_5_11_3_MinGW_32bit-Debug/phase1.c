/******************************************************
 ******************************************************
 *
 * File: phase1.c
 * ----------------------
 * This file is about the string handling about the input
 * files and strings.
 *
 * The maximum size of the input file is 65536.
 *
 ******************************************************
 ******************************************************
 */
#include "phase1.h"
#include <stdio.h>
#include <string.h>
#include "phase2.h"
#include "labelTable.h"
#include <stdlib.h>


/******************************************************
 ******************************************************
 *
 * Function: getsize
 * ------------------------
 * This function can return the length of the input file
 * plus two (for easy processing).
 *
 ******************************************************
 ******************************************************
 */
unsigned int getsize(char asm_address[]){
    FILE *fp;
    char ch;
    char *str = NULL;
        str = (char*)malloc(sizeof(char)*65536);
        for (unsigned int i=0;i<65536;i++){
            str[i]='\0';
        }
    unsigned int size=0;
    fp=fopen(asm_address, "r");
    for (unsigned int i=0;(ch=fgetc(fp))!=EOF;i++){
        str[i]=ch;
        size=i+1;
        }
    size+=2;
    return size;
}


/******************************************************
 ******************************************************
 *
 * Function: whitespace
 * --------------------------
 * This function can replace all the unmeaningful but often
 * appeared symbol by whitespace ' '.
 *
 ******************************************************
 ******************************************************
 */
char *whitespace(char string[], unsigned int size){
    for (unsigned int i=0;i<size;i++){
        if (string[i]==':' || string[i]=='(' || string[i]==')' || string[i]==',' || string[i]=='\r'){
            string[i]=' ';
        }
    }
    return string;
}


/******************************************************
 ******************************************************
 *
 * Function: delete_notes_tabs
 * --------------------------
 * This function can replace notes and tabs by whitespace ' '.
 *
 ******************************************************
 ******************************************************
 */
char *delete_notes_tabs(char string[],unsigned int size){
    for (unsigned int i=0;i<size;i++){
        if (string[i]=='#'){
            for (unsigned int j=i;string[j]!='\n';j++){
                string[j]=' ';
            }
        }
        if (string[i]=='\t'){
            string[i]=' ';
        }
    }
    return string;
}






/******************************************************
 ******************************************************
 *
 * Function: getanswer
 * ---------------------------
 * The key function.
 *
 * Firstly four strings will be created and each of them
 * will store one meaningful word that is register name or
 * the operation name.
 *
 * Secondly, three integers: number_of_enter, ith_character,
 * search_location will be defined which help to count in
 * the loops.
 *
 * By those three integers, four enters will be assigned in
 * different words so that the getbinary function could be
 * run.
 *
 * Using strcat function to add all the returned answer together
 * so that the string answer will be the final binary
 * string answer.
 *
 ******************************************************
 ******************************************************
 */
char *getanswer(char string[], unsigned int size, int tagnumber[], char tagchar[]){


    /******************************************************
     Create 4 character arrays.

     Memory allocation and array initialization are needed
     else there will be something wrong.
    *********************************************************/
    char *enter1 = NULL;
        enter1 = (char*)malloc(sizeof(char)*16);

    char *enter2 = NULL;
        enter2 = (char*)malloc(sizeof(char)*16);

    char *enter3 = NULL;
        enter3 = (char*)malloc(sizeof(char)*16);

    char *enter4 = NULL;
        enter4 = (char*)malloc(sizeof(char)*16);

    for (unsigned int i=0;i<16;i++){
        enter1[i]='\0';
        enter2[i]='\0';
        enter3[i]='\0';
        enter4[i]='\0';
    }






    /******************************************************************
     Create three integers.

     Interger number_of_enter:
     represent the current word locates at which place of the line.
     Usually when it is one, the word is operation name
     when it is two, the word is the first register/label/number
     when it is three, the word is the second register/label/number
     when it is four, the word is the third register/label/number


     Integer ith_character:
     represent the location number of current character to the current word

     Interger search_location:
     Represent when the k-for loop is over, what should the next j
     (in outer j-loop) should be.


     Memory allocation and array initialization are needed for ans and answer
     else there will be something wrong.
    *********************************************************************/
    int number_of_enter=1;
    int ith_character=0;
    unsigned int search_location=0;
    char *answer = NULL;
        answer = (char*)malloc(sizeof(char)*65536);
        for (unsigned int i=0;i<65536;i++){
            answer[i]='\0';
        }
    char *ans = NULL;
        ans = (char*)malloc(sizeof(char)*34);
        for (unsigned int i=0;i<34;i++){
            ans[i]='\0';
        }

    for (unsigned int i=0;i<size;i++){
        if (string[i]=='\n'){
            for (unsigned int j=i+1;string[j]!='\n';j++){
                if (string[j]!=' ' && string[j]!='\n'){
                    for (unsigned int k=j;string[k]!=' ' && string[k]!='\n';k++){
                        if (number_of_enter==1) {enter1[ith_character]=string[k]; ith_character+=1;}
                        if (number_of_enter==2) {enter2[ith_character]=string[k]; ith_character+=1;}
                        if (number_of_enter==3) {enter3[ith_character]=string[k]; ith_character+=1;}
                        if (number_of_enter==4) {enter4[ith_character]=string[k]; ith_character+=1;}
                        search_location=k;
                    }
                    number_of_enter+=1;
                    ith_character=0;
                    j=search_location;
                }
            }

//printf("answer:%s,%d,%d\n",answer,size,i);
            if (i==size-1) return answer;
            //i-loop will break when it i reach the end of the string.

            if (enter1[0]=='\0') return answer;
            //This state also means i reached the end of the string.
         ans=strcat(getbinary(enter1,enter2,enter3,enter4,tagnumber,tagchar),"\n");
            strcat(answer,ans);

            for (unsigned int j=0;j<16;j++){
                enter1[j]='\0';
                enter2[j]='\0';
                enter3[j]='\0';
                enter4[j]='\0';
        }
        }
        number_of_enter=1;
if (i==size-2) return answer;
//printf("answer:%s,%d,%d\n",answer,size,i);
    }

    return answer;
}


/******************************************************
 ******************************************************
 *
 * Function: phase1
 * ---------------------------
 * The string initialization function.
 *
 * The input file will be read and it will initialize the
 * file including delete the notes, tabs.
 *
 ******************************************************
 ******************************************************
 */
char *phase1(char asm_address[], unsigned int size){
    FILE *fp;
    int ch;
    char *string = NULL;
        string = (char*)malloc(sizeof(char)*(size+1));
        for (unsigned int i=0;i<size+1;i++){
            string[i]='\0';
        }
        string[0]='\n';
        string[size-1]='\n';

    fp=fopen(asm_address,
            "r");

    for (unsigned int i=0;(ch=fgetc(fp))!=EOF;i++){
        string[i+1]=(char)ch;
        }


    string=delete_notes_tabs(string,size);

    return string;
}







