// 参考：https://qiita.com/untan/items/8c561a04b47de49bc2e8
template<class T = long long>
struct Graph {
    /////////////メンバ変数///////////////

    // _edges[i] := 頂点iを始点とする辺
    vector<vector<Edge<T>>> _edges;

    // 全ての辺のコストの合計
    T _total_edge_cost;
    
    // すべての辺の数
    int _total_edges;

    // 入次数
    vector<int> _deg_in;

    // 出次数
    vector<int> _deg_out;


    //////////コンストラクタ////////////

    Graph(int n)
        : _edges(n),
          _total_edge_cost(0),
          _total_edges(0),
          _deg_in(n, 0),
          _deg_out(n, 0)
    {}


    //////////メンバ関数////////////////

    // コスト1の辺 u → v を追加
    void add_edge(int u, int v) {
        add_edge(T(1), u, v);
    }


    // コストcの辺 u → v を追加
    void add_edge(T c, int u, int v) {
        _edges[u].push_back(Edge<T>(u, v, c));

        _total_edge_cost += c;
        _total_edges ++;

        _deg_out[u]++;
        _deg_in[v]++;
    }


    // 頂点数を返す
    int size_n() const {
        return _edges.size();
    }


    // 辺の本数を返す
    int size_e() const {
        return _total_edges;
    }
    
    // 頂点iを始点とする辺の本数を返す
    int size_e(int i) const {
        return _edges[i].size();
    }


    // 全ての辺のコストの合計を返す
    T total_edge_cost() const {
        return _total_edge_cost;
    }


    // 頂点iを始点とする辺リストを返す
    const vector<Edge<T>>& edges(int i) const {
        return _edges[i];
    }


    // 入次数配列を返す
    const vector<int>& deg_in() const {
        return _deg_in;
    }

    // 頂点iの入次数を返す
    int deg_in(int i) const {
        return _deg_in[i];
    }

    // 出次数配列を返す
    const vector<int>& deg_out() const {
        return _deg_out;
    }

    // 頂点iの出次数を返す
    int deg_out(int i) const {
        return _deg_out[i];
    }
    
    // iから行ける全ての場所の
    // {最短距離, 頂点} の集合を返す
    // Dijkstra法
    const vector<pair<T, int>> nexts_all(int i) const {
        int n = _edges.size();

        const T INF = numeric_limits<T>::max();

        vector<T> dist(n, INF);

        priority_queue<
            pair<T, int>,
            vector<pair<T, int>>,
            greater<>
        > pq;
        
        dist[i] = 0;
        pq.push({0, i});

        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (d > dist[v]) continue;

            for (auto e : _edges[v]) {
                if (dist[e.to] > d + e.val) {
                    dist[e.to] = d + e.val;
                    pq.push({dist[e.to], e.to});
                }
            }
        }

        vector<pair<T, int>> res;

        for (int j = 0; j < n; j++) {
            if (dist[j] != INF) {
                res.push_back({dist[j], j});
            }
        }
        return res;
    }
    
    // サイクル検出
    // 使用例 -> https://atcoder.jp/contests/abc456/submissions/79128921
    const vector<Edge<T>> detect_cycle() const {
        int n = _edges.size();
    
        vector<int> state(n, 0);
        // 0 = 未訪問
        // 1 = DFS中 seen
        // 2 = DFS完了 finished
    
        vector<Edge<T>> path;
    
        for (int v = 0; v < n; v++) {
            if (state[v] != 0) continue;
    
            auto result = cycle_dfs(v, state, path);
    
            if (!result.empty()) {
                return result;
            }
        }
    
        return {};
    }
    
    vector<Edge<T>> cycle_dfs(
        int v,
        vector<int>& state,
        vector<Edge<T>>& path
    ) const {
        state[v] = 1;
    
        for (const Edge<T>& e : _edges[v]) {
            int to = e.to;
    
            // DFS中の頂点に戻った
            // つまりサイクルが検出された
            if (state[to] == 1) {
    
                vector<Edge<T>> cycle;
    
                // pathの中から to から始まる部分を探す
                for (int i = (int)path.size() - 1; i >= 0; i--) {
                    cycle.push_back(path[i]);
    
                    if (path[i].from == to) {
                        break;
                    }
                }
    
                reverse(cycle.begin(), cycle.end());
                cycle.push_back(e);
    
                return cycle;
            }
    
            // 未訪問
            if (state[to] == 0) {
                path.push_back(e);
    
                auto result = cycle_dfs(to, state, path);
    
                if (!result.empty()) {
                    return result;
                }
    
                path.pop_back();
            }
        }
    
        state[v] = 2;
        return {};
    }

};