#include <iostream>
#include <vector>
#include "Restaurant.hpp"
using namespace std;

class User {
    private:
        int user_id;
        string name;
        string email;

    public:
        User(int user_id, string name, string email);

        int get_user_id();
        string get_name();
        string get_email();

        void set_user_id(int id);
        void set_name(string name);
        void set_mail(string email);
};


class Customer : public User {
    private:
        Order cart;
        string username;
        string password;
        vector<Order> order_history;
        vector<Products> favorites;
    
    public:
        UserAccount();

        Order get_cart();
        string get_username();
        string get_password();
        vector<Order> get_history();
        vector<Products> get_favorites();

        void set_cart(Order o);
        void set_username(string username);
        void set_password(string pass);
        void set_history(vector<Order> orders);
        void set_favorites(vector<Products> favs);
};


class Server : public User {
    private:
        int contact;
        Order delivery;
        string mode_of_delivery;

    public:
        Server(int contact, Order delivery, string mode);

        int get_contact();
        string get_delivery();
        string get_mode();

        void set_contact(int phone);
        void set_delivery(Order deliv);
        void set_mode(string mode);
};
