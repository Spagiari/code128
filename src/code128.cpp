#include <string>
#include <iostream>
#include <sstream>

std::string sCode128AUTO(const char * sCodeBar);

int main ()
{
    std::string scode;
    std::cin >> scode;

    std::cout << sCode128AUTO(scode.c_str()) << std::endl;
}

//Implementa o Code 128 AUTO especializado para o cenário focus.
////C->B e B->C. Não Utiliza Code 128 A.
std::string sCode128AUTO(const char * sCodeBar)
{
    std::stringstream sCode("");
    char cAux;

    int iType = 0;

    int i=0;
    while (sCodeBar[i])
    {
        //CODE 128C
        if (sCodeBar[i] >= 0x30 && sCodeBar[i] <= 0x39)
        {
            if (iType == 0)
            {
                iType = 4;
                cAux = sCodeBar[i];
            }
            else if (iType == 4)
            {
                iType = 3;
                sCode << ">;" << cAux << sCodeBar[i];
            }
            else if (iType == 3)
            {
                iType = 5;
                cAux = sCodeBar[i];
            }
            else if (iType == 2)
            {
                iType = 6;
                cAux = sCodeBar[i];
            }
            else if (iType == 5)
            {
                iType = 3;
                sCode << cAux << sCodeBar[i];
            }
            else if (iType == 6)
            {
                iType = 3;
                sCode << ">5" << cAux << sCodeBar[i];
            }
        }
        //Code 128B
        else if ((sCodeBar[i] >= 0x41 && sCodeBar[i] <= 0x5A) || (sCodeBar[i] >= 0x61 && sCodeBar[i] <= 0x7A) || sCodeBar[i] == 0x2E)
        {
            if (iType == 0)
            {
                iType = 2;
                sCode  <<  ">:" <<  sCodeBar[i];
            }
            else if (iType == 4)
            {
                iType = 2;
                sCode << ">:" << cAux << sCodeBar[i];
            }
            else if (iType == 2)
            {
                sCode  <<  sCodeBar[i];
            }
            else if (iType == 3)
            {
                iType = 2;
                sCode << ">6" << sCodeBar[i];
            }
            else if (iType == 5)
            {
                iType = 2;
                sCode << ">6" << cAux << sCodeBar[i];
            }
            else if (iType == 6)
            {
                iType = 2;
                sCode << cAux << sCodeBar[i];
            }
        }
        ++i;
    }
    if (iType == 6)
    {
        sCode << cAux;
    }
    else if (iType == 5)
    {
        sCode << ">6" << cAux;
    }
    else if (iType == 4)
    {
        sCode << ">:" << cAux;
    }

    return sCode.str();
}
