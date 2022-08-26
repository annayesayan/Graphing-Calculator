#include "animate.h"
#include <iostream>
using namespace std;

animate::animate():sidebar(WORK_PANEL, SIDE_BAR)
{
    cout<<"animate CTOR: TOP"<<endl;

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Anna's Graphing Calculator!");
    window.setFramerateLimit(1000);

    mouseIn = true;
    system=System();
    increment=100;

    rectangle.setSize(sf::Vector2f(100.f, 100.f));
    rectangle.setPosition(sf::Vector2f(500,200));
    rectangle.setFillColor(sf::Color::White);


    cout<<"Geme CTOR. preparing to load the font."<<endl;

    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    func=sf::Text("function",font);
    func.setCharacterSize(60);
    func.setStyle(sf::Text::Bold);
    func.setColor(sf::Color::Cyan);
    func.setPosition(sf::Vector2f(400,200));

    myTextLabel = sf::Text("Initial String for myTextLabel", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));

    cout<<"animate instantiated successfully."<<endl;
}

animate::animate(char s[]): sidebar(WORK_PANEL, SIDE_BAR){
    //cout<<"animate CTOR: TOP"<<endl;
    strcpy(_s,s);
    //------------------------------------------

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Anna's Graphing Calculator!");
    window.setFramerateLimit(60);


    mouseIn = true;

    system=System(_s);
    increment=100;
    sidebar[3]="////////";
    sidebar[4]="sin ( cos ( tan ( 1 / x ) ) )"; sidebar[5]="cos ( x )"; sidebar[6]="tan ( x )";
    sidebar[7]="sin ( x ^ 2 )"; sidebar[8]="cos ( x ^ 2 )"; sidebar[9]="tan ( x ^ 2 )";
    sidebar[10]="tan ( x ) / tan ( 20 * x )";
    sidebar[11]="sin ( cos ( x ) )";
    sidebar[12]="sin ( cos ( 1 / x ) )";
    sidebar[13]="cot ( x )";
    sidebar[14]="csc ( x )";
    sidebar[15]="sec ( x )";
    sidebar[16]="sin ( cos ( tan ( 1 / x ) ) )";

    rectangle.setSize(sf::Vector2f(500.f, 100.f));
    rectangle.setPosition(sf::Vector2f(100,100));
    rectangle.setFillColor(sf::Color(105,105,105));

    screen.setSize(sf::Vector2f(1000.f, 1000.f));
    screen.setPosition(sf::Vector2f(0,0));
    screen.setFillColor(sf::Color::White);

    //cout<<"Geme CTOR. preparing to load the font."<<endl;

    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    func=sf::Text("F(s) = ",font);
    func.setCharacterSize(30);
    func.setStyle(sf::Text::Bold);
    func.setColor(sf::Color::Cyan);
    func.setPosition(sf::Vector2f(110,110));


    myTextLabel = sf::Text("graphing calculator", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setColor(sf::Color::Cyan);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));

    //cout<<"animate instantiated successfully."<<endl;

}

void animate::Draw(){
    window.draw(screen);
    system.draw(window,origin);
    system.plot(window,_s,increment,origin);

    if(input){
        window.draw(rectangle);
        window.draw(func);
    }

    sidebar.draw(window);
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}


void animate::update(){

    //cause changes to the data for the next frame
    if ( mouseIn){
        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
    }
}

void animate::render(){
       window.clear();
       Draw();
       window.display();
}

