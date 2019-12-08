#if _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>

//-------------------------CALCULATE PRIMES WITHOUT THREADS--------------------------

void FindPrimes(unsigned int start, unsigned int end, std::vector<unsigned int>& vect)
{
	//Cycle through numbers while ignoring evens
	for (unsigned int x = start; x <= end; x += 2)
	{
		for (unsigned int y = 2; y < x; y++)
		{
			if ((x % y) == 0)
			{
				break;
			}
			else if((y + 1) == x)
			{
				vect.push_back(x);
			}
		}
	}
}

int main()
{
	std::vector<unsigned int> primeVect;

	//Get time before code starts executing
	unsigned int startTime = clock();

	FindPrimes(1, 100000, primeVect);
	for (auto i : primeVect)
	{
		std::cout << i << "\n";
	}

	//Get time after execution
	unsigned int endTime = clock();

	//print out the number of seconds by taking the difference
	//and dividing by the clock ticks per second
	std::cout << "Exceution Time :" << (endTime - startTime)/double(CLOCKS_PER_SEC) << std::endl;

	return 0;
}

//--------------------------------END CALCULATE PRIMES WITHOUT THREADS------------------------------