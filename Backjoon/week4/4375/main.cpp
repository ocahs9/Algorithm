#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
// #include <cctype>
using namespace std;
typedef long long ll;

// 종료 조건은 없는건가? 여러개의 테스트 케이스라는게..?
//  eof면 종료한다는 의미로 받아들이기
// 핵심은! '저번의 수' 를 이용한다는 점 -> 따라서 모듈러 연산 적용 가능

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  while (cin >> n)
  {

    int cnt = 1;
    int curNum = 1;
    while (1)
    {
      if (curNum % n == 0)
        break;
      else
      {
        curNum = (curNum * 10) + 1;
        curNum %= n;
        cnt++;
      }
    }

    cout << cnt << "\n";
  }
  return 0;
}