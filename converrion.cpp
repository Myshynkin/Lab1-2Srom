#include "Bignumber.h"
#include <string>
#include <iostream>
#include "ourfunctions.h"
#include <vector>
using namespace std;
int convertion1(char a)
{
    if (a == '0') {
        return 0;
    }
    else if (a == '1') {
        return 0x1;
    }
    else if (a == '2') {
        return 0x2;
    }
    else if (a == '3') {
        return 0x3;
    }
    else if (a == '4') {
        return 0x4;
    }
    else if (a == '5') {
        return 0x5;
    }
    else if (a == '6') {
        return 0x6;
    }
    else if (a == '7') {
        return 0x7;
    }
    else if (a == '8') {
        return 0x8;
    }
    else if (a == '9') {
        return 0x9;
    }
    else if (a == 'A') {
        return 0xA;
    }
    else if (a == 'B') {
        return 0xB;
    }
    else if (a == 'C') {
        return 0xC;
    }
    else if (a == 'D') {
        return 0xD;
    }
    else if (a == 'E') {
        return 0xE;
    }
    else if (a == 'F') {
        return 0xF;
    }
    else if (a == 'a') {
        return 0xA;
    }
    else if (a == 'b') {
        return 0xB;
    }
    else if (a == 'c') {
        return 0xC;
    }
    else if (a == 'd') {
        return 0xD;
    }
    else if (a == 'e') {
        return 0xE;
    }
    else if (a == 'f') {
        return 0xF;
    }
    else {

        return -1;
    }
};
char anticonvertion(int a)
{
    string _16 = "0123456789abcdef";
    if (a < 16) {
        return _16[a];
    }
    else { return a; }
}
string conver_2(int a) 
{
    if (a == 0)
    {
        return "0000";
    }
    else if (a == 1)
    {
        return "0001";
    }
    else if (a == 2)
    {
        return "0010";
    }
    else if (a == 3)
    {
        return "0011";
    }
    else if (a == 4)
    {
        return "0100";
    }
    else if (a == 5)
    {
        return "0101";
    }
    else if (a == 6)
    {
        return "0110";
    }
    else if (a == 7)
    {
        return "0111";
    }
    else if (a == 8)
    {
        return "1000";
    }
    else if (a == 9)
    {
        return "1001";
    }
    else if (a == 0xa)
    {
        return "1010";
    }
    else if (a == 0xb) 
    {
        return "1011";
    }
    else if (a == 0xc) 
    {
        return "1100";
    }
    else if (a == 0xd) 
    {
        return "1101";
    }
    else if (a == 0xe) 
    {
        return "1110";
    }
    else if (a == 0xf) 
    {
        return "1111";
    }
}
Bignumber converfull(const Bignumber& a)
{
    string dwoi;
    Bignumber b = a;
    b = dw4_(b);
    for (int i=511; i >= 0; i--)
    {
        for (int j = 0; j <4; j++)
        {
            dwoi.push_back(conver_2(b.number[i])[j]);
        }
    }
    Bignumber A(dwoi);
    return A;
}
long long int _16chislo(int a,int b,int c,int d)
{
    long long result,a1,b1,c1,d1;
    a1 = 16 * 16 * 16 * a;
    b1 = 16* 16 * b;
    c1 = 16 * c;
    d1 =  d;
    result = a1 + b1 + c1 + d1;
    return result;
}
Bignumber dw16_(Bignumber a)
{
    int ind = 0,ind2=0,a1=0,a2=0,a3=0,a4=0;
    bool ucan = 0,nol=0;
    Bignumber b("0");
    for (int i = 0;i<512;i++) 
    {
        if (ind == 0)
        {
            a1 = a.number[i];
        }
        else if (ind == 1)
        {
            a2 = a.number[i];
        }
        else if (ind == 2)
        {
            a3 = a.number[i];
        }
        else if (ind == 3)
        {
            a4 = a.number[i];
            ucan = 1;
            ind = 0;
            nol = 1;
        }
        if(ucan == 1)
        {
            b.number[ind2] = _16chislo(a4, a3, a2, a1);
            ind2++;
            ucan = 0;
        }
       
     
        if (nol == 0)
        {
            ind++;
        }
        nol = 0;

    }
    return b;
}
Bignumber dw4_(Bignumber a)
{
    Bignumber b("0");
    int a1=0, a2=0, a3=0, a4=0,timea=0,ind=0,ind2=0;
    for (int i = 0; i < 512; i++)
    {
        timea = a.number[i];
        a4 = timea / (256 * 16);
        a3 = (timea - (256 * 16 * a4)) / 256;
        a2 = ((timea - (256 * 16 * a4) - a3 * 256)) / 16;
        a1 = ((timea - (256 * 16 * a4) - a3 * 256 - 16 * a2));
        for (int j = 0; j < 4; j++)
        {
            if (ind == 0)
            {
                b.number[j + ind2] = a1;
                ind++;
            }
            else if (ind == 1)
            {
                b.number[j + ind2] = a2;
                ind++;
            }
            else if (ind == 2)
            {
                b.number[j + ind2] = a3;
                ind++;
            }
            else if (ind == 3)
            {
                b.number[j + ind2] = a4;
                ind = 0;
            }
            
        }
        ind2=ind2+4;

    }
    return b;
}