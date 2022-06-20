#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class String {
protected:
    char* str;
    unsigned int size;
public:
    String();
    String(const String&);
    String(String&&);
    String& operator=(const String&);
    String& operator=(String&&);
    ~String();
    String(const char*);
    size_t getSize()const;
    const char* getStr()const;
    void readingFromFile(const char*);
    void setStr(const char*);
    void deleteingWhitespaces();
    bool containingSymbolOnce(char);
    void setSize(unsigned int);
    void formattingString();
    

    friend ostream& operator<<(ostream&, const String&);
    
};

bool operator==(const String&, const String&);