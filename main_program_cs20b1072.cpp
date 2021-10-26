#include <iostream>
using namespace std;

class list
{
    int data;
    list *next;

public:
    //member function to create a newNode
    list *newNode(int n)
    {
        list *temp = new list();
        temp->data = n;
        temp->next = NULL;
        return temp;
    }
    //member function to insert a newNode/value to the list
    void insert(list *head, int num)
    {
        //if the ist is empty
        if (head == NULL)
        {
            head = newNode(num);
        }
        else
        {
            list *temp = head;
            list *ptr;
            ptr = newNode(num);
            //going to the last node of the list
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr; //addding newNode to the list
        }
    }
    //member function to delete a node from the list
    void deleteNode(list *h1, int position)
    {
        if (h1 = NULL)
        {
            cout << "List is empty";
        }
        else
        {
            list *ptr = h1;
            while (--position) //going to the position of node to delete
            {
                ptr = ptr->next;
            }
            if (ptr = h1) //if the deleting node is the head
            {
                h1 = h1->next;
                ptr->next = NULL;
            }
            else
            {
                list *temp;
                temp->next = ptr;
                temp->next = ptr->next; //erasing the position node
                ptr->next = NULL;
            }
        }
    }
    //member function to dispaly
    void display(list *head)
    {
        //if list is empty
        if (head = NULL)
        {
            cout << "List is empty";
        }
        else
        {
            list *temp = head;
            cout << head->data;
            while (temp->next != NULL)
            {
                temp = temp->next;
                cout << "->" << temp->data;
            }
        }
    }
    //member function to merge two lists
    list *merge(list *h1, list *h2)
    {
        list *temp = h1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        //connecting the last node of h1 to first node of h2
        temp->next = h2;
        return h1;
    }
    //member function to sort the list
    list *sort(list *h3)
    {
        list *temp = h3;
        while (temp != NULL)
        {
            list *ptr;
            ptr = temp->next;
            while (ptr != NULL)
            {
                int value;
                if (temp->data > ptr->data)
                {
                    value = temp->data;
                    temp->data = ptr->data;
                    ptr->data = value;
                }
            }
        }
        return h3;
    }
};

int main()
{
    int choice, listNumber, number;
    list *head1, *head2;
    while (1)
    {
        cout << "1.Insert\n2.delete\n3.display\n4.merge\n5.exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter to list number you want enter the element : ";
            cin >> listNumber;
            cout << "enter the number want to enter : ";
            cin >> number;
            if (listNumber == 1)
            {
                head1->insert(head1, number);
            }
            else if (listNumber == 2)
            {
                head2->insert(head2, number);
            }
            break;
        case 2:
            cout << "Enter to list number you want delete the element : ";
            cin >> listNumber;
            cout << "enter the position you want to delete : ";
            cin >> number;
            if (listNumber == 1)
            {
                head1->deleteNode(head1, number);
            }
            else if (listNumber == 2)
            {
                head2->deleteNode(head2, number);
            }
            break;
        case 3:
            cout << "Enter to list number you want enter the display : ";
            cin >> listNumber;
            if (listNumber == 1)
            {
                head1->display(head1);
            }
            else if (listNumber == 2)
            {
                head2->display(head2);
            }
            break;
        case 4:
            head1 = head1->merge(head1, head2);
            head1 = head1->sort(head1);
            break;
        default:
            exit(1);
        }
    }
    return 0;
}
