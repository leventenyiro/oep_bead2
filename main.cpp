#include <iostream>
#include "contest.hpp"
#include "frequency.hpp"

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
    ContestEnor contest(filename);
    bool isExist = false;
    int maxPoint = 0;

    contest.first();
    while (!contest.end()) {
        Contest current = contest.current();
        if (contest.current().highJumpPosition != NULL && getPoint(contest.current().highJumpPosition) > maxPoint) {
            element = contest.current();
            maxPoint = getPoint(element.highJumpPosition);
            isExist = true;
        }
        contest.next();
    }
    
    return isExist;
}

bool secondTask(const string &filename, Frequency& mostYear) {
    FrequencyEnor frequency(filename);
    bool isExist = false;

    frequency.first();
    while (!frequency.end()) {
        if (frequency.current().piece > mostYear.piece) {
            mostYear = frequency.current();
            isExist = true;
        }
        frequency.next();
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
        if (firstTask(filename, element))
            cout << "Highest point in high jump: " << element.name << " (" << element.year << ") - " << getPoint(element.highJumpPosition) << " point(s)" << endl;
        else
            cout << "Nobody takes part in the contest of high jump!" << endl;
    } catch (ContestEnor::Errors err) {
        cerr << "Cannot find the input file: " << filename << endl;
    }

    // second task
    cout << "Second task" << endl;
    try {
        Frequency mostYear;
        if (secondTask(filename, mostYear))
            cout << "Most of the competitors participated in " << mostYear.year;
        else
            cout << "The file is empty!";
    } catch (ContestEnor::Errors err) {
        cerr << "Cannot find the input file: " << filename << endl;
    }
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#endif