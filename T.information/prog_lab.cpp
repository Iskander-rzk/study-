#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>


int main() 
{
    double chance[8] {0.2, 0.18, 0.14, 0.12, 0.12, 0.1, 0.08, 0.06};
      
    double everage_number = 0;
    double entropy = 0, n, redundancy;
    for (int i; i < 8; i++)
    {
        n = chance[i];
        everage_number = (i + 1)*n + everage_number;
        entropy = entropy - n*(log(n)/log(2.0));
        redundancy = 1 - (entropy / (log(8)/log(2.0)));
    }
    
    std::cout << everage_number << std::endl;
    std::cout << entropy << std::endl;
    std::cout << redundancy << std::endl;
    

    return 0;
}