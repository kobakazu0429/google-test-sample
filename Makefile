all:
	gcc-9 -c target.c
	g++-9 test.cpp googletest-release-1.10.0/googletest/src/gtest_main.cc gtest/gtest-all.cc -I. -lpthread target.o
	./a.out
