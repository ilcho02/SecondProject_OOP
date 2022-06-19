#include"Cell.h"


Cell::Cell(const char* name,size_t Row,size_t col,unsigned int Type):
info(name),rowColumn(Row,col),type(Type)
{}
