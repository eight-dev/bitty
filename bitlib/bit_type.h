/**
 * @file bit_type.h
 * @date October 9, 2014
 * @brief Contains definition of the `bit_t` class
 */

#ifndef bitty_bit_type_h
#define bitty_bit_type_h

#include <iostream>

/**
 * @brief Bit type, stores a boolean value
 *
 * @details This class stores single boolean value (can be either `true` or `false`) and provides means to perform routine operations over boolean values.
 *
 * @note Standart C++ boolean type is used as an underlying value type.
 *
 * Example usage:
 * @code
 *	// Initialise bit values
 *	bit_t bit1 = 1, bit2 = false, bit3(25);
 *	
 *	// Perform operations on bit values
 *	bit_t bit4 = (bit1 ^= (bit2 & bit3));
 *	
 *	// Output bit value
 *	std::cout << bit4 << " = " << bit1 << " ^ (" << bit2 << " & " << bit3 << ")" << endl;
 * @endcode
 */
class bit_t {
private:

	/**
	 * @brief Raw boolean value
	 *
	 * @warning This value should not be accessed by any external methods and members.
	 */
	bool value;
public:

	//   ######  ##    ##  ######  ######## ########   ######
	//  ##    ## ###   ## ##    ##    ##    ##     ## ##    ##
	//  ##       ####  ## ##          ##    ##     ## ##
	//  ##       ## ## ##  ######     ##    ########   ######
	//  ##       ##  ####       ##    ##    ##   ##         ##
	//  ##    ## ##   ### ##    ##    ##    ##    ##  ##    ##
	//   ######  ##    ##  ######     ##    ##     ##  ######

	/**
	 * @brief Default empty bit_t constructor
	 *
	 * @details Empty constructor, initialises bit with the default false = 0 value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with default (false) value
	 *	bit_t someBit;
	 * @endcode
	 */
	bit_t();

	/**
	 * @brief Boolean bit_t constructor
	 *
	 * @details Constructs bit from `bool` value.
	 *
	 * @param [in] value Boolean value to initialize bit with.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with specified value
	 *	bit_t someBit(true);
	 * @endcode
	 */
	bit_t(bool value);

	/**
	 * @brief Integer bit_t constructor
	 *
	 * @details Constructs bit from `int` value. The bit is considered set when
	 *	@p value is positive (@p value > 0), and reset otherwise.
	 *
	 * @param [in] value Integer value to initialize bit with.
	 *
	 * Example usage:
	 * @code
	 *	// Set someBit [to true]
	 *	bit_t someBit(25);
	 *	
	 *	// Reset someOtherBit [to false]
	 *	bit_t someOtherBit(0);
	 * @endcode
	 */
	bit_t(int value);



	//   ######     ###     ######  ########
	//  ##    ##   ## ##   ##    ##    ##
	//  ##        ##   ##  ##          ##
	//  ##       ##     ##  ######     ##
	//  ##       #########       ##    ##
	//  ##    ## ##     ## ##    ##    ##
	//   ######  ##     ##  ######     ##

	/**
	 * @brief Casts `bit_t` to `bool`.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise and set someBit
	 *	bit_t someBit(true);
	 *	
	 *	// Initialise some boolean value
	 *	bool someBool = false;
	 *	
	 *	// Implicitly cast bit_t to bool
	 *	someBool = someBit;
	 * @endcode
	 */
	operator bool();

	/**
	 * @brief Casts `bit_t` to `int`
	 *
	 * @details Result integer equals 1 if bit is set and 0 otherwise.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit and someOtherBit with default values
	 *	bit_t someBit(25), someOtherBit(0);
	 *
	 *	// Initialise some integer values
	 *	int someInteger = 0, someOtherInteger = 0;
	 *
	 *	// Implicitly cast bit_t to int
	 *	someInteger = someBit;
	 *	someOtherInteger = someOtherBit;
	 * @endcode
	 */
	operator int();

	/**
	 * @brief Casts `bit_t` to `size_t`
	 *
	 * @details Result integer equals 1 if bit is set and 0 otherwise.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit and someOtherBit with default values
	 *	bit_t someBit(25), someOtherBit(0);
	 *
	 *	// Initialise some integer size_t values
	 *	size_t someInteger = 0, someOtherInteger = 0;
	 *
	 *	// Implicitly cast bit_t to size_t
	 *	someInteger = someBit;
	 *	someOtherInteger = someOtherBit;
	 * @endcode
	 */
	operator size_t();



