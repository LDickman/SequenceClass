// Sequence_tests.cpp
// Unit tests for Sequence class, CS 223 Lab 2

// Name: Lauren Dickman
// Date: 02/04/2020

#include <sstream>
#include <iostream>
#include <string>
#include "Sequence.h"
#include "gtest/gtest.h"  // declares the testing framework

using namespace std;
using namespace cs223_lab2;

namespace {

static const size_t CAPACITY = cs223_lab2::Sequence::CAPACITY;

/*
 Tests for the sequence class are listed below. For this lab,
 you are responsible for writing any tests not already provided.

 Write tests ONE AT A TIME as you go through the
 Test-Driven Development (TDD) process.

 USE THE PROVIDED NAMES for the Google test suites (e.g., "StudentTestSequenceAppend")
 and individual tests (e.g., "Append_To_Empty").  Within this file, tests
 should be implemented in the given order.

 REMINDER: For 2-argument EXPECTS and ASSERTS, the first argument is
 the actual value from executing the function, and the second argument
 is the expected correct value.

 DO NOT CHANGE THE ORDER OF THE TESTS
*/

/*
TestConstructorsAndGetters
  - PRVD_DefaultConstructor_Size_0_HasCurrent_False <<== PROVIDED
  - PRVD_ConstructWithArrayLen0_Size_0_HasCurrent_False <<== PROVIDED
  - PRVD_ConstructWithArrayLen1_Size_1_HasCurrent_True <<== PROVIDED
  - PRVD_ConstructWithArrayLen3_Size_3_HasCurrent_True <<== PROVIDED
*/

TEST(TestConstructorsAndGetters, PRVD_DefaultConstructor_Size_0_HasCurrent_False)
{
    Sequence s1;
    EXPECT_EQ(s1.size(), 0);
    EXPECT_FALSE(s1.has_current());
}

TEST(TestConstructorsAndGetters,
	PRVD_ConstructWithArrayLen0_Size_0_HasCurrent_False)
{
    // setup, execute
    char arr[] = { };
    Sequence s1(arr, 0);

    // check
    EXPECT_EQ(s1.size(), 0);
    EXPECT_FALSE(s1.has_current());
}

TEST(TestConstructorsAndGetters,
	PRVD_ConstructWithArrayLen1_Size_1_HasCurrent_True)
{
    // setup, execute
    char arr[] = { 'X' };
    Sequence s1(arr, 1);

    // check
    EXPECT_EQ(s1.size(), 1);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'X');
}

TEST(TestConstructorsAndGetters,
	PRVD_ConstructWithArrayLen3_Size_3_HasCurrent_True)
{
    // setup, execute
    char arr[] = { 'X', 'Y', 'Z' };
    Sequence s1(arr, 3);

    // check
    EXPECT_EQ(s1.size(), 3);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'X');
}

/*
TestParamConstructorPlusAdvanceStart
  - PRVD_ConstructWithArrayLen1_Advance_Start_CheckCorrectValue <<== PROVIDED
  - PRVD_ConstructWithArrayLen3_Advance_CheckCorrectValues_Start <<== PROVIDED
*/

TEST(TestParamConstructorPlusAdvanceStart,
	PRVD_ConstructWithArrayLen1_Advance_Start_CheckCorrectValue)
{
    // setup, execute
    char arr[] = { 'U' };
    Sequence s1(arr, 1);

    // execute, check
    s1.advance();
    EXPECT_FALSE(s1.has_current());
    s1.start();
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'U');
}

TEST(TestParamConstructorPlusAdvanceStartCurrent,
	PRVD_ConstructorWithArrayLength3_Advance_CheckCorrectValues_Start)
{
    // setup, execute
    char arr[3] = { 'U', 'P', 'Q' };
    Sequence s1(arr, 3);

    // execute, check
    s1.advance();
    EXPECT_EQ(s1.current(), 'P');
    s1.advance();
    EXPECT_EQ(s1.current(), 'Q');
    s1.advance();
    EXPECT_FALSE(s1.has_current());
    s1.start();
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'U');
}


