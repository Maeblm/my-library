// 参考：https://zenn.dev/taketooon/articles/6eea340f2f22e7
ll twoPointer_right(ll cur, ll val){
    // デフォルトは和
    return cur + val;
}

ll twoPointer_left(ll cur, ll val){
    // デフォルトは差
    return cur - val;
}

template <typename T>
ll twoPointer(vector<T> s, T key){
    queue<ll> Q;
    ll ans = 0;
    // curの値はtwoPointer_rightの関数の形で変化することに注意せよ
    T cur = 0;

    for(ll i = 0; i < (int)s.size(); ++i){
        Q.push(s[i]);
        cur = twoPointer_right(cur, s[i]);

        while(!Q.empty() && cur > key){
            cur = twoPointer_left(cur, Q.front());
            Q.pop();
        }

        // この場合key以下となる連続部分列の個数をカウント
        ans += Q.size();
    }

    return ans;
}