//#include <iostream>
//#include <string>
//using namespace std;
//全局对象构造先于main函数,main结束后析构
//1.栈对象会自动调用构造和析构
//2. 堆对象会自动调用构造，但不会自动调用析构，需要手动析构
//3.已初始化的对象存储于 .data段中
//4.未初始化的对象存储与.bss段中




//=========运行时数据====================
// 由程序员分配释放，若不释放，程序结束后由操作系统回收；
// new 在堆区开辟内存， delete释放


//------------引用/别名------------
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

//------实例：交换函数------
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
////引用传递也可以改变变量值，本质是常量指针，指向的地址不可以修改，所指向的地址的值可以修改
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

////const 修饰的常量引用形参，防止勿修改
//void showValue(const int & v) {
//	//v += 20; //报错，
//	cout << v << endl;
//}
//int main() {
//	int a = 10;
//	showValue(a);
//}


////=========函数的默认参数===================
////声明和实现只能有一个有默认参数
//int func(int a, int b, int c);
//int func(int a , int b = 10, int c = 10) {
//	return a + b + c;
//};
//int main() {
//	cout << func(10) << endl;
//	cout << func(10, 20, 30) << endl;
//}

////=========函数的占位参数===================
//int func1(int a, int ) {
//	return a;
//};
////占位参数也可以有默认值
//int func2(int a, int = 50) {
//	return a ;
//};
//int main() {
//	cout << func1(10,20) << endl; //占位参数也必须传值
//	cout << func2(10, 20) << endl;
//}

//=========函数重载===================
//必须满足三个条件：
//1.函数名相同；
//同一个作用域，
//参数类型/个数/顺序不同；

//void func(int a){
//	cout << a<< endl;
//};
////重载时，默认参数会导致编译器不知道调用哪一个，注意
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

//====类/对象 占用空间大小计算========
//类大小计算遵循结构体对齐原则
//与数据成员有关，与成员函数无关，与静态成员无关
//虚继承类的大小影响
//虚函数对类的大小影响

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
//	//查看B1的结构
//	B1 b1;
//	long** p;//创建指针的指针，指向虚基类指针的地址
//	cout << &b1 << endl;		//0000006F12D3F5A8 b1地址，占用8个字节
//	cout << &b1.m_b1 <<" 占用："<<sizeof(b1.m_b1) << endl;	//0000006F12D3F5B0	b1成员变量地址+8，占用4个字节 ,对齐后占用8个字节？
//	cout << &b1.m_bBase << " 占用：" << sizeof(b1.m_bBase) << endl;//0000006F12D3F5B8	b1的虚基类成员变量地址+8，占用4个字节，对齐后占用8个字节？ 所以一共24？
//
//	//查看dd的结构
//	DD d1;
//	cout << &d1 << endl;		//000000F5103AFBC8 b1地址，占用8个字节
//	cout << &d1.m_b1 << " 占用：" << sizeof(d1.m_b1) << endl;	//000000F5103AFBD0	b1成员变量地址+8，占用4个字节
//	cout << &d1.m_b2 << " 占用：" << sizeof(d1.m_b2) << endl;	//000000F5103AFBE0	b1成员变量地址+16，占用4个字节
//	cout << &d1.m_dd << " 占用：" << sizeof(d1.m_dd) << endl;//000000F5103AFBE8	b1的虚基类成员变量地址+8，占用4个字节
//	cout << &d1.m_bBase << " 占用：" << sizeof(d1.m_bBase) << endl;	//000000F5103AFBF0	b1成员变量地址+8，占用4个字节
//	p = (long**)&d1;
//	cout << p[0][0] << endl;
//	cout << p[0][1] << endl;
//	cout << p[2][0] << endl;
//	cout << p[2][1] << endl;
//
//	cout << d1.m_bBase << endl;//直接访问
//	//间接访问,需要运行时支持
//	BBase* p_BBase = &d1;
//	cout << p_BBase->m_bBase << endl;
//
//}

////=========类和对象===================
////--最简单的类----
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

////-----学生实例-------
//class Student {
//	int c_id;//默认为私有权限
//	protected:
//		int c_age; //保护成员属性，类内可访问，类外不行，可继承。
//	private:
//		int c_score; //私有成员属性：类内可访问，类外不行，不可继承。
//	public:
//		string c_name;  
//
//		void setInfo(int setId, int setAge,int setScore) {	
//			c_id = setId;
//			c_score = setScore;
//			if (setAge <=0 || setAge>100) {
//				cout << "设置的年龄不正确" << endl;
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
//	s1.c_name = "孙依依";
//	s1.setInfo(101,1000,99);
//	s1.showStudent();
//}

//-----分别用全局函数和成员函数判断正方体是否相等-------
//class Square {
//	private:
//		int mL; //长
//		int mW; //宽
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
//	cout << "s1面积:" << s1.getArea() << endl;
//	Square s2;
//	s2.setL(10);
//	s2.setW(10);
//	cout << "s2面积:" << s2.getArea() << endl;
//
//	if (isSame(s1, s2)) {
//		cout << "全局函数判断面积相等" << endl;
//	}
//	else
//	{
//		cout << "全局函数判面积不等" << endl;
//	}
//
//	
//	if (s1.isSame(s2)) {
//		cout << "成员函数判断面积相等" << endl;
//		}
//	else
//	{
//		cout << "成员函数判断面积不等" << endl;
//	}
//}

//=================构造函数=====================
/*
1、编译器默认会创建无参构造，有参构造和拷贝构造三种；
2、如已自定义有参，则编译器不再定义无参和有参；
3、如已自定义拷贝，则编译器不再定义无参，有参和拷贝；
*/
//class Person {
//public:
//	Person() {
//		cout << "调用无参构造函数" << endl;
//	}
//	//有参构造函数
//	Person(int a) {
//		m_age = a;
//		cout << "调用有参构造函数" << endl;
//	}
//	//拷贝构造函数
//	Person(const Person &p) {
//		m_age = p.m_age;  //被拷贝的数据也要手动设置一下，编译器是不知道另外一个类的值要跟本类的哪个值对应的。
//		cout << "调用拷贝构造函数.." << endl;
//	}
//
//	~Person() {
//		cout << "析构函数" << endl;
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
//	////括号调用法，建议用这种
//	//Person p1;  //调用无参构造函数，无参构造不能加括号，否则编译器会认为是函数声明。
//	//Person p2(10);  //调用有构造函数
//	//Person p3(p2);  //调用有构造函数
//	//cout << "p2的年龄为：" << p2.age<<endl;
//	//cout << "p3的年龄为：" << p3.age << endl;  //age也必须设置，否则p3的age则是随机数
//
//	////显示调用法
//	//Person p1;
//	//Person p2 = Person(10);
//	//Person p3 = Person(p2);
//
//	////隐式调用法
//	//Person p2 = 10;
//	//Person p3 = p2;
//
//	//调用拷贝构造函数
//	Person p5 = 10;
//	p5.Display_m();
//	Person p6(p5); //调用拷贝构造函数，用p5初始化初始化p6的值
//	p6.Display_m();
//	Person p7=p5; //这种方法与上面等价
//	p7.Display_m();
//}
//
//int main() {
//	test1();
//}

/*----拷贝构造函数调用时机------------
1. 使用一个已经船舰完毕的对象来初始化一个新对象；
2. 值传递方式给函数的参数传值；
3. 以值的方式返回局部对象；
*/
//class Person {
//public:
//	Person() {
//		age = 0;
//		cout << "无参构造函数" << endl;
//	}
//	//有参构造函数
//	Person(int a) {
//		age = a;
//		cout << "有参构造函数" << endl;
//	}
//	//拷贝构造函数， 
//	Person(const Person& p) {
//		age = p.age;  
//		cout << "拷贝构造函数" << endl;
//	}
//
//	~Person() {
//		cout << "析构函数" << endl;
//	}
//	int age;
//};
//
////	//时机1，初始化新对象
////void test1() {
////	Person p1(18);  //调用无参构造函数，无参构造不能加括号，否则编译器会认为是函数声明。
////	Person p2(p1);  //调用拷贝构造函数
//	cout << "p1的年龄为：" << p1.age<<endl;
////	cout << "p2的年龄为：" << p2.age << endl;  
////}
//
////时机2，值传递方式给函数传参
////void doWork(Person p) {}  
////void test2() {
////	Person p1(10);  
////	doWork(p1);  //只是把p1的成员属性拷贝给doWork函数
////}
//
////时机3，以值的方式返回局部对象
//Person doThink() {
//	Person p1;
//	return p1;
//}
//void test3() {
//	Person p2=doThink(); //把返回的局部对象传给p2，会调用拷贝构造函数方式将成员变量传递过来。
//}
//
//int main() {
//	//test1(); //时机1，初始化新对象
//	//test2();  //时机2，值传递方式给函数传参
//	test3();  //时机3，以值的方式返回局部对象
//}






////===============初始化成员列表==================
//class Person {
//public:
//	Person(int a,int b,int c):m_A(a),m_B(b),m_C(c) {
//		cout << "有参构造函数" << endl;
//	}
//
//	~Person() {
//		cout << "析构函数" << endl;
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

////===============类对象作为另一个类的成员==================
//class Phone {
//public:
//	Phone(string name) :m_Pname(name) {
//		cout << "Phone有参构造函数" << endl;
//	}
//
//	~Phone() {
//		cout << "Phone析构函数" << endl;
//	}
//	string m_Pname;
//};
//
//class Person {
//public:
//	//此处编译器自动做了一个 隐式调用： Phone m_Phone = phone_Name;
//	Person(string person_Name,string phone_Name) :m_Name(person_Name), m_Phone(phone_Name) {
//		cout << "Person有参构造函数" << endl;
//	}
//
//	~Person() {
//		cout << "Person析构函数" << endl;
//	}
//	string m_Name;
//	Phone m_Phone;
//};
//
//void test1() {
//	Person p1("孙林林","苹果");
//	cout << p1.m_Name << "有一个" << p1.m_Phone.m_Pname << "手机" << endl;
//};
//
//int main() {
//	test1();
//}


