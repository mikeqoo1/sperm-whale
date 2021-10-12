#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <tuple>
#include <string>
#include <map>
using namespace std;

class Animal
{
public:
    Animal();
    ~Animal();
    std::tuple<string, string, int, int, int> GetAnimal();
    void SetAnimal(string name, string area, int age, int weight, int high);
    void Print();
    void InsertMap(string key, Animal value);
    void FindMap(string key);
    void PrintMap();

private:
    string name; //名稱
    string area; //分佈地區
    int age;     //年紀
    int weight;
    int high;

    map<std::string, Animal> noahs_ark;
};

#endif