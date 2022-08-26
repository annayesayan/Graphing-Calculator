#ifndef VARIABLE_H
#define VARIABLE_H
#include "token.h"

class variable: public Token // for x
{
public:
    variable();
    variable(string x, TYPES type = VARIABLE);
    void Print();
private:
    string _x;

};

#endif // VARIABLE_H
