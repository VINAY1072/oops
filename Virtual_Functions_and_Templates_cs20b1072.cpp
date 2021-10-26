#include <iostream>
#include <string>
using namespace std;

template <typename T>

class person
{
protected:
    string name;
    T roll_number;

public:
    person(string name, T roll_number)
    {
        this->name = name;
        this->roll_number = roll_number;
    }
    void display_person()
    {
        cout << "NAME : " << this->name << endl;
        cout << "ROLL NO : " << this->roll_number << endl;
    }
};

class student : virtual protected person<string>
{
protected:
    string course_1, course_2, course_3;

public:
    student(string name, string roll_number, string course_1, string course_2, string course_3) : person(name, roll_number)
    {
        this->course_1 = course_1;
        this->course_2 = course_2;
        this->course_3 = course_3;
    }
    void display_student()
    {
        cout << "NAME : " << this->name << endl;
        cout << "course_1 NAME : " << this->course_1 << endl;
        cout << "course_2 NAME : " << this->course_2 << endl;
        cout << "course_3 NAME : " << this->course_3 << endl;
        cout << "ROLL NO : " << this->roll_number << endl;
    }
};

class research_student : virtual protected person<int>
{
protected:
    string course_1;
    string research_Area;

public:
    research_student(string name, int rollNumber, string course_1, string research_area) : person(name, rollNumber)
    {
        this->course_1 = course_1;
        this->research_Area = research_area;
    }
    void display_research_student()
    {
        cout << "NAME : " << this->name << endl;
        cout << "course_1 NAME : " << this->course_1 << endl;
        cout << "ROLL NO : " << this->roll_number << endl;
        cout << "Research Area : " << this->research_Area << endl;
    }
};

// function to find wheather the courses are unique or not
bool uniqueCourse(string course_1, string course_2, string course_3)
{
    if (course_1 != course_3 && course_2 != course_3 && course_2 != course_1)
        return true;

    else
        return false;
}

class TA : protected student, research_student
{
protected:
    string course_Assigned;
    string role;
    TA *next;

public:
    TA(string name, string rollNumber, string courseAssigned, string role, string course_1, string course_2, string course_3) : student(name, rollNumber, course_1, course_2, course_3), research_student(name, stoi(rollNumber), course_1, "noArea"), person<string>(name, rollNumber), person<int>(name, stoi(rollNumber))
    {
        this->course_Assigned = courseAssigned;
        this->role = role;
    }
    // Parameterised constructor for ta role as a research student
    TA(string name, int rollNumber, string courseAssigned, string role, string course_1, string research_area) : research_student(name, rollNumber, course_1, research_area), student(name, to_string(rollNumber), course_1, "nocourse_2", "nocourse_3"), person<string>(name, to_string(rollNumber)), person<int>(name, rollNumber)
    {
        this->course_Assigned = courseAssigned;
        this->role = role;
    }
    void display_TA_details()
    {
        cout << "------------TEACHING ASSISTANT DETAILS-------------" << endl;
        if (this->role == "s")
        {
            cout << "Name : " << person<string>::name << endl;
            cout << "Roll No : " << person<string>::roll_number << endl;
        }
        else
        {
            cout << "Name : " << person<int>::name << endl;
            cout << "Roll No : " << person<int>::roll_number << endl;
        }
        cout << "Course assigned : " << this->course_Assigned << endl;
        cout << "Role : " << this->role << " " << endl;
    }
    int find_roll_number()
    {
        if (this->role == "s")

            return stoi(person<string>::roll_number);

        else

            return person<int>::roll_number;
    }
    string TA_ROLE()
    {
        return this->role;
    }
    TA *Find_node_via_roll_number(TA *head, int rollNumber)
    {
        if (head == nullptr)
            return nullptr; // if no TA in list
        TA *temp = head;
        while (temp != nullptr)
        {
            if (temp->find_roll_number() == rollNumber)
                return temp; // return node
            temp = temp->next;
        }
        return nullptr; // if input not found
    }

