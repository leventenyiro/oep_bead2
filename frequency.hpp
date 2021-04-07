#pragma once

#include <fstream>
#include "contest.hpp"

using namespace std;

struct Frequency {
    int year, piece;
};

class FrequencyEnor {
    private:
        ifstream _file;
        ContestEnor _contestEnor;
        Frequency _current;
        bool _end;

    public:
        FrequencyEnor(const string &filename): _contestEnor(filename) {};
        void first() { _contestEnor.first(); next(); };
        void next();
        Frequency current() { return _current; };
        bool end() { return _end; };
};

void FrequencyEnor::next() {
    if (_contestEnor.end()) {
        _end = true;
        return;
    }
    int piece = 0, prev = _contestEnor.current().year;
    while (!_contestEnor.end() && _contestEnor.current().year == prev) {
        piece++;
        _contestEnor.next();
    }

    _current.piece = piece;
    _current.year = prev;
}