# StudentSorceManage

# StudentSorceManage\

### 数据结构

    //结构体
    struct Student {
        string id;
        string name;
        int sorce[8] = { 0 };
    };

### 基础模块

* 完成程序数据读取写入，保证程序的数据不易失

    //读取函数
    int duqu(Student* a) {
        fstream file;
        int i = 0;
    
        file.open("data.txt", ios::in);
    
        for (i = 0; file >> a[i].id >> a[i].name; i++) {
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
        for (int i = 0; i < p; i++) {
            file << a[i].id << " " << a[i].name << " ";
            for (int j = 0; j < 8; j++) {
                file << a[i].sorce[j] << " ";
            }
            file << endl;
        }
        file.close();
    }
    

* 输入规范性检查

> 运用异常处理，规范用户的输入，不至于错误的输入使程序崩溃

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

### 功能模块

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

许多功能都是排序算法，根据具体功能具体实现。

> **题目内容：**
> 
> 某班有最多不超过30人（具体人数由键盘输入）参加期末考试，最多不超过6门（具体门数由键盘输入）。参考学生成绩管理系统V4.0，**定义结构体类型，用结构体数组作函数参数**，编程实现如下菜单驱动的学生成绩管理系统：
> 
> （1）录入每个学生的学号、姓名和各科考试成绩；
> 
> （2）计算每门课程的总分和平均分；
> 
> （3）计算每个学生的总分和平均分；
> 
> （4）按每个学生的总分由高到低排出名次表；
> 
> （5）按每个学生的总分由低到高排出名次表；
> 
> （6）按学号由小到大排出成绩表；
> 
> （7）按姓名的字典顺序排出成绩表；
> 
> （8）按学号查询学生排名及其考试成绩；
> 
> （9）按姓名查询学生排名及其考试成绩；
> 
> （10）按优秀（90~100）、良好（80~89）、中等（70~79）、及格（60~69）、不及格（0~59）5个类别，对每门课程分别统计每个类别的人数以及所占的百分比；
> 
> （11）输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分。
> 
> 选做: 对于本程序，每次运行程序时，学生的学号、姓名、成绩等信息都需要重新输入，因为这些数据都是存储在掉电即失的内存中的，程序一旦运行结束，这些信息也就丢失了。这对于一个实际系统而言，显然是不实用的。只有在输入这些信息之后，将其以文件的形式保存在永久性磁盘中，每次运行程序都可以从这些磁盘文件中读出相应的数据信息，那么这个系统才是算是实用的。

本次课程设计完成了所有的功能，并且完成选做，以及一些问题处理。
这是我的一个作业代码，大家有需要可以参考一下
有什么不足的也可以指出
具体实现思路在博客中有介绍https://blog.csdn.net/Liu_JiaCheng_/article/details/125129391
