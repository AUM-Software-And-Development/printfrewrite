#include <stdio.h>

struct displaydelegate {
void(* d)();
void * darg1;
void * darg2;
int darg3;
int darg4;
};

void setdargs(struct displaydelegate * delegate, void (*function), void * param1, void * param2,
	      int param3, int param4)
{
	delegate->d = function;
	delegate->darg1 = param1;
        delegate->darg2 = param2;
        delegate->darg3 = param3;
        delegate->darg4 = param4;
}

void dnl()
{
	printf("\n");
}

void dstr(void * var, void * tailend)
{
	printf((const char *)var);
	printf((const char *)tailend);
}

void dint(int i, void * tailend)
{
	printf("%i", i);
	printf((const char *)tailend);
}

int main()
{
	struct displaydelegate nl;
	struct displaydelegate string;
	struct displaydelegate integer;
	setdargs(&nl, dnl, NULL, NULL, 0, 0);
	setdargs(&string, dstr, "string1", "\n", 0, 0);
	setdargs(&integer, dint, NULL, NULL, 1, 2);
	
	nl.d(); string.d(string.darg1, string.darg2);
	nl.d(); integer.d(integer.darg3, "\n");
	nl.d(); integer.d(1000, "\n"); nl.d();

	return 0;
}
