#pragma once

#include <fstream>
#include <sstream>
#include <string>

#include <iostream>

using namespace std;

struct Contest {
    std::string name;
    int year;
    std::string contest;
    int position;
};

class Enor {
    private:
        enum Status {
            ABNORM,
            NORM
        };

        std::ifstream _file;
        Contest _current;
        Status _status;
        bool _end;

    public:
        enum Errors{ FILE_ERROR };
        Enor(const std::string &str);

        void first() {
            next();
        }
        void next();
        Contest current() { return _current; }
        bool end() const { return _end; }
};

Enor::Enor(const std::string &str) {
    _file.open(str.c_str());
    if (_file.fail()) throw FILE_ERROR;
}

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

void Enor::next() {
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

        is >> _current.year;

        string contest;
        int position;
        while (_status == NORM) {
            is >> contest >> position;
            // valami jön ide
        }
        
        cout << _current.name << endl;
    }
}