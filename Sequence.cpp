// Sequence.cpp
// Implementation file for Sequence Class

// Name: Lauren Dickman
// Date: 02/04/2020

// The private instance variables of the Sequence class are:
//    value_type data[CAPACITY] -- an array for storing the items
//    size_type length          -- current number of items
//    size_type current_index   -- index of the current item
//       current_index implements the following idea: you can have your
//       index finger on a specific item in the sequence.
//
// CAPACITY is given a specific value in the header file at compile time.
//    Always refer to the capacity of the sequence by name `CAPACITY` in
//    your implementation; never use the actual number value of CAPACITY.
//
// CLASS INVARIANT: 
//    1. The number of the items in the sequence is in the member variable length.
//    2. The items in the sequence are stored in data[0] through data[length-1].
//    3. The current_index will always satisfy one of the following two conditions:
//        a. 0 <= current_index < length.  In this case, there is a current
//           item, data[current_index].  has_current() returns true in this case.
//        b. current_index == length.  In this case, there is NO current item.
//           has_current() returns false in this case.
//

#include <cstdlib>
#include <iostream>
#include "Sequence.h"

using namespace std;

namespace cs223_lab2
{
// CONSTRUCTORS for the Sequence class:
//   Sequence()
//   Postcondition: The sequence has been initialized as an empty sequence.
Sequence::Sequence()
{
    length = 0;
    current_index = 0;
}
//
//   Sequence(const value_type arr[], size_type len)
//     Precondition: The array contains at least len items.
//     Precondition: len <= CAPACITY
//     Postcondition: The first len items of the sequence have been initialized
//        to contain the first len items from the array. If len is zero, there 
//        is no current item; otherwise, the current item is the first item in 
//        the sequence
Sequence::Sequence(Sequence::value_type arr[], Sequence::size_type len)
{
    length = len;
    for (Sequence::size_type i = 0; i < len; i++) 
    {
        data[i] = arr[i];
    }
    current_index = 0;
}
//
// CONSTANT MEMBER FUNCTIONS for the Sequence class:
//   size_type size() const
//     Postcondition: The return value is the length of the sequence.
Sequence::size_type Sequence::size() const
{
    return length;
}
//
//   bool has_current() const
//     Postcondition: A `true` return value indicates that there is a valid
//        current item that may be retrieved by activating the `current`
//        member function (see below). A `false` return value indicates that
//        there is no valid current item.
bool Sequence::has_current() const
{
    if (length == current_index)
    { 
        return false;
    }
    return true;
}
//
//   value_type current() const
//     Precondition: has_current() returns true (there is a current item).
//     Postcondition: The item returned is the current item in the Sequence.
Sequence::value_type Sequence::current() const
{
    return data[current_index];
}
//
// MODIFICATION MEMBER FUNCTIONS for the Sequence class:
//   void start()
//     Postcondition: The sequence of items is not modified.
//     Postcondition: If the sequence is not empty, the first item in the
//        sequence is the current item.void start()
void Sequence::start()
{
    current_index = 0;
}
//
//   void advance()
//     Precondition: has_current() returns true (there is a current item).
//     Postcondition: The sequence of items is not modified.
//     Postcondition: If the current item was already the last item in the
//        sequence, then there is no longer a current item; otherwise, the new
//        current item is the item immediately after the original current item.
//     Example: If the sequence is (p, i, g) with current item p, then after
//        a call to advance() the sequence is (p, i, g) with current item i.
void Sequence::advance()
{
    current_index++;
}
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
void Sequence::append(const Sequence::value_type& entry)
{
    data[length] = entry;
    length++;
    current_index = length - 1;
}
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
void Sequence::insert(const Sequence::value_type& entry)
{
    length ++;
    for (Sequence::size_type i = length ; i > current_index; i--)
    {
        data[i] = data[i - 1]; 
    }
    data[current_index] = entry;
}
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
void Sequence::remove_current()
{
    for (Sequence::size_type i = current_index ; i < length; i++)
    {
        data[i] = data[i+1];
    }
    length--;
}

// OPERATOR OVERLOADS (Class Members)
//   void operator+=(const Sequence& otherSeq)
//     increment operator (+=)
//     Precondition: this.length + otherSeq.length <= Sequence::CAPACITY
//     Postcondition: The order of the items in this sequence is maintained, but
//        the items in otherSeq have been added to the end of this sequence,
//        maintaining their relative order.
//     Postcondition: If this sequence has a current item, the current item is
//        still the current item; if the sequence does not have a current item,
//        there is still no current item.
void Sequence::operator+=(const Sequence& otherSeq)
{
    Sequence::size_type num = current_index;
    for (Sequence::size_type i = 0; i < otherSeq.length; i++) 
    {
        this->append(otherSeq.data[i]);
    }
    current_index = num;
}

// Friend Declarations
//   friend bool operator==(const Sequence& seqA, const Sequence& seqB)
//     equality operator (==); seqA and seqB are "equal" iff they have:
//        - the same size
//        - the same items, and *in the same order*
//     Example: Sequence (d, o, g) with current item o and sequence (d, o, g)
//        with no current item are equal.  (The current item is irrelevant for
//        determining equality of sequences.)
bool operator==(const Sequence& seqA, const Sequence& seqB)
{
    if (seqA.length == seqB.length)
    {
        for (Sequence::size_type i = 0; i < seqA.length; i++) 
        {
            if (seqA.data[i] != seqB.data[i])
            {
                return false;
            }
        }
        return true;
    } 
    return false;
}
//
//   friend bool operator!=(const Sequence& seqA, const Sequence& seqB)
//      inequality operator (!=); logical negation of the equality operator
bool operator!=(const Sequence& seqA, const Sequence& seqB)
{
    if (seqA.length != seqB.length)
    {
        return true;
    }
    else
    {
        for (Sequence::size_type i = 0; i < seqA.length; i++) 
        {
            if (seqA.data[i] != seqB.data[i])
                return true;
        }
        return false;
    }

}
//
// *** implementation provided ***
// stream output operator (<<)
// Example:  A sequence (c, o, w, s) with current item w would produce the
//    following output:
//      sequence: c o w s
// Example:  An empty sequence () would produce the following output:
//      sequence: <empty sequence>
// FOLLOWED BY A NEWLINE
// note: returns the `out` parameter to allow chaining of stream output
// note: get the spacing exactly right
ostream& operator<<(ostream& out, const Sequence& seq)
{
    out << "Sequence:";

    // stream the data for a non-empty sequence
    for (Sequence::size_type i = 0; i < seq.size(); i++)
    {
        out << " " << seq.data[i];
    }

    // stream a message for an empty sequence
    if (seq.size() == 0)
    {
        out << " <empty sequence>";
    }

    // end with a newline
    out << "\n";

    // enable chaining for the << operator
    return out;
}
//
// *** implementation provided ***
// friend istream& operator>>(istream& in, Sequence& seq)
// stream input operator, for modifying a sequence by reading an input stream
// Precondition:  `in` holds a string in the exact format produced by <<
//    (see above), FOLLOWED BY A NEWLINE CHARACTER '\n'
// Postcondition: s1 will hold the items listed in the input stream
// Postcondition: s1 will have its first item as the current item, unless
//    s1 is an empty sequence (in which case there is no current item)
// Example: if the input stream `in` holds the message,
//     "Sequence: c o w s\n"
//    then `in >> s1` will cause s1 to be modified: s1 will have length = 4,
//    items (c, o, w, s), and current item c.
// note: returns the `in` parameter to allow chaining of stream input
istream& operator>>(istream& in, Sequence& seq)
{    
    // "empty out" the current contents of seq    
    seq.length = 0;    
    seq.current_index = 0;   

    // ignore non-relevant input    
    string start_stuff = "Sequence: ";    
    in.ignore(start_stuff.size());    

    // read sequence data from input stream with getline    
    string seq_string;    
    getline(in, seq_string, '\n');    

    // just return if input sequence is empty    
    if (seq_string == string("<empty sequence>")) return in;    

    // otherwise, append chars to seq    
    for (size_t i = 0; i < seq_string.size(); i += 2)    
    {        
        seq.append(seq_string[i]);    
    }    

    // current item should be first item     
    seq.start();    

    // enable chaining for the >> operator
    return in;
}
}  // namespace cs223_lab2
