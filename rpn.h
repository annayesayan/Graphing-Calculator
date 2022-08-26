#ifndef RPN_H
#define RPN_H
#include "token.h"
#include "number.h"
#include "operator.h"
#include "../Stack_Queue/queue.h"
#include  "../Stack_Queue/stack.h"

class RPN
{
public:
    RPN();
    RPN(Queue<Token*> input);
    double rpn(double value=0);   //calculates the result of a postfix Queue
private:
    Queue<Token*> _input;
};



#endif // RPN_H
