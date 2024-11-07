#include <iostream>
using namespace std;

int N, M, J;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> J;
	const int screen_size = N;
	const int buket_size = M - 1; //

	int ret = 0;
	int cur_left_pos = 1; //버킷의 시작점
	int cur_right_pos = cur_left_pos + buket_size; //버킷의 끝점
	for (int i = 0; i < J; i++) {
		int drop_pos; //1~N 
		cin >> drop_pos;
		//버킷 범위 바깥쪽일경우 
		if (drop_pos < cur_left_pos) { //왼쪽 바깥일 경우
			ret += cur_left_pos - drop_pos;
			cur_left_pos = drop_pos;
			cur_right_pos = cur_left_pos + buket_size;
		}
		else if (cur_right_pos < drop_pos) { //오른쪽 바깥일 경우
			ret += drop_pos - cur_right_pos;
			cur_right_pos = drop_pos;
			cur_left_pos = cur_right_pos - buket_size;
		}
	}
	cout << ret << "\n";
	return 0;
}