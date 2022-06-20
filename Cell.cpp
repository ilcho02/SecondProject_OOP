#include"Cell.h"


Cell::Cell(const char* name,unsigned int Row,unsigned int col):
info(name),rowColumn(Row,col)
{}
Cell* Cell::clone(){
    return new Cell(*this);
}
void Cell::setInfo(const char* name){
    info.setStr(name);
}
void Cell::formatInfoForOutput(){
    info.formattingString();
}
const unsigned int Cell::getRow()const{
    return rowColumn.getFirst();
}
const unsigned int Cell::getColumn()const{
    return rowColumn.getSecond();
}