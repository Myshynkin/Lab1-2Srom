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
    return _16[a];

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
    for (int i=511; i >= 0; i--)
    {
        for (int j = 0; j <4; j++)
        {
            dwoi.push_back(conver_2(a.number[i])[j]);
        }
    }
    Bignumber A(dwoi);
    return A;
}