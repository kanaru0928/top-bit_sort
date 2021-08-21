#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef unsigned int uint;
typedef unsigned long long ull;
#define repi(i, a, b) for(int i = int(a); i < int(b); i++)
#define rep(i, n) repi(i, 0, n)
#define repir(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define repr(i, n) repir(i, n, 0)
#define INF 1000000000
#define INF_LL 4000000000000000000
#define all(x) (x).begin(), (x).end()
#define UNI(x) (x).erase(unique(all(x)),(x).end())
#define F first
#define S second
#define MP make_pair
#define MT make_tuple
#define uset unordered_set
#define MOD 1000000007
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

#define MAXBIT 32

template<class T> bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

vector<int> topbit_sort(vector<int> v, vector<int> r){
    if(v.size() <= 1) return r;
    if(v.size() == 2){
        if(r[0] > r[1]) swap(r[0], r[1]);
        return r;
    }
    vector<vector<int>> maxbit(32);
    vector<vector<int>> maxbit_r(32);
    vector<int> zero;
    int n = v.size();
    rep(i, n){
        int index;
        if(!v[i]){
            zero.push_back(r[i]);
            continue;
        }
        else index = (int)log2((uint)v[i]);
        maxbit[index].push_back(v[i]);
        maxbit_r[index].push_back(r[i]);
    }
    vector<int> res;
    if(!maxbit[31].empty()){
        res = topbit_sort(maxbit[31], maxbit_r[31]);
    }
    if(!zero.empty()){
        res.insert(res.end(), all(zero));
    }
    rep(i, 31){
        if(!maxbit[i].empty()){
            rep(j, maxbit[i].size()){
                maxbit[i][j] &= ~(1 << i);
            }
            vector<int> tmp = topbit_sort(maxbit[i], maxbit_r[i]);
            res.insert(res.end(), all(tmp));
        }
    }
    return res;
}

vector<int> topbit_sort(vector<int> a){
    return topbit_sort(a, a);
}

int main(){ 
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // rep(i, n){
    //     cin >> a.at(i);
    // }
    vector<int> a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1};
    vector<int> ans = topbit_sort(a);
    rep(i, ans.size()){
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}
