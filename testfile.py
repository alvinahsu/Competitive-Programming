# Python script to help create cpp template files and directory for contests

import os
import sys
from datetime import datetime

# Arg[1] : Contest type
# CF = CodeForces
# AC = AtCoder
# US = USACO
# LC = LeetCode
# Arg[2] : Contest number
# Arg[3...] : File Names 

numArgs = len(sys.argv) - 1
argList = sys.argv

#check if we contest name and number
if numArgs < 2:
	print("At Least Two Arguments Are Required (Contest Type and Number)")
	exit(1)

contestTypes = {"AC" : "AtCoder", "CF" : "CodeForces", "US" : "USACO", "LC" : "LeetCode"}

currContestType = argList[1]
currContestNum = argList[2]

#check if valid contest
if currContestType not in contestTypes.keys():
	print("Invalid Contest Type ", currContestType, "(Add Or Change Contest Type)")

#check if contest directory exists
contestTypePath = '/Users/alvinhsu/Coding/Contests/' + contestTypes[currContestType]
contestTypeExists = os.path.exists(contestTypePath)

#create contest type directory if not exists
if not contestTypeExists:
	os.mkdir(contestTypePath)

#create directory for contest number
contestName = currContestType + currContestNum
contestFolderNamePath = contestTypePath + '/' + contestName
contestFolderExists = os.path.exists(contestFolderNamePath)

#create contest folder directory if not exists
if not contestFolderExists:
	os.mkdir(contestFolderNamePath)

now = datetime.now()
dateTime = now.strftime("%d/%m/%Y %H:%M:%S")
headerInfo = '''\
/*
*  File: {fname}
*  Author: Alvin hsu 
*  Date: {date}
*/

'''.format(fname=contestName, date=dateTime)

templatePath = '/Users/alvinhsu/Coding/Contests/Templates/main.cpp'
templateFile = open(templatePath, "r")
templateText = templateFile.read()

#create template files (will throw error if one of the file exists)
for i in range(3, numArgs+1):
	fileName = argList[i] + ".cpp"
	filePath = contestFolderNamePath + '/' + fileName
	
	fileExists = os.path.exists(filePath)
	
	if not fileExists:
		createdFile = open(filePath, "w")
		createdFile.write(headerInfo)
		createdFile.write(templateText)
	else:
		print(fileName + " already exists")
		




