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

//https://github.com/Angeld55/Object-oriented_programming_FMI/tree/master/Sem.%2010/Examples/Pair
//класът Pair е взет от горния линк