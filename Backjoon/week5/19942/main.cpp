#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n;
int mp,mf,ms,mv;

vector<int> p;
vector<int> f;
vector<int> s;
vector<int> v;
vector<int> c;

int accP =0;
int accF =0;
int accS =0;
int accV =0;
int accC =0;

int totalCount = 0;
int resultC = 999999999;
vector<int> resultV;

//시작은 항상 num == 0부터
void minCost(int num){
    if(totalCount >= resultC) return; //최소값이 아니니까 바로 종료
    int elementNum = p.size();
    if(num >= p.size()) { //이미 끝난 상태(아예 조건을 만족하지 못하는 상태)
        cout << -1 ;
        return;
    }; 

    resultV.push_back(num + 1); 
    totalCount += c[num];
    accP += p[num]; accF += f[num]; accS += s[num]; accV += v[num]; accC += c[num];

    if(accP >= mp && accF >= mf && accS >= ms && accV >= mv){ //성공적으로 최소조건을 만족한 경우
        cout << "야아아아아" << "\n";
        if(totalCount < resultC) resultC = totalCount;

        cout << totalCount;
        cout << "\n";
        for(auto i : resultV) cout << i << " ";
        return;
    }

    for(int i=num; i < elementNum; i++){ //다음 것으로 넘어가는 로직 
        minCost(i);
    }

    //해당 함수 종료 = 복구 필요
    accP -= p[num]; accF -= f[num]; accS -= s[num]; accV -= v[num]; accC -= c[num];
    totalCount -= c[num];
    resultV.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i=0; i<n; i++){
        int tp,tf,ts,tv,tc;
        cin >> tp >> tf >> ts >> tv >> tc;
        p.push_back(tp); f.push_back(tf); s.push_back(ts); v.push_back(tv); c.push_back(tc);
    }

    minCost(0);
    return 0;
}
