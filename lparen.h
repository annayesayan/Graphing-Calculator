#ifndef LPAREN_H
#define LPAREN_H
#include "operator.h"

class Lparen : public Operator  //left parentheses
{
public:
    Lparen ();
    Lparen (string p, TYPES type = LPAREN);

};

#endif // LPAREN_H
