#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "../Stack_Queue/queue.h"
#include  "../Stack_Queue/stack.h"
#include "token.h"
#include "operator.h"

class shunting_yard
{
public:
    shunting_yard();
    shunting_yard(Queue<Token*> infix);
    Queue <Token*> postfix();       //returns postfix
private:
    Queue <Token*> _infix;
    Queue <Token*> _postfix;
};


#endif // SHUNTING_YARD_H
