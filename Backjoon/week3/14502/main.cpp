#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

// 실수 했던 부분
// 1. 반복문에서 i,j가 아닌 n,m을 사용한 것
// 2. 제대로 접근 바운더리를 설정하지 않은 것
// 3. nx의 접근 범위를 m이 아닌 n으로 설정한 것
// 4. 초기화 로직을 제대로된 위치로 넣지 않은 것
// 5. copy에 대한 잘못된 사용
int n, m;
const int max_n = 8, max_m = 8;
int map[max_n][max_m];
int visited[max_n][max_m];
int copyMap[max_n][max_m];

vector<pair<int, int>> v; // 벽 세울 후보들

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void DFS(int y, int x)
{ // 바이러스 퍼트리는 로직
  visited[y][x] = 1;
  if (copyMap[y][x] == 0)
  {
    copyMap[y][x] = 2; // 바이러스 감염!
  }

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
      continue;
    if (copyMap[ny][nx] != 1 && !visited[ny][nx])
      DFS(ny, nx);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if (map[i][j] == 0)
        v.push_back({i, j});
    }
  }

  int maxArea = 0;
  // 3개의 벽을 골라 세우는 경우 - 3중 for문 이용
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = i + 1; j < v.size(); j++)
    {
      for (int k = j + 1; k < v.size(); k++)
      {
        // copy(begin(map), end(map), copyMap); //vector, array 와 같은 STL 컨테이너에서만 사용 가능
        memcpy(copyMap, map, sizeof(map));

        pair<int, int> first = v[i];
        pair<int, int> second = v[j];
        pair<int, int> third = v[k];

        copyMap[first.first][first.second] = 1;
        copyMap[second.first][second.second] = 1;
        copyMap[third.first][third.second] = 1;

        for (int y = 0; y < n; y++)
        {
          for (int x = 0; x < m; x++)
          {
            // 방문한 적 없고, 바이러스면 방문
            if (copyMap[y][x] == 2 && !visited[y][x])
              DFS(y, x);
          }
        }
        // 안전 영역 넓이 계산 - 최대값 갱신
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < m; j++)
          {
            if (copyMap[i][j] == 0)
              cnt++;
          }
        }
        if (cnt > maxArea)
          maxArea = cnt;
        memset(visited, 0, sizeof(visited)); // visited 초기화
      }
    }
  }

  cout << maxArea;
  return 0;
}