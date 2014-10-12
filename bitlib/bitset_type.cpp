#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

#include "bitset_type.h"
#include "bit_c11_operators.h"


//   ######  ##    ##  ######  ######## ########   ######
//  ##    ## ###   ## ##    ##    ##    ##     ## ##    ##
//  ##       ####  ## ##          ##    ##     ## ##
//  ##       ## ## ##  ######     ##    ########   ######
//  ##       ##  ####       ##    ##    ##   ##         ##
//  ##    ## ##   ### ##    ##    ##    ##    ##  ##    ##
//   ######  ##    ##  ######     ##    ##     ##  ######

bitset_t::bitset_t() : set() {
	return;
}

bitset_t::bitset_t(const std::initializer_list<bit_t> bits) : set(bits) {
	return;
}

bitset_t::bitset_t(const std::initializer_list<bool> bits) : set(bits.begin(), bits.end()) {
	return;
}

bitset_t::bitset_t(const bitset_t& bits) : set(bits.set) {
	return;
}

bitset_t::bitset_t(const std::vector<bit_t>& bits) : set(bits) {
	return;
}

bitset_t::bitset_t(const std::vector<bool>& bits) : set(bits.begin(), bits.end()) {
	return;
}

bitset_t::bitset_t(const bool* head, const size_t length) : set(head, head + length) {
	return;
}



//   ######     ###     ######  ########
//  ##    ##   ## ##   ##    ##    ##
//  ##        ##   ##  ##          ##
//  ##       ##     ##  ######     ##
//  ##       #########       ##    ##
//  ##    ## ##     ## ##    ##    ##
//   ######  ##     ##  ######     ##

bitset_t::operator std::vector<bit_t>() {
	return set;
}



//  #### ######## ######## ########  ######## ##    ##  ######
//   ##     ##    ##       ##     ##    ##    ###   ## ##    ##
//   ##     ##    ##       ##     ##    ##    ####  ## ##
//   ##     ##    ######   ########     ##    ## ## ## ##   ####
//   ##     ##    ##       ##   ##      ##    ##  #### ##    ##
//   ##     ##    ##       ##    ##     ##    ##   ### ##    ##
//  ####    ##    ######## ##     ##    ##    ##    ##  ######

std::vector<bit_t>::iterator bitset_t::begin() {
	return set.begin();
}

std::vector<bit_t>::const_iterator bitset_t::begin() const {
	return set.begin();
}

std::vector<bit_t>::iterator bitset_t::end() {
	return set.end();
}

std::vector<bit_t>::const_iterator bitset_t::end() const {
	return set.end();
}

size_t bitset_t::length() const {
	return set.size();
}

void bitset_t::resize(const size_t length) {
	set.resize(length);
	return;
}

void bitset_t::resize(const size_t length, const bit_t& value) {
	set.resize(length, value);
	return;
}


//  ##        #######   ######   ####  ######
//  ##       ##     ## ##    ##   ##  ##    ##
//  ##       ##     ## ##         ##  ##
//  ##       ##     ## ##   ####  ##  ##
//  ##       ##     ## ##    ##   ##  ##
//  ##       ##     ## ##    ##   ##  ##    ##
//  ########  #######   ######   ####  ######

void bitset_t::setAll() {
	fill(set.begin(), set.end(), true);
	return;
}

void bitset_t::resetAll() {
	fill(set.begin(), set.end(), false);
	return;
}

void bitset_t::fillWith(const bit_t value) {
	fill(set.begin(), set.end(), value);
	return;
}

void bitset_t::invert() {
	for (bit_t& bit : set)
		bit.invert();
	return;
}

size_t hammingDistance(const bitset_t left, const bitset_t right) {
	return std::inner_product(left.begin(),
					  left.end(),
					  right.begin(),
					  0,
					  std::plus<size_t>(),
					  bitwise_nequal());
}



//   ######  ##     ## #### ######## ######## #### ##    ##  ######
//  ##    ## ##     ##  ##  ##          ##     ##  ###   ## ##    ##
//  ##       ##     ##  ##  ##          ##     ##  ####  ## ##
//   ######  #########  ##  ######      ##     ##  ## ## ## ##   ####
//        ## ##     ##  ##  ##          ##     ##  ##  #### ##    ##
//  ##    ## ##     ##  ##  ##          ##     ##  ##   ### ##    ##
//   ######  ##     ## #### ##          ##    #### ##    ##  ######

void bitset_t::rotateLeft(const size_t shift) {
	std::rotate(set.begin(), set.begin() + shift, set.end());
}

void bitset_t::rotateRight(const size_t shift) {
	std::rotate(set.begin(), set.end() - shift, set.end());
}

void bitset_t::shiftLeft(const size_t shift) {
	reverse(set.begin(), set.end());
	reverse(set.begin(), set.end() - shift);
	fill(set.end() - shift, set.end(), false);
}

void bitset_t::shiftRight(const size_t shift) {
	reverse(set.begin(), set.end());
	fill(set.begin(), set.begin() + shift, false);
	reverse(set.begin() + shift, set.end());
}



//  ##     ## ##    ##    ###    ########  ##    ##
//  ##     ## ###   ##   ## ##   ##     ##  ##  ##
//  ##     ## ####  ##  ##   ##  ##     ##   ####
//  ##     ## ## ## ## ##     ## ########     ##
//  ##     ## ##  #### ######### ##   ##      ##
//  ##     ## ##   ### ##     ## ##    ##     ##
//   #######  ##    ## ##     ## ##     ##    ##

bitset_t bitset_t::operator!() const {
	bitset_t bits = *this;
	bits.invert();
	return bits;
}

