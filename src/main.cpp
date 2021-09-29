#include <iostream>
#include "animal.h"

void Setting(Animal *a)
{
    string name = "抹香鯨";
    string area = "大海";
    int age = 100;
    int weight = 1000;
    int high = 30;
    a->SetAnimal(name, area, age, weight, high);
}

int main()
{
    //std::tuple範例
    string name, area;
    int age, weight, high;
    Animal a;
    std::tie(std::ignore, std::ignore, std::ignore, std::ignore, std::ignore) = a.GetAnimal();
    cout << "名稱:" << name << "|地區:" << area << "|年齡:" << age << "|重量(kg):" << weight << "|長度(m):" << high << endl;

    a.SetAnimal("鯊魚", "大海", 10, 200, 5);
    name = std::get<0>(a.GetAnimal());
    area = std::get<1>(a.GetAnimal());
    age = std::get<2>(a.GetAnimal());
    weight = std::get<3>(a.GetAnimal());
    high = std::get<4>(a.GetAnimal());
    cout << "名稱:" << name << "|地區:" << area << "|年齡:" << age << "|重量(kg):" << weight << "|長度(m):" << high << endl;

    Setting(&a);
    std::tie(name, area, age, weight, high) = a.GetAnimal();
    cout << "名稱:" << name << "|地區:" << area << "|年齡:" << age << "|重量(kg):" << weight << "|長度(m):" << high << endl;

    //std::map範例
}