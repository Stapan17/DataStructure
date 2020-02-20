#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;
Node *pre = NULL;

void insertf(int n)
{
    pre = head;
    head = new Node();
    head->data = n;
    head->next = pre;
};

void inserte(int n)
{
    pre = head;
    while (pre->next != NULL)
    {
        pre = pre->next;
    }
    Node *x = new Node();
    x->data = n;
    pre->next = x;
};

void insertm(int m, int n)
{
    pre = head;
    while ((m - 1) > 0)
    {
        pre = pre->next;
        m--;
    }
    Node *x = new Node();
    x->data = n;
    x->next = pre->next;
    pre->next = x;
};

void display()
{
    Node *x = new Node();
    x = head;
    while (x != NULL)
    {
        cout << x->data << " ";
        x = x->next;
    }
};

int main()
{
    insertf(1);
    insertf(2);
    insertf(3);

    insertm(3, 20);

    inserte(1);
    inserte(2);
    inserte(3);
    display();
    return 0;
}