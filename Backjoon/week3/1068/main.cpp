#include <iostream>
#include <vector>
using namespace std;

/*
  고민한 지점
  1. 자식 노드의 자식 노드들까지 전부 invalid 처리 필요 -> dfs 재귀 호출로 해결
  2. 일자 트리의 경우(map의 size가 0이 아님에도 leaf node일 수 있음) -> 처리 추가
  일자 트리란? 0 -> 1 -> 2 -> 3 -> 4 와 같은 형식
*/

int n;
const int max_n = 50;
vector<int> map[max_n];
int visited[max_n];

// tree라서 loop가 존재하지 않으므로, 별도의 조건 없이 DFS 들어가면 됨
void DFS(int x)
{
  visited[x] = 1;

  if (map[x].size())
  {
    for (int i : map[x])
    {
      DFS(i);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int parentNode = -1;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int p;
    cin >> p;
    // 부모 노드 -> 자식 노드로 향하는 그래프(인접 리스트) 구성
    if (p == -1)
      parentNode = i; // 부모 노드 판단
    else
      map[p].push_back(i);
  }

  // 노드 삭제 로직(실제로는 삭제 x, 방문 처리로 invalid 시킴)
  int removeNode;
  cin >> removeNode;

  int cnt = 0;
  if (parentNode != removeNode)
  {
    // invalid 처리 (방문처리)
    DFS(removeNode);

    // leaf node 판단
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      { // invalid 하지 않고
        if (!map[i].size())
          cnt++; // 해당 map이 비어있으면(==leaf node)
        else
        {
          bool flag = true;
          for (int k : map[i])
          { // 일자 트리에 대한 처리
            if (!visited[k])
            {
              flag = false;
              break;
            }
          }
          if (flag)
            cnt++;
        }
      }
    }
  }
  cout << cnt;
  return 0;
}