//==============静态成员==================
//-------------静态成员变量/常量/方法------------------
/* 
访问方法：
1. 通过对象成员访问
2. 通过类名访问
-----静态成员变量------
特点：
1. 静态成员属于类而不是对象,但所有对象共享此成员
2. 类内声明，类外初始化，或者cpp中实现
3. 编译阶段就分配内存
4. 推荐使用类成员方式访问，否则会被误认为是对象的成员变量
-----静态成员常量------


-----静态成员方法------
特点：
1. 共享
2. 静态成员函数只能访问静态变量,因为它没有this指针
*/
//class Person {
//public:
//	Person(string name):m_Name(name) {
//		cout << "Person有参构造函数，成员变量m_Name被初始化为："<<m_Name << endl;
//		++m_countObj; //创建对象时+1
//	}
//
//	~Person() {
//		cout << "Person析构函数" << endl;
//		--m_countObj;//销毁对象时-1
//	}
//	static int m_countObj; //静态成员属于类，而不是对象，所以
//	string m_Name;
//
//	static const int m_const = 111; //只有整形的才可以在类体内初始化
//	static const char m_const_char = 'C'; //char也算是小整形
//
//	static void func(int a) {
//		m_countObj = a;
//		//m_Name = "yyy"; // 静态成员函数只能访问静态变量,因为它没有this指针
//		cout << "static void func()， m_countObj 值已修改！" << endl;
//	}
//};
//int Person::m_countObj = 0;
////测试静态成员变量
//void test1() {
//	Person p1("孙林林");
//	cout << "通过对象成员访问m_countObj:" << p1.m_countObj << endl;
//	
//	Person p2("孙依依");
//	cout << "通过对象成员访问m_countObj:" << p2.m_countObj << endl;
//
//	//p1.m_countObj = 200;
//	//cout << "通过类名访问 Person::m_countObj=" << Person::m_countObj << endl; 
//};
//void test2() {
//
//	Person* p3 = new Person("xxx");
//	cout << "通过类名访问 Person::m_const=" << Person::m_const << endl;
//	cout << "通过对象指针访问 Person::m_const=" << p3->m_const << endl;
//	cout << "通过类名访问 Person::m_const_char=" << Person::m_const_char << endl;
//	cout << "通过对象指针访问 Person::m_const_char=" << p3->m_const_char << endl;
//	delete p3;
//
//};
//
////测试静态成员函数
//void test3() {
//	Person* p4 = new Person("杨絮");
//	cout << "通过对象成员指针访问m_countObj:" << p4->m_countObj << "\t通过类名访问m_countObj:" << Person::m_countObj << endl;
//	p4->func(300); //对象指针调用成员方法
//	cout << Person::m_countObj << endl; //300
//	Person::func(400); //通过类调用静态成员函数
//	cout << Person::m_countObj << endl; //400
//	delete p4;
//};
//int main() {
//	//test1();
//	test2();
//	//test3();
//}


//---- 静态成员方法------
//实例2  静态成员方法判定是否是闰年， 
//特点：不需要创建对象
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
//	//通过对象调用，如果只是想判断一下某个年份是否是闰年，需要创建对象，有点不方便
//	Date d(2012);
//	cout << d.IsLeapYear() << endl; //1
//
//	//通过类的静态方法调用
//	cout << Date::IsLeapYear(2012) << endl; //1 
//	cout << Date::IsLeapYear(2023) << endl; //0
//
//}

//==============this指针==================
/* 本质是一个常量指针，指向的地址是不可以修改的，但指向的地址的内容可修改
概念：
1. 成员变量和成员函数是分开存储的
2. 每个非静态成员函数只会诞生一份函数实例，
this功能：
1. 当形和成员变量同名，则可以用this指针来区分，但不建议这么用。
2. 在类的非静态成员中返回对象本身，可使用retrun *this
*/
////功能1
//class Person {
//public:
//	Person(int age) {
//		this->age = age;  //this 指向被调用成员函数所属的对象。
//	}
//	int age;
//};
//
//void test1() {
//	Person p1(18); //这里调用的是Person的构造函数，成员函数属于p1，this就指向p1
//	cout << "m_A:" << p1.age << endl;
//};
//int main() {
//	test1();
//}

//功能2，实例，将p1的钱给p2
//class Person {
//public:
//	Person(int money) {
//		m_Money = money;  //this 指向被调用成员函数所属的对象。
//	}
//	int m_Money;
//
//	////没有返回值，无法实现
//	//void addMoney(Person &p) {
//	//	this->m_Money += 100;
//	//	p.m_Money -= 100;
//	//}
//
//	////返回的是Person对象，编译器会拷贝出新的Person，所以无法传递下去， 注意不能这么使用
//	//Person addMoney(Person& p) {
//	//	this->m_Money += 100;
//	//	p.m_Money -= 100;
//	//	return *this;
//	//}
//
//	//返回对象的本体,这是一个链式编程思想
//	Person & addMoney(Person& p) {
//		this->m_Money += 100;
//		p.m_Money -= 100;
//		return *this;
//	}
//};
//
//void test1() {
//	Person p1(1000); //p1拥有 1000块
//	cout << "p1拥有:" << p1.m_Money <<"块钱"<< endl;
//	Person p2(0); //p2拥有 0块
//	cout << "p2拥有:" << p2.m_Money << "块钱" << endl;
//
//	p2.addMoney(p1).addMoney(p1).addMoney(p1);  //链式编程思想
//	cout << "p1拥有:" << p1.m_Money << "块钱" << endl;
//	cout << "p2拥有:" << p2.m_Money << "块钱" << endl;
//
//};
//int main() {
//	test1();
//}


//==============空指针调用成员函数==================
/*
概念：
空指针可以调用成员变量和成员函数，但不能访问访问this空指针

*/
//class Person {
//public:
//	int m_Age;
//	Person(int age) :m_Age(age) {}
//	void pirntClassName() {
//		cout << "类的名字是Person" << endl;
//	}
//
//	//void showAgee() {
//	//	cout << "年龄是："<<m_age << endl;   ////报错,因为m_age就相当于this->m_age,没有实例化之前this是一个空指针
//	//}
//	void showAgee() {
//		/*cout << "年龄是：" << this->m_Age << endl; */  //报错,因为m_age就相当于this->m_age
//		if (this == NULL) {
//			return;
//		}
//		else
//		{
//			cout << "年龄是：" << this->m_Age << endl;   //这样就不会报错了
//		}
//		
//	}
//};
//
//void test1() {
//	Person* p = NULL;
//	//p->m_age;
//	//p->pirntClassName();
//	//p->showAgee(); //报错 
//	Person p1(10);
//	p1.showAgee();
//	p->showAgee();
//};
//int main() {
//	test1();
//}


////==============常函数==================
///*
//概念：
//1.const 修饰成员函数名；
//2.常函数不可以修改成员属性，但如果成员属性声明时加关键字mutable后，在常函数就可以修改了。
//*/
//class Person {
//public:
//	Person(int a):m_A(a) {};
//	int m_A;
//	mutable int m_B; //mutable（可变的），此时它可以被常函数修改
//	
//	
//	//this本质是常量指针，指向不可修改，但指向的值可修改；
//	//在成员函数后面加const，修饰的是this指向的值，所以不可修改，相当于const Person * const this;
//	void changeValue1() const{
//		//this->m_A = 100; //报错
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
//	cout << p1.m_B << endl;  //-858993460，实例化时，并没有定义
//	p1.changeValue1();
//	cout << p1.m_B << endl;  //200,被changeValue()赋值了
//};
//void test2() {
//	const Person p1(10); //常对象
//	p1.changeValue1();
//	cout << p1.m_B << endl;  //200,被changeValue()赋值了
//	//p1.changeValue2(); //报错，常对象只能调用常函数。
//};
//int main() {
//	//test1();
//	test2();
//}

//==============友元==================
/*
概念：
	声明友元后，可以访问私有成员
	不属于类，所以在类的任意位置定义作用都相同
*/
//友元函数，示例1：
//class Home {
//	friend void goodGay(Home* home);//声明友元函数
//public:
//	Home(){
//		m_SittingRoom = "客厅";
//		m_BedRoom = "卧室";
//	};
//	string m_SittingRoom;//客厅
//private:
//	string m_BedRoom;//卧室
//};
//
////全局函数
//void goodGay(Home *home) {
//	cout << "好基友全局函数 正在访问：" << home->m_SittingRoom << endl;
//	cout << "好基友全局函数 正在访问：" << home->m_BedRoom << endl; //定义友元后就不报错了，可以访问私有成员属性
//}
//void test1() {
//	Home home;
//	goodGay(&home);
//};
//
//int main() {
//	test1();
//}


////友元函数，示例2：
//#include <math.h>
//class Point {
//	friend double Distance(const Point& p1,const Point& p2);//声明友元函数,放在public或private都一样的效果
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
////全局函数
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
//	cout << "两个点的距离是：" << Distance(p1, p2);
//}


//友元类，示例1：
//class Home {
//	friend class goodGay;//声明友元类
//public:
//	Home();//声明构造函数
//	string m_SittingRoom;//客厅
//private:
//	string m_BedRoom;//卧室
//};
//
////类的构造函数和成员函数可以放在外面定义
//Home::Home() {
//	m_SittingRoom = "客厅";
//	m_BedRoom = "卧室";
//};
//
//
////好基友类
//class goodGay {
//public:
//	goodGay() {
//		hp = new Home;  //在堆区，开辟一个Home类型的内存空间存放Home类，返回一个指针，用hp接收这个指针
//	};
//
//	void visit() {
//		cout << "好基友全局函数 正在访问：" << hp->m_SittingRoom << endl;
//		cout << "好基友全局函数 正在访问：" << hp->m_BedRoom << endl; //定义友元后就不报错了，可以访问私有成员属性
//		cout << sizeof(*hp);//Home类占据80个字节
//	}
//private:
//	Home* hp;//定义一个Home类型的指针
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

////友元类，示例2，遥控器是电视机的友元类
//#include "Television.h"
//#include "TeleController.h"
//int main() {
//	Television tv1(1,12);
//	TeleController tc;
//	tc.ChannelUp(tv1);
//	tc.VolumeUp(tv1);
//	returnValue res = tv1.TvInfo();  //Television 类中定义一个结构体，存放valume和channel
//
//	cout << "valumeInfo:" << res.valume << endl;
//	cout << "channelInfo:" << res.channel << endl;
//}



////----------友元成员函数--------
////这种方式，搞不懂为啥必须这么写才能访问到Home的私有成员？这种友元太拐弯了，不要用了。也搞不懂有何意义。
//class Home; //必须Home 必须先声明，且放在goodGay的前面，为啥？
//class goodGay {
//public:
//	goodGay();  //这三个函数也时必须先声明，实现写到外面，否则提示“调用了未定义的Home”，为啥？
//	void visit();
//	void visit2();
//private:
//	Home* hp;//定义一个Home类型的指针
//};
//class Home {
//	friend void goodGay::visit();
//public:
//	//声明构造函数
//	Home() {
//		m_SittingRoom = "客厅";
//		m_BedRoom = "卧室";
//	};
//	string m_SittingRoom;//客厅
//private:
//	string m_BedRoom;//卧室
//};
//
//goodGay::goodGay() {
//	hp = new Home;
//}
//void goodGay::visit() {
//	cout << "好基友全局函数 正在访问：" << hp->m_SittingRoom << endl;
//	cout << "好基友全局函数 正在访问：" << hp->m_BedRoom << endl; //定义友元后就不报错了，可以访问私有成员属性
//}
//void goodGay::visit2() {
//	cout << "好基友全局函数 正在访问：" << hp->m_SittingRoom << endl;
//	//cout << "好基友全局函数 正在访问：" << hp->m_BedRoom << endl; //定义友元后就不报错了，可以访问私有成员属性
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


////==============重载==================
////+号运算符重载,示例1
//class Person {
//public:
//	int m_A;
//	int m_B;
//	//方法1成员函数实现+号重载
//	/*Person operator+(Person& p)
//	{
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}*/
//};
////方法2，全局函数实现+重载
//Person operator+(Person& p1, Person& p2) {
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
//
////方法3，加号的的函数重载，实现person=person+int
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
//	//成员函数重载的本质调用
//	//Person p3 = p1.operator+(p2);
//	//全局函数重载的本质调用
//	//Person p3 = operator+(p1,p2);
//	// 以上两种都可以简化为下面一种：
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

