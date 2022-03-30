/**************** DO NOT CHANGE THIS FILE! ****************/
// FILE: Sequence.h
// CLASS PROVIDED: Sequence (part of the namespace cs223_lab2)
//
// TYPEDEFS and MEMBER CONSTANTS for the Sequence class:
//   typedef ____ value_type
//   Sequence::value_type is the data type of the items in the Sequence. It
//      may be any of the C++ built-in types (int, char, etc.), or a class with
//      a default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//   Sequence::size_type is the data type of any variable that keeps track of
//      how many items are in a sequence.
//
//   static const size_type CAPACITY = _____
//   Sequence::CAPACITY is the maximum number of items that a sequence can hold.
//
// CONSTRUCTORS for the Sequence class:
//   Sequence()
//   Postcondition: The sequence has been initialized as an empty sequence.
//
//   Sequence(const value_type arr[], size_type len)
//     Precondition: The array contains at least len items.
//     Precondition: len <= CAPACITY
//     Postcondition: The first len items of the sequence have been initialized
//        to contain the first len items from the array. If len is zero, there 
//        is no current item; otherwise, the current item is the first item in 
//        the sequence
//
// CONSTANT MEMBER FUNCTIONS for the Sequence class:
//   size_type size() const
//     Postcondition: The return value is the length of the sequence.
//
//   bool has_current() const
//     Postcondition: A `true` return value indicates that there is a valid
//        current item that may be retrieved by activating the `current`
//        member function (see below). A `false` return value indicates that
//        there is no valid current item.
//
//   value_type current() const
//     Precondition: has_current() returns true (there is a current item).
//     Postcondition: The item returned is the current item in the Sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the Sequence class:
//   void start()
//     Postcondition: The sequence of items is not modified.
//     Postcondition: If the sequence is not empty, the first item in the
//        sequence is the current item.
//
//   void advance()
//     Precondition: has_current() returns true (there is a current item).
//     Postcondition: The sequence of items is not modified.
//     Postcondition: If the current item was already the last item in the
//        sequence, then there is no longer a current item; otherwise, the new
//        current item is the item immediately after the original current item.
//     Example: If the sequence is (p, i, g) with current item p, then after
//        a call to advance() the sequence is (p, i, g) with current item i.
//
//   void append(const value_type& entry)
//     Precondition: size() < CAPACITY.
//     Postcondition: The provided value, `entry`, has been placed at the end 
//        of the sequence. The newly appended item is now the current item of 
//        the sequence.
//     Example: If the sequence is (p, i, g) with current item i, then after
//        a call to append('s') the sequence is (p, i, g, s) with current item s.
//     Example: If the sequence is (c, a, t) with NO CURRENT ITEM, then after
//        a call to append('!') the sequence is (c, a, t, !) with current item !.
//
//   void insert(const value_type& entry)
//     Precondition: size() < CAPACITY.
//     Postcondition: The provided value, `entry`, has been inserted into the 
//        sequence BEFORE the current item. If there was no current item, then 
//        the new entry has been inserted at the FRONT of the sequence. In either 
//        case, the newly inserted item is now the current item of the sequence.
//     Example: If the sequence is (c, a, t, !) with current item !, then after
//        a call to insert('Z') the sequence is (c, a, t, Z, !) with current item Z.
//     Example: If the sequence is (X, Y) with NO CURRENT ITEM, then after
//        a call to insert('K') the sequence is (K, X, Y) with current item K.
//
//   void remove_current()
//     Precondition: has_current returns true (there is a current item).
//     Postcondition: The current item has been removed from the sequence, and 
//        the item that was immediately to the right of current (if there was one) 
//        is now the new current item.
//     Example: If the sequence is (K, X, Y) with current item X, then after
//        a call to remove_current() the sequence is (K, Y) with current item Y.
//     Example: If the sequence is (i, n, d, i, a, n, A) with current item A,
//        then after a call to remove_current() the sequence is (i, n, d, i, a, n)
//        with no current item.
//
// VALUE SEMANTICS for the Sequence class:
//   Assignments and the copy constructor may be used with Sequence objects.
//
// OPERATOR OVERLOADING
//
//   ***MEMBER FUNCTION***
//   void operator+=(const Sequence& otherSeq)
//     increment operator (+=)
//     Precondition: this.length + otherSeq.length <= Sequence::CAPACITY
//     Postcondition: The order of the items in this sequence is maintained, but
//        the items in otherSeq have been added to the end of this sequence,
//        maintaining their relative order.
//     Postcondition: If this sequence has a current item, the current item is
//        still the current item; if the sequence does not have a current item,
//        there is still no current item.
//
//   ***NON-MEMBER FUNCTIONS***
//   friend bool operator==(const Sequence& seqA, const Sequence& seqB)
//     equality operator (==); seqA and seqB are "equal" iff they have:
//        - the same size
//        - the same items, and *in the same order*
//     Example: Sequence (d, o, g) with current item o and sequence (d, o, g)
//        with no current item are equal.  (The current item is irrelevant for
//        determining equality of sequences.)
//
//   friend bool operator!=(const Sequence& seqA, const Sequence& seqB)
//      inequality operator (!=); logical negation of the equality operator
//
//   friend std::ostream& operator<<(std::ostream& out, const Sequence& seq)
//     stream output operator (<<)
//     Example: A sequence (c, o, w, s) with current item w would produce the
//        following output:
//          Sequence: c o w s\n
//     Example: An empty sequence () would produce the following output:
//          Sequence: <empty sequence>\n
//     NOTE: Returns the `out` parameter to allow chaining of stream output.
//     NOTE: Get the spacing exactly right!
//
//   friend std::istream& operator>>(std::istream& in, Sequence& seq)
//     stream input operator, for modifying a sequence by reading an input stream
//     Precondition: `in` holds a string in the exact format produced by <<
//        (see above), FOLLOWED BY A NEWLINE CHARACTER '\n'
//     Postcondition: s1 will hold the items listed in the input stream.
//     Postcondition: The current item of s1 will be its first item, unless
//        s1 is an empty sequence (in which case there is no current item).
//     Example: If the input stream `in` holds the message,
//         "Sequence: c o w s\n"
//        then `in >> s1` will cause s1 to be modified: s1 will have length = 4,
//        items (c, o, w, s), and current item c.
//     NOTE: Returns the `in` parameter to allow chaining of stream input.

