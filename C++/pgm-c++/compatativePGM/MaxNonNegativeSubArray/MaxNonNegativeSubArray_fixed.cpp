/*
Max Non Negative SubArray
Programming
Arrays
easy
15.1% Success

210

109

Bookmark
Asked In:
Problem Description

Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:  

If there is a tie, then compare with segment's length and return segment which has maximum length.
If there is still a tie, then return the segment with minimum starting index.


Problem Constraints
1 <= N <= 105

-109 <= A[i] <= 109



Input Format
The first and the only argument of input contains an integer array A, of length N.



Output Format
Return an array of integers, that is a subarray of A that satisfies the given conditions.



Example Input
Input 1:

 A = [1, 2, 5, -7, 2, 3]
Input 2:

 A = [10, -1, 2, 3, -4, 100]


Example Output
Output 1:

 [1, 2, 5]
Output 2:

 [100]


Example Explanation
Explanation 1:

 The two sub-arrays are [1, 2, 5] [2, 3].
 The answer is [1, 2, 5] as its sum is larger than [2, 3].
Explanation 2:

 The three sub-arrays are [10], [2, 3], [100].
 The answer is [100] as its sum is larger than the other two. 
 */

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
