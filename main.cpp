#include <iostream>

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main() {
    
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#endif