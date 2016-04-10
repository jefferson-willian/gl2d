CC := g++ -std=c++11
CLANG := clang --analyze
CFLAGS := -Wall -Werror

PYTHON := python2.7

GTEST_DIR := ../../googletest/googletest/
GMOCK_DIR := ../../googletest/googlemock/
CPPLINT   := ../../styleguide/cpplint/cpplint.py --filter=-legal/copyright --root=cpp

-include Makefile.helper

_default: libgl2d.a

######### DEPENDENCIES #########

src/point.cpp:  include/point.h  build/util.o
src/util.cpp:   include/util.h
src/angle.cpp:  include/angle.h

######### BUILD #########

BUILD_CPP := $(wildcard src/*.cpp)
BUILD_HDD := $(wildcard include/*.h)
BUILD_OBJ := $(addprefix build/,$(notdir $(BUILD_CPP:.cpp=.o)))

libgl2d.a: ${BUILD_OBJ}
	$(call STD_STATIC_SHARED_LIBRARY, $@, $<)

build/%.o: src/%.cpp
	@mkdir -p build
	$(call STD_COMPILING, $@, $<, -I../ -isystem ${GTEST_DIR}/include)

######### TESTS #########

TEST_CPP := $(wildcard test/*.cpp)
TEST_OBJ := $(addprefix test/build/,$(notdir $(TEST_CPP:.cpp=.o)))

run-tests: bin/tester
	@./bin/tester

bin/tester: $(TEST_OBJ) $(BUILD_OBJ)
	@mkdir -p bin
	$(call STD_LINKING, $@, $^ ${GTEST_DIR}/libgtest.a, -lpthread)

test/build/%.o: test/%.cpp
	@mkdir -p test/build
	$(call STD_COMPILING, $@, $<, -I../ -isystem ${GTEST_DIR}/include)

cpplint:
	$(call STD_CPPLINT, ${PYTHON} ${CPPLINT}, ${BUILD_HDD} ${BUILD_CPP} ${TEST_CPP})

clang:
	$(call STD_CLANG, ${BUILD_CPP} ${TEST_CPP}, -I../ -isystem ${GTEST_DIR}/include)

clean:
	@rm -f build/*
	@rm -f test/build/*


# End:
