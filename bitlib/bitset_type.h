/**
 * @file bitset_type.h
 * @date October 12, 2014
 * @brief Contains definition of the `bitset_t` class
 */

#ifndef bitlib___bitset_type_h
#define bitlib___bitset_type_h

#include <vector>
#include "bit_type.h"

/**
 * @brief Bitset type, stores a set of `bit_t` values
 *
 * @details This class stores a set of boolean (`bit_t`) values of dynamic length and provides means to perform most routine operations over bitsets.
 *
 * @note `std::vector<bit_t>` type is used as an underlying bitset value type.
 * @note Bitset class implements those operations which <b>do not depend</b> on the endianess of the bitset. For example, increment/decrement operators are not overloaded since their implementation depends on the position of the least significant bit in the bitset.
 *
 * Example usage:
 * @code
 *	// Initialize bitset
 *	bitset_t bitset1({0,1,1,0,1,0,1,1});
 *	
 *	// Initialize second bitset as a complement to the first one
 *	bitset_t bitset2 = !bitset1;
 *
 *	// Rotate first bitset left by two and shift second right by three
 *	bitset1.rotateLeft(2);
 *	bitset2.shiftRight(3);
 *
 *	// Calculate Hamming distance between bitsets
 *	size_t dist = hammingDistance(bitset1, bitset2);
 *
 *	// Calculate the scalar product of these bitsets
 *	bit_t prod = bitset1 * bitset2;
 *
 *	// Output bitsets in console, bit by bit
 *	std::cout << "<" << bitset1 << ", " << bitset2 << "> = " << prod << endl;
 * @endcode
 */
class bitset_t {
private:
	/**
	 * @brief Raw `std::vector<bit_t>` array
	 *
	 * @warning This value should not be accessed by any external methods and members.
	 */
	std::vector<bit_t> set;
public:

	//   ######  ##    ##  ######  ######## ########   ######
	//  ##    ## ###   ## ##    ##    ##    ##     ## ##    ##
	//  ##       ####  ## ##          ##    ##     ## ##
	//  ##       ## ## ##  ######     ##    ########   ######
	//  ##       ##  ####       ##    ##    ##   ##         ##
	//  ##    ## ##   ### ##    ##    ##    ##    ##  ##    ##
	//   ######  ##    ##  ######     ##    ##     ##  ######

	/**
	 * @brief Default empty `bitset_t` constructor
	 *
	 * @details Empty constructor, initialises empty bitset (bitset with zero size and no elements).
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBitset
	 *	bitset_t someBitset;
	 * @endcode
	 */
	bitset_t();

	/**
	 * @brief `bit_t` initializer list bitset_t constructor
	 *
	 * @details Constructs bitset from the list of `bit_t` values.
	 *
	 * @param [in] bits List of bits to initialize bitset with.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with specified bits
	 *	bitset_t someBitset({0, 1, 1, 0, 1, 1, 0, 1});
	 * @endcode
	 */
	bitset_t(const std::initializer_list<bit_t> bits);

	/**
	 * @brief `bool` initializer list bitset_t constructor
	 *
	 * @details Constructs bitset from the list of `bool` values.
	 *
	 * @param [in] bits List of boolean values to initialize bitset with.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise someBit with specified bits
	 *	bitset_t someBitset({false, true, true, false});
	 * @endcode
	 */
	bitset_t(const std::initializer_list<bool> bits);

	/**
	 * @brief `std::vector<bit_t>` bitset_t constructor
	 *
	 * @details Constructs bitset from the `std::vector<bit_t>`.
	 *
	 * @param [in] bits 'std::vector' of bits to initialize bitset with.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise vector of bit_t values
	 *	auto someVector = std::vector<bit_t>({0, 1, 1, 0, 1, 1, 0, 1});
	 *
	 *	// Initialise someBit with vector
	 *	bitset_t someBitset(someVector);
	 * @endcode
	 */
	bitset_t(const std::vector<bit_t>& bits);

	/**
	 * @brief `std::vector<bool>` bitset_t constructor
	 *
	 * @details Constructs bitset from the `std::vector<bool>`.
	 *
	 * @param [in] bits 'std::vector' of boolean values to initialize bitset with.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise vector of bit_t values
	 *	auto someVector = std::vector<bool>({true, false, false, true});
	 *
	 *	// Initialise someBit with vector
	 *	bitset_t someBitset(someVector);
	 * @endcode
	 */
	bitset_t(const std::vector<bool>& bits);

	/**
	 * @brief Boolean array bitset_t constructor
	 *
	 * @details Constructs bitset from the C-array of boolean values.
	 *
	 * @param [in] head Pointer to the first `bool` value in the array.
	 * @param [in] length The number of the values in the array.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise C-array of boolean values
	 *	auto carray = bool[4] {true, false, true, true};
	 *
	 *	// Initialise someBit with C-array
	 *	bitset_t someBitset(4, carray);
	 * @endcode
	 */
	bitset_t(const bool* head, const size_t length);

