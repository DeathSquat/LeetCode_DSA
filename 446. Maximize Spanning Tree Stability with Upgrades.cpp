class Solution {
public:
    struct DSU {
        vector<int> p, r;
        DSU(int n) {
            p.resize(n);
            r.resize(n,0);
            for(int i=0;i<n;i++) p[i]=i;
        }
        int find(int x){
            if(p[x]==x) return x;
            return p[x]=find(p[x]);
        }
        bool unite(int a,int b){
            a=find(a); b=find(b);
            if(a==b) return false;
            if(r[a]<r[b]) swap(a,b);
            p[b]=a;
            if(r[a]==r[b]) r[a]++;
            return true;
        }
    };

    bool can(int n, vector<vector<int>>& edges, int k, int T){
        DSU dsu(n);
        int used=0;
        
        vector<pair<int,int>> normal;
        vector<pair<int,int>> upgrade;
        
        for(auto &e: edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];
            
            if(must){
                if(s<T) return false;
                if(!dsu.unite(u,v)) return false;
                used++;
            } else {
                if(s>=T) normal.push_back({u,v});
                else if(2*s>=T) upgrade.push_back({u,v});
            }
        }
        
        for(auto &e: normal){
            if(dsu.unite(e.first,e.second)){
                used++;
                if(used==n-1) return true;
            }
        }
        
        int up=0;
        for(auto &e: upgrade){
            if(up==k) break;
            if(dsu.unite(e.first,e.second)){
                used++;
                up++;
                if(used==n-1) return true;
            }
        }
        
        return used==n-1;
    }
    
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo=0, hi=200000, ans=-1;
        
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(can(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
        
        return ans;
    }
};
