#include <iostream>
using namespace std;

class polynomial
{
    double a, b, c;

public:
    polynomial() // default parameter
    {
        a = 0;
        b = 0;
        c = 0;
    }
    // create a polynomial
    void create(double a_1, double b_1, double c_1)
    {
        a = a_1;
        b = b_1;
        c = c_1;
    }
    // using + operator to add two polynomials
    polynomial operator+(polynomial head_2)
    {
        polynomial h;
        h.a = a + head_2.a;
        h.b = b + head_2.b;
        h.c = c + head_2.c;
        return h;
    }
    // using << operator to display polynomial
    friend ostream &operator<<(ostream &out, polynomial &tm)
    {
        if (tm.a == 0 && tm.b == 0 && tm.c == 0)
        {
            out << "NO POLYNOMIAL\n";
        }
        else
        {
            if (tm.a == 0 && tm.b != 0 && tm.c != 0) // if a=0
                out << tm.b << "x + " << tm.c << "\n";
            else if (tm.b == 0 && tm.a != 0 && tm.c != 0) // if b=0
                out << tm.a << "x^2 + " << tm.c << "\n";
            else if (tm.c == 0 && tm.a != 0 && tm.b != 0) // if c=0
                out << tm.a << "x^2 + " << tm.b << "x + \n";
            else if (tm.a == 0 && tm.b == 0 && tm.c != 0) // a=0 and b=0
                out << tm.c << "\n";
            else if (tm.a == 0 && tm.c == 0 && tm.b != 0) // a=0 and c=0
                out << tm.b << "x\n";
            else if (tm.b == 0 && tm.c == 0 && tm.a != 0) //b=0 and c=0
                out << tm.a << "x^2\n";
            else
                out << tm.a << "x^2 + " << tm.b << "x + " << tm.c << "\n";
        }
        return out;
    }
};

int main()
{
    polynomial head_1, head_2, head_3;
    int choice, list_choice;
    double a, b, c;
    while (1)
    {
        cout << "1. Set Polynomial (a, b, c)\n2. Add Polynomials\n3. Display Polynomial\n4. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "1. create first polynomial\n2. create second polynomial\n";
            cout << "Enter your list choice : ";
            cin >> list_choice;
            if (list_choice == 1)
            {
                cout << "Enter a : ";
                cin >> a;
                cout << "Enter b : ";
                cin >> b;
                cout << "Enter c : ";
                cin >> c;
                head_1.create(a, b, c); // creating first polynomial
            }
            else if (list_choice == 2)
            {
                cout << "Enter a : ";
                cin >> a;
                cout << "Enter b : ";
                cin >> b;
                cout << "Enter c : ";
                cin >> c;
                head_2.create(a, b, c); // creating second polynomial
            }
            break;
        case 2:
            head_3 = head_1 + head_2; // adding two polynomials using + operator
            break;
        case 3:
            cout << "1. show first polynomial\n2. show second polynomial\n3. show third(added) polynomial\n";
            cout << "Enter your list choice : ";
            cin >> list_choice;
            if (list_choice == 1)
            {
                cout << head_1; //printing head1 using << operator
            }
            else if (list_choice == 2)
            {
                cout << head_2; //printing head2 using << operator
            }
            else if (list_choice == 3)
            {
                cout << head_3; //printing head3 using << operator
            }
            break;
        default:
            exit(1);
        }
    }
    return 0;
}