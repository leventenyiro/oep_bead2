/*#include "enor.h"

Enor::Enor(const std::string &str)
{
    _x.open(str.c_str());
    if (_x.fail()) throw FILEERROR;
}

void Enor::next()
{
    if (!(_end = (abnorm == _sx))) {
        std::string nev = _e.nev;
        _current = false;
        //for (; norm == _sx && _e.nev == nev; read());
        while (_sx == norm && _e.nev == nev) {
            _current = _current || ("MEDVE" == _e.fajta);
            read();
        }
        
    }
}

void Enor::read()
{
    _x >> _e.nev >> _e.datum >> _e.fajta >> _e.suly;
    _sx = _x.fail() ? abnorm : norm;
}
*/