#ifndef SEA_H_
#define SEA_H_

#include "animal.h"
using namespace std;

class Sea : public Animal
{
public:
    Sea();
    ~Sea();
    void SetSea(string feature, string treasure);
    void SetFeature(string feature);
    void SetTreasure(string treasure);
    void Print();

private:
    string feature;  //特性
    string treasure; //掉寶
};

#endif