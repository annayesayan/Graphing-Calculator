#include "variable.h"

variable::variable(): _x(0), Token(VARIABLE){}

variable::variable(string x, TYPES type): _x(x), Token(VARIABLE){}

void variable:: Print(){
    cout<<" "<<_x<<" ";
}
