#include<iostream>
using namespace std;
class Time
{
public:
	void set(int hour, int min, int second) {
		if (0 <= hour <= 24 && 0 <= min <= 60 && 0<=second<=60) {
			h = hour; m = min; s = second;
		}
		else
		{
			cout << "you inputed a mistake!" << endl;
		}
	}
	void print() {
		cout << h << ':' << m << ':' << s << endl;
	}

private:
	int h, m, s;
};

int main() {
	Time a;
	int hour, min, second;
	cin >> hour; cin >> min; cin >> second;
	a.set(hour, min, second);
	a.print();
	system("pause");
}