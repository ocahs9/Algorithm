#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
  string input;
  while (1)
  {
    stack<char> s;
    bool isNo = false;
    getline(cin, input);
    if (input == ".")
      break;
    for (char c : input)
    {
      if (c == '(' || c == '[')
      {
        s.push(c);
      }
      else if (c == ')' || c == ']')
      {
        if (s.size() < 1)
        {
          isNo = true;
          break;
        }
        if (c == ')')
        {
          if (s.top() == '(')
          {
            s.pop();
            continue;
          }
          else
          {
            isNo = true;
            break;
          }
        }
        else if (c == ']')
        {
          if (s.top() == '[')
          {
            s.pop();
            continue;
          }
          else
          {
            isNo = true;
            break;
          }
        }
      }
    }
    if (s.size())
      isNo = true; // 마지막 문자 처리!
    if (isNo)
      cout << "no" << "\n";
    else
      cout << "yes" << "\n";
  }
  return 0;
}