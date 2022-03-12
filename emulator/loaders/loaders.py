# *******************************************************************************************************************************
# *******************************************************************************************************************************
#
#		Name:		loaders.py
#		Purpose:	Create demo PGX/PGZ files
#		Created:	12th March 2022
#		Author:		Paul Robson (paul@robsons->org.uk)
#
# *******************************************************************************************************************************
# *******************************************************************************************************************************

# *******************************************************************************************************************************
#
#													Simple file class
#
# *******************************************************************************************************************************


class BinaryFile(object):
	def __init__(self):
		self.data = []
	#
	def writeByte(self,b):
		self.data.append(b & 0xFF)
	#
	def writeLong(self,w,wSize):
		if wSize == 32:
			self.writeByte(w >> 24)
		self.writeByte(w >> 16)
		self.writeByte(w >> 8)
		self.writeByte(w)
	#
	def writeData(self,size):
		coreData = [ord(c) for c in "A1B2D4Z8-"]
		for i in range(0,size):
			self.writeByte(coreData[i % len(coreData)])
	#
	def save(self,fileName):
		open(fileName,"wb").write(bytes(self.data))

# *******************************************************************************************************************************
#
#													Create PGX file
#
# *******************************************************************************************************************************

bf = BinaryFile()
bf.writeByte(ord('P'))									# first 3 bytes are PGX
bf.writeByte(ord('G'))			
bf.writeByte(ord('X'))	

bf.writeByte(0x00 | 0x02) 								# Version 0, 680x0 data

bf.writeLong(0x0025678A,32)								# write a target address in 32 bit format
bf.writeData(128)										# write 128 bytes of quasi random data
bf.save("test.pgx")

# *******************************************************************************************************************************
#
#													Create 24/32 bit PGZ files
#
# *******************************************************************************************************************************

for sz in range(0,2):
	wordSize = 24 if sz == 0 else 32 					# two types of file here

	bf = BinaryFile()
	bf.writeByte(ord('Z') if wordSize==24 else ord('z'))# upper case Z is 24 bit, lowe case Z is 32 bit

	bf.writeLong(0x003579DF,wordSize) 					# address of first block
	bf.writeLong(32,wordSize)							# sze in bytes
	bf.writeData(32)									# data block.

	bf.writeLong(0x00280000,wordSize) 					# address of second block
	bf.writeLong(16,wordSize)							# sze in bytes
	bf.writeData(16)									# data block.

	bf.writeLong(0x00100000,wordSize) 					# start address
	bf.writeLong(0,wordSize) 							# data size 0 and no data

	bf.save("test{0}.pgz".format(wordSize))
