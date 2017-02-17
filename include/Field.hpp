#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>

typedef std::vector< std::vector<bool> > Matrix;

class Field
{
private:
	Matrix matrix;

public:
	// CONSTRUCTOR
	Field(unsigned int size);
};

#endif
