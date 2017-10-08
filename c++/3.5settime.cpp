#include<iostream>
using namespace std;
class Time
{
public:
	void set(int hour, int min, int second) {
		if (hour <= 23 && min <= 59 && second <= 59 && hour*min*second >= 0) {
			h = hour; m = min; s = second;
		}
		else
		{
			cout << "You inputed a bad date!" << endl;
			h = -1;
		}
	}
	void print() {
		if (h == -1) { exit; }
		else { cout << h << ':' << m << ':' << s << endl; }
	}

private:
	int h, m, s;
};

int main() {
	Time a;
	int hour, min, second;
	cout << "Please input date in one by one!" << endl;
	cin >> hour; cin >> min; cin >> second;
	a.set(hour, min, second);
	a.print();
	system("pause");
}