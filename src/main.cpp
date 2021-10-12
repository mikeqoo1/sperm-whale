#include <iostream>
#include <map>

#include "animal.h"
#include "sea.h"

std::map<std::string, Animal> noahs_ark;

void Setting(Animal *a)
{
    string name = "抹香鯨";
    string area = "大海";
    int age = 100;
    int weight = 50000;
    int high = 20;
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

    a.SetAnimal("大白鯊", "大海", 10, 2000, 5);
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
    //新增用insert指令
    noahs_ark.insert(pair<string, Animal>(name, a));

    //新增用array的方式
    Animal b;
    b.SetAnimal("虎鯨", "大海", 10, 6000, 8);
    noahs_ark["虎鯨"] = b;
    b.SetAnimal("大白鯊", "大海", 10, 2000, 5);
    noahs_ark["大白鯊"] = b;

    //map的遍尋和搜尋
    cout << "正向輸出" << endl;
    map<string, Animal>::iterator iter;
    for (iter = noahs_ark.begin(); iter != noahs_ark.end(); iter++)
    {
        std::tie(name, area, age, weight, high) = iter->second.GetAnimal();
        cout << "名稱(key)是" << iter->first << ",住" << area << ",年紀是" << age << "歲"
             << ",體重是" << weight << "公斤"
             << ",長度是" << high << "公尺" << endl;
    }

    cout << "反向輸出" << endl;
    map<string, Animal>::reverse_iterator iter_r;
    for (iter_r = noahs_ark.rbegin(); iter_r != noahs_ark.rend(); iter_r++)
    {
        std::tie(name, area, age, weight, high) = iter_r->second.GetAnimal();
        cout << "名稱(key)是" << iter_r->first << ",住" << area << ",年紀是" << age << "歲"
             << ",體重是" << weight << "公斤"
             << ",長度是" << high << "公尺" << endl;
    }

    iter = noahs_ark.find("海豚");
    if (iter != noahs_ark.end())
    {
        cout << "方舟動物找到, 該動物是" << iter->first << endl;
    }
    else
    {
        cout << "方舟內沒有找到該動物" << endl;
    }

    // WIP: 實做整合2個Class
    Sea aa;
    aa.SetAnimal("遠古巨獸", "目", "怪獸之", "背鰭");
}