#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	else {
		return false;
	}
}

void test(const string s) {
	bool isThereVowel = false; //모음이 최소 1개 이상인지
	bool isNoTripleConOrVow = true; //3번 연속 자음 혹은 모음이 안오는지
	bool isNoSeqChar = true; //같은 글자가 연속적으로 두번 안오는지

	
	char prev;
	char cur = s[0];
	if (isVowel(cur)) isThereVowel = true;

	for (int i = 1; i < s.length(); i++) {
		prev = cur;
		cur = s[i];
		if (isVowel(cur)) isThereVowel = true;
		if (cur != 'e' && cur != 'o') {//e도, o도 아닌 경우
			if (prev == cur) isNoSeqChar = false;
		}
		if (i > 1) {
			char pprev = s[i - 2];
			if (isVowel(cur) == isVowel(prev) && isVowel(prev) == isVowel(pprev)) {
				isNoTripleConOrVow = false;
			}
		}
	}

	string ret = "<";
	ret += s; ret += ">"; ret += " is ";
	
	if (isThereVowel && isNoSeqChar && isNoTripleConOrVow) {
		ret += "acceptable.";		
	}
	else {
		ret += "not acceptable.";
	}
	cout << ret << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string password;
	while (cin >> password) {
		if (password == "end") break;
		test(password);
	}
	
	
	return 0;
}