/*
Test_Seq1_EqualNotEqual_Seq2,
  - STU_Both_Empty_Equivalent
  - STU_Both_Size_3_Same_Data_with_Same_Current_Index_Equivalent
  - STU_Both_Size_3_Same_Data_with_Different_Current_Index_Equivalent
  - STU_Seq1_Shorter_Not_Equivalent
  - STU_Seq1_Longer_Not_Equivalent
  - PRVD_Both_Size_5_Same_Except_First_Item_Not_Equivalent <<== PROVIDED
  - PRVD_Both_Size_5_Same_Except_Middle_Item_Not_Equivalent <<== PROVIDED
  - PRVD_Both_Size_5_Same_Except_Last_Item_Not_Equivalent <<== PROVIDED
*/

TEST(Test_Seq1_EqualEqual_Seq2,
    STU_Both_Empty_Equivalent)
{
    // setup
    char arr[] = { };
    Sequence s1(arr, 0);
    Sequence s2(arr, 0);

    // execute, check
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 != s2);
}

TEST(Test_Seq1_EqualEqual_Seq2,
    STU_Both_Size_3_Same_Data_with_Same_Current_Index_Equivalent)
{
    // setup
    char arr[] = { 'L', 'E', 'D'};
    Sequence s1(arr, 3);
    Sequence s2(arr, 3);

    // execute, check
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 != s2);
}


TEST(Test_Seq1_EqualEqual_Seq2,
    STU_Both_Size_3_Same_Data_with_Different_Current_Index_Equivalent)
{
    // setup
    char arr[] = { 'L', 'A', 'D'};
    Sequence s1(arr, 3);
    Sequence s2(arr, 3);
    s1.advance();

    // execute, check
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 != s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    STU__Seq1_Shorter_Not_Equivalent)
{
    // setup
    char arr[] = { 'L'};
    Sequence s1(arr, 1);
    char Arr[] = {'E', 'D', 'D'};
    Sequence s2(Arr, 3);

    // execute, check
    EXPECT_TRUE(s1 != s2);
    EXPECT_FALSE(s1 == s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    STU__Seq1_Longer_Not_Equivalent)
{
    // setup
    char arr[] = { 'K', 'E', 'V', 'I', 'N'};
    Sequence s1(arr, 5);
    char Arr[] = {'E', 'D'};
    Sequence s2(Arr, 2);

    // execute, check
    EXPECT_TRUE(s1 != s2);
    EXPECT_FALSE(s1 == s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    PRVD_Both_Size_5_Same_Except_First_Item_Not_Equivalent)
{
    // setup
    char arr[] = { 'a', 'b', 'c', 'd', 'e' };
    Sequence s1(arr, 5);
    arr[0] = 'X';
    Sequence s2(arr, 5);

    // execute, check
    EXPECT_TRUE(s1 != s2);
    EXPECT_FALSE(s1 == s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    PRVD_Both_Size_5_Same_Except_Middle_Item_Not_Equivalent)
{
    // setup
    char arr[] = { 'j', 'k', 'l', 'm', 'n' };
    Sequence s1(arr, 5);
    arr[2] = 'X';
    Sequence s2(arr, 5);

    // execute, check
    EXPECT_TRUE(s1 != s2);
    EXPECT_FALSE(s1 == s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    PRVD_Both_Size_5_Same_Except_Last_Item_Not_Equivalent)
{
    // setup
    char arr[] = { 'v', 'w', 'x', 'y', 'z' };
    Sequence s1(arr, 5);
    arr[2] = 'A';
    Sequence s2(arr, 5);

    // execute, check
    EXPECT_TRUE(s1 != s2);
    EXPECT_FALSE(s1 == s2);
}

/*
TestSequenceAppend
  - STU_Append_to_Empty
  - PRVD_Append_to_Length_1 <<== PROVIDED
  - STU_Append_to_Length_2
  - PRVD_Append_until_Filled_to_Capacity <<== PROVIDED
*/

TEST(TestSequenceAppend, STU_Append_to_Empty)
{
    // setup
    char arr[] = {  };
    Sequence s1(arr, 0);

    // execute
    s1.append('L');

    // check
    EXPECT_EQ(s1.size(), 1);
    EXPECT_TRUE(s1.has_current());
    s1.start();                    // go back to the front and verify
    EXPECT_EQ(s1.current(), 'L');  // first item is unchanged
}

TEST(TestSequenceAppend, PRVD_Append_To_Length_1)
{
    // setup
    char arr[] = { 'X' };
    Sequence s1(arr, 1);

    // execute
    s1.append('a');

    // check
    EXPECT_EQ(s1.size(), 2);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'a');
    s1.start();                    // go back to the front and verify
    EXPECT_EQ(s1.current(), 'X');  // first item is unchanged
}

TEST(TestSequenceAppend, STU_Append_To_Length_2)
{
    // setup
    char arr[] = { 'D', 'a' };
    Sequence s1(arr, 2);

    // execute
    s1.append('d');

    // check
    EXPECT_EQ(s1.size(), 3);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'd');
    s1.start();                    // go back to the front and verify
    EXPECT_EQ(s1.current(), 'D');  // first item is unchanged
}

TEST(TestSequenceAppend, PRVD_Append_until_Filled_to_Capacity)
{
    // setup
    Sequence s1;
    string chars_30 = "0123456789qwertyuiopasdfghjklm"; //  length 30

    // execute
    for (Sequence::size_type i = 0; i < CAPACITY; i++)
    {
        s1.append(chars_30[i]);
    }

    // check
    char arr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                   'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm' };
    Sequence correct_seq(arr, 30);
    EXPECT_EQ(s1, correct_seq);     // will call operator==
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'm');
    s1.advance();
    EXPECT_FALSE(s1.has_current());
}

