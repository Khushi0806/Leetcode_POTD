class Solution {
public:
    int maximumGain(string s, int x, int y) {
        auto remove = [](string &s, char a, char b, int gain) {
            string result = "";
            int score = 0;
            for (char c : s) {
                if (!result.empty() && result.back() == a && c == b) {
                    result.pop_back();  // Remove matched pair
                    score += gain;
                } else {
                    result.push_back(c);  // Add to simulated stack
                }
            }
            s = result;  // Update input string for next phase
            return score;
        };

        int totalScore = 0;
        if (x > y) {
            // Prioritize 'ab'
            totalScore += remove(s, 'a', 'b', x);
            totalScore += remove(s, 'b', 'a', y);
        } else {
            // Prioritize 'ba'
            totalScore += remove(s, 'b', 'a', y);
            totalScore += remove(s, 'a', 'b', x);
        }

        return totalScore;
    }
};
