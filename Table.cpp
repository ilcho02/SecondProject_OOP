#include"Table.h"


void Table::copying(const Table& other){
    cellCapacity=other.cellCapacity;
    numberOfCells=other.numberOfCells;
    table=new Cell*[cellCapacity];
    for(int i=0;i<cellCapacity;++i){
        table[i]=other.table[i]->clone();
    }
}
void Table::deleteing(){
    for(int i=0;i<numberOfCells;++i){
        delete table[i];
    }
    delete[] table;
}
void Table::resize(){
    cellCapacity*=2;
    Cell** temp=new Cell*[cellCapacity];
    for(int i=0;i<cellCapacity;++i){
        temp[i]=table[i];
    }
    delete[] table;
    table=temp;
}
Table::Table(){
    cellCapacity=8;
    numberOfCells=0;
    table=new Cell*[cellCapacity];
}
Table::Table(const Table& other){
    copying(other);
}
Table& Table::operator=(const Table& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}
Table::~Table(){
    deleteing();
}
void Table::readingFromFile(const char* fileName){
    deleteing();
    cellCapacity=8;
    numberOfCells=0;
    table=new Cell*[cellCapacity];
    ifstream inputFile(fileName);
    inputFile.seekg(0,ios::end);
    long fileLength=inputFile.tellg();
    inputFile.seekg(0,ios::beg);
    bool a=1;
    bool b=1;
    char* other;
    unsigned int Row=1;
    unsigned int col=1;
    while(a){
        if(!b){
            Row++;
            col=1;
            if(cellCapacity==numberOfCells){
                resize();
            }
            addCell(other,Row,col);
            b=1;
        }
       else{
       char buffer[1024];
       inputFile.getline(buffer,1024,',');
       unsigned int size=strlen(buffer);
       unsigned int i=0;
       while(buffer[i]!='\n' && i<size){
           i++;
       }
       if(i!=size){
        char* str=new char[i+1];
        for(int a=0;a<i;++a){
         str[a]=buffer[a];
        }
        str[i]='\0';
        delete[] other;
        other=new char[size-i+2];
        for(int a=0;a<size-i+1;++a){
         other[a]=buffer[i+1+a];
        }
        other[size-i+1]='\0';
        col++;
        if(cellCapacity==numberOfCells){
            resize();
        }
        addCell(str,Row,col);
        b=0;     
       }
       else{
        char* str=new char[size+1];
        strcpy_s(str,size,buffer);
        if(cellCapacity==numberOfCells){
            resize();
        }
        col++;
        addCell(str,Row,col);
       }
      }
      if(fileLength==inputFile.tellg()){
        a=0;
      }
    }
    inputFile.close();
}
void Table::addCell(const char* name,unsigned int Row,unsigned int col){
    if(cellCapacity=numberOfCells){
        resize();
    }
    Cell* abv=new Cell(name,Row,col);
    table[numberOfCells]=abv->clone();
    numberOfCells++;
}
void Table::print(){}