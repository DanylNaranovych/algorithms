#include <iostream>
typedef unsigned char uchar;
struct education {
	struct {
		union {
			bool exam;
			bool grad_work;
		} admis_meth_to_magistr;
	} magistr;
	struct {
		union {
			bool exam;
			bool grad_work;
		} admis_meth_to_bach;
	} bach;
};

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
	struct education my;
	my.magistr.admis_meth_to_magistr.grad_work = true;
	my.bach.admis_meth_to_bach.exam = true;
	printf("Структура №1\n");
	printIDR(&my, sizeof (my));
	return 0;
}