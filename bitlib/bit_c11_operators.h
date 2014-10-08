#ifndef bitty_bit_c11_operators_h
#define bitty_bit_c11_operators_h

#include "bit_type.h"

//   #######  ########  ######## ########  ######## ##    ##  ######
//  ##     ## ##     ## ##       ##     ##    ##    ###   ## ##    ##
//  ##     ## ##     ## ##       ##     ##    ##    ####  ## ##
//  ##     ## ########  ######   ########     ##    ## ## ##  ######
//  ##     ## ##        ##       ##   ##      ##    ##  ####       ##
//  ##     ## ##        ##       ##    ##     ##    ##   ### ##    ##
//   #######  ##        ######## ##     ##    ##    ##    ##  ######

struct bitwise_xor : public std::binary_function<bit_t, bit_t, bit_t> {
	bit_t operator() (bit_t left, bit_t right) {
		return left ^ right;
	}
};

struct bitwise_and : public std::binary_function<bit_t, bit_t, bit_t> {
	bit_t operator() (bit_t left, bit_t right) {
		return left & right;
	}
};

struct bitwise_or : public std::binary_function<bit_t, bit_t, bit_t> {
	bit_t operator() (bit_t left, bit_t right) {
		return left | right;
	}
};

struct bitwise_nand : public std::binary_function<bit_t, bit_t, bit_t> {
	bit_t operator() (bit_t left, bit_t right) {
		return nand(left, right);
	}
};

struct bitwise_nor : public std::binary_function<bit_t, bit_t, bit_t> {
	bit_t operator() (bit_t left, bit_t right) {
		return nor(left, right);
	}
};

struct bitwise_equal : public std::binary_function<bit_t, bit_t, bool> {
	bool operator() (bit_t left, bit_t right) {
		return (left == right);
	}
};

struct bitwise_nequal : public std::binary_function<bit_t, bit_t, bool> {
	bool operator() (bit_t left, bit_t right) {
		return (left != right);
	}
};

#endif
