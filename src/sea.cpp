#include "sea.h"

Sea::Sea()
{
    feature = "特性";
    treasure = "掉落寶物";
}

Sea::~Sea()
{
}

void Sea::SetSea(string feature, string treasure)
{
    this->feature = feature;
    this->treasure = treasure;
}

void Sea::SetFeature(string feature)
{
    this->feature = feature;
}

void Sea::SetTreasure(string treasure)
{
    this->treasure = treasure;
}

void Sea::Print()
{
    string name, area;
    int age, weight, high;
    std::tie(name, area, age, weight, high) = GetAnimal();
    cout << "名稱:" << name << "|地區:" << area << "|年齡:" << age << "|重量(kg):" << weight << "|長度(m):" << high << "|特性:" << feature << "|掉落寶物:" << treasure << endl;
}