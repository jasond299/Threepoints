// Title: threepoints.cpp
//
// Purpose: read three points determine if they form a line or a triangle
// output information about the line or triangle
//
// 
//
// Author: Jason Djajasasmita
#include <ctime>
#include <string>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;

double Slope(double,double,double,double);
double Length(double, double,double,double);
double Area(double, double,double);
double Perimeter(double, double,double);
double Angle(double, double,double);
int main()
{
    double x1,x2,x3,y1,y2,y3;


    cout << "input point 1:" ;
    cin >> x1;
    cin >> y1;
    cout << "input point 1:";
    cin >> x2;
    cin >> y2;
    cout << "input point 1:";
    cin >> x3;
    cin >> y3;
    double slope1 = Slope(x1,y1,x2,y2);  // calculate slope
    double slope2 = Slope(x2,y2,x3,y3);
    double slope3 = Slope(x1,y1,x3,y3);

    if (isnan(slope1) && isnan(slope2) && isnan(slope3)){ // if all  3 points are the same
           cout << "Infinity Slope "  <<endl;
           return 0;
    }

    else if((x1 == x2 && y1 == y2 )|| (x2 == x3 && y2 == y3) || (x1 == x3 && y1 == y3)){  // if 2 points are the same;
        cout << "A Line" << endl;
        cout << fixed;                      //2 decimal places
        cout << setprecision(2);
        if (x1 == x2 && y1 == y2 ){
            cout << "Slope: "<<slope2 << endl;
            cout << "Length: "<<Length(x2,y2,x3,y3);
        }
        else if (x2 == x3 && y2 == y3){
            cout << "Slope: "<<slope1 << endl;
            cout << "Length: "<<Length(x1,y1,x3,y3);
        }
        else if (x1 == x3 && y1 == y3){
            cout << "Slope: "<<slope1 << endl;
            cout << "Length: "<<Length(x2,y2,x3,y3);
        }
    }
    else if (slope1 == slope2  &&  slope2 == slope3 && slope1 == slope3 || (x1 == x2) && (x2 == x3) ){  // if the 3 slopes are the same or if all x coordinates are equal

        cout << "A Line" << endl;
        cout << fixed;                      //2 decimal places
        cout << setprecision(2);
        if ((x1 == x2) && (x2 == x3)){        //if all x coordinates are the same, slope is infinity
            cout << "Infinity slope" << endl;
        }
        else{
        cout << "Slope:  " << slope1 <<endl;
        }

        double L1 = Length(x1,y1,x2,y2);    //calculate length of all sides
        double L2 = Length(x2,y2,x3,y3);
        double L3 = Length(x1,y1,x3,y3);

        double max = L1;                    // finding the length of the 2 end points of the line to determine the length of the line.
        if (max < L2){
            max = L2;
        }
        if (max < L3){
            max = L3;
        }

        cout << "Length: " << max;

    }

    else{                                 // A triangle case(at least 1 slope is different than the other)
        double L1 = Length(x1,y1,x2,y2);  // length of all sides
        double L2 = Length(x2,y2,x3,y3);
        double L3 = Length(x1,y1,x3,y3);


        cout << "A Triangle" << endl;
        cout << "Sides: " << endl;
        cout << fixed;                    // 2 decimal places
        cout << setprecision(2);
        cout << "  "<< L1 << endl;        //display length of all sides
        cout << "  "<< L2 << endl;
        cout << "  "<< L3 << endl;

        double pi = M_PI;                   // initiallize pi
        double angle1 = Angle(L1,L2,L3);    // calculate the 3 angles
        double angle2 = Angle(L2,L3,L1);
        double angle3 = Angle(L3,L2,L1);
        double angle11= (angle1 * 180)/pi;  // convert to degrees
        double angle22= (angle2 * 180)/pi;
        double angle33= (angle3 * 180)/pi;
        cout << "Angles: " <<endl;
        cout << "  "<< angle1 << " rad " << angle11 << " Degrees" << endl;  //display all interior angles
        cout << "  "<< angle2 << " rad " << angle22 << " Degrees" << endl;
        cout << "  "<< angle3 << " rad " << angle33 << " Degrees" << endl;



        double perimeter = Perimeter(L1,L2,L3);       // calculate perimeter
        cout << "Perimeter: " <<  perimeter << endl;

        double area = Area(L1,L2,L3);                 //calculate area
        cout << "Area:      " << area ;
    }



    return 0;
}

double Slope(double x1, double y1, double x2, double y2 ){  //  (rise/fall)
         double dy = y2 - y1;
         double dx = x2 - x1;
         return dy/dx;
}
double Length(double x1, double y1,double x2,double y2){   // length formula (pythagorean theorem)
         double dy = y2 - y1;
         double dx = x2 - x1;

         double length = sqrt(dy*dy + dx*dx);
         return length;
}

double Perimeter(double L1, double L2,double L3){    // add all length of sides for perimeter

         double P = L1 + L2 + L3;
         return P;

}
double Angle(double L1, double L2 ,double L3){                 //using cosine rule to find the interior angles
         double a = acos( (L2*L2 + L3*L3 - L1*L1)/(2*L2*L3));
         return  a;
}

double Area(double L1, double L2,double L3){           // using Heron's formula to find the area of the triangle
         double x = (L1 + L2 + L3)/2;
         double area = sqrt(x*(x-L1)*(x-L2)*(x-L3));
         return area;
}
