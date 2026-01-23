class Solution {
public:
    typedef long long ll;

    int minimumPairRemoval(vector<int>& nums) {
        int size = nums.size();

        vector<ll> values(size);
        for (int i = 0; i < size; i++) {
            values[i] = nums[i];
        }

        set<pair<ll, int>> pairSet;

        vector<int> next(size), prev(size);
        for (int i = 0; i < size; i++) {
            next[i] = i + 1;
            prev[i] = i - 1;
        }

        int inversionCount = 0;

        for (int i = 0; i < size - 1; i++) {
            if (values[i] > values[i + 1]) {
                inversionCount++;
            }
            pairSet.insert({values[i] + values[i + 1], i});
        }

        int operations = 0;

        while (inversionCount > 0) {

            int left = pairSet.begin()->second;
            int right = next[left];

            int leftNeighbor = prev[left];
            int rightNeighbor = next[right];

            pairSet.erase(pairSet.begin());

            if (values[left] > values[right]) {
                inversionCount--;
            }

            if (leftNeighbor >= 0) {
                if (values[leftNeighbor] > values[left] &&
                    values[leftNeighbor] <= values[left] + values[right]) {
                    inversionCount--;
                } else if (values[leftNeighbor] <= values[left] &&
                           values[leftNeighbor] > values[left] + values[right]) {
                    inversionCount++;
                }
            }

            if (rightNeighbor < size) {
                if (values[rightNeighbor] >= values[right] &&
                    values[rightNeighbor] < values[left] + values[right]) {
                    inversionCount++;
                } else if (values[rightNeighbor] < values[right] &&
                           values[rightNeighbor] >= values[left] + values[right]) {
                    inversionCount--;
                }
            }

            if (leftNeighbor >= 0) {
                pairSet.erase({values[leftNeighbor] + values[left], leftNeighbor});
                pairSet.insert({values[leftNeighbor] + values[left] + values[right], leftNeighbor});
            }

            if (rightNeighbor < size) {
                pairSet.erase({values[right] + values[rightNeighbor], right});
                pairSet.insert({values[left] + values[right] + values[rightNeighbor], left});
                prev[rightNeighbor] = left;
            }

            next[left] = rightNeighbor;
            values[left] += values[right];

            operations++;
        }

        return operations;
    }
};