	//  ##        #######   ######   ####  ######
	//  ##       ##     ## ##    ##   ##  ##    ##
	//  ##       ##     ## ##         ##  ##
	//  ##       ##     ## ##   ####  ##  ##
	//  ##       ##     ## ##    ##   ##  ##
	//  ##       ##     ## ##    ##   ##  ##    ##
	//  ########  #######   ######   ####  ######

	/**
	 * @brief Sets bit to `true` value
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with default value
	 *	bit_t someBit;
	 *
	 *	// Set someBit
	 *	someBit.set();
	 * @endcode
	 */
	void set();

	/**
	 * @brief Resets bit to `false` value
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with true value
	 *	bit_t someBit(true);
	 *
	 *	// Set someBit
	 *	someBit.reset();
	 * @endcode
	 */
	void reset();

	/**
	 * @brief Inverts bit value
	 * 
	 * @details Resets the bit if it is set, and sets the bit otherwise.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with true value
	 *	bit_t someBit(true);
	 *
	 *	// Set someBit
	 *	someBit.invert();
	 * @endcode
	 */
	void invert();



	//  ##     ## ##    ##    ###    ########  ##    ##
	//  ##     ## ###   ##   ## ##   ##     ##  ##  ##
	//  ##     ## ####  ##  ##   ##  ##     ##   ####
	//  ##     ## ## ## ## ##     ## ########     ##
	//  ##     ## ##  #### ######### ##   ##      ##
	//  ##     ## ##   ### ##     ## ##    ##     ##
	//   #######  ##    ## ##     ## ##     ##    ##

	/**
	 * @brief Calculates inverted bit value
	 *
	 * @details Does not modify `*this` bit.
	 *
	 * @return Inverted bit_t value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with true value
	 *	bit_t someBit(true), someOtherBit();
	 *
	 *	// Set someBit
	 *	someOtherBeat = !someBit;
	 * @endcode
	 *
	 * @see operator~()
	 */
	bit_t operator!() const;

	/**
	 * @brief Calculates inverted bit value
	 *
	 * @details Does not modify `*this` bit.
	 *
	 * @return Inverted bit_t value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t someBit(true), someOtherBit();
	 *
	 *	// Set someBit
	 *	someOtherBit = !someBit;
	 * @endcode
	 * 
	 * @see operator!()
	 */
	bit_t operator~() const;

	/**
	 * @brief Increments bit
	 *
	 * @details Inverts bit value.
	 *
	 * @return Inverted bit_t value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with true value
	 *	bit_t someBit(true);
	 *
	 *	// Increment someBit
	 *	++someBit;
	 * @endcode
	 *
	 * @see invert()
	 */
	bit_t& operator++();

	/**
	 * @brief Decrements bit
	 *
	 * @details Inverts bit value.
	 *
	 * @return Inverted bit_t value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with true value
	 *	bit_t someBit(true);
	 *
	 *	// Decrement someBit
	 *	--someBit;
	 * @endcode
	 *
	 * @see invert()
	 */
	bit_t& operator--();

	/**
	 * @brief Increments bit
	 *
	 * @details Inverts bit value.
	 *
	 * @return Inverted bit_t value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with true value
	 *	bit_t someBit(true);
	 *
	 *	// Increment someBit
	 *	someBit++;
	 * @endcode
	 *
	 * @see invert()
	 */
	bit_t& operator++(int);

	/**
	 * @brief Decrements bit
	 *
	 * @details Inverts bit value.
	 *
	 * @return Inverted bit_t value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with true value
	 *	bit_t someBit(true);
	 *
	 *	// Decrement someBit
	 *	someBit--;
	 * @endcode
	 *
	 * @see invert()
	 */
	bit_t& operator--(int);



