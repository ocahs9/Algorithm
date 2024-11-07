#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int alphabet[26]; //해당 알파벳의 개수
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string S;
	getline(cin, S); //띄어쓰기도 포함해서 받는 방법
	
	//그러나 이 코드는 S[i]에 값을 저장하면서 char로 제한해두지 않기 때문에,
    //자동으로 int화되어 정상적으로 계산이 진행된다.
	for (int i = 0; i < S.length(); i++) {
		if (S[i] >= 65 && S[i] < 97) {
			if (S[i] + 13 > 90) S[i] = S[i] + 13 - 26;
			else S[i] = S[i] + 13;
		}
		else if (S[i] >= 97 && S[i] <= 'z') {
			if (S[i] + 13 > 122)S[i] = S[i] + 13 - 26;
			else S[i] = S[i] + 13;
		}
	}
	cout << S << endl;

	return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// using namespace std;

// int alphabet[26]; //해당 알파벳의 개수
// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0); cout.tie(0);

// 	string S;
// 	getline(cin, S); //띄어쓰기도 포함해서 받는 방법
	
// 	//무식하게 더하면 안되는 이유. -> string의 개별 글자는 char이다. 즉, 음수 ~ 양수 범위가 -128 ~127 정도라는 의미이다.
// 	//따라서 나머지 연산을 중간 중간 섞어줘야 한다.
// 	for (int i = 0; i < S.length(); i++) {
// 		//소문자 영어
// 		if ('a' <= S[i] && S[i] <= 'z') {
// 			S[i] = (((S[i] - 'a') + 13) % 26 + 'a');
// 		}
// 		// or 대문자 영어
// 		else if ('A' <= S[i] && S[i] <= 'Z') {
// 			S[i] = (((S[i] - 'A') + 13) % 26 + 'A');
// 		}
// 	}
// 	cout << S << endl;





// 	return 0;
// }