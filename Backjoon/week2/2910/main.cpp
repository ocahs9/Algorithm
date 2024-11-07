#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//특정 숫자가 몇번 나왔는지 알아야 함 + 몇 번째 순서로 나왔는지도 알아야 함
//벡터에 숫자 종류들 집어넣고, key-value pair값으로 하는 map 같은거 사용하면 될 거 같은데..?

int N, C;
int inputs[1001];
map<int, int> f, exist; //f는 빈도수 저장, exist는 해당 값이 나타난 위치 저장
vector<pair<int, int>> v;


bool compare(pair<int, int> a, pair<int, int> b) {
	//first에는 빈도, second에는 해당 값( ~ 1억)
	if (a.first == b.first) {
		return exist[a.second] < exist[b.second]; //오름차순
	}
	return a.first > b.first; //내림차순
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> C ;

	
	for (int i = 0; i < N; i++) {
		cin >> inputs[i];
		f[inputs[i]]++;
		//만약 존재하지 않는다면 (map은 참조만해도 int형은 0, string은 ""로 들어가게 됨)
		if (exist[inputs[i]] == 0) exist[inputs[i]] = i + 1;  // 몇번째에 나왔는지 기록
	}

	//빈도 - 숫자 순서대로 넣기
	for (int i = 0; i < N; i++) {
		v.push_back({ f[inputs[i]], inputs[i] });
	}

	sort(v.begin(), v.end(), compare);
	for (pair<int, int> p : v) {
		cout << p.second << " ";
	}
	
	
	return 0;
}