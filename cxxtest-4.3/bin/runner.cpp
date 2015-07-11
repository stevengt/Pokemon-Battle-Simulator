/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <TestListener.h>
#include <TestTracker.h>
#include <TestRunner.h>
#include <RealDescriptions.h>
#include <TestMain.h>
#include <ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_AttackTests_init = false;
#include "/Users/sthomas2/Documents/Code/of_v0.8.4_osx_release/apps/myApps/Pokemon/tests/AttackTests.h"

static AttackTests suite_AttackTests;

static CxxTest::List Tests_AttackTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_AttackTests( "./tests/AttackTests.h", 9, "AttackTests", suite_AttackTests, Tests_AttackTests );

static class TestDescription_suite_AttackTests_testEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AttackTests_testEquals() : CxxTest::RealTestDescription( Tests_AttackTests, suiteDescription_AttackTests, 13, "testEquals" ) {}
 void runTest() { suite_AttackTests.testEquals(); }
} testDescription_suite_AttackTests_testEquals;

#include "/Users/sthomas2/Documents/Code/of_v0.8.4_osx_release/apps/myApps/Pokemon/tests/BagTests.h"

static BagTests suite_BagTests;

static CxxTest::List Tests_BagTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_BagTests( "./tests/BagTests.h", 7, "BagTests", suite_BagTests, Tests_BagTests );

static class TestDescription_suite_BagTests_testConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BagTests_testConstructor() : CxxTest::RealTestDescription( Tests_BagTests, suiteDescription_BagTests, 11, "testConstructor" ) {}
 void runTest() { suite_BagTests.testConstructor(); }
} testDescription_suite_BagTests_testConstructor;

static class TestDescription_suite_BagTests_testAddItem : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BagTests_testAddItem() : CxxTest::RealTestDescription( Tests_BagTests, suiteDescription_BagTests, 18, "testAddItem" ) {}
 void runTest() { suite_BagTests.testAddItem(); }
} testDescription_suite_BagTests_testAddItem;

static class TestDescription_suite_BagTests_testRemoveItem : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BagTests_testRemoveItem() : CxxTest::RealTestDescription( Tests_BagTests, suiteDescription_BagTests, 34, "testRemoveItem" ) {}
 void runTest() { suite_BagTests.testRemoveItem(); }
} testDescription_suite_BagTests_testRemoveItem;

static class TestDescription_suite_BagTests_testEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BagTests_testEquals() : CxxTest::RealTestDescription( Tests_BagTests, suiteDescription_BagTests, 75, "testEquals" ) {}
 void runTest() { suite_BagTests.testEquals(); }
} testDescription_suite_BagTests_testEquals;

#include "/Users/sthomas2/Documents/Code/of_v0.8.4_osx_release/apps/myApps/Pokemon/tests/ItemTests.h"

static ItemTests suite_ItemTests;

static CxxTest::List Tests_ItemTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ItemTests( "./tests/ItemTests.h", 9, "ItemTests", suite_ItemTests, Tests_ItemTests );

static class TestDescription_suite_ItemTests_testEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ItemTests_testEquals() : CxxTest::RealTestDescription( Tests_ItemTests, suiteDescription_ItemTests, 13, "testEquals" ) {}
 void runTest() { suite_ItemTests.testEquals(); }
} testDescription_suite_ItemTests_testEquals;

#include "/Users/sthomas2/Documents/Code/of_v0.8.4_osx_release/apps/myApps/Pokemon/tests/PokemonTests.h"

static PokemonTests suite_PokemonTests;

static CxxTest::List Tests_PokemonTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_PokemonTests( "./tests/PokemonTests.h", 9, "PokemonTests", suite_PokemonTests, Tests_PokemonTests );

static class TestDescription_suite_PokemonTests_testAddAttack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PokemonTests_testAddAttack() : CxxTest::RealTestDescription( Tests_PokemonTests, suiteDescription_PokemonTests, 13, "testAddAttack" ) {}
 void runTest() { suite_PokemonTests.testAddAttack(); }
} testDescription_suite_PokemonTests_testAddAttack;

static class TestDescription_suite_PokemonTests_testRemoveAttack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PokemonTests_testRemoveAttack() : CxxTest::RealTestDescription( Tests_PokemonTests, suiteDescription_PokemonTests, 29, "testRemoveAttack" ) {}
 void runTest() { suite_PokemonTests.testRemoveAttack(); }
} testDescription_suite_PokemonTests_testRemoveAttack;

#include "/Users/sthomas2/Documents/Code/of_v0.8.4_osx_release/apps/myApps/Pokemon/tests/TrainerTests.h"

static TrainerTests suite_TrainerTests;

static CxxTest::List Tests_TrainerTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TrainerTests( "./tests/TrainerTests.h", 9, "TrainerTests", suite_TrainerTests, Tests_TrainerTests );

static class TestDescription_suite_TrainerTests_testAddPokemon : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TrainerTests_testAddPokemon() : CxxTest::RealTestDescription( Tests_TrainerTests, suiteDescription_TrainerTests, 13, "testAddPokemon" ) {}
 void runTest() { suite_TrainerTests.testAddPokemon(); }
} testDescription_suite_TrainerTests_testAddPokemon;

static class TestDescription_suite_TrainerTests_testRemovePokemon : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TrainerTests_testRemovePokemon() : CxxTest::RealTestDescription( Tests_TrainerTests, suiteDescription_TrainerTests, 31, "testRemovePokemon" ) {}
 void runTest() { suite_TrainerTests.testRemovePokemon(); }
} testDescription_suite_TrainerTests_testRemovePokemon;

#include <Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
