#include <unordered_map>
#include <string>
#include <iostream>

class Database{
    std::unordered_map<std::string, int> data;
    std::unordered_map<std::string, int> transaction_data;
    bool inTransaction = false;
    public:
        void put(std::string key, int value);
        int get(std::string key);
        void begin_transaction();
        void rollback();
        void commit();
};