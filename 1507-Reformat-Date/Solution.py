class Solution:
    def reformatDate(self, date: str) -> str:
        month = {"Jan":"01", "Feb":"02", "Mar":"03", "Apr":"04", "May":"05", "Jun":"06", "Jul":"07", "Aug":"08", "Sep":"09", "Oct":"10", "Nov":"11", "Dec":"12"}
        arr = date.split(" ")
        day = arr[0]
        if day[1] >= '0' and day[1] <= '9':
            day = day[0:2]
        else:
            day = day[0]
        if len(day) == 1:
            return arr[2]+"-"+month[arr[1]]+"-"+"0"+day
        else:
            return arr[2]+"-"+month[arr[1]]+"-"+day
