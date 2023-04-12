#include <iostream>
#include <vector>
using namespace std;

class User {
    private:
    int user_id;
    string user_name;
    string user_email;
    string user_address;

    protected:
    
    public:
    User();
    int getId();
    string getName();
    string setEmail();
    string getAddress();
    void setId(int user_id);
    void setName(string use_name);
    void setEmail(string user_email);
    void setAddress(string user_address);
};

class OnlineItems : public User {

    private:
    int online_item_id;
    string online_item_name;
    string online_item_description;
    float online_item_price;

    protected:

    public:
    OnlineItems();
    setOnlineItemId(int online_item_id);
    setOnlineItemName(string online_item_name);
    setOnlineItemDescription(string online_item_description);
    setOnlineItemPrice(float online_item_price);
    int getOnlineItemId();
    string getOnlineItemName();
    string getOnlineItemDescription();
    float getOnlineItemPrice();

};

class UserAccount : public User {
    private:
    vector<OnlineItems> cart;
    float cart_price;
    string username;
    string password;
    vector<OnlineItems> order_history;
    vector<OnlineItems> favorite_foods;
    
    public:
    UserAccount();
    void setCart(vector<OnlineItems> cart);
    void setCartPrice(float cart_price);
    void setUsername(string username);
    void setPassword(string password);
    void setOrderHistory(vector<OnlineItems> order_history);
    void setFavoriteFoods(vector<OnlineItems> favorite_foods);
    vector<OnlineItems> getCart();
    int getCartPrice();
    string getUsername();
    string getPassword();
    vector<OnlineItems> getOrderHistory();
    vector<OnlineItems> getFavoriteFood();

};
