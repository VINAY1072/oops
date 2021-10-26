#include <iostream>
using namespace std;

class Area
{
public:
    //friend function declaration
    friend double rectangle(double length, double breadth);
    friend double circle(double radius);
};

inline double rectangle(double length, double breadth)
{
    /* if dimensions are in negative values -1 will be returned */
    if (length > 0 && breadth > 0)
        /* Area of rectangle =  length * breadth */
        return (float)(length * breadth);
    else
        return -1;
}

inline double circle(double radius)
{
    /* if dimensions are in negative values -1 will be returned */
    if (radius > 0)
        /* Area of circle =  π R² */
        return (float)((3.14) * radius * radius);
    else
        return -1;
}

class Volume
{
private:
    double length;
    double breadth;
    double radius;
    double height;

public:
    // Constructor definition
    Volume(double l = 1.0, double b = 1.0, double h = 1.0, double r = 1.0)
    {
        length = l;
        breadth = b;
        height = h;
        radius = r;
    }
    /* volume of cuboid function */
    inline double cuboid(double length, double breadth, double height)
    {
        /* if dimensions are in negative values -1 will be returned */
        if (length > 0 && breadth > 0 && height > 0)
            /* Volume of cuboid = length * breadth * height */
            return (rectangle(length, breadth) * height);
        else
            return -1;
    }
    /* volume of sphere function */
    inline double sphere(double radius)
    {
        /* if dimensions are in negative values -1 will be returned */
        if (radius > 0)
            /* Volume of sphere = 4/3 πR³ */
            return (circle(radius) * (float)(1.33 * radius));
        else
            return -1;
    }
    inline double compare_cuboid(Volume V1, double l, double b, double h, double l1, double b1, double h1)
    {
        /* if dimensions are in negative values -1 will be returned */
        if (this->cuboid(l, b, h) == V1.cuboid(l1, b1, h1))
            return 2;
        else if (l > 0 && b > 0 && h > 0 && l1 > 0 && b1 > 0 && h1 > 0)
            return this->cuboid(l, b, h) > V1.cuboid(l1, b1, h1);
        else
            return -1;
    }
    inline double compare_sphere(Volume V1, double r, double r1)
    {
        /* if dimensions are in negative values -1 will be returned */
        if (this->sphere(r) == V1.sphere(r1))
            return 2;
        else if (r > 0 && r1 > 0)
            return this->sphere(r) > V1.sphere(r1);
        else
            return -1;
    }
};

int main()
{
    Volume V1(1, 1, 1, 1), V2(1, 1, 1, 1);
    int choice;
    double l, r, b, h, l1, r1, b1, h1;
    while (1)
    {
        cout << "****************** NOTE IF '-1' IS RETURNED IT MEANS DIMENSIONS ARE TAKEN IN NEGATIVE VALUES******************"
             << "\n";
        cout << "1. area of rectangle\n2. area of circle\n3. unit area of rectangle\n4. unit area of circle\n5. unit volume of cuboid\n6. unit volume of sphere\n7. volume of cuboid\n8. volume of sphere\n9. compare volume of two cuboids\n10. compare volume of two spheres\n11. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the length"
                 << "\n";
            cin >> l;
            cout << "Enter the breadth"
                 << "\n";
            cin >> b;
            cout << "------Area of the rectangle is :--------"
                 << "\n";
            cout << rectangle(l, b) << "\n";
            break;
        case 2:
            cout << "Enter the radius"
                 << "\n";
            cin >> r;
            cout << "------Area of the circle is :---------"
                 << "\n";
            cout << circle(r) << "\n";
            break;
        case 3:
            cout << "-------Unit Area of the rectangle is :---------"
                 << "\n";
            cout << rectangle(1, 1) << "\n";
            break;
        case 4:
            cout << "--------Unit Area of the circle is :---------"
                 << "\n";
            cout << circle(1) << "\n";
            break;
        case 5:
            cout << "---------Unit Volume of the cuboid is :-----------"
                 << "\n";
            cout << V1.cuboid(1, 1, 1) << "\n";
            break;
        case 6:
            cout << "--------Unit Volume of the sphere is :-----------"
                 << "\n";
            cout << V1.sphere(1) << "\n";
            break;
        case 7:
            cout << "Enter the length"
                 << "\n";
            cin >> l;
            cout << "Enter the breadth"
                 << "\n";
            cin >> b;
            cout << "Enter the height"
                 << "\n";
            cin >> h;
            cout << "----------Volume of the cuboid is :-----------"
                 << "\n";
            cout << V1.cuboid(l, b, h) << "\n";
            break;
        case 8:
            cout << "Enter the radius"
                 << "\n";
            cin >> r;
            cout << "----------Volume of the sphere is :------------"
                 << "\n";
            cout << V1.sphere(r) << "\n";
            break;
        case 9:
            cout << "Enter the length of first cuboid"
                 << "\n";
            cin >> l;
            cout << "Enter the breadth of first cuboid"
                 << "\n";
            cin >> b;
            cout << "Enter the height of first cuboid"
                 << "\n";
            cin >> h;
            V1.cuboid(l, b, h);
            cout << "Enter the length of second cuboid"
                 << "\n";
            cin >> l1;
            cout << "Enter the breadth of second cuboid"
                 << "\n";
            cin >> b1;
            cout << "Enter the height of second cuboid"
                 << "\n";
            cin >> h1;
            V2.cuboid(l1, b1, h1);
            if (V1.compare_cuboid(V2, l, b, h, l1, b1, h1) == 2)
                cout << "=====Both are equal=======\n";
            else if (V1.compare_cuboid(V2, l, b, h, l1, b1, h1))
            {
                cout << "============Volume of first cuboid is greater than Volume of second cuboid=============="
                     << "\n";
            }
            else
                cout << "============Volume of second cuboid is greater than Volume of first cuboid=============="
                     << "\n";
            break;
        case 10:
            cout << "Enter the radius of first sphere"
                 << "\n";
            cin >> r;
            V1.sphere(r);
            cout << "Enter the radius of second sphere"
                 << "\n";
            cin >> r1;
            V2.sphere(r1);
            if (V1.compare_sphere(V2, r, r1) == 2)
                cout << "=====Both are equal=======\n";
            else if (V1.compare_sphere(V2, r, r1))
            {
                cout << "=============Volume of first sphere is greater than Volume of second sphere==============="
                     << "\n";
            }
            else
                cout << "=============Volume of second sphere is greater than Volume of first sphere==============="
                     << "\n";
            break;
        default:
            exit(1);
        }
    }

    return 0;
}