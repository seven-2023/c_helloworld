//#include <iostream>
//#include <string>
//using namespace std;
//ȫ�ֶ���������main����,main����������
//1.ջ������Զ����ù��������
//2. �Ѷ�����Զ����ù��죬�������Զ�������������Ҫ�ֶ�����
//3.�ѳ�ʼ���Ķ���洢�� .data����
//4.δ��ʼ���Ķ���洢��.bss����




//=========����ʱ����====================
// �ɳ���Ա�����ͷţ������ͷţ�����������ɲ���ϵͳ���գ�
// new �ڶ��������ڴ棬 delete�ͷ�


//------------����/����------------
#include <iostream>
#include <string>
using namespace std;

int main() {
	int a = 10;
	int& b = a;
	b = 20;
	cout << a << endl;
	cout << b << endl;  
}

//------ʵ������������------
//void valueSwap(int a, int b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void addrSwap(int *a, int *b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
////���ô���Ҳ���Ըı����ֵ�������ǳ���ָ�룬ָ��ĵ�ַ�������޸ģ���ָ��ĵ�ַ��ֵ�����޸�
//void aliasSwap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main() {
//	int a = 10;
//	int b = 20;
//	valueSwap(a, b);
//	cout << a << endl;
//	cout << b << endl;  
//
//	addrSwap(&a, &b);
//	cout << a << endl;
//	cout << b << endl;
//
//	aliasSwap(a, b);
//	cout << a << endl;
//	cout << b << endl;
//}

////const ���εĳ��������βΣ���ֹ���޸�
//void showValue(const int & v) {
//	//v += 20; //����
//	cout << v << endl;
//}
//int main() {
//	int a = 10;
//	showValue(a);
//}


////=========������Ĭ�ϲ���===================
////������ʵ��ֻ����һ����Ĭ�ϲ���
//int func(int a, int b, int c);
//int func(int a , int b = 10, int c = 10) {
//	return a + b + c;
//};
//int main() {
//	cout << func(10) << endl;
//	cout << func(10, 20, 30) << endl;
//}

////=========������ռλ����===================
//int func1(int a, int ) {
//	return a;
//};
////ռλ����Ҳ������Ĭ��ֵ
//int func2(int a, int = 50) {
//	return a ;
//};
//int main() {
//	cout << func1(10,20) << endl; //ռλ����Ҳ���봫ֵ
//	cout << func2(10, 20) << endl;
//}

//=========��������===================
//������������������
//1.��������ͬ��
//ͬһ��������
//��������/����/˳��ͬ��

//void func(int a){
//	cout << a<< endl;
//};
////����ʱ��Ĭ�ϲ����ᵼ�±�������֪��������һ����ע��
////void func(int a, int b = 100) {
////	cout << a + b << endl;
////};
//void func(int a, int b) {
//	cout << a + b << endl;
//};
//
//void func(int a, double b) {
//	cout << a + b << endl;
//};
//void func(double a, int b) {
//	cout << a + b << endl;
//};
//int main() {
//
//	func(10);
//	func(10, 20);
//	func(10, 3.14);
//	func(9.44, 10);
//}

//====��/���� ռ�ÿռ��С����========
//���С������ѭ�ṹ�����ԭ��
//�����ݳ�Ա�йأ����Ա�����޹أ��뾲̬��Ա�޹�
//��̳���Ĵ�СӰ��
//�麯������Ĵ�СӰ��

//class BBase 
//{
//public:
//	BBase(int bbase=111): m_bBase(bbase)
//	{
//	}
//	int m_bBase;
//};
//class B1 :virtual public BBase
//{
//public:
//	int m_b1;
//};
//class B2 :virtual public BBase
//{
//public:
//	int m_b2;
//};
//class DD :public B1, public B2
//{
//public:
//	int m_dd;
//};
//int main() {
//	cout << sizeof(BBase) << endl; //4
//	cout << sizeof(B1) << endl;		//24
//	cout << sizeof(B2) << endl;		//24
//	cout << sizeof(DD) << endl;		//48
//
//	//�鿴B1�Ľṹ
//	B1 b1;
//	long** p;//����ָ���ָ�룬ָ�������ָ��ĵ�ַ
//	cout << &b1 << endl;		//0000006F12D3F5A8 b1��ַ��ռ��8���ֽ�
//	cout << &b1.m_b1 <<" ռ�ã�"<<sizeof(b1.m_b1) << endl;	//0000006F12D3F5B0	b1��Ա������ַ+8��ռ��4���ֽ� ,�����ռ��8���ֽڣ�
//	cout << &b1.m_bBase << " ռ�ã�" << sizeof(b1.m_bBase) << endl;//0000006F12D3F5B8	b1��������Ա������ַ+8��ռ��4���ֽڣ������ռ��8���ֽڣ� ����һ��24��
//
//	//�鿴dd�Ľṹ
//	DD d1;
//	cout << &d1 << endl;		//000000F5103AFBC8 b1��ַ��ռ��8���ֽ�
//	cout << &d1.m_b1 << " ռ�ã�" << sizeof(d1.m_b1) << endl;	//000000F5103AFBD0	b1��Ա������ַ+8��ռ��4���ֽ�
//	cout << &d1.m_b2 << " ռ�ã�" << sizeof(d1.m_b2) << endl;	//000000F5103AFBE0	b1��Ա������ַ+16��ռ��4���ֽ�
//	cout << &d1.m_dd << " ռ�ã�" << sizeof(d1.m_dd) << endl;//000000F5103AFBE8	b1��������Ա������ַ+8��ռ��4���ֽ�
//	cout << &d1.m_bBase << " ռ�ã�" << sizeof(d1.m_bBase) << endl;	//000000F5103AFBF0	b1��Ա������ַ+8��ռ��4���ֽ�
//	p = (long**)&d1;
//	cout << p[0][0] << endl;
//	cout << p[0][1] << endl;
//	cout << p[2][0] << endl;
//	cout << p[2][1] << endl;
//
//	cout << d1.m_bBase << endl;//ֱ�ӷ���
//	//��ӷ���,��Ҫ����ʱ֧��
//	BBase* p_BBase = &d1;
//	cout << p_BBase->m_bBase << endl;
//
//}

////=========��Ͷ���===================
////--��򵥵���----
//class Circle {
//	protected:
//		const double PI = 3.14;
//	public:
//		int r;
//
//		double calculateCircle() {
//			return 2 * PI * r;
//		}
//};
//int main() {
//	Circle c1;
//	c1.r = 10;
//	cout << c1.calculateCircle() << endl;
//}

////-----ѧ��ʵ��-------
//class Student {
//	int c_id;//Ĭ��Ϊ˽��Ȩ��
//	protected:
//		int c_age; //������Ա���ԣ����ڿɷ��ʣ����ⲻ�У��ɼ̳С�
//	private:
//		int c_score; //˽�г�Ա���ԣ����ڿɷ��ʣ����ⲻ�У����ɼ̳С�
//	public:
//		string c_name;  
//
//		void setInfo(int setId, int setAge,int setScore) {	
//			c_id = setId;
//			c_score = setScore;
//			if (setAge <=0 || setAge>100) {
//				cout << "���õ����䲻��ȷ" << endl;
//				c_age = 0;
//				return ;
//			}		
//			c_age = setAge;
//		}
//		void showStudent() {
//			cout << "name:" << c_name << "\tID:" << c_id << "\tage:" << c_age << "\tscore:" << c_score << endl;;
//		}
//};
//int main() {
//	Student s1;
//	s1.c_name = "������";
//	s1.setInfo(101,1000,99);
//	s1.showStudent();
//}

//-----�ֱ���ȫ�ֺ����ͳ�Ա�����ж��������Ƿ����-------
//class Square {
//	private:
//		int mL; //��
//		int mW; //��
//	public:
//		void setL(int L) {
//			mL = L;
//		}
//		int getL() {
//			return mL;
//		}
//
//		void setW(int W) {
//			mW = W;
//		}
//		int getW() {
//			return mW;
//		}
//
//		int getArea() {
//			return mL * mW;
//		}
//		bool isSame(Square& c) {
//			if (mL == c.getL() && mW == c.getW()) {
//				return true;
//			}
//			return false;
//		}
//};
//bool isSame(Square& c1, Square& c2) {
//	if (c1.getL() == c2.getL() && c1.getW() == c2.getW()) {
//		return true;
//	}
//	return false;
//}
//int main() {
//	Square s1;
//	s1.setL(10);
//	s1.setW(10);
//	cout << "s1���:" << s1.getArea() << endl;
//	Square s2;
//	s2.setL(10);
//	s2.setW(10);
//	cout << "s2���:" << s2.getArea() << endl;
//
//	if (isSame(s1, s2)) {
//		cout << "ȫ�ֺ����ж�������" << endl;
//	}
//	else
//	{
//		cout << "ȫ�ֺ������������" << endl;
//	}
//
//	
//	if (s1.isSame(s2)) {
//		cout << "��Ա�����ж�������" << endl;
//		}
//	else
//	{
//		cout << "��Ա�����ж��������" << endl;
//	}
//}

//=================���캯��=====================
/*
1��������Ĭ�ϻᴴ���޲ι��죬�вι���Ϳ����������֣�
2�������Զ����вΣ�����������ٶ����޲κ��вΣ�
3�������Զ��忽��������������ٶ����޲Σ��вκͿ�����
*/
//class Person {
//public:
//	Person() {
//		cout << "�����޲ι��캯��" << endl;
//	}
//	//�вι��캯��
//	Person(int a) {
//		m_age = a;
//		cout << "�����вι��캯��" << endl;
//	}
//	//�������캯��
//	Person(const Person &p) {
//		m_age = p.m_age;  //������������ҲҪ�ֶ�����һ�£��������ǲ�֪������һ�����ֵҪ��������ĸ�ֵ��Ӧ�ġ�
//		cout << "���ÿ������캯��.." << endl;
//	}
//
//	~Person() {
//		cout << "��������" << endl;
//	}
//	
//	void Display_m() {
//		cout << "m_age=" << m_age << endl;
//	}
//private:
//	int m_age;
//};
//
//void test1() {
//
//	////���ŵ��÷�������������
//	//Person p1;  //�����޲ι��캯�����޲ι��첻�ܼ����ţ��������������Ϊ�Ǻ���������
//	//Person p2(10);  //�����й��캯��
//	//Person p3(p2);  //�����й��캯��
//	//cout << "p2������Ϊ��" << p2.age<<endl;
//	//cout << "p3������Ϊ��" << p3.age << endl;  //ageҲ�������ã�����p3��age���������
//
//	////��ʾ���÷�
//	//Person p1;
//	//Person p2 = Person(10);
//	//Person p3 = Person(p2);
//
//	////��ʽ���÷�
//	//Person p2 = 10;
//	//Person p3 = p2;
//
//	//���ÿ������캯��
//	Person p5 = 10;
//	p5.Display_m();
//	Person p6(p5); //���ÿ������캯������p5��ʼ����ʼ��p6��ֵ
//	p6.Display_m();
//	Person p7=p5; //���ַ���������ȼ�
//	p7.Display_m();
//}
//
//int main() {
//	test1();
//}

/*----�������캯������ʱ��------------
1. ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
2. ֵ���ݷ�ʽ�������Ĳ�����ֵ��
3. ��ֵ�ķ�ʽ���ؾֲ�����
*/
//class Person {
//public:
//	Person() {
//		age = 0;
//		cout << "�޲ι��캯��" << endl;
//	}
//	//�вι��캯��
//	Person(int a) {
//		age = a;
//		cout << "�вι��캯��" << endl;
//	}
//	//�������캯���� 
//	Person(const Person& p) {
//		age = p.age;  
//		cout << "�������캯��" << endl;
//	}
//
//	~Person() {
//		cout << "��������" << endl;
//	}
//	int age;
//};
//
////	//ʱ��1����ʼ���¶���
////void test1() {
////	Person p1(18);  //�����޲ι��캯�����޲ι��첻�ܼ����ţ��������������Ϊ�Ǻ���������
////	Person p2(p1);  //���ÿ������캯��
//	cout << "p1������Ϊ��" << p1.age<<endl;
////	cout << "p2������Ϊ��" << p2.age << endl;  
////}
//
////ʱ��2��ֵ���ݷ�ʽ����������
////void doWork(Person p) {}  
////void test2() {
////	Person p1(10);  
////	doWork(p1);  //ֻ�ǰ�p1�ĳ�Ա���Կ�����doWork����
////}
//
////ʱ��3����ֵ�ķ�ʽ���ؾֲ�����
//Person doThink() {
//	Person p1;
//	return p1;
//}
//void test3() {
//	Person p2=doThink(); //�ѷ��صľֲ����󴫸�p2������ÿ������캯����ʽ����Ա�������ݹ�����
//}
//
//int main() {
//	//test1(); //ʱ��1����ʼ���¶���
//	//test2();  //ʱ��2��ֵ���ݷ�ʽ����������
//	test3();  //ʱ��3����ֵ�ķ�ʽ���ؾֲ�����
//}






////===============��ʼ����Ա�б�==================
//class Person {
//public:
//	Person(int a,int b,int c):m_A(a),m_B(b),m_C(c) {
//		cout << "�вι��캯��" << endl;
//	}
//
//	~Person() {
//		cout << "��������" << endl;
//	}
////private:
//	int m_A;
//	int m_B;
//	int m_C;
//
//	void printPerson() {
//		cout << m_A << m_B << m_C << endl;
//	}
//};
//
//void test1() {
//	Person p1(10, 20, 30);
//	p1.printPerson();
//	
//};
//
//int main() {
//	test1();
//}

////===============�������Ϊ��һ����ĳ�Ա==================
//class Phone {
//public:
//	Phone(string name) :m_Pname(name) {
//		cout << "Phone�вι��캯��" << endl;
//	}
//
//	~Phone() {
//		cout << "Phone��������" << endl;
//	}
//	string m_Pname;
//};
//
//class Person {
//public:
//	//�˴��������Զ�����һ�� ��ʽ���ã� Phone m_Phone = phone_Name;
//	Person(string person_Name,string phone_Name) :m_Name(person_Name), m_Phone(phone_Name) {
//		cout << "Person�вι��캯��" << endl;
//	}
//
//	~Person() {
//		cout << "Person��������" << endl;
//	}
//	string m_Name;
//	Phone m_Phone;
//};
//
//void test1() {
//	Person p1("������","ƻ��");
//	cout << p1.m_Name << "��һ��" << p1.m_Phone.m_Pname << "�ֻ�" << endl;
//};
//
//int main() {
//	test1();
//}