	/**
	 * @brief Copy bitset_t constructor
	 *
	 * @details Constructs `bitset_t` from another `bitset_t`.
	 *
	 * @param [in] bits `bitset_t` value to initialize bitset with.
	 *
	 * Example usage:
	 * @code
	 *	// Initiailize bit_t value
	 *	bitset_t someBitset({0, 1, 1, 0, 1, 1, 0, 1});
	 *
	 *	// Construct a copy
	 *	bitset_t someOtherBitset(someBitset);
	 * @endcode
	 */
	bitset_t(const bitset_t& bits);



	//   ######     ###     ######  ########
	//  ##    ##   ## ##   ##    ##    ##
	//  ##        ##   ##  ##          ##
	//  ##       ##     ##  ######     ##
	//  ##       #########       ##    ##
	//  ##    ## ##     ## ##    ##    ##
	//   ######  ##     ##  ######     ##

	/**
	 * @brief Casts `bitset_t` to `std::vector<bit_t>`.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise and set someBitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Initialise some vector
	 *	auto someVector = std::vector<bit_t>(0);
	 *
	 *	// Implicitly cast bitset_t to std::vector<bit_t>
	 *	someVector = someBitset;
	 * @endcode
	 */
	operator std::vector<bit_t>();



	//  #### ######## ######## ########  ######## ##    ##  ######
	//   ##     ##    ##       ##     ##    ##    ###   ## ##    ##
	//   ##     ##    ##       ##     ##    ##    ####  ## ##
	//   ##     ##    ######   ########     ##    ## ## ## ##   ####
	//   ##     ##    ##       ##   ##      ##    ##  #### ##    ##
	//   ##     ##    ##       ##    ##     ##    ##   ### ##    ##
	//  ####    ##    ######## ##     ##    ##    ##    ##  ######

	/**
	 * @brief Returns iterator to beginning
	 *
	 * @details Returns an [random access] iterator pointing to the first element in the bitset.
	 *
	 * @return An iterator to the beginning of the bitset.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Get the iterator to the beginning of the bitset
	 *	std::vector<bit_t>::iterator end = someBitset.end();
	 *
	 *	// First way of cycling through all bits in the bitset
	 *	for (auto bit : someBitset) {
	 *		...
	 *	}
	 *
	 *	// Second way of cycling through all bits in the bitset
	 *	for (auto bit = someBitset.begin(); bit != someBitset.end(); bit++) {
	 *		...
	 *	}
	 * @endcode
	 */
	std::vector<bit_t>::iterator begin();

	/**
	 * @brief Returns (`const`) iterator to beginning
	 *
	 * @details Returns an (`const`) [random access] iterator pointing to the first element in the bitset.
	 *
	 * @return An iterator to the beginning of the bitset.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Get the iterator to the beginning of the bitset
	 *	std::vector<bit_t>::iterator end = someBitset.end();
	 *
	 *	// First way of cycling through all bits in the bitset
	 *	for (auto bit : someBitset) {
	 *		...
	 *	}
	 *
	 *	// Second way of cycling through all bits in the bitset
	 *	for (auto bit = someBitset.begin(); bit != someBitset.end(); bit++) {
	 *		...
	 *	}
	 * @endcode
	 */
	std::vector<bit_t>::const_iterator begin() const;

	/**
	 * @brief Returns iterator to end
	 *
	 * @details Returns an iterator referring to the past-the-end element in the bitset. The past-the-end element is the theoretical element that would follow the last element in the vector. It <b>does not point to any element</b>, and thus shall not be dereferenced.
	 *
	 * @return An iterator to the element past the end of the bitset.
	 *
	 * @note If the bitset is empty, this method returns the same as begin().
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Get the iterator to the end of the bitset
	 *	std::vector<bit_t>::iterator end = someBitset.end();
	 *
	 *	// First way of cycling through all bits in the bitset
	 *	for (auto bit : someBitset) {
	 *		...
	 *	}
	 *
	 *	// Second way of cycling through all bits in the bitset
	 *	for (auto bit = someBitset.begin(); bit != someBitset.end(); bit++) {
	 *		...
	 *	}
	 * @endcode
	 */
	std::vector<bit_t>::iterator end();

	/**
	 * @brief Returns (`const`) iterator to end
	 *
	 * @details Returns an iterator referring to the past-the-end element in the bitset. The past-the-end element is the theoretical element that would follow the last element in the vector. It <b>does not point to any element</b>, and thus shall not be dereferenced.
	 *
	 * @return An (`const`) iterator to the element past the end of the bitset.
	 *
	 * @note If the bitset is empty, this method returns the same as begin().
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Get the iterator to the end of the bitset
	 *	std::vector<bit_t>::iterator end = someBitset.end();
	 *
	 *	// First way of cycling through all bits in the bitset
	 *	for (auto bit : someBitset) {
	 *		...
	 *	}
	 *
	 *	// Second way of cycling through all bits in the bitset
	 *	for (auto bit = someBitset.begin(); bit != someBitset.end(); bit++) {
	 *		...
	 *	}
	 * @endcode
	 */
	std::vector<bit_t>::const_iterator end() const;

