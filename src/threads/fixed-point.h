#ifndef THREADS_TIMER_POINT_H
#define THREADS_TIMER_POINT_H

/* This file implements fixed point arithmetic for the pintos kernel. */

#define F (1<<14)
#define MAX_INT ((1<<31-1))
#define MIN_INT (-(1<<31))

int int_to_fixp(int n);

int fixp_to_int(int x);
int fixp_to_int_round(int x);

int add_fixp(int x, int y);
int add_fixp_int(int x, int n);

int sub_fixp(int x, int y);
int sub_fixp_int(int x, int n);

int mult_fixp(int x, int y);
int mult_fixp_int(int x, int n);

int div_fixp(int x, int y);
int div_fixp_int(int x, int n);

int int_to_fixp(int n)
{
	return n * F;
}

int fixp_to_int(int x)
{
	return x / F; 
}

int fixp_to_int_round(int x)
{
	if(x>=0)
		return (x + F / 2) / F;
	else 
		return (x - F / 2) / F;
}

int add_fixp(int x, int y)
{
	return x + y;
}

int add_fixp_int(int x, int n)
{
	return x + n * F;
}

int sub_fixp(int x, int y)
{
	return x - y;
}
int sub_fixp_int(int x, int n)
{
	return x - n * F;
}

int mult_fixp(int x, int y)
{
	return ((int64_t) x) * y / F;
}

int mult_fixp_int(int x, int n)
{
	return x * n;
}

int div_fixp(int x, int y)
{
	return ((int64_t) x) * F / y;
}

int div_fixp_int(int x, int n)
{
	return x / n;
}

#endif /* threads/fixed-point.h */
