//
//  GamerMap.cpp
//  homework_1
//
//  Created by Leison Gao on 1/18/24.
//

#include "GamerMap.h"
#include <iostream>
using namespace std;

GamerMap::GamerMap() {
    Map m_map;
}
bool GamerMap::addGamer(KeyType name)
{
    return m_map.insert(name, 0.0);
}

double GamerMap::hoursSpent(KeyType name) const
{
    double hours = 0;
    if (m_map.get(name, hours))
        return hours;
    else
        return -1;
}

bool GamerMap::play(KeyType name, ValueType hours)
{
    double time;
    if (m_map.get(name, time))
        return m_map.update(name, hours + time);
    return false;
}

int GamerMap::numGamers() const
{
    return m_map.size();
}

void GamerMap::print() const
{
    for (int i = 0; i < m_map.size(); i ++) {
        KeyType name;
        ValueType time;
        m_map.get(i, name, time);
        cout << name << " " << time << endl;
    }
}
