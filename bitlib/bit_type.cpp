/**
 * @file bit_type.cpp
 * @implements bit_type.h
 * @date October 9, 2014
 * @brief Contains implementation of the `bit_t` class routines
 */

#include "bit_type.h"



//   ######  ##    ##  ######  ######## ########   ######
//  ##    ## ###   ## ##    ##    ##    ##     ## ##    ##
//  ##       ####  ## ##          ##    ##     ## ##
//  ##       ## ## ##  ######     ##    ########   ######
//  ##       ##  ####       ##    ##    ##   ##         ##
//  ##    ## ##   ### ##    ##    ##    ##    ##  ##    ##
//   ######  ##    ##  ######     ##    ##     ##  ######

bit_t::bit_t() : value(0) {
	return;
}

bit_t::bit_t(bool bit) : value(bit) {
	return;
}

bit_t::bit_t(int bit) {
	value = (bit > 0);
	return;
}



//   ######     ###     ######  ########
//  ##    ##   ## ##   ##    ##    ##
//  ##        ##   ##  ##          ##
//  ##       ##     ##  ######     ##
//  ##       #########       ##    ##
//  ##    ## ##     ## ##    ##    ##
//   ######  ##     ##  ######     ##

bit_t::operator bool() {
	return value;
}

bit_t::operator int() {
	return (value ? (int)1 : (int)0);
}

bit_t::operator size_t() {
	return (value ? (size_t)1 : (size_t)0);
}



//  ##        #######   ######   ####  ######
//  ##       ##     ## ##    ##   ##  ##    ##
//  ##       ##     ## ##         ##  ##
//  ##       ##     ## ##   ####  ##  ##
//  ##       ##     ## ##    ##   ##  ##
//  ##       ##     ## ##    ##   ##  ##    ##
//  ########  #######   ######   ####  ######

void bit_t::set() {
	value = true;
	return;
}

void bit_t::reset() {
	value = false;
	return;
}

void bit_t::invert() {
	value = !value;
	return;
}



//  ##     ## ##    ##    ###    ########  ##    ##
//  ##     ## ###   ##   ## ##   ##     ##  ##  ##
//  ##     ## ####  ##  ##   ##  ##     ##   ####
//  ##     ## ## ## ## ##     ## ########     ##
//  ##     ## ##  #### ######### ##   ##      ##
//  ##     ## ##   ### ##     ## ##    ##     ##
//   #######  ##    ## ##     ## ##     ##    ##

bit_t bit_t::operator!() const {
	return (bit_t)(!value);
}

bit_t bit_t::operator~() const {
	return (bit_t)(!value);
}

bit_t& bit_t::operator++() {
	this->invert();
	return *this;
}

bit_t& bit_t::operator--() {
	this->invert();
	return *this;
}

bit_t& bit_t::operator++(int) {
	this->invert();
	return *this;
}

bit_t& bit_t::operator--(int) {
	this->invert();
	return *this;
}



//  ########  #### ##    ##    ###    ########  ##    ##
//  ##     ##  ##  ###   ##   ## ##   ##     ##  ##  ##
//  ##     ##  ##  ####  ##  ##   ##  ##     ##   ####
//  ########   ##  ## ## ## ##     ## ########     ##
//  ##     ##  ##  ##  #### ######### ##   ##      ##
//  ##     ##  ##  ##   ### ##     ## ##    ##     ##
//  ########  #### ##    ## ##     ## ##     ##    ##

bit_t bit_t::operator^(const bit_t& other) const {
	return (bit_t)((this->value || other.value) && !(this->value && other.value));
}

bit_t bit_t::operator&(const bit_t& other) const {
	return (bit_t)(this->value && other.value);
}

bit_t bit_t::operator|(const bit_t& other) const {
	return (bit_t)(this->value || other.value);
}

bit_t nand(const bit_t& left, const bit_t& right) {
	return (bit_t)(!(left.value && right.value));
}

bit_t nor(const bit_t& left, const bit_t& right) {
	return (bit_t)(!(left.value || right.value));
}


//     ###     ######   ######   ######   ##    ## ##     ## ##    ## ########
//    ## ##   ##    ## ##    ## ##    ##  ###   ## ###   ### ###   ##    ##
//   ##   ##  ##       ##       ##        ####  ## #### #### ####  ##    ##
//  ##     ##  ######   ######  ##   #### ## ## ## ## ### ## ## ## ##    ##
//  #########       ##       ## ##    ##  ##  #### ##     ## ##  ####    ##
//  ##     ## ##    ## ##    ## ##    ##  ##   ### ##     ## ##   ###    ##
//  ##     ##  ######   ######   ######   ##    ## ##     ## ##    ##    ##

bit_t& bit_t::operator=(bit_t other) {
	std::swap(this->value, other.value);
	return *this;
}

bit_t& bit_t::operator^=(const bit_t& other) {
	if (other.value) invert();
	return *this;
}

bit_t& bit_t::operator&=(const bit_t& other) {
	if (!other.value) reset();
	return *this;
}

bit_t& bit_t::operator|=(const bit_t& other) {
	if (other.value) set();
	return *this;
}



//   ######   #######  ##     ## ########  ########   ######  ##    ##
//  ##    ## ##     ## ###   ### ##     ## ##     ## ##    ## ###   ##
//  ##       ##     ## #### #### ##     ## ##     ## ##       ####  ##
//  ##       ##     ## ## ### ## ########  ########   ######  ## ## ##
//  ##       ##     ## ##     ## ##        ##   ##         ## ##  ####
//  ##    ## ##     ## ##     ## ##        ##    ##  ##    ## ##   ###
//   ######   #######  ##     ## ##        ##     ##  ######  ##    ##

bool bit_t::operator==(const bit_t& other) const {
	return (bool)(this->value == other.value);
}

bool bit_t::operator!=(const bit_t& other) const {
	return (bool)(this->value != other.value);
}



//  ########  ######## ##          ###    ######## ##    ##  ######
//  ##     ## ##       ##         ## ##      ##    ###   ## ##    ##
//  ##     ## ##       ##        ##   ##     ##    ####  ## ##
//  ########  ######   ##       ##     ##    ##    ## ## ##  ######
//  ##   ##   ##       ##       #########    ##    ##  ####       ##
//  ##    ##  ##       ##       ##     ##    ##    ##   ### ##    ##
//  ##     ## ######## ######## ##     ##    ##    ##    ##  ######

bool bit_t::operator<(const bit_t& other) const {
	return ((this->value == false) && (other.value == true));
}

bool bit_t::operator>(const bit_t& other) const {
	return ((this->value == true) && (other.value == false));
}

bool bit_t::operator<=(const bit_t& other) const {
	return !((this->value == true) && (other.value == false));
}

bool bit_t::operator>=(const bit_t& other) const {
	return !((this->value == false) && (other.value == true));
}



//  #### ##    ## ######## ########  ########    ###     ######  ########
//   ##  ###   ##    ##    ##     ## ##         ## ##   ##    ## ##
//   ##  ####  ##    ##    ##     ## ##        ##   ##  ##       ##
//   ##  ## ## ##    ##    ########  ######   ##     ## ##       ######
//   ##  ##  ####    ##    ##   ##   ##       ######### ##       ##
//   ##  ##   ###    ##    ##    ##  ##       ##     ## ##    ## ##
//  #### ##    ##    ##    ##     ## ##       ##     ##  ######  ########

std::string bit_t::toBinaryString() const {
	return (value ? "1" : "0");
}

std::ostream& operator<<(std::ostream& os, const bit_t& bit)
{
	os << bit.toBinaryString();
	return os;
}
