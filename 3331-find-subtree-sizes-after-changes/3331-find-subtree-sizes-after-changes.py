ENTER = 0
EXIT = 1

class Solution:
    def findSubtreeSizes(self, parent: list[int], s: str) -> list[int]:
        n = len(parent)
        first_child, next_sibling = [-1]*n, [-1]*n
        for x in range(n - 1, 0, -1):
            p = parent[x]
            next_sibling[x] = first_child[p]
            first_child[p] = x

        codes = [ord(ch) - 97 for ch in s]
        size = [1] * n
        last = [-1] * 26

        stack = [(0, ENTER, -1)]
        push = stack.append
        pop = stack.pop

        while stack:
            x, stage, above = pop()
            c = codes[x]
            if stage == ENTER:
                prev_last = last[c]
                child = first_child[x]
                if child == -1:
                    if x:
                        dest = prev_last if prev_last >= 0 else parent[x]
                        size[dest] += 1
                    continue

                push((x, EXIT, prev_last))
                last[c] = x
                while child != -1:
                    push((child, ENTER, -1))
                    child = next_sibling[child]
            else:
                last[c] = above
                if x:
                    dest = above if above >= 0 else parent[x]
                    size[dest] += size[x]

        return size
        