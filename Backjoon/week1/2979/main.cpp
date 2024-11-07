#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int A, B, C;
int carCount[101]; // 1~ 100 사이의 시간대에 차의 개수
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		int from, to;
		cin >> from >> to;
		for (int i = from; i < to; i++) {
			carCount[i]++;
		}

	}
	
	int totalPrice = 0;
	for (int i : carCount) {
		if (i != 1 && i != 2 && i != 3)
			continue;
		else {
			if (i == 1) totalPrice += A*1;
			else if (i == 2) totalPrice += B*2;
			else if (i == 3) totalPrice += C*3;
		}
	}

	cout << totalPrice;

	return 0;
}