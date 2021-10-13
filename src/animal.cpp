#include <tuple>
#include "animal.h"

Animal::Animal()
{
    name = "動物"; //名稱
    area = "地球"; //分佈地區
    age = 9999999; //年紀
    weight = 9999;
    high = 999999;
}

Animal::~Animal()
{
}

std::tuple<string, string, int, int, int> Animal::GetAnimal()
{
    return std::tuple<string, string, int, int, int>{name, area, age, weight, high};
}

void Animal::SetAnimal(string n, string a, int age, int w, int h)
{
    name = n;
    area = a;
    this->age = age;
    weight = w;
    high = h;
}

void Animal::Print()
{
    cout << "名稱:" << name << "|地區:" << area << "|年齡:" << age << "|重量(kg):" << weight << "|長度(m):" << high << endl;
}

void Animal::InsertMap(string key, Animal value)
{
    noahs_ark.insert(pair<string, Animal>(key, value));
}

void Animal::FindMap(string key)
{
    map<string, Animal>::iterator iter;
    iter = noahs_ark.find(key);
    if (iter != noahs_ark.end())
    {
        cout << "方舟動物找到, 該動物是" << iter->first << endl;
    }
    else
    {
        cout << "方舟內沒有找到該動物" << endl;
    }
}

void Animal::PrintMap()
{
    cout << "Map正向輸出" << endl;
    map<string, Animal>::iterator iter;
    for (iter = noahs_ark.begin(); iter != noahs_ark.end(); iter++)
    {
        std::tie(name, area, age, weight, high) = iter->second.GetAnimal();
        cout << "名稱(key)是" << iter->first << ",住" << area << ",年紀是" << age << "歲"
             << ",體重是" << weight << "公斤"
             << ",長度是" << high << "公尺" << endl;
    }

    cout << "Map反向輸出" << endl;
    map<string, Animal>::reverse_iterator iter_r;
    for (iter_r = noahs_ark.rbegin(); iter_r != noahs_ark.rend(); iter_r++)
    {
        std::tie(name, area, age, weight, high) = iter_r->second.GetAnimal();
        cout << "名稱(key)是" << iter_r->first << ",住" << area << ",年紀是" << age << "歲"
             << ",體重是" << weight << "公斤"
             << ",長度是" << high << "公尺" << endl;
    }
}