#include <iostream>
#include "intersection.hpp"

using namespace std;

int main() {
    string strArr[] = {"1,3,5,7,13", "1,2,4,13,15"};
    cout << FindIntersection(strArr) << endl;
    return 0;
}