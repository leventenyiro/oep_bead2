#include <iostream>
#include "contest.hpp"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int getPoint(int position) {
    switch (position)
    {
        case 1: return 12; break;
        case 2: return 10; break;
        case 3: return 8; break;
        case 4: return 6; break;
        case 5: return 4; break;
        case 6: return 2; break;
        default: return 0; break;
    }
}

bool firstTask(const string &filename, Contest& element) {
    /*
        kinek volt a legtöbb pontja
        mikor és mennyi
        1. - 12 pont
        2. - 10 pont...
    */
    ContestEnor contest(filename);
    bool isExist = false;
    int maxPoint = 0;
    contest.first();
    while (!contest.end()) {
        //cout << contest.current().highJumpPosition;
        Contest current = contest.current();
        if (contest.current().highJumpPosition != NULL && (contest
        .current().highJumpPosition) > maxPoint) {
            element = contest.current();
            maxPoint = getPoint(element.highJumpPosition);
            isExist = true;
        }
        contest.next();
    }
    
    return isExist;
}

int main() {
    string filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;

    // first task
    cout << "First task" << endl;
    try {
        Contest element;
        if (firstTask(filename, element)) {
            cout << "Highest point in high jump: " << element.name << " (" << element.year << ") - " << getPoint(element.highJumpPosition) << " point(s)";
        } else {
            cout << "Nobody takes part in the contest of high jump!";
        }
    } catch (ContestEnor::Errors err) {
        cerr << "Cannot find the input file: " << filename << endl;
    }
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#endif