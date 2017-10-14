#include<string>
#include<iostream>
using namespace std;
class student {
public:
	int mu;
	student() {
		string n = "02128", x = "你猜", nam = "杨过"; double M = 10.0, E = 10.0, C = 10.0, t = 10.0, ave = 10.0;
		num = n;  name = nam;  xb = x; English = E;  Math = M;   Computer = C;  summ = t;  averagee = ave;
	};
	double sum();
	double average();
	double print();
	void get_reg_num();
	void set_stu_inf();
	void set_mu() { cin >> mu; };
	string seach(string n);
	void update_stu_inf(string nn);
	void add_stu_inf();
	double all_stu_sum();
	double all_stu_ave() {
		return all_stu_sum() / mu;
	};
	string max();
private:
	string num; string name; string xb; double Math; double English; double Computer; double summ; double averagee;
};
student *stu = new student["02128", "你猜", "杨过", 64, 56, 74];
double student::sum() { return(English + Math + Computer); }
double student::average() { return(sum() / 3.0); }
double student::print() {
	cout << num << "\t" << name << "\t" << xb << "\t" << Math << "\t" << English << "\t" << Computer << "\t" << sum() << "\t" << average() << endl;
	return 0;
}
double student::all_stu_sum() {
	double allt = 0;
	for (int i = 0; i<mu; i++) {
		allt = allt + (this+i)->sum();
	}
	return allt;
};
string student::max() {
	string ii;
	double all_summ;
	for (int i = 0; i<mu; i++) {
		if (this->sum()>(this+1)->sum()) {
			all_summ = this->sum(); ii = this->num;
		}
		else { all_summ = (this+1)->sum(); ii = (this + 1)->num; };
	}
	cout <<"最高总成绩为" <<all_summ << endl;
	return ii;
};
void student::get_reg_num() {
	string inname;
	cin >> inname;
	for (int i = 0; i < mu; i++) {
		if (stu[i].name == inname)
		{
			cout << stu[i].num << endl;
		}
	}
}
void student::set_stu_inf() {
	cout << "请注意！该功能只在第一次使用！" << endl;
    string n, nam, x; double M, E, C;
		for (int i = 0; i<mu; i++) {
			cout << "第" << i + 1 << "个:" << endl;
			cout << "学号："; cin >> n;
			cout << "姓名："; cin >> nam;
			cout << "性别："; cin >> x;
			cout << "数学："; cin >> M;
			cout << "英语："; cin >> E;
			cout << "计算机："; cin >> C;
			stu[i].num = n;
			stu[i].name = nam;
			stu[i].xb = x;
			stu[i].Math = M;
			stu[i].English = E;
			stu[i].Computer = C;
		}
}
void student::add_stu_inf() {
	if (mu<0) { cout << "请先用功能1！" << endl; exit; }
	else {
		int addn;
		string n, nam, x; double M, E, C;
		cout << "需要添加的人数："; cin >> addn;
		for (int i = mu; i<mu + addn; i++) {
			cout << "第" << i + 1 << "个:" << endl;
			cout << "\t学号："; cin >> n;
			cout << "\t姓名："; cin >> nam;
			cout << "\t性别："; cin >> x;
			cout << "\t数学："; cin >> M;
			cout << "\t英语："; cin >> E;
			cout << "\t计算机："; cin >> C;
			stu[i].num = n;
			stu[i].name = nam;
			stu[i].xb = x;
			stu[i].Math = M;
			stu[i].English = E;
			stu[i].Computer = C;
		}
		mu = mu + addn;
	}
}
string student::seach(string nn) {
	for (int i = 0; i < mu; i++) {
		if (stu[i].num == nn)
		{
			stu[i].print();
		}
	}
	char *over = "Over";
	return over;
}
void student::update_stu_inf(string nn) {
	string n, nam, x; double M, E, C;
	for (int i = 0; i < mu; i++) {
		if (stu[i].num == nn)
		{
			cout << "\t姓名："; cin >> nam;
			cout << "\t性别："; cin >> x;
			cout << "\t数学："; cin >> M;
			cout << "\t英语："; cin >> E;
			cout << "\t计算机："; cin >> C;
			stu[i].name = nam;
			stu[i].xb = x;
			stu[i].Math = M;
			stu[i].English = E;
			stu[i].Computer = C;
		}
	}
}
void main() {
	string nn;
	int ch;
	do {
		cout << "\t1.输入学生信息" << endl
			<< "\t2.输出全部学生信息" << endl
			<< "\t3.通过姓名找学号" << endl
			<< "\t4.通过学号找信息" << endl
			<< "\t5.修改学生信息" << endl
			<< "\t6.添加学生信息" << endl
			<< "\t7.算所有的总成绩和平均成绩和最高成绩" << endl
			<< "\t8.退出" << endl;
		cout << "功能选择:";
		cin >> ch;
		cout << "---------------BEGIN--------------------" << endl;
		if (ch == 1) {
			cout << "需要输入多少条信息？:";
			stu[0].set_mu();
			cout << "现在输入学生信息:" << endl;
			stu[0].set_stu_inf();
		};
		if (ch == 2) {
			cout << "学号" << "\t" << "姓名" << "\t" << "性别" << "\t" << "数学" << "\t" << "英语" << "\t" << "计算机" << "\t" << "总分" << "\t" << "平均分" << endl;
			for (int i = 0; i<stu[0].mu; i++) {
				stu[i].print();
			}
		};
		if (ch == 3) {
			cout << "现在你可以通过姓名找学号：";
			stu[0].get_reg_num();
		};
		if (ch == 4) {
			cout << "现在你可以通过学号找到该学生的全部信息：";
			cin >> nn;
			stu[0].seach(nn);
		};
		if (ch == 5) {
			cout << "修改学生信息：学号：";
			stu[0].update_stu_inf(nn);
		};
		if (ch == 6) {
			stu[0].add_stu_inf();
		};
		if (ch == 8) {
			exit(1);
		};
		if (ch == 7) {
			cout << "总成绩：" << stu[0].all_stu_sum() << " 平均成绩：" << stu[0].all_stu_ave() << " 最高成绩者学号：" << stu[0].max() << endl;
		};
		cout << "----------------END-------------------" << endl;
	} while (ch != 8);
}
