//
//  map.cpp
//  homework_1
//
//  Created by Leison Gao on 1/18/24.
//

#include "map.h"

using KeyType = std::string;
using ValueType = double;
using namespace std;

Map::Map() {
    m_size = 0;
//    std::string m_entries[DEFAULT_MAX_ITEMS];
    Entry m_entries[150];
}
         
bool Map::empty() const {
    return m_size == 0;
}  // Return true if the map is empty, otherwise false.

int Map::size() const {
    return m_size;
}    // Return the number of key/value pairs in the map.
//

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
// If key is not equal to any key currently in the map and if the
// key/value pair can be added to the map, then do so and return true.
// Otherwise, make no change to the map and return false (indicating
// that either the key is already in the map, or the map has a fixed
// capacity and is full).


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
// If key is equal to a key currently in the map, then make that key no
// longer map to the value that it currently maps to, but instead map to
// the value of the second parameter; in this case, return true.
// Otherwise, make no change to the map and return false.

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
  // If key is equal to a key currently in the map, then make that key no
  // longer map to the value that it currently maps to, but instead map to
  // the value of the second parameter; in this case, return true.

  // If key is not equal to any key currently in the map, and if the
  // key/value pair can be added to the map, then do so and return true.
  // Otherwise, make no change to the map and return false (indicating
  // that the key is not already in the map and the map has a fixed
  // capacity and is full).

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
  // If key is equal to a key currently in the map, remove the key/value
  // pair with that key from the map and return true.  Otherwise, make
  // no change to the map and return false.

bool Map::contains(const KeyType& key) const {
    for (int i = 0; i < m_size; i ++) {
        if (m_entries[i].m_key == key) {
            return true;
        }
    }
    return false;
}
  // Return true if key is equal to a key currently in the map, otherwise
  // false.

bool Map::get(const KeyType& key, ValueType& value) const {
    for (int i = 0; i < m_size; i ++) {
        if (m_entries[i].m_key == key) {
            value = m_entries[i].m_value;
            return true;
        }
    }
    return false;
}
  // If key is equal to a key currently in the map, set value to the
  // value in the map which the key maps to, and return true.  Otherwise,
  // make no change to the value parameter of this function and return
  // false.

bool Map::get(int i, KeyType& key, ValueType& value) const {
    if (i >= 0 && i < m_size) {
        key = m_entries[i].m_key;
        value = m_entries[i].m_value;
        return true;
    }
    return false;
}
  // If 0 <= i < size(), copy into the key and value parameters the
  // key and value of the key/value pair in the map whose key is strictly
  // greater than exactly i keys in the map and return true.  Otherwise,
  // leave the key and value parameters unchanged and return false.

void Map::swap(Map& other) {
    Entry temp_entries[DEFAULT_MAX_ITEMS];
    copy(begin(other.m_entries), end(other.m_entries), begin(temp_entries));
    copy(begin(m_entries), end(m_entries), begin(other.m_entries));
    copy(begin(temp_entries), end(temp_entries), begin(other.m_entries));

    int temp_size = other.m_size;
    other.m_size = m_size;
    m_size = temp_size;

}

void Map::visualize() {
    for (int i = 0; i < m_size; i ++){
        cout << "element " << i << " key: " << m_entries[i].m_key << " value: " << m_entries[i].m_value << endl;
    }
}
  // Exchange the contents of this map with the other one.
