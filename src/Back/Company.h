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

std::mt19937 rnd(time(nullptr));

void peoples_update(std::vector<std::vector<std::pair<int, int>>>& peoples_insurances, Company& co, int cur_month) {
    for (int i = 0; i < 100; ++i) {
        int determinant = (int)rnd() % 100;
        if (peoples_insurances[i][0] == std::make_pair(0, 0) &&
            determinant <= co.get_home_insurance_demand()) {
            peoples_insurances[i][0] = std::make_pair(cur_month, co.get_home_insurance_period() + cur_month);
        }
        determinant = (int)rnd() % 100;
        if (peoples_insurances[i][1] == std::make_pair(0, 0) &&
            determinant <= co.get_car_insurance_demand()) {
            peoples_insurances[i][1] = std::make_pair(cur_month, co.get_car_insurance_period() + cur_month);
        }
        determinant = (int)rnd() % 100;
        if (peoples_insurances[i][2] == std::make_pair(0, 0) &&
            determinant <= co.get_life_insurance_demand()) {
            peoples_insurances[i][2] = std::make_pair(cur_month, co.get_life_insurance_period() + cur_month);
        }
    }
}

std::vector<std::vector<std::pair<int, int>>> peoples_insurances(Company& co, int cur_month) {
//   peoples_insurances[i] = vector({l, r}, {l, r}, {l, r}) where home, car, life
    std::vector<std::vector<std::pair<int, int>>> res(100);
    for (int i = 0; i < 100; ++i) {
        int determinant = (int)rnd() % 100;
        if (determinant <= co.get_home_insurance_demand()) {
            res[i][0] = std::make_pair(cur_month, co.get_home_insurance_period() + cur_month);
        } else {
            res[i][0] = std::make_pair(0, 0);
        }
        determinant = (int)rnd() % 100;
        if (determinant <= co.get_car_insurance_demand()) {
            res[i][1] = std::make_pair(cur_month, co.get_car_insurance_period() + cur_month);
        } else {
            res[i][1] = std::make_pair(0, 0);
        }
        determinant = (int)rnd() % 100;
        if (determinant <= co.get_life_insurance_demand()) {
            res[i][2] = std::make_pair(cur_month, co.get_life_insurance_period() + cur_month);
        } else {
            res[i][2] = std::make_pair(0, 0);
        }
    }
    return res;
}

std::vector<std::vector<std::pair<int, double>>> insurance_cases(std::vector<std::vector<std::pair<int, int>>>& peoples_insurances,
                                                                 Company& co) {
//in res[i] vector{month of union, coefficient of union}

    std::vector<std::vector<std::pair<int, double>>> res(100);
    int cases_home = (int)rnd() % 25;
    int cases_car = (int)rnd() % 35;
    int cases_life = (int)rnd() % 30;
    for(int i = 0; i < 100; ++i) {
        if (peoples_insurances[i][0] != std::make_pair(0, 0) && i < cases_home) {
            res[i][0].first = (int)rnd() % co.get_home_insurance_period() + peoples_insurances[i][0].first;
            auto coefficient = (double)rnd();
            coefficient -= (int)coefficient;
            res[i][0].second = coefficient + 0.01;
        }
        if (peoples_insurances[i][1] != std::make_pair(0, 0) && i < cases_car) {
            res[i][1].first = true;
            auto coefficient = (double)rnd();
            coefficient -= (int)coefficient;
            res[i][1].second = coefficient + 0.01;
        }
        if (peoples_insurances[i][2] != std::make_pair(0, 0) && i < cases_life) {
            res[i][2].first = true;
            auto coefficient = (double)rnd();
            coefficient -= (int)coefficient;
            res[i][2].second = coefficient + 0.01;
        }
    }
    return res;
}

std::vector<std::pair<int, int>> month_result(std::vector<std::vector<std::pair<int, int>>>& peoples_insurances,
                                              std::vector<std::vector<std::pair<int, double>>>& insurance_cases,
                                              Company& co, int month) {
// home, car, life
    std::vector<std::pair<int, int>> res(3);
    for (int i = 0; i < 100; ++i) {
        bool home = peoples_insurances[i][0] != std::make_pair(0, 0) && month <= peoples_insurances[i][0].second;
        bool car = peoples_insurances[i][1] != std::make_pair(0, 0) && month <= peoples_insurances[i][1].second;
        bool life = peoples_insurances[i][2] != std::make_pair(0, 0) && month <= peoples_insurances[i][2].second;

        res[0].first += home * co.get_home_insurance_price();
        if (insurance_cases[i][0].first == month) {
            res[0].second += co.get_home_insurance_compensation() * insurance_cases[i][0].second;
        }

        res[1].first += car * co.get_car_insurance_price();
        if (insurance_cases[i][1].first == month) {
            res[1].second += co.get_home_insurance_compensation() * insurance_cases[i][1].second;
        }

        res[2].first += life * co.get_life_insurance_price();
        if (insurance_cases[i][2].first == month) {
            res[2].second += co.get_home_insurance_compensation() * insurance_cases[i][2].second;
        }
    }
    return res;
}

