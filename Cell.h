#pragma once
#include"ProjectString.h"
#include"Pair.hpp"

enum CellInfo{
    INT=1,
    DOUBLE,
    CHAR,
    FORMULA
};

class Cell{
private:
    String info;
    Pair<size_t,size_t> rowColumn;
    CellInfo type;
    public:
    



};