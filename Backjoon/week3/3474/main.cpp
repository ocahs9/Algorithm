#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 맨 뒤 0의 개수 = 10의 곱셈 횟수
// 10의 곱셈 횟수 = min(2의 곱셈 횟수, 5의 곱셈횟수)
int t;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int n;
    cin >> n;
    // 살짝 도식화 해보면
    /*
      1 2 3 4 5 6 7 8 9 10
    2     1   1   1   1    1
    4         1       1
    8                 1
    */
    // 이런 형식이니까 오히려 2의 승수(혹은 5의 승수)로 나누어서 쉽게 구할 수 있겠다!
    int two = 0;
    int five = 0;
    for (int i = 2; i <= n; i *= 2)
    {
      two += n / i;
    }

    for (int i = 5; i <= n; i *= 5)
    {
      five += n / i;
    }

    cout << min(two, five) << "\n";
  }
  return 0;
}