/*
TestSequenceInsert
  - STU_Insert_into_Empty
  - PRVD_Insert_into_Length_1_with_CurrentIndex_0 <<== PROVIDED
  - PRVD_Insert_into_Length_1_with_CurrentIndex_1 <<== PROVIDED
  - STU_Insert_into_Length_5_with_CurrentIndex_0
  - STU_Insert_into_Length_5_with_CurrentIndex_2
  - STU_Insert_into_Length_5_with_CurrentIndex_4
  - STU_Insert_into_Length_5_with_CurrentIndex_5
  - PRVD_Insert_into_Length_CAPACITYminus1_with_CurrentIndex_CAPACITYminus2 <<== PROVIDED
  - PRVD_Insert_into_Length_CAPACITYminus1_with_CurrentIndex_0 <<== PROVIDED
*/

TEST(TestSequenceInsert, STU_Insert_into_Empty)
{
    // setup
    char arr[] = {  };
    Sequence s1(arr, 0);
    s1.start();

    // execute
    s1.insert('!');

    // check
    char Arr[] = { '!' };
    Sequence correct_seq(Arr, 1);
    EXPECT_EQ(s1.current(), '!');
    EXPECT_EQ(s1, correct_seq);
}

TEST(TestSequenceInsert, PRVD_Insert_into_Length_1_with_CurrentIndex_0)
{
    // setup
    Sequence s1;
    s1.append('%');

    // execute
    s1.insert('?');

    // check
    char arr[] = { '?', '%' };
    Sequence correct_seq(arr, 2);
    EXPECT_EQ(s1.current(), '?');
    EXPECT_EQ(s1, correct_seq);
}

TEST(TestSequenceInsert, PRVD_Insert_into_Length_1_with_CurrentIndex_1)
{
    // setup
    Sequence s1;
    s1.append('%');

    // execute
    s1.insert('?');

    // check
    char arr[] = { '?', '%' };
    Sequence correct_seq(arr, 2);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), '?');
    EXPECT_EQ(s1, correct_seq);    // will call operator==
}

