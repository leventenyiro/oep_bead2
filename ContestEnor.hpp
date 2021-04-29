#pragma once

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Contest {
    string name;
    int year, point;
    bool hasHighJump;
};

class ContestEnor {
    private:
        ifstream _file;
        Contest _current;
        bool _end;

    public:
        enum Errors{ FILE_ERROR };
        ContestEnor(const string &str);
        void first() { next(); }
        void next();
        Contest current() { return _current; }
        bool end() const { return _end; }
};

ContestEnor::ContestEnor(const string &str) {
    _file.open(str.c_str());
    if (_file.fail()) throw FILE_ERROR;
}

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}

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

void ContestEnor::next() {
    string line;
    getline(_file, line);
    _current.name = "";
    if ( !(_end = _file.fail()) ) {
        istringstream is(line);

        string name = "";

        bool isStringNumber = false;
        while (!isStringNumber) {
            is >> name;
            if (isNumber(name)) {
                isStringNumber = true;
            } else {
                _current.name += name + " ";
            }
        }
        _current.name.pop_back();

        _current.year = atoi(name.c_str());
        string contest;
        int position;

        int point = 0;
        bool isHighJump = false;
        is >> contest >> position;
        while (!is.fail()) {
            point += getPoint(position);

            if (contest == "magasugrás")
                isHighJump = true;
            is >> contest >> position;
        }

        _current.hasHighJump = isHighJump;
        _current.point = point;
    }
}