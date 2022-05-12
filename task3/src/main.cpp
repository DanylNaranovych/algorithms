#include <iostream>
typedef unsigned char uchar;

void printIDR(const void *object,  unsigned int OBJECT_SIZE)
{
	uchar *uobj = (uchar *) object;
	for (int i = 0; i < OBJECT_SIZE; ++i, ++uobj) {
		uchar mask = ~0; // маска вида 10..000000
		mask >>= 1;
		mask = ~mask;
		while (mask) {
			if (*uobj & mask)
				std::cout << '1';
			else
				std::cout << '0';
				mask >>= 1;
		}
		std::cout << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	int sign = -16;
	printIDR(&sign, sizeof (sign));
	return 0;
}