TEST(TestSequenceInsert, STU_Insert_into_Length_5_with_CurrentIndex_0)
{
    // setup
    char arr[] = { 'H', 'a', 'p', 'p', 'y' };
    Sequence s1(arr, 5);
    s1.start();

    // execute
    s1.insert('!');

    // check
    char Arr[] = { '!','H', 'a', 'p', 'p', 'y' };
    Sequence correct_seq(Arr, 6);
    EXPECT_EQ(s1.current(), '!');
    EXPECT_EQ(s1, correct_seq);
}

TEST(TestSequenceInsert, STU_Insert_into_Length_5_with_CurrentIndex_2)
{
    // setup
    char arr[] = { 'L','a', 'r', 'e', 'n' };
    Sequence s1(arr, 5);
    s1.start();
    s1.advance();
    s1.advance();

    // execute
    s1.insert('u');

    // check
    char Arr[] = { 'L','a', 'u', 'r', 'e', 'n' };
    Sequence correct_seq(Arr, 6);
    EXPECT_EQ(s1.current(), 'u');
    EXPECT_EQ(s1, correct_seq);
}

TEST(TestSequenceInsert, STU_Insert_into_Length_5_with_CurrentIndex_4)
{
    // setup
    char arr[] = { 'L','O', 'V', 'E', '!' };
    Sequence s1(arr, 5);
    s1.start();
    s1.advance();
    s1.advance();
    s1.advance();
    s1.advance();

    // execute
    s1.insert('S');

    // check
    char Arr[] = { 'L','O', 'V', 'E', 'S', '!' };
    Sequence correct_seq(Arr, 6);
    EXPECT_EQ(s1.current(), 'S');
    EXPECT_EQ(s1, correct_seq);
}

TEST(TestSequenceInsert, STU_Insert_into_Length_5_with_CurrentIndex_5)
{
    // setup
    char arr[] = { 'A','M', 'B', 'E', 'R' };
    Sequence s1(arr, 5);
    s1.start();
    s1.advance();
    s1.advance();
    s1.advance();
    s1.advance();

    // execute
    s1.insert('R');

    // check
    char Arr[] = { 'A','M', 'B', 'E', 'R', 'R'};
    Sequence correct_seq(Arr, 6);
    EXPECT_EQ(s1.current(), 'R');
    EXPECT_EQ(s1, correct_seq);
}

TEST(TestSequenceInsert,
    PRVD_Insert_into_Length_CAPACITYminus1_CurrentIndex_CAPACITYminus2)
{
    // setup
    Sequence s1;
    string chars_29 = "0123456789qwertyuiopasdfghjkl"; // length 29
    for (Sequence::size_type i = 0; i < CAPACITY - 1; i++)
    {
        s1.append(chars_29[i]);
    }
    ASSERT_EQ('l', s1.current()); // current_index 28, cap minus 2

    // execute
    s1.insert('?');               // insert '?' at index 28

    // check
    char arr[30] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                     'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                     'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', '?', 'l' };
    Sequence correct_seq(arr, 30);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), '?');
    EXPECT_EQ(s1, correct_seq);
}

TEST(TestSequenceInsert,
    PRVD_Insert_into_Length_CAPACITYminus1_CurrentIndex_0)
{
    // setup
    Sequence s1;
    string chars_29 = "0123456789qwertyuiopasdfghjkl"; // length 29
    for (Sequence::size_type i = 0; i < CAPACITY - 1; i++)
    {
        s1.append(chars_29[i]);
    }
    s1.start(); // current index 0, length is CAP minus 1

    // execute
    s1.insert('?');  // '?' at index 0, all others shifted one right

    // check
    char arr[30] = { '?', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                     'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                     'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
    Sequence correct_seq(arr, 30);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), '?');
    EXPECT_EQ(s1, correct_seq);
}

/*
TestSequenceRemoveCurrent
  - PRVD_Remove_from_Length_1_CurrentIndex_0 <<== PROVIDED
  - PRVD_Remove_from_Length_2_CurrentIndex_0 <<== PROVIDED
  - PRVD_Remove_from_Length_2_CurrentIndex_1 <<== PROVIDED
  - STU_Remove_from_Length_5_CurrentIndex_0
  - STU_Remove_from_Length_5_CurrentIndex_2
  - STU_Remove_from_Length_5_CurrentIndex_4
  - PRVD_Remove_from_Length_CAPACITY_CurrentIndex_CAPACITYminus1 <<== PROVIDED
  - PRVD_Remove_from_Length_CAPACITY_CurrentIndex_0 <<== PROVIDED
*/

