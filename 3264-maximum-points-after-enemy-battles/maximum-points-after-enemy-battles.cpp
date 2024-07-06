class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long total=0;
        int minEl=INT_MAX;
    for(int i : enemyEnergies){
        total += i;
        minEl = min(minEl,i);
    }

    if(currentEnergy < minEl){
        return 0;
    }

    total = (long)currentEnergy + (total - minEl);

    return total / minEl;
    }
};