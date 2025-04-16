#include "inventory.h"
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

using inventory = std::vector<Item>;

namespace {
    inventory data = {
        {1, "iPhone 16 Pro", 999.99, 15},
        {2, "AirPods Pro 3", 249.99, 30},
        {3, "MacBook Pro M4", 1599.99, 8},
        {4, "iPad Pro M4", 799.99, 12},
        {5, "Apple Watch Ultra 3", 849.99, 20},
        {6, "PlayStation 5 Pro", 699.99, 10}
    };
}
// stop words: printf scanf for while for_each
// Implement your code


void create_item(const std::string& name, double price, int qty){
    inventory& inv = data;
    inv.push_back({generate_next_id(), name, price, qty});
}

const inventory get_inventory(){
    inventory dup = data;
    std::sort(dup.begin(), dup.end(), [](const Item& a, const Item& b){
        if (a.price != b.price)
            return a.price < b.price;  // 가격 큰 순
        return a.id < b.id;            // 가격 같으면 id 오름차순
    });

    return dup;
}

bool find_item(int id, Item& found_item){
    inventory& inv = data;
    auto i = std::find_if(inv.begin(), inv.end(), [&](const Item& it){
        if (it.id == id) {
            found_item = it;
            return true;
        }
        return false;
    });
    if(i != inv.end()){
        // cout << "Found: [ID: " << found_item.id << "] " 
        // << found_item.name << " $" << found_item.price << " Qty: " 
        // << found_item.qty << endl;
        return true;

    } else {
        // cout << "Item not found with ID: "<< id << endl;
        return false;
    }
}
bool update_item(int id, double new_price, int new_qty){
    Item i1;
    inventory& inv = data;

    auto i = std::find_if(inv.begin(), inv.end(), [&](const Item& it){
        if (it.id == id) {
            i1 = it;
            return true;
        }
        return false;
    });
    if(i != inv.end()){
        i1.price = new_price;
        i1.qty= new_qty;
        inv.erase(i);
        inv.push_back(i1);
        return true;
    } else return false;
}

bool delete_item(int id){
    inventory& inv = data;
    auto i = std::remove_if(inv.begin(), inv.end(),[&](auto it){
        return (it.id == id);
    });
    if(i != inv.end()){
        inv.erase(i,inv.end());
        return true;

    } else return false;
}


int generate_next_id(){
    inventory& inv = data;
    if(!inv.size()) return 1;
    auto it = std::max_element(inv.begin(), inv.end(), [](const Item& a, const Item& b){
        return a.id < b.id;
    });
    return (it != inv.end() ? it->id + 1 : 1);
}

double calculate_total_value(){
    inventory& inv = data;
    return std::accumulate(inv.begin(), inv.end(), 0.0, [](double sum, const Item& item){
        return sum + item.price * item.qty;
    });
}
