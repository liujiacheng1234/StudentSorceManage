#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX_STUDENT 30

//�ṹ��
struct Student {
	string id;
	string name;
	int sorce[8] = { 0 };
	Student* next;
};

//��������
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
			cout << "�����������������" << endl;
			break;
		}

	}

	xieru(a, student_nums);
	return 0;
}

//��ȡ����
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

//д�뺯��
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

//��ʾ�˵�
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

//����淶�Լ��
int input() {
	string a;
	int i;

	while (1) {
		try {
			cout << "������ѡ��";
			cin >> a;
			i = stoi(a);
			break;
		}
		catch (exception& invalid_argument) {
			cout << "�����������������" << endl;
			continue;
		}
	}

	return i;
}

//¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�
void choice1(Student* a, int& student_nums) {
	int nums = 0;
	int nums1 = 0;
	int sum = 0;
	cout << "��ǰѧ��������" << student_nums << "����������" << MAX_STUDENT - student_nums << "��ѧ��" << endl;
	cout << "��ѡ��¼��ѧ������:" << endl;
	while (true)
	{
		if ((nums = input()) > (MAX_STUDENT - student_nums)) {
			cout << "ѧ�����������������" << endl;
		}
		else {
			break;
		}
	}
	
	cout << "������ѧ����Ŀ������" << endl;
	while (true)
	{
		if ((nums1 = input()) > 6) {
			cout << "��Ŀ���������������" << endl;
		}
		else {
			break;
		}
	}
	for (int q = 0; q < nums; student_nums++, q++) {
		
		a[student_nums].sorce[6] = nums1;
		cout << "������ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�" << endl;
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
	cout << "¼��ɹ�" << endl;
	cout << "=====================" << endl;
	cout << "\n\n\n\n\n\n";
}


//2.����ÿ�ſγ̵��ֺܷ�ƽ����
void choice2(Student* a, int student_nums) {
	int count = 0;
	int i = 0;
	for (int j = 0; j < a[0].sorce[6]; j++) {
		for (i = 0; i < student_nums; i++) {
			count += a[i].sorce[j];
		}
		cout << "��" << j+1 << "���ܷ�Ϊ��" << count << endl;
		count = count / a[0].sorce[6];
		cout << "ƽ����Ϊ��" << count << endl;
		cout << "=====================" << endl;
		count = 0;
	}
}

//3.����ÿ��ѧ�����ֺܷ�ƽ����
void choice3(Student* a, int student_nums) {
	int count = 0;
	for (int i = 0; i < student_nums; i++) {
		cout << a[i].id << " " << a[i].name << " ";
		for (int j = 0; j < a[i].sorce[6]; j++) {
			count += a[i].sorce[j];
		}
		cout << "�ܷ�Ϊ��" << count << endl;
		count = count / a[i].sorce[6];
		cout << "ƽ����Ϊ��" << count << endl;
		cout << "=====================" << endl;
		count = 0;
	}
}

//�����ܷ�����
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

//4.��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
void choice4(Student* a, int student_nums) {
	paixu(a, student_nums);
	for (int i = 0; i < student_nums; i++) {
		cout << a[i].id << " " << a[i].name << " " << a[i].sorce[7] << endl;
	}
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}

//5.��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
void choice5(Student* a, int student_nums) {
	paixu(a, student_nums);
	for (int i = student_nums-1; i >= 0; i--) {
		cout << a[i].id << " " << a[i].name << " " << a[i].sorce[7] << endl;
	}
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}

//6.��ѧ����С�����ų��ɼ���
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

//7.���������ֵ�˳���ų��ɼ���
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

//8.��ѧ�Ų�ѯѧ���������俼�Գɼ�
void choice8(Student* a, int student_nums) {
	paixu(a, student_nums);
	cout << "������Ҫ��ѯ��ѧ�ţ�";
	int temp = input();
	for (int i = 0; i < student_nums; i++) {
		if (temp == stoi(a[i].id)) {
			cout << a[i].id << " " << a[i].name << " �����ڣ�" << i + 1 << " �ܷ֣�" << a[i].sorce[7] << endl;
		}
	}
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}

//9.��������ѯѧ���������俼�Գɼ�
void choice9(Student* a, int student_nums) {
	paixu(a, student_nums);
	cout << "������Ҫ��ѯ�����֣�";
	string temp;
	cin >> temp;
	for (int i = 0; i < student_nums; i++) {
		if (temp == a[i].name) {
			cout << a[i].id << " " << a[i].name << " �����ڣ�" << i + 1 << " �ܷ֣�" << a[i].sorce[7] << endl;
		}
	}
	cout << "=====================" << endl;
	cout << "\n\n\n\n" << endl;
}

//10.�����㣨90~100�������ã�80~89�����еȣ�70~79��������60~69����������0~59��5�����
//   ��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�
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
		cout << "��" << i + 1 << "�ƣ�" << endl;
		cout << "����������" << A << " ��ռ�ٷֱ�Ϊ��" << (A/G)*100 << "%" << endl;
		cout << "����������" << B << " ��ռ�ٷֱ�Ϊ��" << (B / G) * 100 << "%" << endl;
		cout << "�е�������" << C << " ��ռ�ٷֱ�Ϊ��" << (C / G) * 100 << "%" << endl;
		cout << "����������" << D << " ��ռ�ٷֱ�Ϊ��" << (D / G) * 100 << "%" << endl;
		cout << "������������" << E << " ��ռ�ٷֱ�Ϊ��" << (E / G) * 100 << "%" << endl;
		cout << "=====================" << endl;
		cout << "\n\n\n\n";
		A = 0, B = 0, C = 0, D = 0, E = 0;
	}
}

//���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ����
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