////+号运算符重载,示例2
//class Complex {
//public:
//	Complex() {}
//	~Complex() {}
//	Complex(int real,int imag):m_real(real),m_imag(imag)
//	{	
//	}
//	//1.成员函数实现相加，缺点是c1会被改变
//	Complex& Add(const Complex& other) {
//		m_real += other.m_real;
//		m_imag += other.m_imag;
//		return *this;
//	}
//
//	////2. 成员函数+号重载 ,成员函数+和友元函数+可以共存，但优先级高于友元函数+
//	//Complex operator+(const Complex& other) {
//	//	int r = m_real + other.m_real;   //正常情况可以不使用this
//	//	int i = this->m_imag + other.m_imag; //使用this看着更明显一点
//	//	return Complex(r, i);//使用构造函数构造出一个对象并返回
//	//}
//
//	//3.友元函数+号重载
//	friend Complex operator+(const Complex& com1,const Complex& com2) {
//		int r = com1.m_real + com2.m_real;   //正常情况可以不使用this
//		int i = com1.m_imag + com2.m_imag; //使用this看着更明显一点
//		return Complex(r, i);//使用构造函数构造出一个对象并返回
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
//	////1.成员函数实现相加，缺点是c1会被改变
//	//c1.Add(c2);
//	//c1.Display();
//	
//	//2. 成员函数+号重载  //3.友元函数+号重载
//	Complex c3 = c1 + c2;
//	c3.Display();
//}

////-----左移运算符（<<）重载-----
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
////无法实现成员函数重载<<运算符
//ostream & operator<<(ostream &cout, Person &p) {  //cout是ostream的返回类型
//	cout << "m_A=" << p.m_A << "\tm_B=" << p.m_B;
//	return cout;
//}
//void test1() {
//	Person p1(10,10);
//	cout << p1 <<"\t实现了“<<”的 重载." << endl;;
//};
//
//int main() {
//	test1();
//}

////等号运算符重载
//#include "string.h"
//#include <iostream>
//using namespace std;
//
//class Str {
//public:
//	explicit Str(const char* str) //转换构造函数，将字符串str构造成Str对象 , explicit后就无法隐式调用了
//	{  
//		cout << "调用：Str(const char* str)//转换构造函数" << endl;
//		m_str = AllocAndCpy(str);
//	}
//	Str(const Str& other) //拷贝构造函数
//	{  
//		cout << "调用：Str(const Str& other)//拷贝构造函数" << endl;
//		m_str = AllocAndCpy(other.m_str);
//	}
//	Str& operator=(const Str& other) //赋值运算符重载
//	{
//		cout << "调用：Str& operator=(const Str& other))//赋值运算符重载" << endl;
//		if (&other == this)
//			return *this; //如果等号右边跟左边相同，则直接返回对象本身，不做赋值运算
//		delete[] m_str;//释放掉自己的内存，然后再赋值
//		m_str= AllocAndCpy(other.m_str);
//		return *this;
//	}
//
//	Str& operator=(const char* str) //字符串赋值运算符重载
//	{
//		cout << "Str& operator=(const char* str) //字符串赋值运算符重载" << endl;
//		delete[] m_str;//释放掉自己的内存，然后再赋值
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
//		int len = strlen(str) + 1;  //strlen()返回的是字符的数量不包含字符串的结束符
//		char* newstr = new char[len];
//		memset(newstr, 0, len); //向newstr中填len个0
//		strcpy_s(newstr, len, str); //参数：拷贝对象，拷贝长度，拷贝内容
//
//		return newstr;
//	}
//};
//
//int main() {
//	Str s1("abc");
//	//Str s2(s1); //调用拷贝构造函数
//	//s2.Display();
//
//	//Str s3("");//调用拷贝构造函数
//	//s3= s1;//调用赋值运算符重载
//	//s3.Display();
//
//	Str s4("");
//	s4= "xxx"; //加上explicit后，转换构造函数无法被调用，编译出错。定义Str& operator=(const char* str) 后就可以直接调用了
//	//Str s4="xxx"; //这种方法必须先将右值转换为Str对象，但没有相应的构造函数
//	s4.Display();
//}




//========继承==========
//class BasePage {
//public:
//	void header() {
//		cout << "首页，注册，登录..." << endl;
//	}
//	void left() {
//		cout << "java，python，c++ 课程分类列表..." << endl;
//	}
//	void footer() {
//		cout << "帮助中心，站内地图，交流合作..." << endl;
//	}
//};
//
//class Java :public BasePage {
//public:
//	void content() {
//		cout << "JAVA 视频教程" << endl;
//	}
//};
//class Python :public BasePage {
//public:
//	void content() {
//		cout << "Python 视频教程" << endl;
//	}
//};
//class Cpp :public BasePage {
//public:
//	void content() {
//		cout << "C++ 视频教程" << endl;
//	}
//};
//
//void test() {
//	cout << "-----java页面-----" << endl;
//	Java java;
//	java.header();
//	java.left();
//	java.footer();
//	java.content();
//
//	cout << "-----python页面-----" << endl;
//	Python python;
//	python.header();
//	python.left();
//	python.footer();
//	python.content();
//
//	cout << "-----cpp页面-----" << endl;
//	Cpp cpp;
//	cpp.header();
//	cpp.left();
//	cpp.footer();
//	cpp.content();
//}
//int main() {
//	test();
//}

////----继承的权限----
//class BasePage {
//public:
//	BasePage() {
//		cout << "BasePage 构造..." << endl;
//	}
//	~BasePage() {
//		cout << "BasePage 析构..." << endl;
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
//		cout << "Son 构造..." << endl;
//	}
//	~Son() {
//		cout << "Son 析构..." << endl;
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


////虚继承解决钻石继承的二义性问题，避免产生多次拷贝
////虚基类Furniture是钻石顶，SofaBed是最后的
//#include<iostream>
//using namespace std;
//class Furniture //虚基类
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
//class Bed :virtual public Furniture //虚继承
//{
//public:
//	Bed(int weight):Furniture(weight) //虚继承要使用基类的构造来构造自己的
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
//class Sofa :virtual public Furniture //虚继承
//{
//public:
//	Sofa(int weight):Furniture(weight) //虚继承要使用基类的构造来构造自己的
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
//	SofaBed(int weight):Bed(weight), Sofa(weight), Furniture(weight) //全都要写在这里
//	{
//		cout << "SofaBed..." << endl;
//		FoldIn(); //默认折叠
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




//打印类的结构
// 打开“Develop Command Prompt ...”
// cd D:\c_study\hellow_world\hellow_world\
//cl /d1 reportSingleClassLayoutBasePage hellow_world.cpp
//cl /d1 reportSingleClassLayoutSon hellow_world.cpp

//=========多态=========
/*
功能：基类指针指向派生类的对象，调用的是派生类的虚函数

静多态特点：函数重载，运算符重载


动多态(运行时确定函数地址)
满足条件：
1. 有继承关系
2. 子类重写父类虚函数
调用方法：
父类指针指或引用指向子类对象
优点：灵活
缺点：调用时需要有查找虚函数表的过程，效率较低
*/

//class Animal {
//public:
//	//动态多态需要创建虚函数，virtual修饰， 编译时，不指定函数的调用
//	virtual void speek() {
//		cout << "动物在说话..." << endl;
//	}
//};
//class Cat:public Animal {
//public:
//	virtual void speek() {	//重写父类函数时，virtual可省略，参见Dog类
//		cout << "小猫在说话..." << endl;
//	}
//};
//class Dog :public Animal {
//public:
//	void speek()  {
//		cout << "小狗在说话..." << endl;
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

//----------多态实例----------
/*
优点：可读性强，利于后期扩展和维护
*/
//--普通方式实现计算器功能--
//class Calculator {
//public:	
//	int getResult(string oper) {
//		if (oper == "+") {
//			return m_Num1 + m_Num1;
//		}
//		else if (oper == "-") {
//			return m_Num1 - m_Num2;
//		}
//		//如果要提供新的运算，需要修改类的源码
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



////--多态方式实现计算器功能--
////将计算器类抽象出来
//class AbstractCalculator {
//public:
//	/*virtual int getResult() {
//		return 0;
//	}*/
//	virtual int getResult() = 0; //纯虚函数
//	int m_Num1;
//	int m_Num2;
//};
////加法运算
//class AddCalculator :public AbstractCalculator {
//public:
//	//重写虚函数，否则子类依然是纯虚函数
//	virtual int getResult() {
//		return m_Num1+m_Num2;
//	}
//};
////减法运算
//class SubCalculator :public AbstractCalculator {
//public:
//	virtual int getResult() {
//		return m_Num1 - m_Num2;
//	}
//};
////扩展：乘法运算，只需要扩展就可以了，不需要修改父类代码
//class MulCalculator :public AbstractCalculator {
//public:
//	virtual int getResult() {
//		return m_Num1 * m_Num2;
//	}
//};
//void test() {
//	//AbstractCalculator c; //纯虚函数无法实例化
//
//	//加法指针，用父类创建指针，指向子类在堆区开辟的地址
//	AbstractCalculator * p_Add =new AddCalculator;
//	p_Add->m_Num1 = 10;
//	p_Add->m_Num2 = 10;
//	cout << p_Add->m_Num1 << "+" << p_Add->m_Num2 << "=" << p_Add->getResult() << endl;
//	delete p_Add;
//
//	//减法指针
//	AbstractCalculator* p_Sub = new SubCalculator;
//	p_Sub->m_Num1 = 10;
//	p_Sub->m_Num2 = 10;
//	cout << p_Sub->m_Num1 << "-" << p_Sub->m_Num2 << "=" << p_Sub->getResult() << endl;
//	delete p_Sub;
//
//	//乘法指针
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

//-- 多态 纯虚函数 --
//拥有纯虚函数的类叫做抽象类，不能声明抽象类对象，
//纯虚函数不需要实现，实现的事情交给派生类

////纯虚函数 抽象类，实例1，饮料制作
//class AbstractDrinking {
//public:
//	virtual void Boil() = 0; //烧水，纯虚函数必须重写
//	virtual void PutSomething() = 0; //加入辅料
//	//virtual void waitMinutes() = 0; //等待几分钟，如果是纯虚函数，则子函数必须重写，否则报错
//	virtual void waitMinutes() { //虚函数不需要重写
//		cout << "等待几分钟" << endl;
//	}
//	void makeDrink() {
//		Boil();
//		PutSomething();
//		waitMinutes();
//	}
//};
////制作咖啡
//class Coffee :public AbstractDrinking {
//public:
//	
//	virtual void Boil() {
//		cout << "烧农夫山泉水"<<endl;
//	}
//	virtual void PutSomething() {
//		cout << "放入速溶咖啡"<<endl;
//	}
//	/*virtual void waitMinutes() {
//		cout << "等待几分钟" << endl;
//	}*/
//};
////制作茶水
//class Tee :public AbstractDrinking {
//public:
//	virtual void Boil() {
//		cout << "烧娃哈哈纯净水" << endl;
//	}
//	virtual void PutSomething() {
//		cout << "放入茶叶" << endl;
//	}
//	/*virtual void waitMinutes() {
//		cout << "等待几分钟" << endl;
//	}*/
//};
//
//void doWork(AbstractDrinking * pAbs) { //定义
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

