#include<bits/stdc++.h>
#define bst           ios_base::sync_with_stdio(0);
#define bug(x)        cerr<<#x<<'='<<x<<endl;
#define lp(i,a,b)     for(int i=a; i<=b; i++)
#define ll            long long int
#define eb            emplace_back
#define pb            push_back
#define mp            make_pair
using namespace std;
class obj{
    public :
        string u;
        ll w;
    obj(ll c, string a){
        w=c, u=a;
    }
};
class compare{        ///making priority_queue in increasing order
    public :
        bool operator () (obj &a , obj &b){
            return a.w > b.w ;
        }
};
int main(){
    bst
    ll t, tc=1;
    cin>>t;
    while(t--){
        ll m;
        cin>>m;
        string str[m+5];
        ll n=0, i, j, k;
        map<string, vector<pair<ll, string>>> path;
        
        
        
        priority_queue<obj,vector<obj>, compare> pq;         ///increasing order
        
        
        
        map<string, ll> mp;
        for(i=0; i<m; i++){
            string s1, s2;
            ll c;
            cin>>s1>>s2>>c;
            path[s1].eb(c, s2);
            path[s2].eb(c, s1);
            if(mp[s1]==0) str[n++]=s1; ///to save every city
            if(mp[s2]==0) str[n++]=s2;
            mp[s1]=1; mp[s2]=1;
        }
        ll ans=0;
        pq.push({0, str[0]});

        while(!pq.empty()){
            ll c=pq.top().w;
            string s1=pq.top().u;
            pq.pop();
            if(mp[s1]==2) continue;///we already counted this node
            mp[s1]=2;
            ans+=c;
            ll limit=path[s1].size();
            for(i=0; i<limit; i++){
                ll ww=path[s1][i].first;
                string x=path[s1][i].second;
                if(mp[x]!=2){
                    pq.push({ww, x});
                } 
            }
        }
        bool flag=false;
        for(i=0; i<n; i++) if(mp[str[i]]!=2) flag=true;
        
        if(flag) cout<<"Case "<<tc++<<": Impossible"<<endl;
        else cout<<"Case "<<tc++<<": "<<ans<<endl;
    }
    return 0;
}
