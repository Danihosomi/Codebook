int n;
ll dist[501][501][501];

void fw(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[k][i][j]=min(dist[k][i][j],dist[k-1][i][k]+dist[k-1][k][j]);
            }
        }
    }
}