ll MOD = (1e+9)+7;

ll mod_pow(ll n, ll p){
    ll res = 1;
    ll pw = n;
    while(p > 0){
        if(p & 1){
            res = res * pw % MOD;
        }
        //桁数のshift
        pw = pw * pw % MOD;
        p = p >> 1;
    }
    return res;
}