	/**
	 * @brief Returns length of the bitset
	 *
	 * @details Returns total number of bits stored in the bitset.
	 *
	 * @return `size_t` number of bits stored in the bitset.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Get the bitset length
	 *	size_t length = someBitset.length();
	 * @endcode
	 */
	size_t length() const;

	/**
	 * @brief Returns length of the bitset
	 *
	 * @details Returns total number of bits stored in the bitset.
	 *
	 * @return `size_t` number of bits stored in the bitset.
	 *
	 * @note This method is equal to length() and is implemented in order to achieve compability with C++11 containers.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Get the bitset length
	 *	size_t length = someBitset.size();
	 * @endcode
	 */
	size_t size() const {
		return length();
	}

	/**
	 * @brief Resizes the container to contain @p length elements
	 *
	 * @details If the current size is greater than count, the container is reduced to its first @p length elements. If the current size is less than @p length, additional zero-initialized bits are appended.
	 *
	 * @param [in] length New size of the container.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Resize a bitset
	 *	someBitset.resize(5);
	 * @endcode
	 */
	void resize(const size_t length);

	/**
	 * @brief Resizes the container to contain @p length elements
	 *
	 * @details If the current size is greater than count, the container is reduced to its first @p length elements. If the current size is less than @p length, additional copies of @p value are appended.
	 *
	 * @param [in] length New size of the container.
	 * @param [in] value The value to initialize the new elements with.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Resize a bitset
	 *	someBitset.resize(5, (bit_t)true);
	 * @endcode
	 */
	void resize(const size_t length, const bit_t& value);



	//  ##        #######   ######   ####  ######
	//  ##       ##     ## ##    ##   ##  ##    ##
	//  ##       ##     ## ##         ##  ##
	//  ##       ##     ## ##   ####  ##  ##
	//  ##       ##     ## ##    ##   ##  ##
	//  ##       ##     ## ##    ##   ##  ##    ##
	//  ########  #######   ######   ####  ######

	/**
	 * @brief Sets [to `true`] all bits in the bitset
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Set all bits in the bitset
	 *	someBitset.setAll();
	 * @endcode
	 */
	void setAll();

	/**
	 * @brief Resets [to `false`] all bits in the bitset
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Reset all bits in the bitset
	 *	someBitset.resetAll();
	 * @endcode
	 */
	void resetAll();

	/**
	 * @brief Assigns @p value to all bits in the bitset
	 *
	 * @param [in] value The value to initialize the elements of the bitset with.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Reset all bits in the bitset
	 *	someBitset.fillWith((bit_t)false);
	 * @endcode
	 */
	void fillWith(const bit_t value);

	/**
	 * @brief Inverts [complements] all bits in the bitset
	 *
	 * Example usage:
	 * @code
	 *	// Initialise a bitset
	 *	bitset_t someBitset({0, 1, 1, 0});
	 *
	 *	// Invert all bits in the bitset
	 *	someBitset.invert();
	 * @endcode
	 */
	void invert();

	/**
	 * @brief Returns the number of bits at which @p left and @p right bitset are different
	 *
	 * @details In information theory, the Hamming distance between two bitsets of equal length is the number of positions at which the corresponding bits are different. In another way, it measures the minimum number of substitutions required to change @p left bitset into the @p right, or the minimum number of errors that could have transformed @p left bitset into the @p right one.
	 *
	 * @param left The first [left] bitset.
	 * @param right The second [right] bitset.
	 *
	 * @return The number of bits at which @p left and @p right bitset are different.
	 *
	 * @warning @p left and @p right bitsets <b>must be of equal length</b>.
	 *
	 * @note Two different solutions to implement this method were found: first one used a temporary bitset, each bit of which stored a sum of corresponding bits of @p left and @p rigth bitsets, and then used `std::accumulate` method to calculate total number of non-zero bits in this temporary bitset. The second way suggested using `std::inner_product` method with custom operators: it uses `std::plus<size_t>` as an accumulative operator and @ref bitwise_nequal() as binary product operator. Second approach showed much better performance over long bitsets.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise two bitsets of equal length
	 *	bitset_t firstBitset({0, 1, 1, 0}), secondBitset({1, 1, 1, 0});
	 *
	 *	// Calculate the Hamming distance between the bitsets
	 *	size_t distance = hammingDistance(firstBitset, secondBitset);
	 * @endcode
	 */
	friend size_t hammingDistance(const bitset_t left, const bitset_t right);



	//   ######  ##     ## #### ######## ######## #### ##    ##  ######
	//  ##    ## ##     ##  ##  ##          ##     ##  ###   ## ##    ##
	//  ##       ##     ##  ##  ##          ##     ##  ####  ## ##
	//   ######  #########  ##  ######      ##     ##  ## ## ## ##   ####
	//        ## ##     ##  ##  ##          ##     ##  ##  #### ##    ##
	//  ##    ## ##     ##  ##  ##          ##     ##  ##   ### ##    ##
	//   ######  ##     ## #### ##          ##    #### ##    ##  ######

