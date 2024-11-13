/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password1)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, four_letter_password1)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaab");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, three_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aAb");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, includes_space_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("a a");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, four_letter_password2)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aaAb");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, single_letter_password2)
{
	Password my_password;
	int actual = my_password.has_mixed_case("a");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, seven_letter_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("bdionsd");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, five_letter_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("DIONS");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, includes_digits_password1)
{
	Password my_password;
	int actual = my_password.has_mixed_case("323dfs");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, includes_digits_password2)
{
	Password my_password;
	int actual = my_password.has_mixed_case("323dFs");
	ASSERT_EQ(false, actual);
}