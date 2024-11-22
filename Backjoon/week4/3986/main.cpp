#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
// #include <cctype>
using namespace std;

// 그냥 돌렸을 때 펑펑 터지는 stack을 생각해볼 수 있음
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  int ret = 0;
  for (int i = 0; i < N; i++)
  {
    stack<char> str;
    string input;
    cin >> input;

    for (char c : input)
    {
      // top메서드는 size가 있을때만 동작하므로
      if (str.size() && str.top() == c)
        str.pop();
      else
        str.push(c);
    }
    if (!str.size())
      ret++;
  }

  cout << ret;

  return 0;
}