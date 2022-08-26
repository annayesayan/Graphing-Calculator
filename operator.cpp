#include "operator.h"

Operator::Operator(): _presedence(0), _op(0), Token(OPERATOR){}

Operator::Operator(string op, TYPES type): _op(op), Token(type){}

int Operator:: Precedence(){
    if(_op=="(")
        _presedence=0;
    if(_op=="+" || _op=="-")
        _presedence=1;
    if(_op=="*" || _op=="/" || _op=="^")
        _presedence=2;
    if(_op==")")
        _presedence=3;
    if(_op=="sin" || _op=="cos" || _op=="tan" ||
        _op=="csc" || _op=="sec" || _op=="cot")
        _presedence=4;
    return _presedence;
}

string Operator:: OP(){
    return _op;
}

void Operator:: Print(){
    cout<<" "<<_op<<" ";
}

