#include "electronic.h"

void init_mcq_et1(Mcq* mcq)
{
    mcq->previous_question = NULL;
    mcq->question_number = 1;

    sprintf(mcq->question,"Que vaut la tension U si l'interrupteur K est ouvert?");

    sprintf(mcq->prop1,"0");
    sprintf(mcq->prop2,"E/2");
    sprintf(mcq->prop3,"E");
    sprintf(mcq->prop4,"-E");
            
    sprintf(mcq->answer1,"E");
    sprintf(mcq->correction,"Correction: E");

    sprintf(mcq->image_path,"../res/qcm1.png");

    mcq->activate_validate_button = 1;
    mcq->already_done = 0;
    mcq->activate_prev_button = 0;
    mcq->activate_next_button = 0;

    ////

    Mcq *tmp = mcq;

    Mcq *next2 = calloc(1,sizeof(Mcq));

    next2->previous_question = tmp;
    tmp->next_question = next2;

    tmp = tmp->next_question;

    tmp->question_number = 2;
    
    sprintf(tmp->question,"Si R1 = R2 = R3 = R4 = R, alors quel est la résistance équivalente?");

    sprintf(tmp->prop1,"Req = 4R");
    sprintf(tmp->prop2,"Req = R");
    sprintf(tmp->prop3,"Req = 5R/3");
    sprintf(tmp->prop4,"Req = 3/R");
            
    sprintf(tmp->answer1,"Req = 5R/3");
    sprintf(tmp->correction,"Correction: Req = 5R/3");
    
    sprintf(tmp->image_path,"../res/qcm2.png");

    tmp->activate_validate_button = 1;
    tmp->already_done = 0;
    tmp->activate_prev_button = 0;
    tmp->activate_next_button = 0;

    ////

    Mcq* next3 = calloc(1,sizeof(Mcq));

    next3->previous_question = tmp;
    tmp->next_question = next3;

    tmp = tmp->next_question;

    tmp->question_number = 3;
    
    sprintf(tmp->question,"Si R2 = R3 = R4 = R et que Req = R, alors que doit valoir R1?");

    sprintf(tmp->prop1,"R1 = R");
    sprintf(tmp->prop2,"R1 = 2R");
    sprintf(tmp->prop3,"R1 = R/3");
    sprintf(tmp->prop4,"R1 = 1/3R");
            
    sprintf(tmp->answer1,"R1 = R/3");
    sprintf(tmp->correction,"Correction: R1 = R/3");
    
    sprintf(tmp->image_path,"../res/qcm2.png");

    tmp->activate_validate_button = 1;
    tmp->already_done = 0;
    tmp->activate_prev_button = 0;
    tmp->activate_next_button = 0;

    ////

    Mcq* next4 = calloc(1,sizeof(Mcq));

    next4->previous_question = tmp;
    tmp->next_question = next4;

    tmp = tmp->next_question;

    tmp->question_number = 4;
    
    sprintf(tmp->question,"Dans le circuit ci-contre, que vaut U ?");

    sprintf(tmp->prop1,"1V");
    sprintf(tmp->prop2,"-1V");
    sprintf(tmp->prop3,"2V");
    sprintf(tmp->prop4,"-2V");
            
    sprintf(tmp->answer1,"-1V");
    sprintf(tmp->correction,"Correction: -1V");
    
    sprintf(tmp->image_path,"../res/qcm3.png");

    tmp->activate_validate_button = 1;
    tmp->already_done = 0;
    tmp->activate_prev_button = 0;
    tmp->activate_next_button = 0;
    
    ////

    Mcq* next5 = calloc(1,sizeof(Mcq));

    next5->previous_question = tmp;
    tmp->next_question = next5;

    tmp = tmp->next_question;

    tmp->question_number = 5;
    
    sprintf(tmp->question,"Quelle est la bonne formule ?");

    sprintf(tmp->prop1,"I1 = 3I/5");
    sprintf(tmp->prop2,"I1 = I/4");
    sprintf(tmp->prop3,"I1 = 3I/4");
    sprintf(tmp->prop4,"I1 = 3RI/4");
            
    sprintf(tmp->answer1,"I1 = I/4");
    sprintf(tmp->correction,"Correction: I1 = I/4");
    
    sprintf(tmp->image_path,"../res/qcm4.png");

    tmp->activate_validate_button = 1;
    tmp->already_done = 0;
    tmp->activate_prev_button = 0;
    tmp->activate_next_button = 0;

    ////

    Mcq* next6 = calloc(1,sizeof(Mcq));

    next6->previous_question = tmp;
    tmp->next_question = next6;

    tmp = tmp->next_question;

    tmp->question_number = 6;
    
    sprintf(tmp->question,"Quel est expression de la tension U ?");

    sprintf(tmp->prop1,"U = (E1+E2)/3");
    sprintf(tmp->prop2,"U = (E1-E2)/3");
    sprintf(tmp->prop3,"U = E1/3 + E2/2");
    sprintf(tmp->prop4,"U = (E1+E2)/3R");
            
    sprintf(tmp->answer1,"U = (E1-E2)/3");
    sprintf(tmp->correction,"Correction: U = (E1-E2)/3");
    
    sprintf(tmp->image_path,"../res/qcm5.png");

    tmp->activate_validate_button = 1;
    tmp->already_done = 0;
    tmp->activate_prev_button = 0;
    tmp->activate_next_button = 0;

    ////

    Mcq* next7 = calloc(1,sizeof(Mcq));

    next7->previous_question = tmp;
    tmp->next_question = next7;

    tmp = tmp->next_question;

    tmp->question_number = 7;
    
    sprintf(tmp->question,"Quelle est la résistance vue entre A et B ?");

    sprintf(tmp->prop1,"3R");
    sprintf(tmp->prop2,"R");
    sprintf(tmp->prop3,"2R/3");
    sprintf(tmp->prop4,"3R/2");
            
    sprintf(tmp->answer1,"3R/2");
    sprintf(tmp->correction,"Correction: 3R/2");
    
    sprintf(tmp->image_path,"../res/qcm6.png");

    tmp->activate_validate_button = 1;
    tmp->already_done = 0;
    tmp->activate_prev_button = 0;
    tmp->activate_next_button = 0;

    ////

    Mcq* next8 = calloc(1,sizeof(Mcq));

    next8->previous_question = tmp;
    tmp->next_question = next8;

    tmp = tmp->next_question;

    tmp->question_number = 8;
    
    sprintf(tmp->question,"Soit le circuit ci-contre. Que vaut U ?");

    sprintf(tmp->prop1,"20V");
    sprintf(tmp->prop2,"4V");
    sprintf(tmp->prop3,"-4V");
    sprintf(tmp->prop4,"-8V");
            
    sprintf(tmp->answer1,"-4V");
    sprintf(tmp->correction,"Correction: -4V");
    
    sprintf(tmp->image_path,"../res/qcm7.png");

    tmp->activate_validate_button = 1;
    tmp->already_done = 0;
    tmp->activate_prev_button = 0;
    tmp->activate_next_button = 0;

    ////

    Mcq* next9 = calloc(1,sizeof(Mcq));

    next9->previous_question = tmp;
    tmp->next_question = next9;

    tmp = tmp->next_question;

    tmp->question_number = 9;
    
    sprintf(tmp->question,"Quelle est la bonne formule ?");

    sprintf(tmp->prop1,"I1 = I/3R");
    sprintf(tmp->prop2,"I1 = 2I/3");
    sprintf(tmp->prop3,"I1 = I/3");
    sprintf(tmp->prop4,"I1 = I/2");
            
    sprintf(tmp->answer1,"I1 = 2I/3");
    sprintf(tmp->correction,"Correction: I1 = 2I/3");
    
    sprintf(tmp->image_path,"../res/qcm8.png");

    tmp->activate_validate_button = 1;
    tmp->already_done = 0;
    tmp->activate_prev_button = 0;
    tmp->activate_next_button = 0;

    ////

    Mcq* next10 = calloc(1,sizeof(Mcq));

    next10->previous_question = tmp;
    tmp->next_question = next10;

    tmp = tmp->next_question;

    tmp->question_number = 10;
    
    sprintf(tmp->question,"Soit le circuit ci-contre: Quelle est l'expression de U ?");

    sprintf(tmp->prop1,"U = RI");
    sprintf(tmp->prop2,"U = E/2");
    sprintf(tmp->prop3,"U = E + I");
    sprintf(tmp->prop4,"U = (E+RI)/2");
            
    sprintf(tmp->answer1,"U = (E+RI)/2");
    sprintf(tmp->correction,"Correction: U = (E+RI)/2");
    
    sprintf(tmp->image_path,"../res/qcm9.png");

    tmp->activate_validate_button = 1;
    tmp->already_done = 0;
    tmp->activate_prev_button = 0;
    tmp->activate_next_button = 0;
}