# Top-bit sort
## アルゴリズム
![top-bit sort](https://user-images.githubusercontent.com/68174393/130323664-4cd97708-b911-432b-90c6-bf7ed7c94f29.png)

1. 二進数表記したときの桁数ごとにグループに分ける
2. 全部の数の最上位を消す
3. グループの要素数が3以上なら再帰する

基数ソート、分布数え上げソート、クイックソートあたりを足して割った感じな気がする。同じものが既にあったら教えてください。

## 計算量
$O(N\log N)$くらいであってほしい(願望)
