#include <iostream>
#include <cstring>
using namespace std;

const int max_N = 101;
int map[max_N][max_N];
bool visited[max_N][max_N];
int N;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void DFS(int y, int x, const int std) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (map[ny][nx] > std && !visited[ny][nx]) {
			DFS(ny, nx, std);
		}
	}

	return;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int maxHeight = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (maxHeight < map[i][j]) maxHeight = map[i][j];
		}
	}

	//height에 따라 달라지는 잠김 여부 
	int max_cc = 1;
	for (int std = 1; std <= maxHeight; std++) {
		memset(visited, 0, sizeof(visited));
		int cc = 0;
		//모든 노드에 대해 검사
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > std && !visited[i][j]) {
					DFS(i, j, std);
					cc++;
				}
			}
		}
		if (cc > max_cc) max_cc = cc;
	}

	cout << max_cc;
	return 0;
}