//==============��̬��Ա==================
//-------------��̬��Ա����/����/����------------------
/* 
���ʷ�����
1. ͨ�������Ա����
2. ͨ����������
-----��̬��Ա����------
�ص㣺
1. ��̬��Ա����������Ƕ���,�����ж�����˳�Ա
2. ���������������ʼ��������cpp��ʵ��
3. ����׶ξͷ����ڴ�
4. �Ƽ�ʹ�����Ա��ʽ���ʣ�����ᱻ����Ϊ�Ƕ���ĳ�Ա����
-----��̬��Ա����------


-----��̬��Ա����------
�ص㣺
1. ����
2. ��̬��Ա����ֻ�ܷ��ʾ�̬����,��Ϊ��û��thisָ��
*/
//class Person {
//public:
//	Person(string name):m_Name(name) {
//		cout << "Person�вι��캯������Ա����m_Name����ʼ��Ϊ��"<<m_Name << endl;
//		++m_countObj; //��������ʱ+1
//	}
//
//	~Person() {
//		cout << "Person��������" << endl;
//		--m_countObj;//���ٶ���ʱ-1
//	}
//	static int m_countObj; //��̬��Ա�����࣬�����Ƕ�������
//	string m_Name;
//
//	static const int m_const = 111; //ֻ�����εĲſ����������ڳ�ʼ��
//	static const char m_const_char = 'C'; //charҲ����С����
//
//	static void func(int a) {
//		m_countObj = a;
//		//m_Name = "yyy"; // ��̬��Ա����ֻ�ܷ��ʾ�̬����,��Ϊ��û��thisָ��
//		cout << "static void func()�� m_countObj ֵ���޸ģ�" << endl;
//	}
//};
//int Person::m_countObj = 0;
////���Ծ�̬��Ա����
//void test1() {
//	Person p1("������");
//	cout << "ͨ�������Ա����m_countObj:" << p1.m_countObj << endl;
//	
//	Person p2("������");
//	cout << "ͨ�������Ա����m_countObj:" << p2.m_countObj << endl;
//
//	//p1.m_countObj = 200;
//	//cout << "ͨ���������� Person::m_countObj=" << Person::m_countObj << endl; 
//};
//void test2() {
//
//	Person* p3 = new Person("xxx");
//	cout << "ͨ���������� Person::m_const=" << Person::m_const << endl;
//	cout << "ͨ������ָ����� Person::m_const=" << p3->m_const << endl;
//	cout << "ͨ���������� Person::m_const_char=" << Person::m_const_char << endl;
//	cout << "ͨ������ָ����� Person::m_const_char=" << p3->m_const_char << endl;
//	delete p3;
//
//};
//
////���Ծ�̬��Ա����
//void test3() {
//	Person* p4 = new Person("����");
//	cout << "ͨ�������Աָ�����m_countObj:" << p4->m_countObj << "\tͨ����������m_countObj:" << Person::m_countObj << endl;
//	p4->func(300); //����ָ����ó�Ա����
//	cout << Person::m_countObj << endl; //300
//	Person::func(400); //ͨ������þ�̬��Ա����
//	cout << Person::m_countObj << endl; //400
//	delete p4;
//};
//int main() {
//	//test1();
//	test2();
//	//test3();
//}


//---- ��̬��Ա����------
//ʵ��2  ��̬��Ա�����ж��Ƿ������꣬ 
//�ص㣺����Ҫ��������
//class Date {
//public:
//	Date(int year) :m_year(year) {}
//
//	bool IsLeapYear() {
//		return (m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0);
//	}
//	static bool IsLeapYear(int year) {
//		return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
//	}
//private:
//	int m_year;
//};
//void main() {
//	//ͨ��������ã����ֻ�����ж�һ��ĳ������Ƿ������꣬��Ҫ���������е㲻����
//	Date d(2012);
//	cout << d.IsLeapYear() << endl; //1
//
//	//ͨ����ľ�̬��������
//	cout << Date::IsLeapYear(2012) << endl; //1 
//	cout << Date::IsLeapYear(2023) << endl; //0
//
//}

//==============thisָ��==================
/* ������һ������ָ�룬ָ��ĵ�ַ�ǲ������޸ĵģ���ָ��ĵ�ַ�����ݿ��޸�
���
1. ��Ա�����ͳ�Ա�����Ƿֿ��洢��
2. ÿ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ����
this���ܣ�
1. ���κͳ�Ա����ͬ�����������thisָ�������֣�����������ô�á�
2. ����ķǾ�̬��Ա�з��ض�������ʹ��retrun *this
*/
////����1
//class Person {
//public:
//	Person(int age) {
//		this->age = age;  //this ָ�򱻵��ó�Ա���������Ķ���
//	}
//	int age;
//};
//
//void test1() {
//	Person p1(18); //������õ���Person�Ĺ��캯������Ա��������p1��this��ָ��p1
//	cout << "m_A:" << p1.age << endl;
//};
//int main() {
//	test1();
//}

//����2��ʵ������p1��Ǯ��p2
//class Person {
//public:
//	Person(int money) {
//		m_Money = money;  //this ָ�򱻵��ó�Ա���������Ķ���
//	}
//	int m_Money;
//
//	////û�з���ֵ���޷�ʵ��
//	//void addMoney(Person &p) {
//	//	this->m_Money += 100;
//	//	p.m_Money -= 100;
//	//}
//
//	////���ص���Person���󣬱������´�����µ�Person�������޷�������ȥ�� ע�ⲻ����ôʹ��
//	//Person addMoney(Person& p) {
//	//	this->m_Money += 100;
//	//	p.m_Money -= 100;
//	//	return *this;
//	//}
//
//	//���ض���ı���,����һ����ʽ���˼��
//	Person & addMoney(Person& p) {
//		this->m_Money += 100;
//		p.m_Money -= 100;
//		return *this;
//	}
//};
//
//void test1() {
//	Person p1(1000); //p1ӵ�� 1000��
//	cout << "p1ӵ��:" << p1.m_Money <<"��Ǯ"<< endl;
//	Person p2(0); //p2ӵ�� 0��
//	cout << "p2ӵ��:" << p2.m_Money << "��Ǯ" << endl;
//
//	p2.addMoney(p1).addMoney(p1).addMoney(p1);  //��ʽ���˼��
//	cout << "p1ӵ��:" << p1.m_Money << "��Ǯ" << endl;
//	cout << "p2ӵ��:" << p2.m_Money << "��Ǯ" << endl;
//
//};
//int main() {
//	test1();
//}


//==============��ָ����ó�Ա����==================
/*
���
��ָ����Ե��ó�Ա�����ͳ�Ա�����������ܷ��ʷ���this��ָ��

*/
//class Person {
//public:
//	int m_Age;
//	Person(int age) :m_Age(age) {}
//	void pirntClassName() {
//		cout << "���������Person" << endl;
//	}
//
//	//void showAgee() {
//	//	cout << "�����ǣ�"<<m_age << endl;   ////����,��Ϊm_age���൱��this->m_age,û��ʵ����֮ǰthis��һ����ָ��
//	//}
//	void showAgee() {
//		/*cout << "�����ǣ�" << this->m_Age << endl; */  //����,��Ϊm_age���൱��this->m_age
//		if (this == NULL) {
//			return;
//		}
//		else
//		{
//			cout << "�����ǣ�" << this->m_Age << endl;   //�����Ͳ��ᱨ����
//		}
//		
//	}
//};
//
//void test1() {
//	Person* p = NULL;
//	//p->m_age;
//	//p->pirntClassName();
//	//p->showAgee(); //���� 
//	Person p1(10);
//	p1.showAgee();
//	p->showAgee();
//};
//int main() {
//	test1();
//}


////==============������==================
///*
//���
//1.const ���γ�Ա��������
//2.�������������޸ĳ�Ա���ԣ��������Ա��������ʱ�ӹؼ���mutable���ڳ������Ϳ����޸��ˡ�
//*/
//class Person {
//public:
//	Person(int a):m_A(a) {};
//	int m_A;
//	mutable int m_B; //mutable���ɱ�ģ�����ʱ�����Ա��������޸�
//	
//	
//	//this�����ǳ���ָ�룬ָ�򲻿��޸ģ���ָ���ֵ���޸ģ�
//	//�ڳ�Ա���������const�����ε���thisָ���ֵ�����Բ����޸ģ��൱��const Person * const this;
//	void changeValue1() const{
//		//this->m_A = 100; //����
//		this->m_B = 200;
//	}
//
//	void changeValue2(){
//		m_A = 100;
//	}
//};
//
//void test1() {
//	Person p1(10);
//	cout << p1.m_B << endl;  //-858993460��ʵ����ʱ����û�ж���
//	p1.changeValue1();
//	cout << p1.m_B << endl;  //200,��changeValue()��ֵ��
//};
//void test2() {
//	const Person p1(10); //������
//	p1.changeValue1();
//	cout << p1.m_B << endl;  //200,��changeValue()��ֵ��
//	//p1.changeValue2(); //����������ֻ�ܵ��ó�������
//};
//int main() {
//	//test1();
//	test2();
//}

//==============��Ԫ==================
/*
���
	������Ԫ�󣬿��Է���˽�г�Ա
	�������࣬�������������λ�ö������ö���ͬ
*/
//��Ԫ������ʾ��1��
//class Home {
//	friend void goodGay(Home* home);//������Ԫ����
//public:
//	Home(){
//		m_SittingRoom = "����";
//		m_BedRoom = "����";
//	};
//	string m_SittingRoom;//����
//private:
//	string m_BedRoom;//����
//};
//
////ȫ�ֺ���
//void goodGay(Home *home) {
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << home->m_SittingRoom << endl;
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << home->m_BedRoom << endl; //������Ԫ��Ͳ������ˣ����Է���˽�г�Ա����
//}
//void test1() {
//	Home home;
//	goodGay(&home);
//};
//
//int main() {
//	test1();
//}


////��Ԫ������ʾ��2��
//#include <math.h>
//class Point {
//	friend double Distance(const Point& p1,const Point& p2);//������Ԫ����,����public��private��һ����Ч��
//public:
//	Point(int x, int y);
//private:
//	int m_x;
//	int m_y;
//};
//Point::Point(int x, int y) :m_x(x), m_y(y)
//{
//}
//
////ȫ�ֺ���
//double Distance(const Point& p1, const Point& p2) 
//{
//	double dx = p1.m_x - p2.m_x;
//	double dy = p1.m_y - p2.m_y;
//	return sqrt(dx * dx + dy * dy);
//}
//
//int main() {
//	Point p1(3, 4);
//	Point p2(6, 8);
//	cout << "������ľ����ǣ�" << Distance(p1, p2);
//}


//��Ԫ�࣬ʾ��1��
//class Home {
//	friend class goodGay;//������Ԫ��
//public:
//	Home();//�������캯��
//	string m_SittingRoom;//����
//private:
//	string m_BedRoom;//����
//};
//
////��Ĺ��캯���ͳ�Ա�������Է������涨��
//Home::Home() {
//	m_SittingRoom = "����";
//	m_BedRoom = "����";
//};
//
//
////�û�����
//class goodGay {
//public:
//	goodGay() {
//		hp = new Home;  //�ڶ���������һ��Home���͵��ڴ�ռ���Home�࣬����һ��ָ�룬��hp�������ָ��
//	};
//
//	void visit() {
//		cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << hp->m_SittingRoom << endl;
//		cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << hp->m_BedRoom << endl; //������Ԫ��Ͳ������ˣ����Է���˽�г�Ա����
//		cout << sizeof(*hp);//Home��ռ��80���ֽ�
//	}
//private:
//	Home* hp;//����һ��Home���͵�ָ��
//};
//void test1() {
//	//Home home;
//	goodGay gg;
//	
//	gg.visit();
//};
//
//int main() {
//	test1();
//}

////��Ԫ�࣬ʾ��2��ң�����ǵ��ӻ�����Ԫ��
//#include "Television.h"
//#include "TeleController.h"
//int main() {
//	Television tv1(1,12);
//	TeleController tc;
//	tc.ChannelUp(tv1);
//	tc.VolumeUp(tv1);
//	returnValue res = tv1.TvInfo();  //Television ���ж���һ���ṹ�壬���valume��channel
//
//	cout << "valumeInfo:" << res.valume << endl;
//	cout << "channelInfo:" << res.channel << endl;
//}



////----------��Ԫ��Ա����--------
////���ַ�ʽ���㲻��Ϊɶ������ôд���ܷ��ʵ�Home��˽�г�Ա��������Ԫ̫�����ˣ���Ҫ���ˡ�Ҳ�㲻���к����塣
//class Home; //����Home �������������ҷ���goodGay��ǰ�棬Ϊɶ��
//class goodGay {
//public:
//	goodGay();  //����������Ҳʱ������������ʵ��д�����棬������ʾ��������δ�����Home����Ϊɶ��
//	void visit();
//	void visit2();
//private:
//	Home* hp;//����һ��Home���͵�ָ��
//};
//class Home {
//	friend void goodGay::visit();
//public:
//	//�������캯��
//	Home() {
//		m_SittingRoom = "����";
//		m_BedRoom = "����";
//	};
//	string m_SittingRoom;//����
//private:
//	string m_BedRoom;//����
//};
//
//goodGay::goodGay() {
//	hp = new Home;
//}
//void goodGay::visit() {
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << hp->m_SittingRoom << endl;
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << hp->m_BedRoom << endl; //������Ԫ��Ͳ������ˣ����Է���˽�г�Ա����
//}
//void goodGay::visit2() {
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << hp->m_SittingRoom << endl;
//	//cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << hp->m_BedRoom << endl; //������Ԫ��Ͳ������ˣ����Է���˽�г�Ա����
//}
//void test1() {
//	goodGay gg;
//	gg.visit();
//	gg.visit2();
//};
//
//int main() {
//	test1();
//}


////==============����==================
////+�����������,ʾ��1
//class Person {
//public:
//	int m_A;
//	int m_B;
//	//����1��Ա����ʵ��+������
//	/*Person operator+(Person& p)
//	{
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}*/
//};
////����2��ȫ�ֺ���ʵ��+����
//Person operator+(Person& p1, Person& p2) {
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
//
////����3���Ӻŵĵĺ������أ�ʵ��person=person+int
//Person operator+(Person& p, int num) {
//	Person temp;
//	temp.m_A = p.m_A + num;
//	temp.m_B = p.m_B + num;
//	return temp;
//}
//
//void test1() {
//	Person p1;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	Person p2;
//	p2.m_A = 10;
//	p2.m_B = 10;
//
//	//��Ա�������صı��ʵ���
//	//Person p3 = p1.operator+(p2);
//	//ȫ�ֺ������صı��ʵ���
//	//Person p3 = operator+(p1,p2);
//	// �������ֶ����Լ�Ϊ����һ�֣�
//	Person p3 = p1 + p2;
//	cout << "m_A=" <<p3.m_A << "\tm_B=" << p3.m_B << endl;
//
//	//person=person+int
//	Person p4 = p1 + 100;
//	cout << "m_A=" << p4.m_A << "\tm_B=" << p4.m_B << endl;
//};
//
//int main() {
//	test1();
//}

////+�����������,ʾ��2
//class Complex {
//public:
//	Complex() {}
//	~Complex() {}
//	Complex(int real,int imag):m_real(real),m_imag(imag)
//	{	
//	}
//	//1.��Ա����ʵ����ӣ�ȱ����c1�ᱻ�ı�
//	Complex& Add(const Complex& other) {
//		m_real += other.m_real;
//		m_imag += other.m_imag;
//		return *this;
//	}
//
//	////2. ��Ա����+������ ,��Ա����+����Ԫ����+���Թ��棬�����ȼ�������Ԫ����+
//	//Complex operator+(const Complex& other) {
//	//	int r = m_real + other.m_real;   //����������Բ�ʹ��this
//	//	int i = this->m_imag + other.m_imag; //ʹ��this���Ÿ�����һ��
//	//	return Complex(r, i);//ʹ�ù��캯�������һ�����󲢷���
//	//}
//
//	//3.��Ԫ����+������
//	friend Complex operator+(const Complex& com1,const Complex& com2) {
//		int r = com1.m_real + com2.m_real;   //����������Բ�ʹ��this
//		int i = com1.m_imag + com2.m_imag; //ʹ��this���Ÿ�����һ��
//		return Complex(r, i);//ʹ�ù��캯�������һ�����󲢷���
//	}
//	void Display() const
//	{
//		cout << m_real << "+" << m_imag << "i" << endl;
//	}
//private:
//	int m_real;
//	int m_imag;
//};
//
//int main() {
//	Complex c1(1, 3);
//	Complex c2(2, 4);
//	////1.��Ա����ʵ����ӣ�ȱ����c1�ᱻ�ı�
//	//c1.Add(c2);
//	//c1.Display();
//	
//	//2. ��Ա����+������  //3.��Ԫ����+������
//	Complex c3 = c1 + c2;
//	c3.Display();
//}

