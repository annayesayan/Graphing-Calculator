#ifndef SYSTEM_H
#define SYSTEM_H
#include <SFML/Graphics.hpp>
#include "../Stack_Queue/queue.h"
#include "../Stack_Queue/stack.h"
#include "loc.h"
#include "tokenizer.h"
class System
{
public:
    System();
    System(char s[]);
    void draw(sf::RenderWindow& window, loc* origin);          // draws axis
    Queue<loc*> solve(char s[],int increment, loc* origin);    // creates a queue of locations to plot
    void plot(sf::RenderWindow& window, char s[],int increment, loc* origin); //plots the points
    //Queue<loc*> polar(char s[],int increment, loc* origin);
private:
    char _s[100];
};

loc convert(double x, double y, int increment=100, loc* origin=new loc(500,500));
    //converts to apropriate increments, for zoom in/out purposes
#endif // SYSTEM_H
