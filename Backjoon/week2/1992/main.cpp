#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 64;
int N;
int qmap[MAX_N][MAX_N]; //char형식이 아닌 int 형식으로 받음 따라서 string(1, qmap[y][x]) 는 사용불가


//시작 y, 시작 x, size 이렇게 3가지 매개변수만 받도록 수정 
//반환값은 3가지 문자열 형식으로 나뉨 -> 1, 0, (어쩌구)
string divide_conquer(int y, int x, int size) {
	if (size == 1) return to_string(qmap[y][x]); 
	int b = qmap[y][x];
	string ret = "";

	//현재 구역의 값을 전부 돌아보면서, 값이 전부 같은지 파악
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			//값이 다른걸 인식하는 순간, 분할 정복 시작!
			if (b != qmap[i][j]) {
				ret += "(";
				ret += divide_conquer(y, x, size / 2);
				ret += divide_conquer(y, x + size / 2, size / 2);
				ret += divide_conquer(y + size / 2, x, size / 2);
				ret += divide_conquer(y + size / 2, x + size / 2, size / 2);
				ret += ")";

				return ret;
			}
		}
	}
	//값이 전부 같다면 그냥 그 숫자 출력
	return to_string(qmap[y][x]);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	
	//cin으로만 표현할 수도 있다 ! -> getline 사용 x
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line; 
		for (int j = 0; j < line.length(); j++) {
			qmap[i][j] = line[j] - '0';
		}
	}
	
	cout << divide_conquer(0, 0, N) << "\n";
	return 0;
}