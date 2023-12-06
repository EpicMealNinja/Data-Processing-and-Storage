#include "database.h"

void Database::put(std::string key, int value){
    if (!inTransaction){
        // Throw an error here
        std::cout << "ERROR: No transaction in progress" << std::endl;
        return;
    }
        
    transaction_data[key] = value;
}

int Database::get(std::string key){
    return data[key];
}

void Database::begin_transaction(){
    inTransaction = true;
}

void Database::rollback(){
    if (!inTransaction){
        // Throw an error here
        std::cout << "ERROR: No transaction in progress" << std::endl;
        return;
    }

    inTransaction = false;
    transaction_data.clear();
}

void Database::commit(){
    if (!inTransaction){
        // Throw an error here
        std::cout << "ERROR: No transaction in progress" << std::endl;
        return;
    }
    inTransaction = false;
    for (auto iter = transaction_data.begin(); iter != transaction_data.end(); iter++)
        data[iter->first] = iter->second;
    transaction_data.clear();
}