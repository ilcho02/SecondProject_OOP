#pragma once
#include<iostream>
using namespace std;
class String {
private:
    char* str;
    size_t size;
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
    

    friend ostream& operator<<(ostream&, const String&);
    
};

bool operator==(const String&, const String&);