#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int max_x = 51, max_y = 51;
int M, N, K;
int X, Y;
int map[max_y][max_x];
bool visited[max_y][max_x]; 

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int y, int x) {
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (q.size()) {
		pair<int, int> here = q.front(); q.pop();
		y = here.first; x = here.second;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T ;
	for (int i = 0; i < T; i++) {
		memset(map, 0, sizeof(map)); //제대로 동작하는지 확인 필요
		memset(visited, 0, sizeof(visited));
		cin >> M >> N; //N이 세로길이
		cin >> K; //배추가 심어진 위치의 개수
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					BFS(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}