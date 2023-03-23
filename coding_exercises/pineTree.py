from collections import deque

"""
const printPineTree = (segments: number, height: number) => {

}


/*

printPineTree(2, 3)

   *
  *** -> ['*', '*', '*'] -> currently length 3.
 *****
  ***
 *****
******* -> ['*', '*', '*', '*', '*', '*', '*'] <-
   *
   *
 *****

printPineTree(3, 4)

     *
    ***
   *****
  *******
    ***
   *****
  *******
 *********
   *****
  *******
 *********
***********
     *
     *
 *********


printPineTree(4, 6)

        *
       ***
      *****
     *******
    *********
   ***********
       ***
      *****
     *******
    *********
   ***********
  *************
      *****
     *******
    *********
   ***********
  *************
 ***************
     *******
    *********
   ***********
  *************
 ***************
*****************. <- this does not require spacing
        *
        *
 ***************

*/
"""

"""
    segments(int)  height: (int)
    *
    ***
    *****
    ***
    *****
    ******* -> length of longest row = 7
    *
    *
    *****

    Steps:
    1. first, generate all the asterisks per row as double ended queues
        1.1 Also add two rows of one asterisk and a row of the length of the longest -2
    2. Add prefix and suffix spacing to those strings so that they all match the longest row of just asterisks.
"""

def getSegment(start, height):
    currSegment = []
    currLongestRow = -1 
    for rowIdx in range(height):
        asterisksInRow = rowIdx * 2 + start
        newRow = ["*" for _ in range(asterisksInRow)]
        currLongestRow = max(len(newRow), currLongestRow)
        currSegment.append(newRow)
    return currSegment, currLongestRow

def getTrunkSegment(baseLength):
    trunkSegment = [getSegment(1, 1)[0] for _ in range(2)]
    trunkSegment.append(getSegment(baseLength, 1)[0])
    return trunkSegment

def getRowsWithSpacing(allSegments, longestRow):
    rowsWithSpacing = []
    for segment in allSegments:
        for row in segment:
            finalRow = deque(row)
            currLen = len(finalRow)
            while longestRow - currLen > 0:
                finalRow.appendleft(" ")
                finalRow.append(" ")
                currLen += 2
            rowsWithSpacing.append(finalRow)
    return rowsWithSpacing



def printPineTree(segments, height):
    allSegments = []
    longestRow = -1
    # ["*", "*", "*"] <-
    for segmentIdx in range(segments):
        currSegment, currLongestRow = getSegment(segmentIdx * 2 + 1, height)
        longestRow = max(currLongestRow, longestRow)
        allSegments.append(currSegment)
    
    # [['*'], ["*", "*", "*"]
    
    trunkSegment = getTrunkSegment(longestRow-2)
    allSegments.extend(trunkSegment)

    rowsWithSpacing = getRowsWithSpacing(allSegments, longestRow)

    for row in rowsWithSpacing:
        print("".join(row))
    

printPineTree(2, 3)
printPineTree(3, 4)
printPineTree(4, 6)
    


