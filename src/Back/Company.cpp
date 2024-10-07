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
}

void Company::set_car_insurance_period(int period) {
    car_insurance_period = period;
}

void Company::set_life_insurance_period(int period) {
    life_insurance_period = period;
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
std::vector<std::vector<bool>> peoples_insurances(Company co) {
    std::vector<std::vector<bool>> res(100);
    for (int i = 0; i < 100; ++i) {
        int determinant = (int)rnd() % 100;
        if (determinant <= co.get_home_insurance_demand()) {
            res[i][0] = true;
        }
        determinant = (int)rnd() % 100;
        if (determinant <= co.get_car_insurance_demand()) {
            res[i][1] = true;
        }
        determinant = (int)rnd() % 100;
        if (determinant <= co.get_life_insurance_demand()) {
            res[i][2] = true;
        }
    }
    return res;
}

std::vector<std::vector<std::pair<bool, double>>> insurance_cases(std::vector<std::vector<bool>> peoples_insurances,
                                                                  Company co) {
    std::vector<std::vector<std::pair<bool, double>>> res(100);
    int cases_home = (int)rnd() % 40;
    int cases_car = (int)rnd() % 40;
    int cases_life = (int)rnd() % 40;
    for(int i = 0; i < 40; ++i) {
        if (peoples_insurances[i][0] && i < cases_home) {
            res[i][0].first = true;
            auto coefficient = (double)rnd();
            coefficient -= (int)coefficient;
            res[i][0].second = coefficient;
        }
        if (peoples_insurances[i][1] && i < cases_car) {
            res[i][1].first = true;
            auto coefficient = (double)rnd();
            coefficient -= (int)coefficient;
            res[i][1].second = coefficient;
        }
        if (peoples_insurances[i][2] && i < cases_life) {
            res[i][2].first = true;
            auto coefficient = (double)rnd();
            coefficient -= (int)coefficient;
            res[i][2].second = coefficient;
        }
    }
    return res;
}

std::vector<std::pair<int, int>> month_result(std::vector<std::vector<bool>> peoples_insurances,
                                              std::vector<std::vector<std::pair<bool, double>>> insurance_cases,
                                              Company co) {
// home, car, life
    std::vector<std::pair<int, int>> res(3);
    for (int i = 0; i < 100; ++i) {
        res[0].first += peoples_insurances[i][0] * co.get_home_insurance_price();
        res[0].second += insurance_cases[i][0].first * co.get_home_insurance_compensation() * insurance_cases[i][0].second;

        res[1].first += peoples_insurances[i][1] * co.get_car_insurance_price();
        res[1].second += insurance_cases[i][1].first * co.get_car_insurance_compensation() * insurance_cases[i][1].second;

        res[2].first += peoples_insurances[i][2] * co.get_life_insurance_price();
        res[2].second += insurance_cases[i][2].first * co.get_life_insurance_compensation() * insurance_cases[i][2].second;
    }
    return res;
}

