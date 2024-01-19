//
//  map.hpp
//  homework_1
//
//  Created by Leison Gao on 1/18/24.
//

#ifndef newMap_hpp
#define newMap_hpp

#include <stdio.h>
#include <iostream>

using KeyType = std::string;
using ValueType = double;

const int DEFAULT_MAX_ITEMS = 150;

class Map
{
    public:
        Map(int size = DEFAULT_MAX_ITEMS);
        ~Map();
        Map& operator=(const Map& rhs);
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
        Entry *m_entries;
        int m_size;
        int m_max_size;
        
};

#endif /* map_hpp */
