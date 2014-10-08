//
//  __bitset_type.h
//  bitlib
//
//  Created by Aaron West on 17.09.14.
//  Copyright (c) 2014 Nemso Unincorporated. All rights reserved.
//

#ifndef bitlib___bitset_type_h
#define bitlib___bitset_type_h

#include "bit_type.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

class bitset_t {
private:
	// Raw std::vector
	std::vector<bit_t> set;
public:

	//   ######  ##    ##  ######  ######## ########   ######
	//  ##    ## ###   ## ##    ##    ##    ##     ## ##    ##
	//  ##       ####  ## ##          ##    ##     ## ##
	//  ##       ## ## ##  ######     ##    ########   ######
	//  ##       ##  ####       ##    ##    ##   ##         ##
	//  ##    ## ##   ### ##    ##    ##    ##    ##  ##    ##
	//   ######  ##    ##  ######     ##    ##     ##  ######

	// Default empty constructor
	bitset_t();

	// Initializes bitset from list
	bitset_t(std::initializer_list<bit_t> bits);

	// Copy constructor
	bitset_t(const bitset_t& bits);

	// Initializes bitset from vector of bits
	bitset_t(std::vector<bit_t>& bits);

	// Initializes bitset from array of bools
	bitset_t(const size_t length, const bool* head);



	//   ######     ###     ######  ########
	//  ##    ##   ## ##   ##    ##    ##
	//  ##        ##   ##  ##          ##
	//  ##       ##     ##  ######     ##
	//  ##       #########       ##    ##
	//  ##    ## ##     ## ##    ##    ##
	//   ######  ##     ##  ######     ##

	// Bit_t vector cast
	operator std::vector<bit_t>();



	//  #### ######## ######## ########  ######## ##    ##  ######
	//   ##     ##    ##       ##     ##    ##    ###   ## ##    ##
	//   ##     ##    ##       ##     ##    ##    ####  ## ##
	//   ##     ##    ######   ########     ##    ## ## ## ##   ####
	//   ##     ##    ##       ##   ##      ##    ##  #### ##    ##
	//   ##     ##    ##       ##    ##     ##    ##   ### ##    ##
	//  ####    ##    ######## ##     ##    ##    ##    ##  ######

	// STL begin iterator wrap
	std::vector<bit_t>::iterator begin();

	// STL end iterator wrap
	std::vector<bit_t>::iterator end();

	// Returns the length of this bitset
	size_t length();

	// Returns the length, added for C++11 compability
	size_t size() {
		return length();
	}

	void resize(size_t length);

	void resize(size_t length, const bit_t& value);



	//  ##        #######   ######   ####  ######
	//  ##       ##     ## ##    ##   ##  ##    ##
	//  ##       ##     ## ##         ##  ##
	//  ##       ##     ## ##   ####  ##  ##
	//  ##       ##     ## ##    ##   ##  ##
	//  ##       ##     ## ##    ##   ##  ##    ##
	//  ########  #######   ######   ####  ######

	// Set all bits to TRUE
	void setAll();

	// Set all bits to FALSE
	void resetAll();

	void fillWith(bit_t value);

	// Invert bitset
	void invert();

	// Hamming distance
	friend size_t hammingDistance(bitset_t left, bitset_t right);



	//   ######  ##     ## #### ######## ######## #### ##    ##  ######
	//  ##    ## ##     ##  ##  ##          ##     ##  ###   ## ##    ##
	//  ##       ##     ##  ##  ##          ##     ##  ####  ## ##
	//   ######  #########  ##  ######      ##     ##  ## ## ## ##   ####
	//        ## ##     ##  ##  ##          ##     ##  ##  #### ##    ##
	//  ##    ## ##     ##  ##  ##          ##     ##  ##   ### ##    ##
	//   ######  ##     ## #### ##          ##    #### ##    ##  ######

	// Cyclic shift bits left
	void rotateLeft(size_t shift);

	// Cyclic shift bits right
	void rotateRight(size_t shift);

	// Shift bits left (data loss warning)
	void shiftLeft(size_t shift);

	// Shift bits right (data loss warning)
	void shiftRight(size_t shift);