	/**
	 * @brief Rotates left the bits in the bitset
	 *
	 * @details Rotates the order of the bits in the bitset, in such a way that the bit pointed by @ref begin() ` + ` @p shift becomes the new first element.
	 *
	 * @param shift Position of the bit that is moved to the first position in the bitset.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise the bitset
	 *	bitset_t bitset({0, 1, 1, 0});
	 *
	 *	// Rotate left by two
	 *	bitset.rotateLeft(2);
	 * @endcode
	 */
	void rotateLeft(const size_t shift);

	/**
	 * @brief Rotates right the bits in the bitset
	 *
	 * @details Rotates the order of the bits in the bitset, in such a way that the bit pointed by @ref end() ` - ` @p shift becomes the new last element.
	 *
	 * @param shift Position of the bit that is moved to the last position in the bitset @b subtracted from the total length of the bitset.
	 *
	 * @warning Implementation of the right rotation of the bitset is slightly more complicated than the implementation of the left rotation (requires calculating the total length of the bitset (constant complexity)), thus <b>it takes slightly more time to rotate long bitsets right</b>.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise the bitset
	 *	bitset_t bitset({0, 1, 1, 0});
	 *
	 *	// Rotate right by two
	 *	bitset.rotateRight(2);
	 * @endcode
	 */
	void rotateRight(const size_t shift);

	/**
	 * @brief Shifts left the bits in the bitset
	 *
	 * @details Shifts the bits in the bitset, in such a way that the bit pointed by @ref begin() ` + ` @p shift becomes the new first element.
	 *
	 * @param shift Position of the bit that is moved to the first position in the bitset.
	 *
	 * @warning For every non-zero @p shift value exactly @p shift bits are lost and cannot be restored. <b>This operation cannot be undone</b>.
	 *
	 * @note Appended bits are zero-initialized.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise the bitset
	 *	bitset_t bitset({0, 1, 1, 0});
	 *
	 *	// Shift left by two
	 *	bitset.shiftLeft(2);
	 * @endcode
	 */
	void shiftLeft(const size_t shift);

	/**
	 * @brief Shifts right the bits in the bitset
	 *
	 * @details Shifts the bits in the bitset, in such a way that the bit pointed by @ref end() ` - ` @p shift becomes the new last element.
	 *
	 * @param shift Position of the bit that is moved to the last position in the bitset @b subtracted from the total length of the bitset.
	 *
	 * @warning For every non-zero @p shift value exactly @p shift bits are lost and cannot be restored. <b>This operation cannot be undone</b>.
	 *
	 * @note Appended bits are zero-initialized.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise the bitset
	 *	bitset_t bitset({0, 1, 1, 0});
	 *
	 *	// Shift right by two
	 *	bitset.shiftRight(2);
	 * @endcode
	 */
	void shiftRight(const size_t shift);



	//  ##     ## ##    ##    ###    ########  ##    ##
	//  ##     ## ###   ##   ## ##   ##     ##  ##  ##
	//  ##     ## ####  ##  ##   ##  ##     ##   ####
	//  ##     ## ## ## ## ##     ## ########     ##
	//  ##     ## ##  #### ######### ##   ##      ##
	//  ##     ## ##   ### ##     ## ##    ##     ##
	//   #######  ##    ## ##     ## ##     ##    ##

	/**
	 * @brief Calculates inverted bitset value
	 *
	 * @details Does not modify `*this` bitset.
	 *
	 * @return Inverted bitset_t value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset
	 *	bitset_t someBitset({0,0,1,0});
	 *
	 *	// Assign inverted bitset to the other bitset
	 *	bitset_t someOtherBitset = !someBitset;
	 * @endcode
	 *
	 * @see operator~()
	 */
	bitset_t operator!() const;