////-----�����������<<������-----
//#include <fstream>
//class Person {
//	
//	friend ostream& operator<<(ostream& cout, Person& p);
//public:
//	Person(int a, int b) :m_A(a), m_B(b) {};
//private:
//	int m_A;
//	int m_B;
//};
////�޷�ʵ�ֳ�Ա��������<<�����
//ostream & operator<<(ostream &cout, Person &p) {  //cout��ostream�ķ�������
//	cout << "m_A=" << p.m_A << "\tm_B=" << p.m_B;
//	return cout;
//}
//void test1() {
//	Person p1(10,10);
//	cout << p1 <<"\tʵ���ˡ�<<���� ����." << endl;;
//};
//
//int main() {
//	test1();
//}

////�Ⱥ����������
//#include "string.h"
//#include <iostream>
//using namespace std;
//
//class Str {
//public:
//	explicit Str(const char* str) //ת�����캯�������ַ���str�����Str���� , explicit����޷���ʽ������
//	{  
//		cout << "���ã�Str(const char* str)//ת�����캯��" << endl;
//		m_str = AllocAndCpy(str);
//	}
//	Str(const Str& other) //�������캯��
//	{  
//		cout << "���ã�Str(const Str& other)//�������캯��" << endl;
//		m_str = AllocAndCpy(other.m_str);
//	}
//	Str& operator=(const Str& other) //��ֵ���������
//	{
//		cout << "���ã�Str& operator=(const Str& other))//��ֵ���������" << endl;
//		if (&other == this)
//			return *this; //����Ⱥ��ұ߸������ͬ����ֱ�ӷ��ض�����������ֵ����
//		delete[] m_str;//�ͷŵ��Լ����ڴ棬Ȼ���ٸ�ֵ
//		m_str= AllocAndCpy(other.m_str);
//		return *this;
//	}
//
//	Str& operator=(const char* str) //�ַ�����ֵ���������
//	{
//		cout << "Str& operator=(const char* str) //�ַ�����ֵ���������" << endl;
//		delete[] m_str;//�ͷŵ��Լ����ڴ棬Ȼ���ٸ�ֵ
//		m_str = AllocAndCpy(str);
//		return *this;
//	}
//
//	void Display() const 
//	{
//		cout << "m_str=" << m_str << endl;
//	}
//
//	~Str() {
//		delete[] m_str;
//	}
//
//private:
//	char* m_str;
//	char* AllocAndCpy(const char* str) {
//		int len = strlen(str) + 1;  //strlen()���ص����ַ��������������ַ����Ľ�����
//		char* newstr = new char[len];
//		memset(newstr, 0, len); //��newstr����len��0
//		strcpy_s(newstr, len, str); //�������������󣬿������ȣ���������
//
//		return newstr;
//	}
//};
//
//int main() {
//	Str s1("abc");
//	//Str s2(s1); //���ÿ������캯��
//	//s2.Display();
//
//	//Str s3("");//���ÿ������캯��
//	//s3= s1;//���ø�ֵ���������
//	//s3.Display();
//
//	Str s4("");
//	s4= "xxx"; //����explicit��ת�����캯���޷������ã������������Str& operator=(const char* str) ��Ϳ���ֱ�ӵ�����
//	//Str s4="xxx"; //���ַ��������Ƚ���ֵת��ΪStr���󣬵�û����Ӧ�Ĺ��캯��
//	s4.Display();
//}




//========�̳�==========
//class BasePage {
//public:
//	void header() {
//		cout << "��ҳ��ע�ᣬ��¼..." << endl;
//	}
//	void left() {
//		cout << "java��python��c++ �γ̷����б�..." << endl;
//	}
//	void footer() {
//		cout << "�������ģ�վ�ڵ�ͼ����������..." << endl;
//	}
//};
//
//class Java :public BasePage {
//public:
//	void content() {
//		cout << "JAVA ��Ƶ�̳�" << endl;
//	}
//};
//class Python :public BasePage {
//public:
//	void content() {
//		cout << "Python ��Ƶ�̳�" << endl;
//	}
//};
//class Cpp :public BasePage {
//public:
//	void content() {
//		cout << "C++ ��Ƶ�̳�" << endl;
//	}
//};
//
//void test() {
//	cout << "-----javaҳ��-----" << endl;
//	Java java;
//	java.header();
//	java.left();
//	java.footer();
//	java.content();
//
//	cout << "-----pythonҳ��-----" << endl;
//	Python python;
//	python.header();
//	python.left();
//	python.footer();
//	python.content();
//
//	cout << "-----cppҳ��-----" << endl;
//	Cpp cpp;
//	cpp.header();
//	cpp.left();
//	cpp.footer();
//	cpp.content();
//}
//int main() {
//	test();
//}

////----�̳е�Ȩ��----
//class BasePage {
//public:
//	BasePage() {
//		cout << "BasePage ����..." << endl;
//	}
//	~BasePage() {
//		cout << "BasePage ����..." << endl;
//	}
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//class Son :protected BasePage {
//public:
//	Son() {
//		cout << "Son ����..." << endl;
//	}
//	~Son() {
//		cout << "Son ����..." << endl;
//	}
//	int m_D;
//	void setValue() {
//		m_A = 10;
//		m_B = 20;
//	}
//	int getValueA() {
//		return m_A;
//	}
//	int setValueB() {
//		return m_B;
//	}
//};
//void testInherite() {
//	Son son;
//	son.m_D = 200;
//	son.setValue();
//	cout << son.getValueA() << endl;
//	cout << son.setValueB() << endl;
//	cout << son.m_D << endl;
//}
//
//int main() {
//	testInherite();
//}


////��̳н����ʯ�̳еĶ��������⣬���������ο���
////�����Furniture����ʯ����SofaBed������
//#include<iostream>
//using namespace std;
//class Furniture //�����
//{
//public:
//	Furniture(int weight):m_weight(weight)
//	{
//		cout << "Furniture..." << endl;
//	}
//	~Furniture()
//	{
//		cout << "~Furniture..." << endl;
//	}
//	int m_weight;
//};
//
//class Bed :virtual public Furniture //��̳�
//{
//public:
//	Bed(int weight):Furniture(weight) //��̳�Ҫʹ�û���Ĺ����������Լ���
//	{
//		cout << "Bed..." << endl;
//	}
//	~Bed()
//	{
//		cout << "~Bed..." << endl;
//	}
//	void Sleep() {
//		cout << "The Bed can be used for sleeping!" << endl;
//	}
//};
//
//class Sofa :virtual public Furniture //��̳�
//{
//public:
//	Sofa(int weight):Furniture(weight) //��̳�Ҫʹ�û���Ĺ����������Լ���
//	{
//		cout << "Sofa..." << endl;
//	}
//	~Sofa()
//	{
//		cout << "~Sofa..." << endl;
//	}
//	void Sit() {
//		cout << "The Sofa can be used for siting" << endl;
//	}
//};
//
//class SofaBed :public Bed, public Sofa
//{
//public:
//	SofaBed(int weight):Bed(weight), Sofa(weight), Furniture(weight) //ȫ��Ҫд������
//	{
//		cout << "SofaBed..." << endl;
//		FoldIn(); //Ĭ���۵�
//	}
//	~SofaBed()
//	{
//		cout << "SofaBed..." << endl;
//	}
//	void FoldOut() {
//		cout << "SofaBed can be FoldOut" << endl;
//	}
//	void FoldIn() {
//		cout << "SofaBed can be FoldIn" << endl;
//	}
//};
//int main() {
//	SofaBed sofaBed(100);
//	sofaBed.m_weight = 200;
//	sofaBed.FoldIn();
//	sofaBed.Sit();
//	sofaBed.FoldOut();
//	sofaBed.Sleep();
//}




//��ӡ��Ľṹ
// �򿪡�Develop Command Prompt ...��
// cd D:\c_study\hellow_world\hellow_world\
//cl /d1 reportSingleClassLayoutBasePage hellow_world.cpp
//cl /d1 reportSingleClassLayoutSon hellow_world.cpp

//=========��̬=========
/*
���ܣ�����ָ��ָ��������Ķ��󣬵��õ�����������麯��

����̬�ص㣺�������أ����������


����̬(����ʱȷ��������ַ)
����������
1. �м̳й�ϵ
2. ������д�����麯��
���÷�����
����ָ��ָ������ָ���������
�ŵ㣺���
ȱ�㣺����ʱ��Ҫ�в����麯����Ĺ��̣�Ч�ʽϵ�
*/

//class Animal {
//public:
//	//��̬��̬��Ҫ�����麯����virtual���Σ� ����ʱ����ָ�������ĵ���
//	virtual void speek() {
//		cout << "������˵��..." << endl;
//	}
//};
//class Cat:public Animal {
//public:
//	virtual void speek() {	//��д���ຯ��ʱ��virtual��ʡ�ԣ��μ�Dog��
//		cout << "Сè��˵��..." << endl;
//	}
//};
//class Dog :public Animal {
//public:
//	void speek()  {
//		cout << "С����˵��..." << endl;
//	}
//};
//
//void doSpeek(Animal &animal) {
//	animal.speek();
//}
//
//void test() {
//	Cat cat;
//	doSpeek(cat);  //*animal->cat
//	Dog dog;
//	doSpeek(dog);  //*animal->dog
//}
//
//int main() {
//	test();
//}

//----------��̬ʵ��----------
/*
�ŵ㣺�ɶ���ǿ�����ں�����չ��ά��
*/
//--��ͨ��ʽʵ�ּ���������--
//class Calculator {
//public:	
//	int getResult(string oper) {
//		if (oper == "+") {
//			return m_Num1 + m_Num1;
//		}
//		else if (oper == "-") {
//			return m_Num1 - m_Num2;
//		}
//		//���Ҫ�ṩ�µ����㣬��Ҫ�޸����Դ��
//	}
//public:
//	int m_Num1;
//	int m_Num2;
//};
//
//void test() {
//	Calculator c;
//	c.m_Num1 = 10;
//	c.m_Num2 = 10;
//	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
//	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
//}
//int main() {
//	test();
//}



////--��̬��ʽʵ�ּ���������--
////����������������
//class AbstractCalculator {
//public:
//	/*virtual int getResult() {
//		return 0;
//	}*/
//	virtual int getResult() = 0; //���麯��
//	int m_Num1;
//	int m_Num2;
//};
////�ӷ�����
//class AddCalculator :public AbstractCalculator {
//public:
//	//��д�麯��������������Ȼ�Ǵ��麯��
//	virtual int getResult() {
//		return m_Num1+m_Num2;
//	}
//};
////��������
//class SubCalculator :public AbstractCalculator {
//public:
//	virtual int getResult() {
//		return m_Num1 - m_Num2;
//	}
//};
////��չ���˷����㣬ֻ��Ҫ��չ�Ϳ����ˣ�����Ҫ�޸ĸ������
//class MulCalculator :public AbstractCalculator {
//public:
//	virtual int getResult() {
//		return m_Num1 * m_Num2;
//	}
//};
//void test() {
//	//AbstractCalculator c; //���麯���޷�ʵ����
//
//	//�ӷ�ָ�룬�ø��ഴ��ָ�룬ָ�������ڶ������ٵĵ�ַ
//	AbstractCalculator * p_Add =new AddCalculator;
//	p_Add->m_Num1 = 10;
//	p_Add->m_Num2 = 10;
//	cout << p_Add->m_Num1 << "+" << p_Add->m_Num2 << "=" << p_Add->getResult() << endl;
//	delete p_Add;
//
//	//����ָ��
//	AbstractCalculator* p_Sub = new SubCalculator;
//	p_Sub->m_Num1 = 10;
//	p_Sub->m_Num2 = 10;
//	cout << p_Sub->m_Num1 << "-" << p_Sub->m_Num2 << "=" << p_Sub->getResult() << endl;
//	delete p_Sub;
//
//	//�˷�ָ��
//	AbstractCalculator* p_Mul = new MulCalculator;
//	p_Mul->m_Num1 = 10;
//	p_Mul->m_Num2 = 10;
//	cout << p_Mul->m_Num1 << "*" << p_Mul->m_Num2 << "=" << p_Mul->getResult() << endl;
//	delete p_Mul;
//}
//
//int main() {
//	test();
//}

//-- ��̬ ���麯�� --
//ӵ�д��麯��������������࣬�����������������
//���麯������Ҫʵ�֣�ʵ�ֵ����齻��������

////���麯�� �����࣬ʵ��1����������
//class AbstractDrinking {
//public:
//	virtual void Boil() = 0; //��ˮ�����麯��������д
//	virtual void PutSomething() = 0; //���븨��
//	//virtual void waitMinutes() = 0; //�ȴ������ӣ�����Ǵ��麯�������Ӻ���������д�����򱨴�
//	virtual void waitMinutes() { //�麯������Ҫ��д
//		cout << "�ȴ�������" << endl;
//	}
//	void makeDrink() {
//		Boil();
//		PutSomething();
//		waitMinutes();
//	}
//};
////��������
//class Coffee :public AbstractDrinking {
//public:
//	
//	virtual void Boil() {
//		cout << "��ũ��ɽȪˮ"<<endl;
//	}
//	virtual void PutSomething() {
//		cout << "�������ܿ���"<<endl;
//	}
//	/*virtual void waitMinutes() {
//		cout << "�ȴ�������" << endl;
//	}*/
//};
////������ˮ
//class Tee :public AbstractDrinking {
//public:
//	virtual void Boil() {
//		cout << "���޹�������ˮ" << endl;
//	}
//	virtual void PutSomething() {
//		cout << "�����Ҷ" << endl;
//	}
//	/*virtual void waitMinutes() {
//		cout << "�ȴ�������" << endl;
//	}*/
//};
//
//void doWork(AbstractDrinking * pAbs) { //����
//	pAbs->makeDrink();
//	delete pAbs;
//}
//
//void test() {
//	doWork(new Coffee);
//	cout << "----------------" << endl;
//	doWork(new Tee);
//}
//
//int main() {
//	test();
//}

////���麯�� ������ʵ��2����
//#include <vector>
//class Shape
//{
//public:
//	virtual void Draw() = 0;
//	virtual ~Shape() {}
//};
//class Circle :public Shape
//{
//public:
//	void Draw() {
//		cout << "Circle::Draw()" << endl;
//	}
//	virtual ~Circle() {
//		cout << "virtual ~Circle" << endl;
//	}
//};
//class Square :public Shape
//{
//public:
//	void Draw() {
//		cout << "Square::Draw()" << endl;
//	}
//	virtual ~Square() {
//		cout << "virtual ~Square" << endl;
//	}
//};
//void DrawAllShapes(const vector<Shape*>& v)
//{
//	vector<Shape*>::const_iterator it;
//	for (vector<Shape*>::const_iterator it = v.begin();it != v.end();++it) {
//		(*it)->Draw();
//	}
//}
//void DeleteAllShapes(const vector<Shape*>& v)
//{
//	vector<Shape*>::const_iterator it;
//	for (vector<Shape*>::const_iterator it = v.begin();it != v.end();++it) {
//		delete *it;
//	}
//}
////�򵥹���ģʽ
//class ShapeFactory
//{
//public:
//	static Shape* CreateShape(const string& shapeName) {
//		Shape* ps = 0;
//		if (shapeName == "Circle") {
//			ps = new Circle;
//		}
//		else if (shapeName == "Square") {
//			ps = new Square;
//		}
//		return ps;
//	}
//};
//int main() {
//	//Shape s;//Error,�����಻��ʵ��������
//	vector<Shape*> v;//Shape���͵�ָ������
//	Shape* ps;	//Shape���͵�ָ��
//
//	//ps = new Circle;
//	ps = ShapeFactory::CreateShape("Circle");
//	v.push_back(ps);
//
//	//ps = new Square;
//	ps = ShapeFactory::CreateShape("Square");
//	v.push_back(ps);
//
//	DrawAllShapes(v); //Circle::Draw()  Square::Draw()
//	DeleteAllShapes(v); //ɾ�����󣬷�ֹ�ڴ�й¶
//}

