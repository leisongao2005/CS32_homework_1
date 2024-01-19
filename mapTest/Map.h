//
//  map.hpp
//  homework_1
//
//  Created by Leison Gao on 1/18/24.
//

#ifndef map_hpp
#define map_hpp

#include <stdio.h>
#include <iostream>

using KeyType = int;
using ValueType = std::string;

const int DEFAULT_MAX_ITEMS = 150;

class Map
{
    public:
        Map();
        bool empty() const;
        int size() const;
        bool insert(const KeyType& key, const ValueType& value);
        bool update(const KeyType& key, const ValueType& value);
        bool insertOrUpdate(const KeyType& key, const ValueType& value);
        bool erase(const KeyType& key);
        bool contains(const KeyType& key) const;
        bool get(const KeyType& key, ValueType& value) const;
        bool get(int i, KeyType& key, ValueType& value) const;
        void swap(Map& other);
        void dump();
    private:
        struct Entry
        {
            KeyType m_key;
            ValueType m_value;
        };
        Entry m_entries[DEFAULT_MAX_ITEMS];
        int m_size;
        
};

#endif /* map_hpp */
