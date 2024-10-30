#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string S;
int cnt[26];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> S;
	for (int i = 0; i < S.length(); i++) cnt[S[i] - 'a']++;
	
	for (int i : cnt)
		cout << i << " ";

	return 0;
}