////��̬��������
////��̬���ö��󷽷�
////��̬������������
////��Ҫ��ÿ�������Ԫ����
//#include <vector>
//#include "Shape.h"
//#include "DynBase.h"
//#include <string>;
//void DrawAllShapes(const vector<Shape*>& v)
//{
//	vector<Shape*>::const_iterator it;
//	for (vector<Shape*>::const_iterator it = v.begin();it != v.end();++it) {
//		(*it)->Draw();
//	}
//}
//void DeleteAllShapes(const vector<Shape*>& v)
//{
//	vector<Shape*>::const_iterator it;
//	for (vector<Shape*>::const_iterator it = v.begin();it != v.end();++it) {
//		delete* it;
//	}
//};
//
//int main() {
//		vector<Shape*> v;//Shape���͵�ָ������
//		Shape* ps;	//Shape���͵�ָ��
//		ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Circle"));
//		v.push_back(ps);
//	
//		//ps = new Square;
//		ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Square"));
//		v.push_back(ps);
//	
//		//DrawAllShapes(v); //Circle::Draw()  Square::Draw()
//		//DeleteAllShapes(v); //ɾ�����󣬷�ֹ�ڴ�й¶
//}


//RTTI
// ��̬ת��
// static_cast ���ڱ������Ͽɵ�ת��
// reinterpret_cast ���ڱ��������Ͽɵ�ת�ͣ�������������������Բ������ʹ��
// const_cast ȥ��������
// ����ʱת�ͣ����ܲ����麯��
//dynamic_cast<> 1,�����ڳ������ϣ�2.��������������������ʱ������Ϣ��Ĭ�Ͽ�������
//typeid()����typeinfo����

//class Shape
//{
//public:
//	virtual void Draw() = 0;
//	virtual ~Shape() {}
//};
//class Circle :public Shape
//{
//public:
//	void Draw() {
//		cout << "Circle::Draw()" << endl;
//	}
//};
//class Square :public Shape
//{
//public:
//	void Draw() {
//		cout << "Square::Draw()" << endl;
//	}
//};
//class Rectangle :public Shape
//{
//public:
//	void Draw() {
//		cout << "Rectangle::Draw()" << endl;
//	}
//};
//
//int main() {
//	Shape* p_Shape;
//	Circle c;
//	p_Shape = &c;
//	/*Square s;
//	p_Shape = &s;*/
//	/*Rectangle r;
//	p_Shape = &r;*/
//
//	if (dynamic_cast<Circle*>(p_Shape)) 
//	{
//		cout << "p_Shape is point to Circle object" << endl;
//		Circle* p_Circle = dynamic_cast<Circle*>(p_Shape); //��ȫ����ת�ͣ���ΪShape�ǳ����࣬�����ǲ���ȫ��
//		p_Circle->Draw();
//	}
//	else if(dynamic_cast<Square*>(p_Shape))
//	{
//		cout << "p_Shape is point to Square object" << endl;
//		Square* p_Square = dynamic_cast<Square*>(p_Shape); //��ȫ����ת��
//		p_Square->Draw();
//	}
//	else
//	{
//		cout << "p_Shape is point to other object" << endl;
//	}
//	
//	//typeid()->typeinfo����
//	//cout << typeid(*p_Shape).name() << endl; //class Rectangle ��ָ��ָ���������������д��ָ�뱾��
//	//cout << typeid(Circle).name() << endl; //class Circle
//	if (typeid(*p_Shape).name()==typeid(Circle).name()) //ָ��ָ���������Circle������ͬ����...
//	{
//		cout << "p_Shape is point to Circle object" << endl;
//		((Circle*)p_Shape)->Draw(); //��ȫ����ת�ͣ����ܵ�ͬ��dynamic_cast
//	}
//	else if (typeid(*p_Shape).name() == typeid(Square).name())
//	{
//		cout << "p_Shape is point to Square object" << endl;
//		((Square*)p_Shape)->Draw(); //��ȫ����ת�ͣ����ܵ�ͬ��dynamic_cast
//	}
//	else
//	{
//		cout << "p_Shape is point to other object" << endl;
//	}
//}



//--������/��������--
/*
���ã�
1.�������ָ����ͷ��������
�������ʹ�����������
�����ʹ�����ɳ����࣬�޷�ʵ��������
*/
//class Animal {
//public:
//	Animal() {
//		cout << "-->Animal���캯������" << endl;
//	}
//	////��ͨ�����������ᵼ����delete����ָ��ʱ���޷���������������������Բ�����ô
//	//~Animal() {
//	//	cout << "<--Animal������������" << endl;
//	//}
//
//	////������
//	//virtual ~Animal() {
//	//	cout << "<--Animal������������" << endl;
//	//}
//	
//	//��������,��Ҫ�о���ʵ�֣������˴��������������ͱ���˳����࣬�޷�ʵ����
//	virtual ~Animal() = 0;
//	virtual void speek() = 0;
//};
////����������ʵ��
//Animal::~Animal() {
//	cout << "<--Animal������������" << endl;
//}
//
//class Cat:public Animal {
//public:
//	Cat(string name) {
//		m_Name = new string(name);
//		cout << "-->Cat���캯���ѵ���" << endl;
//	}
//	~Cat() {
//		if (m_Name != NULL) {
//			delete m_Name;
//			m_Name = NULL;
//			cout << "<--Cat���������ѵ���" << endl;
//		}
//	}
//	virtual void speek() {	//��д���ຯ��ʱ��virtual��ʡ�ԣ��μ�Dog��
//		cout <<*m_Name<< "Сè��˵��..." << endl;
//	}
//	string* m_Name; //����һ��ָ��ָ�������string���͵�name
//};
//class Dog :public Animal {
//public:
//	void speek()  {
//		cout << "С����˵��..." << endl;
//	}
//};
//
//void doSpeek(Animal &animal) {
//	animal.speek();
//}
//
//void test() {
//	////����1,���ֵ��÷�����ֻ�и�����Ҫ������ʱ��Ż��������������������Ϊ���ƶ����ͷ�
//	//Cat cat("TOM");
//	//doSpeek(cat); 
//	//Dog dog;
//	//doSpeek(dog); 
//	///*
//	//--Animal���캯������
//	//--Cat���캯���ѵ���
//	//TOMСè��˵��...
//	//--Animal���캯������
//	//С����˵��...
//	//--Animal������������
//	//--Cat���������ѵ���
//	//--Animal������������
//	//*/
//
//	//����2,����/������/��������
//	Animal* pAnimal = new Cat("�ӷ�");
//	pAnimal->speek();
//	delete pAnimal;  //���ʱ��û�а�Cat���������������ڴ�й¶
//	cout << "------------------------" << endl;
//	Dog dog;
//	doSpeek(dog);
//	/*
//	-->Animal���캯������
//	-->Cat���캯���ѵ���
//	�ӷ�Сè��˵��...
//	//�ڴ�й¶�㣺С��������û�е���
//	<--Animal������������
//
//	-->Animal���캯������
//	С����˵��...
//	<--Animal������������
//	*/
//}
//
//int main() {
//	test();
//}

//�麯���ĵ���
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//};
//class Derived:public Base
//{
//public:
//	/*virtual */void Func1() //ʡ��vertual�ؼ��֣�����Ȼ���麯����
//	{
//		cout << "Derived::Func1()" << endl;
//	}
//	/*virtual */void Func2() //ʡ��vertual�ؼ��֣�����Ȼ���麯����
//	{
//		cout << "Derived::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Derived::Func3()" << endl;
//	}
//};
//int main() {
//	Derived d;
//	Base* p_Base=&d;
//
//	p_Base->Func1(); //Derived::Func1() �麯���Ǹ���ָ��ָ��Ķ��������õ�
//	p_Base->Func2(); //Derived::Func2() �麯���Ǹ���ָ��ָ��Ķ��������õ�
//	p_Base->Func3(); //Base::Func3() ���麯���Ǹ���ָ�����͵��õ�
//}

////������
//class Base
//{
//public:
//	 Base() {
//		cout << "Base..." << endl;
//	}
//	 virtual ~Base() {
//		cout << "~Base..." << endl;
//	}
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//};
//class Derived:public Base
//{
//public:
//	Derived() {
//		cout << "Derived..." << endl;
//	}
//	 ~Derived() {
//		cout << "~Derived..." << endl;
//	}
//	/*virtual */void Func1() //ʡ��vertual�ؼ��֣�����Ȼ���麯����
//	{
//		cout << "Derived::Func1()" << endl;
//	}
//	/*virtual */void Func2() //ʡ��vertual�ؼ��֣�����Ȼ���麯����
//	{
//		cout << "Derived::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Derived::Func3()" << endl;
//	}
//};
//int main() {
//	Base* p_Base=new Derived; //������������Base... Derived... 
//
//	p_Base->Func1(); //Derived::Func1() �麯���Ǹ���ָ��ָ��Ķ��������õ�
//
//	delete p_Base; //~Base... ��������û�б����������ڴ�й¶ ��ʹ������������DerivedҲ�ᱻ��������
//}


//�麯���б�ָ��
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//
//	int m_dataBase;
//};
//class Derived:public Base
//{
//public:
//	void Func2()  //�̳��麯��
//	{
//		cout << "Derived::Func2()" << endl;
//	}
//	virtual void Func3()  //�̳��麯��
//	{
//		cout << "Derived::Func3()" << endl;
//	}
//	int m_dataDerived;
//};
//typedef void (*FUNC)();
//int main() {
//	cout << sizeof(Base) << endl; //16 = 8�����ָ�룩+ 8��4��int m_data�������=8��
//	cout << sizeof(Derived) << endl; //24=8�����ָ�룩+ 8��4��int m_dataBase�������=8�� + 8��4��int m_dataDerived�������=8��
//
//	//Base b;
//	//long** p = (long**)&b;
//	//FUNC fun = (FUNC)p[0][0]; //Base::Func1()��ָ���麯����
//	//fun(); //x86���гɹ���64Ϊɶ����
//	//fun = (FUNC)p[0][1]; //Base::Func2()��ָ���麯����
//	//fun(); //x86���гɹ���64Ϊɶ����
//
//	Derived d;
//	long** p = (long**)&d;
//	FUNC fun = (FUNC)p[0][0]; //Base::Func1()������е�һ���ǻ�����麯��
//	fun(); 
//	fun = (FUNC)p[0][1]; //Derived::Func2()������е�2������������麯��
//	fun(); 
//	fun = (FUNC)p[0][2]; //Derived::Func3()��������е�3������������麯��
//	fun(); 
//}

////�и�
//class CObject
//{
//public:
//	virtual void Serialize()
//	{
//		cout << "CObject::virtual void Serialize()" << endl;
//	}
//
//};
//class CDocument :public CObject
//{
//public:
//	//CDocument(const CDocument& other) //��������
//	//{ 
//	//	cout << "CDocument(const CDocument& other)" << endl;
//	//}
//	int m_data_CDocument;
//	void func()
//	{
//		cout << "Document::func" << endl;
//		Serialize();
//	}
//	virtual void Serialize()
//	{
//		cout << "CDocument::virtual void Serialize()" << endl;
//	}
//};
//class CMyDoc :public CDocument
//{
//public:
//	int m_data_CMyDoc;
//	virtual void Serialize()
//	{
//		cout << "CMyDoc::virtual void Serialize()" << endl;
//	}
//};
//
//int main() {
//	CMyDoc mydoc;
//	CMyDoc* p_mydoc = new CMyDoc; //���������ָ�룬
//
//	cout << "#1 testing" << endl;
//	mydoc.func();	//Document::func���̳и������ͨ��Ա������  
//	//CMyDoc::virtual void Serialize() �����Լ����麯��
//
//	cout << "#2 testing" << endl;
//	((CDocument*)(&mydoc))->func(); //ͬ�� ��ֻ�ǽ�����ǿת��ָ��
//
//	cout << "#3 testing" << endl;
//	p_mydoc->func(); //ͬ�ϣ�ָ�������ͨ��Ա����
//
//	cout << "#4 testing" << endl;
//	((CDocument)mydoc).func(); //CDocument::virtual void Serialize()��Serialize��ȫת��Ϊ�������
//}



//========�ļ�����====================

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	FILE* fp;
//	errno_t err;                                    //��ͬ��1
//	char ch, filename[10];
//	printf("���������õ��ļ�����");
//	scanf_s("%s", filename, 10);
//	if ((err = fopen_s(&fp, filename, "w")) != 0)    //��ͬ��2
//	{
//		printf("�޷��򿪴��ļ�\n");            //����򲻿���������򲻿�
//		exit(0);                               //��ֹ����
//	}
//	ch = getchar();                            //���������������Ļس���
//	printf("������һ��׼���洢�����̵��ַ�������#��������");
//	ch = getchar();                            //�������մӼ�������ĵ�һ���ַ�
//	while (ch != '#')                          //�����롰#��ʱ����ѭ��
//	{
//		fputc(ch, fp);                         //��������һ���ַ�
//		putchar(ch);                           //��������ַ���ʾ����Ļ��
//		ch = getchar();                        //�ٽ��մӼ��������һ���ַ�
//	}
//	fclose(fp);                                //�ر��ļ�
//	putchar(10);                               //����Ļ���һ�����з�
//	return 0;
//}


/*
#include xxx����������
ofstream	д����
ifstream	������
fstream		��д����
�򿪷�ʽ��
ios::in		ֻ����
ios::out	ֻд
ios::ate	��ʼλ�ã��ļ�β
ios::app	append׷�ӷ�ʽд�ļ�
ios::trunc	�ļ�����ʱ���������ļ���������
ios::binary	�����Ʒ�ʽ
�û����
ios::binary | ios::iosapp
*/

//void fWrite() {
//	//1.����������
//	ofstream f_obj;
//	//2.ָ���򿪷�ʽ
//	f_obj.open("./test.txt", ios::out);
//	//3.д����
//	f_obj << "������������" << endl;
//	f_obj << "�ձ�Ů" << endl;
//	f_obj << "���䣺2" << endl;
//	f_obj << "----------------" << endl;
//	//4.�رն���
//	f_obj.close();
//}
//void fAppend() {
//	//1.����������
//	ofstream f_obj;
//	//2.ָ���򿪷�ʽ
//	f_obj.open("./test.txt", ios::app);
//	//3.д����
//	f_obj << "����������" << endl;
//	f_obj << "�ձ�Ů" << endl;
//	f_obj << "���䣺20" << endl;
//	f_obj << "----------------" << endl;
//	//4.�رն���
//	f_obj.close();
//}

