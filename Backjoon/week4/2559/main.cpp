#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 더 효율적인 방식 (min,max 활용하고, 최소값 절절하게 설정해두기_
// 최소값은 -100 * 10만번 => -1000만
short temp;
int psum[100001], ret = -10000004;
vector<int> cnt;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, K;
  cin >> N >> K;

  for (int i = 1; i <= N; i++)
  {
    cin >> temp;
    psum[i] = temp + psum[i - 1]; // 구간합 누적
  }

  for (int i = K; i <= N; i++)
  {
    ret = max(ret, psum[i] - psum[i - K]);
  }
  cout << ret << "\n";

  return 0;
}