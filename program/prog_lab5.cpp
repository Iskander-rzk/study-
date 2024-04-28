#include <iostream>
#include <vector>

void show_object()
{

}


int main()
{
    int a = 1, number_object = 1;
    std::vector<int> Objects, year, address, size, sites;
    std::vector<std::vector<int>> sports;
    while (a != 0)
    {
        
        std::cout << "1. Choose the studium" << std::endl << "2. Add the studium" << std::endl << "0. Exit";
        std::cin >> a;
        if (a == 0) break;
        else if (a == 1)
        {
            for (int i = 0; i <= Objects.size(); i++)  std::cout << i << "." << Objects[i];

            std::cin >> number_object;
            if (number_object <= Objects.size())
            {
                std::cout << Objects[number_object] << std::endl;
                std::cout << "Year o building: " << year[number_object] << std::endl;
                std::cout << "Address: " << address[number_object] << std::endl;
                std::cout << "Capacity: " << size[number_object] << std::endl;

                for (int i = 0; i <= sports[number_object].size(); i++)
                {
                    std::cout << sports[number_object][i];
                }
            }
        }
    }
}