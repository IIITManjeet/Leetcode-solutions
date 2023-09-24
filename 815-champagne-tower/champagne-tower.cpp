class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
vector<double> tower(102, 0.0);
        tower[0] = poured;
        for (int i = 0; i < query_row; i++) {
            vector<double> ntower(102, 0.0);
            for (int j = 0; j <= i; j++) {
                double overflow = max(0.0, (tower[j] - 1.0) / 2.0);
                ntower[j] += overflow;
                ntower[j + 1] += overflow;
            }
            
            for (int j = 0; j <= i + 1; j++) {
                tower[j] = ntower[j];
            }
        }
        
        return min(1.0, tower[query_glass]);        

    }
};