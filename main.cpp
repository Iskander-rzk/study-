#include <iostream>
#include <string>
#include <bitset>

int main()
{
	int n = 0, b = 0, c, N = 0, l = 0;
    signed short a;
	std::cin >> a;
	int i = 0;
	while (i < a.size())
	{
		if (a[i] == '0')
		{
			if (n > N) N = n;
			n = 0;
			b = 1;
		}
		else if (a[i] == '1' && b == 1) n++;
		i++;
	}
	std::cout << N;
	return 0;
}
