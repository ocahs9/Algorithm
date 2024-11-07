#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const int max_n = 101, max_m = 101;
int N, M;
int map[max_n][max_m];
int visited[max_n][max_m]; //최단거리 배열

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
			if (ny < 1 || ny > N || nx < 1 || nx > M) continue;
			if (map[ny][nx] && !visited[ny][nx]) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	cin.ignore();  // cin에서 남은 개행 문자를 처리 -> 필수!

	for (int i = 1; i <= N; i++) {
		string line;
		getline(cin, line);
		for (int j = 1; j <= M; j++) {
			map[i][j] = (int)line[j - 1] - (int)'0';
		}
	}

	BFS(1, 1);	
	cout << visited[N][M];
}