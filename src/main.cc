/**
 * @file main.cc
 * @brief gtest test!!!
 * @author sunrlong <sunrlong@gmail.com>
 * @version 0.0.1
 * @date 2015-09-04
 */

#include "gtest/gtest.h"
#include <iostream>

using std::cout;
using std::endl;

int Foo(int a, int b){
	return a+b;
}


TEST(FooTest, FooTestName){
	EXPECT_EQ(5,Foo(2,3));
	EXPECT_EQ(10,Foo(12,3));
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

