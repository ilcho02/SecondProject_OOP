#include"ProjectString.h"


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
    if(i!=size){
        str=new char[i+1];
        for(int a=0;a<i;++a){
            str[a]=buffer[a];
        }
        str[i]='\0';
        delete[] str;
        str=new char[size-i+2];
        for(int a=0;a<size-i+1;++a){
            str[a]=buffer[i+1+a];
        }
        str[size-i+1]='\0';
    }
    else{    
        str=new char[size+1];
        strcpy_s(str,size+1,buffer);
    }
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

void String::setSize(unsigned int size)
{
    this->size=size;
}

void String::formattingString(){
    unsigned int count=0;
    while(str[size-count-1]==' '){
        count++;
    }
    unsigned int len2=size-count;
    count=0;
    while(str[count]==' '){
        count++;
    }
    size=len2-count;
    char* abc=new char[size+1];        
    for(int i=0;i<size;++i){
       abc[i]=str[count+i];
    }
    abc[size]='\0';
    delete[] str;
    str=new char[size+1];
    strcpy_s(str,size+1,abc);
    if(str[0]=='\"' && str[size-1]=='\"'){
        unsigned short count=0;
        for(int i=1;i<size;++i){
            if((str[i]=='\"' && str[i-1]=='\\') || (str[i]=='\\' && str[i-1]=='\\')){
                count++;
            }
        }
        char* temp=new char[size-1-count];
        int j=1;
        for(int i=0;i<size-2-count;++i){
            if((str[i+j+2]=='\"' && str[i+j+1]=='\\') || (str[i+j+2]=='\\' && str[i+j+1]=='\\')){
                temp[i]=str[i+j+1];
                j++;
            }
            else{
                temp[i]=str[i+j];
            }
        }
        temp[size-2-count]='\0';
        delete[] str;
        size=strlen(temp);
        str=new char[size+1];
        strcpy_s(str,size,temp);
    }
    else if(str[0]='+'){
        char* temp=new char[size];
        for(int i=0;i<size-1;++i){
            temp[i]=str[i+1];
        }
        temp[size-1]='\0';
        delete[] str;
        size=strlen(temp);
        str=new char[size+1];
        strcpy_s(str,size,temp);
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
