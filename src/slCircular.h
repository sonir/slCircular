
#pragma once

#include "math.h"
#include <iostream>

using namespace std;

typedef struct sl_position {
    
    float x;
    float y;
    
    
} sl_position ;


//Test Perfect Sync?

class slCircular {
    
  public:

    float theta; //theta means rad digree. rad is pirad * PI. 0.5 pirad = 90
    float radius;
    float offset; //Offset in pirad
    float pirad;
    sl_position center; //Center position in xy
    sl_position arc_position; //Now Position in xy

    
    //Constructor1
    slCircular(){   init();    }

    //Constructor2
    slCircular(float got_center_x , float got_center_y, float got_radius){
                
        init();
        setElements(got_center_x, got_center_y, got_radius);

    };

    //Constructor3
    slCircular(float got_center_x , float got_center_y, float got_radius, float got_offset){
                
        setElements(got_center_x, got_center_y, got_radius);
        offset = got_offset;
    };


    void init (){

        //Calc PI
        pi = atan(1.0) * 4.0;
        pirad = 0.f;
        
        //Init Variables
        center.x = 0.f;
        center.y = 0.f;
        arc_position.x = 0.f;
        arc_position.y = 0.f;
        theta = 0.f;
        radius = 1.0f;
        offset = 0.f;

    }

    void setElements(float got_center_x , float got_center_y, float got_radius){

        center.x = got_center_x;
        center.y = got_center_y;
        radius = got_radius;

    }

    

    sl_position piradToPosition(float new_position){

        pirad = new_position;
        //Position means pirad. ex. 1piRad=180, 0.5piPrad=90
        //Convert from pirad to rad (theta)
        theta = (double)(new_position+offset)*PI;
        //Calc X
        arc_position.x = ( (cos(theta)*radius) + center.x );
        //Calc Y
        arc_position.y = ( (sin(theta)*radius) + center.y );

        return arc_position;        
    }


  private:
    double pi;
    
};