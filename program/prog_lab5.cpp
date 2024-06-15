#include <iostream>
#include <vector>
#include <fstream>

/**
 * @brief 
 * 
 * @return int 
 */


int main()
{
    int a = 1, number_object = 1, n;
    std::string b, line;
    std::vector<std::string> Objects, year, address, size, sites, local_sports;
    std::vector<std::vector<std::string>> sports;

    std::ifstream in("Objects.txt"); // окрываем файл для чтения
    
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
            Objects.push_back(line);
        }
    }

    std::ifstream in("year.txt"); // окрываем файл для чтения
    
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
            year.push_back(line);
        }
    }
 

    std::ifstream in("address.txt"); // окрываем файл для чтения
    
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
            address.push_back(line);
        }
    }

    std::ifstream in("sites.txt"); // окрываем файл для чтения
    
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
            sites.push_back(line);
        }
    }

    std::ifstream in("sports.txt"); // окрываем файл для чтения
    
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
            Objects.push_back(line);
        }
    }
 

    
 
    
    while (a != 0)
    {
        
        std::cout << "1. Choose the studium" << std::endl << "2. Add the studium" << std::endl << "3. Delete the studium" << std::endl << "0. Exit" << std::endl;
        std::cin >> a;
        
        if (a == 0) break;
        else if (a == 1)
        {
            for (int i = 1; i < Objects.size()+1; i++)  std::cout << i << "." << Objects[i-1] << std::endl;
            std::cout << "0. Exit" << std::endl;
            std::cin >> number_object;
            if (a == 0) break;
            number_object--;
            if (number_object < Objects.size())
            {
                std::cout << Objects[number_object] << std::endl;
                std::cout << "Year of building: " << year[number_object] << std::endl;
                std::cout << "Address: " << address[number_object] << std::endl;
                std::cout << "Capacity: " << size[number_object] << std::endl;
                std::cout << "Sites: " << sites[number_object] << std::endl; 
                std::cout << "Sports: ";
                for (int i = 0; i < sports[number_object].size(); i++)
                {
                    std::cout << sports[number_object][i];
                }
                std::cout << std::endl;
            }
        }
        else if (a == 2)
        {
            
            std::cout << "Enter the name of stadium" << std::endl;
            std::cin >> b;
            Objects.push_back(b);
            
            std::cout << "Enter the year of building" << std::endl;
            std::cin >> b;
            year.push_back(b);

            std::cout << "Enter the address" << std::endl;
            std::cin >> b;
            address.push_back(b);

            std::cout << "Enter capacity" << std::endl;
            std::cin >> b;
            size.push_back(b);

            std::cout << "Enter sites" << std::endl;
            std::cin >> b;
            sites.push_back(b); 

            std::cout << "Enter the count of sports" << std::endl;
            std::cin >> n;
            for (int i = 0; i <= n-1; i++)
            {
                std::cin >> b;
                local_sports.push_back(b);
            }
            sports.push_back(local_sports);
        }
        else if (a == 3)
        {
            for (int i = 1; i < Objects.size()+1; i++)  std::cout << i << "." << Objects[i-1] << std::endl;
            std::cout << "0. Exit" << std::endl;
            std::cin >> number_object;
            if (a == 0) break;
            number_object--;
            if (number_object < Objects.size())
            {
                Objects.erase(Objects.begin() + number_object);
                year.erase(year.begin() + number_object);
                address.erase(address.begin() + number_object);
                sites.erase(sites.begin() + number_object);
                sports.erase(sports.begin() + number_object);
            }
        }
    }
}