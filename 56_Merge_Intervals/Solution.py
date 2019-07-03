class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if intervals == None or len(intervals) == 0:
            return []


        intervals.sort(key = lambda interval : interval[1])
        result = [intervals[0]]

        n = len(intervals)
        for i in range(1,n):
            if intervals[i][0] > result[-1][1]:
                result.append(intervals[i])
            else:
                t = intervals[i]
                while len(result)>0 and t[0]<=result[-1][1]:
                    interval = result.pop()
                    if interval[0] < t[0]:
                        t = [interval[0],t[1]]

                result.append(t)
        return result
