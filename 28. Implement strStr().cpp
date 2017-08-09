int strStr(string haystack, string needle) {
        
        /*暴力解法
        int m = haystack.size(), n = needle.size();
        if(m < n)
            return -1;
        if(n == 0)
            return 0;
        for(int i = 0; i <= m-n; i++){
            int p = i, q = 0;
            while(q < n && haystack[p] == needle[q]){
                ++p;
                ++q;
            }
            if(q == n)
                return i;
        }
        return -1;
        */
        
        /*KMP解法*/
        int m = haystack.size(), n = needle.size();
        if(m < n)
            return -1;
        if(n == 0)
            return 0;
        
        /*求解next数组*/
        vector<int> next(n, 0);     //next数组
        next[0] = -1;
        int i = 0, j = -1;
        while(i < n - 1){
            if(j == -1 || needle[i] == needle[j]){
                ++i;
                ++j;
                if(needle[i] != needle[j])
                    next[i] = j;
                else
                    next[i] = next[j];
            }
            else
                j = next[j];
        }
        
        /*根据求得的next数组进行匹配*/
        i = 0, j = 0;
        while(i < m && j < n){
            if(j == -1 || haystack[i] == needle[j]){
                ++i;
                ++j;
            }
            else
                j = next[j];
        }
        if(j == n)
            return i - n;
        
        return -1;
    }
