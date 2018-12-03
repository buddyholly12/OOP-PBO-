#include"CPecahan.h"
#include<stdio.h>

CPecahan::CPecahan(int pb, int py)
{
	pembilang = pb;
	penyebut = py;
	if(penyebut == 0)
		penyebut = 1;
}

int CPecahan::GetPembilang() const
{
	return pembilang;
}

int CPecahan::GetPenyebut() const
{
	return penyebut;
}

void CPecahan::SetPembilang(int n)
{
	pembilang = n;
}

void CPecahan::SetPenyebut(int n)
{
	if(n!=0)
		penyebut = n;
}

void CPecahan::Println() const
{
	printf("%d/%d\n",pembilang,penyebut);
}


CPecahan CPecahan::operator+(const CPecahan &p) const
{
	CPecahan hasil;
	hasil.penyebut = penyebut * p.penyebut;
	hasil.pembilang = pembilang * p.penyebut 
						+ p.pembilang * penyebut;

	return hasil;
}

double CPecahan::ToDouble() const
{
	return (double)pembilang/penyebut;
}

bool CPecahan::operator>(const CPecahan &p) const
{
	return ToDouble() > p.ToDouble();
}

void CPecahan::operator+=(const CPecahan &p)
{
	int py = penyebut * p.penyebut;
	int pb = pembilang * p.penyebut 
						+ p.pembilang * penyebut;
}

CPecahan CPecahan::operator++()
{
	pembilang += penyebut;

	return (*this);
}

CPecahan CPecahan::operator++(int)
{
	CPecahan hasil(*this);
	pembilang += penyebut;
	return hasil;
}

CPecahan CPecahan::operator =(const CPecahan &p)
{
	this->pembilang = p.pembilang;
	this->penyebut = p.penyebut;
	return (*this);
}