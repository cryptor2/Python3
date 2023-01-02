#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *takeInput_Better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *mergeTwoArrays(Node *head1, Node *head2)
{
    if (head2 == NULL || head1 == NULL)
    {
        if (head1 == NULL)
            return head2;
        else
        {
            return head1;
        }
    }
    else
    {
        Node *p1 = head1;
        Node *p2 = head2;
        Node *dummyNode = new Node(-1);
        Node *p3 = dummyNode;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->data < p2->data)
            {
                p3->next = p1;
                p1 = p1->next;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        if (p1 == NULL && p2 != NULL)
        {
            p3->next = p2;
        }
        else if (p1 != NULL && p2 == NULL)
        {
            p3->next = p1;
        }
        return dummyNode->next;
    }
}

int main()
{
    Node *head = takeInput_Better();
    Node *head2 = takeInput_Better();

    Node *finalhead = mergeTwoArrays(head, head2);
    print(finalhead);
}