	//  ########  #### ##    ##    ###    ########  ##    ##
	//  ##     ##  ##  ###   ##   ## ##   ##     ##  ##  ##
	//  ##     ##  ##  ####  ##  ##   ##  ##     ##   ####
	//  ########   ##  ## ## ## ##     ## ########     ##
	//  ##     ##  ##  ##  #### ######### ##   ##      ##
	//  ##     ##  ##  ##   ### ##     ## ##    ##     ##
	//  ########  #### ##    ## ##     ## ##     ##    ##

	/**
	 * @brief Exclusive OR operator
	 *
	 * @details Overloaded bitwise exclusive OR (XOR, \f$ \oplus \f$) operator, sometimes
	 *	considered equal to addition modulo 2, has the following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1\oplus x_2\f$ |
	 *	|:---------:|:---------:|:---------------------:|
	 *	|0          |0          |0                      |
	 *	|0          |1          |1                      |
	 *	|1          |0          |1                      |
	 *	|1          |1          |0                      |
	 *	XOR can be expressed in terms of NOT (\f$\neg\f$), OR (\f$\vee\f$) and
	 *	AND (\f$\wedge\f$) as follows:
	 *	\f$ f = x_1 \oplus x_2 = (x_1 \vee x_2) \wedge \neg(x_1 \wedge x_2) \f$.
	 *
	 * @param [in] other Second `bit_t` operand \f$x_2\f$.
	 *
	 * @note \f$x_1\f$ is passed via `*this`.
	 *
	 * @return `bit_t` value \f$ x_3 = f(x_1, x_2) \f$
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true), x3;
	 *	
	 *	// Calculate x3 = xor(x1, x2)
	 *	x3 = x1 ^ x2;
	 * @endcode
	 */
	bit_t operator^(const bit_t& other) const;

	/**
	 * @brief Conjunction operator
	 *
	 * @details Overloaded bitwise conjunction (AND, \f$\&\f$, \f$\wedge\f$) operator, 
	 *	only returns `true` when both operands are `true`, and `false` otherwise; has the
	 *	following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1\wedge x_2\f$ |
	 *	|:---------:|:---------:|:---------------------:|
	 *	|0          |0          |0                      |
	 *	|0          |1          |0                      |
	 *	|1          |0          |0                      |
	 *	|1          |1          |1                      |
	 *
	 * @param [in] other Second `bit_t` operand \f$x_2\f$.
	 *
	 * @note \f$x_1\f$ is passed via `*this`.
	 *
	 * @return `bit_t` value \f$ x_3 = f(x_1, x_2) \f$
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true), x3;
	 *
	 *	// Calculate x3 = and(x1, x2)
	 *	x3 = x1 & x2;
	 * @endcode
	 */
	bit_t operator&(const bit_t& other) const;

	/**
	 * @brief Disjunction operator
	 *
	 * @details Overloaded bitwise disjunction (OR, \f$\vert\f$, \f$\vee\f$) operator, only returns
	 *	`false` when both operands are `false`, and `true` otherwise; has the
	 *	following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1 \vee x_2\f$  |
	 *	|:---------:|:---------:|:---------------------:|
	 *	|0          |0          |0                      |
	 *	|0          |1          |1                      |
	 *	|1          |0          |1                      |
	 *	|1          |1          |1                      |
	 *
	 * @param [in] other Second `bit_t` operand \f$x_2\f$.
	 *
	 * @note \f$x_1\f$ is passed via `*this`.
	 *
	 * @return `bit_t` value \f$ x_3 = f(x_1, x_2) \f$
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true), x3;
	 *
	 *	// Calculate x3 = or(x1, x2)
	 *	x3 = x1 | x2;
	 * @endcode
	 */
	bit_t operator|(const bit_t& other) const;

	/**
	 * @brief Negated conjuction operator
	 *
	 * @details Bitwise negated AND (NAND) operator, only returns
	 *	`false` when both operands are `true`, and `true` otherwise; has the
	 *	following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=\neg(x_1\wedge x_2)\f$ |
	 *	|:---------:|:---------:|:---------------------------:|
	 *	|0          |0          |1                            |
	 *	|0          |1          |1                            |
	 *	|1          |0          |1                            |
	 *	|1          |1          |0                            |
	 *
	 * @param [in] left First `bit_t` operand \f$x_1\f$.
	 * @param [in] right Second `bit_t` operand \f$x_2\f$.
	 *
	 * @return `bit_t` value \f$ x_3 = f(x_1, x_2) \f$
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true), x3;
	 *
	 *	// Calculate x3 = nand(x1, x2)
	 *	x3 = nand(x1, x2);
	 * @endcode
	 */
	friend bit_t nand(const bit_t& left, const bit_t& right);

