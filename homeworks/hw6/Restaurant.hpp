#include <iostream>
#include <vector>
using namespace std;

class Restaurant {
private:
  string name;
  string address;
  int contact;
  Menu menu;

protected:
public:
  Restaurant(string name, string address, int contact, Menu menu);

  string get_res_name();
  string get_res_address();
  string get_res_contact();
  Menu get_menu();


  void set_res_name(string name);
  void set_res_address(string address);
  void set_res_contact(int contact);
  void set_menu(Menu menu);

};

class Product {
private:
  int product_id;
  string name;
  string description;
  double price;

public:
  Product(int product_id, string name, string description, double price);

  int get_prod_id();
  string get_prod_name();
  string get_prod_desc();
  double get_prod_price();

  void set_prod_id(int id);
  void set_prod_name(string name);
  void set_prod_desc(string desc);
  void set_prod_price(double price);
};

class Menu {
private:
  vector<Product> menu_options;

public:
  Menu(vector<Product> menu_options);
  
  vector<Product> get_menu();
  void set_menu(vector<Product> products);

  void add_product(Product p);
  void remove_product(Product p);
};

class Order {
private:
  int order_id;
  vector<Product> order_products;
  double total_price;
  string order_date;

public:
  Order(int order_id, vector<Product> order_products, double total_price, string order_date);

  int get_order_id();
  vector<Product> get_order();
  double get_order_total();
  string get_order_date();

  void set_order_id(int id);
  void set_order_products(vector<Product> prods);
  void set_order_total(double toal);
  void set_order_date(string date);
};