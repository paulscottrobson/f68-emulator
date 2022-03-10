# *******************************************************************************************************************************
# *******************************************************************************************************************************
#
#		Name:		buildcount.py
#		Purpose:	Configuration analysis script
#		Created:	10th March 2022
#		Author:		Paul Robson (paul@robsons->org.uk)
#
# *******************************************************************************************************************************
# *******************************************************************************************************************************

import os,re 

f = "../include/generated/buildnumber.h".replace("/",os.sep)
n = 0
h = open(f,"r")
for l in h.readlines():
	m = re.search("BUILD_COUNT\\s*\\((\\d+)\\)",l)
	if m is not None:
		n = int(m.group(1))
h.close()

n = n + 1
h = open(f,"w")
h.write("//\n//\tAutomatically generated.\n//\n")
h.write("#define BUILD_COUNT ({0})\n".format(n))
h.close()
print("Build # {0}".format(n))