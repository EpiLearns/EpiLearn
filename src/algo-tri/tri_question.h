#ifndef TRI_QUESTION_H
#define TRI_QUESTION_H


typedef struct question
{
    int difficulty;
    char* name;

} question;

    
void bubble_sorting(struct question T[], int N);

#endif