#include "sea.h"

Sea::Sea()
{
    feature = "特性";
    treasure = "掉落寶物";
    power = 0;
}

Sea::~Sea()
{
}

void Sea::SetSea(string feature, string treasure, int power)
{
    this->feature = feature;
    this->treasure = treasure;
    this->power = power;
}

void Sea::SetFeature(string feature)
{
    this->feature = feature;
}

void Sea::SetTreasure(string treasure)
{
    this->treasure = treasure;
}

void Sea::SetPower(int power)
{
    this->power = power;
}

void Sea::Print()
{
    string name, area;
    int age, weight, high;
    std::tie(name, area, age, weight, high) = GetAnimal(); //取得父類別

    //基本的初始化stringstream
    stringstream ss;
    ss.str("");
    ss.clear();
    ss << "名稱:" << name << "|地區:" << area << "|年齡:" << age << "|重量(kg):" << weight << "|長度(m):" << high
       << "|特性:" << feature << "|掉落寶物:" << treasure << "|戰鬥力:" << power;

    //輸出
    cout << ss.str() << endl;
}

Sea Sea::operator+(const Sea &s)
{
    Sea temp;
    temp.power = this->power + s.power;
    // cout << "this->power" << this->power << endl;
    // cout << "s.power" << s.power << endl;
    return temp;
}

bool Sea::operator>(const Sea &s)
{
    Sea temp;
    temp.power = this->power + s.power;
    // cout << "this->power" << this->power << endl;
    // cout << "s.power" << s.power << endl;
    if (temp.power > s.power)
        return true;
    return false;
}