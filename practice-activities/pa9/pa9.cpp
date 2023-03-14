// Nadia Youssef - Practice Activity 9

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct AvgPrice {
bool operator() (const vector<double>& prices) {
    double total = 0;
    // for(int i = 0; i < prices.size(); i++) {
    //     total = total + prices[i];
    // }
    for (auto p : prices) {
        total += p;
    }
    
    return total / (prices.size());
    }
};

int main() {
    map<string, vector<double> > products;
    products["iPhone14"] = {999.99, 978.99, 1009.99, 1199.99, 899.99};
    products["iPad Pro"] = {1499.00, 1459.98, 1545.99, 1599.00, 1399.99};
    products["Noise Cancelling\nHeadphones"] = {60.99, 230.00, 99.00, 79.95, 135.99};
    products["Back Roller"] = {44.99, 79.00, 56.99, 49.99, 65.95};
    products["Bike\t"] = {254.99, 169.90, 225.00, 299.99, 120.95};

    vector<string> stores = {"eBay", "Amazon", "Staples", "Target", "Walmart"};

    cout << "Name\t\t";
    for (auto store_name: stores) {
        cout << store_name << "\t";
    }
    cout << endl;

    for (auto item: products) {
        cout << item.first;
        for (auto price : item.second) {
            cout << "\t" << price;
        }
        cout << endl;
    }

    cout << endl << endl;

    for(int i = 0; i < stores.size(); i++) {
        cout << "Store Name: " << stores[i] << endl;
        for(auto item: products) {
            cout << item.first << "\t" << item.second[i];
        cout << endl;
        }
        cout << endl;      
    }
    cout << endl << endl;

    auto avg = [](vector<double>& prices){
        double total = 0;
        for (auto p : prices) {total += p;}
        return total / (prices.size());
    };

    for (auto item: products) {
        cout << item.first << " average price: " << avg(item.second);
        cout << endl;
    }

    cout << endl << endl;

    auto greatest = [](vector<double>& prices){
        double greatest = prices[0];
        for (auto p : prices) {if(p > greatest) greatest = p;}
        return greatest;
    };

    for (auto item: products) {
        cout << item.first << "'s best price: " << greatest(item.second);
        cout << endl;
    }

}