#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    bool Is_empty(Node *head)
    {
        if (head == NULL)
            return true;
        else
            return false;
    }

public:
    // function to add node to a Node
    Node *addNode(Node *head, int val)
    {
        Node *newnode = new Node();
        newnode->data = val;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head; // head is not NULL
            while (temp->next != NULL)
            {
                temp = temp->next; // go to end of Node
            }
            temp->next = newnode; // linking to newnode
        }
        return head;
    }

    void display(Node *head)
    {
        if (Is_empty(head))
        {
            std::cout << "--------list is empty!---------" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << endl;
        }
    }
    Node *operator+(Node &head2)
    {
        if (!this->next)
        {
            this->next = &head2;
            return this;
        }

        // Initialize current and next pointers of
        // both lists
        Node *prev1 = this, *curr1 = this->next;
        Node *prev2 = &head2, *curr2 = prev2->next;

        while (curr1 && prev2)
        {
            /* if prev2 lies in between prev1 and curr1
             then do prev1->prev2->curr1 */
            if ((prev2->data) >= (prev1->data) && (prev2->data) <= (curr1->data))
            {
                curr2 = prev2->next;
                prev1->next = prev2;
                prev2->next = curr1;

                /*let prev1 and prev2 to point
                to their immediate next pointers */
                prev1 = prev2;
                prev2 = curr2;
            }
            else
            {
                // if more nodes in first list update curr1 and prev1 to its next
                if (curr1->next)
                {
                    curr1 = curr1->next;
                    prev1 = prev1->next;
                }

                /* else point the last node of first list
                to the remaining nodes of second list */
                else
                {
                    curr1->next = prev2;
                    return this;
                }
            }
        }
        return this;
    }
    Node *merge(Node *head1, Node *head2)
    {
        if (!head1)
            return head2;
        if (!head2)
            return head1;

        /* start with the linked list
        whose starting data is the lowest 
        if head1 data is less than head2 data */
        if (head1->data < head2->data)
            return *head1 + *head2; // operator + is called b/w head1 and head2
        else
            return *head2 + *head1; // operator + is called b/w head2 and head1
    }
    Node *sort(Node *head)
    {
        Node *curr = head;
        int temp;
        while (curr != NULL)
        {
            Node *prev;
            prev = curr->next;
            while (prev != NULL)
            {
                if (curr->data > prev->data)
                {
                    temp = curr->data;
                    curr->data = prev->data;
                    prev->data = temp;
                }
                prev = prev->next;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main()
{
    Node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    int choice, List_choice, number;
    while (1)
    {
        cout << "1. Insert\n2. Display\n3. Merge\n4. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the list choice [1 Or 2]: ";
            cin >> List_choice;
            cout << "Enter the element  : ";
            cin >> number;
            if (List_choice == 1)
            {
                head1 = head1->addNode(head1, number);
                head1 = head1->sort(head1);
            }
            else if (List_choice == 2)
            {
                head2 = head2->addNode(head2, number);
                head2 = head2->sort(head2);
            }
            break;
        case 2:
            cout << "Enter the list choice [1 Or 2]: ";
            cin >> List_choice;
            if (List_choice == 1)
            {
                head1->display(head1);
            }
            else if (List_choice == 2)
            {
                head2->display(head2);
            }
            break;
        case 3:
            head1 = head1->merge(head1, head2); /* Merging list 2 lists to list 1 */
            head2 = NULL;                       /* initializing second list again to null */
            cout << "List after merging will be \n";
            head1->display(head1);
            break;
        default:
            exit(1);
        }
    }
    // Deallocating the memory using delete
    delete head1;
    delete head2;
    return 0;
}