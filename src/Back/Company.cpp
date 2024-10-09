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
    return car_insurance_period;
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
    home_insurance_demand = home_insurance_compensation / home_insurance_price / home_insurance_period * 40;
    car_insurance_demand = car_insurance_compensation / car_insurance_price / car_insurance_period * 40;
    life_insurance_demand = life_insurance_compensation / life_insurance_price / life_insurance_period * 40;
}

