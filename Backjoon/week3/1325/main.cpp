#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
const int max_n = 10001;
vector<int> map[max_n];
int visited[max_n];
int cntArr[max_n];
int cnt = 0;

void DFS(int x)
{
  visited[x] = 1;
  cnt++;
  for (int i : map[x])
  {
    if (!visited[i])
      DFS(i);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;

  // map 구성
  for (int i = 0; i < m; i++)
  {
    int c, p;
    cin >> c >> p;
    map[p].push_back(c);
  }

  int maxVal = 0;
  for (int i = 1; i <= n; i++)
  {
    // 그냥 무조건 실행
    DFS(i);
    if (cnt > maxVal)
      maxVal = cnt;
    cntArr[i] = cnt;

    // 초기화 과정
    cnt = 0;
    memset(visited, 0, sizeof(visited));
  }

  // 해당하는 값 출력
  for (int i = 1; i <= n; i++)
  {
    if (maxVal == cntArr[i])
      cout << i << " ";
  }
  return 0;
}