#include "rpn.h"
#include <cmath>

RPN::RPN(){}

RPN:: RPN(Queue<Token*> input): _input(input){}

double RPN:: rpn(double value){
    Stack<Number*> s;
    Token* t;  Number* num1; Number* num2;
    Queue<Token*> copy=_input;
    while (!copy.empty()) {
        t=copy.pop();
       if(t->Type()==NUMBER){
           Number* n=static_cast<Number*>(t);
            s.push(n);
       }
       else if(t->Type()==VARIABLE){
           s.push(new Number(value));
       }
       else if(t->Type()==FUNCTION){
           string o= static_cast<Operator*>(t)->OP();
           Number* T;
           if(o=="sin")
             T= new Number(sin(s.pop()->Num()));
           if(o=="cos")
             T= new Number(cos(s.pop()->Num()));
           if(o=="tan")
             T= new Number(tan(s.pop()->Num()));
           if(o=="csc")
             T= new Number((1/sin(s.pop()->Num())));
           if(o=="sec")
             T= new Number((1/cos(s.pop()->Num())));
           if(o=="cot")
             T= new Number((1/tan(s.pop()->Num())));
           s.push(T);
       }
       else{
            num1=s.pop();
            num2=s.pop();
            string o= static_cast<Operator*>(t)->OP();
            Number* T;
            if(o=="+")
                T = new Number(num2->Num()+num1->Num());
            if(o=="-")
                T = new Number(num2->Num()-num1->Num());
            if(o=="*")
                T = new Number(num2->Num()*num1->Num());
            if(o=="/")
                T = new Number(num2->Num()/num1->Num());
            if(o=="^")
                T = new Number(pow(num2->Num(),num1->Num()));
            s.push(T);
        }
    }
    num1=s.pop();
    return num1->Num();
}