    // function to create the node
    TA *create_node(TA *head, int choice)
    {

        if (choice == 1)
        {
            string name, rollNumber, course_1, course_2, course_3, courseAssigned;
            cout << "Enter the name of TA: ";
            cin >> name;
            while (1)
            {
                cout << "Enter the roll number of " << name << " : ";
                cin >> rollNumber;
                if (stoi(rollNumber) > 0 && this->Find_node_via_roll_number(head, stoi(rollNumber)) == nullptr)
                    break;
                cout << "****************ROLL NUMBER SHOULD BE GREATER THAN ZERO AND DIFFERENT******************" << endl;
            }
            cout << "Enter the Course Assigned for TA: ";
            cin >> courseAssigned;
            while (1)
            {
                cout << "------------COURSES AS STUDENT-------------" << endl;
                cout << "Enter course_1: ";
                cin >> course_1;
                cout << "Enter course_2: ";
                cin >> course_2;
                cout << "Enter course_3: ";
                cin >> course_3;
                if (uniqueCourse(course_1, course_2, course_3))
                    break;
                else
                    cout << "***********COURSES SHOULD BE UNIQUE***********" << endl;
            }
            TA *ptr = new TA(name, rollNumber, courseAssigned, "s", course_1, course_2, course_3);
            ptr->next = nullptr;
            if (head == nullptr)
            {
                head = ptr;
            }
            else
            {
                TA *temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = ptr;
            }
        }
        if (choice == 2)
        {
            string name, course_1, research_area, courseAssigned;
            int rollNumber;
            cout << "Enter the name of TA: ";
            cin >> name;
            while (1)
            {
                cout << "Enter the roll number of " << name << " : ";
                cin >> rollNumber;
                if (rollNumber > 0 && this->Find_node_via_roll_number(head, rollNumber) == nullptr)
                    break;
                cout << "*************ROLL NUMBER SHOULD BE GREATER THAN ZERO AND DIFFERENT**************" << endl;
            }
            cout << "Enter the Course Assigned : ";
            cin >> courseAssigned;
            cout << "---------------COURSES FOR RESEARCH STUDENT---------------" << endl;
            cout << "Enter the course_1: ";
            cin >> course_1;
            cout << "Enter the research area: ";
            cin >> research_area;
            TA *ptr = new TA(name, rollNumber, courseAssigned, "rs", course_1, research_area);
            ptr->next = nullptr;
            if (head == nullptr)
            {
                head = ptr;
            }
            else
            {
                TA *temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = ptr;
            }
        }
        return head;
    }

    // function on person if its roll is in string for s
    void person_details(string s)
    {
        person<string> *ptr;
        person<string> temp = *this;
        ptr = &temp;
        ptr->display_person();
    }

    // function on person if its roll is int for rs
    void person_details(int i)
    {
        person<int> *ptr;
        person<int> temp = *this;
        ptr = &temp;
        ptr->display_person();
    }

    // function on student
    void student_details()
    {
        student *ptr;
        student temp = *this;
        ptr = &temp;
        ptr->display_student();
    }

    // function on research student
    void research_student_details()
    {
        research_student *ptr;
        research_student temp = *this;
        ptr = &temp;
        ptr->display_research_student();
    }
};

int main()
{
    int choices, choice;
    char sub_choice;
    TA *head = nullptr;

    while (1)
    {
        cout << "\n 1. Set TA Details "
             << "\n 2. Display "
             << "\n     a. person  "
             << "\n     b. student  "
             << "\n     c. Research student  "
             << "\n     d. Teaching Assistant "
             << "\n 3. Exit" << endl;
        cout << " Enter Your choice : ";
        cin >> choices;
        switch (choices)
        {
        case 1:
            choice = 1;
            while (1)
            {
                cout << "Choose the role of TA: " << endl;
                cout << "1. student" << endl;
                cout << "2. Research student" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1 || choice == 2)
                    break;
                cout << "*******INVALID CHOICE********" << endl;
            }
            head = head->create_node(head, choice);
            break;
        case 2:
            cout << "Enter your sub choice: ";
            cin >> sub_choice;
            switch (sub_choice)
            {
            case 'a':
            {
                string rollNumber;
                cout << "Enter the roll Number of the person(in integers): ";
                cin >> rollNumber;
                TA *temp = head->Find_node_via_roll_number(head, stoi(rollNumber));
                if (temp == nullptr)
                {
                    cout << "***********EMPTY OR THAT ROLL DOESN'T EXIST***********" << endl;
                }
                else
                {
                    if (temp->TA_ROLE() == "s")
                        temp->person_details("s"); // function overloading with string
                    else
                        temp->person_details(1); // function overloading with int
                }
            }
            break;
            case 'b':
            {
                int rollNumber;
                cout << "Enter the roll Number of the person(in integers): ";
                cin >> rollNumber;
                TA *temp = head->Find_node_via_roll_number(head, rollNumber);
                if (temp == nullptr)
                {
                    cout << "***********EMPTY OR THAT ROLL DOESN'T EXIST***********" << endl;
                }
                else
                {
                    if (temp->TA_ROLE() == "s")
                        temp->student_details();
                    else
                        cout << "***********HE/SHE IS NOT A STUDENT***********" << endl;
                }
            }
            break;
            case 'c':
            {
                int rollNumber;
                cout << "Enter the roll Number of the person(in integers): ";
                cin >> rollNumber;
                TA *temp = head->Find_node_via_roll_number(head, rollNumber);
                if (temp == nullptr)
                {
                    cout << "***********EMPTY OR THAT ROLL DOESN'T EXIST***********" << endl;
                }
                else
                {
                    if (temp->TA_ROLE() == "rs")
                        temp->research_student_details();
                    else
                        cout << "***********HE/SHE IS NOT A RESEARCH STUDENT***********" << endl;
                }
            }
            break;
            case 'd':
            {
                int rollNumber;
                cout << "Enter the roll Number of the person(in integers): ";
                cin >> rollNumber;
                TA *temp = head->Find_node_via_roll_number(head, rollNumber);
                if (temp == nullptr)
                {
                    cout << "***********EMPTY OR THAT ROLL DOESN'T EXIST***********" << endl;
                }
                else
                {
                    temp->display_TA_details();
                }
            }
            break;
            default:
                cout << "***********INVALID SUB CHOICE***********" << endl;
                break;
            }

            break;
        default:
            exit(0);
        }
    }
    return 0;
}