	//  ##     ## ##    ##    ###    ########  ##    ##
	//  ##     ## ###   ##   ## ##   ##     ##  ##  ##
	//  ##     ## ####  ##  ##   ##  ##     ##   ####
	//  ##     ## ## ## ## ##     ## ########     ##
	//  ##     ## ##  #### ######### ##   ##      ##
	//  ##     ## ##   ### ##     ## ##    ##     ##
	//   #######  ##    ## ##     ## ##     ##    ##

	// Bitset full complement
	bitset_t operator!();

	// Bitset full complement
	bitset_t operator~();



	//  ########  #### ##    ##    ###    ########  ##    ##
	//  ##     ##  ##  ###   ##   ## ##   ##     ##  ##  ##
	//  ##     ##  ##  ####  ##  ##   ##  ##     ##   ####
	//  ########   ##  ## ## ## ##     ## ########     ##
	//  ##     ##  ##  ##  #### ######### ##   ##      ##
	//  ##     ##  ##  ##   ### ##     ## ##    ##     ##
	//  ########  #### ##    ## ##     ## ##     ##    ##

	// XOR
	bitset_t operator^(bitset_t& other);

	// AND
	bitset_t operator&(bitset_t& other);

	// OR
	bitset_t operator|(bitset_t& other);

	// SCALAR PRODUCT W/XOR
	bit_t operator*(bitset_t& other);

	// NAND
	friend bitset_t nand(bitset_t& left, bitset_t& right);

	// NOR
	friend bitset_t nor(bitset_t& left, bitset_t& right);



	//     ###     ######   ######   ######   ##    ## ##     ## ##    ## ########
	//    ## ##   ##    ## ##    ## ##    ##  ###   ## ###   ### ###   ##    ##
	//   ##   ##  ##       ##       ##        ####  ## #### #### ####  ##    ##
	//  ##     ##  ######   ######  ##   #### ## ## ## ## ### ## ## ## ##    ##
	//  #########       ##       ## ##    ##  ##  #### ##     ## ##  ####    ##
	//  ##     ## ##    ## ##    ## ##    ##  ##   ### ##     ## ##   ###    ##
	//  ##     ##  ######   ######   ######   ##    ## ##     ## ##    ##    ##

	// Assignment
	bitset_t& operator=(bitset_t other);

	// XOR assignment
	bitset_t& operator^=(const bitset_t& other);

	// AND assignment
	bitset_t& operator&=(const bitset_t& other);

	// OR assignment
	bitset_t& operator|=(const bitset_t& other);

	bit_t& operator[] (const size_t index);

	//   ######   #######  ##     ## ########  ########   ######  ##    ##
	//  ##    ## ##     ## ###   ### ##     ## ##     ## ##    ## ###   ##
	//  ##       ##     ## #### #### ##     ## ##     ## ##       ####  ##
	//  ##       ##     ## ## ### ## ########  ########   ######  ## ## ##
	//  ##       ##     ## ##     ## ##        ##   ##         ## ##  ####
	//  ##    ## ##     ## ##     ## ##        ##    ##  ##    ## ##   ###
	//   ######   #######  ##     ## ##        ##     ##  ######  ##    ##

	// Equality test
	bool operator== (bitset_t& other);

	// Inequality test
	bool operator!= (bitset_t& other);



	//  #### ##    ## ######## ########  ########    ###     ######  ########
	//   ##  ###   ##    ##    ##     ## ##         ## ##   ##    ## ##
	//   ##  ####  ##    ##    ##     ## ##        ##   ##  ##       ##
	//   ##  ## ## ##    ##    ########  ######   ##     ## ##       ######
	//   ##  ##  ####    ##    ##   ##   ##       ######### ##       ##
	//   ##  ##   ###    ##    ##    ##  ##       ##     ## ##    ## ##
	//  #### ##    ##    ##    ##     ## ##       ##     ##  ######  ########

	// Returns binary representation of a bit
	std::string toBinaryString();

	std::string toBinaryString(std::string delimiter);

	// Inserts binary representation to stream
	friend std::ostream& operator<<(std::ostream& os, const bitset_t& bits);
};

#endif
