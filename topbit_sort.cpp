/**
 * @file topbit_sort.cpp
 * @brief オリジナルのソート
 * @author kanaru
 * @date 2021/8/21
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define MAXBIT 32

vector<int> topbit_sort(vector<int> v, vector<int> r){
    // サイズが1の時はそのまま返す
    if(v.size() <= 1) return r;
    // サイズが2の時は大小を判定して返す
    if(v.size() == 2){
        if(r[0] > r[1]) swap(r[0], r[1]);
        return r;
    }
    //  二進法の桁数ごとに分けるための配列
    vector<vector<int>> maxbit(MAXBIT);     //  処理用の値
    vector<vector<int>> maxbit_r(MAXBIT);   //  戻り値用の値
    vector<int> zero;
    int n = v.size();
    for(int i = 0; i < n; i++){
        int index;
        if(!v[i]){   // log_2(0)は-∞に発散するので別で保管する
            zero.push_back(r[i]);
            continue;
        }
        else index = (int)log2((uint)v[i]); //  uintにすることで負の値に対応
        maxbit[index].push_back(v[i]);
        maxbit_r[index].push_back(r[i]);
    }
    vector<int> res;
    //  並べるときは負、0、正の順
    if(!maxbit[MAXBIT - 1].empty()){
        for(int j = 0; j < maxbit[MAXBIT - 1].size(); j++){
            maxbit[MAXBIT - 1][j] &= ~(1 << MAXBIT - 1);
        }
        res = topbit_sort(maxbit[MAXBIT - 1], maxbit_r[MAXBIT - 1]);
    }
    if(!zero.empty()){
        res.insert(res.end(), zero.begin(), zero.end());
    }
    for(int i = 0; i < MAXBIT - 1; i++){
        if(!maxbit[i].empty()){
            //  最上位を0にする
            for(int j = 0; j < maxbit[i].size(); j++){
                maxbit[i][j] &= ~(1 << i);
            }
            vector<int> tmp = topbit_sort(maxbit[i], maxbit_r[i]);
            res.insert(res.end(), tmp.begin(), tmp.end());
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
    
    // int型のみ対応(負でもOK) ちょっと書き換えればuintとかLLとかにも対応できると思います。
    vector<int> a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1};
    vector<int> ans = topbit_sort(a);
    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}
