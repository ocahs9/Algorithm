#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#include <cctype>
using namespace std;

// 배열은 인덱스로 바로 접근 가능 : O(1)
// 맵은 O(logN)
string s;
string pokeS[100004];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	//map 2개를 만듬 (역방향 탐색도 빠르게 하기 위함)
	map<string, int> pokeI;

	for (int i = 1; i <= N; i++) {
		cin >> pokeS[i];
		pokeI[pokeS[i]] = i;
	}

	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;
		//c_str은 string을 char * 로 변환해주고, 해당 string이 만약 숫자가 아니었다면 0을 반환
		if(atoi(input.c_str())){ //숫자라면
			cout << pokeS[atoi(input.c_str())] << "\n";
		}
		else { //문자라면
			cout << pokeI[input] << "\n";
		}
	}
	
	return 0;
}