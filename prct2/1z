#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main ()
{
	time_t t = time(NULL);
	tm * ptm;
	ptm = gmtime(&t);
	int y = ptm->tm_year + 1900;
	int w = ptm->tm_wday;
	int m = ptm->tm_mon;
	string mass1[] = {"Январь", "Ферваль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
	string mass2[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
	cout << mass2[w] << " " << mass1[m] << " " <<ptm->tm_mday<< " " <<ptm->tm_hour<< ":" <<ptm->tm_min<< ":" <<ptm->tm_sec<< " " << y <<endl;
	return 0;
}
