#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "constant.h"
using namespace  std;


class Token //parent class
{
public:
    Token();
    Token (TYPES type);
    virtual void Print(){}
    int Type();
    friend ostream& operator <<(ostream& outs, Token* t){
        t->Print();
        return outs;
    }
private:
    TYPES _type;
};

#endif // TOKEN_H
