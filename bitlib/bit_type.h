#ifndef bitty_bit_type_h
#define bitty_bit_type_h

class bit_t {
private:
	bool value;
public:

	//   ######  ##    ##  ######  ######## ########   ######
	//  ##    ## ###   ## ##    ##    ##    ##     ## ##    ##
	//  ##       ####  ## ##          ##    ##     ## ##
	//  ##       ## ## ##  ######     ##    ########   ######
	//  ##       ##  ####       ##    ##    ##   ##         ##
	//  ##    ## ##   ### ##    ##    ##    ##    ##  ##    ##
	//   ######  ##    ##  ######     ##    ##     ##  ######

	// Default empty constructor
	bit_t();

	// Boolean constructor
	bit_t(bool bit);

	// Integer constructor
	bit_t(int bit);



	//   ######     ###     ######  ########
	//  ##    ##   ## ##   ##    ##    ##
	//  ##        ##   ##  ##          ##
	//  ##       ##     ##  ######     ##
	//  ##       #########       ##    ##
	//  ##    ## ##     ## ##    ##    ##
	//   ######  ##     ##  ######     ##

	// Bool cast
	operator bool();

	// Integer cast
	operator int();

	// Size_t cast
	operator size_t();



	//  ##        #######   ######   ####  ######
	//  ##       ##     ## ##    ##   ##  ##    ##
	//  ##       ##     ## ##         ##  ##
	//  ##       ##     ## ##   ####  ##  ##
	//  ##       ##     ## ##    ##   ##  ##
	//  ##       ##     ## ##    ##   ##  ##    ##
	//  ########  #######   ######   ####  ######

	// Set bit to TRUE
	void set();

	// Set bit to FALSE
	void reset();

	// Invert bit
	void invert();



	//  ##     ## ##    ##    ###    ########  ##    ##
	//  ##     ## ###   ##   ## ##   ##     ##  ##  ##
	//  ##     ## ####  ##  ##   ##  ##     ##   ####
	//  ##     ## ## ## ## ##     ## ########     ##
	//  ##     ## ##  #### ######### ##   ##      ##
	//  ##     ## ##   ### ##     ## ##    ##     ##
	//   #######  ##    ## ##     ## ##     ##    ##

	// Bit's complement
	bit_t operator!();

	// Bit's complement
	bit_t operator~();

	// Increment bit (prefix)
	bit_t& operator++();

	// Decrement bit (prefix)
	bit_t& operator--();

	// Increment bit (postfix)
	bit_t& operator++(int);

	// Decrement bit (postfix)
	bit_t& operator--(int);



	//  ########  #### ##    ##    ###    ########  ##    ##
	//  ##     ##  ##  ###   ##   ## ##   ##     ##  ##  ##
	//  ##     ##  ##  ####  ##  ##   ##  ##     ##   ####
	//  ########   ##  ## ## ## ##     ## ########     ##
	//  ##     ##  ##  ##  #### ######### ##   ##      ##
	//  ##     ##  ##  ##   ### ##     ## ##    ##     ##
	//  ########  #### ##    ## ##     ## ##     ##    ##

	// Exclusive or (xor, addition modulo 2)
	bit_t operator^(bit_t& other);

	// Conjunction (and)
	bit_t operator&(bit_t& other);

	// Disjunction (or)
	bit_t operator|(bit_t& other);

	// Nand (negated and)
	friend bit_t nand(bit_t& left, bit_t& right);

	// Nor (negated or)
	friend bit_t nor(bit_t& left, bit_t& right);



	//     ###     ######   ######   ######   ##    ## ##     ## ##    ## ########
	//    ## ##   ##    ## ##    ## ##    ##  ###   ## ###   ### ###   ##    ##
	//   ##   ##  ##       ##       ##        ####  ## #### #### ####  ##    ##
	//  ##     ##  ######   ######  ##   #### ## ## ## ## ### ## ## ## ##    ##
	//  #########       ##       ## ##    ##  ##  #### ##     ## ##  ####    ##
	//  ##     ## ##    ## ##    ## ##    ##  ##   ### ##     ## ##   ###    ##
	//  ##     ##  ######   ######   ######   ##    ## ##     ## ##    ##    ##

	// Assignment
	bit_t& operator=(bit_t other);

	// Exclusive or assignment
	bit_t& operator^=(const bit_t& other);

	// Conjuction assignment
	bit_t& operator&=(const bit_t& other);

	// Disjunction assignment
	bit_t& operator|=(const bit_t& other);



	//   ######   #######  ##     ## ########  ########   ######  ##    ##
	//  ##    ## ##     ## ###   ### ##     ## ##     ## ##    ## ###   ##
	//  ##       ##     ## #### #### ##     ## ##     ## ##       ####  ##
	//  ##       ##     ## ## ### ## ########  ########   ######  ## ## ##
	//  ##       ##     ## ##     ## ##        ##   ##         ## ##  ####
	//  ##    ## ##     ## ##     ## ##        ##    ##  ##    ## ##   ###
	//   ######   #######  ##     ## ##        ##     ##  ######  ##    ##

	// Equality test
	bool operator==(bit_t& other);

	// Inequality test
	bool operator!=(bit_t& other);



	//  ########  ######## ##          ###    ######## ##    ##  ######
	//  ##     ## ##       ##         ## ##      ##    ###   ## ##    ##
	//  ##     ## ##       ##        ##   ##     ##    ####  ## ##
	//  ########  ######   ##       ##     ##    ##    ## ## ##  ######
	//  ##   ##   ##       ##       #########    ##    ##  ####       ##
	//  ##    ##  ##       ##       ##     ##    ##    ##   ### ##    ##
	//  ##     ## ######## ######## ##     ##    ##    ##    ##  ######

	// 'Less than' relation
	bool operator<(const bit_t& other);

	// 'Greater than' relation
	bool operator>(const bit_t& other);

	// 'Less than or equal to' relation
	bool operator<=(const bit_t& other);

	// 'Greater than or equal to' relation
	bool operator>=(const bit_t& other);



	//  #### ##    ## ######## ########  ########    ###     ######  ########
	//   ##  ###   ##    ##    ##     ## ##         ## ##   ##    ## ##
	//   ##  ####  ##    ##    ##     ## ##        ##   ##  ##       ##
	//   ##  ## ## ##    ##    ########  ######   ##     ## ##       ######
	//   ##  ##  ####    ##    ##   ##   ##       ######### ##       ##
	//   ##  ##   ###    ##    ##    ##  ##       ##     ## ##    ## ##
	//  #### ##    ##    ##    ##     ## ##       ##     ##  ######  ########

	// Returns binary representation of a bit
	std::string toBinaryString() const;

	// Inserts binary bit representation into ostream
	friend std::ostream& operator<<(std::ostream& os, const bit_t& bit);
};


#endif
