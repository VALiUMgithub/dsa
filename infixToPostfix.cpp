#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int operatorPrecedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int calculate(int a, int b, char operatorSign)
{
    if (operatorSign == '+')
        return a + b;
    else if (operatorSign == '-')
        return a - b;
    else if (operatorSign == '*')
        return a * b;
    else if (operatorSign == '/')
        return a / b;
    else if (operatorSign == '^')
        return pow(a, b);
}

string convertInfixToPostfix(string infix)
{
    string postfix = "";
    stack<char> myStack;
    char ch;

    for (int i = 0; infix[i]; i++)
    {
        ch = infix[i];

        if (ch == '(')
            myStack.push(ch);
        else if (ch == ')')
        {
            while (!myStack.empty() && myStack.top() != '(')
            {
                postfix = postfix + myStack.top();
                myStack.pop();
            }

            if (!myStack.empty() && myStack.top() == '(')
                myStack.pop();
        }
        else
        {
            int priority = operatorPrecedence(ch);

            if (priority == 0)
                postfix = postfix + ch;
            else
            {
                if (myStack.empty())
                    myStack.push(ch);
                else
                {
                    while (!myStack.empty() && myStack.top() != '(' && priority <= operatorPrecedence(myStack.top()))
                    {
                        postfix = postfix + myStack.top();
                        myStack.pop();
                    }
                    myStack.push(ch);
                }
            }
        }
    }

    while (!myStack.empty())
    {
        postfix += myStack.top();
        myStack.pop();
    }

    return postfix;
}

int evaluatePostfixExpression(string postfix)
{
    stack<int> myStack;
    char ch;

    for (int i = 0; postfix[i]; i++)
    {
        ch = postfix[i];
        if (ch >= '0' && ch <= '9')
            myStack.push(ch - '0');
        else
        {
            int a, b;
            b = myStack.top();
            myStack.pop();

            a = myStack.top();
            myStack.pop();

            myStack.push(calculate(a, b, ch));
        }
    }

    return myStack.top();
}

int main()
{
    string infixExpression, postfixExpression;
    int result;

    infixExpression = "4+5*2+5";

    postfixExpression = convertInfixToPostfix(infixExpression);

    // cout<<"Infix Expression: "<<infixExpression<<endl;
    // cout<<"Postfix Expression: "<<postfixExpression<<endl;

    result = evaluatePostfixExpression(postfixExpression);

    cout << "\nResult is: " << result << endl;

    return 0;
}
