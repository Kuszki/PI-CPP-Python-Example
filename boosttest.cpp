/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  {description}                                                          *
 *  Copyright (C) 2022  Łukasz "Kuszki" Dróżdż  lukasz.kuszki@gmail.com    *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the  Free Software Foundation, either  version 3 of the  License, or   *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This  program  is  distributed  in the hope  that it will be useful,   *
 *  but WITHOUT ANY  WARRANTY;  without  even  the  implied  warranty of   *
 *  MERCHANTABILITY  or  FITNESS  FOR  A  PARTICULAR  PURPOSE.  See  the   *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have  received a copy  of the  GNU General Public License   *
 *  along with this program. If not, see http://www.gnu.org/licenses/.     *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define BOOST_TEST_MODULE boosttest
#include <boost/test/included/unit_test.hpp>

#include "cppclass.hpp"
#include "cppcode.hpp"

BOOST_AUTO_TEST_SUITE(cpp_class)

BOOST_AUTO_TEST_CASE(constr)
{
	cppclass obj1(123), obj2;

	BOOST_CHECK_EQUAL(obj1.get_value(), 123);
	BOOST_CHECK_EQUAL(obj2.get_value(), 0);
}

BOOST_AUTO_TEST_CASE(setter)
{
	cppclass obj1(123), obj2;

	obj1.set_value(456);
	obj2.set_value(123);

	BOOST_CHECK_EQUAL(obj1.get_value(), 456);
	BOOST_CHECK_EQUAL(obj2.get_value(), 123);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(cpp_code)

BOOST_AUTO_TEST_CASE(textjust)
{
	using s_t = std::string::size_type;

	std::ifstream file("LICENSE");
	std::string buff;

	file.seekg(0, std::ios::end);
	buff.resize(file.tellg());
	file.seekg(0, std::ios::beg);

	file.read(buff.data(), buff.size());

	const auto str = justify(buff, 80);
	const auto len = str.length();

	for (s_t i = 0; i < len; ++i)
	{
		auto pos = str.find('\n', i);

		if (pos == std::string::npos ||
		    pos == len-1) break;

		BOOST_CHECK_EQUAL(pos - i, 80);

		i = pos;
	}
}

BOOST_AUTO_TEST_CASE(fibvalue)
{
	BOOST_CHECK_EQUAL(fibonacci(19), 4181);
	BOOST_CHECK_EQUAL(fibonacci(15), 610);
	BOOST_CHECK_EQUAL(fibonacci(12), 144);
	BOOST_CHECK_EQUAL(fibonacci(9), 34);
	BOOST_CHECK_EQUAL(fibonacci(1), 1);
}

BOOST_AUTO_TEST_SUITE_END()
