/**********************************************************************************************************************
 * Black-Scholes Option Pricer
 *
 * Main entry point. Run different test cases by toggling the options below
 *
 * Created by Michael Lewis on 8/2/20.
 *********************************************************************************************************************/

#include "TestBatches.hpp"
#include "TestBuilder.hpp"
#include "TestExtras.hpp"

// Comment or uncomment to toggle test cases
int main() {

    // Hard-coded test cases
    TestBatches batchTests;
    batchTests.RunTest();

    // Test Builder Pattern, which allows the user to input option data
//    TestBuilder builderTest;
//    builderTest.RunTest();

    // Test extras
//    TestExtras extrasTest;
//    extrasTest.RunTest();
}