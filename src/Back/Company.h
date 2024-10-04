//
// Created by Данил Подлягин on 03.10.2024.
// Modified by Tourist 04.10.24 11:11
//

#pragma once

class Company {
public:

    Company():
        cur_balance(0), home_insurance_price(0),
        car_insurance_price(0), life_insurance_price(0) {}

    void set_home_insurance_price(int price);

    void set_car_insurance_price(int price);

    void set_life_insurance_price(int price);

    void set_home_insurance_demand(int demand);

    void set_car_insurance_demand(int demand);

    void set_life_insurance_demand(int demand);

    void set_cur_balance(int balance);

    int get_home_insurance_price();

    int get_car_insurance_price();

    int get_life_insurance_price();

    int get_home_insurance_demand();

    int get_car_insurance_demand();

    int get_life_insurance_demand();

    int get_cur_balance();

    int tax(int percent);

    bool bankrupt();





private:
    int cur_balance, home_insurance_price, car_insurance_price, life_insurance_price;

    int home_insurance_demand, car_insurance_demand, life_insurance_demand;




};