void animate::processEvents()
{
   //cout<<"Animate processEvents() is getting called!"<<endl;

   sf::Event event;
   float mouseX, mouseY;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code){
                case sf::Keyboard::Left:
                   sidebar[SB_KEY_PRESSED] = "LEFT";
                   x_org+=10;
                   origin=new loc(x_org,y_org);
                   break;
               case sf::Keyboard::Right:
                   sidebar[SB_KEY_PRESSED] = "RIGHT";
                   x_org-=10;
                   origin=new loc(x_org,y_org);
                   break;
               case sf::Keyboard::Up:
                   sidebar[SB_KEY_PRESSED] = "UP";
                   y_org+=10;
                   origin=new loc(x_org,y_org);
                   break;
               case sf::Keyboard::Down:
                   sidebar[SB_KEY_PRESSED] = "Down";
                   y_org-=10;
                   origin=new loc(x_org,y_org);
                   break;
               case sf::Keyboard::Escape:
                   sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
               case sf::Keyboard::Enter:
                   sidebar[SB_KEY_PRESSED] = "ZOOM IN";
                   increment+=10;
                   break;
               case sf::Keyboard::RShift:
                   sidebar[SB_KEY_PRESSED] = "ZOOM OUT";
                   increment-=10;
                   break;
               case sf::Keyboard::R:
                   sidebar[SB_KEY_PRESSED] = "RESET";
                   increment=100;
                   origin=new loc(500,500);
                   break;
               case sf::Keyboard::F:
                   if(input==false)
                       input=true;
                   else{
                       input=false;
                       string eq=func.getString();
                       cout<<"eq: "<<eq<<endl;
                       char inp[eq.length()];
                       strcpy(inp, eq.c_str());
                       if(!error(inp)){
                           eq_loc++;
                           sidebar[eq_loc] = eq;
                           strcpy(_s,inp);
                           sidebar[SB_KEY_PRESSED]="<---Your Graph";
                       }else
                           sidebar[SB_KEY_PRESSED]= "FUNCTION INVALID";


//                       ofstream outfile;
//                       outfile.open("functions.txt");
//                       if (outfile.fail()){
//                           cout<<"failed to open"<<endl;
//                       }else{
//                           outfile<<sidebar[eq_loc]<<endl;
//                       }
//                       outfile.close();

                   }
                   break;
               }
               break;
            //text Entered
           case sf::Event::TextEntered:

               if(input==true){
                   cout<<"text has been entered"<<endl;
                   if(event.text.unicode >=32 && event.text.unicode <=126 && event.text.unicode !=102)
                        s_func+= (char)event.text.unicode;
                   else if(event.text.unicode==8 && s_func.getSize()>0)
                       s_func.erase(s_func.getSize()-1,s_func.getSize());

                   func.setString(s_func);
               }
               break;
           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
               mouseX = event.mouseMove.x;
               mouseY = event.mouseMove.y;

               break;
           case sf::Event::MouseButtonReleased:
                   if (event.mouseButton.button == sf::Mouse::Right ||
                           event.mouseButton.button == sf::Mouse::Left)
                   {
                       sidebar[SB_MOUSE_CLICKED] = "CLICK " +
                               mouse_pos_string(window);
                       clicked(window);
                       cout<<"_s: "<<_s<<endl;
                   }
                   break;

               default:
                   break;
           }
       }
}

void animate::run()
{
   cout<<"Animate run() is being called!"<<endl;

   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}


string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}

void animate::clicked(sf::RenderWindow& window){      //checks on which function is clicked
    int j=0;
    for (int i=4; i<30; i++){
        if(sf::Mouse::getPosition(window).x>=960 && sf::Mouse::getPosition(window).x <=1200
           && sf::Mouse::getPosition(window).y >=110+j && sf::Mouse::getPosition(window).y<=130+j){
            cout<<"sidebar["<<i<<"] = "<<sidebar[i]<<endl;
            if(sidebar[i]!=""){
                string s =sidebar[i];
                char inp[s.length()];
                strcpy(inp, s.c_str());
                strcpy(_s,inp);
                sidebar[SB_KEY_PRESSED]="<---Your Graph";
                break;
            }
        }
        j+=30;
    }
}

bool animate::error(char inp[]){           //for invalid equations
    tokenizer t(inp);
    Queue<Token*> q =t.infix();

    bool error=false;
    while (!q.empty() && error==false) {   //checks for equation to be in right order
        Token* t=q.pop();
        if(!q.empty()){
            Token* next=q.pop();
            //cout<<t<<" "<<next<<endl;
            if((t->Type()==NUMBER || t->Type()==VARIABLE) && (next->Type()==OPERATOR || next->Type()==RPAREN)
                    ){
                error=false;
                cout<<"correct"<<endl;
            }
            else if((t->Type()==OPERATOR || t->Type()==LPAREN) && (next->Type()==NUMBER || next->Type()==VARIABLE)
                    ){
                error=false;
                cout<<"op first, correct"<<endl;

            }
            else if(((t->Type()==OPERATOR || t->Type()==FUNCTION)&& next->Type()==LPAREN) ||
                    (t->Type()==RPAREN && next->Type()==OPERATOR)){
                error=false;
                cout<<"correct"<<endl;
            }else{
                cout<<"Incorrect: "<<t<<next<<endl;
                error=true;
            }
        }
    }

    Queue<Token*> temp =t.infix();
    while(error==false && !temp.empty()){   //checks for parentheses to match
        Token* token=temp.pop();
        if(token->Type()==LPAREN){
            while (token->Type()!=RPAREN && !temp.empty()) {
                token=temp.pop();
            }
            if(token->Type()!=RPAREN){
                cout<<"missing a right parentheses"<<endl;
                error=true;
            }
        }
        else if(token->Type()==RPAREN){
            cout<<"missing a left parentheses"<<endl;
            error=true;
        }
    }
    return error;
}












