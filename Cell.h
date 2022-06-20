#pragma once
#include"ProjectString.h"
#include"Pair.hpp"

/*enum CellInfo{
    INT=1,
    DOUBLE,
    CHAR,
    FORMULA
};*/

class Cell{
private:
    String info;
    Pair<unsigned int,unsigned int> rowColumn;
public:
    Cell()=default;
    Cell(const char*,unsigned int,unsigned int);
    Cell* clone();
    void setInfo(const char*);
    void formatInfoForOutput();
    const unsigned int getRow()const;
    const unsigned int getColumn()const;


};