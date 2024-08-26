#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    char data;
    Node* next;

    Node(char x)
    {
        data = x;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();//every node will be popped
        }
    }

    void push(char data)
    {
        Node* newNode = new Node(data);
        if (isEmpty())
        {
            Node* n = new Node(data);
            top = n;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << "\n";
            return;
        }
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    char peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '\0'; // Return null character if stack is empty
        }
        return top->data;
    }


};

bool isMatchingPair(char character1, char character2)
{
    return (character1 == '(' && character2 == ')') ||
        (character1 == '{' && character2 == '}') ||
        (character1 == '[' && character2 == ']');
}

bool areParenthesesBalanced(const string& expr)
{
    Stack s;

    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.isEmpty() || !isMatchingPair(s.peek(), ch))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }

    return s.isEmpty();
}

int main()
{
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    if (areParenthesesBalanced(expression))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}