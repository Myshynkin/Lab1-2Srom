#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int convertion1(char a);
char anticonvertion(int a);
class Bignumber
{
private:int number[2048];
public:Bignumber(string bignumber);
	friend Bignumber operator + (const Bignumber& a, const Bignumber& b);
	friend Bignumber operator - (const Bignumber& a, const Bignumber& b);
	friend Bignumber operator * (const Bignumber& a,const Bignumber& b);
	friend Bignumber operator / (const Bignumber& a, const Bignumber& b);
	friend Bignumber operator % (const Bignumber& a, const Bignumber& b);
	friend Bignumber operator ^ (const Bignumber& a, const Bignumber& b);
	friend bool operator == (const Bignumber& a, const Bignumber& b);
	friend bool operator > (const Bignumber& a, const Bignumber& b);
	friend bool operator < (const Bignumber& a, const Bignumber& b);
	friend bool operator <= (const Bignumber& a, const Bignumber& b);
	friend bool operator >= (const Bignumber& a, const Bignumber& b);
	friend Bignumber converfull(const Bignumber& a);
	friend Bignumber dw16_(Bignumber a);
	friend Bignumber dw4_(Bignumber a);
	Bignumber& operator=( const Bignumber& b);
	void incons();
	Bignumber LongMulOne(int one);
	Bignumber LongShiftI(int u);
	int BitLengh();
};