#include "bitset_type.h"
#include "bit_c11_operators.h"

//   ######  ##    ##  ######  ######## ########   ######
//  ##    ## ###   ## ##    ##    ##    ##     ## ##    ##
//  ##       ####  ## ##          ##    ##     ## ##
//  ##       ## ## ##  ######     ##    ########   ######
//  ##       ##  ####       ##    ##    ##   ##         ##
//  ##    ## ##   ### ##    ##    ##    ##    ##  ##    ##
//   ######  ##    ##  ######     ##    ##     ##  ######

// Default empty constructor
bitset_t::bitset_t() : set() {
	return;
}

// Initializes bitset from list
bitset_t::bitset_t(std::initializer_list<bit_t> bits) : set(bits) {
	return;
}

// Copy constructor
bitset_t::bitset_t(const bitset_t& bits) : set(bits.set) {
	return;
}

// Initializes bitset from vector of bits
bitset_t::bitset_t(std::vector<bit_t>& bits) {
	std::swap(bits, set);
	return;
}

// Initializes bitset from array of bools
bitset_t::bitset_t(const size_t length, const bool* head) {
	set = std::vector<bit_t>(length, head);
	return;
}



//   ######     ###     ######  ########
//  ##    ##   ## ##   ##    ##    ##
//  ##        ##   ##  ##          ##
//  ##       ##     ##  ######     ##
//  ##       #########       ##    ##
//  ##    ## ##     ## ##    ##    ##
//   ######  ##     ##  ######     ##

// Bit_t vector cast
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

// STL begin iterator wrap
std::vector<bit_t>::iterator bitset_t::begin() {
	return set.begin();
}

// STL end iterator wrap
std::vector<bit_t>::iterator bitset_t::end() {
	return set.end();
}

size_t bitset_t::length() {
	return set.size();
}

// Resizes bitset
void bitset_t::resize(size_t length) {
	set.resize(length);
	return;
}

