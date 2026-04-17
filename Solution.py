class Solution:
    def minMirrorPairDistance(self, nums):
        mp = {}
        ans = float('inf')

        def reverse_num(x):
            rev = 0
            while x > 0:
                rev = rev * 10 + (x % 10)
                x //= 10
            return rev

        for i, num in enumerate(nums):
            if num in mp:
                ans = min(ans, i - mp[num])
            mp[reverse_num(num)] = i

        return -1 if ans == float('inf') else ans