////纯虚函数 抽象类实例2，画
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
////简单工厂模式
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
//	//Shape s;//Error,抽象类不能实例化对象
//	vector<Shape*> v;//Shape类型的指针容器
//	Shape* ps;	//Shape类型的指针
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
//	DeleteAllShapes(v); //删除对象，防止内存泄露
//}

////动态创建对象
////动态调用对象方法
////动态操作对象属性
////需要给每个类添加元数据
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
//		vector<Shape*> v;//Shape类型的指针容器
//		Shape* ps;	//Shape类型的指针
//		ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Circle"));
//		v.push_back(ps);
//	
//		//ps = new Square;
//		ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Square"));
//		v.push_back(ps);
//	
//		//DrawAllShapes(v); //Circle::Draw()  Square::Draw()
//		//DeleteAllShapes(v); //删除对象，防止内存泄露
//}


//RTTI
// 静态转型
// static_cast 用在编译器认可的转型
// reinterpret_cast 用在编译器不认可的转型，不做对齐操作，兼容性差，不建议使用
// const_cast 去除常量性
// 运行时转型，性能不如虚函数
//dynamic_cast<> 1,运行在抽象类上；2.编译器开启“启用运行时类型信息（默认开启）”
//typeid()返回typeinfo对象

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
//		Circle* p_Circle = dynamic_cast<Circle*>(p_Shape); //安全向下转型，因为Shape是抽象类，否则是不安全的
//		p_Circle->Draw();
//	}
//	else if(dynamic_cast<Square*>(p_Shape))
//	{
//		cout << "p_Shape is point to Square object" << endl;
//		Square* p_Square = dynamic_cast<Square*>(p_Shape); //安全向下转型
//		p_Square->Draw();
//	}
//	else
//	{
//		cout << "p_Shape is point to other object" << endl;
//	}
//	
//	//typeid()->typeinfo对象
//	//cout << typeid(*p_Shape).name() << endl; //class Rectangle ，指针指向的类名，而不能写成指针本身
//	//cout << typeid(Circle).name() << endl; //class Circle
//	if (typeid(*p_Shape).name()==typeid(Circle).name()) //指针指向的类名与Circle类名相同，则...
//	{
//		cout << "p_Shape is point to Circle object" << endl;
//		((Circle*)p_Shape)->Draw(); //安全向下转型，功能等同于dynamic_cast
//	}
//	else if (typeid(*p_Shape).name() == typeid(Square).name())
//	{
//		cout << "p_Shape is point to Square object" << endl;
//		((Square*)p_Shape)->Draw(); //安全向下转型，功能等同于dynamic_cast
//	}
//	else
//	{
//		cout << "p_Shape is point to other object" << endl;
//	}
//}



//--虚析构/纯虚析构--
/*
作用：
1.解决父类指针可释放子类对象
虚析构和纯虚析构区别：
纯虚会使此类变成抽象类，无法实例化对象。
*/
//class Animal {
//public:
//	Animal() {
//		cout << "-->Animal构造函数调用" << endl;
//	}
//	////普通析构析构，会导致在delete父类指针时，无法将子类对象析构掉，所以不能这么
//	//~Animal() {
//	//	cout << "<--Animal析构函数调用" << endl;
//	//}
//
//	////虚析构
//	//virtual ~Animal() {
//	//	cout << "<--Animal析构函数调用" << endl;
//	//}
//	
//	//纯虚析构,需要有具体实现，且有了纯虚析构，这个类就变成了抽象类，无法实例化
//	virtual ~Animal() = 0;
//	virtual void speek() = 0;
//};
////纯虚析构的实现
//Animal::~Animal() {
//	cout << "<--Animal析构函数调用" << endl;
//}
//
//class Cat:public Animal {
//public:
//	Cat(string name) {
//		m_Name = new string(name);
//		cout << "-->Cat构造函数已调用" << endl;
//	}
//	~Cat() {
//		if (m_Name != NULL) {
//			delete m_Name;
//			m_Name = NULL;
//			cout << "<--Cat析构函数已调用" << endl;
//		}
//	}
//	virtual void speek() {	//重写父类函数时，virtual可省略，参见Dog类
//		cout <<*m_Name<< "小猫在说话..." << endl;
//	}
//	string* m_Name; //定义一个指针指向堆区的string类型的name
//};
//class Dog :public Animal {
//public:
//	void speek()  {
//		cout << "小狗在说话..." << endl;
//	}
//};
//
//void doSpeek(Animal &animal) {
//	animal.speek();
//}
//
//void test() {
//	////方法1,这种调用方法，只有父类需要析构的时候才会调用子类析构，不能人为控制堆区释放
//	//Cat cat("TOM");
//	//doSpeek(cat); 
//	//Dog dog;
//	//doSpeek(dog); 
//	///*
//	//--Animal构造函数调用
//	//--Cat构造函数已调用
//	//TOM小猫在说话...
//	//--Animal构造函数调用
//	//小狗在说话...
//	//--Animal析构函数调用
//	//--Cat析构函数已调用
//	//--Animal析构函数调用
//	//*/
//
//	//方法2,析构/虚析构/纯虚析构
//	Animal* pAnimal = new Cat("加菲");
//	pAnimal->speek();
//	delete pAnimal;  //这个时候并没有把Cat析构函数，会有内存泄露
//	cout << "------------------------" << endl;
//	Dog dog;
//	doSpeek(dog);
//	/*
//	-->Animal构造函数调用
//	-->Cat构造函数已调用
//	加菲小猫在说话...
//	//内存泄露点：小狗的析构没有调用
//	<--Animal析构函数调用
//
//	-->Animal构造函数调用
//	小狗在说话...
//	<--Animal析构函数调用
//	*/
//}
//
//int main() {
//	test();
//}

//虚函数的调用
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
//	/*virtual */void Func1() //省略vertual关键字，它依然是虚函数。
//	{
//		cout << "Derived::Func1()" << endl;
//	}
//	/*virtual */void Func2() //省略vertual关键字，它依然是虚函数。
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
//	p_Base->Func1(); //Derived::Func1() 虚函数是根据指针指向的对象来调用的
//	p_Base->Func2(); //Derived::Func2() 虚函数是根据指针指向的对象来调用的
//	p_Base->Func3(); //Base::Func3() 非虚函数是根据指针类型调用的
//}

////虚析构
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
//	/*virtual */void Func1() //省略vertual关键字，它依然是虚函数。
//	{
//		cout << "Derived::Func1()" << endl;
//	}
//	/*virtual */void Func2() //省略vertual关键字，它依然是虚函数。
//	{
//		cout << "Derived::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Derived::Func3()" << endl;
//	}
//};
//int main() {
//	Base* p_Base=new Derived; //非析构函数，Base... Derived... 
//
//	p_Base->Func1(); //Derived::Func1() 虚函数是根据指针指向的对象来调用的
//
//	delete p_Base; //~Base... ，派生类没有被析构掉，内存泄露 。使用了虚析构后Derived也会被析构掉了
//}


//虚函数列表指针
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
//	void Func2()  //继承虚函数
//	{
//		cout << "Derived::Func2()" << endl;
//	}
//	virtual void Func3()  //继承虚函数
//	{
//		cout << "Derived::Func3()" << endl;
//	}
//	int m_dataDerived;
//};
//typedef void (*FUNC)();
//int main() {
//	cout << sizeof(Base) << endl; //16 = 8（虚表指针）+ 8（4（int m_data）对齐后=8）
//	cout << sizeof(Derived) << endl; //24=8（虚表指针）+ 8（4（int m_dataBase）对齐后=8） + 8（4（int m_dataDerived）对齐后=8）
//
//	//Base b;
//	//long** p = (long**)&b;
//	//FUNC fun = (FUNC)p[0][0]; //Base::Func1()，指向虚函数表
//	//fun(); //x86运行成功，64为啥不行
//	//fun = (FUNC)p[0][1]; //Base::Func2()，指向虚函数表
//	//fun(); //x86运行成功，64为啥不行
//
//	Derived d;
//	long** p = (long**)&d;
//	FUNC fun = (FUNC)p[0][0]; //Base::Func1()，虚表中第一个是基类的虚函数
//	fun(); 
//	fun = (FUNC)p[0][1]; //Derived::Func2()，虚表中第2个是派生类的虚函数
//	fun(); 
//	fun = (FUNC)p[0][2]; //Derived::Func3()，，虚表中第3个是派生类的虚函数
//	fun(); 
//}

////切割
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
//	//CDocument(const CDocument& other) //拷贝构造
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
//	CMyDoc* p_mydoc = new CMyDoc; //派生类对象指针，
//
//	cout << "#1 testing" << endl;
//	mydoc.func();	//Document::func（继承父类的普通成员函数）  
//	//CMyDoc::virtual void Serialize() 调用自己的虚函数
//
//	cout << "#2 testing" << endl;
//	((CDocument*)(&mydoc))->func(); //同上 ，只是将对象强转成指针
//
//	cout << "#3 testing" << endl;
//	p_mydoc->func(); //同上，指针调用普通成员函数
//
//	cout << "#4 testing" << endl;
//	((CDocument)mydoc).func(); //CDocument::virtual void Serialize()，Serialize完全转化为父类对象，
//}



//========文件操作====================

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	FILE* fp;
//	errno_t err;                                    //不同点1
//	char ch, filename[10];
//	printf("请输入所用的文件名：");
//	scanf_s("%s", filename, 10);
//	if ((err = fopen_s(&fp, filename, "w")) != 0)    //不同点2
//	{
//		printf("无法打开此文件\n");            //如果打不开，就输出打不开
//		exit(0);                               //终止程序
//	}
//	ch = getchar();                            //用来接收最后输入的回车符
//	printf("请输入一个准备存储到磁盘的字符串（以#结束）：");
//	ch = getchar();                            //用来接收从键盘输入的第一个字符
//	while (ch != '#')                          //当输入“#”时结束循环
//	{
//		fputc(ch, fp);                         //向磁盘输出一个字符
//		putchar(ch);                           //将输出的字符显示在屏幕上
//		ch = getchar();                        //再接收从键盘输入的一个字符
//	}
//	fclose(fp);                                //关闭文件
//	putchar(10);                               //向屏幕输出一个换行符
//	return 0;
//}


/*
#include xxx，三种类型
ofstream	写操作
ifstream	读操作
fstream		读写操作
打开方式：
ios::in		只读打开
ios::out	只写
ios::ate	初始位置：文件尾
ios::app	append追加方式写文件
ios::trunc	文件存在时，创建新文件并覆盖它
ios::binary	二进制方式
用或组合
ios::binary | ios::iosapp
*/

//void fWrite() {
//	//1.创建流对象
//	ofstream f_obj;
//	//2.指定打开方式
//	f_obj.open("./test.txt", ios::out);
//	//3.写内容
//	f_obj << "姓名：孙依依" << endl;
//	f_obj << "姓别：女" << endl;
//	f_obj << "年龄：2" << endl;
//	f_obj << "----------------" << endl;
//	//4.关闭对象
//	f_obj.close();
//}
//void fAppend() {
//	//1.创建流对象
//	ofstream f_obj;
//	//2.指定打开方式
//	f_obj.open("./test.txt", ios::app);
//	//3.写内容
//	f_obj << "姓名：杨絮" << endl;
//	f_obj << "姓别：女" << endl;
//	f_obj << "年龄：20" << endl;
//	f_obj << "----------------" << endl;
//	//4.关闭对象
//	f_obj.close();
//}

