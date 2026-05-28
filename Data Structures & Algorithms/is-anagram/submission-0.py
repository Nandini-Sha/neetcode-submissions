class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        shash = [0]*26
        thash = [0]*26

        for i in range(len(s)):
            shash[ord(s[i])-ord('a')] += 1
            thash[ord(t[i])-ord('a')] += 1

        for i in range(26):
            if shash[i]!=thash[i]:
                return False

        return True