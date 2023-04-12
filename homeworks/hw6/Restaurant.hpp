#include <vector>
using std::vector;

class Restaurant {
private:
  string name;
  string area;
  int rest_id;

protected:
public:
  Restaurant();
  string getName();
  string getArea();
  string getContact();
  int getRest_id();
  void setName(string name);
  void setArea(string location);
  void setRest_id(int rest_id);
};

class Items : public Restaurant {
private:
  int item_id;
  string item_name;
  string item_description;
  float item_price;

protected:
public:
  Rest_Items();
  int getItemId();
  string getItemName();
  string getItemDescription();
  float getItemPrice();
  void setItemId(int item_id);
  void setItemName(string item_name);
  void setItemDescription(string item_description);
  void setItemPrice(float item_price);
};

class Menu : public Restaurant {
private:
  vector<Rest_Items> menu_item;

public:
  Menu();
  void addMenuItem(item : Items);
  void removeMenuItem(item : Items);
  void setMenuItem(vector<Rest_Items> menu_item);
  vector<Items> getMenuItem();
};

class Order : public Restaurant {
private:
  int order_id;
  vector<Items> order_items;
  float order_total;
  string order_date;

public:
  Order();
  int getOrderId();
  vector<Rest_Items> getOrderItems();
  float getOrderTotal();
  string getOrderDate();
  void setOrderId(int order_id);
  void setOrderItems(vector<Rest_Items> order_items);
  void setOrderTotal(float order_total);
  void setOrderDate(string order_date);
};

class Server : public Restaurant {
private:
  string server_name;
  int server_id;
  int server_phone;
  vector<Rest_Items> server_order;

public:
  Server();
  string getServerName();
  int getServerId();
  int getServerPhone();
  string getServerOrder();
  void setServerName(string delivery_name);
  void setServerId(int delivery_id);
  void setServerPhone(int delivery_phone);
  void setServerOrder(string delivery_destination);
};
