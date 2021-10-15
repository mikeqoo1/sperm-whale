#include <iostream>
#include <map>

#include "animal.h"
#include "sea.h"

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
    a.Print();

    a.SetAnimal("大白鯊", "大海", 10, 2000, 5);
    name = std::get<0>(a.GetAnimal());
    area = std::get<1>(a.GetAnimal());
    age = std::get<2>(a.GetAnimal());
    weight = std::get<3>(a.GetAnimal());
    high = std::get<4>(a.GetAnimal());
    a.Print();

    Setting(&a);
    std::tie(name, area, age, weight, high) = a.GetAnimal();
    a.Print();

    //std::map範例
    //新增用insert指令
    a.InsertMap(name, a);

    //新增用array的方式
    //noahs_ark["虎鯨"] = b;
    a.SetAnimal("虎鯨", "大海", 10, 6000, 8);
    a.InsertMap("虎鯨", a);
    a.SetAnimal("大白鯊", "大海", 10, 2000, 5);
    a.InsertMap("大白鯊", a);

    //map的遍尋和搜尋
    a.PrintMap();
    a.FindMap("海豚");

    //子類別的範例
    Sea godzilla;
    godzilla.SetAnimal("哥吉拉", "地心", 0, 96340, 119.8);
    godzilla.SetSea("怪獸之王", "核能背鰭", 99999);
    godzilla.Print(); //多載

    Sea kong;
    kong.SetAnimal("金剛", "骷髏島", 0, 0, 102);
    kong.SetSea("巨獸種族", "無", 88888);
    kong.Print(); //多載

    //運算子多載
    Sea tempaaa;
    string godzilla_name, kong_name;
    godzilla_name = std::get<0>(godzilla.GetAnimal());
    kong_name = std::get<0>(kong.GetAnimal());
    godzilla.GetAnimal();
    tempaaa = godzilla + kong;
    std::cout << "Power合併=" << tempaaa.GetPower() << std::endl;
    std::cout << "Name=" << godzilla_name << std::endl;
    std::cout << "Name=" << kong_name << std::endl;

    if (godzilla > kong)
    {
        cout << "哥吉拉比金剛厲害" << endl;
    }
}