ifeq ($(OS),Windows_NT)
include ..\..\documents\common.make
else
include ../../documents/common.make
endif

all:
	python setup.py
ifeq ($(OS),Windows_NT)
	python buildcount.py
endif
