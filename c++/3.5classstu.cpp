#include<string>
#include<iostream>
using namespace std;
class student {
public:
	int mu = 3;
	student(){
		string n = "02128", nam = "杨过"; double M = 10.0, E = 10.0, C = 10.0, t = 10.0, ave = 10.0;
		num = n;  name = nam;  English = E;   Math = M;   Computer = C;  summ = t;  averagee = ave;
	};
	double sum();
	double average();
	double print();
	void get_reg_num();
	void set_stu_inf();
	void set_mu() { cin >> mu; };
	string seach(string n);
private:
	string num; string name; double Math; double English; double Computer; double summ; double averagee;
};
student::student(string n, string nam, double M, double E, double C, double t = 10.0, double ave = 10.0) {
	num = n;  name = nam;  English = E;   Math = M;   Computer = C;  summ = t;  averagee = ave;
}
student *stu = new student["02128", "杨过", 64, 56, 74];
double student::sum() { return(English + Math + Computer); }
double student::average() { return(sum() / 3.0); }
double student::print() {
	cout << num << "\t" << name << "\t" << Math << "\t" << English << "\t" << Computer << "\t" << sum() << "\t" << average() << endl;
	return 0;
}
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
	string n, nam; double M, E, C;
	for (int i = 0; i<mu; i++) {
		cout << "第" << i + 1 << "个:" << endl;
		cin >> n >> nam >> M >> E >> C;
		stu[i].num = n;
		stu[i].name = nam;
		stu[i].English = E;
		stu[i].Math = M;
		stu[i].Computer = C;
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
void main() {
	string nn;
	cout << "需要输入多少条信息？:";
	stu[0].set_mu();
	cout << "现在输入学生信息:(格式:学号[回车]姓名[回车]英语[回车]数学[回车]计算机[回车])" << endl;
	stu[0].set_stu_inf();
	cout << "学号" << "\t" << "姓名" << "\t" << "数学" << "\t" << "英语" << "\t" << "计算机" << "\t" << "总分" << "\t" << "平均分" << endl;
	for (int i = 0; i<stu[0].mu; i++) {
		stu[i].print();
	}
	cout << "现在你可以通过姓名找学号：";
	stu[0].get_reg_num();
	cout << "现在你可以通过学号找到该学生的全部信息：";
	cin >> nn;
	stu[0].seach(nn);
	system("pause");
}
//引发的异常: 0xC0000005 : 读取位置 0x00000000 时发生访问冲突。（已解决，是返回值读取了它不该读取了内存）
