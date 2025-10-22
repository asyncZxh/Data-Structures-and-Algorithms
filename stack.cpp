#include <iostream>

const int maxSize = 10;
int stack[maxSize] = {};
int top = -1;

bool isFull();
bool isEmpty();
void push(int);
void pop();
int peek();
void printStack();

int main()
{
    push(1);
    push(3);
    push(7);
    push(12);
    push(18);
    push(26);
    push(38);
    push(49);
    push(57);
    push(98);
    printStack();

    std::cout << "Top Data: " << peek() << std::endl
              << std::endl;
    std::cout << "is Full: " << std::boolalpha << isFull() << std::endl
              << std::endl;
    std::cout << "is Empty: " << std::boolalpha << isEmpty() << std::endl
              << std::endl;

    pop();
    pop();
    pop();
    printStack();

    std::cout << "Top Data: " << peek() << std::endl
              << std::endl;
    std::cout << "is Full: " << std::boolalpha << isFull() << std::endl
              << std::endl;
    std::cout << "is Empty: " << std::boolalpha << isEmpty() << std::endl
              << std::endl;

    return 0;
}

bool isFull()
{
    if (top == maxSize - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

void push(int data)
{
    if (!isFull())
    {
        stack[++top] = data;
        return;
    }
    std::cout << "full cannot add more data" << std::endl;
}

void pop()
{
    if (!isEmpty())
    {
        stack[top--] = 0;
        return;
    }
    std::cout << "empty cannot delete more data" << std::endl;
}

int peek()
{
    if (!isEmpty())
    {
        return stack[top];
    }
    std::cout << "Stack is empty, nothing to peek ";
    return false;
}

void printStack()
{
    std::cout << "[ ";
    for (int i{0}; i <= top; i++)
    {
        std::cout << stack[i] << (i < top ? ", " : "");
    }
    std::cout << " ]" << std::endl
              << std::endl;
}