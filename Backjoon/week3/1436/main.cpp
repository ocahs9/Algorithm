#include <iostream>
#include <string>
using namespace std;
// 오히려 별 생각 없이, 문법만 제대로 익히면 풀 수 있는 문제
int n;
int main()
{
  cin >> n;
  int count = 1;
  int start = 666;

  while (1)
  {
    if (n == count)
      break;
    start++;
    string number = to_string(start);
    if (number.find("666") != string::npos)
      count++;
  }

  cout << start;
  return 0;
}