	/**
	 * @brief Negated disjuction operator
	 *
	 * @details Bitwise negated OR (NOR) operator, only returns
	 *	`true` when both operands are `false`, and `false` otherwise; has the
	 *	following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=\neg(x_1\wedge x_2)\f$ |
	 *	|:---------:|:---------:|:---------------------------:|
	 *	|0          |0          |1                            |
	 *	|0          |1          |0                            |
	 *	|1          |0          |0                            |
	 *	|1          |1          |0                            |
	 *
	 * @param [in] left First `bit_t` operand \f$x_1\f$.
	 * @param [in] right Second `bit_t` operand \f$x_2\f$.
	 *
	 * @return `bit_t` value \f$ x_3 = f(x_1, x_2) \f$
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true), x3;
	 *
	 *	// Calculate x3 = nor(x1, x2)
	 *	x3 = nor(x1, x2);
	 * @endcode
	 */
	friend bit_t nor(const bit_t& left, const bit_t& right);



	//     ###     ######   ######   ######   ##    ## ##     ## ##    ## ########
	//    ## ##   ##    ## ##    ## ##    ##  ###   ## ###   ### ###   ##    ##
	//   ##   ##  ##       ##       ##        ####  ## #### #### ####  ##    ##
	//  ##     ##  ######   ######  ##   #### ## ## ## ## ### ## ## ## ##    ##
	//  #########       ##       ## ##    ##  ##  #### ##     ## ##  ####    ##
	//  ##     ## ##    ## ##    ## ##    ##  ##   ### ##     ## ##   ###    ##
	//  ##     ##  ######   ######   ######   ##    ## ##     ## ##    ##    ##

	/**
	 * @brief Assignment operator
	 *
	 * @details Bitwise unary assignment operator, assigns @p other operand
	 *	value to `*this`.
	 *
	 * @param [in] other The right `bit_t` part of the assignment.
	 *
	 * @return Modified `*this` `bit_t` value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true);
	 *
	 *	// Assign x2 bit value to x1 bit
	 *	x1 = x2;
	 * @endcode
	 */
	bit_t& operator=(const bit_t other);

	/**
	 * @brief Exclusive OR compound assignment operator
	 *
	 * @details Bitwise unary exclusive OR (XOR, \f$\oplus\f$) compound assignment operator, 
	 * assigns @p other operand value xored by current `*this` value to `*this`, as follows:
	 * \f[
	 *	x = x \oplus other.
	 * \f]
	 *
	 * @param [in] other The right `bit_t` part of the assignment.
	 *
	 * @return Modified `*this` `bit_t` value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true);
	 *
	 *	// Xor x1 by x2, then assign result bit value to x1
	 *	x1 ^= x2;
	 * @endcode
	 */
	bit_t& operator^=(const bit_t& other);

	/**
	 * @brief Conjunction compound assignment operator
	 *
	 * @details Bitwise unary conjunction (AND, \f$\wedge\f$, \f$\&\f$) compound assignment operator,
	 * assigns @p other operand value conjucted by current `*this` value to `*this`, as follows:
	 * \f[
	 *	x = x \wedge other.
	 * \f]
	 *
	 * @param [in] other The right `bit_t` part of the assignment.
	 *
	 * @return Modified `*this` `bit_t` value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true);
	 *
	 *	// Assign x1 && x2 conjuction value to x1
	 *	x1 &= x2;
	 * @endcode
	 */
	bit_t& operator&=(const bit_t& other);

	/**
	 * @brief Disjunction compound assignment operator
	 *
	 * @details Bitwise unary disjunction (OR, \f$\vee\f$, \f$\vert\f$) compound assignment operator,
	 * assigns @p other operand value disjucted by current `*this` value to `*this`, as follows:
	 * \f[
	 *	x = x \vee other.
	 * \f]
	 *
	 * @param [in] other The right `bit_t` part of the assignment.
	 *
	 * @return Modified `*this` `bit_t` value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true);
	 *
	 *	// Assign x1 || x2 conjuction value to x1
	 *	x1 |= x2;
	 * @endcode
	 */
	bit_t& operator|=(const bit_t& other);



