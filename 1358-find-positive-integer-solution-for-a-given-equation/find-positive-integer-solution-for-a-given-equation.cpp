/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z)
    {
        vector<vector<int>>ans;
        for(int x=1;x<=z;x++){
            int b=1,e=z;
            while(b<=e){
                int m=b+(e-b)/2;
                if(customfunction.f(x,m)==z){
                    auto t={x,m};
                    ans.push_back(t);
                    e=m-1;
                }
                else if(customfunction.f(x,m)>z){
                    e=m-1;
                }
                else{
                    b=m+1;
                }
            }
        }
        return ans;
    }
};