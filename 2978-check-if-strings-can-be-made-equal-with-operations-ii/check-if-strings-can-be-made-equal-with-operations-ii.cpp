class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> s1EvenFreq, s1OddFreq, s2EvenFreq, s2OddFreq;
        for (int i=0;i<s1.length();i++) {
            if (i%2==0) {
                s1EvenFreq[s1[i]]++;
                s2EvenFreq[s2[i]]++;
            }
            else{
                s1OddFreq[s1[i]]++;
                s2OddFreq[s2[i]]++;
            }
        }
        return (s1EvenFreq==s2EvenFreq)&&(s1OddFreq==s2OddFreq);
    }
};