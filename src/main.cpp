#include <iostream>
#include <cstdlib>

#include "field.hpp"

// MAIN
int main()
{
	Field field(8, 10);
	field.FillMines();
	field.Print();

	return EXIT_SUCCESS;
};
