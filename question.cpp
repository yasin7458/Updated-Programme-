#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *head = NULL;

void InsertStart()
{
    int n;

    cout << endl;
    cout << "How Many Value's To Add In List :- ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;

        cout << "Enter The " << i + 1 << " Value :- ";
        cin >> data;

        Node *newNode = new Node();

        newNode->value = data;
        newNode->next = head;

        head = newNode;
    }

    cout << endl;
    cout << "Values Inserted At Start Successfully..." << endl;
}

void InsertEnd()
{
    int n;

    cout << endl;
    cout << "How Many Value's To Add In List :- ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;

        cout << "Enter The " << i + 1 << " Value :- ";
        cin >> data;

        Node *newNode = new Node();

        newNode->value = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    cout << endl;
    cout << "Values Inserted At End Successfully..." << endl;
}

void DeleteStart()
{
    if (head == NULL)
    {
        cout << endl;
        cout << "Linked List Is Empty....!!" << endl;
        return;
    }

    Node *temp = head;

    head = head->next;

    delete temp;

    cout << endl;
    cout << "First Node Deleted Successfully..." << endl;
}

void DeleteEnd()
{
    if (head == NULL)
    {
        cout << endl;
        cout << "Linked List Is Empty..." << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;

        head = NULL;

        cout << endl;
        cout << "Last Node Deleted Successfully..." << endl;

        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = NULL;

    cout << endl;
    cout << "Last Node Deleted Successfully..." << endl;
}

void DisplayData()
{
    if (head == NULL)
    {
        cout << endl;
        cout << "Linked List Is Empty..." << endl;
        return;
    }

    Node *temp = head;

    cout << endl;
    cout << "Linked List :- ";

    while (temp != NULL)
    {
        cout << temp->value << " -> ";

        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void ReverseLinkedList(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }

    ReverseLinkedList(temp->next);

    cout << temp->value << " -> ";
}

void CountNode()
{
    int count = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        count++;

        temp = temp->next;
    }

    cout << endl;
    cout << "Total Nodes Are :- " << count << endl;
}

void Update()
{
    if (head == NULL)
    {
        cout << endl;
        cout << "Linked List Is Empty..." << endl;
        return;
    }

    int oldValue, newValue;

    cout << endl;
    cout << "Enter The Old Value :- ";
    cin >> oldValue;

    cout << "Enter The New Value :- ";
    cin >> newValue;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->value == oldValue)
        {
            temp->value = newValue;

            cout << endl;
            cout << "Value Updated Successfully..." << endl;

            return;
        }

        temp = temp->next;
    }

    cout << endl;
    cout << "Value Isn't Found..." << endl;
}

int main()
{
    while (true)
    {
        cout << endl;
        cout << "====== WELCOME TO OUR LINKED LIST PROGRAM ======" << endl;

        cout << endl;
        cout << "1. InsertStart" << endl;
        cout << "2. InsertEnd" << endl;
        cout << "3. DeleteStart" << endl;
        cout << "4. DeleteEnd" << endl;
        cout << "5. DisplayData" << endl;
        cout << "6. ReverseLinkedList" << endl;
        cout << "7. Count Node" << endl;
        cout << "8. Update" << endl;
        cout << "9. Exit" << endl;

        int choice;

        cout << endl;
        cout << "Enter Your Choice :- ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            InsertStart();

            break;

        case 2:

            InsertEnd();

            break;

        case 3:

            cout << endl;
            cout << "Before DeleteStart Program :- ";

            DisplayData();

            DeleteStart();

            cout << endl;
            cout << "After DeleteStart Program :- ";

            DisplayData();

            break;

        case 4:

            cout << endl;
            cout << "Before DeleteEnd Program :- ";

            DisplayData();

            DeleteEnd();

            cout << endl;
            cout << "After DeleteEnd Program :- ";

            DisplayData();

            break;

        case 5:

            DisplayData();

            break;

        case 6:

            if (head == NULL)
            {
                cout << endl;
                cout << "Linked List Empty Chhe..." << endl;
            }
            else
            {
                cout << endl;
                cout << "Original Linked List :- ";

                DisplayData();

                cout << endl;
                cout << "Reversed Linked List :- ";

                ReverseLinkedList(head);

                cout << "NULL" << endl;
            }

            break;
            break;

        case 7:

            CountNode();

            break;

        case 8:

            cout << endl;
            cout << "Before Update Program :- ";

            DisplayData();

            Update();

            cout << endl;
            cout << "After Update Program :- ";

            DisplayData();

            break;

        case 9:

            cout << endl;
            cout << "Program Exit..." << endl;

            return 0;

        default:

            cout << endl;
            cout << "Invalid Choice..." << endl;
        }
    }

    return 0;
}