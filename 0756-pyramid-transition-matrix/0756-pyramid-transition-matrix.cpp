class Solution {
public:
    map<string, vector<string>> transitions;
    map<string, bool> memo;

    bool buildPyramid(int position,
                      string currentLayer,
                      string previousLayer,
                      int layerSize) 
    {
        if (layerSize == 1) return true;

        if (position == layerSize - 1) {
            if (memo.count(currentLayer))
                return memo[currentLayer];

            return memo[currentLayer] =
                   buildPyramid(0, "", currentLayer, layerSize - 1);
        }

        string pairBlocks = previousLayer.substr(position, 2);

        if (!transitions.count(pairBlocks))
            return false;

        for (auto nextBlock : transitions[pairBlocks]) {
            if (buildPyramid(position + 1,
                             currentLayer + nextBlock,
                             previousLayer,
                             layerSize))
                return true;
        }

        return false;
    }

    bool pyramidTransition(string bottomLayer,
                           vector<string>& allowed) 
    {
        int size = bottomLayer.size();

        for (auto rule : allowed) {
            transitions[rule.substr(0, 2)].push_back(rule.substr(2));
        }

        return buildPyramid(0, "", bottomLayer, size);
    }
};
