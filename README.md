[![CMake](https://github.com/Kuszki/PI-CPP-Python-Example/actions/workflows/cmake.yml/badge.svg)](https://github.com/Kuszki/PI-CPP-Python-Example/actions/workflows/cmake.yml)
# PI-CPP-Python-Example
Przykład wykorzystania kodu z języka C++ w Pythonie.

W przykładzie pokazano w jaki sposób zbudować biblioteki współdzielone
zaimplementowane w języku C++, a następnie wykorzystać je w programie
napisanym w języku Python.

Przykład obejmuje tworzenie bindów do funkcji oraz przykładowej klasy.

W przykładzie zawarto również 4 testy jednostkowe w standardzie CTest:
- test modułu `cppcode` napisany w języku C++,
- test modułu `cppcode` użytego w programie Pythona,
- test modułu `cppclass` użytego w programie Pythona,
- test w standardzie `boost` klasy CPP oraz funkcji CPP.

## Wymagania
- libboost-python: `apt install libboost-python-dev`,
- libboost-test: `apt install libboost-test-dev`,
- python: `apt install python3` (wersja 2 teź jest wspierana).

## Budowanie
- Klonowanie projektu: `git clone https://github.com/Kuszki/PI-CPP-Python-Example`,
- Utworzenie katalogu budowania i przejście do niego: `mkdir build && cd build`,
- Konfiguracja CMake: `cmake ../PI-CPP-Python-Example -DCMAKE_BUILD_TYPE=Release`,
- Budowanie: `cmake --build .` (uniwersalne) lub `make` bądź `nmake` (zaleznie od platformy),
- Testowanie: `ctest` (opcjonalne - uruchamia wszystkie zdefiniowane testy).

## Przydatne linki
- [Więcej przykładów](https://github.com/TNG/boost-python-examples)
- [Dokumentacja](https://www.boost.org/doc/libs/1_78_0/libs/python/doc/html/index.html)
- [Tutorial](https://www.boost.org/doc/libs/1_78_0/libs/python/doc/html/tutorial/index.html)