TEST(TestSequenceRemoveCurrent, PRVD_Remove_from_Length_1_CurrentIndex_0)
{
	// setup
    Sequence s1;
    s1.append('?');
    s1.start();

    // execute
    s1.remove_current();

    // check
    EXPECT_EQ(s1.size(), 0);
    EXPECT_FALSE(s1.has_current());
}

TEST(TestSequenceRemoveCurrent, PRVD_Remove_from_Length_2_CurrentIndex_0)
{
	// setup
    Sequence s1;
    s1.append('K');
    s1.append('9');
    s1.start();

    // execute
    s1.remove_current();

    // check
    EXPECT_EQ(s1.size(), 1);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), '9');
}

TEST(TestSequenceRemoveCurrent, PRVD_Remove_from_Length_2_CurrentIndex_1)
{
	// setup
    Sequence s1;
    s1.append('K');
    s1.append('9');
    s1.start();
    s1.advance();

    // execute
    s1.remove_current();

    // check
    EXPECT_EQ(s1.size(), 1);
    EXPECT_FALSE(s1.has_current());
    s1.start();
    EXPECT_EQ(s1.current(), 'K');
}

TEST(TestSequenceRemoveCurrent, STU_Remove_from_Length_5_CurrentIndex_0)
{
    // setup
    char arr[] = { 'H', 'a', 'p', 'p', 'y' };
    Sequence s1(arr, 5);
    s1.start();

    // execute
    s1.remove_current();

    // check
    EXPECT_EQ(s1.size(), 4);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'a');
}

TEST(TestSequenceRemoveCurrent, STU_Remove_from_Length_5_CurrentIndex_2)
{
    // setup
    char arr[] = { 'H', 'a', 'p', 'p', 'y' };
    Sequence s1(arr, 5);
    s1.start();
    s1.advance();
    s1.advance();

    // execute
    s1.remove_current();

    // check
    EXPECT_EQ(s1.size(), 4);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'p');
}

TEST(TestSequenceRemoveCurrent, STU_Remove_from_Length_5_CurrentIndex_4)
{
    // setup
    char arr[] = { 'H', 'a', 'p', 'p', 'y' };
    Sequence s1(arr, 5);
    s1.start();
    s1.advance();
    s1.advance();
    s1.advance();
    s1.advance();

    // execute
    s1.remove_current();

    // check
    EXPECT_EQ(s1.size(), 4);
    EXPECT_FALSE(s1.has_current());
}


TEST(TestSequenceRemoveCurrent,
    PRVD_Remove_from_Length_CAPACITY_CurrentIndex_CAPACITYminus1)
{
    // setup
    Sequence s1;
    string chars_30 = "QWERTYUIOPASDFGHJKLZXCVBN12345"; // length 30
    for (Sequence::size_type i = 0; i < CAPACITY; i++)
    {
        s1.append(chars_30[i]);
    }
    ASSERT_EQ('5', s1.current()); // current_index 29, cap minus 1

    // execute
    s1.remove_current();

    // check
    char arr[] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                     'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z',
                     'X', 'C', 'V', 'B', 'N', '1', '2', '3', '4' };
    Sequence correct_seq(arr, 29);
    EXPECT_FALSE(s1.has_current());
    EXPECT_EQ(s1, correct_seq);
}

TEST(TestSequenceRemoveCurrent,
    PRVD_Remove_from_Length_CAPACITY_CurrentIndex_0)
{
    // setup
    Sequence s1;
    string chars_30 = "QWERTYUIOPASDFGHJKLZXCVBN12345"; // length 30
    for (Sequence::size_type i = 0; i < CAPACITY; i++)
    {
        s1.append(chars_30[i]);
    }
    s1.start();
    ASSERT_EQ('Q', s1.current());

    // execute
    s1.remove_current();

    // check
    char arr[30] = { 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                     'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z',
                     'X', 'C', 'V', 'B', 'N', '1', '2', '3', '4', '5' };
    Sequence correct_seq(arr, 29);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'W');
    EXPECT_EQ(s1, correct_seq);
}

