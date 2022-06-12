#pragma once



template <typename A,typename B>
class Pair{
private:
    A first;
    B second;
public:
    Pair(const A& a,const B& b){
        first=a;
        second=b;
    }
    const A& getFirst() const{
        return first;
    }
    const B& getSecond() const{
        return second;
    }
    void setFirst(const A& a){
        first=a;
    }
    void setSecond(const B& b){
        second=b;
    }


};





/*
template<typename A,typename B>
Pair<A,B>::Pair
template<typename A,typename B>
Pair<A,B>::Pair*/