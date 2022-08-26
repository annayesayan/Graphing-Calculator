#include "system.h"

System::System(){}

System::System(char s[]){
    strcpy(_s,s);
}

void System::draw(sf::RenderWindow& window, loc* origin){
//    cout<<"in system draw"<<endl;
//    cout<<"origin x: "<<endl;
//    cout<<origin->x<<endl;

    sf::RectangleShape line(sf::Vector2f(3,1000));             //draw the y-axis
    line.setPosition(origin->x,0);
    line.setFillColor(sf::Color(105,105,105));
    window.draw(line);
    sf::RectangleShape line2(sf::Vector2f(1000,3));            //draw the x-axis
    line2.setPosition(0,origin->y);
    line2.setFillColor(sf::Color(105,105,105));
    window.draw(line2);

//    for(int i=0; i<=1000; i+=100){                        //draw the dashes on axis
//        sf::RectangleShape line(sf::Vector2f(2,10));
//        line.setPosition(i,500);
//        window.draw(line);
//    }


}

Queue<loc*> System::solve(char s[], int increment, loc* origin){
    //cout<<"solve, increment= "<<increment<<endl;
    tokenizer t1(s);
    Queue<loc*> points;
    //Queue<sf::Vector2f> p;

    for(double i=-50; i<=50; i+=0.004){
        loc* l=new loc(convert(i,t1.evaluate(i),increment,origin));
        points.push(l);
    }
    return points;
}
//Queue<loc*> System::polar(char s[],int increment, loc* origin){
//    tokenizer t1(s);
//    Queue<loc*> points;
//    double theta=0; double val=0;
//    for(double i=0; i<=90; i++){
//        theta= i*(pi/180);
//        loc* l=new loc(convert(t1.evaluate(theta),val,increment,origin));
//        points.push(l);
//        val=i * 0.0222;
//    }
//    //val=2;
//    for(double i=91; i<=180; i++){
//        theta= i*(pi/180);
//        loc* l=new loc(convert(t1.evaluate(theta),val,increment,origin));
//        points.push(l);
//        val=i * 0.0222;
//    }

//    return points;
//}

void System:: plot(sf::RenderWindow& window, char s[],int increment, loc* origin){

    Queue<loc*> p=solve(s, increment, origin);
    //Queue<loc*> p=polar(s, increment, origin);
    while (!p.empty()){
        loc* l=p.pop();
        sf::CircleShape shape(2);
        shape.setFillColor(sf::Color::Cyan);
        shape.setPosition(sf::Vector2f(l->x,l->y));
        window.draw(shape);
    }
}

loc convert(double x, double y, int increment, loc* origin){
    loc l(x*increment+origin->x, origin->y-(y*increment));
    return l;
}