	/**
	 * @brief Calculates inverted bitset value
	 *
	 * @details Does not modify `*this` bitset.
	 *
	 * @return Inverted bitset_t value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset
	 *	bitset_t someBitset({0,0,1,0});
	 *
	 *	// Assign inverted bitset to the other bitset
	 *	bitset_t someOtherBitset = ~someBitset;
	 * @endcode
	 *
	 * @see operator!()
	 */
	bitset_t operator~() const;



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
	 * @details Overloaded bitwise exclusive OR (XOR, \f$ \oplus \f$) operator, considered equal to addition modulo 2, has the following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1\oplus x_2\f$ |
	 *	|:---------:|:---------:|:---------------------:|
	 *	|0          |0          |0                      |
	 *	|0          |1          |1                      |
	 *	|1          |0          |1                      |
	 *	|1          |1          |0                      |
	 *	XOR can be expressed in terms of NOT (\f$\neg\f$), OR (\f$\vee\f$) and AND (\f$\wedge\f$) as follows: \f$ f = x_1 \oplus x_2 = (x_1 \vee x_2) \wedge \neg(x_1 \wedge x_2) \f$. Operator is applied [pairwise] <b>to every pair of corresponding bits in the bitsets</b>: \f[ Y = X_1 \oplus X_2 \iff \forall i : Y^i = X_1^i \oplus X_2^i = f\left(X_1^i, X_2^i\right), \f] where \f$ X^i \f$ denotes \f$i-\f$th bit of the \f$X\f$ bitset.
	 *
	 * @param [in] other Second `bitset_t` operand \f$X_2\f$.
	 *
	 * @note \f$X_1\f$ bitset is passed via `*this`.
	 *
	 * @return `bitset_t` value \f$ Y = f(X_1, X_2) \f$
	 *
	 * @warning Bitsets \f$X_1\f$ (the one that this operator is invoked upon, `*this`) and \f$X_2\f$ (@p other) <b>must be of equal length</b>.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset_t values
	 *	bitset_t X1({0,1,1,0}), X2({1,1,1,0}), Y;
	 *
	 *	// Calculate Y = xor(X1, X2)
	 *	Y = X1 ^ X2;
	 * @endcode
	 */
	bitset_t operator^(const bitset_t& other) const;

	/**
	 * @brief Conjunction operator
	 *
	 * @details Overloaded bitwise conjuction (AND, \f$\&\f$, \f$\wedge\f$) operator, only returns `true` when both operands are `true`, and `false` otherwise; has the following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1\wedge x_2\f$ |
	 *	|:---------:|:---------:|:---------------------:|
	 *	|0          |0          |0                      |
	 *	|0          |1          |0                      |
	 *	|1          |0          |0                      |
	 *	|1          |1          |1                      |
	 *	Operator is applied [pairwise] <b>to every pair of corresponding bits in the bitsets</b>: \f[ Y = X_1 \wedge X_2 \iff \forall i : Y^i = X_1^i \wedge X_2^i = f\left(X_1^i, X_2^i\right), \f] where \f$ X^i \f$ denotes \f$i-\f$th bit of the \f$X\f$ bitset.
	 *
	 * @param [in] other Second `bitset_t` operand \f$X_2\f$.
	 *
	 * @note \f$X_1\f$ bitset is passed via `*this`.
	 *
	 * @return `bitset_t` value \f$ Y = f(X_1, X_2) \f$
	 *
	 * @warning Bitsets \f$X_1\f$ (the one that this operator is invoked upon, `*this`) and \f$X_2\f$ (@p other) <b>must be of equal length</b>.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset_t values
	 *	bitset_t X1({0,1,1,0}), X2({1,1,1,0}), Y;
	 *
	 *	// Calculate Y = X1 & X2
	 *	Y = X1 & X2;
	 * @endcode
	 */
	bitset_t operator&(const bitset_t& other) const;

	/**
	 * @brief Disjunction operator
	 *
	 * @details Overloaded bitwise disjuction (OR, \f$\vert\f$, \f$\vee\f$) operator, only returns `false` when both operands are `false`, and `true` otherwise; has the following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1 \vee x_2\f$  |
	 *	|:---------:|:---------:|:---------------------:|
	 *	|0          |0          |0                      |
	 *	|0          |1          |1                      |
	 *	|1          |0          |1                      |
	 *	|1          |1          |1                      |
	 *	Operator is applied [pairwise] <b>to every pair of corresponding bits in the bitsets</b>: \f[ Y = X_1 \vee X_2 \iff \forall i : Y^i = X_1^i \vee X_2^i = f\left(X_1^i, X_2^i\right), \f] where \f$ X^i \f$ denotes \f$i-\f$th bit of the \f$X\f$ bitset.
	 *
	 * @param [in] other Second `bitset_t` operand \f$X_2\f$.
	 *
	 * @note \f$X_1\f$ bitset is passed via `*this`.
	 *
	 * @return `bitset_t` value \f$ Y = f(X_1, X_2) \f$
	 *
	 * @warning Bitsets \f$X_1\f$ (the one that this operator is invoked upon, `*this`) and \f$X_2\f$ (@p other) <b>must be of equal length</b>.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset_t values
	 *	bitset_t X1({0,1,1,0}), X2({1,1,1,0}), Y;
	 *
	 *	// Calculate Y = X1 | X2
	 *	Y = X1 | X2;
	 * @endcode
	 */
	bitset_t operator|(const bitset_t& other) const;

