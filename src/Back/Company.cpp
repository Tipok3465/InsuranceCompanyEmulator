//
// Created by Данил Подлягин on 03.10.2024.
//

#include "Company.h"

void Company::set_home_insurance_price(int price) {
    home_insurance_price = price;
}

void Company::set_car_insurance_price(int price) {
    car_insurance_price = price;
}

void Company::set_life_insurance_price(int price) {
    life_insurance_price = price;
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

int Company::get_home_insurance_price() {
    return home_insurance_price;
}

int Company::get_car_insurance_price() {
    return car_insurance_price;
}

int Company::get_life_insurance_price() {
    return life_insurance_price;
}

int Company::get_home_insurance_demand() {
    return home_insurance_demand;
}

int Company::get_car_insurance_demand() {
    return car_insurance_demand;
}

int Company::get_life_insurance_demand() {
    return life_insurance_demand;
}

int Company::get_cur_balance() {
    return cur_balance;
}

int Company::tax(int percent) {
    int tax = cur_balance * percent / 100;
    cur_balance -= tax;
    return tax;
}

bool Company::bankrupt() {
    return cur_balance <= 0;
}
