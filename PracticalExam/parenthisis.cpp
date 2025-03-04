#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (st.empty())
                return false;
            char top = st.top();
            st.pop();
            if ((str[i] == ')' && top != '(') ||
                (str[i] == '}' && top != '{') ||
                (str[i] == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return st.empty();
}

vector<string> tokenize(string input)
{
    vector<string> ans;
    string token = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
        {
            if (!token.empty())
            {
                ans.push_back(token);
                token = "";
            }
        }
        else
        {
            token += input[i];
        }
    }
    if (!token.empty())
    {
        ans.push_back(token);
    }
    return ans;
}

int main()
{
    string str;
    cout << "Enter a string to check for valid parenthesis: ";
    cin >> str;
    if (isValidParenthesis(str))
    {
        cout << "Valid Parenthesis" << endl;
    }
    else
    {
        cout << "Invalid Parenthesis" << endl;
    }

    vector<string> tokens = tokenize(str);
    cout << "Tokens:" << endl;
    for (const string &token : tokens)
    {
        cout << token << endl;
    }

    return 0;
}
