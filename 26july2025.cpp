long long maxSubarrays(int n, std::vector<std::vector<int>>& conflicts) {
    std::vector<std::vector<int>> conflictWith(n + 1);
    for (const auto& pair : conflicts) {
        int a = std::max(pair[0], pair[1]);
        int b = std::min(pair[0], pair[1]);
        conflictWith[a].push_back(b);
    }

    long long result = 0;
    std::vector<long long> topTwo = {0, 0};
    std::vector<long long> gain(n + 1, 0);

    for (int end = 1; end <= n; ++end) {
        for (int conflictStart : conflictWith[end]) {
            if (conflictStart > topTwo[0]) {
                topTwo = {conflictStart, topTwo[0]};
            } else if (conflictStart > topTwo[1]) {
                topTwo = {topTwo[0], conflictStart};
            }
        }

        result += end - topTwo[0];

        if (topTwo[0] > 0) {
            gain[topTwo[0]] += topTwo[0] - topTwo[1];
        }
    }

    long long bestGain = *std::max_element(gain.begin(), gain.end());
    return result + bestGain;
}
