struct edge{ll to, cost;};
typedef pair<ll,ll> P;//p.first=コスト　p.second=点の名前
class graph{
    private:
        ll V;
        vector<vector<edge>> G;
        vector<ll> d;
    public:
        graph(ll n){
            V = n;
            G.resize(V);
            d.resize(V);
            REP(i,V){
                d[i] = INF;
            }
        }
        void add_edge(ll s,ll t,ll cost){
            edge e;
            e.to = t,e.cost = cost;
            G[s].push_back(e);
        }
        void dijkstra(ll s){
            d[s] = 0;
            priority_queue<P,vector<P>, greater<P> > que;
            que.push(P(0,s));
            while(!que.empty()){
                P p = que.top();
                que.pop();
                ll v = p.second;
                if(d[v]<p.first)continue;//書き換えることが不可能な場合
                for(auto e:G[v]){
                    if(d[e.to]>d[v]+e.cost){//移動する予定の頂点のコストが、今いる頂点から移動した方が少なくて済む場合
                        d[e.to] = d[v]+e.cost;//書き換え
                        que.push(P(d[e.to],e.to));
                    }
                }
            }
        }
};
//graph g(n) n頂点のグラフを作成
//g.add_edge(a,b,cost) 頂点aから頂点bへのコストcostの辺を張る
//g.dijkstra(s) 頂点sから各頂点への最短距離をダイクストラ方で探索
//int dist = g.d[i] 探索結果の確認