//4�ֶ��ļ���ʽ��
//void fRead() {
//	ifstream ifs;
//	ifs.open("./test.txt", ios::in);
//	
//	if (!ifs.is_open()) {
//		cout << "�ļ���ʧ��" << endl;
//		return ;
//	}
//
//	////����1������
//	//char buf[1024] = { 0 };
//	//while (ifs>>buf) {  //��buf���������Ϣ��������
//	//	cout << buf << endl;
//	//}
//
//	////����2�����ж�
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf,sizeof(buf))) {  //��buf���������Ϣ��������
//	//	cout << buf << endl;
//	//}
//
//	//����3��string ͷ�ļ��Դ���getline����
//	string buf;
//	while (getline(ifs,buf)) {  //��buf���������Ϣ��������
//		cout << buf << endl;
//	}
//
//	////����4
//	//char c;
//	//while ((c=ifs.get())!=EOF)  //End Of File
//	//{
//	//	cout << c ;
//	//}
//	ifs.close();
//}
//int main() {
//	//fWrite();  //д
//	//fAppend();	//׷��
//	fRead(); 
//}


//#include <cassert>
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//int main()
//{
//	ofstream fout("test.txt");
//	assert(fout);
//	char ch;
//	for (int i = 0; i < 26;i++)
//	{
//		ch = 'A' + i;
//		fout.put(ch);
//	}
//	fout.close();
//
//	ifstream fin("test.txt");
//	while (fin.get(ch))
//	{
//		cout << ch;
//	}
//	cout << endl;
//	fin.close();
//}

//�����ƶ�д�ļ���
/*
������ı���ʽ���ļ���д���ַ���ʱ������\n����ת��
windowsƽ̨nתΪ\r\n
linuxƽ̨��������
macϵͳinתΪ\r
����Զ����Ʒ�ʽ���ļ�д���ַ���ʱ������\n������ת��
*/
//#include <fstream>
//int main() 
//{
//	ofstream fout("test.txt", ios::out | ios::binary);
//	fout << "ABC\r\n";
//	fout.close();
//
//	return 0;
//}



//#include <fstream>
////���ֲ���string�Ľṹ��̫���ˣ�����������������
//struct Person {
//	char m_Name[64];  //������char��ʽ���ײ���Cд�ģ�������Ҫ��string����Ϊ�п��ܲ����쳣��Ϣ
//	int m_Age;
//};
//void fWrite() {
//	ofstream ofs("./test.txt", ios::out|ios::binary);
//	//ofs.open("./test.txt", ios::in); //�ɼ�Ϊ��һ��
//	
//	if (!ofs.is_open()) {
//		cout << "�ļ���ʧ��" << endl;
//		return ;
//	}
//	Person p = { "����",18 };
//	ofs.write((const char*)&p, sizeof(p));
//	ofs.close();
//}
////���������ļ���
//void fRead() {
//	ifstream ifs("./test.txt", ios::in | ios::binary);
//	if (!ifs.is_open()) {
//		cout << "�ļ���ʧ��" << endl;
//		return ;
//	}
//
//	Person p;
//	ifs.read((char*)&p, sizeof(p));  //ǿת��char *���Ե�ַ��ȡ�����ַ�� �����ռ��С��
//
//	cout << "������"<<p.m_Name << endl;
//	cout << "���䣺"<<p.m_Age << endl;
//
//	ifs.close();
//}
//int main() {
//	fWrite();  
//	//fAppend();	
//	fRead(); 
//}

//#include <cassert>
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//struct Test
//{
//	int a;
//	string b;
//	string c;
//};
//int main() {
//	Test t1;
//	t1.a = 100;
//	t1.b = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
//	t1.c = "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC";
//
//	/* ���ܰ��սṹ��Ĵ�С����Ϊ�жϣ���Ϊ�ṹ�����ŵ���ʵ�����ݵ�ָ�룬��������ʵ�ַ����Ĵ�С��
//	ofstream fout("test.txt", ios::out | ios::binary);
//	fout.write((char*)&m1, sizeof(m1));
//	fout.close();
//	MyStruct m2;
//	ifstream fin("test.txt", ios::out | ios::binary);
//	fin.read((char*)&m2, sizeof(MyStruct));
//	cout << m2.a << " " << m2.b << " " << m2.c << endl;
//	fin.close();*/
//
//	ofstream fout("test.txt", ios::out | ios::binary);
//	//fout.write((char*)&t1, sizeof(t1));
//	fout.write((char*)&t1.a, sizeof(int));
//	int len;
//	len = t1.b.length();
//	fout.write((char*)&len, sizeof(int));
//	fout.write(t1.b.data(),t1.b.length());
//	len = t1.c.length();
//	fout.write((char*)&len, sizeof(int));
//	fout.write(t1.c.data(), t1.c.length());
//	fout.close();
//
//	ifstream fin("test.txt", ios::in | ios::binary);
//	Test t2;
//	fin.read((char*)&t2.a, sizeof(int));
//	fin.read((char*)&len, sizeof(int));
//	t2.b.resize(len);
//	fin.read(&t2.b[0], len);
//
//	fin.read((char*)&len, sizeof(int));
//	t2.c.resize(len);
//	fin.read(&t2.c[0], len);
//	cout << t2.a << " "<<t2.b<<" " << t2.c << endl;
//	fin.close();
//}

////�����ȡ
//#include<cassert>
//#include<fstream>
//#include<string>
////randomRead.txt ��abcdefg 7���ַ�
//int main() {
//	ifstream fin("randomRead.txt");
//	assert(fin);
//	fin.seekg(2); //��ָ��ָ��2
//	char ch;
//	fin.get(ch); //��ȡ������ֵ����ch��
//	cout << ch << endl; //c
//
//	fin.seekg(-1, ios::end);
//	fin.get(ch);
//	cout << ch << endl; //g, ���һ��
//
//	fin.seekg(0, ios::end);
//	streampos pos = fin.tellg(); //��ȡָ��ƫ��λ��
//	cout << pos << endl;//7 ,���һ���ַ���ָ��
//}

////�ַ�������ʾ��2��������������ַ�����ȡ����������һ���ַ���
//#include<string>
//#include<sstream>
//int main() {
//	string tmpStr;
//	string word;
//	while (getline(cin,tmpStr)) 
//	{
//		istringstream iss(tmpStr);
//		while (iss >> word)
//			cout << word << "#";
//		cout << endl;			
//	}
//}

////�ַ�������ʾ��2����double����ת����string����, ��stringתdouble
//#include<string>
//#include<sstream>
//string doubleToStr(double d) 
//{
//	ostringstream oss;
//	oss << d; //��double����oss����
//	cout << typeid(oss.str()).name() << endl; //class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
//	return oss.str();
//}
//double stringToDouble(const string& str)
//{
//	double val;
//	istringstream iss(str);
//	iss>>val; //��double����oss����
//	return val;
//}
//int main() {
//	double val = 55.55;
//	string str = doubleToStr(val);
//	cout << str << endl;
//
//	string str1="123.1123";
//	double d1;
//	d1= stringToDouble(str1);
//	cout << d1 << endl;
//}

////�ַ�������ʾ��3��
//#include<string>
//#include<sstream>
//int main() {
//	//����������������
//	//istringstream iss("192,168,0,100");
//	//int v1;
//	//int v2;
//	//int v3;
//	//int v4;
//	//char ch;
//	//iss >> v1 >> ch >> v2 >> ch >> v3 >> ch >> v4;
//
//	//ch = '.';
//	//ostringstream oss;
//	//oss << v1 << ch << v2 << ch << v3 << ch << v4;
//	//cout << oss.str() << endl;
//
//
//	//stringstream �����������
//	stringstream iss("192,168,0,100");
//	int v1;
//	int v2;
//	int v3;
//	int v4;
//	char ch;
//	iss >> v1 >> ch >> v2 >> ch >> v3 >> ch >> v4;
//
//	ch = '.';
//	stringstream oss;
//	oss << v1 << ch << v2 << ch << v3 << ch << v4;
//	cout << oss.str() << endl;
//}



//�������ʽ��
//#include<iomanip>
////��ȿ���
////�������
////������
////���ȿ���
////���ƿ���
//int main() {
//	system("chcp 936");//���Ļҳ������������ʧ�ܣ����ô���
//	int n = 64;
//	cout << "================��ȿ���================" << endl;
//	cout << setw(10) << n << '#' << endl; //        64#  �Ҷ���
//	cout << "================�������================" << endl;
//	cout << setw(10) <<setiosflags(ios::left)<< n << '#' << endl; //64        # �����
//	cout << setw(10) << n << '#' << endl; //64        # �������ú�ͻ��ס�ˡ�
//	//cout << setw(10) << setiosflags(ios::right) << n << '#' << endl; //        64# �Ҷ��뷽��1
//	cout << setw(10) << resetiosflags(ios::left) << n << '#' << endl; //        64# �Ҷ��뷽��2��default
//	cout << "================������================" << endl;
//	cout << setw(10) << setfill('*') << n << '#' << endl; //********64#
//	cout << setw(10) << n << '#' << endl; //********64#  ���Ҳ���ס
//	cout << setw(10) << setfill(' ') << n << '#' << endl; //�ָ��ո����
//
//	cout << "================���ȿ���================" << endl;
//	double d1 = 123.45;
//	double d2 = 0.018755;
//	cout << setprecision(4)<<d1 << endl; //123.5  ��Ч����Ϊ4������4��5��
//	cout << setprecision(4)<<d2 << endl; //0.01876
//	cout << setprecision(2)<<d1 << endl; //1.2e+02 ��Ч����Ϊ2�������ÿ�ѧ������
//	cout << setprecision(2)<<d2 << endl; //0.019 ��Ч����Ϊ2��
//
//	cout << setiosflags (ios::fixed);//ʹsetprecision()����С����ľ���
//	cout << setprecision(4) << d1 << endl; //123.4500 //С�����4λ������Ĳ�0
//	cout << setprecision(4) << d2 << endl; //0.0188
//	cout << setprecision(2) << d1 << endl; //123.45 //С�����2λ���������������
//	cout << setprecision(2) << d2 << endl; //0.02 
//
//	cout << "================���ƿ���================" << endl;
//	cout << hex << 17 << endl; //11		//16*1+1 16������ʾ
//	cout << dec << 17 << endl; //17		//10����
//	cout << oct << 17 << endl; //21		//8*2+1 8������ʾ
//
//	cout << "================ռλ��================" << endl;
//	int x = 2;
//	int y = 6;
//	printf("%d+%d=%d\n",x,y,x+y);
//	printf("%s%d%s\n","������", x, "����");
//	system("pause");
//	return 0;
//}


//===========������C++�߼��׶�==============
// ��ʽ���
//---------ģ��-----------
//��ͨģʽʵ��������������
//void intSwap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << a << endl;
//	cout << b << endl;
//}
////��ͨģʽʵ����������������
//void doubleSwap(double& a, double& b) {
//	double temp = a;
//	a = b;
//	b = temp;
//	cout << a << endl;
//	cout << b << endl;
//}
////����ģ��
//template<typename T>//����ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ���������͵ĳ���
//void mySway(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//	cout << "first=" << a << endl;
//	cout << "second="<< b << endl;
//}
////����ģ������
//template<typename T>//����ģ�壬���ٱ�������������н����ŵ�T��Ҫ����T��һ���������͵ĳ���
//void mySway(T& a, T& b ,T& c) {
//	T temp = a;
//	a = b;
//	b = c;
//	c = temp;
//	cout <<"first="<< a << endl;
//	cout << "second=" << b << endl;
//	cout << "last=" << c << endl;
//}
//
//int main() {
//	/*int a = 10;
//	int b = 20;
//	intSwap(a, b);
//	*/
//
//	/*double a = 1.11;
//	double b = 2.22;
//	doubleSwap(a, b);
//	*/
//	
//	//ģ�����
//	double a = 1.11;
//	double b = 2.22;
//	double c = 3.33;
//	//����1���Զ������Ƶ������ε����;�����
//	mySway(a, b);
//	
//	//����2����ʽָ������
//	//mySway<double>(a, b);
//	//mySway<double>(a, b, c); //��������
//}

////--��ʽ����ת��---
//template<class T> //<class T>==<typename T> ,������ͬ������Ϊ�������ͣ�����typename���ں���ģ�壬class������ģ��
//void intCharSway(T a, T b) {
//	T temp = a;
//	a = b;
//	b = temp;
//	cout << a << endl;
//	cout << b << endl;
//}
//template<class T> 
//T add(T a, T b) {
//	return a + b;
//}
//int main() {
//	char x = 'a'; //97
//	int y = 98; 
//	int z = 1;
//	//intCharSway(x, y); //�����Զ��Ƶ���֧����ʽ����ת��
//	//intCharSway<char>(x, y); //��ʾָ�����ͣ�֧����ʽ����ת��
//	cout << add<int>(x, z) << endl;  //����98
//	cout << add<char>(x, z) << endl;  //����b
//}


////--��ʽ����ת��---
//template<class T> //<class T>==<typename T> ,������ͬ������Ϊ�������ͣ�����typename���ں���ģ�壬class������ģ��
//void intCharSway(T a, T b) {
//	T temp = a;
//	a = b;
//	b = temp;
//	cout << a << endl;
//	cout << b << endl;
//}
//template<class T>
//T add(T a, T b) {
//	return a + b;
//}
//int main() {
//	char x = 'a'; //97
//	int y = 98;
//	int z = 1;
//	//intCharSway(x, y); //�����Զ��Ƶ���֧����ʽ����ת��
//	//intCharSway<char>(x, y); //��ʾָ�����ͣ�֧����ʽ����ת��
//	cout << add<int>(x, z) << endl;  //����98
//	cout << add<char>(x, z) << endl;  //����b
//}

////�����ֵ 
//template<typename T, int len>  //�������ͺͳ��ȣ�����ָ�����鳤�ȣ�
//T max(T arr[len]) {
//	T ret = arr[0];
//	for (int i = 1;i < len;i++) {
//		ret = ret > arr[i] ? ret : arr[i];
//	}
//	return ret;
//}
//void main() {
//	int arr1[5] = { 1,2,3,4,5 };
//	int res1 = max<int, 5>(arr1);
//	cout << "res1=" << res1 << endl;
//
//	double arr2[3] = { 1.1,2.2,3.3 };
//	double res2 = max<double, 3>(arr2);
//	cout << "res2=" << res2 << endl;
//}


//--ģ�������---
//template<class T>
//bool myCompare(T& a, T& b) {
//	if (a = b) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//class Person {
//public:
//	Person(string name, int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	string m_Name;
//	int m_Age;
//};
////���þ��廯��person������������� ,����ǰ�� template<>����ָ����������
//template<> bool myCompare(Person& p1, Person& p2) {
//	if (p1.m_Name==p2.m_Name && p1.m_Age==p2.m_Age) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//int main() {
//	//��������
//	int a = 10;
//	int b = 10;
//	cout << myCompare<int>(a, b) << endl; 
//
//	//������������֤
//	Person p1("����",18);
//	Person p2("����",18);
//	cout << myCompare(p1, p2) << endl; //���ڴ���������Person�����Ծ��廯��ģ��ᱻ���ȵ��á����û�о��廯������б���
//}

//����ģ���ػ�/����
//������������Ѱ�ҷ�ģ�庯�����Ҳ������Զ��Ƶ�Ϊģ�庯��
//#include <string>
//const int& max(const int& a, const int& b) {
//	cout << "non template" << endl;
//	return a > b ? a : b;
//}
//template <typename T>
//const T& max(const T& a, const T& b) {
//	cout << "template" << endl;
//	return a > b ? a : b;
//}
//template<>  //�ػ�
//const char* const& max(const char* const& a, const char* const& b) {
//	if (strcmp(a, b) < 0)
//		return b;
//	else if (strcmp(a, b) >0)
//		return a;
//	else
//		return 0;
//}
//
//int main() {
//	cout << ::max(5.5, 6.6) << endl;
//	cout << ::max('a', 'z') << endl;
//	const char* str1 = "aaa";
//	const char* str2 = "bbb";
//	/*cout << strcmp(str1, str2) << endl;*/
//	cout << ::max(str1, str2) << endl;
//
//	//cout << ::max("a", "z") << endl; //Ϊ�η���a
//	//cout << strcmp("a", "z") << endl; //���ص���-1
//	cout << ::max(1.1, 2.2) << endl; //�Զ��Ƶ����β��Ǹ����������Ե��õ���ģ��
//	cout << ::max(1, 2) << endl; //�Զ��Ƶ����β������������Ե��õ���int���غ���
//	cout << ::max<>(1, 2) << endl; //ָ������ģ�庯��+�Զ��Ƶ�
//	cout << ::max<int>(1, 2) << endl; //ָ������ģ�庯��+ָ������ģ��
//}

//---------��ģ��----------------
//#include <string>
//template<class NameType, class AgeType=bool > //��ģ��֧��Ĭ�ϲ�������
//class Person{
//public:
//	Person(NameType name, AgeType age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	};
//	NameType m_Name;
//	AgeType m_Age;
//
//	void showPerson() {
//		cout << "name: " << this->m_Name << "\tage: " << this->m_Age<<endl;
//	}
//};
//int main() {
//	Person<string, int>p( "�����", 9999); //��ģ��ֻ֧����ʽָ������
//	p.showPerson();
//}

//��ģ���еĳ�Ա���������Ƕ������ʱ�����ģ����ǵ���ʱ������
//class Person1 {
//public:
//	void showPerson1() {
//		cout << "person1 showPerson1 "  << endl;
//	}
//};
//
//class Person2 {
//public:
//	void showPerson2() {
//		cout << "person2 showPerson2 " << endl;
//	}
//};
//template<class T>
//class Myclass {
//public:
//	T obj;  //����T���͵ĳ�Ա����Ϊ��ʱ��֪�����ǳ�Ա�������ǳ�Ա����
//	//��������Ա����
//	void func1() { obj.showPerson1(); }
//	void func2() { obj.showPerson2(); }
//};
//int main() {
//	Myclass<Person1> p; 
//	p.func1();
//	p.func2(); //ֻ���ڵ���ʱ�ű���"showPerson2": ���� "Person1" �ĳ�Ա����Ϊֻ���ڵ���ʱ��ģ��Ż�ȥ������Ա����
//}


//----��ģ����Ϊ��������------
//�Ƽ�ʹ�õ�һ�֣��������ֲ����飬��Ϊ2��3�Ƚϸ��ӣ���ʵ��ģ��+����ģ���������
//template<class NameType ,class AgeType =int>
//class Person {
//public:
//	Person(NameType name, AgeType age) {
//		this->mName = name;
//		this->mAge = age;
//	}
//	void showPerson() {
//		cout << "name: " << this->mName << "\tage: " << this->mAge << endl;
//	}
//	NameType mName;
//	AgeType mAge;
//};
//
////����1�� ָ�����������
//void func1(Person<string,int> &p) {
//	p.showPerson();
//}
////����2�� ����ģ�廯
//template<class T1, class T2>
//void func2(Person<T1, T2>& p) {
//	p.showPerson();
//	cout << "T1�����ͣ�" << typeid(T1).name() << endl;
//	cout << "T2�����ͣ�" << typeid(T2).name() << endl;
//	/* ��������string��ʵ�����ƾ���ô��
//	T1�����ͣ�class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
//	T2�����ͣ�int
//	*/
//}
//
////����3�� ������ģ�廯
//template<class T>
//void func3(T& p) {
//	p.showPerson();
//	cout << "T�����ͣ�" << typeid(T).name() << endl;
//	/* ��ӡ���£�T�����;���Person�࣬��զ�о��������и����أ���Ȼ���Ǻ���ģ��+��ģ��
//		T�����ͣ�class Person<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int>
//	*/
//}
//int main() {
//	Person<string, int>p("����",28);
//	//func1(p);//������Ϊ��������
//	//func2(p);
//	func3(p);
//}

//----��ģ��̳�------
//template<class T>
//class Base {
//	public:
//		Base(T t) { t1 = t;  }
//	void printT() {
//		cout << t1 << endl;
//	}
//	
//	T t1;
//};
//class Son :public Base<int> {  //<int>����ָ������
//public:
//	Son(int m):Base(m) {}
//
//}; 
//
//void test1() {
//	Son c(10);
//	c.printT();
//}
//
//int main() {
//	test1();
//	//test2();
//}


//��ģ��̳���ģ�壬������T1ָ�������е�T����
//template<class T1, class T2>
//class Son2 :public Base<T1> {
//public:
//	Son2() {
//		cout << typeid(T1).name() << endl;
//		cout << typeid(T2).name() << endl;
//	}
//};
//void test2() {
//	Son2<int, char> child2;
//	child2.
//}

////--------��ģ��ĺ���������ʵ��------
//template<class NameType ,class AgeType =int>
//class Person {
//public:
//	Person(NameType name, AgeType age);
//	void showPerson();
//	NameType mName;
//	AgeType mAge;
//};
////���캯��������ʵ��
//template<class NameType, class AgeType >
//Person<NameType, AgeType>::Person(NameType name, AgeType age) {
//	this->mName = name;
//	this->mAge = age;
//}
////��Ա����������ʵ��
//template<class NameType, class AgeType >
//void Person<NameType, AgeType>::showPerson() {
//	cout << "name: " << this->mName << "\tage: " << this->mAge << endl;
//}
//int main() {
//	Person<string, int>p("seven", 36);
//	p.showPerson();
//}


//----180-184------

//=========== STL(Standard Template Library,��׼ģ���) ===============
/*
����ԭ�����ݽṹ���㷨��һ�ױ�׼��߸����ԣ�
�ص㣺�������д��붼����ģ�������ģ�庯��
�����Ϊ��������container�����㷨��algorithm������������iterator��,�����������������㷨
����������������㷨�����������º�����������������������ռ�������
�������������ݽṹ����vector�����Ϊ���飩��list��deque,set,map�ȡ�
����������ǿ��ֵ���������������е�ÿ��Ԫ���й̶�λ�á�
�����������������ṹ��ÿ��Ԫ��֮��û���ϸ�������ϵ�˳���ϵ��
�㷨��sort��find��copy��for_each�ȡ�
�ʱ��㷨���������滻��ɾ���ȸı����ݵġ�
���ʱ��㷨�����ң�������������Ѱ�Ҽ�ֵ�Ȳ���ı����ݵġ�
�����������Ϊָ��Ϳ����ˣ������루�����������д������ǰ����д������ֻ����ǰ�ƽ�����˫�򣨶�д����ǰ��󶼿��ԣ���������ʣ���Ծ�ķ����������ݣ�������ǿ�����þ��Ǻ�����
�º�������Ϊ��ϵ�Ĺ���������Ϊ�㷨��ĳ�ֲ���
��������һ�����������������߷º������ߵ������ӿڵĶ�������ʱ������⡣
�ռ�������������ռ�������������ʱ������⡣
*/


//#include <vector>
//#include <algorithm> //��׼�㷨ͷ�ļ�
//void myPrint(int val) {
//	cout << val << endl;
//}
//void test01() {
//	vector<int> v;
//	//��������
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	////������ʽ1,while ѭ��
//	//vector<int>::iterator itBegin = v.begin();//��ʼ������
//	//vector<int>::iterator itEnd = v.end();
//	//while (itBegin!=itEnd)
//	//{
//	//	cout << *itBegin << endl;
//	//	itBegin++;
//	//}
//
//	////������ʽ2,for ѭ��
//	//for (vector<int>::iterator itBegin=v.begin(); itBegin!= v.end();itBegin++)
//	//{
//	//	cout << *itBegin << endl;
//	//}
//
//	//������ʽ3,for_each ѭ��
//	//�����˻ص�������
//	for_each(v.begin(), v.end(), myPrint);
//}
//int main() {
//	test01();
//}

//#include <vector>
////#include <algorithm> //��׼�㷨ͷ�ļ�
//#include <numeric> //accumulate()
//
//auto accumulateValue(vector<int> val ,int num) {
//	int comp{ num };//�����ֵҪ��num�Ƚ�
//	//sum����͵Ľ������ֵΪ0�� 
//	auto sum = accumulate(begin(val), end(val), 0, [comp](int sum, int v)
//		{
//			if (v < comp) //v�Ǵ����values��ֵ��С��3��������>=3�ͼ��� 
//				return sum;
//			return sum + v;
//		});
//	return sum;
//}
//
//int main() {
//	vector<int> values{ 2, 1, 5, 3, 5 };
//	int num = 3;
//	auto sum=accumulateValue(values, num);
//	cout << "The sum of the elements greater than " << num - 1 << " is " << sum << endl;  //13  >=3Ԫ�صĺ�
//	auto product = std::accumulate(std::begin(values), std::end(values), 1, std::multiplies<int>()); 
//	cout << "The multiplies is :" << product << endl; //150 ����Ԫ�صĳ˻�
//}


////˫�������
//#include<vector>
//void main() {
//	vector<int> v(6);
//	vector<int>::iterator it = v.begin();
//	vector<int>::iterator it_save = it;
//
//	*it++ = 1; //��������������ֵ
//	*it++ = 2;
//	*it++ = 3;
//	*it++ = 4;
//	*it++ = 5;
//	*it = 6;
//
//	while (it_save!=v.end()) {
//		cout << *it_save++ ;
//	}
//	cout << endl;
//
//	do {
//		cout << *--it_save; //Ҫ��--����Ϊָ���Ѿ�ָ����v.end()�ˣ���Ҫ--����ܻص����һ��Ԫ��
//	} while (it_save != v.begin());
//	cout << endl;
//
//	//��ָ������ָ��v.begin()
//	it = v.begin();
//	*(it+2)= 0; //ÿ��������ֵΪ0
//	while (it_save != v.end()) {
//		cout << *it_save++;
//	}
//	cout << endl;
//}



//#include <vector>
//#include <algorithm> //��׼�㷨ͷ�ļ�
//#include <numeric> //accumulate()
//
//template<typename T>
//void outPut(T val) {
//	cout << val << " ";
//}
//
//int main() {
//	//vector<int> values{ 2, 1, 5, 3, 5 };
//	//for_each(values.begin(), values.end(), outPut<int>); //21535
//	//cout << endl;
//	//fill(values.begin(),values.begin()+3,0); //ǰ3�����0��00035
//	//for_each(values.begin(), values.end(), outPut<int>);
//	//cout << endl;
//
//	//��������ѭ������
//	vector<char> ch;
//	ch.push_back('A');
//	ch.push_back('B');
//	ch.push_back('C');
//	ch.push_back('D');
//	ch.push_back('E');
//	//for_each(ch.begin(), ch.end(), outPut<char>); //ABCDEF
//	//cout << endl;
//	//rotate(ch.begin(), ch.begin() + 3, ch.end());  //��index=3��Ԫ�ؿ�ʼ����ѭ��
//	//for_each(ch.begin(), ch.end(), outPut<char>); //DE(rotate)ABC
//	//cout << endl;
//
//	//����1��
//	////remove(ch.begin(), ch.end(), 'B'); //��ͷ��β���ң�������B��ɾ����Ȼ������ֵ��ǰ�ƣ����һ�����㣬ACDEE
//	//ch.erase(remove(ch.begin(), ch.end(), 'B'),ch.end()); //ɾ�����һλ���͵õ��˽��
//
//	//����2��
//	for (vector<char>::iterator it = ch.begin(); it != ch.end();/*++it*/) {
//		if (*it == 3) {
//			it = ch.erase(it);
//		}
//		else
//			++it;
//	}
//
//	for_each(ch.begin(), ch.end(), outPut<char>); //
//	cout << endl;
//}


//---�Զ������ݱ���---
//#include <vector>
//#include <algorithm> //��׼�㷨ͷ�ļ�
//class Person {
//public:
//	Person(string name, int age) {
//		mName = name;
//		mAge = age;
//	}
//	string mName;
//	int mAge;
//};
////vector��Ŷ���
//void test01() {
//	Person p1("������", 2);
//	Person p2("����", 35);
//	Person p3("������", 36);
//	//��������
//	vector<Person> v; //Ҫָ����������
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//
//	//for ѭ������
//	for (vector<Person>::iterator itBegin=v.begin(); itBegin!= v.end();itBegin++)
//	{
//		//cout <<"������"<< (*itBegin).mName<<"\t���䣺" << (*itBegin).mAge<< endl; //������ָ�������Person��������
//		cout <<"������"<< itBegin->mName<<"\t���䣺" << itBegin->mAge<< endl; //itBegin���Ǹ�������ָ�룬���Կ����ü�ͷֱ�ӵ���
//	}
//}
////vector��Ŷ���ָ��
//void test02() {
//	Person p1("������", 2);
//	Person p2("����", 35);
//	Person p3("������", 36);
//	//��������
//	vector<Person*> v; //Ҫָ����������
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//
//	//for ѭ������
//	for (vector<Person*>::iterator itBegin = v.begin(); itBegin != v.end();itBegin++)
//	{
//
//		cout << "name��" << (*itBegin) ->mName << "\tage��" << (*itBegin) ->mAge << endl; //itBegin���Ǹ�������ָ�룬�����ó�Person�ĵ�ַ���ü�ͷָ���ַ����ʵֵ
//	}
//}
//int main() {
//	test01();
//	test02();
//}




////---����Ƕ������---
//#include <vector>
//#include <algorithm> //��׼�㷨ͷ�ļ�
//void test01() {
//	vector<vector<int>> v; //Ƕ������
//	
//	//�����ڲ�С����
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//	//��С����д������
//	for (int i = 0;i < 4;i++) {
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//	}
//	//��С����д�뵽��������
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//	//˫forѭ������������Ϣ
//	for (vector<vector<int>>::iterator itOut = v.begin();itOut != v.end();itOut++) {
//		for (vector<int> ::iterator itIn = (*itOut).begin();itIn != (*itOut).end();itIn++) {
//			cout << *itIn << " ";
//		}
//		cout << endl;//С����������Ժ���endl
//	}
//}
//int main() {
//	test01();
//}

//#include <vector>
//typedef vector<int> INTVECTOR;
//
////��һ��show
////void ShowVec(const INTVECTOR& v)  //ʹ�����ã����򿽱����캯�����v���п������죬����һ�����������þ�������һ��
////{
////	unsigned int i;
////	//int i;
////	for (i = 0; i < v.size();i++) {
////		cout << v[i] << " ";
////	}
////	cout << endl;
////}
//
////�ڶ���show
//void ShowVec(const INTVECTOR& v) {
//	for(INTVECTOR::const_iterator it = v.begin();it != v.end();++it) //�����it++���һ�����һ����ʱָ�룬ָ��������������϶����һ�����������һ������ָ��Ķ�����++i��ʡ������һ����
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	INTVECTOR v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//
//	ShowVec(v);
//}


//---string����---
//char *��һ��ָ��
//string��һ���࣬�ڲ���װ��char*����char*������
//��Ա������find/copy/delete/replace/insert
/*��������
1. string();  // 1. Ĭ�Ϲ��죬�������ַ������磬string str
2. string(const char* str);  // 2.ʹ���ַ���str��ʼ��
3. string(const string& str); // 3. ���������ʼ����ʹ��һ��string�����ʼ����һ��string����
4. string(int n,char c);  //ʹ��n���ַ�c��ʼ��
*/
//void test01() {
//	string s1; //1.Ĭ�Ϲ���
//	const char* str = "hello world";
//	//string s2("hello world");
//	string s2(str);  //2.ʹ���ַ���str��ʼ��
//	cout << "s2=" << s2 << endl;
//
//	string s3(s2); //3.���������ʼ��
//	cout << "s3=" << s3 << endl; 
//
//	string s4( 10 ,'a'); //3.���������ʼ��
//	cout << "s4=" << s4 << endl;
//}
//int main() {
//	test01();
//}

//---string��ֵ����---
/* ����ԭ��
1. string& operator=(const char* s);   //char*�����ַ�������ֵ����ǰ�ַ���
2. string& operator=(const string &s);   //���ַ���s��ֵ����ǰ�ַ���
3. string& operator=(char c);   //�ַ�c��ֵ����ǰ�ַ���
4. string& assign(const char *s);   //���ַ���s��ֵ����ǰ�ַ���
5. string& assign(const char *s,int n);   //���ַ���s��ǰn���ַ���ֵ����ǰ�ַ���
6. string& assign(const char &s);   //���ַ���s��ֵ����ǰ�ַ���
7. string& assign(int n,char c);  //��n���ַ�c��ֵ����ǰ�ַ���
*/
//void test01() {
//	//1
//	string str1; 
//	str1 = "hello world"; //�ַ���"hello world"ʵ����const char * ���͡�
//	cout << "str1=" << str1 << endl;
//	//2
//	string str2 = str1; //��ַ����
//	cout << str2 << endl; 
//	//3
//	string str3;
//	str3 = 'a'; 
//	cout << str2 << endl;
//	//4
//	string str4;
//	str4.assign("hello C++");
//	cout << str4 << endl;
//	//5
//	string str5;
//	str5.assign("hello C++",5);
//	cout << str5 << endl;
//	//6
//	string str6;
//	str6.assign(str4);
//	cout << str6 << endl;
//	//7
//	string str7;
//	str7.assign(10, 'w');
//	cout << str7 << endl;
//}
//int main() {
//	test01();
//}

////---stringƴ��---
///* ����ԭ��
//1. string& operator+=(const char* str);   //����+=
//2. string& operator+==(const char c);   //����+=
//3. string& operator+=(const string& str);   //����+=
//4. string& append(const char *s);   //׷���ַ���
//5. string& append(const char *s,int n);   //���ַ�����ǰn���ַ�׷��
//6. string& append(const string &str);   //ͬoperator+=(const string& str)
//7. string& append(const string &s, int startPos,int n);  //startPos��ʼλ�ã�n=����
//*/
//void test01() {
//	//1
//	string str1;
//	str1 = "��"; 
//	str1 += "������Ϸ";
//	cout << "str1=" << str1 << endl;
//	//2
//	str1 += ':'; //ƴ��char�ַ�
//	cout << str1 << endl;
//	//3
//	string str2;
//	str2 = "LOL ������ҫ";
//	str1 += str2;
//	cout << str1 << endl;
//	//4
//	string str3="I";
//	str3.append(" love ");
//	cout << str3 << endl;
//	//5
//	str3.append("game abcde", 5); //��ǰ5���ַ�ƴ�� "game�ո�"
//	cout << str3 << endl;
//	//6
//	//str3.append(str2);  //ֱ��ƴ�ӣ�
//	//cout << str3 << endl;
//	//7
//	str3.append(str2, 4, 8); //�ӵ��ĸ��ַ���ʼƴ�ӣ�"������ҫ"�����ĸ��ַ�,��ռ��8���ֽ�
//	cout << str3 << endl;
//}
//int main() {
//	test01();
//}

//---�ַ������Һ��滻---
// ����ֻ������õģ������Ҫ����Ĺ��ܣ����аٶ�
//����
//void test01() {
//	string str1="abcdefgde";
//	int res = str1.find("de");  //res=3,�±��0��ʼ
//	if(res == -1){   //-1,û���򷵻�-1
//		cout << "û���ҵ��ַ���"<<endl;
//	}
//	else {
//		cout << "�ҵ��ַ�����pos = " << res << endl;
//	}
//	//rfind //����������,���ؽ����find��һ����
//	int res2 = str1.find("de");
//	cout << res2 << endl;
//}
////�滻
//void test02() {
//	string str1 = "abcdef";
//	str1.replace(1, 2, "1111"); //a1111def ,��λ��1����bc2���ַ��滻��1111
//	cout << str1 << endl; 
//}
//int main() {
//	//test01();  //����
//	test02();  //�滻
//}

//---�ַ����Ƚ�---
// ����ascall���С������λ�Ƚ�
//һ�������Ƿ���ȣ�һ�㲻�����ڱȽϴ�С
//void test01() {
//	string str1 = "hello";
//	string str2 = "hello";
//	if (str1.compare(str2)==0) {
//		cout << "str1==str2" << endl;
//	}
//	else if (str1.compare(str2)>0) {
//		cout << "str1>str2" << endl;
//	}
//}
//int main() {
//	test01();
//}

//---�ַ������ַ���ȡ���޸Ĳ���---
//void test01() {
//	string str1 = "hello";
//	//ͨ��[]���ʵ����ַ�
//	for (int i = 0;i < str1.size();i++) {
//		cout << str1[i] << " ";
//	}
//	cout << endl;
//
//	//ͨ��at��ʽ���ʵ����ַ�,Ч����[]��ͬ
//	for (int i = 0;i < str1.size();i++) {
//		cout << str1.at(i) << " ";
//	}
//	cout << endl;
//
//	str1[0] = 'x'; //�޸ķ���1
//	cout << str1 << endl;
//
//	str1.at(1) = 'x'; //�޸ķ���2
//	cout << str1 << endl;
//}
//int main() {
//	test01();
//}

//---�ַ����Ĳ���---
//void test01() {
//	string str1 = "hello";
//	str1.insert(1, "111"); //h111ello
//	cout << str1 << endl;
//	str1.erase(1, 3);//��1��λ�ò��������,�ع鵽hello
//	cout << str1 << endl;
//}
//int main() {
//	test01();
//}

//---�ַ�����ȡ---
//void test01() {
//	string str1 = "abcedfg";
//	string subStr=str1.substr(1, 3); //bcd
//	cout << subStr << endl;
//}
////��ȡ�������е��û���seven.sun
//void test02() {
//	string email = "seven.sun@endeavorstreaming.com";
//	int pos = email.find("@"); //9
//	//cout << pos<<endl;
//	string userName = email.substr(0, pos); 
//	cout << userName << endl;
//}
//int main() {
//	//test01();
//	test02();
//}


//---vector����---
//vector��������
//#include<vector>
//void printVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	//���췽ʽ1��Ĭ�Ϲ��죩�� �޲ι���
//	vector<int> v1; 
//	for (int i = 0;i < 10;i++) {
//		v1.push_back(i);
//	}
//	printVec(v1);
//
//	//���췽ʽ2��ͨ�����䷽ʽ���й���
//	vector<int> v2(v1.begin(),v1.end());
//	printVec(v2);
//
//	//���췽ʽ3:n��Ԫ�ط�ʽ����
//	vector<int>v3(10, 999); //10��999
//	printVec(v3);
//
//	//���췽ʽ4:��������
//	vector<int>v4(v3); //10��999
//	printVec(v4);
//}
//int main() {
//	test01();
//}

////vector��ֵ
//#include<vector>
//void printVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	//�ȹ������һ��v1
//	vector<int> v1;
//	for (int i = 0;i < 10;i++) {
//		v1.push_back(i);
//	}
//	printVec(v1);
//
//	//��ֵ����1��operator=
//	vector<int> v2;
//	v2 = v1;
//	printVec(v2);
//
//	//��ֵ����2��assign(v.begin(),v.end())
//	vector<int>v3; //10��999
//	v3.assign(v1.begin(), v1.end());
//	printVec(v3);
//
//	//���췽ʽ3:v.assign(n,xxx)
//	vector<int>v4;
//	v4.assign(10, 888);//10��999
//	printVec(v4);
//}
//int main() {
//	test01();
//}



////vector�����������ʹ�С����
//#include<vector>
//void printVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	//�ȹ������һ��v1
//	vector<int> v1;
//	for (int i = 0;i < 10;i++) {
//		v1.push_back(i);
//	}
//	printVec(v1);
//
//	if (v1.empty()) {
//		cout << "v1Ϊ��" << endl;
//	}
//	else {
//		cout << "v1��Ϊ�գ�����Ϊ��"<<v1.capacity() << endl; //13,��Ԥ�������13Ҳ�����꣬�����ݵ��µ�ַ������ԭ���Ŀ�����ȥ
//		cout << "v1��ʵ��СΪ��" << v1.size() << endl; //10
//	}
//	//����ָ����С
//	v1.resize(15); //���ݺ�Ĭ����0���
//	printVec(v1);
//	v1.resize(20, 999);//����ָ���������
//	printVec(v1);
//	v1.resize(5);//��С�󣬶��ಿ�ֱ�ɾ����
//	printVec(v1);
//
//}
//int main() {
//	test01();
//}

//vector���������ɾ��
//#include<vector>
//void printVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01() {
//	vector<int> v1; //��������v1
//	v1.push_back(1);//β������
//	v1.push_back(100);
//	printVec(v1);
//
//	//����
//	v1.insert(v1.begin(), 888);//��ͷ������1��888
//	v1.insert(v1.begin(), 3 ,999);//��ͷ������3��999
//	printVec(v1);
//
//	//��β��ɾ��
//	v1.erase(v1.begin());//��ͷɾ��1��
//	printVec(v1);
//	//v1.erase(v1.begin(), v1.end());//��ͷɾ��β���������
//	//printVec(v1);
//
//	//���
//	v1.clear();
//	cout << "��պ��������"<<v1.capacity() << endl; //6
//	cout << "��պ��ʵ�ʴ�С��"<<v1.size() << endl; //0
//	printVec(v1);
//}
//int main() {
//	test01();
//}


////vector����  ���ݴ�ȡ
//#include<vector>
//void test01() {
//	vector<int> v1; //��������v1
//	for (int i = 0;i < 10;i++) {
//		v1.push_back(i);
//	}
//	for (int i = 0;i < v1.size();i++) {
//		cout << v1[i] << " "; //���鷽ʽ��������
//	}
//	cout << endl;
//	for (int i = 0;i < v1.size();i++) {
//		cout << v1.at(i) << " "; //at��ʽ��������
//	}
//	cout << endl;
//	//��ȡ��һ��Ԫ��
//	cout << "��һ��Ԫ�أ�"<<v1.front()<<endl;
//	//��ȡ���һ��Ԫ��
//	cout << "���һ��Ԫ�أ�" << v1.back() << endl;
//}
//int main() {
//	test01();
//}


//vector����  ����
//#include<vector>
//void printVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
////����������������ʾ��
//void test01() {
//	vector<int> v1; //��������v1
//	for (int i = 0;i < 10;i++) {
//		v1.push_back(i);
//	}
//	printVec(v1);
//
//	vector<int> v2; //��������v1
//	for (int i = 9;i >= 0;i--) {
//		v2.push_back(i);
//	}
//	printVec(v2);
//
//	//�����������������ã�
//	v1.swap(v2);
//	printVec(v1);
//	printVec(v2);
//}
////ʵ����;������swap���������ڴ�ռ䣬��Լ�ڴ�
//void test02() {
//	vector<int> v1; //��������v1
//	for (int i = 0;i < 100000;i++) {
//		v1.push_back(i);
//	}
//	
//	cout << "v1������Ϊ:" << v1.capacity() << endl; //138255
//	cout << "v1��ʵ�ʴ�С:" << v1.size() << endl; //100000
//
//	v1.resize(3);
//	cout << "v1������Ϊ:" << v1.capacity() << endl; //138255
//	cout << "v1��ʵ�ʴ�С:" << v1.size() << endl; //3
//
//	vector<int>(v1).swap(v1);   //vector<int>(v1) �����������󣬿�������v1����ԭ��v1����ָ��ָ�����������Զ����գ�v1ָ���ݻ���СΪ3��
//	cout << "v1������Ϊ:" << v1.capacity() << endl; //3
//	cout << "v1��ʵ�ʴ�С:" << v1.size() << endl; //3
//}
//int main() {
//	//test01();
//	test02();
//
//}

////vector����  Ԥ���ռ䣨��ʡ��չ�ռ������ʱ����ģ�
//#include<vector>
//void test01() {
//	vector<int> v1; //��������v1
//	v1.reserve(100000); //Ԥ��10w���ռ䡣
//	int num = 0;
//	int* p = NULL;
//	for (int i = 0;i < 100000;i++) {
//		v1.push_back(i);
//		if (p!= &v1[0]) {
//			p = &v1[0];
//			num++;
//		}
//	}
//	cout << num<< endl;  //30(����30��);1(Ԥ��100000���ֽڣ�����һ�ξͿ�������)
//}
//int main() {
//	test01();
//}

//=============== map ����==========================
//����ʽ������ key:value 

//#include <string>
//#include <map>

//int main() {
//	map<string, int> mapContainer; //����һ��map����
//
//	//��ֵ����
//	mapContainer["aaa"]= 100;
//	mapContainer.insert(map<string, int>::value_type("bbb", 200));
//	mapContainer.insert(pair<string,int>("ccc", 300));
//	mapContainer.insert(make_pair("ddd", 400)); //make_pare����ֵ��pair���ͣ����Եȼ�����һ����
//	mapContainer["eee"] = 500;
//
//	//���ҷ���1
//	cout << mapContainer["aaa"] << endl; //100
//	//cout << mapContainer["xxx"] << endl; //0 ,û�ҵ�����0 ȱ���ǲ����ڵļ��ṹ���һ��"xxx":0 ��Ԫ�� ��������ʹ��
//	//���ҷ���2
//	map<string, int>::iterator it1 = mapContainer.find("bbb");
//	if (it1!=mapContainer.end()) {
//		it1->second = 2000;
//	}
//	else {
//		cout << "not found" << endl;
//	}
//
//	//ɾ������1
//	mapContainer.erase("ccc"); //�����Ǽ�
//	//ɾ������2
//	map<string, int>::const_iterator it2=mapContainer.find("ccc");
//	if (it2!=mapContainer.end()) {
//		mapContainer.erase(it2);  //������ָ��
//	}
//
//	for (map<string, int>::const_iterator it = mapContainer.begin();it != mapContainer.end();++it) {
//		cout << it->first << " " << it->second << endl;
//	}
//	return 0;
//}
//=============deque����==========================
//˫�����飬���Դ�ͷ�˺�β�ˣ��п������ƻ�����������ɾ������
/*deque��vector����
vector����ͷ�������ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
deque��Զ��ԣ�����ͷ���Ĳ���ɾ���ٶȱ�vector��
vector����Ԫ��ʱ���ཻ��deque��
*/
//#include<deque>
////��ͨ��ӡ����,����ԭ�����ݿ��Ա��޸ģ�������
//void printDeque1(deque<int>&d) {
//	for (deque<int>::iterator it = d.begin();it != d.end();it++) {
//		*it = 100;
//		cout << *it << " "; //100 100 100 100 100 100 100 100 100 100
//	}
//	cout << endl;
//}
////const����������ֹ��ӡ�������޸���������ֵ
//void printDeque2(const deque<int>& d) {
//	for (deque<int>::const_iterator it = d.begin();it != d.end();it++) {
//		//*it = 100;  //��ʱ��Ҫ�����޸�����ֵ���ͻᱨ��
//		cout << *it << " "; //0 1 2 3 4 5 6 7 8 9
//	}
//	cout << endl;
//}
//void test01() {
//	deque<int> d1; //��������d1
//	//push_back��ʽ��������
//	for (int i = 0;i < 10;i++) {
//		d1.push_back(i);
//	}
//	printDeque2(d1);
//
//	//�������������������������
//	deque<int> d2(d1.begin(), d1.end());
//	printDeque2(d2);
//
//	//ָ��������ָ��ֵ
//	deque<int> d3(10,999 ); //10��999
//	printDeque2(d3);
//
//	//�������췽ʽ��������d2
//	deque<int> d4(d3);
//	printDeque2(d4);
//}
//int main() {
//	test01();
//}

////deque������ֵ����
//#include<deque>
////const����������ֹ��ӡ�������޸���������ֵ
//void printDeque(const deque<int>& d) {
//	for (deque<int>::const_iterator it = d.begin();it != d.end();it++) {
//		cout << *it << " "; //0 1 2 3 4 5 6 7 8 9
//	}
//	cout << endl;
//}
//void test01() {
//	deque<int> d1; //��������d1
//	//push_back��ʽ��������
//	for (int i = 0;i < 10;i++) {
//		d1.push_back(i);
//	}
//	printDeque(d1);
//
//	//�ȺŸ�ֵ
//	deque<int> d2;
//	d2 = d1;
//	printDeque(d2);
//
//	//assign ��ֵ
//	deque<int> d3;
//	d3.assign(d2.begin(), d2.end());
//	printDeque(d3);
//
//	//n��ָ��ֵ
//	deque<int> d4;
//	d4.assign(10, 999);
//	printDeque(d4);
//}
//int main() {
//	test01();
//}

//deque������С����
/*
ע�⣡��deque��û��������capacity()����ģ���Ϊ����һ�����˿��ڵķǹ̶�����
deque.empty();	//�ж������Ƿ�Ϊ��
deque.size();	//����Ԫ�صĸ���
deque.resize(num);	//�䳤����Ĭ��ֵ��䣬�����������ಿ��
deque.resize(num,elem);	// resize��ĳ��ȱ�ԭ����������element��䣬����������ɾ�������
*/
//#include<deque>
////const����������ֹ��ӡ�������޸���������ֵ
//void printDeque(const deque<int>& d) {
//	for (deque<int>::const_iterator it = d.begin();it != d.end();it++) {
//		cout << *it << " "; 
//	}
//	cout << endl;
//}
//void test01() {
//	deque<int> d1; //��������d1
//	//push_back��ʽ��������
//	for (int i = 0;i < 10;i++) {
//		d1.push_back(i);
//	}
//	printDeque(d1);
//
//	if (d1.empty()) {
//		cout << "d1Ϊ��" << endl;
//	}
//	else {
//		cout << "d1��Ϊ��" << endl;
//		cout << "d1��ʵ�ʴ�С��" << d1.size() << endl;
//	}
//
//	//����ָ��������С
//	deque<int> d2;
//	d1.resize(15);//����������0�����
//	d2 = d1;  
//	printDeque(d2); //0 1 2 3 4 5 6 7 8 9 0 0 0 0 0
//
//	//���ذ汾������ָ��������С������������ָ��ֵ�����
//	d1.resize(18,999);  //����������999�����
//	printDeque(d1); //0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 999 999 999
//
//	d1.resize(3);  //���ಿ��ɾ����
//	printDeque(d1); //0 1 2 
//}
//int main() {
//	test01();
//}
 

//207
//deque�����Ĳ����ɾ��
/*

*/
//#include<deque>
////const����������ֹ��ӡ�������޸���������ֵ
//void printDeque(const deque<int>& d) {
//	for (deque<int>::const_iterator it = d.begin();it != d.end();it++) {
//		cout << *it << " "; 
//	}
//	cout << endl;
//}
//void test01() {
//
//}
//int main() {
//	test01();
//}

//=============== set ���� ==============
// û��˳��
//#include<set>
//void main() {
//	set<int> iSet;  //�������μ���
//	iSet.insert(1); //��������
//	iSet.insert(3);
//	iSet.insert(5);
//	iSet.insert(7);
//	iSet.insert(9);
//
//	cout << "old_set:" << endl;
//	set<int>::iterator it; //ѭ������������е�����
//	for (it = iSet.begin(); it != iSet.end(); it++) {
//		cout << *it << endl; //13579
//	}
//
//	it = iSet.begin(); //
//	iSet.erase(it++);//ɾ��1,���ҵ���������ƶ�
//	iSet.erase(it); //ɾ����3
//	cout << "new_set:" << endl;
//	for (it = iSet.begin();it != iSet.end();it++) {
//		cout << *it << endl; //579
//	}
//
//	iSet.clear();
//	cout << "after clear():" << endl;
//	for (it = iSet.begin();it != iSet.end();it++) {
//		cout << *it << endl; //��
//	}
//}

//#include <set>
//void main() {
//	set<char> cSet;
//	cSet.insert('S');
//	cSet.insert('E');
//	cSet.insert('V');
//	//cSet.insert('E'); //�����ظ�������ֻ�ᱣ��һ��
//	cSet.insert('N');
//	cout << "current set:" << endl;
//	set<char>::iterator it;
//	for (it = cSet.begin();it != cSet.end();it++) {
//		cout << *it << endl;
//	}
//
//	char cTmp = 'S';
//	it = cSet.find(cTmp); //���Ҽ������Ƿ����ĳ��ֵ
//	if (it == cSet.end()) {
//		cout << "not found " << cTmp << endl;
//	}
//	else {
//		cout << "found " << cTmp << endl;
//	}
//}

//�ж����
//#include <cstdlib>
//#include <cstdio>
//using namespace std;
//#include <vector>
//#include <set>
//int main(int argc, char** argv)
//{
//	int myints1[] = { 10,20,30,40,50 };
//	int myints2[] = { 50,40,30,20,10 };
//	set<int> s1(myints1, myints1 + 5);
//	set<int> s2(myints2, myints2 + 5);
//	if (s1 == s2) {
//		printf("s1 == s2\n");
//	}
//	else printf("s1 != s2\n");
//
//	set<int>::iterator it2 = s2.begin();
//	for (set<int>::iterator it1 = s1.begin();it1 != s1.end();it1++) {
//		printf("s1: % d  s2 : % d \n" , *it1,*it2);
//			it2++;
//	}
//}




////������
//int main() {
//	cout << "������һ�����������ҽ�������Ķ����Ʊ�ʾ��1�ĸ��������ж����Ƿ���2����" << endl;
//	int num;
//	cin >> num;
//	int x = num; //�������㣬���ֻ����numֱ�Ӽ��㣬��numֵ�ᱻ�ı�
//	int count=0;//��¼1�ĸ���
//	while (x) {
//		x = x & (x - 1); //λ������
//		count++;
//		cout << count << endl;
//	}
//	cout << "����������Ķ�������" << count << "��1��" << endl;
//
//	if (count == 1 && num > 1) {  //�߼�����
//		cout << "�������2���ݡ�" << endl;
//	}
//	else {
//		cout << "���������2���ݡ�" << endl;
//	}
//}

////�ݹ�����
//int func(int n) {
//	if (n == 0) {
//		return 1;
//	}
//	else {
//		return n * func(n - 1);
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	cout << func(n) << endl;
//}


////ָ��ռ�ô�С
//int main() {
//	char c = 'A';
//	char* cp = &c;
//	cout << sizeof(cp) << endl;  //64λϵͳ����ַռ��8���ֽ�
//}

//һάָ������
// ˳������ȡ������ӡ
//int main() {
//	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int* p = a;//int *p =&a[0];
//
//	//1. pָ��������ʽ, p���ָ��һ��δ֪�ط�
//	//for (int i = 0;i < 10;i++,p++) {
//	//	cout << *p << " ";
//	//}
//	//cout << endl;
//	//cout<<*p<<endl;
//	
//	//2. *(p+i)��ʽ ��p��λ�ò���
//	for (int i = 0;i < 10;i++) {
//		cout << *(p + i) << " ";
//	}
//	cout << endl;
//	cout << *p << endl;
//}

//��άָ��
////1.ָ��ֱ�����
//int main() {
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int* p = &a[0][0]; //��ά���鲻������a��ָ���ˣ���������*p=a[][0]
//	for (int i = 0;i < 12;i++) {
//		cout << *p << " ";
//		p++;
//	}
//	cout << endl;
//}
////2.����ָ�뷽��
//int main() {
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	for (int i = 0;i < 3;i++) {
//		for (int j=0;j < 4;j++) {
//			cout << *(*(a + i) + j)<<" "; //*(a+i)=a[i], so ...
//		}
//	}
//	cout << endl;
//}

//ָ�뷽ʽʵ���ַ�������ƴ��
//int main() {
//	char arrStr1[100],arrStr2[100];
//	char* p1 = arrStr1;
//	char* p2 = arrStr2;
//	cout << "�����ַ���1��" << endl;
//	gets_s(arrStr1);
//	cout << "�����ַ���2��" << endl;
//	gets_s(arrStr2);
//
//	//�ҵ���һ���ַ�����ĩ��
//	while (*p1)
//	{
//		p1++;//�ҵ��ַ���1�Ľ�β
//	}
//	while (*p2)
//	{
//		*p1++ = *p2++;
//	}
//	*p1 = '\0';//���ַ�����β���Ͻ�����
//	
//	cout << "new str1: " ;
//	puts(arrStr1);
//}

////ָ�뷽ʽ��ȡ�ַ�������
//int main() {
//	char ch1[100] = "��Һã��ܸ��˼�����λ��";
//	char* cp = ch1;
//	//ָ��ȡ����ֵ��Ϊ����Ϊ�ж�
//	for (cp ; *cp !='\0'; cp++) {
//		cout << *cp ;
//	}
//	cout << endl;
//	//ָ��Ҳ������Ϊ����
//	for (int i = 0;cp[i];i++) {
//		cout << cp[i];
//	}
//	cout << endl;
//	//������ʼָ��+i�ķ�ʽ
//	for (int i=0;*(ch1+i);i++)
//	{
//		cout << *(ch1 + i);
//	}
//	cout << endl;
//
//}





////�ɱ����
//#include<iostream>
//#include<STDARG.H>
//using namespace std;
//
//void outPut(int num, ...) {
//	va_list arguments;
//	va_start(arguments, num);
//	int data1 = va_arg(arguments, int);
//	char data2 = va_arg(arguments, char);
//	char data3 = va_arg(arguments, char);
//
//	cout << num << endl;
//	cout << data1 << endl;
//	cout << data2 << endl;
//	cout << data3 << endl;
//	va_end(arguments);
//}
//
//int main() {
//	outPut(11, 3, 'A', 'B','C'); //����Ĵ�����Ҳ������
//	cout << "----------------" << endl;
//	outPut(11, 3, 'A'); //ȱ��data3������ϵͳ�������һ��char���͵�
//
//}


////ǿ������ת���� ���������ã��õĴ����ǲ���Ҫǿ��ת���ġ�
////(int)���ʽ	���տƼ��ﲻ�Ƽ����ַ��������ҿ����Ĵ�������ô˷���
////static_cast<���Ͷ����>�����ʽ�� ��̬����ת����1.һ�����ڻ��ۺ�������֮���ת����2.֧������ʱ���Ͱ�ȫ��飬ת��ʧ��ʱ����NULL��
////const_cast<���Ͷ����>(���ʽ)    ȥ�����ʽ��const���ԣ�������ʽ�Ƿ�const���ͻᱨ��
////reinterpret_cast<���Ͷ��帽>(���ʽ) ��ת�����ͱ�����ָ�룬���ã��������ͣ�����ָ�룬��Աָ�롣�ڱ���λ�����ϵ�����ת����һ�����ں���ָ��֮��ת�����˽⼴�ɣ�û������
//#include<iostream>
//using namespace std;
//void parentheses() {
//	double x = 5.1;
//	int y = 60;
//	char ch;
//	ch = (char)(x + y);//(x+y)����������ʿת��Ϊdouble; (char)����ǿ��ת��Ϊchar
//	cout << ch << endl;
//
//	cout << sizeof(x) << endl;  //doubleռ8���ֽ�
//	cout << sizeof(y) << endl; //intռ4���ֽ�
//	cout << sizeof(x+y) << endl; //������ֵҲ��double���ͣ�����Ҳ��8
//	cout << sizeof(ch) << endl; //char ռ1���ֽ�
//}
//void staticCast() {
//	int i = 5;
//	double d = 21.3;
//	cout << i / 2 << endl;						//2 �Զ�����ת��Ϊint��
//	cout << static_cast<double>(i) / 2 << endl;	//2.5 ��̬����ǿ��ת��
//	cout << d / 3 << endl;						//7.1 double����
//	cout << static_cast<int>(d / 3);			//7,  ��̬����ת��
//}
//void outPut(char* s) {
//	char str[] = "see you nala";
//	s = str;
//	cout << s << endl;
//}
//int main() {
//	parentheses();
//	cout << "---------------" << endl;
//	staticCast();
//	cout << "---------------" << endl;
//	char str1[] = "hello world";
//	const char* p = str1;
//	//outPut(p);	//����const char* �ǳ������ܴ�ֵ������char *
//	outPut(const_cast<char *>(p)); //ȥ����p��const����
//}






//����ָ�룬ʵ���ǽ������������ת��Ϊֵ�������
//auto_ptr ����Ȩ��ռ�����ܹ���������ת��
//shared_ptr ����Ȩ�����ڲ�ά����һ�����ü�����+1��-1
//weak_ptr	��ָ�룬��Ҫ��shared_ptr���ʹ�ã�Ϊ�˽��ѭ������
//scoped_ptr ��auto���ƣ�����Ȩ��ռ�����ܹ�������������������ת��





////C���쳣����
//#include <stdio.h>
//#include <setjmp.h>
//jmp_buf buf;
//
//double Divide(double a, double b)
//{
//	printf("Divide Double ...\n");
//	if (b==0.0)
//	{
//		longjmp(buf,1); //throw1
//	}
//	else if (b < 0)
//	{
//		longjmp(buf, 2); //throw2
//	}
//	else
//	{
//		return a / b;
//	}
//}
//int Divide(int a, int b)
//{
//	printf("Divide int ... \n");
//	if (b ==0)
//	{
//		longjmp(buf,1 ); //throw1
//	}
//	else if (b < 0)
//	{
//		longjmp(buf, 2); //throw2
//	}
//	else
//	{
//		return a / b;
//	}
//}
//int main() {
//	int ret;
//	ret = setjmp(buf);
//	if (ret == 0) //try Ĭ��ֵ���������˴�
//	{
//		printf("division...\n");
//		//printf(" % f\n", Divide(5.0, 0.0));
//		printf(" % d \n", Divide(5, -1));
//	}
//	else if (ret == 1)  //catch1
//	{
//		printf("division by zero ...\n");
//	}
//	else if (ret == 2)  //catch2
//	{
//		printf("I just support positive number ...\n");
//	}
//	return 0;
//}

////C++���쳣���� ֻ�ܴ���һ�ִ�����
//#include <iostream>
//using namespace std;
//
//double Divide(double a, double b)
//{
//	printf("Divide Double ...\n");
//	if (b == 0.0)
//	{
//		throw 1; //throw1
//	}
//	else
//	{
//		return a / b;
//	}
//}
//int Divide(int a, int b)
//{
//	printf("Divide int ... \n");
//	if (b == 0)
//	{
//		throw 1; //throw1
//	}
//	else
//	{
//		return a / b;
//	}
//}
//int main() {
//	try
//	{
//		printf("division...\n");
//		//printf(" % f\n", Divide(5.0, 0.0));
//		printf(" % d \n", Divide(5, 0));
//	}
//	catch(int)
//	{
//		printf("division by zero ...\n");
//	}
//
//	return 0;
//}