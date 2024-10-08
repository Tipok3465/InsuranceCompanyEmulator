//
// Created by Данил Подлягин on 03.10.2024.
//

#include "Company.h"

void Company::set_home_insurance_price(int price) {
    home_insurance_price = price;
    update_demand();
}

void Company::set_car_insurance_price(int price) {
    car_insurance_price = price;
    update_demand();
}

void Company::set_life_insurance_price(int price) {
    life_insurance_price = price;
    update_demand();
}

void Company::set_cur_balance(int balance) {
    cur_balance = balance;
}

void Company::set_car_insurance_demand(int demand) {
    car_insurance_demand = demand;
}

void Company::set_home_insurance_demand(int demand) {
    home_insurance_demand = demand;
}

void Company::set_life_insurance_demand(int demand) {
    life_insurance_demand = demand;
}

void Company::set_home_insurance_compensation(int compensation) {
    home_insurance_compensation = compensation;
    update_demand();
}

void Company::set_car_insurance_compensation(int compensation) {
    car_insurance_compensation = compensation;
    update_demand();
}

void Company::set_life_insurance_compensation(int compensation) {
    life_insurance_compensation = compensation;
    update_demand();
}

void Company::set_home_insurance_period(int period) {
    home_insurance_period = period;
    update_demand();
}

void Company::set_car_insurance_period(int period) {
    car_insurance_period = period;
    update_demand();
}

void Company::set_life_insurance_period(int period) {
    life_insurance_period = period;
    update_demand();
}

int Company::get_home_insurance_price() const {
    return home_insurance_price;
}

int Company::get_car_insurance_price() const {
    return car_insurance_price;
}

int Company::get_life_insurance_price() const {
    return life_insurance_price;
}

int Company::get_home_insurance_demand() const {
    return home_insurance_demand;
}

int Company::get_car_insurance_demand() const {
    return car_insurance_demand;
}

int Company::get_life_insurance_demand() const {
    return life_insurance_demand;
}

int Company::get_home_insurance_compensation() const {
    return home_insurance_compensation;
}

int Company::get_car_insurance_compensation() const {
    return car_insurance_compensation;
}

int Company::get_life_insurance_compensation() const {
    return life_insurance_compensation;
}

int Company::get_home_insurance_period() const {
    return home_insurance_period;
}

int Company::get_car_insurance_period() const {
    return car_insurance_compensation;
}

int Company::get_life_insurance_period() const {
    return life_insurance_period;
}

int Company::get_cur_balance() const {
    return cur_balance;
}

int Company::tax(int percent) {
    int tax = cur_balance * percent / 100;
    cur_balance -= tax;
    return tax;
}

bool Company::bankrupt() const {
    return cur_balance <= 0;
}

int Company::buy_home_insurance() {
    cur_balance += home_insurance_price;
    return home_insurance_price;
}

int Company::buy_car_insurance() {
    cur_balance += car_insurance_price;
    return car_insurance_price;
}

int Company::buy_life_insurance() {
    cur_balance += life_insurance_price;
    return life_insurance_price;
}

void Company::update_demand() {
    home_insurance_demand = home_insurance_compensation / home_insurance_price / home_insurance_period * 100;
    car_insurance_demand = car_insurance_compensation / car_insurance_price / car_insurance_period * 100;
    life_insurance_demand = life_insurance_compensation / life_insurance_price / life_insurance_period * 100;
}

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

