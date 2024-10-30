#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	string pattern;
	cin >> pattern;

	auto starIdx = pattern.find("*");
	string prefix = pattern.substr(0, starIdx);
	string suffix = pattern.substr(starIdx + 1);

	for (int i = 0; i < N; i++) {
		string filename;
		cin >> filename;

		//반례 (ab*ab와 ab)
		if(prefix.size() + suffix.size() > filename.size()) cout << "NE" << "\n";
		else {
			if (prefix == filename.substr(0, prefix.size()) && suffix == filename.substr(filename.size() - suffix.size()))
				cout << "DA" << "\n";
			else
				cout << "NE" << "\n";
		}
	}
	
	return 0;
}