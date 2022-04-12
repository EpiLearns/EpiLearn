#ifndef TRI_QUESTION_H
#define TRI_QUESTION_H


typedef struct question
{
    int difficulty;
    char* question;
    char* answer;

} question;
typedef struct student
{
    int level;
} student;

    
void bubble_sorting(struct question T[], int N);

#endif