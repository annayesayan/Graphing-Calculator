#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iostream>
#include "../Stack_Queue/queue.h"
#include  "../Stack_Queue/stack.h"
#include "shunting_yard.h"
#include "number.h"
#include "rpn.h"
#include "shunting_yard.h"
#include "lparen.h"
#include "rparen.h"
#include "variable.h"
#include "function.h"
#include <stdlib.h>
using namespace std;

class tokenizer
{
public:
    tokenizer();
    tokenizer(char s[]);
    Queue<Token*> infix(); //turn ths char s into a queue of tokens
    double evaluate(double value=0); //calls shunting yard, rpn to solve the equation

private:
    char _s[100];
};

#endif // TOKENIZER_H
