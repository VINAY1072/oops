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
        // newnode creation
        Node *newnode = new Node();
        newnode->data = val;
        newnode->next = NULL;

        // if head is empty starting node will be new node
        if (Is_empty(head))
        {
            head = newnode;
        }
        // else add the node to end of list
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
    //over loading delete function by changing parameters
    Node *addNode(Node *head, int val, int position)
    {
        Node *newnode = new Node();
        newnode->data = val;
        newnode->next = NULL;
        Node *temp = head;
        Node *temp2 = head;
        // if position = 1
        if (position == 1)
        {
            head = newnode;
            head->next = temp;
        }
        else if (position > size(head) + 1 || position < 1)
        {
            cout << "--------position is greater than size of list (or) less than one---------\n";
        }
        // else node is added to the particular position
        else
        {
            while (position != 1)
            {
                temp2 = temp;
                temp = temp->next;
                position--;
            }
            newnode->next = temp;
            temp2->next = newnode;
        }

        return head;
    }
    int deleteNode(Node **head)
    {
        int x;
        Node *curr = *head;
        Node *prev = *head;
        if (*head == NULL)
        {
            std::cout << "---------list is empty--------\n";
            return -1;
        }
        // if head has only one node
        else if (size(*head) == 1)
        {
            *head = curr->next;
            x = curr->data;
            delete curr;
            curr = NULL;
        }
        // else delete node at last
        else
        {
            while (curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            curr->next = NULL;
            x = curr->data;
            delete curr;
            curr = NULL;
            prev->next = NULL;
        }
        // returns deleted element
        return x;
    }
    //over loading delete function by changing parameters
    int deleteNode(Node **head, int p)
    {
        int x;
        Node *curr = *head;
        Node *prev = *head;
        if (*head == NULL)
        {
            std::cout << "---------list is empty--------\n";
            return -1;
        }
        else if (p > size(*head) || p < 1)
        {
            cout << "--------position is greater than size of list (or) less than one---------\n";
            return -1;
        }
        // if position = 1
        else if (p == 1)
        {
            *head = curr->next;
            x = curr->data;
            delete curr;
            curr = NULL;
        }
        // else deletes node at particular position
        else
        {
            while (p != 1)
            {
                prev = curr;
                curr = curr->next;
                p--;
            }
            prev->next = curr->next;
            x = curr->data;
            delete curr;
            curr = NULL;
        }
        return x;
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
    // returns size of list
    int size(Node *head)
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main()
{
    Node *head = NULL;
    int choice, List_choice, number, position;
    while (1)
    {
        cout << "1. Insert At End\n2. Insert At Particular Position\n3. Delete at End\n4. Delete At Particular Position\n5. Display List\n6. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element  : ";
            cin >> number;

            head = head->addNode(head, number);

            break;
        case 2:
            cout << "Enter the element  : ";
            cin >> number;
            cout << "Enter the position  : ";
            cin >> position;
            head = head->addNode(head, number, position);
            break;
        case 3:
            if (head == NULL)
                cout << "--------list is empty!---------" << endl;
            else
            {
                cout << "The deleted last element is :\n";
                cout << head->deleteNode(&head) << "\n";
            }

            break;
        case 4:
            cout << "Enter the position  : ";
            cin >> position;
            if (head == NULL)
                cout << "--------list is empty!---------" << endl;
            else
            {
                cout << "The deleted element at " << position << " position is :\n";
                cout << head->deleteNode(&head, position) << "\n";
            }
            break;
        case 5:
            head->display(head);
            break;
        default:
            exit(1);
        }
    }
    // Deallocating the memory using delete
    delete head;
    return 0;
}