#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#include <cctype>
using namespace std;

//'그냥 홀수개인 알파벳이 1개여야 한다' 라는 개념으로 축소시킬 수 있음
int cnt[26];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	cin >> input;

	char mid ;
	for (char c : input) {
		cnt[c - 'A']++;
	}
	
	string ret = "";
	int flag = 0;
	//역방향으로 붙여나감
	for (int i = 'Z'-'A'; i >= 'A'-'A'; i--) {
		if (cnt[i] & 1) { //홀수라면
			flag++;
			mid = char('A' + i); 
			//반례 생각! (3개, 5개인 경우에는 붙여주긴 해야함) 
			for (int j = 0; j < cnt[i] - 1; j+=2) {
				ret = char('A' + i) + ret;
				ret += char('A' + i);
			}
		}
		else {
			//짝수라면 2개씩 쓸테니까
			for (int j = 0; j < cnt[i]; j += 2) {
				ret = char('A' + i) + ret;
				ret += char('A' + i);
			}
		}
		if (flag >= 2) break;
	}

	if (flag >= 2) cout << "I'm Sorry Hansoo" << "\n";
	else if(flag == 1) {
		ret.insert(ret.begin() + ret.size() / 2, mid);
		cout << ret << "\n";
	}
	else {
		cout << ret << "\n";
	}
	
	return 0;
}