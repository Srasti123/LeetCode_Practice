class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                if rootX < rootY:
                    parent[rootY] = rootX
                else :
                    parent[rootX] = rootY
        
        parent = {chr(i) : chr(i) for i in range(ord('a'), ord('z') + 1)}

        for i1, i2 in zip(s1, s2):
            union(i1, i2)
        res = []
        for c in baseStr:
            res.append(find(c))
        return "".join(res)