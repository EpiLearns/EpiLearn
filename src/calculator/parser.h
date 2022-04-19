#ifndef PARSER_H
#define PARSER_H

#include "node.h"

char* calculator_replaceWord(char* s, char* oldW,char* newW);
int calculator_checkSyntax(char* string);
node* calculator_parseExpression(char* string);
void calculator_removeSpaces(char* str);


int calculator_findMatchingParenthesisIndexLeft(char* string, int index);
int calculator_findMatchingParenthesisIndexRight(char* string, int index);


#endif