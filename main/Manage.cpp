#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX_STUDENT 30

//结构体
struct Student {
	string id;
	string name;
	int sorce[8] = { 0 };
	Student* next;
};

//函数声明
int duqu(Student* a);
void xieru(Student* a, int p);
void ShowMemu();
int input();
void paixu(Student* a, int student_nums);
void choice1(Student* a,int& student_nums);
void choice2(Student* a, int student_nums);
void choice3(Student* a, int student_nums);
void choice4(Student* a, int student_nums);
void choice5(Student* a, int student_nums);
void choice6(Student* a, int student_nums);
void choice7(Student* a, int student_nums);
void choice8(Student* a, int student_nums);
void choice9(Student* a, int student_nums);
void choice10(Student* a, int student_nums);
void choice11(Student* a, int student_nums);


int main() {
	Student a[MAX_STUDENT];
	int student_nums = duqu(a);

	while (1) {
		ShowMemu();
		int choice = input();
		switch (choice)
		{
		case 1:
			choice1(a, student_nums);
			break;
		case 2:
			choice2(a, student_nums);
			break;
		case 3:
			choice3(a, student_nums);
			break;
		case 4:
			choice4(a, student_nums);
			break;
		case 5:
			choice5(a, student_nums);
			break;
		case 6:
			choice6(a, student_nums);
			break;
		case 7:
			choice7(a, student_nums);
			break;
		case 8:
			choice8(a, student_nums);
			break;
		case 9:
			choice9(a, student_nums);
			break;
		case 10:
			choice10(a, student_nums);
			break;
		case 11:
			choice11(a, student_nums);
			break;
		case 0:
			xieru(a, student_nums);
			return 0;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}

	}

	xieru(a, student_nums);
	return 0;
}

//读取函数
int duqu(Student* a) {
	fstream file;
	int i = 0;

	file.open("data.txt", ios::in);
	
	for (i = 0;file >> a[i].id >> a[i].name; i++) {
		for (int j = 0; j < 8; j++) {
			file >> a[i].sorce[j];
		}
	}

	file.close();

	return i;
}

//写入函数
void xieru(Student* a, int p) {
	fstream file;
	file.open("data.txt", ios::out);
	for (int i = 0;i < p ; i++) {
		file << a[i].id << " " << a[i].name << " ";
		for (int j = 0; j < 8; j++) {
			file << a[i].sorce[j] << " ";
		}
		file << endl;
	}
	file.close();
}

//显示菜单
void ShowMemu() {
	cout << "Management for Students' scores" << endl;
	cout << "1.Input record" << endl;
	cout << "2.Caculate total and average score of every course" << endl;
	cout << "3.Caculate total and average score of every student" << endl;
	cout << "4.Sort in descending order by score" << endl;
	cout << "5.Sort in ascending order by score" << endl;
	cout << "6.Sort in ascending order by number" << endl;
	cout << "7.Sort in dictionary order by name" << endl;
	cout << "8.Search by number" << endl;
	cout << "9.Search by name" << endl;
	cout << "10.Statistic analysis" << endl;
	cout << "11.List record" << endl;
	cout << "0.Exit" << endl;
}

