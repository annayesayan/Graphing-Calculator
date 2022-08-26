#include "shunting_yard.h"
shunting_yard::shunting_yard(){}

shunting_yard:: shunting_yard(Queue<Token*> infix): _infix(infix){}

Queue <Token*> shunting_yard:: postfix(){
    Stack<Operator*> s;

    while(!_infix.empty()){
           Token* t = _infix.pop();
           Operator* o=static_cast<Operator*>(t);
           switch (t->Type()) {
                case NUMBER:
                    _postfix.push(t);
                break;
                case VARIABLE:
                    _postfix.push(t);
                break;
                case OPERATOR:
                   if(s.empty() || s.front()->Precedence() < o->Precedence())
                        s.push(o);
                   else if(!s.empty() && s.front()->Precedence() >= o->Precedence()){
                       _postfix.push(s.pop());
                       s.push(o);
                   }
                break;
                case FUNCTION:
                    s.push(o);
                break;
                case LPAREN:
                    s.push(o);
                break;
                case RPAREN:
                    while (s.front()->Precedence()!=0) {
                        _postfix.push(s.pop());
                    }
                    s.pop();
                break;
           }
    }
    while(!s.empty()){             //pop rest of stack if infix is already empty
         _postfix.push(s.pop());
    }
    //cout<<"_postfix: "<<_postfix<<endl;
    return _postfix;
}
