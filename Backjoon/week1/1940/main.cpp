#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#include <cctype>
using namespace std;

int parts[15001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//N : 재료의 개수 , M: 갑옷을 만들기 위한 숫자
	int ret = 0;
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> parts[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (parts[i] + parts[j] == M) ret++;
		}
	}
	cout << ret << "\n";
	
	return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <map>
// //#include <cctype>
// using namespace std;

// int N, M;
// int ret = 0;
// int parts[15001];

// void combi(int start, vector<int>& b) {
// 	if (b.size() == 2) {
// 		if (parts[b[0]] + parts[b[1]] == M) ret++;
// 		return;
// 	}
// 	for (int i = start + 1; i < N; i++) {
// 		b.push_back(i);
// 		combi(i, b);
// 		b.pop_back();
// 	}
// }

// //'그냥 홀수개인 알파벳이 1개여야 한다' 라는 개념으로 축소시킬 수 있음
// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0); cout.tie(0);

// 	//N : 재료의 개수 , M: 갑옷을 만들기 위한 숫자
// 	cin >> N >> M;
	
// 	for (int i = 0; i < N; i++) {
// 		cin >> parts[i];
// 	}

// 	vector<int> b;
// 	combi(-1, b);
// 	cout << ret << "\n";
	
// 	return 0;
// }
