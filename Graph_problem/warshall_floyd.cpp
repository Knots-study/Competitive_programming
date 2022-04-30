//warshall-floyd
//「すべての頂点」から「すべての頂点」への最短距離を求める
//計算量O(n^3)

//始点と終点が同じ場合(a=b)adj[a][b]=0
//道が存在しない場合INFを代入する

void warshall_floyd(int n){
    for(int k=0;k<n;k++){//経由地
        for(int i=0;i<n;i++){//始点
            for(int j=0;j<n;j++){//終点
                if(adj[i][k]!=INF&&adj[k][j]!=INF){
                    chmin(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
    }
}