//
// Created by Данил Подлягин on 03.10.2024.
// Modified by Tourist 04.10.24 11:11
//
#include "../header.h"

#pragma once

class Company {
public:

    Company():
        cur_balance(0), home_insurance_price(0),
        car_insurance_price(0), life_insurance_price(0),
        home_insurance_demand(0), car_insurance_demand(0),
        life_insurance_demand(0), home_insurance_compensation(0),
        car_insurance_compensation(0), life_insurance_compensation(0),
        home_insurance_period(0), car_insurance_period(0),
        life_insurance_period(0) {}


    Company(int cur_balance, int  home_insurance_price,
            int car_insurance_price, int life_insurance_price,
            int home_insurance_period, int car_insurance_period,
            int life_insurance_period, int home_insurance_compensation,
            int car_insurance_compensation, int life_insurance_compensation):
        cur_balance(cur_balance), home_insurance_price(home_insurance_price),
        car_insurance_price(car_insurance_price), life_insurance_price(life_insurance_price),
        home_insurance_demand(0), car_insurance_demand(0),
        life_insurance_demand(0), home_insurance_compensation(home_insurance_compensation),
        car_insurance_compensation(car_insurance_compensation), life_insurance_compensation(life_insurance_compensation),
        home_insurance_period(home_insurance_period), car_insurance_period(car_insurance_period),
        life_insurance_period(life_insurance_period) {
        update_demand();
    }

    void set_home_insurance_price(int price);

    void set_car_insurance_price(int price);

    void set_life_insurance_price(int price);

    void set_home_insurance_demand(int demand);

    void set_car_insurance_demand(int demand);

    void set_life_insurance_demand(int demand);

    void set_home_insurance_compensation(int compensation);

    void set_car_insurance_compensation(int compensation);

    void set_life_insurance_compensation(int compensation);

    void set_home_insurance_period(int period);

    void set_car_insurance_period(int period);

    void set_life_insurance_period(int period);

    void update_demand();

    void set_cur_balance(int balance);

    [[nodiscard]] int get_home_insurance_price() const;

    [[nodiscard]] int get_car_insurance_price() const;

    [[nodiscard]] int get_life_insurance_price() const;

    [[nodiscard]] int get_home_insurance_demand() const;

    [[nodiscard]] int get_car_insurance_demand() const;

    [[nodiscard]] int get_life_insurance_demand() const;

    [[nodiscard]] int get_home_insurance_compensation() const;

    [[nodiscard]] int get_car_insurance_compensation() const;

    [[nodiscard]] int get_life_insurance_compensation() const;

    [[nodiscard]] int get_home_insurance_period() const;

    [[nodiscard]] int get_car_insurance_period() const;

    [[nodiscard]] int get_life_insurance_period() const;

    [[nodiscard]] int get_cur_balance() const;

    int tax(int percent);

    [[nodiscard]] bool bankrupt() const;

    int buy_home_insurance();

    int buy_car_insurance();

    int buy_life_insurance();



private:
    int cur_balance, home_insurance_price, car_insurance_price, life_insurance_price;

    int home_insurance_demand, car_insurance_demand, life_insurance_demand;

    int home_insurance_compensation, car_insurance_compensation, life_insurance_compensation;

    int home_insurance_period, car_insurance_period, life_insurance_period;
};

