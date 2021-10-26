#include <iostream>
#include <string>
using namespace std;

// class of sorts
template <class T>
class SORTS
{
    T arr[1000];
    int n;

public:
    // function to swap two elements
    void swap(T *xp, T *yp)
    {
        T temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    // selection sort algorithm
    void Selection_sort(T arr[], int n)
    {
        int i, j, k, l;
        for (i = 0; i < n - 1; i++)
        {
            k = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[k])
                    k = j;
            }
            swap(&arr[k], &arr[i]);
        }
    }
    // function to display the array
    void print_array(T arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << " " << arr[i];
        }
        cout << "\n";
    }
};
int main()
{
    SORTS<int> s1;
    SORTS<float> f1;
    SORTS<char> c1;
    SORTS<double> d1;
    SORTS<string> S1;
    int n, i, choice, sub_choice, flag = 0;
exception:
    try
    {
        cout << "Enter the size of array : ";
        cin >> n;
        if (n <= 0)
        {
            throw n;
        }
    }
    catch (int n)
    {
        cout << "SIZE CANNOT BE ZERO OR NEGATIVE" << endl;
        goto exception;
    }
    int array[n];
    float f_array[n];
    char c_array[n];
    double d_array[n];
    string s_array[n + 1];
    while (1)
    {
        cout << "1. SELECTION SORT(USING INTEGERS ARRAY)\n2. SELECTION SORT(USING FLOAT ARRAY)\n3. SELECTION SORT(USING CHARACTER ARRAY)\n4. SELECTION SORT(USING DOUBLE ARRAY)\n5. SELECTION SORT(USING STRING ARRAY)\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            while (1)
            {
                cout << "1. GET VALUES\n2. SORT\n3. DISPLAY\n4. EXIT\n";
                cout << "Enter your sub choice : ";
                cin >> sub_choice;
                switch (sub_choice)
                {
                case 1:
                    cout << "Enter the integer array : \n";
                    for (i = 0; i < n; i++)
                    {
                        flag = 1;
                        cin >> array[i];
                    }
                    break;
                case 2:
                    if (flag == 0)
                        cout << "----ARRAY IS EMPTY----\n";
                    else
                        s1.Selection_sort(array, n);
                    break;
                case 3:
                    if (flag == 0)
                        cout << "----ARRAY IS EMPTY----\n";
                    else
                        s1.print_array(array, n);
                    break;
                default:
                    exit(1);
                    break;
                }
            }
            break;
        case 2:
            while (1)
            {
                cout << "1. GET VALUES\n2. SORT\n3. DISPLAY\n4. EXIT\n";
                cout << "Enter your sub choice : ";
                cin >> sub_choice;
                switch (sub_choice)
                {
                case 1:
                    cout << "Enter the float array : \n";
                    for (i = 0; i < n; i++)
                    {
                        flag = 1;
                        cin >> f_array[i];
                    }
                    break;
                case 2:
                    if (flag == 0)
                        cout << "----ARRAY IS EMPTY----\n";
                    else
                        f1.Selection_sort(f_array, n);
                    break;
                case 3:
                    if (flag == 0)
                        cout << "----ARRAY IS EMPTY----\n";
                    else
                        f1.print_array(f_array, n);
                    break;
                default:
                    exit(1);
                    break;
                }
            }
            break;
        case 3:
            while (1)
            {
                cout << "1. GET VALUES\n2. SORT\n3. DISPLAY\n4. EXIT\n";
                cout << "Enter your sub choice : ";
                cin >> sub_choice;
                switch (sub_choice)
                {
                case 1:
                    cout << "Enter the char array : \n";
                    for (i = 0; i < n; i++)
                    {
                        flag = 1;
                        cin >> c_array[i];
                    }
                    break;
                case 2:
                    if (flag == 0)
                        cout << "----ARRAY IS EMPTY----\n";
                    else
                        c1.Selection_sort(c_array, n);
                    break;
                case 3:
                    if (flag == 0)
                        cout << "----ARRAY IS EMPTY----\n";
                    else
                        c1.print_array(c_array, n);
                    break;
                default:
                    exit(1);
                    break;
                }
            }
            break;
        case 4:
            while (1)
            {
                cout << "1. GET VALUES\n2. SORT\n3. DISPLAY\n4. EXIT\n";
                cout << "Enter your sub choice : ";
                cin >> sub_choice;
                switch (sub_choice)
                {
                case 1:
                    cout << "Enter the double array : \n";
                    for (i = 0; i < n; i++)
                    {
                        flag = 1;
                        cin >> d_array[i];
                    }
                    break;
                case 2:
                    if (flag == 0)
                        cout << "----ARRAY IS EMPTY----\n";
                    else
                        d1.Selection_sort(d_array, n);
                    break;
                case 3:
                    if (flag == 0)
                        cout << "----ARRAY IS EMPTY----\n";
                    else
                        d1.print_array(d_array, n);
                    break;
                default:
                    exit(1);
                    break;
                }
            }
            break;
        case 5:
            while (1)
            {
                cout << "1. GET VALUES\n2. SORT\n3. DISPLAY\n4. EXIT\n";
                cout << "Enter your sub choice : ";
                cin >> sub_choice;
                switch (sub_choice)
                {
                case 1:
                    cout << "Enter the string array : \n";
                    for (i = 0; i < n; i++)
                    {
                        flag = 1;
                        cin >> s_array[i];
                    }
                    break;
                case 2:
                    if (flag == 0)
                        cout << "----ARRAY IS EMPTY----\n";
                    else
                        S1.Selection_sort(s_array, n);
                    break;
                case 3:
                    if (flag == 0)
                        cout << "----ARRAY IS EMPTY----\n";
                    else
                        S1.print_array(s_array, n);
                    break;
                default:
                    exit(1);
                }
            }
            break;
        default:
            cout << "-----INVALID CHOICE-----\n";
            break;
        }
    }

    return 0;
}