#include"ProjectString.h"
#include<cstring>
#include<fstream>

String::String() {
    str = nullptr;
    size = 0;
}

String::String(const String& other) {
    int len = strlen(other.str) + 1;
    str = new char[len];
    strcpy_s(str, len, other.str);
    size = other.size;
}
String::String(String&& other) {
    size=other.size;
    str = other.str;    
    other.str = nullptr;
}
String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] str;
        size = other.size;
        str = new char[size];
        strcpy_s(str, size, other.str);
    }
    return *this;
}
String& String::operator=(String&& other) {
    if (this != &other) {
        delete[] str;
        size = other.size;
        str = other.str;
        str = nullptr;
    }
    return *this;
}
String:: ~String() {
    delete[] str;
}
String::String(const char* name) {
    size = strlen(name) + 1;
    str = new char[size];
    strcpy_s(str, size, name);
}
size_t String::getSize()const {
    return this->size;
}
const char* String::getStr()const {
    return str;
}
void String::readingFromFile(const char* fileName){
    ifstream inputFile(fileName);
    delete [] str;
    char buffer[1024];
    inputFile.getline(buffer,1024,',');
    unsigned short len=strlen(buffer);
    unsigned short count=0;
    while(buffer[len-count-1]==' '){
        count++;
    }
    unsigned short len2=len-count;
    count=0;
    while(buffer[count]==' '){
        count++;
    }
    size=len2-count;
    str=new char[size+1];
    for(int i=0;i<size;++i){
        str[i]=buffer[count+i];
    }
    str[size]='\0';
    inputFile.close();
}




ostream& operator<<(ostream& os, const String& src) {
    os << src.str;
    return os;
}
bool operator==(const String& l, const String& r) {
    if(strcmp(l.getStr(), r.getStr()) == 0){
        return true;
    }
    else{
        return false;
    }
}
