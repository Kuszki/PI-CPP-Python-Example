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

#include <iostream>
#include <fstream>

#include "cppclass.hpp"
#include "cppcode.hpp"

using namespace std;

int main(int argc, char* argp[])
{
	using s_t = std::string::size_type;

	if (fibonacci(19) != 4181) return -1;

	std::ifstream file("LICENSE");
	std::string buff;

	file.seekg(0, std::ios::end);
	buff.resize(file.tellg());
	file.seekg(0, std::ios::beg);

	file.read(buff.data(), buff.size());

	const auto str = justify(buff, 80);
	const auto len = str.length();

	std::cout << str << std::endl;

	for (s_t i = 0; i < len; ++i)
	{
		auto pos = str.find('\n', i);

		if (pos == std::string::npos || pos == len-1) break;
		else if (pos - i != 80) return -1;
		else i = pos;
	}

	return 0;
}
