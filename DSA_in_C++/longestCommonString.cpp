     //solution 1 time complexity O(m*n*min(m,n)) space O(1)
    int longestCommonSubstr(string str1, string str2) {
        your code here
        int length=0, counter=0;
        int indexOfStr1, indexOfStr2, startIndex;
        
        for (int i=0;i<str1.size();i++) {
            for (int j=0;j<str2.size();j++) {
                counter=0;
                while(j+counter < str2.size() && i+counter < str1.size() && str1[i+counter]==str2[j+counter]) {
                    counter++;
                }
                length=max(length, counter);
            }
        }
        return length;
    }

    // solution2     
    int longestCommonSubstr(string str1, string str2) {
        int res = 0;
        
        for (int i = 0; i < str1.size(); i++) {
            for (int j = 0; j < str2.size(); j++) {
                res = max(res, LCSuf(str1, str2, i, j));
            }
        }
        return res;
    }
    
    int LCSuf(const string& s1, const string& s2, int m, int n) {
        if (m >= s1.size() || n >= s2.size() || s1[m] != s2[n])
            return 0;
        return 1 + LCSuf(s1, s2, m+1, n+1);
    }
    
    //solution 3 
    int longestCommonSubstr(string str1, string str2) {    
        int m = str1.length();
        int n = str2.length();
        
        vector<vector<int>> LCSuf(m + 1, vector<int>(n + 1, 0));
    
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    LCSuf[i][j] = LCSuf[i - 1][j - 1] + 1;
                    res = max(res, LCSuf[i][j]);
                } else {
                    LCSuf[i][j] = 0;
                }
            }
        }
        return res;
    }
    
    //solution 4 time:O(m*n) space:O(m*n)
    int longestCommonSubstr(string str1, string str2) {    
        int m = str1.length();
        int n = str2.length();
        
        vector<vector<int>> LCSuf(m, vector<int>(n, 0));
    
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (str1[i] == str2[j]) {
                    if (i == 0 || j == 0) {
                        LCSuf[i][j] = 1;
                    } else {
                        LCSuf[i][j] = LCSuf[i - 1][j - 1] + 1;
                    }
                    res = max(res, LCSuf[i][j]);
                } else {
                    LCSuf[i][j] = 0;
                }
            }
        }
        
        return res;
    }