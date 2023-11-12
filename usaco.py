# Compare files for usaco test cases

import os
import sys
import filecmp

directory = os.getcwd()

numArgs = len(sys.argv) - 1
argList = sys.argv

fileIn = argList[1]
fileOut = fileIn[:-3]+'.out'
fileGen = argList[2]

good = filecmp.cmp(fileOut, fileGen)

if not good:
    print("FAILED TEST #:", fileIn[fileIn.rfind('/')+1:])