// Resizes bitset
void bitset_t::resize(size_t length, const bit_t& value) {
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

void bitset_t::fillWith(bit_t value) {
	fill(set.begin(), set.end(), value);
	return;
}

void bitset_t::invert() {
	for (bit_t& bit : set)
		bit.invert();
	return;
}

size_t hammingDistance(bitset_t left, bitset_t right) {
	if (right.set.size() > left.set.size())
		std::swap(left, right);
	right.set.insert(right.end(), left.set.size() - right.set.size(), (bit_t)0);
	std::vector<size_t> temp(left.set.size());
	std::transform(left.set.begin(), left.set.end(), right.set.begin(), temp.begin(), bitwise_nequal());
	return std::accumulate(temp.begin(), temp.end(), (size_t)0);
}



//   ######  ##     ## #### ######## ######## #### ##    ##  ######
//  ##    ## ##     ##  ##  ##          ##     ##  ###   ## ##    ##
//  ##       ##     ##  ##  ##          ##     ##  ####  ## ##
//   ######  #########  ##  ######      ##     ##  ## ## ## ##   ####
//        ## ##     ##  ##  ##          ##     ##  ##  #### ##    ##
//  ##    ## ##     ##  ##  ##          ##     ##  ##   ### ##    ##
//   ######  ##     ## #### ##          ##    #### ##    ##  ######

void bitset_t::rotateLeft(size_t shift) {
	reverse(set.begin(), set.end());
	reverse(set.begin(), set.end() - shift);
	reverse(set.end() - shift, set.end());
}

void bitset_t::rotateRight(size_t shift) {
	reverse(set.begin(), set.end());
	reverse(set.begin(), set.begin() + shift);
	reverse(set.begin() + shift, set.end());
}

void bitset_t::shiftLeft(size_t shift) {
	reverse(set.begin(), set.end());
	reverse(set.begin(), set.end() - shift);
	fill(set.end() - shift, set.end(), false);
}

void bitset_t::shiftRight(size_t shift) {
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

bitset_t bitset_t::operator!() {
	bitset_t bits = *this;
	bits.invert();
	return bits;
}

bitset_t bitset_t::operator~() {
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

// XOR
bitset_t bitset_t::operator^(bitset_t& other) {
	bitset_t temp = *this;
	std::transform(temp.set.begin(), temp.set.end(), other.set.begin(), temp.set.begin(), bitwise_xor());
	return temp;
}

// AND
bitset_t bitset_t::operator&(bitset_t& other) {
	bitset_t temp = *this;
	std::transform(temp.set.begin(), temp.set.end(), other.set.begin(), temp.set.begin(), bitwise_and());
	return temp;
}

// OR
bitset_t bitset_t::operator|(bitset_t& other) {
	bitset_t temp = *this;
	std::transform(temp.set.begin(), temp.set.end(), other.set.begin(), temp.set.begin(), bitwise_or());
	return temp;
}

// NAND
bitset_t nand(bitset_t& left, bitset_t& right) {
	bitset_t temp;
	std::transform(left.begin(), left.end(), right.begin(), temp.begin(), bitwise_nand());
	return temp;
}

// NOR
bitset_t nor(bitset_t& left, bitset_t& right) {
	bitset_t temp;
	std::transform(left.begin(), left.end(), right.begin(), temp.begin(), bitwise_nor());
	return temp;
}

// SCALAR PRODUCT
bit_t bitset_t::operator*(bitset_t& other) {
	bitset_t temp = *this;
	std::transform(temp.set.begin(), temp.set.end(), other.set.begin(), temp.set.begin(), bitwise_and());
	return std::accumulate(temp.set.begin(), temp.set.end(), 0, bitwise_xor());
}



//     ###     ######   ######   ######   ##    ## ##     ## ##    ## ########
//    ## ##   ##    ## ##    ## ##    ##  ###   ## ###   ### ###   ##    ##
//   ##   ##  ##       ##       ##        ####  ## #### #### ####  ##    ##
//  ##     ##  ######   ######  ##   #### ## ## ## ## ### ## ## ## ##    ##
//  #########       ##       ## ##    ##  ##  #### ##     ## ##  ####    ##
//  ##     ## ##    ## ##    ## ##    ##  ##   ### ##     ## ##   ###    ##
//  ##     ##  ######   ######   ######   ##    ## ##     ## ##    ##    ##

// Assignment
bitset_t& bitset_t::operator=(bitset_t other) {
	std::swap(this->set, other.set);
	return *this;
}

// XOR assignment
bitset_t& bitset_t::operator^=(const bitset_t& other) {
	std::transform(set.begin(), set.end(), other.set.begin(), set.begin(), bitwise_xor());
	return *this;
}

// AND assignment
bitset_t& bitset_t::operator&=(const bitset_t& other) {
	std::transform(set.begin(), set.end(), other.set.begin(), set.begin(), bitwise_and());
	return *this;
}

// OR assignment
bitset_t& bitset_t::operator|=(const bitset_t& other) {
	std::transform(set.begin(), set.end(), other.set.begin(), set.begin(), bitwise_or());
	return *this;
}

bit_t& bitset_t::operator[] (const size_t index) {
	return set[index];
}



//   ######   #######  ##     ## ########  ########   ######  ##    ##
//  ##    ## ##     ## ###   ### ##     ## ##     ## ##    ## ###   ##
//  ##       ##     ## #### #### ##     ## ##     ## ##       ####  ##
//  ##       ##     ## ## ### ## ########  ########   ######  ## ## ##
//  ##       ##     ## ##     ## ##        ##   ##         ## ##  ####
//  ##    ## ##     ## ##     ## ##        ##    ##  ##    ## ##   ###
//   ######   #######  ##     ## ##        ##     ##  ######  ##    ##

// Equality test
bool bitset_t::operator== (bitset_t& other) {
	bool areEqual = true;
	bitset_t temp = other;
	std::transform(this->begin(), this->end(), other.begin(), temp.begin(), bitwise_equal());
	areEqual = std::accumulate(temp.begin(), temp.end(), areEqual, bitwise_and());
	return areEqual;
}

// Inequality test
bool bitset_t::operator!= (bitset_t& other) {
	bool areEqual = true;
	bitset_t temp = other;
	std::transform(this->begin(), this->end(), other.begin(), temp.begin(), bitwise_equal());
	areEqual = std::accumulate(temp.begin(), temp.end(), areEqual, bitwise_and());
	return !areEqual;
}



//  #### ##    ## ######## ########  ########    ###     ######  ########
//   ##  ###   ##    ##    ##     ## ##         ## ##   ##    ## ##
//   ##  ####  ##    ##    ##     ## ##        ##   ##  ##       ##
//   ##  ## ## ##    ##    ########  ######   ##     ## ##       ######
//   ##  ##  ####    ##    ##   ##   ##       ######### ##       ##
//   ##  ##   ###    ##    ##    ##  ##       ##     ## ##    ## ##
//  #### ##    ##    ##    ##     ## ##       ##     ##  ######  ########

// Returns binary representation of a bit
std::string bitset_t::toBinaryString() {
	return toBinaryString("");
}

std::string bitset_t::toBinaryString(std::string delimiter) {
	std::string temp = "";
	for (bit_t& bit : set)
		temp += bit.toBinaryString() + delimiter;
	temp.pop_back();
	return temp;
}

// Inserts binary representation to stream
std::ostream& operator<<(std::ostream& os, bitset_t& bits) {
	return os << bits.toBinaryString();
}


