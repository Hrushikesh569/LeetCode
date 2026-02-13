class Solution {
public:

    int helper(string& s, char ch1, char ch2) {
        int n = s.length();
        int maxL = 0;
        unordered_map<int, int> diffMap;
        int count1 = 0, count2 = 0;

        for(int i = 0; i < n; i++) {

            // Reset if third character appears
            if(s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                count1 = count2 = 0;
                continue;
            }

            if(s[i] == ch1) count1++;
            if(s[i] == ch2) count2++;

            if(count1 == count2) {
                maxL = max(maxL, count1 + count2);
            }

            int diff = count1 - count2;

            if(diffMap.count(diff)) {
                maxL = max(maxL, i - diffMap[diff]);
            } else {
                diffMap[diff] = i;
            }
        }

        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.length();
        int maxL = 1;

        //Case-1
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                count++;
            } else {
                maxL = max(maxL, count);
                count = 1;
            }
        }
        maxL = max(maxL, count);


        //Case-2
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'b', 'c'));


        //Case-3
        unordered_map<string, int> diffMap;

        int countA = 0;
        int countB = 0;
        int countC = 0;

        for(int i = 0; i < n; i++) {

            if(s[i] == 'a') countA++;
            if(s[i] == 'b') countB++;
            if(s[i] == 'c') countC++;

            if(countA == countB && countA == countC) {
                maxL = max(maxL, countA + countB + countC);
            }

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            string state = to_string(diffAB) + "_" + to_string(diffAC);

            if(diffMap.count(state)) {
                maxL = max(maxL, i - diffMap[state]);
            } else {
                diffMap[state] = i;
            }
        }

        return maxL;
    }
};