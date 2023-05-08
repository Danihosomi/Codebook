int n, k;
vi v[2];

// O(2^((n/2)+1))

vi getValues(int id){ // Mudar de acordo com problema tambem
    vi values;

    for(int mask=0;mask<(1<<(sz(v[id])));mask++){
        int sum = 0;
        
        for(int j=0;j<sz(v[id]);j++)
            if((1<<j)&mask) sum = (v[id][j]+sum)%k;

        values.pb(sum);
    }

    return values;
}

ll Combine(vi& v1, vi& v2){
    return inf; // implementar Combine de acordo com problema
}

ll MeetInMiddle(vi& g){
    random_shuffle(all(g));
    
    for(int i=0;i<sz(g);i++){
        if(i*2>sz(g)) v[0].pb(g[i]);
        else v[1].pb(g[i]);
    }

    ll ans=0;

    auto m1 = getValues(0);
    auto m2 = getValues(1);

    return ans = Combine(m1,m2);
}