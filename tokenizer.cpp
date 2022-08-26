#include "tokenizer.h"

tokenizer::tokenizer(): _s(){}


tokenizer:: tokenizer(char s[]) {
    strcpy(_s,s);
}

Queue<Token*> tokenizer:: infix(){
    Queue<Token*> _infix;

    char c[100]; strcpy(c,_s); //make a copy

    char* p=strtok(c," ");
    while(p!=NULL){
        string str;
        str = string(p);
        if (str=="+" || str=="-" || str=="*" || str=="/" || str=="^"){
            _infix.push(new Operator(str));
        }
        else if(str== "(")
            _infix.push(new Lparen(str));
        else if(str==")")
            _infix.push(new Rparen(str));
        else if(str== "x")
            _infix.push(new variable(str));
        else if (str== "sin" || str=="cos" || str=="tan" || str=="csc"
                 || str=="sec" || str=="cot")
            _infix.push(new Function(str));
        else if (str=="pi")
            _infix.push(new Number(pi));
        else{
            //cout<<"before pushing number"<<endl;
            _infix.push(new Number(stod(str)));
            //cout<<"     after pushing number"<<endl;
        }
        p=strtok(NULL," ");
    }
    //cout<<"_infix is: "<<_infix<<endl;
    return _infix;
}

double tokenizer:: evaluate(double value){
    shunting_yard s(infix());
    RPN r(s.postfix());
    return r.rpn(value);
}


