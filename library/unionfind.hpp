template<class T = long long>
struct Unionfind {
  
  //配列
  //  size:各要素の属するサイズ(要素数) 初期状態1
  //  parents:各要素の親を記録 初期状態では各要素が独立した木
  vector<int> size, parents;
  
  //デフォルトコンストラクタ
  Unionfind(){};
  Unionfind(int n){
    //初期化 要素の作成
    size.resize(n, 0);
    parents.resize(n,0);
    
    for(int i = 0; i < n; i++){
      makeTree(i);
    }
    
  }
  
  //関数 makeTree
  //  指定された要素xを新しい集合として初期化
  void makeTree(int x){
    parents[x] = x;//要素xは自分自身が親
    size[x] = 1;//要素xが属する集合のサイズは1
  }
  
  //関数isSame
  //  xとyが同じ集合に入るか確かめる
  bool isSame(int x, int y){
    return findRoot(x) == findRoot(y);//同じ場合true
  }
  
  bool unite(int x, int y){
    //要素x,yの代表者を取得
    x = findRoot(x);
    y = findRoot(y);
    if(x == y) return false;//すでに要素x,yの代表者が同じ場合何もしない
    
    //要素数が小さいほうの要素が属する集合に結合する
    if(size[x] > size[y]){
      parents[y] = x;
      size[x] += size[y];//要素数の更新
    } else{
      parents[x] = y;
      size[y] += size[x];
    }
    return true;
  }
  
  //関数 findRoot
  //  要素xが属する集合の代表者を見つける
  int findRoot(int x){
    if(x != parents[x]){//自分自身が親ではなかった場合
      //親の代表者を探すと同時に、自身の親を木の根に更新する
      parents[x] = findRoot(parents[x]);
    }
    //自分自身が親だった場合
    return parents[x];//要素xが属する集合の代表者は自分自身 つまり要素x
  }
  
  //関数treeSize
  //  xを含む集合の要素数
  int treeSize(int x){
    //要素xの代表者の要素数を取得(この値しか更新されていない)
    return size[findRoot(x)];
  }
};