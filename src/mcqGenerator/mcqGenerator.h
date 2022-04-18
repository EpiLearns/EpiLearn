#ifndef MCQGENERATOR_H
#define MCQGENERATOR_H

typedef struct Mcq
{
    int question_number;
    int total_time;

    char *question[256];

    char *answer1[256];
    char *answer2[256];

    struct Mcq *next_question;
    struct Mcq *previous_question;

} Mcq;

#endif