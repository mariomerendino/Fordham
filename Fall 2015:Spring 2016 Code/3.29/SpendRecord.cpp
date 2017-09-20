#include <iostream>
#include "SpendRecord.h"

void SpendRecord::print(ostream & stream) const
{
	DollarAmount::print(stream);
	stream << description;
}

void SpendRecord::input (istream & stream)
{
	DollarAmount::input (stream);
	if (!isTerminator())
		stream >> description;
}


istream & operator>> (istream & input, SpendRecord & obj)
{
	obj.input (input);
	return input;
}

ostream & operator << (ostream & output, const SpendRecord & obj)
{
	obj.print(output);
	return output;
}

