#include "../../include/test/UnitTestMain.h"

void runDirectionUnitTests(){
    testMod(Direction(3, 4, 0), 5);
    cout << "Direction unit tests passed." << endl;
}

void runAllUnitTests(){
    runDirectionUnitTests();

    cout << "ALL UNIT TESTS HAVE PASSED." << endl;

}