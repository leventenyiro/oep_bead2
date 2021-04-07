#pragma once

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Contest {
    string name;
    int year, highJumpPosition;
};

class ContestEnor {
    private:
        enum Status {
            ABNORM,
            NORM
        };

        ifstream _file;
        Contest _current;
        Status _status;
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

void ContestEnor::next() {
    string line;
    getline(_file, line);
    _current.name = "";
    if ( !(_end = _file.fail()) ) {
        istringstream is(line);

        string element = "";

        bool isStringNumber = false;
        while (!isStringNumber) {
            is >> element;
            if (isNumber(element)) {
                isStringNumber = true;
            } else {
                _current.name += element + " ";
            }
        }
        _current.name.pop_back();

        _current.year = atoi(element.c_str());
        string contest;
        int position;
        while (!is.fail()) {
            is >> contest >> position;
            if (contest == "magasugrás")
                _current.highJumpPosition = position;
        }
    }
}