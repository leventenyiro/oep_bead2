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
        Contest _element;
        Status _status;
        bool _end;

    public:
        enum Errors{ FILE_ERROR };
        Enor(const std::string &str);

        void first() {
            next();
        }
        void next();
        bool end() const { return _end; }


};

Enor::Enor(const std::string &str) {
    _file.open(str.c_str());
    if (_file.fail()) throw FILE_ERROR;
}

/*void Enor::next() {
    if (!(_end = (ABNORM == _status))) {
        std::string nev = _element.name;
        _current = false;
        //for (; NORM == _sx && _e.nev == nev; read());
        while (_status == NORM && _element.name == nev) {
            //_current = _current || ("MEDVE" == _element.fajta);
            read();
        }
        
    }
}*/

/*void Enor::read() {
    //_file >> _element.name >> _element.year >> _element.contest >> _element.position;
    //_file >> _element.name >> _element.year;
    _status = _file.fail() ? ABNORM : NORM;
}*/

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void Enor::next() {
    string line;
    getline(_file, line);
    _element.name = "";
    if ( !(_end = _file.fail()) ) {
        istringstream is(line);

        string element = "";

        bool isStringNumber = false;
        while (!isStringNumber) {
            is >> element;
            if (isNumber(element)) {
                isStringNumber = true;
            } else {
                _element.name += element + " ";
            }
        }

        is >> _element.year;

        string contest;
        int position;
        while (_status == NORM) {
            is >> contest >> position;
            // valami jön ide
        }
        
        cout << _element.name << endl;
        
        //string name = line.substr(0, line.find('\t'))
        //cout << line.substr(0, line.find('\r')) << endl;
        //cout << _element.name << " " << _element.year << endl;
    }
}