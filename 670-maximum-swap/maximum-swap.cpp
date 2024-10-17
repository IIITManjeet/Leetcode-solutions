class Solution {
public:
    int maximumSwap(int num) {
        vector<int> lastOcc(10, 0);
        string numChrs = to_string(num);
        int size = numChrs.size();
        
        for(int indx = 0; indx < size; indx++) {
            lastOcc[numChrs[indx] - '0'] = indx;
        }
        
        for(int indx = 0; indx < size; indx++) {
            char currDig = numChrs[indx];
            for(char dig = '9'; dig > currDig; dig--) {
                if(indx < lastOcc[dig - '0']) {
                    swap(numChrs[indx], numChrs[lastOcc[dig - '0']]);
                    return stoi(numChrs);
                }
            }
        }
        
        return stoi(numChrs);
    }
};