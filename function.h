#ifndef FUNCTION_H
#define FUNCTION_H
#include "operator.h"

class Function: public Operator  //sin cos tan...
{
public:
    Function();
    Function(string p, TYPES type=FUNCTION);
};

#endif // FUNCTION_H
