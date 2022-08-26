/* Author: Anna Yesayan
 * Project: Graphing Calculator
 */
#include <iostream>
#include "../Stack_Queue/queue.h"
#include "tokenizer.h"
#include "sidebar.h"
#include "animate.h"
#include <cmath>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    cout<<endl<<endl;

    char c[]="sin ( x ^ 2 )";    //initial equation to start with
    animate a(c);
    a.run();

    cout<<"exiting"<<endl;
    return 0;
}

/*NOTES: - fix so it inputs on sidebar,                 DONE
         - file load,
         - fix the coordinates that show on sidebar
         - clicking from sidebar                        DONE
         - add exceptions / error handling
         - add pi                                       DONE


         - when done, add polar coordinates
         - add linear transformation class
         - add other cool stuff, if time
*/