/*
Test_Seq1_PlusAssign_Seq2,
  - PRVD_Both_Typical           <<== PROVIDED
  - STU_Both_Empty
  - STU_Seq1_Empty_and_Seq2_Typical
  - STU_Seq1_Typical_and_Seq2_Empty
*/

TEST(Test_Seq1_PlusAssign_Seq2, PRVD_Both_Typical)
{
    // setup
    char arr1[] = { 'a', 'b', 'c', 'd' };
    char arr2[] = { 'X', 'Y' };
    Sequence s1(arr1, 4);
    s1.start();
    s1.advance();         // s1 current item is 'b'
    Sequence s2(arr2, 2);
    s2.start();           // s2 current item is 'X'

    // execute
    s1 += s2;

    // check
    char arr3[] = { 'a', 'b', 'c', 'd', 'X', 'Y' };
    Sequence correct_seq(arr3, 6);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'b'); // s1 current should still be 'b'
    EXPECT_EQ(s1, correct_seq);
}

TEST(Test_Seq1_PlusAssign_Seq2, STU_Both_Empty)
{
    // setup
    char arr1[] = {  };
    char arr2[] = {  };
    Sequence s1(arr1, 0);        
    Sequence s2(arr2, 0);        

    // execute
    s1 += s2;

    // check
    char arr3[] = {  };
    Sequence correct_seq(arr3, 0);
    EXPECT_FALSE(s1.has_current());
    EXPECT_EQ(s1, correct_seq);
}

TEST(Test_Seq1_PlusAssign_Seq2, STU_Seq1_Empty_and_Seq2_Typical)
{
    // setup
    char arr1[] = {  };
    char arr2[] = { 'H', 'i' };
    Sequence s1(arr1, 0);
    Sequence s2(arr2, 2);
    s2.start();

    // execute
    s1 += s2;

    // check
    char arr3[] = { 'H', 'i' };
    Sequence correct_seq(arr3, 2);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s2.current(), 'H'); // s2 current should still be 'b'
    EXPECT_EQ(s2, correct_seq);
}

TEST(Test_Seq1_PlusAssign_Seq2, STU_Seq1_Typical_and_Seq2_Empty)
{
    // setup
    char arr1[] = { 'e', 'm', 'p', 't', 'y' };
    char arr2[] = {  };
    Sequence s1(arr1, 5);
    s1.start();
    s1.advance();         // s1 current item is 'm'
    Sequence s2(arr2, 0);

    // execute
    s1 += s2;

    // check
    char arr3[] = { 'e', 'm', 'p', 't', 'y' };
    Sequence correct_seq(arr3, 5);
    EXPECT_TRUE(s1.has_current());
    EXPECT_EQ(s1.current(), 'm'); // s1 current should still be 'b'
    EXPECT_EQ(s1, correct_seq);
}

/*
TestSequenceStreamOutputOperator,
  - PRVD_Empty       <<== PROVIDED
  - PRVD_Typical     <<== PROVIDED
  - PRVD_Chaining    <<== PROVIDED
*/

TEST(TestSequenceStreamOutputOperator, PRVD_Empty)
{
    stringstream out;   // simulated output stream
    string correct;     // correct output

    // Setup sequence and store correct output
    Sequence seq;

    // Execute (put sequence into output stream)
    out << seq;

    // Check (check that contents of output stream are correct)
    correct = "Sequence: <empty sequence>\n";
    EXPECT_EQ(out.str(), correct);
}

