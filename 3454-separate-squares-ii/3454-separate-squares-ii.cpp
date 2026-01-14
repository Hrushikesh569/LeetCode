class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<long long, int, long long, long long>> sweepEvents;

        for (auto& square : squares) {
            long long x = square[0];
            long long y = square[1];
            long long side = square[2];

            sweepEvents.push_back({y, 1, x, x + side});
            sweepEvents.push_back({y + side, -1, x, x + side});
        }

        sort(sweepEvents.begin(), sweepEvents.end());

        vector<pair<long long, long long>> activeXIntervals;
        long long previousY = get<0>(sweepEvents[0]);
        long long totalArea = 0;

        vector<tuple<long long, long long, long long>> horizontalBands;

        auto getUnionWidth = [&](vector<pair<long long, long long>>& intervals) -> long long {
            sort(intervals.begin(), intervals.end());
            long long widthSum = 0;
            long long farRight = (long long)-1e18;

            for (auto& interval : intervals) {
                long long left = interval.first;
                long long right = interval.second;
                if (left > farRight) {
                    widthSum += right - left;
                    farRight = right;
                } else if (right > farRight) {
                    widthSum += right - farRight;
                    farRight = right;
                }
            }
            return widthSum;
        };
        for (auto& event : sweepEvents) {
            long long currentY = get<0>(event);
            int type = get<1>(event);
            long long leftX = get<2>(event);
            long long rightX = get<3>(event);
            if (currentY > previousY && !activeXIntervals.empty()) {
                long long height = currentY - previousY;
                long long width = getUnionWidth(activeXIntervals);
                horizontalBands.push_back({previousY, height, width});
                totalArea += height * width;
            }
            if (type == 1) {
                activeXIntervals.push_back({leftX, rightX});
            } else {
                auto it = find(activeXIntervals.begin(), activeXIntervals.end(),
                               make_pair(leftX, rightX));
                if (it != activeXIntervals.end()) {
                    activeXIntervals.erase(it);
                }
            }

            previousY = currentY;
        }

         double halfArea = (double)totalArea / 2.0;
        double coveredArea = 0.0;

        for (auto& band : horizontalBands) {
             long long bandStartY = get<0>(band);
         long long bandHeight = get<1>(band);
            long long bandWidth = get<2>(band);
            double bandArea = ( double)bandHeight * bandWidth;
            if (coveredArea + bandArea >= halfArea) {
                return (double)bandStartY +
                       (halfArea - coveredArea) / (double)bandWidth;
            }
            coveredArea += bandArea;
        } return (double)previousY;
    }
};
