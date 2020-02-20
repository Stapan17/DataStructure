#include <iostream>
using namespace std;

#define max 10

class stack
{
    int n;

public:
    int a[max];
    stack()
    {
        n = -1;
    }
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void display();
};

void stack::push(int x)
{
    if (n >= (max - 1))
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        a[++n] = x;
        cout << x << " is pushed in stack at" << endl;
    }
}

int stack::pop()
{
    if (n < 0)
    {
        cout << "stack underflow" << endl;
        return 0;
    }
    else
    {
        int x = a[n--];
        return x;
    }
}

int stack::peek()
{
    if (n < 0)
    {
        cout << "stack is empty " << endl;
        return 0;
    }
    else
    {
        int x = a[n];
        return x;
    }
};

bool stack::isEmpty()
{
    return (n < 0);
};

void stack::display()
{
    for (int i = 0; i <= n; i++)
        cout << a[i] << " ";
}

int main()
{
    class stack s;
    s.push(1);
    s.push(2);
    s.display();
    cout << "\n";
    s.pop();
    s.isEmpty();

    s.display();
    return 0;
}