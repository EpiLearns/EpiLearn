#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* graph_replaceWord(char* s, char* oldW,char* newW)
{
    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
  
    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;
  
            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }
  
    // Making new string of enough length
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);
  
    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, oldW) == s) {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }
  
    result[i] = '\0';
    return result;
}

int graph_checkSyntax(char* string){

    //Check syntax, right now only checks if the characters are valid.
    /*
    TODO:
        - Check parenthesis as valid
        - Check all operators as valid
    */
    char math[] = "x.+-*/^()1234567890";
    char alphabet[] = "abcdefghijklmnopqrstuvwyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* checkA = strpbrk(string, alphabet);
    char* checkB = strpbrk(string, math);

    if(checkA != NULL || checkB == NULL){
        printf("$: INVALID COMMAND\n");
        printf("$: Only the math operation symbols:\n '+', '-', '*', '/', '^', '(', ')', numbers and commands are accepted as input.\n");
        return 0;
    }
    else return 1;
}

node* graph_parseExpression(char *string){
    node* current = graph_createNode();
    int len = strlen(string);
    int parenthesisLevel = 0;

    //First base case, check if the string contains only an integer number


    char *check;
    double number = strtod(string, &check);
    

    if(check[0] == '\0'){
        
        current->value = number;
        
        current->operator = NULL;
        return current;
    }
    //Second "base" case, check if entire string is within parenthesis
    //not really a base case if it calls itself again, but it behaves like one

    if(string[0] == '(' && string[len - 1] == ')' && graph_findMatchingParenthesisIndexRight(string, 0) == len - 1){
        string[len - 1] = '\0';
        free(current);
        current = graph_parseExpression(&string[1]);
        return current;
    }

    //Right to left, because tree is later evaluated left to right, so the tree constructor does it in reverse
    //First pass is + and - signs, again because tree is evaluated in inverse order to its construction

    for(int i = len -1; i >= 0; i--){
        char c = string[i];
        if (c == '(') parenthesisLevel--;
        if (c == ')') parenthesisLevel++;

        if (parenthesisLevel == 0 && (c == '+' || c == '-')){
            string[i] = 0;
            current->operator = (c == '+' ? graph_add : graph_sub);
            current->left = graph_parseExpression(string);
            current->right = graph_parseExpression(&string[i + 1]);
            return current;
        }
    }


    //Second pass for * and / signs

    for(int i = len -1; i >= 0; i--){
        char c = string[i];
        if (c == '(') parenthesisLevel--;
        if (c == ')') parenthesisLevel++;

        if (parenthesisLevel == 0 && (c == '*' || c == '/')){
            string[i] = 0;
            current->operator = (c == '*' ? graph_mult : graph_divi);
            current->left = graph_parseExpression(string);
            current->right = graph_parseExpression(&string[i + 1]);
            return current;
        }
    }

    //Third pass for ^ operator

    for(int i = len -1; i >= 0; i--){
        char c = string[i];
        if (c == '(') parenthesisLevel--;
        if (c == ')') parenthesisLevel++;

        if (c == '^' && parenthesisLevel == 0){
            string[i] = 0;
            current->operator = graph_power;
            current->left = graph_parseExpression(string);
            current->right = graph_parseExpression(&string[i + 1]);
            return current;
        }
    }
    return NULL;
}

void graph_removeSpaces(char* str){
    

    int oLen = strlen(str);
    int counter = 0;
    for(int i = 0; i <= oLen; i++){
        if(str[i] != ' ' && str[i] != '\n'){
            str[counter] = str[i];
            counter++;
        }
        else str[i] = '\0';
    }
    return;
}

int graph_findMatchingParenthesisIndexRight(char* string, int index){
    int len = strlen(string);
    int parentesisLevel = 1;
    for (int i = index + 1; i < len; i++){
        char c = string[i];
        if(c == '(') parentesisLevel++;
        else if (c == ')'){
            parentesisLevel--;
        }
        if (parentesisLevel == 0){
            return i;
        }
    }
    return 0;
}

//Not used, but useful to have anyways

int graph_findMatchingParenthesisIndexLeft(char* string, int index){
    int parentesisLevel = 1;
    for (int i = index - 1; i >= 0; i--){
        char c = string[i];
        if(c == '(') parentesisLevel--;
        else if (c == ')'){
            parentesisLevel++;
        }
        if (parentesisLevel == 0){
            return i;
        }
    }
    return 0;
}