	//   ######   #######  ##     ## ########  ########   ######  ##    ##
	//  ##    ## ##     ## ###   ### ##     ## ##     ## ##    ## ###   ##
	//  ##       ##     ## #### #### ##     ## ##     ## ##       ####  ##
	//  ##       ##     ## ## ### ## ########  ########   ######  ## ## ##
	//  ##       ##     ## ##     ## ##        ##   ##         ## ##  ####
	//  ##    ## ##     ## ##     ## ##        ##    ##  ##    ## ##   ###
	//   ######   #######  ##     ## ##        ##     ##  ######  ##    ##

	/**
	 * @brief Equality test operator
	 *
	 * @details Test whether the `bit_t` instances are equal
	 *
	 * @param [in] other The right `bit_t` part of the comparison.
	 * 
	 * @retval true `*this` and @p other bits are equal
	 * @retval false `*this` and @p other bits are not equal
	 *
	 * @note \f$x_1\f$ is passed via `*this`.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true), x3;
	 *
	 *	// Test if x1 and x2 are equal
	 *	x3 = (x1 == x2);
	 * @endcode
	 */
	bool operator==(const bit_t& other) const;

	/**
	 * @brief Inequality test operator
	 *
	 * @details Test whether the `bit_t` instances are not equal
	 *
	 * @param [in] other The right `bit_t` part of the comparison.
	 *
	 * @retval true `*this` and @p other bits are not equal
	 * @retval false `*this` and @p other bits are equal
	 *
	 * @note \f$x_1\f$ is passed via `*this`.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t x1(false), x2(true), x3;
	 *
	 *	// Test if x1 and x2 are not equal
	 *	x3 = (x1 != x2);
	 * @endcode
	 */
	bool operator!=(const bit_t& other) const;



	//  ########  ######## ##          ###    ######## ##    ##  ######
	//  ##     ## ##       ##         ## ##      ##    ###   ## ##    ##
	//  ##     ## ##       ##        ##   ##     ##    ####  ## ##
	//  ########  ######   ##       ##     ##    ##    ## ## ##  ######
	//  ##   ##   ##       ##       #########    ##    ##  ####       ##
	//  ##    ##  ##       ##       ##     ##    ##    ##   ### ##    ##
	//  ##     ## ######## ######## ##     ##    ##    ##    ##  ######

	/**
	 * @brief Less than relation operator
	 *
	 * @details Bitwise overloaded relation less than (\f$<\f$) operator, only returns
	 *	`true` when first operand is `false` and second is `true`, and `false` otherwise; has the
	 *	following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1 < x_2\f$ |
	 *	|:---------:|:---------:|:-----------------:|
	 *	|0          |0          |0                  |
	 *	|0          |1          |1                  |
	 *	|1          |0          |0                  |
	 *	|1          |1          |0                  |
	 *
	 * @param [in] other Second `bit_t` operand \f$x_2\f$.
	 *
	 * @return `bit_t` value \f$ x_3 = f(x_1, x_2) \f$
	 *
	 * @note \f$x_1\f$ is passed via `*this`.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t and boolean values
	 *	bit_t x1(false), x2(true);
	 *	bool value = false;
	 *
	 *	// Calculate value = x1 < x2
	 *	value = x1 < x2;
	 * @endcode
	 */
	bool operator<(const bit_t& other) const;

	/**
	 * @brief Greater than relation operator
	 *
	 * @details Bitwise overloaded relation greater than (\f$>\f$) operator, only returns
	 *	`true` when first operand is `true` and second is `false`, and `false` otherwise; has the
	 *	following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1 < x_2\f$ |
	 *	|:---------:|:---------:|:-----------------:|
	 *	|0          |0          |0                  |
	 *	|0          |1          |0                  |
	 *	|1          |0          |1                  |
	 *	|1          |1          |0                  |
	 *
	 * @param [in] other Second `bit_t` operand \f$x_2\f$.
	 *
	 * @return `bit_t` value \f$ x_3 = f(x_1, x_2) \f$
	 *
	 * @note \f$x_1\f$ is passed via `*this`.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t and boolean values
	 *	bit_t x1(false), x2(true);
	 *	bool value = false;
	 *
	 *	// Calculate value = x1 > x2
	 *	value = x1 > x2;
	 * @endcode
	 */
	bool operator>(const bit_t& other) const;

