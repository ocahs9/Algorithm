#include <iostream>
#include <string>
#include <stack>
using namespace std;

int t;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    stack<char> s;
    string input;
    bool flag = false;
    cin >> input;
    for (char c : input)
    {
      if (c == '(')
        s.push(c);
      else
      {
        if (s.size())
          s.pop();
        else
        {
          flag = true;
          break;
        }
      }
    }
    if (!s.size() && !flag)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }
  return 0;
}