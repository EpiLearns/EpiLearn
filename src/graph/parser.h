#ifndef PARSER_H
#define PARSER_H

#include "node.h"

char* replaceWord(char* s, char* oldW,char* newW);
int checkSyntax(char* string);
node* parseExpression(char* string);
void removeSpaces(char* str);


int findMatchingParenthesisIndexLeft(char* string, int index);
int findMatchingParenthesisIndexRight(char* string, int index);


#endif