	/**
	 * @brief Less or equal to relation operator
	 *
	 * @details Bitwise overloaded relation less or equal to (\f$\leq\f$) operator, only returns
	 *	`false` when first operand is `true` and second is `false`, and `true` otherwise; has the
	 *	following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1 \leq x_2\f$ |
	 *	|:---------:|:---------:|:--------------------:|
	 *	|0          |0          |1                     |
	 *	|0          |1          |1                     |
	 *	|1          |0          |0                     |
	 *	|1          |1          |1                     |
	 *
	 * @param [in] other Second `bit_t` operand \f$x_2\f$.
	 *
	 * @return `bit_t` value \f$ x_3 = f(x_1, x_2) \f$
	 *
	 * @note \f$x_1\f$ is passed via `*this`.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t and boolean values
	 *	bit_t x1(false), x2(true);
	 *	bool value = false;
	 *
	 *	// Calculate value = x1 <= x2
	 *	value = x1 <= x2;
	 * @endcode
	 */
	bool operator<=(const bit_t& other) const;

	/**
	 * @brief Greater or equal to relation operator
	 *
	 * @details Bitwise overloaded relation greater or equal to (\f$\geq\f$) operator, only returns
	 *	`false` when first operand is `false` and second is `true`, and `true` otherwise; has the
	 *	following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1 \geq x_2\f$ |
	 *	|:---------:|:---------:|:--------------------:|
	 *	|0          |0          |1                     |
	 *	|0          |1          |0                     |
	 *	|1          |0          |1                     |
	 *	|1          |1          |1                     |
	 *
	 * @param [in] other Second `bit_t` operand \f$x_2\f$.
	 *
	 * @return `bit_t` value \f$ x_3 = f(x_1, x_2) \f$
	 *
	 * @note \f$x_1\f$ is passed via `*this`.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t and boolean values
	 *	bit_t x1(false), x2(true);
	 *	bool value = false;
	 *
	 *	// Calculate value = x1 >= x2
	 *	value = x1 >= x2;
	 * @endcode
	 */
	bool operator>=(const bit_t& other) const;



	//  #### ##    ## ######## ########  ########    ###     ######  ########
	//   ##  ###   ##    ##    ##     ## ##         ## ##   ##    ## ##
	//   ##  ####  ##    ##    ##     ## ##        ##   ##  ##       ##
	//   ##  ## ## ##    ##    ########  ######   ##     ## ##       ######
	//   ##  ##  ####    ##    ##   ##   ##       ######### ##       ##
	//   ##  ##   ###    ##    ##    ##  ##       ##     ## ##    ## ##
	//  #### ##    ##    ##    ##     ## ##       ##     ##  ######  ########

	/**
	 * @brief Returns string with bit binary representation
	 *
	 * @retval "1" if `*this` bit is set
	 * @retval "0" if `*this` bit is reset
	 *
	 * @note Method does not modify `*this` value, upon which it was invoked.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bit_t values
	 *	bit_t someBit(false), someOtherBit(true);
	 *	
	 *	// Insert bits in the console output stream
	 *	std::cout << someBit << " " << someOtherBit << endl;
	 * @endcode
	 */
	std::string toBinaryString() const;

	/**
	 * @brief Inserts @p bit binary representation into @p os
	 *
	 * @details Insertion is performed with toBinaryString() method.
	 *
	 * @param [in,out] os An `std::ostream` which method is invoked upon.
	 * @param [in] bit Bit to be inserted.
	 *
	 * @return Modified `std::ostream` stream.
	 *
	 * @note Uses overloaded for `std::string` stream insertion operator.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a couple of bit_t values
	 *	bit_t someBit(true), someOtherBit(false);
	 *	
	 *	// Insert them in default console output stream
	 *	std::cout << someBit << " " << someOtherBit << endl;
	 * @endcode
	 *
	 * @see toBinaryString()
	 */
	friend std::ostream& operator<<(std::ostream& os, const bit_t& bit);
};


#endif
