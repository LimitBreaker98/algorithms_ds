def levDist(str1, str2, m, n):
    if m == 0:
        return n
    if n == 0:
        return m
    if str1[m-1] == str2[n-1]:
        return levDist(str1, str2, m-1, n-1)
    
    return 1 + min(levDist(str1, str2, m, n-1),
                   levDist(str1, str2, m-1, n),
                   levDist(str1, str2, m-1, n-1)
                   )

str1 = "abc"
str2 = "abcx"
print (levDist(str1, str2, len(str1), len(str2)))
 