	/**
	 * @brief Scalar product operator
	 *
	 * @details Scalar product operator (\f$*,\,\times,\,\cdot\f$) operator, sometimes is referred to as the inner product w/addition modulo 2. Scalar product \f$ y \f$ of bitsets \f$X_1\f$ and \f$X_2\f$ is calculated as follows: \f[ y = \left\langle X_1,\,X_2 \right\rangle \iff  y = \bigoplus_{i} \left( X_1^i \wedge X_2^i \right) = \sum_{i} \left( X_1^i \wedge X_2^i \right) \pmod{2}, \f] where \f$ X^i \f$ denotes \f$i-\f$th bit of the \f$X\f$ bitset.
	 *
	 * @param [in] other Second `bitset_t` operand \f$X_2\f$.
	 *
	 * @note \f$X_1\f$ bitset is passed via `*this`.
	 *
	 * @return `bitset_t` value \f$ Y = f(X_1, X_2) \f$
	 *
	 * @warning Bitsets \f$X_1\f$ (the one that this operator is invoked upon, `*this`) and \f$X_2\f$ (@p other) <b>must be of equal length</b>.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset_t values
	 *	bitset_t X1({0,1,1,0}), X2({1,1,1,0});
	 *
	 *	// Calculate scalar product <X1, X2>
	 *	bit_t product = X1 * X2;
	 * @endcode
	 */
	bit_t operator*(const bitset_t& other) const;

	/**
	 * @brief Negated conjuction operator
	 *
	 * @details Bitwise negated AND (NAND, \f$\big\vert\f$) operator, only returns `false` when both operands are `true`, and `true` otherwise; has the following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f=x_1 \,\big\vert\, x_2      \f$ |
	 *	|:---------:|:---------:|:---------------------------:|
	 *	|0          |0          |1                            |
	 *	|0          |1          |1                            |
	 *	|1          |0          |1                            |
	 *	|1          |1          |0                            |
	 *	Operator is applied [pairwise] <b>to every pair of corresponding bits in the bitsets</b>: \f[ Y = X_1\,\big\vert\,X_2 \iff \forall i : Y^i = X_1^i \,\big\vert\, X_2^i = f\left(X_1^i, X_2^i\right), \f] where \f$ X^i \f$ denotes \f$i-\f$th bit of the \f$X\f$ bitset.
	 *
	 * @param [in] left The first `bitset_t` operand, \f$X_1\f$.
	 * @param [in] right The first `bitset_t` operand, \f$X_2\f$.
	 *
	 * @return `bitset_t` value \f$ Y = f(X_1, X_2) \f$
	 *
	 * @warning Bitsets \f$X_1\f$ (the one that this operator is invoked upon, `*this`) and \f$X_2\f$ (@p other) <b>must be of equal length</b>.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset_t values
	 *	bitset_t X1({0,1,1,0}), X2({1,1,1,0}), Y;
	 *
	 *	// Calculate Y = !(X1 & X2)
	 *	Y = nand(X1, X2)
	 * @endcode
	 */
	friend bitset_t nand(bitset_t& left, bitset_t& right);

	/**
	 * @brief Negated disjuction operator
	 *
	 * @details Bitwise negated OR (NOR, \f$\downarrow\f$) operator, only returns `true` when both operands are `false`, and `false` otherwise; has the following truth table:
	 *	| \f$x_1\f$ | \f$x_2\f$ | \f$f= x_1 \downarrow x_2\f$ |
	 *	|:---------:|:---------:|:---------------------------:|
	 *	|0          |0          |1                            |
	 *	|0          |1          |0                            |
	 *	|1          |0          |0                            |
	 *	|1          |1          |0                            |
	 *	Operator is applied [pairwise] <b>to every pair of corresponding bits in the bitsets</b>: \f[ Y = X_1 \downarrow X_2 \iff \forall i : Y^i = X_1^i \downarrow X_2^i = f\left(X_1^i, X_2^i\right), \f] where \f$ X^i \f$ denotes \f$i-\f$th bit of the \f$X\f$ bitset.
	 *
	 * @param [in] left The first `bitset_t` operand, \f$X_1\f$.
	 * @param [in] right The first `bitset_t` operand, \f$X_2\f$.
	 *
	 * @return `bitset_t` value \f$ Y = f(X_1, X_2) \f$
	 *
	 * @warning Bitsets \f$X_1\f$ (the one that this operator is invoked upon, `*this`) and \f$X_2\f$ (@p other) <b>must be of equal length</b>.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset_t values
	 *	bitset_t X1({0,1,1,0}), X2({1,1,1,0}), Y;
	 *
	 *	// Calculate Y = nor(X1, X2)
	 *	Y = nor(X1, X2)
	 * @endcode
	 */
	friend bitset_t nor(bitset_t& left, bitset_t& right);



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
	 * @param [in] other The right `bitset_t` part of the assignment.
	 *
	 * @return Modified `*this` `bitset_t` value.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitsets
	 *	bitset_t X1({0,1,1,0}), X2;
	 *
	 *	// Assign X1 bits to X2 bitset
	 *	X2 = X1;
	 * @endcode
	 */
	bitset_t& operator=(const bitset_t other);

	/**
	 * @brief Exclusive OR compound assignment operator
	 *
	 * @details Bitwise unary exclusive OR (XOR, \f$\oplus\f$) compound assignment operator, assigns @p other operand value xored by current `*this` value to `*this`, as follows: \f[ Y = Y \oplus X.\f]
	 *
	 * @param [in] other The right `bitset_t` part of the assignment, \f$X\f$.
	 *
	 * @return Modified `*this` `bitset_t` value.
	 *
	 * @warning Bitsets \f$Y\f$ (the one that this operator is invoked upon, `*this`) and \f$X\f$ (@p other) <b>must be of equal length</b>.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitsets
	 *	bitset_t X({0,1,1,0}), Y({0,0,0,1});
	 *
	 *	// Xor X by Y, then assign result bits to Y
	 *	Y ^= X;
	 * @endcode
	 */
	bitset_t& operator^=(const bitset_t& other);

	/**
	 * @brief Conjunction compound assignment operator
	 *
	 * @details Bitwise unary conjunction (AND, \f$\wedge\f$, \f$\&\f$) compound assignment operator, assigns @p other operand value conjucted by current `*this` value to `*this`, as follows: \f[ Y = Y \wedge X.\f]
	 * @param [in] other The right `bitset_t` part of the assignment, \f$X\f$.
	 *
	 * @return Modified `*this` `bitset_t` value.
	 *
	 * @warning Bitsets \f$Y\f$ (the one that this operator is invoked upon, `*this`) and \f$X\f$ (@p other) <b>must be of equal length</b>.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitsets
	 *	bitset_t X({0,1,1,0}), Y({0,0,0,1});
	 *
	 *	// Conjunct X by Y, then assign result bits to Y
	 *	Y &= X;
	 * @endcode
	 */
	bitset_t& operator&=(const bitset_t& other);

	/**
	 * @brief Disjunction compound assignment operator
	 *
	 * @details Bitwise unary disjunction (OR, \f$\vee\f$) compound assignment operator, assigns @p other operand value disjucted by current `*this` value to `*this`, as follows: \f[ Y = Y \vee X.\f]
	 * @param [in] other The right `bitset_t` part of the assignment, \f$X\f$.
	 *
	 * @return Modified `*this` `bitset_t` value.
	 *
	 * @warning Bitsets \f$Y\f$ (the one that this operator is invoked upon, `*this`) and \f$X\f$ (@p other) <b>must be of equal length</b>.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitsets
	 *	bitset_t X({0,1,1,0}), Y({0,0,0,1});
	 *
	 *	// Disjunct X by Y, then assign result bits to Y
	 *	Y |= X;
	 * @endcode
	 */
	bitset_t& operator|=(const bitset_t& other);

	/**
	 * @brief Returns bit at position @p index
	 *
	 * @details Returns a reference to the bit at specified location @p index.
	 *
	 * @param [in] index Position of the bit to return.
	 *
	 * @return Reference to the requested bit.
	 *
	 * @warning No bounds checking is performed.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset
	 *	bitset_t X({0,1,1,0});
	 *
	 *	// Capture second bit (1) by reference
	 *	bit_t bit = X[1];
	 * @endcode
	 */
	std::vector<bit_t>::reference operator[](const size_t index);

	/**
	 * @brief Returns bit at position @p index
	 *
	 * @details Returns a (`const`) reference to the bit at specified location @p index.
	 *
	 * @param [in] index Position of the bit to return.
	 *
	 * @return (`const`) reference to the requested bit.
	 *
	 * @warning No bounds checking is performed.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset
	 *	bitset_t X({1,0,1,0});
	 *
	 *	// Capture second bit (0) by reference
	 *	bit_t bit = X[1];
	 * @endcode
	 */
	std::vector<bit_t>::const_reference operator[](const size_t index) const;

	/**
	 * @brief Returns bit at position @p index
	 *
	 * @details Returns a reference to the bit at specified location @p index.
	 *
	 * @param [in] index Position of the bit to return.
	 *
	 * @return Reference to the requested bit.
	 *
	 * @note This method automatically checks whether @p index is within the bounds of valid bits in the bitset, throwing an `out_of_range` exception if it is not. This is in contrast with member @ref operator[](), that does not check against bounds.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset
	 *	bitset_t X({1,0,1,0});
	 *
	 *	// Capture second bit (0) by reference
	 *	bit_t bit = X.at(1);
	 * @endcode
	 */
	std::vector<bit_t>::reference at(const size_t index);

