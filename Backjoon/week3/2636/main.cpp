#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
const int max_n = 100, max_m = 100;
int map[max_n][max_m];
int visited[max_n][max_m];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<pair<int, int>> v;
void DFS(int y, int x)
{
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
      continue;
    if (!visited[ny][nx] && map[ny][nx] == 0)
    { // 방문한 적 없는 빈 공간
      DFS(ny, nx);
    }
    else if (!visited[ny][nx] && map[ny][nx] == 1)
    { // 방문한 적 없는 치즈라면
      visited[ny][nx] = 1;
      v.push_back({ny, nx});
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int time = 0;
  int vsize = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
    }
  }

  // visitied는 설정되어 있는데, map값은 1인 곳? -> 다음 한 시간 뒤에 없어질 곳
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!visited[i][j] && map[i][j] == 0)
      {
        DFS(i, j);

        for (auto i : v)
        { // c로 점철된 부분 녹임
          map[i.first][i.second] = 0;
        }
        // 다 초기화해야 정상적으로 접근(치즈 부분) -> 대신 모든 지점을 다 방문하게 됨
        memset(visited, 0, sizeof(visited));

        if (v.size())
        { // 유효한 접근(치즈가 남아있을 때 접근)일 때 필요한 조치
          vsize = v.size();
          time++;
        }
        v.clear();
      }
    }
  }

  cout << time << endl;
  cout << vsize << endl;

  return 0;
}