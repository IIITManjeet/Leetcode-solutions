#define ll long long
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repL(i, a, b) for (ll i = a; i <= b; i++)
#define nl '\n'
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define F first
#define PB push_back
#define S second
const int INF = 1e9;
#define MOD 1000000007
class Solution {
public:
    void change(vector<vi>&gr,vi& dist,int u,int v){
        if(dist[u]+1<dist[v]){
            dist[v]=dist[u]+1;
            queue<int>q;q.push(v);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto neigh:gr[node])if(dist[node]+1<dist[neigh])dist[neigh]=dist[node]+1,q.push(neigh);
            }
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vi>gr(n);
        rep(i,0,n-2){
            gr[i].PB(i+1);
        }
        vi dist(n,INT_MAX);
        dist[0]=0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neigh:gr[node]){
                if(dist[node]+1<dist[neigh])dist[neigh]=dist[node]+1,q.push(neigh);
            }
        }
        vi ans;
        for(auto q:queries){
            int u=q[0],v=q[1];
            gr[u].PB(v);
            change(gr,dist,u,v);
            ans.PB(dist[n-1]);
        }
        return ans;
    }
};