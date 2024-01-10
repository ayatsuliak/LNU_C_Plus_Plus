#include "Jewelry.h"

fstream& operator>>(fstream& is, Jewelry& other)
{
    is >> other.name >> other.metal >> other.price >> other.weight;
    return is;
}

ostream& operator<<(ostream& os, const Jewelry& other)
{
    os << other.name << " " << other.metal << " " << other.price << " " << other.weight << " ";
    return os;
}

fstream& operator>>(fstream& is, Shop& other)
{
    is >> other.adress >> other.count;
    other.jewelry.resize(other.count);
    for (size_t i = 0; i < other.count; i++)
    {
        is >> other.jewelry[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const Shop& other)
{
    os << other.adress << " " << other.count << " ";
    for (size_t i = 0; i < other.count; i++)
    {
        os << other.jewelry[i] << " ";
    }
    return os;
}

string Jewelry::GetName()
{
    return name;
}

string Jewelry::GetMetal()
{
    return metal;
}

double Jewelry::GetPrice()
{
    return price;
}

size_t Shop::GetCount()
{
    return count;
}
