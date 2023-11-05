class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        int n=s.size();
        int left=0,right=k-1;
        int ans=0;
        while(right<n){
            string cur="";
            for(int i=left;i<=right;i++){
                cur+=s[i];
            }
            int curNum=stoi(cur);
            if(curNum!=0){
                if(num%curNum==0)ans++;
            }
            left++;right++;
        }
        return ans;
    }
};