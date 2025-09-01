class Solution(object):
    def maxAverageRatio(self, classes, extraStudents):
        def gain(p, t):
            return float((p + 1)) / float(t + 1) - float(p) / float(t)

        heap = [(-gain(p, t), p, t) for p, t in classes]
        heapq.heapify(heap)
        print(heap)
        for _ in range(extraStudents):
            g, p, t = heapq.heappop(heap)
            p, t = p + 1, t + 1
            heapq.heappush(heap, (-gain(p, t), p, t))

        total = sum(float(p) / float(t) for _, p, t in heap)
        print(total)
        print(heap)
        return total / len(classes)
                


        