#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;
constexpr __int64 total = 9e18 + 0.22e18;
int factor(int x)
{
	int fact = 1;
	for (int i = x; i > 0; i--)
	{
		fact *= i;
	}
	return fact;
}
void primefactor(int x)
{
	for (__int64 i = 2; i < total; i++)
	{
		vector<pair<int, int>>vect;
		int answer;
		__int64 number = i;
		int counter = 0;
		int count = 0;
		while (number % 2 == 0)
		{
			count++;
			counter++;
			number /= 2;
		}
		if (counter > 0)
		{
			vect.push_back(make_pair(2, counter));
		}
		for (int j = 3; j <= sqrt(number); j +=2)
		{
			counter = 0;
			while (number % j == 0)
			{
				count++;
				counter++;
				number /= j;
			}
			if (counter > 0)
			{
				vect.push_back(make_pair(j, counter));
			}
		}
		if (number > 2)// for handling if x is already a prime
		{
			count++;
			vect.push_back(make_pair(number, 1));
		}
		answer = factor(count);
		for (int i = 0; i < vect.size(); i++)
		{
			answer /= factor(vect[i].second);
		}
		if (x == answer)
		{
			cout << i << endl;
			break;
		}

	}
}
int main()
{
	int ways;
	int cases;
	do
	{
		cin >> cases;
	} while (cases > 1000);
	for (int i = 0; i < cases; i++)
	{
		cin >> ways;
		primefactor(ways);
	}
	return 0;
}


