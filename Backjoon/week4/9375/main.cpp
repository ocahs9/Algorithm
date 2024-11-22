#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
// #include <cctype>
using namespace std;

// 각 종류 의류의 개수 + 1(안 입는 경우의 수) 를 활용하는 방식
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t; // test case
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    // 매번 초기화 되어야 하니까 for 반복문 안에 존재해야 함
    map<string, int> v; // 아무값이 없으면 0이었음

    long long caseCount = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      string a, b; // a는 사실 중요하지 않음 (사용 안함)
      cin >> a >> b;
      v[b]++;
    }

    for (auto c : v)
    {
      caseCount *= (c.second + 1);
    }
    caseCount -= 1;
    cout << caseCount << "\n";
  }

  return 0;
}