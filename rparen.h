#ifndef RPAREN_H
#define RPAREN_H
#include "operator.h"

class Rparen: public Operator  //right parentheses
{
public:
    Rparen();
    Rparen(string p, TYPES type = RPAREN);
};
#endif // RPAREN_H
