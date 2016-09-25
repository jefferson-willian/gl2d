all:
	cd gl2d && make
	cd graphics && make

test:
	cd gl2d && make
	cd gl2d/external/googletest/googletest && make
	cd gl2d/test && make && ./unittest
