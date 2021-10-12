#include <tuple>
#include "sea.h"

Sea::Sea()
{
    科 = "動物";
    目 = "地球";
    feature = "特性";
    treasure = "掉落寶物";
}

Sea::~Sea()
{
}

void Sea::SetAnimal(string 目, string 科, string feature, string treasure)
{
    this->目 = 目;
    this->科 = 科;
    this->feature = feature;
    this->treasure = treasure;
}

void Sea::Set目(string 目)
{
    this->目 = 目;
}

void Sea::Set科(string 科)
{
    this->科 = 科;
}

void Sea::SetFeature(string feature)
{
    this->feature = feature;
}

void Sea::SetTreasure(string treasure)
{
    this->treasure = treasure;
}