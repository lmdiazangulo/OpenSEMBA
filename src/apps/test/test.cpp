#include <stdio.h>
#include <gtest/gtest.h>
#include <string>

using namespace std;

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  string tests;

  tests += "*ProjectFile*:";
  tests += "*Math*:";
  tests += "*Geometry*:";
//  tests += "*ParserSTL*:";
//  tests += "*ConformalMesherLauncherTest*:";
//  tests += "*EMSource*:";
//  tests += "*ParserGid*:";
//  tests += "*AdapterFDTDTest.OpenFOAMConversion*:";
//  tests += "*AdapterFDTDTest.UGRMesherConversion*:";

  //test += "*UGRMesher*";

  ::testing::GTEST_FLAG(filter) = tests.c_str();

//  ::testing::GTEST_FLAG(filter) = string("-AdapterFDTDTest.OpenFOAMConversion:-SembaTest.sphereThroughOpenfoam");

  return RUN_ALL_TESTS();
}
