#include <tuple>
#include "animal.h"

Animal::Animal()
{
    name = "動物"; //名稱
    area = "地球"; //分佈地區
    age = 9999999;       //年紀
    weight = 9999;
    high = 999999;
}

Animal::~Animal()
{
}

void Animal::SetAnimal(string n, string a, int age, int w, int h)
{
    name = n;
    area = a;
    this->age = age;
    weight = w;
    high = h;
}

std::tuple<string, string, int, int, int> Animal::GetAnimal()
{
    return std::tuple<string, string, int, int, int>{name, area, age, weight, high};
}