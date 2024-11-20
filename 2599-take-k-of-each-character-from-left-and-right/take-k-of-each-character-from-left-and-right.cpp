#define all(v) v.begin(), v.end()
class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>a(3,0);
        int n=s.size();
        for(auto ch:s)a[ch-'a']++;
        if(*min_element(all(a))<k)return -1;
        int l=0;
        int ans=INT_MAX;
        for(int r=0;r<n;r++){
            a[s[r]-'a']--;
            while(*min_element(all(a))<k){
                a[s[l]-'a']++;
                l++;
            }
            ans=min(ans,n-r+l-1);
        }
        return ans;   
    }
};