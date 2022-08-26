#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"

class Operator: public Token
{
public:
    Operator();
    Operator(string op, TYPES type = OPERATOR);
    int Precedence();
    string OP();
    void Print();
private:
    int _presedence;
    string _op;
};

#endif // OPERATOR_H
