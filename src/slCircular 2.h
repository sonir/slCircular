
//#define PI 3.14159265
#include "math.h"
#include <iostream>
using namespace std;

typedef struct sl_position {
    
    float x;
    float y;
    
    
} sl_position ;


class slCircular {

    
  public:

    float theta; //theta means rad digree. rad is pirad * PI. 0.5 pirad = 90
    float radius;

    slCircular(){
        
        
        //Calc PI
        pi = atan(1.0) * 4.0;
        
        //Init Variables
        center.x = 0.;
        center.y = 0.;
        arc_position.x = 0.;
        arc_position.y = 0.;
        theta = 0.;
        radius = 1.0;


//        cout << "0.5 * PI =" << 0.5*PI << endl;
//        cout << "--" << endl;

//        cout << cos(0.) << endl;
//        cout << cos(1.5707963267948966) << endl;
//        cout << cos(3.141592653589793) << endl;

        //Setup Pi
        cout << "pi =" << pi << endl;

        //Set Deg
        float dig = 90.;
        cout << "degree is " << dig << endl;
        
        //Set Rad
        theta = (dig/180.)*pi;
        cout << "theta is " << theta << endl;

        //Calc Cos
        float cosval = (float)cos((float)theta);
        cout << cosval << endl;
        printf("%f\n",cosval);
        
        double cosval2 = cos((float)theta);
        cout << cosval2 << endl;
        
        
//        cout << cos(1.570) << endl;
        //If the value less than more 3points flow , the valus has problem.
        
//        cout << "--" << endl;
//        cout << sin(0.*PI) << endl;
//        cout << sin(1.5707963267948966) << endl;
//        cout << sin(3.141592653589793) << endl;

        
        
    };
    
    sl_position piradToPosition(float new_position){
        
        //Position means pirad. ex. 1piRad=180, 0.5piPrad=90
        //Convert from pirad to rad (theta)
        theta = (double)new_position*PI;
        //Calc X
        arc_position.x = ( (cos(theta)*radius) + center.x );
        //Calc Y
        arc_position.y = ( (sin(theta)*radius) + center.y );
        
        return arc_position;
        
    }

    
  private:
    sl_position center; //Center position in xy
    sl_position arc_position; //Now Position in xy
    double pi;

    
};