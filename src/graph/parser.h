#ifndef PARSER_H
#define PARSER_H

#include "node.h"

char* graph_replaceWord(char* s, char* oldW,char* newW);
int graph_checkSyntax(char* string);
node* graph_parseExpression(char* string);
void graph_removeSpaces(char* str);

int graph_findMatchingParenthesisIndexLeft(char* string, int index);
int graph_findMatchingParenthesisIndexRight(char* string, int index);


#endif