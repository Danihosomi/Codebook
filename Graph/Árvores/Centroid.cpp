int n, vis[200005], tam[200005], pai[200005];
vi v[200005], g[200005];

int findSize(int a,int p){ // Acha o tamanho dos sizes das Subtrees
    if(vis[a]) return 0;
    tam[a]=1;
    
    for(auto x : v[a]){
        if(x==p) continue;
        tam[a]+=findSize(x,a);
    }

    return tam[a];
}

int findCentroid(int a,int p,int tamS){ // Retorna o Centroid da Subtree de tamanho tamS

    for(auto x : v[a]){
        if(x==p) continue;
        if(!vis[x] && tam[x]*2>tamS)
            return findCentroid(x,a,tamS);
    }

    return a;
}

ii parCentroid(){
	findSize(1,1); int ans1=findCentroid(1,1,tam[1]), ans2=ans1;
	for (int x : v[ans1]) if (2*tam[x]==tam[1]) ans2 = x;
	return {ans1,ans2};
}

void build(int a,int p=-1){ // Faz a Decomposition do Centroid
    findSize(a,a);

    int c = findCentroid(a,a,tam[a]);
    vis[c]=1;
    if(p!=-1) pai[c]=p;
    

    for(auto x : v[c])
        if(!vis[x]) build(x,c);
}

