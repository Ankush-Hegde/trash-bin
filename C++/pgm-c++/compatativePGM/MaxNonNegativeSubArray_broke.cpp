


vector<int> Solution::maxset(vector<int> &A) {
    int N = A.size();
    int largestSum = 0;
    int tempStartIndex = 0, tempEndIndex = 0, tempSum = 0;
    int flagNoNegative = 1;
    int startIndex = 0, endIndex = 0;
    vector<int> result;
    
    for (int i = 0; i < N; i++) {
        if (A[i] <= -1) {
            flagNoNegative = 0;
            
            if (tempSum >= largestSum) {
                largestSum = tempSum;
                
                startIndex = tempStartIndex;
                
                endIndex = tempEndIndex;
            }
            
            tempSum = 0;
            tempStartIndex = i + 1;
            tempEndIndex = i + 1;
            
        } else {
            tempSum += A[i];
            tempEndIndex = i;
        }
    }
    
    if (flagNoNegative) {
        return A;
    } else {
        if (tempSum >= largestSum) {
            largestSum = tempSum;
            
            startIndex = tempStartIndex;
            
            endIndex = tempEndIndex;
        }
        
        if (startIndex == endIndex && A[startIndex] <= -1) {
            return result;
        }
        
        for (int i = startIndex; i <= endIndex; i++) {
            result.push_back(A[i]);
        }
        
        return result;
    }
}
