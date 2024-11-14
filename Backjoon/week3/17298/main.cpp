#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//
int n;
const int max_n = 1000000;
int dp[max_n];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  stack<pair<int, int>> s; // index를 기억해야 함!
  vector<int> v;           // 추후 차례대로 출력할 값들 저장할 컨테이너
  for (int i = 0; i < n; i++)
  {
    int input;
    cin >> input;
    if (s.empty())
    {
      s.push({i, input});
      v.push_back(-1);
    }
    else
    {
      // 크기가 더 큰 값이 들어오면 연속적으로 pop
      while (s.size() && s.top().second < input)
      {
        int index = s.top().first;
        s.pop();
        v[index] = input;
      }
      s.push({i, input});
      v.push_back(-1);
    }
  }

  // 출력
  for (int i : v)
  {
    cout << i << " ";
  }

  return 0;
}