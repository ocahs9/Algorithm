#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int input[9], sum;
int n = 9, r = 7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < n; i++) { 
		cin >> input[i]; 
	}
	sort(input, input + n);
	do {
		sum = 0;
		for (int i = 0; i < 7; i++) sum += input[i];
		if (sum == 100) {
			//sort(input, input + r);//7개만 출력할거니까
			for (int i = 0; i < 7; i++) cout << input[i] << "\n";
			break;
		}
		
	} while (next_permutation(input, input + n));
	

	return 0;
}