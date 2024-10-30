#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string S, temp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> S;
	temp = S; //깊은 복사 생성자(string 클래스가 알아서 해줌)
	reverse(temp.begin(), temp.end()); //reverse는 기존의 배열의 구조를 바꿈
	if (temp == S) cout << 1;
	else cout << 0;

	return 0;
}