//4种读文件方式：
//void fRead() {
//	ifstream ifs;
//	ifs.open("./test.txt", ios::in);
//	
//	if (!ifs.is_open()) {
//		cout << "文件打开失败" << endl;
//		return ;
//	}
//
//	////方法1，按字
//	//char buf[1024] = { 0 };
//	//while (ifs>>buf) {  //把buf里的所有信息都读出来
//	//	cout << buf << endl;
//	//}
//
//	////方法2，按行读
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf,sizeof(buf))) {  //把buf里的所有信息都读出来
//	//	cout << buf << endl;
//	//}
//
//	//方法3，string 头文件自带的getline方法
//	string buf;
//	while (getline(ifs,buf)) {  //把buf里的所有信息都读出来
//		cout << buf << endl;
//	}
//
//	////方法4
//	//char c;
//	//while ((c=ifs.get())!=EOF)  //End Of File
//	//{
//	//	cout << c ;
//	//}
//	ifs.close();
//}
//int main() {
//	//fWrite();  //写
//	//fAppend();	//追加
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

//二进制读写文件：
/*
如果以文本形式打开文件，写入字符的时候，遇到\n会作转换
windows平台n转为\r\n
linux平台保留不变
mac系统in转为\r
如果以二进制方式打开文件写入字符的时候，遇到\n不会作转换
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
////这种不带string的结构体太简单了，不适用于正常场景
//struct Person {
//	char m_Name[64];  //建议用char方式（底层用C写的），而不要用string，因为有可能产生异常信息
//	int m_Age;
//};
//void fWrite() {
//	ofstream ofs("./test.txt", ios::out|ios::binary);
//	//ofs.open("./test.txt", ios::in); //可简化为上一步
//	
//	if (!ofs.is_open()) {
//		cout << "文件打开失败" << endl;
//		return ;
//	}
//	Person p = { "张三",18 };
//	ofs.write((const char*)&p, sizeof(p));
//	ofs.close();
//}
////读二进制文件：
//void fRead() {
//	ifstream ifs("./test.txt", ios::in | ios::binary);
//	if (!ifs.is_open()) {
//		cout << "文件打开失败" << endl;
//		return ;
//	}
//
//	Person p;
//	ifs.read((char*)&p, sizeof(p));  //强转成char *，以地址读取具体地址； 给出空间大小。
//
//	cout << "姓名："<<p.m_Name << endl;
//	cout << "年龄："<<p.m_Age << endl;
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
//	/* 不能按照结构体的大小来作为判断，因为结构体里存放的是实际内容的指针，并不是真实字符串的大小。
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

////随机读取
//#include<cassert>
//#include<fstream>
//#include<string>
////randomRead.txt 有abcdefg 7个字符
//int main() {
//	ifstream fin("randomRead.txt");
//	assert(fin);
//	fin.seekg(2); //将指针指向2
//	char ch;
//	fin.get(ch); //将取出来的值放入ch中
//	cout << ch << endl; //c
//
//	fin.seekg(-1, ios::end);
//	fin.get(ch);
//	cout << ch << endl; //g, 最后一个
//
//	fin.seekg(0, ios::end);
//	streampos pos = fin.tellg(); //获取指针偏移位置
//	cout << pos << endl;//7 ,最后一个字符的指针
//}

////字符串流，示例2，将键盘输入的字符串读取，并传给另一个字符串
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

////字符串流，示例2，将double类型转化成string类型, 将string转double
//#include<string>
//#include<sstream>
//string doubleToStr(double d) 
//{
//	ostringstream oss;
//	oss << d; //将double传个oss对象
//	cout << typeid(oss.str()).name() << endl; //class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
//	return oss.str();
//}
//double stringToDouble(const string& str)
//{
//	double val;
//	istringstream iss(str);
//	iss>>val; //将double传个oss对象
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

////字符串流，示例3，
//#include<string>
//#include<sstream>
//int main() {
//	//输入流类和输出流类
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
//	//stringstream 输入输出流类
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



//输出流格式化
//#include<iomanip>
////宽度控制
////对齐控制
////填充控制
////精度控制
////进制控制
//int main() {
//	system("chcp 936");//更改活动页，如果输出中文失败，则用此行
//	int n = 64;
//	cout << "================宽度控制================" << endl;
//	cout << setw(10) << n << '#' << endl; //        64#  右对齐
//	cout << "================对齐控制================" << endl;
//	cout << setw(10) <<setiosflags(ios::left)<< n << '#' << endl; //64        # 左对齐
//	cout << setw(10) << n << '#' << endl; //64        # 对齐设置后就会记住了。
//	//cout << setw(10) << setiosflags(ios::right) << n << '#' << endl; //        64# 右对齐方法1
//	cout << setw(10) << resetiosflags(ios::left) << n << '#' << endl; //        64# 右对齐方法2，default
//	cout << "================填充控制================" << endl;
//	cout << setw(10) << setfill('*') << n << '#' << endl; //********64#
//	cout << setw(10) << n << '#' << endl; //********64#  填充也会记住
//	cout << setw(10) << setfill(' ') << n << '#' << endl; //恢复空格填充
//
//	cout << "================精度控制================" << endl;
//	double d1 = 123.45;
//	double d2 = 0.018755;
//	cout << setprecision(4)<<d1 << endl; //123.5  有效精度为4，并且4舍5入
//	cout << setprecision(4)<<d2 << endl; //0.01876
//	cout << setprecision(2)<<d1 << endl; //1.2e+02 有效精度为2，后面用科学计数法
//	cout << setprecision(2)<<d2 << endl; //0.019 有效精度为2，
//
//	cout << setiosflags (ios::fixed);//使setprecision()控制小数点的精度
//	cout << setprecision(4) << d1 << endl; //123.4500 //小数点后4位，不足的补0
//	cout << setprecision(4) << d2 << endl; //0.0188
//	cout << setprecision(2) << d1 << endl; //123.45 //小数点后2位，多余的四舍五入
//	cout << setprecision(2) << d2 << endl; //0.02 
//
//	cout << "================进制控制================" << endl;
//	cout << hex << 17 << endl; //11		//16*1+1 16进制显示
//	cout << dec << 17 << endl; //17		//10进制
//	cout << oct << 17 << endl; //21		//8*2+1 8进制显示
//
//	cout << "================占位符================" << endl;
//	int x = 2;
//	int y = 6;
//	printf("%d+%d=%d\n",x,y,x+y);
//	printf("%s%d%s\n","孙依依", x, "岁了");
//	system("pause");
//	return 0;
//}


//===========以下是C++高级阶段==============
// 范式编程
//---------模板-----------
//普通模式实现两个整数交换
//void intSwap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << a << endl;
//	cout << b << endl;
//}
////普通模式实现两个浮点数交换
//void doubleSwap(double& a, double& b) {
//	double temp = a;
//	a = b;
//	b = temp;
//	cout << a << endl;
//	cout << b << endl;
//}
////函数模板
//template<typename T>//声明模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个数据类型的抽象
//void mySway(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//	cout << "first=" << a << endl;
//	cout << "second="<< b << endl;
//}
////函数模板重载
//template<typename T>//声明模板，高速编译器后面代码中紧跟着的T不要报错，T是一个数据类型的抽象
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
//	//模板调用
//	double a = 1.11;
//	double b = 2.22;
//	double c = 3.33;
//	//方法1，自动类型推导（传参的类型决定）
//	mySway(a, b);
//	
//	//方法2，显式指定类型
//	//mySway<double>(a, b);
//	//mySway<double>(a, b, c); //调用重载
//}

////--隐式类型转换---
//template<class T> //<class T>==<typename T> ,作用相同，不过为区分类型，建议typename用于函数模板，class用于类模板
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
//	//intCharSway(x, y); //报错，自动推导不支持隐式类型转换
//	//intCharSway<char>(x, y); //显示指定类型，支持隐式类型转换
//	cout << add<int>(x, z) << endl;  //返回98
//	cout << add<char>(x, z) << endl;  //返回b
//}


////--隐式类型转换---
//template<class T> //<class T>==<typename T> ,作用相同，不过为区分类型，建议typename用于函数模板，class用于类模板
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
//	//intCharSway(x, y); //报错，自动推导不支持隐式类型转换
//	//intCharSway<char>(x, y); //显示指定类型，支持隐式类型转换
//	cout << add<int>(x, z) << endl;  //返回98
//	cout << add<char>(x, z) << endl;  //返回b
//}

////求最大值 
//template<typename T, int len>  //定义类型和长度（用于指定数组长度）
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


//--模板局限性---
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
////利用具体化的person，来解决局限性 ,函数前加 template<>，并指定参数类型
//template<> bool myCompare(Person& p1, Person& p2) {
//	if (p1.m_Name==p2.m_Name && p1.m_Age==p2.m_Age) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//int main() {
//	//正常调用
//	int a = 10;
//	int b = 10;
//	cout << myCompare<int>(a, b) << endl; 
//
//	//局限性体现验证
//	Person p1("张三",18);
//	Person p2("李四",18);
//	cout << myCompare(p1, p2) << endl; //由于传参类型是Person，所以具体化的模板会被优先调用。如果没有具体化，则此行报错。
//}

//函数模板特化/重载
//编译器会优先寻找非模板函数，找不到后自动推导为模板函数
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
//template<>  //特化
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
//	//cout << ::max("a", "z") << endl; //为何返回a
//	//cout << strcmp("a", "z") << endl; //返回的是-1
//	cout << ::max(1.1, 2.2) << endl; //自动推导，形参是浮点数，所以调用的是模板
//	cout << ::max(1, 2) << endl; //自动推导，形参是整数，所以调用的是int重载函数
//	cout << ::max<>(1, 2) << endl; //指定调用模板函数+自动推导
//	cout << ::max<int>(1, 2) << endl; //指定调用模板函数+指定类型模板
//}

//---------类模板----------------
//#include <string>
//template<class NameType, class AgeType=bool > //类模板支持默认参数类型
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
//	Person<string, int>p( "孙悟空", 9999); //类模板只支持显式指定类型
//	p.showPerson();
//}

//类模板中的成员函数并不是定义对象时创建的，而是调用时才生成
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
//	T obj;  //定义T类型的成员，因为此时并知道它是成员变量还是成员函数
//	//有连个成员函数
//	void func1() { obj.showPerson1(); }
//	void func2() { obj.showPerson2(); }
//};
//int main() {
//	Myclass<Person1> p; 
//	p.func1();
//	p.func2(); //只有在调用时才报错，"showPerson2": 不是 "Person1" 的成员，因为只有在调用时类模板才会去创建成员函数
//}


//----类模板作为函数参数------
//推荐使用第一种，其他两种不建议，因为2，3比较复杂，其实类模板+函数模板组合体了
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
////方法1， 指定传入的类型
//void func1(Person<string,int> &p) {
//	p.showPerson();
//}
////方法2， 参数模板化
//template<class T1, class T2>
//void func2(Person<T1, T2>& p) {
//	p.showPerson();
//	cout << "T1的类型：" << typeid(T1).name() << endl;
//	cout << "T2的类型：" << typeid(T2).name() << endl;
//	/* 输出结果，string的实际名称就这么长
//	T1的类型：class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
//	T2的类型：int
//	*/
//}
//
////方法3， 整个类模板化
//template<class T>
//void func3(T& p) {
//	p.showPerson();
//	cout << "T的类型：" << typeid(T).name() << endl;
//	/* 打印如下，T的类型就是Person类，我咋感觉第三种中更好呢？虽然它是函数模板+类模板
//		T的类型：class Person<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int>
//	*/
//}
//int main() {
//	Person<string, int>p("唐曾",28);
//	//func1(p);//对象作为函数参数
//	//func2(p);
//	func3(p);
//}

//----类模板继承------
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
//class Son :public Base<int> {  //<int>必须指定类型
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


//类模板继承类模板，可以用T1指定父类中的T类型
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

////--------类模板的函数体类外实现------
//template<class NameType ,class AgeType =int>
//class Person {
//public:
//	Person(NameType name, AgeType age);
//	void showPerson();
//	NameType mName;
//	AgeType mAge;
//};
////构造函数体类外实现
//template<class NameType, class AgeType >
//Person<NameType, AgeType>::Person(NameType name, AgeType age) {
//	this->mName = name;
//	this->mAge = age;
//}
////成员函数体类外实现
//template<class NameType, class AgeType >
//void Person<NameType, AgeType>::showPerson() {
//	cout << "name: " << this->mName << "\tage: " << this->mAge << endl;
//}
//int main() {
//	Person<string, int>p("seven", 36);
//	p.showPerson();
//}


//----180-184------

//=========== STL(Standard Template Library,标准模板库) ===============
/*
诞生原因：数据结构和算法的一套标准提高复用性；
特点：几乎所有代码都采用模板类或者模板函数
广义分为：容器（container）、算法（algorithm）、迭代器（iterator）,迭代器连接容器和算法
六大组件：容器，算法，迭代器，仿函数，适配器（配接器），空间配置器
容器：各种数据结构，如vector（理解为数组），list，deque,set,map等。
序列容器：强调值的排序，序列容器中的每个元素有固定位置。
关联容器：二叉树结构，每个元素之间没有严格的物理上的顺序关系。
算法：sort，find，copy，for_each等。
质变算法：拷贝，替换，删除等改变内容的。
非质变算法：查找，计数，遍历，寻找极值等不会改变内容的。
迭代器：理解为指针就可以了，有输入（读），输出（写），向前（读写操作，只能向前推进），双向（读写，向前向后都可以），随机访问（跳跃的访问任意数据，功能最强）常用就是后两个
仿函数：行为雷系的哈数，可作为算法的某种策略
适配器：一种用来修饰容器或者仿函数或者迭代器接口的东西，暂时不用理解。
空间配置器：负责空间的配置与管理，暂时不用理解。
*/


//#include <vector>
//#include <algorithm> //标准算法头文件
//void myPrint(int val) {
//	cout << val << endl;
//}
//void test01() {
//	vector<int> v;
//	//插入数据
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	////遍历方式1,while 循环
//	//vector<int>::iterator itBegin = v.begin();//起始迭代器
//	//vector<int>::iterator itEnd = v.end();
//	//while (itBegin!=itEnd)
//	//{
//	//	cout << *itBegin << endl;
//	//	itBegin++;
//	//}
//
//	////遍历方式2,for 循环
//	//for (vector<int>::iterator itBegin=v.begin(); itBegin!= v.end();itBegin++)
//	//{
//	//	cout << *itBegin << endl;
//	//}
//
//	//遍历方式3,for_each 循环
//	//利用了回调技术，
//	for_each(v.begin(), v.end(), myPrint);
//}
//int main() {
//	test01();
//}

//#include <vector>
////#include <algorithm> //标准算法头文件
//#include <numeric> //accumulate()
//
//auto accumulateValue(vector<int> val ,int num) {
//	int comp{ num };//传入的值要跟num比较
//	//sum是求和的结果；初值为0； 
//	auto sum = accumulate(begin(val), end(val), 0, [comp](int sum, int v)
//		{
//			if (v < comp) //v是传入的values的值，小于3就跳过，>=3就计算 
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
//	cout << "The sum of the elements greater than " << num - 1 << " is " << sum << endl;  //13  >=3元素的和
//	auto product = std::accumulate(std::begin(values), std::end(values), 1, std::multiplies<int>()); 
//	cout << "The multiplies is :" << product << endl; //150 所有元素的乘积
//}


////双向迭代器
//#include<vector>
//void main() {
//	vector<int> v(6);
//	vector<int>::iterator it = v.begin();
//	vector<int>::iterator it_save = it;
//
//	*it++ = 1; //向向量容器中填值
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
//		cout << *--it_save; //要先--，因为指针已经指向了v.end()了，需要--后才能回到最后一个元素
//	} while (it_save != v.begin());
//	cout << endl;
//
//	//将指针重新指向v.begin()
//	it = v.begin();
//	*(it+2)= 0; //每个两个赋值为0
//	while (it_save != v.end()) {
//		cout << *it_save++;
//	}
//	cout << endl;
//}



//#include <vector>
//#include <algorithm> //标准算法头文件
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
//	//fill(values.begin(),values.begin()+3,0); //前3个填成0，00035
//	//for_each(values.begin(), values.end(), outPut<int>);
//	//cout << endl;
//
//	//向量容器循环排序
//	vector<char> ch;
//	ch.push_back('A');
//	ch.push_back('B');
//	ch.push_back('C');
//	ch.push_back('D');
//	ch.push_back('E');
//	//for_each(ch.begin(), ch.end(), outPut<char>); //ABCDEF
//	//cout << endl;
//	//rotate(ch.begin(), ch.begin() + 3, ch.end());  //从index=3的元素开始重新循环
//	//for_each(ch.begin(), ch.end(), outPut<char>); //DE(rotate)ABC
//	//cout << endl;
//
//	//方法1：
//	////remove(ch.begin(), ch.end(), 'B'); //从头到尾查找，如遇到B则删除，然后后面的值向前移，最后一个补足，ACDEE
//	//ch.erase(remove(ch.begin(), ch.end(), 'B'),ch.end()); //删除最后一位，就得到了结果
//
//	//方法2：
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


//---自定义数据遍历---
//#include <vector>
//#include <algorithm> //标准算法头文件
//class Person {
//public:
//	Person(string name, int age) {
//		mName = name;
//		mAge = age;
//	}
//	string mName;
//	int mAge;
//};
////vector存放对象
//void test01() {
//	Person p1("孙依依", 2);
//	Person p2("杨絮", 35);
//	Person p3("孙林林", 36);
//	//插入数据
//	vector<Person> v; //要指定容器类型
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//
//	//for 循环遍历
//	for (vector<Person>::iterator itBegin=v.begin(); itBegin!= v.end();itBegin++)
//	{
//		//cout <<"姓名："<< (*itBegin).mName<<"\t年龄：" << (*itBegin).mAge<< endl; //解引用指针出来是Person数据类型
//		cout <<"姓名："<< itBegin->mName<<"\t年龄：" << itBegin->mAge<< endl; //itBegin就是个容器的指针，所以可以用箭头直接调用
//	}
//}
////vector存放对象指针
//void test02() {
//	Person p1("孙依依", 2);
//	Person p2("杨絮", 35);
//	Person p3("孙林林", 36);
//	//插入数据
//	vector<Person*> v; //要指定容器类型
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//
//	//for 循环遍历
//	for (vector<Person*>::iterator itBegin = v.begin(); itBegin != v.end();itBegin++)
//	{
//
//		cout << "name：" << (*itBegin) ->mName << "\tage：" << (*itBegin) ->mAge << endl; //itBegin就是个容器的指针，解引用出Person的地址，用箭头指向地址的真实值
//	}
//}
//int main() {
//	test01();
//	test02();
//}




////---容器嵌套容器---
//#include <vector>
//#include <algorithm> //标准算法头文件
//void test01() {
//	vector<vector<int>> v; //嵌套容器
//	
//	//定义内部小容器
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//	//给小容器写入数据
//	for (int i = 0;i < 4;i++) {
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//	}
//	//将小容器写入到大容器中
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//	//双for循环读出容器信息
//	for (vector<vector<int>>::iterator itOut = v.begin();itOut != v.end();itOut++) {
//		for (vector<int> ::iterator itIn = (*itOut).begin();itIn != (*itOut).end();itIn++) {
//			cout << *itIn << " ";
//		}
//		cout << endl;//小容器输出完以后再endl
//	}
//}
//int main() {
//	test01();
//}

//#include <vector>
//typedef vector<int> INTVECTOR;
//
////第一种show
////void ShowVec(const INTVECTOR& v)  //使用引用，否则拷贝构造函数会对v进行拷贝构造，多了一步；用了引用就少了这一步
////{
////	unsigned int i;
////	//int i;
////	for (i = 0; i < v.size();i++) {
////		cout << v[i] << " ";
////	}
////	cout << endl;
////}
//
////第二种show
//void ShowVec(const INTVECTOR& v) {
//	for(INTVECTOR::const_iterator it = v.begin();it != v.end();++it) //如果是it++最后一步会多一个临时指针，指向结束符，动作上多出来一步，还多出来一个销毁指针的动作，++i就省掉了这一步。
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


//---string容器---
//char *是一个指针
//string是一个类，内部封装了char*，是char*型容器
//成员函数：find/copy/delete/replace/insert
/*构造类型
1. string();  // 1. 默认构造，创建空字符串，如，string str
2. string(const char* str);  // 2.使用字符串str初始化
3. string(const string& str); // 3. 拷贝构造初始化，使用一个string对象初始化另一个string对象
4. string(int n,char c);  //使用n个字符c初始化
*/
//void test01() {
//	string s1; //1.默认构造
//	const char* str = "hello world";
//	//string s2("hello world");
//	string s2(str);  //2.使用字符串str初始化
//	cout << "s2=" << s2 << endl;
//
//	string s3(s2); //3.拷贝构造初始化
//	cout << "s3=" << s3 << endl; 
//
//	string s4( 10 ,'a'); //3.拷贝构造初始化
//	cout << "s4=" << s4 << endl;
//}
//int main() {
//	test01();
//}

//---string赋值操作---
/* 函数原型
1. string& operator=(const char* s);   //char*类型字符串，赋值给当前字符串
2. string& operator=(const string &s);   //把字符串s赋值给当前字符串
3. string& operator=(char c);   //字符c赋值给当前字符串
4. string& assign(const char *s);   //把字符串s赋值给当前字符串
5. string& assign(const char *s,int n);   //把字符串s的前n个字符赋值给当前字符串
6. string& assign(const char &s);   //把字符串s赋值给当前字符串
7. string& assign(int n,char c);  //用n个字符c赋值给当前字符串
*/
//void test01() {
//	//1
//	string str1; 
//	str1 = "hello world"; //字符串"hello world"实际是const char * 类型。
//	cout << "str1=" << str1 << endl;
//	//2
//	string str2 = str1; //地址传参
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

////---string拼接---
///* 函数原型
//1. string& operator+=(const char* str);   //重载+=
//2. string& operator+==(const char c);   //重载+=
//3. string& operator+=(const string& str);   //重载+=
//4. string& append(const char *s);   //追加字符串
//5. string& append(const char *s,int n);   //把字符串的前n个字符追加
//6. string& append(const string &str);   //同operator+=(const string& str)
//7. string& append(const string &s, int startPos,int n);  //startPos开始位置，n=长度
//*/
//void test01() {
//	//1
//	string str1;
//	str1 = "我"; 
//	str1 += "爱玩游戏";
//	cout << "str1=" << str1 << endl;
//	//2
//	str1 += ':'; //拼接char字符
//	cout << str1 << endl;
//	//3
//	string str2;
//	str2 = "LOL 王者荣耀";
//	str1 += str2;
//	cout << str1 << endl;
//	//4
//	string str3="I";
//	str3.append(" love ");
//	cout << str3 << endl;
//	//5
//	str3.append("game abcde", 5); //将前5个字符拼接 "game空格"
//	cout << str3 << endl;
//	//6
//	//str3.append(str2);  //直接拼接，
//	//cout << str3 << endl;
//	//7
//	str3.append(str2, 4, 8); //从第四个字符开始拼接，"王者荣耀"，共四个字符,但占用8个字节
//	cout << str3 << endl;
//}
//int main() {
//	test01();
//}

//---字符串查找和替换---
// 这里只用了最常用的，如果需要更多的功能，自行百度
//查找
//void test01() {
//	string str1="abcdefgde";
//	int res = str1.find("de");  //res=3,下标从0开始
//	if(res == -1){   //-1,没有则返回-1
//		cout << "没有找到字符串"<<endl;
//	}
//	else {
//		cout << "找到字符串，pos = " << res << endl;
//	}
//	//rfind //从右往左找,返回结果和find是一样的
//	int res2 = str1.find("de");
//	cout << res2 << endl;
//}
////替换
//void test02() {
//	string str1 = "abcdef";
//	str1.replace(1, 2, "1111"); //a1111def ,从位置1，将bc2个字符替换成1111
//	cout << str1 << endl; 
//}
//int main() {
//	//test01();  //查找
//	test02();  //替换
//}

//---字符串比较---
// 按照ascall码大小进行逐位比较
//一般用于是否相等，一般不会用于比较大小
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

//---字符串的字符读取与修改操作---
//void test01() {
//	string str1 = "hello";
//	//通过[]访问单个字符
//	for (int i = 0;i < str1.size();i++) {
//		cout << str1[i] << " ";
//	}
//	cout << endl;
//
//	//通过at方式访问单个字符,效果与[]相同
//	for (int i = 0;i < str1.size();i++) {
//		cout << str1.at(i) << " ";
//	}
//	cout << endl;
//
//	str1[0] = 'x'; //修改方法1
//	cout << str1 << endl;
//
//	str1.at(1) = 'x'; //修改方法2
//	cout << str1 << endl;
//}
//int main() {
//	test01();
//}

//---字符串的插入---
//void test01() {
//	string str1 = "hello";
//	str1.insert(1, "111"); //h111ello
//	cout << str1 << endl;
//	str1.erase(1, 3);//从1号位置搽除掉三个,回归到hello
//	cout << str1 << endl;
//}
//int main() {
//	test01();
//}

//---字符串截取---
//void test01() {
//	string str1 = "abcedfg";
//	string subStr=str1.substr(1, 3); //bcd
//	cout << subStr << endl;
//}
////截取邮箱名中的用户名seven.sun
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


//---vector容器---
//vector容器构造
//#include<vector>
//void printVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	//构造方式1（默认构造）： 无参构造
//	vector<int> v1; 
//	for (int i = 0;i < 10;i++) {
//		v1.push_back(i);
//	}
//	printVec(v1);
//
//	//构造方式2：通过区间方式进行构造
//	vector<int> v2(v1.begin(),v1.end());
//	printVec(v2);
//
//	//构造方式3:n个元素方式构造
//	vector<int>v3(10, 999); //10个999
//	printVec(v3);
//
//	//构造方式4:拷贝构造
//	vector<int>v4(v3); //10个999
//	printVec(v4);
//}
//int main() {
//	test01();
//}

////vector赋值
//#include<vector>
//void printVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	//先构造出来一个v1
//	vector<int> v1;
//	for (int i = 0;i < 10;i++) {
//		v1.push_back(i);
//	}
//	printVec(v1);
//
//	//赋值方法1：operator=
//	vector<int> v2;
//	v2 = v1;
//	printVec(v2);
//
//	//赋值方法2：assign(v.begin(),v.end())
//	vector<int>v3; //10个999
//	v3.assign(v1.begin(), v1.end());
//	printVec(v3);
//
//	//构造方式3:v.assign(n,xxx)
//	vector<int>v4;
//	v4.assign(10, 888);//10个999
//	printVec(v4);
//}
//int main() {
//	test01();
//}



////vector容器的容量和大小操作
//#include<vector>
//void printVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	//先构造出来一个v1
//	vector<int> v1;
//	for (int i = 0;i < 10;i++) {
//		v1.push_back(i);
//	}
//	printVec(v1);
//
//	if (v1.empty()) {
//		cout << "v1为空" << endl;
//	}
//	else {
//		cout << "v1不为空，容量为："<<v1.capacity() << endl; //13,有预留，如果13也被用完，则扩容到新地址，并把原来的拷贝过去
//		cout << "v1真实大小为：" << v1.size() << endl; //10
//	}
//	//重新指定大小
//	v1.resize(15); //扩容后，默认以0填充
//	printVec(v1);
//	v1.resize(20, 999);//可以指定填充内容
//	printVec(v1);
//	v1.resize(5);//缩小后，多余部分被删除了
//	printVec(v1);
//
//}
//int main() {
//	test01();
//}

//vector容器插入和删除
//#include<vector>
//void printVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01() {
//	vector<int> v1; //定义容器v1
//	v1.push_back(1);//尾部插入
//	v1.push_back(100);
//	printVec(v1);
//
//	//插入
//	v1.insert(v1.begin(), 888);//从头部插入1个888
//	v1.insert(v1.begin(), 3 ,999);//从头部插入3个999
//	printVec(v1);
//
//	//从尾部删除
//	v1.erase(v1.begin());//从头删除1个
//	printVec(v1);
//	//v1.erase(v1.begin(), v1.end());//从头删到尾，等于清空
//	//printVec(v1);
//
//	//清空
//	v1.clear();
//	cout << "清空后的容量："<<v1.capacity() << endl; //6
//	cout << "清空后的实际大小："<<v1.size() << endl; //0
//	printVec(v1);
//}
//int main() {
//	test01();
//}


////vector容器  数据存取
//#include<vector>
//void test01() {
//	vector<int> v1; //定义容器v1
//	for (int i = 0;i < 10;i++) {
//		v1.push_back(i);
//	}
//	for (int i = 0;i < v1.size();i++) {
//		cout << v1[i] << " "; //数组方式访问数组
//	}
//	cout << endl;
//	for (int i = 0;i < v1.size();i++) {
//		cout << v1.at(i) << " "; //at方式访问数组
//	}
//	cout << endl;
//	//获取第一个元素
//	cout << "第一个元素："<<v1.front()<<endl;
//	//获取最后一个元素
//	cout << "最后一个元素：" << v1.back() << endl;
//}
//int main() {
//	test01();
//}


//vector容器  互换
//#include<vector>
//void printVec(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
////容器互换基本操作示例
//void test01() {
//	vector<int> v1; //定义容器v1
//	for (int i = 0;i < 10;i++) {
//		v1.push_back(i);
//	}
//	printVec(v1);
//
//	vector<int> v2; //定义容器v1
//	for (int i = 9;i >= 0;i--) {
//		v2.push_back(i);
//	}
//	printVec(v2);
//
//	//容器交换函数（内置）
//	v1.swap(v2);
//	printVec(v1);
//	printVec(v2);
//}
////实际用途：巧用swap，可收缩内存空间，节约内存
//void test02() {
//	vector<int> v1; //定义容器v1
//	for (int i = 0;i < 100000;i++) {
//		v1.push_back(i);
//	}
//	
//	cout << "v1的容量为:" << v1.capacity() << endl; //138255
//	cout << "v1的实际大小:" << v1.size() << endl; //100000
//
//	v1.resize(3);
//	cout << "v1的容量为:" << v1.capacity() << endl; //138255
//	cout << "v1的实际大小:" << v1.size() << endl; //3
//
//	vector<int>(v1).swap(v1);   //vector<int>(v1) 匿名容器对象，拷贝构造v1，与原来v1调换指针指向，匿名容器自动回收，v1指向容积大小为3的
//	cout << "v1的容量为:" << v1.capacity() << endl; //3
//	cout << "v1的实际大小:" << v1.size() << endl; //3
//}
//int main() {
//	//test01();
//	test02();
//
//}

////vector容器  预留空间（节省扩展空间带来的时间损耗）
//#include<vector>
//void test01() {
//	vector<int> v1; //定义容器v1
//	v1.reserve(100000); //预留10w个空间。
//	int num = 0;
//	int* p = NULL;
//	for (int i = 0;i < 100000;i++) {
//		v1.push_back(i);
//		if (p!= &v1[0]) {
//			p = &v1[0];
//			num++;
//		}
//	}
//	cout << num<< endl;  //30(扩容30次);1(预留100000个字节，所以一次就可以填完)
//}
//int main() {
//	test01();
//}

//=============== map 容器==========================
//关联式容器， key:value 

//#include <string>
//#include <map>

//int main() {
//	map<string, int> mapContainer; //创建一个map容器
//
//	//赋值方法
//	mapContainer["aaa"]= 100;
//	mapContainer.insert(map<string, int>::value_type("bbb", 200));
//	mapContainer.insert(pair<string,int>("ccc", 300));
//	mapContainer.insert(make_pair("ddd", 400)); //make_pare返回值是pair类型，所以等价于上一步。
//	mapContainer["eee"] = 500;
//
//	//查找方法1
//	cout << mapContainer["aaa"] << endl; //100
//	//cout << mapContainer["xxx"] << endl; //0 ,没找到返回0 缺点是不存在的键会构造出一个"xxx":0 的元素 ，不建议使用
//	//查找方法2
//	map<string, int>::iterator it1 = mapContainer.find("bbb");
//	if (it1!=mapContainer.end()) {
//		it1->second = 2000;
//	}
//	else {
//		cout << "not found" << endl;
//	}
//
//	//删除方法1
//	mapContainer.erase("ccc"); //参数是键
//	//删除方法2
//	map<string, int>::const_iterator it2=mapContainer.find("ccc");
//	if (it2!=mapContainer.end()) {
//		mapContainer.erase(it2);  //参数是指针
//	}
//
//	for (map<string, int>::const_iterator it = mapContainer.begin();it != mapContainer.end();++it) {
//		cout << it->first << " " << it->second << endl;
//	}
//	return 0;
//}
//=============deque容器==========================
//双端数组，可以从头端和尾端（中控器控制缓冲区）插入删除操作
/*deque与vector区别
vector对于头部插入和删除效率低，数据量越大效率越低
deque相对而言，对于头部的插入删除速度比vector快
vector访问元素时的嘟嘟会比deque快
*/
//#include<deque>
////普通打印函数,容器原有内容可以被修改，不完美
//void printDeque1(deque<int>&d) {
//	for (deque<int>::iterator it = d.begin();it != d.end();it++) {
//		*it = 100;
//		cout << *it << " "; //100 100 100 100 100 100 100 100 100 100
//	}
//	cout << endl;
//}
////const迭代器，防止打印过程中修改了容器的值
//void printDeque2(const deque<int>& d) {
//	for (deque<int>::const_iterator it = d.begin();it != d.end();it++) {
//		//*it = 100;  //此时若要尝试修改容器值，就会报错
//		cout << *it << " "; //0 1 2 3 4 5 6 7 8 9
//	}
//	cout << endl;
//}
//void test01() {
//	deque<int> d1; //定义容器d1
//	//push_back方式构造容器
//	for (int i = 0;i < 10;i++) {
//		d1.push_back(i);
//	}
//	printDeque2(d1);
//
//	//利用容器区间迭代器构造容器
//	deque<int> d2(d1.begin(), d1.end());
//	printDeque2(d2);
//
//	//指定数量的指定值
//	deque<int> d3(10,999 ); //10个999
//	printDeque2(d3);
//
//	//拷贝构造方式构造容器d2
//	deque<int> d4(d3);
//	printDeque2(d4);
//}
//int main() {
//	test01();
//}

////deque容器赋值操作
//#include<deque>
////const迭代器，防止打印过程中修改了容器的值
//void printDeque(const deque<int>& d) {
//	for (deque<int>::const_iterator it = d.begin();it != d.end();it++) {
//		cout << *it << " "; //0 1 2 3 4 5 6 7 8 9
//	}
//	cout << endl;
//}
//void test01() {
//	deque<int> d1; //定义容器d1
//	//push_back方式构造容器
//	for (int i = 0;i < 10;i++) {
//		d1.push_back(i);
//	}
//	printDeque(d1);
//
//	//等号赋值
//	deque<int> d2;
//	d2 = d1;
//	printDeque(d2);
//
//	//assign 赋值
//	deque<int> d3;
//	d3.assign(d2.begin(), d2.end());
//	printDeque(d3);
//
//	//n个指定值
//	deque<int> d4;
//	d4.assign(10, 999);
//	printDeque(d4);
//}
//int main() {
//	test01();
//}

//deque容器大小操作
/*
注意！！deque是没有总容量capacity()概念的，因为它是一个两端开口的非固定容量
deque.empty();	//判断容器是否为空
deque.size();	//返回元素的个数
deque.resize(num);	//变长则以默认值填充，变短则产出多余部分
deque.resize(num,elem);	// resize后的长度比原来长，则用element填充，如果变短了则删除多余的
*/
//#include<deque>
////const迭代器，防止打印过程中修改了容器的值
//void printDeque(const deque<int>& d) {
//	for (deque<int>::const_iterator it = d.begin();it != d.end();it++) {
//		cout << *it << " "; 
//	}
//	cout << endl;
//}
//void test01() {
//	deque<int> d1; //定义容器d1
//	//push_back方式构造容器
//	for (int i = 0;i < 10;i++) {
//		d1.push_back(i);
//	}
//	printDeque(d1);
//
//	if (d1.empty()) {
//		cout << "d1为空" << endl;
//	}
//	else {
//		cout << "d1不为空" << endl;
//		cout << "d1的实际大小：" << d1.size() << endl;
//	}
//
//	//重新指定容器大小
//	deque<int> d2;
//	d1.resize(15);//新增部分以0来填充
//	d2 = d1;  
//	printDeque(d2); //0 1 2 3 4 5 6 7 8 9 0 0 0 0 0
//
//	//重载版本，重新指定容器大小，新增部分以指定值来填充
//	d1.resize(18,999);  //新增部分以999来填充
//	printDeque(d1); //0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 999 999 999
//
//	d1.resize(3);  //多余部分删除掉
//	printDeque(d1); //0 1 2 
//}
//int main() {
//	test01();
//}
 

//207
//deque容器的插入和删除
/*

*/
//#include<deque>
////const迭代器，防止打印过程中修改了容器的值
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

//=============== set 容器 ==============
// 没有顺序
//#include<set>
//void main() {
//	set<int> iSet;  //创建整形集合
//	iSet.insert(1); //插入数据
//	iSet.insert(3);
//	iSet.insert(5);
//	iSet.insert(7);
//	iSet.insert(9);
//
//	cout << "old_set:" << endl;
//	set<int>::iterator it; //循环并输出集合中的数据
//	for (it = iSet.begin(); it != iSet.end(); it++) {
//		cout << *it << endl; //13579
//	}
//
//	it = iSet.begin(); //
//	iSet.erase(it++);//删掉1,并且迭代器向后移动
//	iSet.erase(it); //删掉了3
//	cout << "new_set:" << endl;
//	for (it = iSet.begin();it != iSet.end();it++) {
//		cout << *it << endl; //579
//	}
//
//	iSet.clear();
//	cout << "after clear():" << endl;
//	for (it = iSet.begin();it != iSet.end();it++) {
//		cout << *it << endl; //空
//	}
//}

//#include <set>
//void main() {
//	set<char> cSet;
//	cSet.insert('S');
//	cSet.insert('E');
//	cSet.insert('V');
//	//cSet.insert('E'); //不能重复，否则只会保留一个
//	cSet.insert('N');
//	cout << "current set:" << endl;
//	set<char>::iterator it;
//	for (it = cSet.begin();it != cSet.end();it++) {
//		cout << *it << endl;
//	}
//
//	char cTmp = 'S';
//	it = cSet.find(cTmp); //查找集合中是否存在某个值
//	if (it == cSet.end()) {
//		cout << "not found " << cTmp << endl;
//	}
//	else {
//		cout << "found " << cTmp << endl;
//	}
//}

//判断相等
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




////与运算
//int main() {
//	cout << "请输入一个正整数，我将算出他的二进制表示中1的个数，并判断其是否是2的幂" << endl;
//	int num;
//	cin >> num;
//	int x = num; //用来计算，如果只用用num直接计算，则num值会被改变
//	int count=0;//记录1的个数
//	while (x) {
//		x = x & (x - 1); //位与运算
//		count++;
//		cout << count << endl;
//	}
//	cout << "您输入的数的二进制有" << count << "个1；" << endl;
//
//	if (count == 1 && num > 1) {  //逻辑运算
//		cout << "这个数是2的幂。" << endl;
//	}
//	else {
//		cout << "这个数不是2的幂。" << endl;
//	}
//}

////递归运算
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


////指针占用大小
//int main() {
//	char c = 'A';
//	char* cp = &c;
//	cout << sizeof(cp) << endl;  //64位系统，地址占用8个字节
//}

//一维指针数组
// 顺序将数组取出并打印
//int main() {
//	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int* p = a;//int *p =&a[0];
//
//	//1. p指针自增方式, p最后指向一个未知地方
//	//for (int i = 0;i < 10;i++,p++) {
//	//	cout << *p << " ";
//	//}
//	//cout << endl;
//	//cout<<*p<<endl;
//	
//	//2. *(p+i)方式 ，p的位置不变
//	for (int i = 0;i < 10;i++) {
//		cout << *(p + i) << " ";
//	}
//	cout << endl;
//	cout << *p << endl;
//}

//二维指针
////1.指针直接输出
//int main() {
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int* p = &a[0][0]; //二维数组不能再用a来指向了，但可以用*p=a[][0]
//	for (int i = 0;i < 12;i++) {
//		cout << *p << " ";
//		p++;
//	}
//	cout << endl;
//}
////2.数组指针方法
//int main() {
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	for (int i = 0;i < 3;i++) {
//		for (int j=0;j < 4;j++) {
//			cout << *(*(a + i) + j)<<" "; //*(a+i)=a[i], so ...
//		}
//	}
//	cout << endl;
//}

//指针方式实现字符串数组拼接
//int main() {
//	char arrStr1[100],arrStr2[100];
//	char* p1 = arrStr1;
//	char* p2 = arrStr2;
//	cout << "请输字符串1：" << endl;
//	gets_s(arrStr1);
//	cout << "请输字符串2：" << endl;
//	gets_s(arrStr2);
//
//	//找到第一个字符串的末端
//	while (*p1)
//	{
//		p1++;//找到字符串1的结尾
//	}
//	while (*p2)
//	{
//		*p1++ = *p2++;
//	}
//	*p1 = '\0';//给字符串结尾加上结束符
//	
//	cout << "new str1: " ;
//	puts(arrStr1);
//}

////指针方式读取字符串数组
//int main() {
//	char ch1[100] = "大家好，很高兴见到各位！";
//	char* cp = ch1;
//	//指针取到的值不为空作为判断
//	for (cp ; *cp !='\0'; cp++) {
//		cout << *cp ;
//	}
//	cout << endl;
//	//指针也可以视为数组
//	for (int i = 0;cp[i];i++) {
//		cout << cp[i];
//	}
//	cout << endl;
//	//数组起始指针+i的方式
//	for (int i=0;*(ch1+i);i++)
//	{
//		cout << *(ch1 + i);
//	}
//	cout << endl;
//
//}





////可变参数
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
//	outPut(11, 3, 'A', 'B','C'); //多余的传进来也不处理
//	cout << "----------------" << endl;
//	outPut(11, 3, 'A'); //缺少data3参数，系统随机给了一个char类型的
//
//}


////强制类型转换， 尽可能少用，好的代码是不需要强制转换的。
////(int)表达式	明日科技里不推荐这种方法，但我看到的大多数都用此方法
////static_cast<类型定义符>（表达式） 静态类型转换：1.一般用于积累和派生类之间的转换；2.支持运行时类型安全检查，转换失败时返回NULL。
////const_cast<类型定义符>(表达式)    去掉表达式的const属性，如果表达式是非const类型会报错
////reinterpret_cast<类型定义附>(表达式) 被转换类型必须是指针，引用，算数类型，函数指针，成员指针。在比特位级别上的类型转换，一般用在函数指针之间转换，了解即可，没有例子
//#include<iostream>
//using namespace std;
//void parentheses() {
//	double x = 5.1;
//	int y = 60;
//	char ch;
//	ch = (char)(x + y);//(x+y)被编译器隐士转换为double; (char)将其强制转换为char
//	cout << ch << endl;
//
//	cout << sizeof(x) << endl;  //double占8个字节
//	cout << sizeof(y) << endl; //int占4个字节
//	cout << sizeof(x+y) << endl; //计算后的值也是double类型，所以也是8
//	cout << sizeof(ch) << endl; //char 占1个字节
//}
//void staticCast() {
//	int i = 5;
//	double d = 21.3;
//	cout << i / 2 << endl;						//2 自动类型转换为int；
//	cout << static_cast<double>(i) / 2 << endl;	//2.5 静态类型强制转换
//	cout << d / 3 << endl;						//7.1 double类型
//	cout << static_cast<int>(d / 3);			//7,  静态类型转换
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
//	//outPut(p);	//报错，const char* 是常量不能传值给变量char *
//	outPut(const_cast<char *>(p)); //去掉了p的const属性
//}






//智能指针，实际是将对象语义对象转化为值语义对象
//auto_ptr 所有权独占，不能共享，但可以转移
//shared_ptr 所有权共享，内部维护了一个引用技术，+1，-1
//weak_ptr	弱指针，它要与shared_ptr配合使用，为了解决循环引用
//scoped_ptr 与auto类似，所有权独占，不能共享。区别在于它不可以转移





////C的异常处理
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
//	if (ret == 0) //try 默认值，都会进入此处
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

////C++的异常处理 只能处理一种错误吗？
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