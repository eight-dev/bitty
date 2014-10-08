#include <iostream>
#include "bit_type.h"

//   ######  ##    ##  ######  ######## ########   ######
//  ##    ## ###   ## ##    ##    ##    ##     ## ##    ##
//  ##       ####  ## ##          ##    ##     ## ##
//  ##       ## ## ##  ######     ##    ########   ######
//  ##       ##  ####       ##    ##    ##   ##         ##
//  ##    ## ##   ### ##    ##    ##    ##    ##  ##    ##
//   ######  ##    ##  ######     ##    ##     ##  ######

// Default empty constructor
bit_t::bit_t() {
	value = 0;
	return;
}

// Boolean constructor
bit_t::bit_t(bool bit) : value(bit) {
	return;
}

// Integer constructor
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

// Bool cast
bit_t::operator bool() {
	return value;
}

// Integer cast
bit_t::operator int() {
	return (value ? 1 : 0);
}

// Size_t cast
bit_t::operator size_t() {
	return (value ? 1 : 0);
}



//  ##        #######   ######   ####  ######
//  ##       ##     ## ##    ##   ##  ##    ##
//  ##       ##     ## ##         ##  ##
//  ##       ##     ## ##   ####  ##  ##
//  ##       ##     ## ##    ##   ##  ##
//  ##       ##     ## ##    ##   ##  ##    ##
//  ########  #######   ######   ####  ######

// Set bit to TRUE
void bit_t::set() {
	value = true;
	return;
}

// Set bit to FALSE
void bit_t::reset() {
	value = false;
	return;
}

// Invert bit
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

// Bit's complement
bit_t bit_t::operator!() {
	return (bit_t)(!value);
}

// Bit's complement
bit_t bit_t::operator~() {
	return (bit_t)(!value);
}

// Increment bit (prefix)
bit_t& bit_t::operator++() {
	this->invert();
	return *this;
}

// Decrement bit (prefix)
bit_t& bit_t::operator--() {
	this->invert();
	return *this;
}

// Increment bit (postfix)
bit_t& bit_t::operator++(int) {
	this->invert();
	return *this;
}

// Decrement bit (postfix)
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

// Exclusive or (xor, addition modulo 2)
bit_t bit_t::operator^(bit_t& other) {
	return (bit_t)((this->value || other.value) && !(this->value && other.value));
}

// Conjunction (and)
bit_t bit_t::operator&(bit_t& other) {
	return (bit_t)(this->value && other.value);
}

// Disjunction (or)
bit_t bit_t::operator|(bit_t& other) {
	return (bit_t)(this->value || other.value);
}

// Nand (negated and)
bit_t nand(bit_t& left, bit_t& right) {
	return (bit_t)(!(left.value && right.value));
}

// Nor (negated or)
bit_t nor(bit_t& left, bit_t& right) {
	return (bit_t)(!(left.value || right.value));
}


//     ###     ######   ######   ######   ##    ## ##     ## ##    ## ########
//    ## ##   ##    ## ##    ## ##    ##  ###   ## ###   ### ###   ##    ##
//   ##   ##  ##       ##       ##        ####  ## #### #### ####  ##    ##
//  ##     ##  ######   ######  ##   #### ## ## ## ## ### ## ## ## ##    ##
//  #########       ##       ## ##    ##  ##  #### ##     ## ##  ####    ##
//  ##     ## ##    ## ##    ## ##    ##  ##   ### ##     ## ##   ###    ##
//  ##     ##  ######   ######   ######   ##    ## ##     ## ##    ##    ##

// Assignment
bit_t& bit_t::operator=(bit_t other) {
	std::swap(this->value, other.value);
	return *this;
}

// Exclusive or assignment
bit_t& bit_t::operator^=(const bit_t& other) {
	if (other.value) invert();
	return *this;
}

// Conjuction assignment
bit_t& bit_t::operator&=(const bit_t& other) {
	if (!other.value) reset();
	return *this;
}

// Disjunction assignment
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

// Equality test
bool bit_t::operator==(bit_t& other) {
	return (bool)(this->value == other.value);
}

// Inequality test
bool bit_t::operator!=(bit_t& other) {
	return (bool)(this->value != other.value);
}



//  ########  ######## ##          ###    ######## ##    ##  ######
//  ##     ## ##       ##         ## ##      ##    ###   ## ##    ##
//  ##     ## ##       ##        ##   ##     ##    ####  ## ##
//  ########  ######   ##       ##     ##    ##    ## ## ##  ######
//  ##   ##   ##       ##       #########    ##    ##  ####       ##
//  ##    ##  ##       ##       ##     ##    ##    ##   ### ##    ##
//  ##     ## ######## ######## ##     ##    ##    ##    ##  ######

// 'Less than' relation
bool bit_t::operator<(const bit_t& other) {
	return ((this->value == false) && (other.value == true));
}

// 'Greater than' relation
bool bit_t::operator>(const bit_t& other) {
	return ((this->value == true) && (other.value == false));
}

// 'Less than or equal to' relation
bool bit_t::operator<=(const bit_t& other) {
	return !((this->value == true) && (other.value == false));
}

// 'Greater than or equal to' relation
bool bit_t::operator>=(const bit_t& other) {
	return !((this->value == false) && (other.value == true));
}



//  #### ##    ## ######## ########  ########    ###     ######  ########
//   ##  ###   ##    ##    ##     ## ##         ## ##   ##    ## ##
//   ##  ####  ##    ##    ##     ## ##        ##   ##  ##       ##
//   ##  ## ## ##    ##    ########  ######   ##     ## ##       ######
//   ##  ##  ####    ##    ##   ##   ##       ######### ##       ##
//   ##  ##   ###    ##    ##    ##  ##       ##     ## ##    ## ##
//  #### ##    ##    ##    ##     ## ##       ##     ##  ######  ########

// Returns binary representation of a bit
std::string bit_t::toBinaryString() const {
	return (value ? "1" : "0");
}

// Inserts binary bit representation into ostream
std::ostream& operator<<(std::ostream& os, const bit_t& bit)
{
	os << bit.toBinaryString();
	return os;
}
