#include <iostream>
#include "enor.hpp"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

// First task


int main() {
    Enor t("input.txt");
    for (t.first(); !t.end(); t.next()) {
        
    }
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#endif