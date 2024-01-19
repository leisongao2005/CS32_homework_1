//
//  GamerMap.hpp
//  homework_1
//
//  Created by Leison Gao on 1/18/24.
//

#ifndef GamerMap_hpp
#define GamerMap_hpp

#include <stdio.h>
#include <iostream>
#include "newMap.h"

using KeyType = std::string;
using ValueType = double;

class GamerMap
{
    public:
        GamerMap();
        bool addGamer(std::string name);
        double hoursSpent(std::string name) const;
        bool play(std::string name, double hours);
        int numGamers() const;
        void print() const;
    private:
        Map m_map;
};

#endif /* GamerMap_hpp */
