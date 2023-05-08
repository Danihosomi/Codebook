const int len = 448; // ajustar len para problema em questao sqrt(n+.0)+1

struct Query{
    int l, r, id;
    int operator<(Query other) const{
        return make_pair(l/len,r)<make_pair(other.l/len,other.r);
    }
};

int n, v[1000000];
vector<Query> query; // Offline, sem update, depende de outra estrutura de dados

vi resposta(){
    vi ans(sz(query));
    sort(all(query));

    int cl=0, cr=-1;

    for(auto x : query){
        while(cl>x.l){
            cl--;
            //strutura.add(cl);
        }
        while(cr<x.r){
            cr++;
            //strutura.add(cr);
        }
        while(cl<x.l){
            //strutura.remove(cl);
            cl++;
        }
        while(cr>x.r){
            //strutura.remove(cr);
            cr--;
        }
        ans[x.id] = 0; // strutura.resposta();
    }

    return ans;
}
