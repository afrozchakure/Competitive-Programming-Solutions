class LRUCache
{
public:
    list<pair<int, int>> l;

    // We'll use list as second element, since HashMap doesn't keep track of position
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int size;

    LRUCache(int capacity)
    {
        size = capacity;
    }

    // Retrieve the value at the key
    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;

        // Put the element in front of the list
        // list_name.splice(iterator position, list, iterator i), iterator i which need to
        // be placed at "position"
        l.splice(l.begin(), l, m[key]);
        return m[key]->second; // returning the value at the key
    }

    // put the new value in the key
    // if size of LL becomes same as hashmap, we delete the
    // last element from LL and the same element from hashmap
    void put(int key, int value)
    {

        if (m.find(key) != m.end())
        {
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            return;
        }

        // if the size of linked list becomes same as
        // hashmap, we delete the last element from linked list and hashmap
        if (l.size() == size)
        {
            // Take the last element from the list
            // pop it and erase it from the hashMap
            auto d_key = l.back().first;
            l.pop_back();
            m.erase(d_key);
        }

        // push the new key, value into the hashmap and LL
        l.push_front({key, value});
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */