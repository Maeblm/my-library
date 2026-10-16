//参考：https://zenn.dev/appleple/articles/8f9d8afdb9d7de
ll m;
cin >> m;
rep(i,0,m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    indeg[y] ++;
    G.add_edge(x,y);
}

bool flag = false;

queue<int> q;

int s = -1;
rep(i,0,n){
    if(G.deg_in(i) == 0){
        s = i;
        q.push(s);
        break;
    }
}

vi ans(n);

if(s != -1){
    int i = 0;
    while(!q.empty()){
        i++;
        int pos = q.front();
        q.pop();
        ans[pos] = i;
        // cntは同時に入次数0の頂点が2つ以上存在するかを確認する
        int cnt = 0;
        rep(j,0,G.deg_out(pos)){
            indeg[G.nexts(pos)[j].second] --;
            if(indeg[G.nexts(pos)[j].second] == 0){
                cnt ++;
                q.push(G.nexts(pos)[j].second);
            }
        }
        if(cnt >= 2){
            break;
        }
    }
    if(i == n){
        flag = true;
        cout << "Yes" << endl;
        rep(j,0,n){
            cout << ans[j] << " ";
        }
    } 
}
if(!flag) cout << "No" << endl;