bitset_t bitset_t::operator~() const {
	bitset_t bits = *this;
	bits.invert();
	return bits;
}



//  ########  #### ##    ##    ###    ########  ##    ##
//  ##     ##  ##  ###   ##   ## ##   ##     ##  ##  ##
//  ##     ##  ##  ####  ##  ##   ##  ##     ##   ####
//  ########   ##  ## ## ## ##     ## ########     ##
//  ##     ##  ##  ##  #### ######### ##   ##      ##
//  ##     ##  ##  ##   ### ##     ## ##    ##     ##
//  ########  #### ##    ## ##     ## ##     ##    ##

bitset_t bitset_t::operator^(const bitset_t& other) const {
	bitset_t temp = *this;
	std::transform(temp.set.begin(), temp.set.end(), other.set.begin(), temp.set.begin(), bitwise_xor());
	return temp;
}

bitset_t bitset_t::operator&(const bitset_t& other) const {
	bitset_t temp = *this;
	std::transform(temp.set.begin(), temp.set.end(), other.set.begin(), temp.set.begin(), bitwise_and());
	return temp;
}

bitset_t bitset_t::operator|(const bitset_t& other) const {
	bitset_t temp = *this;
	std::transform(temp.set.begin(), temp.set.end(), other.set.begin(), temp.set.begin(), bitwise_or());
	return temp;
}

bitset_t nand(bitset_t& left, bitset_t& right) {
	bitset_t temp;
	std::transform(left.begin(), left.end(), right.begin(), temp.begin(), bitwise_nand());
	return temp;
}

bitset_t nor(bitset_t& left, bitset_t& right) {
	bitset_t temp;
	std::transform(left.begin(), left.end(), right.begin(), temp.begin(), bitwise_nor());
	return temp;
}

bit_t bitset_t::operator*(const bitset_t& other) const {
	return std::inner_product(this->begin(),
					  this->end(),
					  other.begin(),
					  0,
					  bitwise_and(),
					  bitwise_nequal());
}



//     ###     ######   ######   ######   ##    ## ##     ## ##    ## ########
//    ## ##   ##    ## ##    ## ##    ##  ###   ## ###   ### ###   ##    ##
//   ##   ##  ##       ##       ##        ####  ## #### #### ####  ##    ##
//  ##     ##  ######   ######  ##   #### ## ## ## ## ### ## ## ## ##    ##
//  #########       ##       ## ##    ##  ##  #### ##     ## ##  ####    ##
//  ##     ## ##    ## ##    ## ##    ##  ##   ### ##     ## ##   ###    ##
//  ##     ##  ######   ######   ######   ##    ## ##     ## ##    ##    ##

bitset_t& bitset_t::operator=(const bitset_t other) {
	set = other.set;
	return *this;
}

bitset_t& bitset_t::operator^=(const bitset_t& other) {
	std::transform(set.begin(), set.end(), other.set.begin(), set.begin(), bitwise_xor());
	return *this;
}

bitset_t& bitset_t::operator&=(const bitset_t& other) {
	std::transform(set.begin(), set.end(), other.set.begin(), set.begin(), bitwise_and());
	return *this;
}

bitset_t& bitset_t::operator|=(const bitset_t& other) {
	std::transform(set.begin(), set.end(), other.set.begin(), set.begin(), bitwise_or());
	return *this;
}

std::vector<bit_t>::reference bitset_t::operator[] (const size_t index) {
	return set[index];
}

std::vector<bit_t>::const_reference bitset_t::operator[] (const size_t index) const {
	return set[index];
}

std::vector<bit_t>::reference bitset_t::at(const size_t index) {
	return set.at(index);
}

std::vector<bit_t>::const_reference bitset_t::at(const size_t index) const {
	return set.at(index);
}


//   ######   #######  ##     ## ########  ########   ######  ##    ##
//  ##    ## ##     ## ###   ### ##     ## ##     ## ##    ## ###   ##
//  ##       ##     ## #### #### ##     ## ##     ## ##       ####  ##
//  ##       ##     ## ## ### ## ########  ########   ######  ## ## ##
//  ##       ##     ## ##     ## ##        ##   ##         ## ##  ####
//  ##    ## ##     ## ##     ## ##        ##    ##  ##    ## ##   ###
//   ######   #######  ##     ## ##        ##     ##  ######  ##    ##

bool bitset_t::operator== (bitset_t& other) {
	return (hammingDistance(*this, other) == 0);
}

bool bitset_t::operator!= (bitset_t& other) {
	return (hammingDistance(*this, other) != 0);
}



//  #### ##    ## ######## ########  ########    ###     ######  ########
//   ##  ###   ##    ##    ##     ## ##         ## ##   ##    ## ##
//   ##  ####  ##    ##    ##     ## ##        ##   ##  ##       ##
//   ##  ## ## ##    ##    ########  ######   ##     ## ##       ######
//   ##  ##  ####    ##    ##   ##   ##       ######### ##       ##
//   ##  ##   ###    ##    ##    ##  ##       ##     ## ##    ## ##
//  #### ##    ##    ##    ##     ## ##       ##     ##  ######  ########

std::string bitset_t::toBinaryString() const {
	return toBinaryString("");
}

std::string bitset_t::toBinaryString(const std::string delimiter) const {
	std::string temp = "";
	for (bit_t bit : set)
		temp += bit.toBinaryString() + delimiter;
	if (!delimiter.empty()) temp.pop_back();
	return temp;
}

std::ostream& operator<<(std::ostream& os, const bitset_t& bits) {
	return os << bits.toBinaryString();
}


