vector<int> Solution::maxset(vector<int> &A) {
    int N = A.size();
    long long largestSum = 0, tempSum = 0; // Use long long for large sums
    int tempStartIndex = 0, tempEndIndex = 0;
    int startIndex = -1, endIndex = -1; // Initialize to -1 to handle edge cases
    vector<int> result;

    for (int i = 0; i < N; i++) {
        if (A[i] < 0) { // Use `A[i] < 0` for clarity
            if (tempSum > largestSum || (tempSum == largestSum && (tempEndIndex - tempStartIndex > endIndex - startIndex))) {
                largestSum = tempSum;
                startIndex = tempStartIndex;
                endIndex = tempEndIndex;
            }
            tempSum = 0;
            tempStartIndex = i + 1;
        } else {
            tempSum += A[i];
            tempEndIndex = i;
        }
    }

    // Handle the last segment after the loop
    if (tempSum > largestSum || (tempSum == largestSum && (tempEndIndex - tempStartIndex > endIndex - startIndex))) {
        startIndex = tempStartIndex;
        endIndex = tempEndIndex;
    }

    // If no valid subarray found, return an empty result
    if (startIndex == -1) {
        return result;
    }

    for (int i = startIndex; i <= endIndex; i++) {
        result.push_back(A[i]);
    }

    return result;
}
