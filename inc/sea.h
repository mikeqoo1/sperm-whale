#ifndef SEA_H_
#define SEA_H_

#include "animal.h"
using namespace std;

class Sea : public Animal
{
public:
    Sea();
    ~Sea();
    void SetAnimal(string 目, string 科, string feature, string treasure);
    void Set目(string 目);
    void Set科(string 科);
    void SetFeature(string feature);
    void SetTreasure(string treasure);

private:
    string 目;       //目
    string 科;       //科
    string feature;  //特性
    string treasure; //掉寶
};

#endif