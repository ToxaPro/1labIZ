#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int RandomGenerator()
{
	static mt19937 rnd((uint64_t)&rnd);
	uniform_int_distribution<int> d(-1000000000,1000000000);
	return d(rnd);
}

int main(int argc, char **argv)
{
	vector<int> f;
	for(int i=0; i<10000000; i++) {
		f.push_back(rand() % 1000000000 -1000000000);
	}
	steady_clock::time_point tp1 = steady_clock::now();
	std::stable_sort(f.begin(), f.end());
	steady_clock::time_point tp2 = steady_clock::now();
	milliseconds ms1 = duration_cast<milliseconds>(tp2 - tp1);
	
	vector<int> v(10000000);
	generate(v.begin(),v.end(),RandomGenerator);
	steady_clock::time_point tp3 = steady_clock::now();
	std::sort(v.begin(), v.end());
	steady_clock::time_point tp4 = steady_clock::now();
	milliseconds ms2 = duration_cast<milliseconds>(tp4 - tp3);
	
	vector<int> w(10000000);
	w.assign(v.begin(), v.end());
	cout<<(double)ms1.count()/1000<<" cек.\n";
	cout<<(double)ms2.count()/1000<<" cек.\n";
	return 0;
}