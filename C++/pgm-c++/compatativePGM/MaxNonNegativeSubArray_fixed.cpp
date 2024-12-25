vector<int> Solution::maxset(vector<int> &A) {
    int N = A.size();
    long long largestSum = 0, tempSum = 0;
    int tempEndIndex = 0, tempStartIndex = 0;
    int flagNoNegative = 1;
    int startIndex = 0, endIndex = 0;
    vector<int> result;
    
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            flagNoNegative = 0;
            
            if (tempSum > largestSum || (largestSum == tempSum &&(tempEndIndex - tempStartIndex > endIndex - startIndex))) {
                largestSum = tempSum;
                
                startIndex = tempStartIndex;
                
                endIndex = tempEndIndex;
            }
            
            tempSum = 0;
            tempStartIndex = i + 1;
            tempEndIndex = i + 1; // extra
            
        } else {
            tempSum += A[i];
            tempEndIndex = i;
        }
    }
    
    if (flagNoNegative) {
        return A;
    } else {
        if (tempSum > largestSum || (largestSum == tempSum &&(tempEndIndex - tempStartIndex > endIndex - startIndex))) {
            largestSum = tempSum;
            
            startIndex = tempStartIndex;
            
            endIndex = tempEndIndex;
        }
        
        if (startIndex == endIndex && A[startIndex] < 0) {
            return result;
        }
        
        for (int i = startIndex; i <= endIndex; i++) {
            result.push_back(A[i]);
        }
        
        return result;
    }
}
