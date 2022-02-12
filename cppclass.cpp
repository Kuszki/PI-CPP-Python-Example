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

#include "cppclass.hpp"

cppclass::cppclass(int value)
     : m_value(value) {}

cppclass::~cppclass(void) {}

int cppclass::get_value(void) const
{
	return m_value;
}

void cppclass::set_value(int value)
{
	m_value = value;
}

// Utworzenie dowiązania "cppclass"
BOOST_PYTHON_MODULE(cppclass)
{
	// Dodanie do dowiązania klasy "cppclass"
	boost::python::class_<cppclass>("cppclass")
	          .def(boost::python::init<int>()) // Dodanie konstruktora
	          .def("get_value", &cppclass::get_value) // Dodanie metody "get_value"
	          .def("set_value", &cppclass::set_value); // Dodanie metody "set_value"
}
