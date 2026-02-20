class Solution {
public:
    string makeLargestSpecial(string str) {
        vector<string> specialParts;
        int balance = 0;
        int segmentStart = 0;

        for (int i = 0; i < str.length(); i++) {
            balance += (str[i] == '1') ? 1 : -1;

            if (balance == 0) {
                string middlePart = str.substr(segmentStart + 1, i - segmentStart - 1);

                specialParts.push_back(
                    "1" + makeLargestSpecial(middlePart) + "0"
                );

                segmentStart = i + 1;
            }
        }

        sort(specialParts.begin(), specialParts.end(), greater<string>());

        string largestString;
        for (string &part : specialParts) {
            largestString += part;
        }

        return largestString;
    }
};