TEST(TestSequenceStreamOutputOperator, PRVD_Typical)
{
    stringstream out;   // simulated output stream
    string correct;     // correct output

    // Setup sequence and store correct output
    char arr1[] = { 'h', 'i', '!' };
    Sequence seq(arr1, 3);

    // Execute (put sequence into output stream)
    out << seq;

    // Check (check that contents of output stream are correct)
    correct = "Sequence: h i !\n";
    EXPECT_EQ(out.str(), correct);
}

TEST(TestSequenceStreamOutputOperator, PRVD_Chaining)
{
    stringstream out;   // simulated output stream
    string correct;     // correct output

    // Setup sequence and store correct output
    Sequence seqA;      // empty sequence
    char arr1[] = { 'h', 'i', '!' };
    Sequence seqB(arr1, 3);      // sequence (h i !)

    // Execute (put sequence into output stream)
    out << seqA << seqB;

    // Check (check that contents of output stream are correct)
    correct = "Sequence: <empty sequence>\nSequence: h i !\n";
    EXPECT_EQ(out.str(), correct);
}

/*
TestSequenceStreamInputOperator,
  - PRVD_Read_Longer_into_Shorter <<== PROVIDED
  - PRVD_Read_Shorter_into_Longer <<== PROVIDED
  - PRVD_Read_Empty_into_Nonempty <<== PROVIDED
  - PRVD_Chaining <<== PROVIDED
*/

TEST(TestSequenceStreamInputOperator, PRVD_Read_Longer_into_Shorter)
{
    stringstream in;    // simulated input stream

    // Setup sequence and store the string representation of a new sequence
    char arr[] = { 'h', 'i', '!' };
    Sequence seq(arr, 3);

    in << "Sequence: b y e !\n";

    // Execute (read in sequence from the input stream)
    in >> seq;

    // Check (check that seq has been correctly modified)
    char arr2[] = { 'b', 'y', 'e', '!' };
    Sequence correct_seq(arr2, 4);
    EXPECT_EQ(seq.current(), 'b');
    EXPECT_EQ(seq, correct_seq);
}

TEST(TestSequenceStreamInputOperator, PRVD_Read_Shorter_into_Longer)
{
    stringstream in;    // simulated input stream

    // Setup sequence and store the string representation of a new sequence
    char arr[] = { 't', 'r', 'u', 'c', 'k' };
    Sequence seq(arr, 5);

    in << "Sequence: c a r\n";

    // Execute (read in sequence from the input stream)
    in >> seq;

    // check (check that seq has been correctly modified)
    char arr2[] = { 'c', 'a', 'r' };
    Sequence correct_seq(arr2, 3);
    EXPECT_EQ(seq.current(), 'c');
    EXPECT_EQ(seq, correct_seq);
}

TEST(TestSequenceStreamInputOperator, PRVD_Read_Empty_into_Nonempty)
{
    // Setup sequence and store the string representation of a new sequence
    stringstream in;    // simulated input stream
    in << "Sequence: <empty sequence>\n";
    char arr[] = { 's', 't', 'u', 'f', 'f' };
    Sequence seq(arr, 5);

    // Execute (read in sequence from the input stream)
    in >> seq;

    // Check (check that seq has been correctly modified)
    EXPECT_EQ(seq.size(), 0);
    EXPECT_FALSE(seq.has_current());
}

TEST(TestSequenceStreamInput, PRVD_Chaining)
{

    // Setup sequences and store the string representations
    stringstream in;    // simulated input stream
    in << "Sequence: a b c\n";
    in << "Sequence: x y z\n";
    Sequence seqA;
    Sequence seqB;

    // Execute (read in sequence from the input stream)
    in >> seqA >> seqB;

    // Check (check that both seqA & seqB have been correctly modified)
    char arrA[] = { 'a', 'b', 'c' };
    Sequence correct_seqA(arrA, 3);
    EXPECT_EQ(seqA.current(), 'a');
    EXPECT_EQ(seqA, correct_seqA);

    char arrB[] = { 'x', 'y', 'z' };
    Sequence correct_seqB(arrB, 3);
    EXPECT_EQ(seqB.current(), 'x');
    EXPECT_EQ(seqB, correct_seqB);
}

} // End namespace

// main() for testing -- boilerplate
int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
