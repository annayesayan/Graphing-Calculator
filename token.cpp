#include "token.h"

Token::Token(): _type(TOKEN){}

Token:: Token (TYPES type): _type(type){}

int Token:: Type(){
    return _type;
}

