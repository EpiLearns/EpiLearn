#ifndef CALCULATOR_H
#define CALCULATOR_H

char* suppression(const char *string);

const char* f(char *expression);

void on_button_enter_calculator();

void on_button_clear_calculator();

void on_button_po();

void on_button_pc();

void on_button_star();

void on_button_number9();

void on_button_number8();

void on_button_number7();

void on_button_number6();

void on_button_number5();

void on_button_number4();
void on_button_number3();
void on_button_number2();
void on_button_number1();

void on_button_number0();

void on_button_dot();

void on_button_equal();

void on_button_calculatorplus();

void on_button_calculatorminus();

void on_button_calculatorproduct();

void on_button_calculatorslash();

void on_button_calculatorsuppr();

int open_calculator();
#endif