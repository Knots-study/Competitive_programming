const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
bool visited[50][50];

int main(){
    int r,c,sy,sx,gy,gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    --sy;--sx;--gy;--gx;
    vector<vector<char>> vec(r,vector<char>(c));
    vector<vector<int>> count(r,vector<int>(c,0));
    REP(i,r){
        REP(j,c){
            cin >> vec[i][j];
        }
    }
    queue<int> que;
    que.push(sx);
    que.push(sy);
    count[sy][sx]=0;
    visited[sy][sx]=1;
    while(!que.empty()){
        int x = que.front();que.pop();
        int y = que.front();que.pop();
        for(int dir=0;dir<4;++dir){
            int X = x+dx[dir];
            int Y = y+dy[dir];
            if(X<0||X>=c||Y<0||Y>=r)continue;
            if(visited[Y][X]==1)continue;
            if(vec[Y][X]=='#')continue;
            else{
                que.push(X);
                que.push(Y);
                count[Y][X] += (count[y][x]+1);
                visited[Y][X]=1;
            }
        }
    }
    COUT(count[gy][gx]);
}