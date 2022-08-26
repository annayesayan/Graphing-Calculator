#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"

class Number: public Token
{
public:
    Number();
    Number(double num);
    void Print();
    double Num();
private:
    double _num;
};

#endif // NUMBER_H
