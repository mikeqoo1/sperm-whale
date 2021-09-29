#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <tuple>
#include <string>
using namespace std;

class Animal
{
public:
    Animal();
    ~Animal();
    std::tuple<string, string, int, int, int> GetAnimal();
    void SetAnimal(string name, string area, int age, int weight, int high);

private:
    string name; //名稱
    string area; //分佈地區
    int age;     //年紀
    int weight;
    int high;
};

#endif