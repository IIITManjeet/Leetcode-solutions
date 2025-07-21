from typing import List
from collections import defaultdict

class Solution:
   def findRadius(self, houses: List[int], heaters: List[int]) -> int:
       max_house = max(max(houses),max(heaters))
       l, r = 0, max_house
       houses.sort()
       heaters.sort()

       while l < r:
           m = (l + r) // 2

           isHeated = defaultdict(bool)
           i = 0 
           for house in houses:
               while i + 1 < len(heaters) and abs(heaters[i + 1] - house) <= abs(heaters[i] - house):
                   i += 1
               if abs(heaters[i] - house) <= m:
                   isHeated[house] = True
               else:
                   isHeated[house] = False

           allHousesHeated = True
           for k, v in isHeated.items():
               if not v:
                   allHousesHeated = False
                   break

           if allHousesHeated:
               r = m
           else:
               l = m + 1

       return l
