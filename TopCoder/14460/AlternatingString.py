class AlternatingString:
    def maxLength(self,s):
        max_alt = 1
        cur_alt = 1
        for i in range(1,len(s)):
            if s[i] != s[i-1]:
                cur_alt += 1
            else:
                cur_alt = 1
            if max_alt < cur_alt:
                max_alt = cur_alt
        return max_alt
    
            
