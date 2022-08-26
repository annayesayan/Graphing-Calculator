#include "number.h"

Number::Number() : _num(0), Token(NUMBER){}

Number::Number(double num): _num(num), Token(NUMBER){}

void Number:: Print(){
    cout<< " "<<_num<<" ";
}

double Number:: Num(){
    return _num;
}

