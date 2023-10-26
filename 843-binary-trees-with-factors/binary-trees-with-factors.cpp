class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long long int>m;
        for(int i=0;i<arr.size();i++){
            m.insert({arr[i],1});
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            long long int  count=0;
            auto it1=m.find(arr[i]);
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    auto it2=m.find(arr[i]/arr[j]);
                    auto it3=m.find(arr[j]);
                    if(it2!=m.end()){
                        count+=(it2->second)*(it3->second);
                    }
                }
            }
            it1->second+=count;
        }
        long long int sum=0;
        for(auto it:m){
            sum+=it.second;
        }
        return sum%(1000000007);
    }
};