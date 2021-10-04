class OrderedStream
{
public:
    unordered_map<int, string> records;
    int counter = 1;
    OrderedStream(int n)
    {
    }

    vector<string> insert(int id, string value)
    {
        records[id] = value;
        vector<string> result;

        while (records.count(counter))
        {
            result.push_back(records[ptr]);
            counter++;
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */