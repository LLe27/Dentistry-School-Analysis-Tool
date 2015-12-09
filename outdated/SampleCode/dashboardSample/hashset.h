//
//  hashset.h
//  
//
//  Created by Zain Hemani on 2015-10-22.
//
//

/*
 * File: hashset.h
 * ---------------
 * This interface exports the HashSet class, which is identical to the Set
 * class except for the fact that it uses a hash table as its underlying
 * representation.  The advantage of the HashSet class is that it operates
 * in constant time, as opposed to the O(log N) time for the Set class.
 * The disadvantage of HashSet is that iterators return the values in a
 * seemingly random order.
 */

#ifndef _hashset_h
#define _hashset_h

#include <iostream>
#include "hashmap.h"
#include "vector.h"

/*
 * Class: HashSet<ValueType>
 * -------------------------
 * This template class stores a collection of distinct elements.
 */

template <typename ValueType>
class HashSet {
    
public:
    
    /*
     * Constructor: HashSet
     * Usage: HashSet<ValueType> set;
     * ------------------------------
     * Initializes an empty set of the specified element type.
     */
    
    HashSet();
    
    /*
     * Destructor: ~HashSet
     * --------------------
     * Frees any heap storage associated with this set.
     */
    
    ~HashSet();
    
    /*
     * Method: size
     * Usage: count = set.size();
     * --------------------------
     * Returns the number of elements in this set.
     */
    
    int size() const;
    
    /*
     * Method: isEmpty
     * Usage: if (set.isEmpty()) . . .
     * -------------------------------
     * Returns true if this set contains no elements.
     */
    
    bool isEmpty() const;
    
    /*
     * Method: add
     * Usage: set.add(value);
     * ----------------------
     * Adds an element to this set, if it was not already there.  For
     * compatibility with the STL set class, this method is also exported as
     * insert.
     */
    
    void add(const ValueType & value);
    void insert(const ValueType & value);
    
    /*
     * Method: remove
     * Usage: set.remove(value);
     * -------------------------
     * Removes an element from this set.  If the value was not contained in the
     * set, no error is generated and the set remains unchanged.
     */
    
    void remove(const ValueType & value);
    
    /*
     * Method: contains
     * Usage: if (set.contains(value)) . . .
     * -------------------------------------
     * Returns true if the specified value is in this set.
     */
    
    bool contains(const ValueType & value) const;
    
    /*
     * Method: isSubsetOf
     * Usage: if (set.isSubsetOf(set2)) . . .
     * --------------------------------------
     * Implements the subset relation on sets.  It returns true if every
     * element of this set is contained in set2.
     */
    
    bool isSubsetOf(const HashSet & set2) const;
    
    /*
     * Method: clear
     * Usage: set.clear();
     * -------------------
     * Removes all elements from this set.
     */
    
    void clear();
    
    /*
     * Operator: ==
     * Usage: set1 == set2
     * -------------------
     * Returns true if set1 and set2 contain the same elements.
     */
    
    bool operator==(const HashSet & set2) const;
    
    /*
     * Operator: !=
     * Usage: set1 != set2
     * -------------------
     * Returns true if set1 and set2 are different.
     */
    
    bool operator!=(const HashSet & set2) const;
    
    /*
     * Operator: +
     * Usage: set1 + set2
     *        set1 + element
     * ---------------------
     * Returns the union of sets set1 and set2, which is the set of elements
     * that appear in at least one of the two sets.  The right hand set can be
     * replaced by an element of the value type, in which case the operator
     * returns a new set formed by adding that element.
     */
    
    HashSet operator+(const HashSet & set2) const;
    HashSet operator+(const ValueType & element) const;
    
    /*
     * Operator: *
     * Usage: set1 * set2
     * ------------------
     * Returns the intersection of sets set1 and set2, which is the set of all
     * elements that appear in both.
     */
    
    HashSet operator*(const HashSet & set2) const;
    
    /*
     * Operator: -
     * Usage: set1 - set2
     *        set1 - element
     * ---------------------
     * Returns the difference of sets set1 and set2, which is all of the
     * elements that appear in set1 but not set2.  The right hand set can be
     * replaced by an element of the value type, in which case the operator
     * returns a new set formed by removing that element.
     */
    
    HashSet operator-(const HashSet & set2) const;
    HashSet operator-(const ValueType & element) const;
    
    /*
     * Operator: +=
     * Usage: set1 += set2;
     *        set1 += value;
     * ---------------------
     * Adds all of the elements from set2 (or the single specified value) to
     * set1.  As a convenience, the HashSet package also overloads the comma
     * operator so that it is possible to initialize a set like this:
     *
     *    HashSet<int< digits;
     *    digits += 0, 1, 2, 3, 4, 5, 6, 7, 8, 9;
     */
    
    HashSet & operator+=(const HashSet & set2);
    HashSet & operator+=(const ValueType & value);
    
    /*
     * Operator: *=
     * Usage: set1 *= set2;
     * --------------------
     * Removes any elements from set1 that are not present in set2.
     */
    
    HashSet & operator*=(const HashSet & set2);
    
    /*
     * Operator: -=
     * Usage: set1 -= set2;
     *        set1 -= value;
     * ---------------------
     * Removes the elements from set2 (or the single specified value) from
     * set1.  As a convenience, the HashSet package also overloads the comma
     * operator so that it is possible to remove multiple elements from a set
     * like this:
     *
     *    digits -= 0, 2, 4, 6, 8;
     *
     * which removes the values 0, 2, 4, 6, and 8 from the set digits.
     */
    
    HashSet & operator-=(const HashSet & set2);
    HashSet & operator-=(const ValueType & value);
    
    /*
     * Method: first
     * Usage: ValueType value = set.first();
     * -------------------------------------
     * Returns the first value in the set in the order established by the
     * foreach macro.  If the set is empty, first generates an error.
     */
    
    ValueType first() const;
    
    /*
     * Additional HashSet operations
     * -----------------------------
     * In addition to the methods listed in this interface, the HashSet class
     * supports the following operations:
     *
     *   - Stream insertion using the << operator
     *   - Deep copying for the copy constructor and assignment operator
     *   - Iteration using the range-based for statement, standard STL
     *     iterators, and the mapping function mapAll
     *
     * The iteration forms process the HashSet in an unspecified order.
     */
    
};

#endif
