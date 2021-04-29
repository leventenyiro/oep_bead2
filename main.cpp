#include <iostream>
#include "ContestEnor.hpp"
#include "FrequencyEnor.hpp"

using namespace std;

// first task
bool firstTask(const string &filename, Contest& element) {
    ContestEnor contest(filename);
    bool isExist = false;
    int maxPoint = -1;
        contest.first();

    while (!contest.end()) {
        if (contest.current().hasHighJump && contest.current().point > maxPoint) {
            maxPoint = contest.current().point;
            element = contest.current();
            isExist = true;
        }
        contest.next();
    }

    return isExist;
}

// second task
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

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main() {
    string filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;

    // first task
    cout << "First task" << endl;
    try {
        Contest element;
        if (firstTask(filename, element))
            cout << "Highest point, who takes part in high jump: " << element.name << " (" << element.year << ") - " << element.point << " point(s)" << endl;
        else
            cout << "Nobody takes in high jump!" << endl;
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

TEST_CASE("file doesn't exist", "catch exception") {
    Contest e;
    CHECK_THROWS(firstTask("t.txt", e));
}

// first task
TEST_CASE("first task empty file", "t0.txt") {
    Contest e;
    CHECK_FALSE(firstTask("t0.txt", e));
}

TEST_CASE("first task 1 contest, true", "t1.txt") {
    Contest e;
    CHECK(firstTask("t1.txt", e));
    CHECK((e.name == "Nagyon Ügyes Péter" && e.year == 2018) == TRUE);
}

TEST_CASE("first task 1 contest, false", "t2.txt") {
    Contest e;
    CHECK_FALSE(firstTask("t2.txt", e));
}

TEST_CASE("first task more contest, first one meets the requirements", "t3.txt") {
    Contest e;
    CHECK(firstTask("t3.txt", e));
    CHECK((e.name == "Nagyon Ügyes Péter" && e.year == 2018) == TRUE);
}

TEST_CASE("first task more contest, second one meets the requirements", "t4.txt") {
    Contest e;
    CHECK(firstTask("t4.txt", e));
    CHECK((e.name == "Minta József" && e.year == 2019) == TRUE);
}

TEST_CASE("first task more contest, last one meets the requirements", "t5.txt") {
    Contest e;
    CHECK(firstTask("t5.txt", e));
    CHECK((e.name == "Példa Ferenc" && e.year == 2020) == TRUE);
}

TEST_CASE("first task more contest, no one meets the requirements", "t6.txt") {
    Contest e;
    CHECK_FALSE(firstTask("t6.txt", e));
}

TEST_CASE("first one earns the most points", "t7.txt") {
    Contest e;
    CHECK(firstTask("t7.txt", e));
    CHECK((e.name == "Nagyon Ügyes Péter" && e.year == 2018) == TRUE);
}

TEST_CASE("second one earns the most points", "t8.txt") {
    Contest e;
    CHECK(firstTask("t8.txt", e));
    CHECK((e.name == "Minta József" && e.year == 2019) == TRUE);
}

TEST_CASE("last one earns the most points", "t9.txt") {
    Contest e;
    CHECK(firstTask("t9.txt", e));
    CHECK((e.name == "Példa Ferenc" && e.year == 2020) == TRUE);
}

TEST_CASE("no one earns the most points, because the bad positions", "t10.txt") {
    Contest e;
    CHECK_FALSE(firstTask("t10.txt", e));
}

TEST_CASE("two contest, but equal position, first one will win", "t11.txt") {
    Contest e;
    CHECK(firstTask("t11.txt", e));
    CHECK((e.name == "Nagyon Ügyes Péter" && e.year == 2018) == TRUE);
}

// second task
TEST_CASE("empty file", "t0.txt") {
    Frequency f;
    CHECK_FALSE(secondTask("t0.txt", f));
}

TEST_CASE("one contest", "t1.txt") {
    Frequency f;
    CHECK(secondTask("t1.txt", f));
    CHECK((f.year == 2018));
}

TEST_CASE("two contest, but other years", "t11.txt") {
    Frequency f;
    CHECK(secondTask("t11.txt", f));
    CHECK((f.year == 2018));
}

TEST_CASE("three contest, but first and second are same year", "t3.txt") {
    Frequency f;
    CHECK(secondTask("t3.txt", f));
    CHECK((f.year == 2018));
}

TEST_CASE("three contest, but second and third are same year", "t4.txt") {
    Frequency f;
    CHECK(secondTask("t4.txt", f));
    CHECK((f.year == 2019));
}

#endif