#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_M = 101, MAX_N = 101;
int map[MAX_M][MAX_N];
int visited[MAX_M][MAX_N];

int M, N, K;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 }; //아... 처음에 이거 잘못 설정해서 제대로 탐색을 못했음

//넓이 반환(이동한 횟수)
int DFS(int y, int x) {
	int area = 1;
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
		//직사각형이 차지하지 않고 있는 지점을 탐색!
		if (map[ny][nx] == 0 && !visited[ny][nx]) {
			area += DFS(ny, nx);
		}
	}
	return area;
}

bool compare(int a, int b) {
	return a < b; //오름차순 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> M >> N >> K;

	//실제 배열은 위,아래로 뒤집힌 상태! - 그래도 로직상 문제 x

	//K개의 직사각형
	for (int i = 0; i < K; i++) {
		int left_below_x, left_below_y;
		int right_above_x, right_above_y;
		cin >> left_below_x >> left_below_y >> right_above_x >> right_above_y;
		for (int row = left_below_y; row < right_above_y; row++) {
			for (int col = left_below_x; col < right_above_x; col++) {
				map[row][col] += 1; //그냥 누적하는 방식으로 구현
			}
		}
	}

	int cc = 0;
	vector<int> areas;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && !visited[i][j]) {
				areas.push_back(DFS(i, j));
				cc++;
			}
		}
	}
	

	sort(areas.begin(), areas.end(), compare);
	cout << cc << "\n";
	for (int area : areas) {
		cout << area << " ";
	}

	return 0;
}