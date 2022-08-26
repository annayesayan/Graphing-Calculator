#ifndef LOC_H
#define LOC_H

struct loc{                   // x and y coordinates on the graph
    loc(double _x,double _y){
        x=_x;
        y=_y;
    }
    double x;
    double y;
};

#endif // LOC_H
