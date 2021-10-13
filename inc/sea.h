#ifndef SEA_H_
#define SEA_H_

#include <sstream>
#include "animal.h"
using namespace std;

class Sea : public Animal
{
public:
    Sea();
    ~Sea();
    void SetSea(string feature, string treasure, int power);
    void SetFeature(string feature);
    void SetTreasure(string treasure);
    void SetPower(int power);
    void Print();
    //運算子多載
    Sea operator+(const Sea &s);
    bool operator>(const Sea &s);

private:
    string feature;  //特性
    string treasure; //掉寶
    int power;       //戰鬥力
};

#endif