//输入规范性检查
int input() {
	string a;
	int i;

	while (1) {
		try {
			cout << "请输入选择：";
			cin >> a;
			i = stoi(a);
			break;
		}
		catch (exception& invalid_argument) {
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
	}

	return i;
}

//录入每个学生的学号、姓名和各科考试成绩
void choice1(Student* a, int& student_nums) {
	int nums = 0;
	int nums1 = 0;
	int sum = 0;
	cout << "当前学生数量：" << student_nums << "还可以输入" << MAX_STUDENT - student_nums << "个学生" << endl;
	cout << "请选择录入学生个数:" << endl;
	while (true)
	{
		if ((nums = input()) > (MAX_STUDENT - student_nums)) {
			cout << "学生数量超过最高限制" << endl;
		}
		else {
			break;
		}
	}
	
	cout << "请输入学生科目数量：" << endl;
	while (true)
	{
		if ((nums1 = input()) > 6) {
			cout << "科目数量超过最高限制" << endl;
		}
		else {
			break;
		}
	}
	for (int q = 0; q < nums; student_nums++, q++) {
		
		a[student_nums].sorce[6] = nums1;
		cout << "请输入每个学生的学号、姓名和各科考试成绩" << endl;
		cin >> a[student_nums].id >> a[student_nums].name;
		for (int i = 0; i < nums1; i++) {
			int temp = 0;
			cin >> temp;
			a[student_nums].sorce[i] = temp;
			sum += temp;
		}
		a[student_nums].sorce[7] = sum;
		sum = 0;
	}

	xieru(a, student_nums);
	cout << "录入成功" << endl;
	cout << "=====================" << endl;
	cout << "\n\n\n\n\n\n";
}


//2.计算每门课程的总分和平均分
void choice2(Student* a, int student_nums) {
	int count = 0;
	int i = 0;
	for (int j = 0; j < a[0].sorce[6]; j++) {
		for (i = 0; i < student_nums; i++) {
			count += a[i].sorce[j];
		}
		cout << "第" << j+1 << "科总分为：" << count << endl;
		count = count / a[0].sorce[6];
		cout << "平均分为：" << count << endl;
		cout << "=====================" << endl;
		count = 0;
	}
}

//3.计算每个学生的总分和平均分
void choice3(Student* a, int student_nums) {
	int count = 0;
	for (int i = 0; i < student_nums; i++) {
		cout << a[i].id << " " << a[i].name << " ";
		for (int j = 0; j < a[i].sorce[6]; j++) {
			count += a[i].sorce[j];
		}
		cout << "总分为：" << count << endl;
		count = count / a[i].sorce[6];
		cout << "平均分为：" << count << endl;
		cout << "=====================" << endl;
		count = 0;
	}
}

//根据总分排序
void paixu(Student* a, int student_nums) {
	Student temp;
	for (int i = 0; i < student_nums - 1; i++) {
		for (int j = i + 1; j < student_nums; j++) {
			if (a[i].sorce[7] < a[j].sorce[7]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

//4.按每个学生的总分由高到低排出名次表
void choice4(Student* a, int student_nums) {
	paixu(a, student_nums);
	for (int i = 0; i < student_nums; i++) {
		cout << a[i].id << " " << a[i].name << " " << a[i].sorce[7] << endl;
	}
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}

//5.按每个学生的总分由低到高排出名次表；
void choice5(Student* a, int student_nums) {
	paixu(a, student_nums);
	for (int i = student_nums-1; i >= 0; i--) {
		cout << a[i].id << " " << a[i].name << " " << a[i].sorce[7] << endl;
	}
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}

//6.按学号由小到大排出成绩表
void choice6(Student* a, int student_nums) {
	Student temp;
	long long int u = 0;
	for (int i = 0; i < student_nums - 1; i++) {
		for (int j = i + 1; j < student_nums; j++) {
			if (stoi(a[i].id) < stoi(a[j].id)) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = student_nums - 1; i >= 0; i--) {
		cout << a[i].id << " " << a[i].name << " " << a[i].sorce[7] << endl;
	}
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}

//7.按姓名的字典顺序排出成绩表
void choice7(Student* a, int student_nums) {
	Student temp;
	for (int i = 0; i < student_nums - 1; i++) {
		for (int j = i + 1; j < student_nums; j++) {
			if (a[i].name.compare(a[j].name)>0) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < student_nums; i++) {
		cout << a[i].id << " " << a[i].name << " " << a[i].sorce[7] << endl;
	}
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}

//8.按学号查询学生排名及其考试成绩
void choice8(Student* a, int student_nums) {
	paixu(a, student_nums);
	cout << "请输入要查询的学号：";
	int temp = input();
	for (int i = 0; i < student_nums; i++) {
		if (temp == stoi(a[i].id)) {
			cout << a[i].id << " " << a[i].name << " 排名第：" << i + 1 << " 总分：" << a[i].sorce[7] << endl;
		}
	}
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}

//9.按姓名查询学生排名及其考试成绩
void choice9(Student* a, int student_nums) {
	paixu(a, student_nums);
	cout << "请输入要查询的名字：";
	string temp;
	cin >> temp;
	for (int i = 0; i < student_nums; i++) {
		if (temp == a[i].name) {
			cout << a[i].id << " " << a[i].name << " 排名第：" << i + 1 << " 总分：" << a[i].sorce[7] << endl;
		}
	}
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}

//10.按优秀（90~100）、良好（80~89）、中等（70~79）、及格（60~69）、不及格（0~59）5个类别，
//   对每门课程分别统计每个类别的人数以及所占的百分比
void choice10(Student* a, int student_nums) {
	float A = 0, B = 0, C = 0, D = 0, E = 0, G = student_nums;
	for (int i = 0; i < a[0].sorce[6]; i++) {
		for (int j = 0; j < student_nums; j++) {
			if (a[j].sorce[i] >= 90 && a[j].sorce[i] <= 100) {
				A++;
			}
			else if (a[j].sorce[i] >= 80 && a[j].sorce[i] < 90) {
				B++;
			}
			else if (a[j].sorce[i] >= 70 && a[j].sorce[i] < 80) {
				C++;
			}
			else if (a[j].sorce[i] >= 60 && a[j].sorce[i] < 70) {
				D++;
			}
			else if (a[j].sorce[i] >= 0 && a[j].sorce[i] < 60) {
				E++;
			}
		}
		cout << "第" << i + 1 << "科：" << endl;
		cout << "优秀人数：" << A << " 所占百分比为：" << (A/G)*100 << "%" << endl;
		cout << "良好人数：" << B << " 所占百分比为：" << (B / G) * 100 << "%" << endl;
		cout << "中等人数：" << C << " 所占百分比为：" << (C / G) * 100 << "%" << endl;
		cout << "及格人数：" << D << " 所占百分比为：" << (D / G) * 100 << "%" << endl;
		cout << "不及格人数：" << E << " 所占百分比为：" << (E / G) * 100 << "%" << endl;
		cout << "=====================" << endl;
		cout << "\n\n\n\n";
		A = 0, B = 0, C = 0, D = 0, E = 0;
	}
}

//输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分
void choice11(Student* a, int student_nums) {
	paixu(a, student_nums);
	for (int i = 0; i < student_nums; i++) {
		cout << a[i].id << " " << a[i].name << " ";
		for (int j = 0; j < a[i].sorce[6]; j++) {
			cout << a[i].sorce[j] << " ";
		}
		cout << endl;
	}
	choice2(a, student_nums);
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}