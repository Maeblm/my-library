S e_min() {return make_pair(inf, 1);}
S e_max() {return make_pair(-inf, 1);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >>  m;
    vector<S> a(n);

    rep(i,0,n){
        int p;
        cin >> p;
        a[i] = make_pair(p,i);
    }

    atcoder::segtree<S, op_min, e_min> segmin(a);
    atcoder::segtree<S, op_max, e_max> segmax(a);

    rep(i,0,m){
        int l,r;
        cin >> l >> r;
        l --;
        S im = segmin.prod(l,r);
        S iM = segmax.prod(l,r);

        segmin.set(iM.second, make_pair(im.first, iM.second));
        segmin.set(im.second, make_pair(iM.first, im.second));
        segmax.set(iM.second, make_pair(im.first, iM.second));
        segmax.set(im.second, make_pair(iM.first, im.second));        
    }

    rep(i,0,n){
        cout << segmin.get(i).first << " ";
    }
}