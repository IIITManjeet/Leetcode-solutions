#define rep(i, a, b) for (int i = a; i <= b; i++)
typedef vector<int> vi;
const int N = 100001;
int cnt=0;
int spf[N]={0}, occupied[N]={0}, isActive[N]={0};
void dfs(int node,unordered_map<int,vi>& gr,vector<bool>& vis){
    if(vis[node])return;
    vis[node]=true;
    cnt++;
    for(auto ne:gr[node]){
        if(!vis[ne]){
            dfs(ne,gr,vis);
        }
    }
}
void sieve() {
    rep(i, 1, N - 1) spf[i] = i;
    rep(i, 2, N - 1) {
        if (spf[i] == i) {
            for (int j = 2 * i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vi primeFactorize(int n) {
    vi primes;
    while (n != 1) {
        int x = spf[n];
        while (n % x == 0) {
            n /= x;
        }
        primes.push_back(x);
    }
    return primes;
}
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        sieve();
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[i]=primeFactorize(nums[i]);
        }
        unordered_map<int,vector<int>>rmp;
        for(auto p:mp){
            int id=p.first;
            for(auto prime:p.second){
                rmp[prime].push_back(id);
            }
        }
        unordered_map<int,vi>gr;
        for(auto p:rmp){
            vi ids=p.second;
            if(ids.size()<=1){
                continue;
            }
            for(int i=1;i<ids.size();i++){
                int u=ids[i-1];
                int v=ids[i];
                gr[u].push_back(v);
                gr[v].push_back(u);
            }
        }
        vector<bool>vis(n,false);
        cnt=0;
        dfs(0,gr,vis);
        if(cnt==n)return true;
        return false;
    }
};