#ifndef CS223_LAB2_H
#define CS223_LAB2_H

namespace cs223_lab2
{
class Sequence
{
  public:
    // TYPEDEFS and MEMBER CONSTANTS
    typedef char value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 30;

    // CONSTRUCTORS
    Sequence();
    Sequence(value_type arr[], size_type len);

    // CONSTANT MEMBER FUNCTIONS
    size_type size() const;
    bool has_current() const;
    value_type current() const;

    // MODIFICATION MEMBER FUNCTIONS
    void start();
    void advance();
    void append(const value_type& entry);
    void insert(const value_type& entry);
    void remove_current();

    // OPERATOR OVERLOADS (Class Members)
    void operator+=(const Sequence& otherSeq);

    // Friend Declarations
    friend bool operator==(const Sequence& seqA, const Sequence& seqB);
    friend bool operator!=(const Sequence& seqA, const Sequence& seqB);
    friend std::ostream& operator<<(std::ostream& out, const Sequence& seq);
    friend std::istream& operator>>(std::istream& in, Sequence& seq);

  private:
    value_type data[CAPACITY];
    size_type length;    // NOTE CHANGE OF NAME
                         // (length is called `used` in the textbook)
    size_type current_index;
};

// OPERATOR OVERLOADS (Friends)
bool operator==(const Sequence& seqA, const Sequence& seqB);
bool operator!=(const Sequence& seqA, const Sequence& seqB);
std::ostream& operator<<(std::ostream& out, const Sequence& seq);
std::istream& operator>>(std::istream& in, Sequence& seq);

}  // namespace cs223_lab2

#endif
