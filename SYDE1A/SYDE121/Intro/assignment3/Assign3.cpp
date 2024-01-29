//SYDE 121 Assignment 3:
//Albert Nguyen-Tran
//Student Number: 21006431
//October 5th, 2022

// Assign3_1.cpp This program illustrates the local and global variables and call-by-value.
// This program computes the side area and the cross section area of a cylinder
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const double PI = 3.14159; // This variable is defined globally, known to all functions in this program as PI
const double conversion = 0.3937; // This is the Cm to inch conversion factor

double area(double r);
double volume(double r);

double area(double r, double h);
double totalArea(double r, double side_area);
double volume(double r, double h);

int main(void)
{
    double r, h; //variables local to the main function
    double side_area, total_area, cylinder_volume; 
    double surface_area, sphere_volume;
    int choice;

    cout << "Enter all numbers in cm, but they will be converted to inches\n";
    cout << "Enter the radius of the shape in cm: \n";
    cin >> r;
    cout << "The radius will be converted into inches";
    r = r * conversion;

    cout << "\nEnter 1 if your shape is a cylinder, 2 if your shape is a sphere: \n";
    cin >> choice;

    if (choice == 1) {
        cout << "\nEnter the height of the cylinder in cm: \n";
        cin >> h;
        cout << "The height will be convered into inches\n";
        h = h * conversion;

        side_area = area(r, h);
        total_area = totalArea(r, side_area);
        cylinder_volume = volume(r, h);

        cout << "\nCYLINDER\n";
        cout << "RADIUS: " << r << "IN HEIGHT: " << h << "IN";
        cout << "\nSIDE AREA: " << side_area;
        cout << "\nTOTAL AREA: " << total_area;
        cout << "\nCYLINDER VOLUME: " << cylinder_volume;


    } else if (choice == 2) {
        surface_area = area(r);
        sphere_volume = volume(r);

        cout << "\nSPHERE\n";
        cout << "RADIUS: " << r << "IN";
        cout << "\nSURFACE AREA: " << surface_area;
        cout << "\nSPHERE VOLUME: " << sphere_volume;

    } else {
        cout << "Invalid Choice\n";
    }
}

//SPHERE

//Sphere surface area overloaded with the name "area"
double area(double r)
{   
    return 4*PI*(r*r);
}

//Sphere volume overloaded with the name "volume"
double volume(double r){
    return (4.0/3.0)*PI*(r * r * r);
}

//CYLINDER

//Cylinder side area overloaded with the name "area" using two parameters instead of one
double area(double r, double h)
{
    return (2*PI*r) * h;
}


double totalArea(double r, double side_area)
{
    return 2*(PI*(r * r)) + side_area;
}


//Cylinder volume overloaded with the name "volume" using two parameters instead of one
double volume(double r, double h)
{
    return (PI*(r * r)) * h;
}