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

#include "cppcode.hpp"

std::string justify(const std::string& text, unsigned size)
{
	std::list<std::string> list; // lista wyrazów z bieżącej linii
	std::list<std::string> buffer; // lista wyrazów w tekście

	std::ostringstream outtext; // strumień wyjściowy
	std::stringstream intext; // strumień roboczy

	std::string tmp; // tymczasowy bufor na wyraz

	unsigned c = 0; // długość wyrazów + podstawowych spacji

	for (const auto& s : text) // iteruj litery
		if (std::isprint(s)) intext << s; // jesli znak jest drukowalny - dopisz go
		else intext << ' '; // jeśli nie jest - dopisz spacje zamiast niego

	while (std::getline(intext, tmp, ' ')) if (tmp.size()) // podziel ciąg na wyrazy
	{
		buffer.push_back(tmp); // dodaj wytaz do listy
	}

	while (buffer.size()) // powtarzać aż do wyczyszczenia bufora wejścia
	{
		const std::string& front = buffer.front(); // pierwszy wyraz z listy

		if (c + front.size() >= size && list.size()) // jeśli należy przejść do nowej linii
		{
			if (list.size() != 1) // jeśli jest więcej niż jeden wyraz
			{
				unsigned spaces = size - c; // spacje do dodania (wszystkie)
				unsigned bonus = spaces / (list.size() - 1); // spacje do dodania po każdym wyrazie
				unsigned extra = spaces % (list.size() - 1); // dodatkowe spacje tylko dla pierwszych wyrazów

				while (list.size() != 1) // dla wszystkich wyrazów z wyjątkiem ostatniego
				{
					outtext << list.front() << std::string(bonus + 1, ' '); // wpisz wyraz i wszystkie spacje

					if (extra) // gdy należy dodać ekstra spacje
					{
						outtext << ' ';

						spaces -= bonus + 1;
						extra -= 1;
					}
					else
					{
						spaces -= bonus;
					}

					list.pop_front(); // usuń wyraz z listy
				}

				outtext << std::string(spaces, ' ') <<  list.front() << std::endl; // wpisz ostatni wyraz
			}
			else
			{
				outtext << list.front() << std::endl; // gdy jest tylko jeden wyraz - wpisz go
			}

			list.clear(); // wyczyść liste
			c = 0; // wyzeruj licznik znaków
		}
		else // gdy nie trzeba jeszcze przechodzić do kolejnej linii
		{
			if (front.size() <= size) // jeśli wyraz mieści się w linii
			{
				list.push_back(front); // dodaj go do listy

				c += front.size() + (c > 0); // aktualizuj ilość znaków

				buffer.pop_front(); // usuń wyraz z bufora
			}
			else // jeśli wyraz nie mieści się w linii
			{
				list.push_back(front.substr(0, size - c - (c > 0))); // podziel wyraz (tak, aby pierwsza część zmieściła się w aktualnej linii)

				std::string buff = front.substr(size - c - (c > 0)); // pobierz resztę wyrazu

				c += front.size() + (c > 0); // aktualizuj licznik

				buffer.pop_front(); // usuń przetwarzany wyraz z bufora
				buffer.push_front(buff); // dodaj nieprzetworzoną część wyrazu na początek bufora
			}
		}
	}

	if (list.size()) // obsłuż wyrazy z ostatniej linijki - ostatnia linia nie jest justowana, zgodnie z zasadami
	{
		while (list.size() != 1)
		{
			outtext << list.front() << ' ';

			list.pop_front();
		}

		outtext << list.front() << std::endl;
	}

	return outtext.str();
}

unsigned fibonacci(unsigned n)
{
	switch (n)
	{
		case 0: return 0;
		case 1: return 1;
		default: return
			          fibonacci(n-1) +
			          fibonacci(n-2);
	}
}

// Utworzenie dowiązania o nazwie "cppcode"
BOOST_PYTHON_MODULE(cppcode)
{
	boost::python::def("justify", justify); // Dodaj funkcję "justify"
	boost::python::def("fibonacci", fibonacci); // Dodaj funkcję "fibonacci"
}
