#ifndef ANIMATE_H
#define ANIMATE_H
#include <SFML/Graphics.hpp>
#include "sidebar.h"
#include "constant.h"
#include "system.h"
#include "../Stack_Queue/queue.h"
#include "../Stack_Queue/stack.h"
#include "shunting_yard.h"
#include "number.h"
#include "rpn.h"
#include "shunting_yard.h"
#include "lparen.h"
#include "rparen.h"
#include "variable.h"
#include "tokenizer.h"
#include "loc.h"
#include <stdlib.h>
#include <fstream>

class animate
{
public:
    animate();
    animate(char s[]);
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    void clicked(sf::RenderWindow& window); //checks for positions clicked from sidebar
    bool error(char inp[100]);              //checks for exceptions
private:
    sf::RenderWindow window;
    sf::RectangleShape screen;          //screen rectangle

    Sidebar sidebar;
    System system;
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    sf::RectangleShape rectangle;       //for text box
    bool mouseIn;                       //mouse
    char _s[100];                       //to store char equation
    int increment;
    loc* origin=new loc(500,500);       //origin location
    double x_org=500; double y_org=500; //x and y locations
    int eq_loc=16;                      //position in sidebar to start filling in equations
    bool input=false;                   //used to input function on screen

    sf::String s_func;                  //for input func
    sf::Text func;                      //for input func



};

string mouse_pos_string(sf::RenderWindow& window); //mouse position


#endif // ANIMATE_H
