//Union-Find
/*　
    連結成分に操作する際に利用する可能性が高い
    is_same(x,y):x,yが同じ集合にいるか
    unite(x,y):x,yを同じ集合にする
    treesize(x):xを含む集合の要素数
*/
struct UnionFind{
    vector<int> size,parents;
    UnionFind() {}
    UnionFind(int n){
        size.resize(n,0);
        parents.resize(n,0);
        for(int i=0;i<n;i++){
            makeTree(i);
        }
    }
    void makeTree(int x){
        parents[x] = x; //xの親はx
        size[x] = 1; //初期値の木のサイズは1
    }
    bool is_same(int x,int y){
        if(findroot(x)==findroot(y))return 1;///xとyの親が一緒なら1を返す
        else return 0;
    }
    bool unite(int x,int y){
        x = findroot(x);
        y = findroot(y);
        if(x==y)return 0;//xとyが同じならスルー
        //計算量逓減のために木の高さが低い方を高い方に接続
        if(size[x]>size[y]){
            parents[y] = x;
            size[x] += size[y];
        }
        else{
            parents[x] = y;
            size[y] += size[x];
        }
        return 1;//処理を終えた後,接続したことをreturn1で返す
    }
    int findroot(int x){
        if(x != parents[x]){
            parents[x] = findroot(parents[x]);
        }
        return parents[x];
    }
    int treesize(int x){
        return size[findroot(x)];
    }
};
 
//辺の定義
struct Edge{
    ll u,v,cost;
    //頂点uと頂点vを結ぶ辺のコストcost
};
 
//辺を直接比較するための関数
bool comp_e(const Edge &e1,const Edge &e2){
    return e1.cost < e2.cost;
};
 
struct Kruskal{
    UnionFind uf;
    ll sum;//最小全域木の重みの総和
    vector<Edge> edges;
    int V;
    Kruskal(const vector<Edge> &edges_, int V_):edges(edges_),V(V_){init();}
    void init(){
        sort(edges.begin(),edges.end(),comp_e);
        uf = UnionFind(V);
        sum = 0;
        for(auto e : edges){
            if(!uf.is_same(e.u,e.v)){//閉路にならないのであれば加える
                uf.unite(e.u,e.v);
                sum += e.cost;
            }
        }
    }
};