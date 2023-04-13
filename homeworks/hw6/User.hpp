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
        Billing payment_info;
    
    public:
        Customer(Order cart, string username, string password, vector<Order> order_history, vector<Products> favorites, Billing payment_info;);

        Order get_cart();
        string get_username();
        string get_password();
        vector<Order> get_history();
        vector<Products> get_favorites();
        Billing get_payment_info();

        void set_cart(Order o);
        void set_username(string username);
        void set_password(string pass);
        void set_history(vector<Order> orders);
        void set_favorites(vector<Products> favs);
        void set_payment_info(Billing payment_info);

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


class Billing {
    private:
        string card_type;
        string name_on_card;
        int card_num;
        int exp_date;
        int cvv;

    public:
        Billing(string card_type, string name_on_card, int card_num, int exp_date, int cvv);

        string get_card_type();
        string get_card_name();
        int get_card_num();
        int get_exp_date();
        int get_cvv();

        void set_card_type(string type);
        void set_card_name(string name);
        void set_card_num(int num);
        void set_exp_date(int date);
        void set_cvv(int cvv);
  
};