//
//  map.cpp
//  homework_1
//
//  Created by Leison Gao on 1/18/24.
//

#include "Map.h"
#include <iostream>

using KeyType = int;
using ValueType = std::string;

using namespace std;

Map::Map() {
    m_size = 0;
    Entry m_entries[150];
}
         
bool Map::empty() const {
    return m_size == 0;
}

int Map::size() const {
    return m_size;
}

bool Map::insert(const KeyType& key, const ValueType& value) {
    if (m_size >= DEFAULT_MAX_ITEMS)
        return false;
    int pos = 0;
    for (int i = 0; i < m_size; i ++) {
        if (m_entries[i].m_key == key) {
            return false;
        }
        if (key > m_entries[i].m_key) {
            pos ++;
        }
    }
    m_size ++;
    for (int i = m_size; i > pos; i --) {
        m_entries[i].m_key = m_entries[i - 1].m_key;
        m_entries[i].m_value = m_entries[i - 1].m_value;
    }
    m_entries[pos].m_key = key;
    m_entries[pos].m_value = value;
    return true;
}

bool Map::update(const KeyType& key, const ValueType& value) {
    for (int i = 0; i < m_size; i ++) {
        if (m_entries[i].m_key == key) {
            m_entries[i].m_key = key;
            m_entries[i].m_value = value;
            return true;
        }
    }
    return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
    int pos = 0;
    for (int i = 0; i < m_size; i ++) {
        if (m_entries[i].m_key == key) {
            m_entries[i].m_key = key;
            m_entries[i].m_value = value;
            return true;
        }
        if (key > m_entries[i].m_key) {
            pos ++;
        }
    }

    if (m_size < DEFAULT_MAX_ITEMS) {
        m_size ++;
        for (int i = m_size; i > pos; i --) {
            m_entries[i].m_key = m_entries[i - 1].m_key;
            m_entries[i].m_value = m_entries[i - 1].m_value;
        }
        m_entries[pos].m_key = key;
        m_entries[pos].m_value = value;
        return true;
    }
    return false;
}

bool Map::erase(const KeyType& key) {
    for (int i = 0; i < m_size; i ++) {
        if (m_entries[i].m_key == key) {
            m_size --;
            for (int j = i; j < m_size; j ++) {
                m_entries[j].m_key = m_entries[j + 1].m_key;
                m_entries[j].m_value = m_entries[j+ 1].m_value;
            }
            return true;
        }
    }
    return false;
}

bool Map::contains(const KeyType& key) const {
    for (int i = 0; i < m_size; i ++) {
        if (m_entries[i].m_key == key) {
            return true;
        }
    }
    return false;
}

bool Map::get(const KeyType& key, ValueType& value) const {
    for (int i = 0; i < m_size; i ++) {
        if (m_entries[i].m_key == key) {
            value = m_entries[i].m_value;
            return true;
        }
    }
    return false;
}

bool Map::get(int i, KeyType& key, ValueType& value) const {
    if (i >= 0 && i < m_size) {
        key = m_entries[i].m_key;
        value = m_entries[i].m_value;
        return true;
    }
    return false;
}

void Map::swap(Map& other) {
    std::swap(m_entries, other.m_entries);
    std::swap(m_size, other.m_size);
}

void Map::dump() {
    for (int i = 0; i < m_size; i ++){
        cerr << "element " << i << " key: " << m_entries[i].m_key << " value: " << m_entries[i].m_value << endl;
    }
}
