int h,w;
int sx,sy,gx,gy;
vector<vector<char>> s;
int N = 4e+6;
//各マス×4(方向) + 2(S,G) 4方向は「そのマスまでどうやって来たか」
vvi e(N+2, vi(0));
vi prv(N+2);
int D = 4;
vi dx = {1,-1,0,0};
vi dy = {0,0,1,-1};

void init(){
  rep(i,0,h){
    rep(j,0,w){
      //d1は「直前にどの方向から来たか」
      rep(d1,0,D){
        bool dne = false;
        //prev初期化 1次元化の式に注意
        prv[((i*w)+j)*D+d1] = -1;
        
        //「どの方向から来たか」によらないマス
        switch(s[i][j]){
          case '#':
            //通れない
            dne = true;
            break;
          //以下の6行はStart, Goal把握
          case 'S':
            sx = i; sy = j;
            break;
          case 'G':
            gx = i; gy = j;
            break;
          default:
            break;
        }
        if(dne) continue;
      }
        
      //次の移動の方向d2
      rep(d2,0,D){
        int nx = i + dx[d2];
        int ny = j + dy[d2];
      
        //進めるか
        if(0<=nx && nx<h && 0<=ny && ny<w && s[nx][ny]!='#'){
          //直前の動いた方向d1との対応関係を調べる（44~58行目で調べられていない）
          //同じマスに4このマスが重なっていると思えばよい
          rep(d1,0,D){
            int idx1 = (i*w+j)*D+d1;
            int idx2 = (nx*w+ny)*D+d2;
            
            //マスA→B→Cで同じ方向に動くには、Bがxであってはならない
            if(d1==d2 and s[i][j] != 'x'){
              e[idx1].pb(idx2);
            }
            //マスA→B→Cで違う方向に動くには、Bがoであってはならない 上とorでまとめてもよい
            if(d1 != d2 and s[i][j] != 'o'){
              e[idx1].pb(idx2);
            }
          }
        }
      }
    }
  }
  
  //多重スタート(N)・ゴール(N+1)回避 一方向にまとめる
  rep(d,0,D){
    e[N].pb((sx*w+sy)*D + d);
    e[(gx*w+gy)*D + d].pb(N+1);
  }
  prv[N] = -2; prv[N+1] = -1;
}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> h >> w;
  s.resize(h,vector<char>(w));
  rep(i,0,h){
    rep(j,0,w){
      cin >> s[i][j];
    }
  }
  
  init();
  bool flag = false;
  
  queue<int> q;
  //スタート地点
  q.push(N);

  while(!q.empty()){
    int cur = q.front();
    q.pop();
    
    int sz = e[cur].size();
    rep(i,0,sz){
      //未探索だったら つまり 「前にどのマスから来たか」のデータが存在しなかったら
      if(prv[e[cur][i]] == -1){
        q.push(e[cur][i]);
        prv[e[cur][i]] = cur;
        //もしゴールだったら（次にN+1に遷移するようだったら）
        if(e[cur][i] == N+1){
          flag = true;
          break;
        }
      }
      
    }
    if(flag) break;
  }
  //ルートの想定最長移動距離は4HWであり、これは5e+6より小さい prvを記録していれば十分
  
  string ans;
  
  if(flag){
    cout << "Yes" << endl;
    
    int cur = prv[N+1];
    //経路復元
    while(prv[cur] != N){
      int x1 = (prv[cur]/D)/w;
      int y1 = (prv[cur]/D)%w;
      int x2 = (cur/D)/w;
      int y2 = (cur/D)%w;
      if(x2-x1 == 1) ans += 'D';
      if(x2-x1 == -1) ans += 'U';
      if(y2-y1 == 1) ans += 'R';
      if(y2-y1 == -1) ans += 'L';
      cur = prv[cur];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  } else{
    cout << "No" << endl;
  }
    cout << fixed << setprecision(30);
    return 0;
}
