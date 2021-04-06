#pragma once

#include <fstream>

class Enor
{
public:
    enum Errors{ FILEERROR };
    Enor(const std::string &str);

    void first() {
        read();
        next();
    }
    void next();
    bool current() const { return _current; }
    bool end() const { return _end; }

private:
    enum Status {
        abnorm,
        norm
    };

    struct Trofea {
        std::string nev;
        std::string datum;
        std::string fajta;
        int suly;
    };

    std::ifstream _x;
    Trofea _e;
    Status _sx;
    bool _current;
    bool _end;

    void read();
};