	/**
	 * @brief Returns bit at position @p index
	 *
	 * @details Returns a (`const`) reference to the bit at specified location @p index.
	 *
	 * @param [in] index Position of the bit to return.
	 *
	 * @return (`const`) reference to the requested bit.
	 *
	 * @note This method automatically checks whether @p index is within the bounds of valid bits in the bitset, throwing an `out_of_range` exception if it is not. This is in contrast with member @ref operator[](), that does not check against bounds.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset
	 *	bitset_t X({1,0,1,0});
	 *
	 *	// Capture second bit (0) by reference
	 *	bit_t bit = X.at(1);
	 * @endcode
	 */
	std::vector<bit_t>::const_reference at(const size_t index) const;

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
	 * @details Test whether the `bitset_t` instances are equal
	 *
	 * @param [in] other The right `bitset_t` part of the comparison.
	 *
	 * @retval true `*this` and @p other bitsets are equal
	 * @retval false `*this` and @p other bitsets are unequal
	 *
	 * @note The bitsets are considered equal if, and only if every bit in the first bitset is equal to the corresponding bit in the second bitset: \f[ X_1 = X_2 \iff \forall i : X_1^i = X_2^i,\f] where \f$ X^i \f$ denotes \f$i-\f$th bit of the \f$X\f$ bitset.
	 * @note The bitsets are considered unequal if there is at least one bit in the first vector which is different from the corresponding but in the second vector: \f[ X_1 \neq X_2 \iff \exists i : X_1^i \neq X_2^i,\f] where \f$ X^i \f$ denotes \f$i-\f$th bit of the \f$X\f$ bitset.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitsets
	 *	bitset_t X1({0,1,1,1,0}), X2({1,1,1,0,1,0});
	 *
	 *	// Test if X1 and X2 are equal
	 *	bool y = (X1 == X2);
	 * @endcode
	 */
	bool operator== (bitset_t& other);

	/**
	 * @brief Unequality test operator
	 *
	 * @details Test whether the `bitset_t` instances are unequal
	 *
	 * @param [in] other The right `bitset_t` part of the comparison.
	 *
	 * @retval true `*this` and @p other bitsets are unequal
	 * @retval false `*this` and @p other bitsets are equal
	 *
	 * @note The bitsets are considered equal if, and only if every bit in the first bitset is equal to the corresponding bit in the second bitset: \f[ X_1 = X_2 \iff \forall i : X_1^i = X_2^i,\f] where \f$ X^i \f$ denotes \f$i-\f$th bit of the \f$X\f$ bitset.
	 * @note The bitsets are considered unequal if there is at least one bit in the first vector which is different from the corresponding but in the second vector: \f[ X_1 \neq X_2 \iff \exists i : X_1^i \neq X_2^i,\f] where \f$ X^i \f$ denotes \f$i-\f$th bit of the \f$X\f$ bitset.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitsets
	 *	bitset_t X1({0,1,1,1,0}), X2({1,1,1,0,1,0});
	 *
	 *	// Test if X1 and X2 are unequal
	 *	bool y = (X1 != X2);
	 * @endcode
	 */
	bool operator!= (bitset_t& other);



	//  #### ##    ## ######## ########  ########    ###     ######  ########
	//   ##  ###   ##    ##    ##     ## ##         ## ##   ##    ## ##
	//   ##  ####  ##    ##    ##     ## ##        ##   ##  ##       ##
	//   ##  ## ## ##    ##    ########  ######   ##     ## ##       ######
	//   ##  ##  ####    ##    ##   ##   ##       ######### ##       ##
	//   ##  ##   ###    ##    ##    ##  ##       ##     ## ##    ## ##
	//  #### ##    ##    ##    ##     ## ##       ##     ##  ######  ########

	/**
	 * @brief Returns string with the binary representation of the bitset
	 *
	 * @return `std::string` containing the binary bit representation.
	 *
	 * @note Method does not modify `*this` value, upon which it was invoked.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset
	 *	bitset_t bitset({0,1,1,0,1,0,1});
	 *
	 *	// Insert bits in the console output stream
	 *	std::cout << bitset.toBinaryString() << endl;
	 * @endcode
	 */
	std::string toBinaryString() const;

	/**
	 * @brief Returns string with the binary representation of the bitset
	 *
	 * @details Bits in the string would be separated by the delimiter.
	 *
	 * @return `std::string` containing the binary bit representation w/delimiters.
	 *
	 * @note Method does not modify `*this` value, upon which it was invoked.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset
	 *	bitset_t bitset({0,1,1,0,1,0,1});
	 *
	 *	// Insert bits in the console output stream
	 *	std::cout << bitset.toBinaryString(" ") << endl;
	 * @endcode
	 */
	std::string toBinaryString(const std::string delimiter) const;

	/**
	 * @brief Inserts @p bitset binary representation into @p os
	 *
	 * @details Insertion is performed with toBinaryString() method.
	 *
	 * @param [in,out] os An `std::ostream` which method is invoked upon.
	 * @param [in] bits Bitset to be inserted.
	 *
	 * @return Modified `std::ostream` stream.
	 *
	 * @note Uses overloaded for `std::string` stream insertion operator.
	 *
	 * Example usage:
	 * @code
	 *	// Initialise bitset
	 *	bitset_t bitset({0,1,1,0,1,0,1});
	 *
	 *	// Insert bits in the console output stream
	 *	std::cout << bitset << endl;
	 * @endcode
	 *
	 * @see toBinaryString()
	 */
	friend std::ostream& operator<<(std::ostream& os, const bitset_t& bits);
};

#endif
