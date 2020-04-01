#include<bits/stdc++.h>
#define bst           ios_base::sync_with_stdio(0);
#define bug(x)        cerr<<#x<<'='<<x<<endl;
#define lp(i,a,b)     for(int i=a; i<=b; i++)
#define ll            long long int
#define eb            emplace_back
#define pb            push_back
#define mp            make_pair
using namespace std;
ll f, e, n, m;
vector<ll> x, y, start, end_;
vector<ll> edge[107];
ll check(ll a, ll x2, ll b, ll x1, ll g, ll i, ll y1, ll y2){
    ///checking many points if one of them in range 
    a+=(i*(x2/g));  ///a=a0+(k*x2)/g;
    b-=(i*(x1/g));   
    ll keep1=y1+(a * x1);
    ll keep2=y2-(b * x2);
    if(keep1>=y1 && keep1<f && keep2>=y2) return true;
    return false;
}
ll eeg(ll x, ll y, ll &a, ll &b){  ///extended euclid algo
    if(x==0){
        a=0, b=1;
        return y;
    }
    ll a1, b1;
    ll gcd=eeg(y%x, x, a1, b1);
    a=b1-((y/x)*a1);
    b=a1;
    return gcd;
}
ll create_edge(ll u, ll v){   ///diophantine equations
    ll x1=x[u], y1=y[u], x2=x[v], y2=y[v], i, j, k;
    ll a, b, gcd;
    x2=-x2;   ///y1+ax1=y2+bx2; so, ax1-bx2=y2-y1;
    if(x2>x1) gcd=eeg(x1, x2, a, b);
    else gcd=eeg(x2, x1, b, a);     /// we will get a & b for gcd; ax+by=gcd(x, y);
    ll c=y2-y1;



    if(c%gcd!=0) return false;

    a*=(c/gcd), b*=c/gcd; /// we get a & b for c;
    bool ok=false;
    
    for(i=-500; i<=500; i++){
        if(check(a, x2, b, x1, gcd, i, y1, y2)) ok=true;  ///checking many points if it come into the range
    }
    return ok;

}
int main(){
    ll t;
    cin>>t;
    while(t--){
        scanf("%lld %lld %lld %lld", &f, &e, &n, &m);
        ll i, j, k, l;
        x.clear(), y.clear(), end_.clear(), start.clear();
        for(i=0; i<105; i++) edge[i].clear();
        for(i=0; i<e; i++){
            ll u , v;
            scanf("%lld %lld", &u, &v);
            x.eb(u); y.eb(v);
            if(v<=n && (n-v)%u==0) start.eb(i);   ///if we can enter this elevator from starting floor
            if(v<=m && (m-v)%u==0) end_.eb(i);
        }
        for(i=0; i<e-1; i++){
            for(j=i+1; j<e; j++){
                if(create_edge(i, j)){
                    edge[i].eb(j); edge[j].eb(i);
                }
            }
        }
        bool dest[1000]={};
        ll limit=end_.size();
        for(i=0; i<limit; i++) dest[end_[i]]=true;

        queue<ll> q;
        limit=start.size();
        bool dekho[1000]={};
        for(i=0; i<limit; i++){
            q.push(start[i]);
            dekho[start[i]]=true;
        }

        bool ok=false;
        while(!q.empty()){  ///bfs to check is it possible or not to go one floor to another
            ll lala=q.front();
            if(dest[lala]==true){
                ok=true;
                break;
            }
            limit=edge[lala].size();
            for(i=0; i<limit ;i++){
                ll fuck=edge[lala][i];
                if(dekho[fuck]==false) q.push(fuck);
            }
            q.pop();
        }

        if(ok) printf("It is possible to move the furniture.\n");
        else printf("The furniture cannot be moved.\n");



    }
    return 0;
}
