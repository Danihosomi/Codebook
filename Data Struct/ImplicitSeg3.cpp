#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

struct node{ // Seg3 que vai se criando conforme as query
    int left, right;
    ll sum;
    node *lno=nullptr, *rno=nullptr;

    node(int lb,int rb){
        left=lb; right=rb;
    }

    void extend(){ // build
        if(!lno && left+1<right){
            int meio=left+((right-left)>>1);
            lno = new node(left,meio);
            rno = new node(meio,right);
        }
    }

    void add(int k,ll val){ // update
        extend();
        sum+=val;
        if(lno) (k<lno->right ? lno->add(k,val) : rno->add(k,val));
    }

    ll query(int lq,int rq){
        if(lq<=left && right<=rq) return sum; // Aqui responde query
        if(max(left,lq)>=min(right,rq)) return 0; // Aqui valor Nulo;
        extend();
        return lno->query(lq,rq)+rno->query(lq,rq);
    }
};

int main(){_


    return 0;

}