#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "include/stack.h"

using namespace std;

bool isBalanced(string str)
{
    Stack open_blocks = Stack(32);
    char error = 'e';

    map<char, char> pairs;
    pairs[')'] = '(';
    pairs[']'] = '[';
    pairs['}'] = '{';

    for (char c : str)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            open_blocks.append(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (!open_blocks.isEmpty() && open_blocks.peek() == pairs[c])
            {
                open_blocks.pop();
            }
            else
            {
                error = c;
            }
        }
    }

    if (open_blocks.isEmpty() && error == 'e')
        return true;
    else if (error == 'e')
        cout << "Bloco aberto por '" << open_blocks.peek() << "' nao foi fechado" << endl;
    else
        if (open_blocks.isEmpty())
            cout << "Fechamento de bloco '" << error << "' esta incorreto, sem abertura;" << endl;
        else
            cout << "Fechamento de bloco '" << error << "' esta incorreto, a ultima abertura foi '" << open_blocks.peek() << "';" << endl;

    return false;
}

int main()
{
    vector<string> expressions = {
        "(a + b)",
        "{[a * (b + c)]}",
        "a + {b - [c * d]}",
        "a + (b",
        "{[a * b]",
        "(a + b)}",
        "a + {b - [c * d}"};

    for (const string &expression : expressions)
    {
        cout << expression << " - ";

        if (isBalanced(expression))
        {
            cout << "Expressao balanceada!" << endl;
        }
    }

    system("pause");
    return 0;
}