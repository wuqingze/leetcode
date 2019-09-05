class Solution:

    def insert(self, intervals, newInterval):
        if None == intervals or [] == intervals:
            return [newInterval]
            
        index = 0
        n = len(intervals)
        i =0
        while i < n:
            if newInterval[0] < intervals[i][0]:
                if newInterval[1] < intervals[i][0]:
                    index = i
                    break
                elif newInterval[1] >= intervals[i][0] and newInterval[1] <= intervals[i][1]:
                    index = i+1
                    newInterval[1] = intervals[i][1]
                    break
                else:
                    index = i+1
            elif newInterval[0] >= intervals[i][0] and newInterval[0] <= intervals[i][1]:
                if newInterval[1] >= intervals[i][0] and newInterval[1] <= intervals[i][1]:
                    index = i+1
                    newInterval = None
                    break
                else:
                    newInterval[0] = intervals[i][0]
                    index = i + 1
            else:
                index = i + 1
            i += 1

        result = []
        if newInterval != None:
            i = 0
            while i < index:
                if intervals[i][1] < newInterval[0]:
                    result.append(intervals[i])
                else:
                    break
                i += 1

            result.append(newInterval)
            i = index
            while i<n:
                result.append(intervals[i])
                i += 1
        else:
            result = intervals
        return result

s = Solution()
# print(s.insert([[1,3],[6,9]],[2,5]))
# print(s.insert([[1,5]],[2,3]))
# print(s.insert([[1,2],[3,5],[6,7],[8,10],[12,16]],[4,8]))

# print(s.insert([[0,3]],[0,5]))
print(s.insert([[1,5]],[0,3]))
