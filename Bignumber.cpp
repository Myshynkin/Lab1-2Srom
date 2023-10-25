#include "Bignumber.h"
#include <string>
#include <iostream>
#include "ourfunctions.h"

using namespace std;


 Bignumber:: Bignumber(string bignumber)
    {
     for (size_t i = 0; i < 2048; i++)
     {
         number[i] = 0;
     }
       
     for (size_t j = 0; j < bignumber.size(); j++)
            {
                if (convertion1(bignumber[bignumber.size() - 1 - j]) != -1)
                {
                    number[j] = convertion1(bignumber[bignumber.size()-1 - j]);
                }
                else 
                {
                 
                    cout << "Error. Incorrect number entered." << '\n';
                    Bignumber obj(imput(1));
                     break;
                }
            }


    }

Bignumber operator + (const Bignumber& a, const Bignumber& b) 
{
    Bignumber dod("0");
    int c = 0, m1;
    for (size_t i = 0; i<512; i++ ) 
    {
       m1 = a.number[i] + b.number[i]+c;
       if (m1 > 65535)
       {
           dod.number[i] = m1 - 65536;
           c = 1;
       }
       else
       {
           dod.number[i] = m1;
           c = 0;
       }
    }
    return dod;
}
Bignumber operator - (const Bignumber& a, const Bignumber& b)
{
    Bignumber vid("0");
    int d = 0, m1;
    for (size_t i = 0; i < 512; i++)
    {
        m1 = a.number[i] - b.number[i] - d;
        if (m1 >= 0)
        {
            vid.number[i] = m1;
            d = 0;
        }
        else
        {
            vid.number[i] = m1 + 65536;
            d = 1;
        }
    }
    return vid;
}
void Bignumber:: incons()
{
    Bignumber a = *this;
    a = dw4_(a);
    bool n = 0;
    for (size_t j = 0; j < 512; j++)
    {
        if (a.number[511 - j] != 0||n!=0)
        {
            n = 1;
            cout << anticonvertion(a.number[511 - j] );
        }
    }
    if (n == 0)
    {
        cout << '0';
    }
}
Bignumber& Bignumber:: operator=(const Bignumber& b)
{
    for (size_t j = 0; j < 512; j++)
    {
        number[j] = b.number[j];
    }
    return *this;
}

Bignumber Bignumber:: LongMulOne(int one)
{
    Bignumber res = *this;
    int c = 0, temp;
    for (size_t j = 0; j < 512; j++)
    {
        temp = res.number[j] * one + c;
        res.number[j] = temp & 65535;
        c = temp >> 16;
    }
    return res;
}
Bignumber Bignumber::LongShiftI(int u)
{
    Bignumber sdv = *this;
    if (u > 0) {
        for (size_t j = 511; j >= u; j--)
        {
            sdv.number[j] = sdv.number[j - u];
        }
        for (size_t k = u - 1; k > 0; k--)
        {

            sdv.number[k] = 0;
        }
        sdv.number[0] = 0;
    }
    return sdv;
}
Bignumber operator * (const Bignumber& a,const Bignumber& b)
{
    Bignumber umn("0"),temp("0"),ant("0");
    int c = 0;
    ant = a;
    for (size_t i = 0; i < 512; i++)
    {
        temp = ant.LongMulOne(b.number[i]).LongShiftI(i);
        umn = umn + temp;
    }
    return umn;
}
bool operator == (const Bignumber& a,const Bignumber& b)
{
    bool z=1;
    for (size_t i = 0; i < 512; i++)
    {
        if (a.number[i] != b.number[i])
        {
            z = 0;
            break;
        }
    }
    return z;

}
bool operator > (const Bignumber& a, const Bignumber& b)
{
    bool z = 0,z1 = 0, z2=0;
    for (size_t i = 511; i > 0; i--)
    {
        if ( a.number[i] > b.number[i])
        {
            z = 1;
            z1 = 1;
            break;
        }
        else if (a.number[i] < b.number[i])
        {
            z = 1;
            z1 = 0;
            break;

        }
    }
    if (z==0&&a.number[0] > b.number[0])
    {
        z = 1;
        z1 = 1;
    }
    else if (z == 0 && a.number[0] > b.number[0])
    {
        z = 1;
        z1 = 0;
    }
    return z1;

}
bool operator < (const Bignumber& a, const Bignumber& b)
{
    bool z = 0,z1 = 0,z2=0;
    for (size_t i = 511; i > 0; i--)
    {
        if (a.number[i] < b.number[i])
        {
            z = 1;
            z1 = 1;
            break;
        }
        else if (a.number[i] > b.number[i])
        {
            z = 1;
            z1 = 0;
            break;

        }
    }
    if (z == 0 && a.number[0] < b.number[0])
    {
        z = 1;
        z1 = 1;
    }
    else if (z == 0 && a.number[0] > b.number[0])
    {
        z = 1;
        z1 = 0;
    }
    
    return z1;

}
bool operator <= (const Bignumber& a, const Bignumber& b)
{
    if (a < b||a==b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool operator >= (const Bignumber& a, const Bignumber& b)
{
    if (a > b || a == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Bignumber::BitLengh()
{
    int lengh = 0,nul=0;
    for (int i = 511; i >= 0; i--)
    {
        if (number[i] != 0||nul==1)
        {
            lengh++;
            nul = 1;
        }

    }
    return lengh;
}
Bignumber operator / (const Bignumber& a, const Bignumber& b)
{
    Bignumber C("0"),R("0"),B("0"),Q("0");
    R = a; B = b;
    int k = B.BitLengh(),t;
        while (R >= B)
        {
            t = R.BitLengh();
            C = B.LongShiftI(t - k);
            if (C > R)
            {
                t = t - 1;
                C = B.LongShiftI(t - k);
            }
            R = R - C;
            if (t >= k)
            {
                Q.number[t - k]++;
            }
            if ( t < k) 
            {
                Q.number[0]++;
            }
        }
        return Q;
}
Bignumber operator % (const Bignumber& a, const Bignumber& b)
{
    Bignumber C("0"), R("0"), B("0"), Q("0");
    R = a; B = b;
    int k = B.BitLengh(), t;
    while (R >= B)
    {
        t = R.BitLengh();
        C = B.LongShiftI(t - k);
        if (C > R)
        {
            t = t - 1;
            C = B.LongShiftI(t - k);
        }
        R = R - C;
        if (t >= k)
        {
            Q.number[t - k]++;
        }
        if (t < k)
        {
            Q.number[0]++;
        }
    }
    return R;
}
Bignumber operator ^ (const Bignumber& a, const Bignumber& b)
{
    Bignumber B = converfull(b), C("1"),A("0");
    A = a;
    int M_1 = B.BitLengh();
    for (int i = M_1-1; i >= 0; i--) 
    {
        if (B.number[i] == 1)
        {
            C = C * A;
        }
        if (i != 0)
        {
            C = C * C;
            
        }

    }
    return C;
}