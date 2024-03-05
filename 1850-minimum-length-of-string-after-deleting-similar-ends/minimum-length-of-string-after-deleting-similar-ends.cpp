class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        if(n==1)return n;
        int i=0,j=n-1;
        while(i<j && s[i]==s[j]){
            char ch=s[i];
            while(i<=j && s[i]==ch){
                i++;
            }
            while(i<=j && s[j]==ch){
                j--;
            }
        }
        return j-i+1;
    }
};