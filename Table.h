#pragma once
#include"Cell.h"


class Table{
private:
    Cell** table;
    unsigned int numberOfCells;
    unsigned int cellCapacity;
    void copying(const Table&);
    void deleteing();
    void resize();
public:
    Table();
    Table(Cell**,unsigned int);
    Table(const Table&);
    Table& operator=(const Table&);
    ~Table();
    void readingFromFile(const char*);
    void addCell(const char*,unsigned int,unsigned int);
    void print();
};