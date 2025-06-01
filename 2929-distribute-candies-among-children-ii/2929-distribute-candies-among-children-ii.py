class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        def count_ways(n):
            if n < 0:
                return 0
            return (n + 2) * (n + 1) // 2  

        total = count_ways(n)
        total -= 3 * count_ways(n - (limit + 1))
        total += 3 * count_ways(n - 2 * (limit + 1))
        total -= count_ways(n - 3 * (limit + 1))

        return total
