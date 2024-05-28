#include <iostream>
#include <string>
 
std::string FloatToBin(const double x)
{
    std::string ret;
    unsigned int z = x;
    double r = x-z;
    
    // тут переводится целая часть
    while (z!=0)
    {
        ret=(char)(z%2+0x30)+ret; 
        z=z/2;
    }
    
    int counter=0;
    //тут дробная
    if (r!=0) ret+=".";
    while (r!=0)
    {
        z=r*2;
        ret+=(char)(z+0x30);
        r=r*2-z;
        ++counter;
        if (counter==10) // тут понимаем, процесс затянулся и число может быть вообще иррационально, поставим точки
          {
              ret+="...";
              break;
          }
    }
    return ret;
}
 
int main()
{
    std::string s;
    float a;
    std::cout << "Введите число Float в десятичной системе счисления: ";
    std::cin >> a;
    s = FloatToBin(a);
    std::cout << s << std::endl;
    return 0;
}