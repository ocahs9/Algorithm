#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
//#include <cctype>
using namespace std;
typedef long long ll;

ll pow(int a, int b, int c) {
	if (b == 1) {
		return a % c;
	}

	ll ret = pow(a, b / 2, c);
	ret = (ret * ret) % c;
	if (b % 2) ret = ret * a % c;
	return ret;
}

//나머지 연산의 활용
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;

	cout << pow(a, b, c);

	return 0;
}