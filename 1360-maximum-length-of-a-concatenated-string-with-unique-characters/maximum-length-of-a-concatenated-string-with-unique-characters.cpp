



class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLength = 0;
        backTrack(arr, 0, 0, maxLength);
        return maxLength;
    }

private:
    void backTrack(const vector<string>& arr, int index, int charSet, int& maxLength) {
        if (index == arr.size()) {
            int count = 0;
            for (int i = 0; i < 26; ++i) {
                if ((charSet & (1 << i)) != 0) {
                    count++;
                }
            }
            maxLength = max(maxLength, count);
            return;
        }

        int newCharSet = charSet;
        bool isValidString = true;

        for (char ch : arr[index]) {
            int bit = 1 << (ch - 'a');
            if ((newCharSet & bit) == 0) {
                newCharSet |= bit;
            } else {
                isValidString = false;
                break;
            }
        }

        if (isValidString) {
            backTrack(arr, index + 1, newCharSet, maxLength);
        }

        backTrack(arr, index + 1, charSet, maxLength);
    }
};






