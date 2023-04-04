# Python script to help create cpp template files and directory for practice

import os
import sys
from datetime import datetime

# Arg[1] : Practice type
# CF = CodeForces
# AC = AtCoder
# US = USACO
# LC = LeetCode
# Arg[2] : Practice number
# Arg[3...] : File Names 

numArgs = len(sys.argv) - 1
argList = sys.argv

#check if we practice name and number
if numArgs < 2:
	print("At Least Two Arguments Are Required (Practice Type and Number)")
	exit(1)

practiceTypes = {"AC" : "AtCoder", "CF" : "CodeForces", "US" : "USACO", "LC" : "LeetCode"}
	
currPracticeType = argList[1]
currPracticeNum = argList[2]

#check if valid practice
if currPracticeType not in practiceTypes.keys():
	print("Invalid practice Type ", currPracticeType, "(Add Or Change practice Type)")

#check if practice directory exists
practiceTypePath = '/Users/alvinhsu/Coding/Practice/' + practiceTypes[currPracticeType]
practiceTypeExists = os.path.exists(practiceTypePath)

#create practice type directory if not exists
if not practiceTypeExists:
	os.mkdir(practiceTypePath)

#create directory for practice number
practiceName = currPracticeType + currPracticeNum
practiceFolderNamePath = practiceTypePath + '/' + practiceName
practiceFolderExists = os.path.exists(practiceFolderNamePath)

#create practice folder directory if not exists
if not practiceFolderExists:
	os.mkdir(practiceFolderNamePath)

now = datetime.now()
dateTime = now.strftime("%d/%m/%Y %H:%M:%S")

templatePath = '/Users/alvinhsu/Coding/Practice/Templates/main.cpp'
templateFile = open(templatePath, "r")
templateText = templateFile.read()

#create template files (will throw error if one of the file exists)
for i in range(3, numArgs+1):
	headerInfo = '''\
/*
*  File: {fname}
*  Author: Alvin Hsu 
*  Date: {date}
*/

'''.format(fname=practiceName+argList[i], date=dateTime)
	fileName = argList[i] + ".cpp"
	filePath = practiceFolderNamePath + '/' + fileName
	
	fileExists = os.path.exists(filePath)
	
	if not fileExists:
		createdFile = open(filePath, "w")
		createdFile.write(headerInfo)
		createdFile.write(templateText)
	else:
		print(fileName + " already exists")