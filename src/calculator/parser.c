#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* replaceWord(char* s, char* oldW,char* newW)
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

int calculator_checkSyntax(char* string){

    //Check syntax, right now only checks if the characters are valid.
    /*
    TODO:
        - Check parenthesis as valid
        - Check all operators as valid
    */
    char math[] = "x.+-*/^()1234567890cossinqrtel";
    char alphabet[] = "abdfghjkmpuvwyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* checkA = strpbrk(string, alphabet);
    char* checkB = strpbrk(string, math);

    if(checkA != NULL || checkB == NULL){
        printf("$: INVALID COMMAND\n");
        printf("$: Only the math operation symbols:\n '+', '-', '*', '/', '^', '(', ')', numbers and commands are accepted as input.\n");
        return 0;
    }
    else return 1;
}

node* calculator_parseExpression(char *string){
    node* current = createNode();
    int len = strlen(string);
    int parenthesisLevel = 0;
    removeSpaces(string);

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

    if(string[0] == '(' && string[len - 1] == ')' && findMatchingParenthesisIndexRight(string, 0) == len - 1){
        string[len - 1] = '\0';
        free(current);
        current = calculator_parseExpression(&string[1]);
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
            current->operator = (c == '+' ? add : sub);
            current->left = calculator_parseExpression(string);
            current->right = calculator_parseExpression(&string[i + 1]);
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
            current->operator = (c == '*' ? mult : divi);
            current->left = calculator_parseExpression(string);
            current->right = calculator_parseExpression(&string[i + 1]);
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
            current->operator = power;
            current->left = calculator_parseExpression(string);
            current->right = calculator_parseExpression(&string[i + 1]);
            return current;
        }
    }
    
    // Fourth pass for cos operator
    for (int i = len-1; i >= 0; i--)
    {
        char c = string[i];
        if (c == '(') parenthesisLevel--;
        if (c == ')') parenthesisLevel++;

        if (c == 'c' && string[i+1] ==  'o' && string[i+2] == 's' && parenthesisLevel == 0)
        {
            string[i] = 0; 
            string[i+1] = 0;
            string[i+2] = 0;
            current->operator = cosinus;
            current->left = calculator_parseExpression(string);
            current->right = calculator_parseExpression(&string[i+3]);
            return current;
        }
    }

    for (int i = len-1; i >= 0; i--)
    {
        char c = string[i];
        if (c == '(') parenthesisLevel--;
        if (c == ')') parenthesisLevel++;

        if (c == 's' && string[i+1] ==  'i' && string[i+2] == 'n' && parenthesisLevel == 0)
        {
            string[i] = 0; 
            string[i+1] = 0;
            string[i+2] = 0;
            current->operator = sinus;
            current->left = calculator_parseExpression(string);
            current->right = calculator_parseExpression(&string[i+3]);
            return current;
        }
    }
    for (int i = len-1; i >= 0; i--)
    {
        char c = string[i];
        if (c == '(') parenthesisLevel--;
        if (c == ')') parenthesisLevel++;

        if (c == 's' && string[i+1] ==  'q' && string[i+2] == 'r' && string[i+3] == 't' && parenthesisLevel == 0)
        {
            string[i] = 0; 
            string[i+1] = 0;
            string[i+2] = 0;
            string[i+3] = 0;
            current->operator = square_root;
            current->left = calculator_parseExpression(string);
            current->right = calculator_parseExpression(&string[i+4]);
            return current;
        }
    }
    for (int i = len-1; i>= 0; i--)
    {
        char c = string[i];
        if (c == '(') parenthesisLevel--;
        if (c == ')') parenthesisLevel++;
        if(c == 'e' && parenthesisLevel == 0)
        {
            string[i] = 0;
            current->operator = exponential;
            current->left = calculator_parseExpression(string);
            current->right = calculator_parseExpression(&string[i+1]);
            return current;

        }
    }
    
    for(int i = len-1; i>=0; i--)
    {
        char c = string[i];
        if(c == '(') parenthesisLevel--;
        if(c == ')') parenthesisLevel++;
        if(c == 'l' && string[i+1] == 'n' && parenthesisLevel == 0)
        {
            string[i] = 0;
            string[i+1] = 0;
            current->operator = logarithme;
            current->left = calculator_parseExpression(string);
            current->right = calculator_parseExpression(&string[i+2]);
            return current;
        }
    }
    return NULL;
}

void removeSpaces(char* str){
    

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



int findMatchingParenthesisIndexRight(char* string, int index){
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

int findMatchingParenthesisIndexLeft(char* string, int index){
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