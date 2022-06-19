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
    size = strlen(name);
    str = new char[size+1];
    strcpy_s(str, size+1, name);
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
    size=strlen(buffer);
    unsigned int i=0;
    while(buffer[i]!='\n' && i<size){
        i++;
    }
    cout<<"i:"<<i<<endl;
    if(i!=size){
        size=i;
        str=new char[size+1];
        for(int i=0;i<size;++i){
            str[i]=buffer[i];
        }
        str[size]='\0';
    }
    else{    
        str=new char[size+1];
        strcpy_s(str,size+1,buffer);
    }
    
    /*unsigned short len=strlen(buffer);
    unsigned short count=0;
    while(buffer[len-count-1]==' '){
        count++;
    }
    unsigned short len2=len-count;
    count=0;
    while(buffer[count]==' '){
        count++;
    }
    if(buffer[count]=='+'){
        size=len2-count-1;
        str=new char[size];
        for(int i=0;i<size;++i){
        str[i]=buffer[count+i+1];
        }
    }
    else{
        size=len2-count;
        str=new char[size+1];
        for(int i=0;i<size;++i){
            str[i]=buffer[count+i];
        }
    }
    str[size]='\0';*/
    inputFile.close();
}

void String::setStr(const char* name){
    size=strlen(name);
    delete[] str;
    str=new char[size+1];
    strcpy_s(str,size+1,name);
}
void String::deleteingWhitespaces(){
    unsigned int count=0;
    while(str[size-count-1]==' '){
        count++;
    }
    unsigned int len2=size-count;
    count=0;
    while(str[count]==' '){
        count++;
    }
    if(str[count]=='+'){
        size=len2-count-1;
        char* abv=new char[size+1];
        for(int i=0;i<size;++i){
        abv[i]=str[count+i+1];
        }
        abv[size]='\0';
        delete[] str;
        str=new char[size];
        strcpy_s(str,size+1,abv);
    }
    else{
        size=len2-count;
        char* abc=new char[size+1];        
        for(int i=0;i<size;++i){
            abc[i]=str[count+i];
        }
        abc[size]='\0';
        delete[] str;
        str=new char[size+1];
        strcpy_s(str,size+1,abc);
    }
}
bool String::containingSymbolOnce(char symbol){
    bool a=0;
    int i=0;
    while(str[i]!=symbol && i<size){
        i++;
    }
    if(i==size){
        return a;
    }
    else{
        return a=1;
    }
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
