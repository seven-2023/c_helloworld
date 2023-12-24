//#ifndef _DYN_BASE_
//#define _DYN_BASE_
//#include <map>
//#include<string>
//using namespace std;
//
//typedef void* (*CREATE_FUNC)(); //声明一个创建函数的指针函数
//class DynObjectFactory
//{
//public:
//	static void* CreateObject(const string& name) 
//	{
//		map<string, CREATE_FUNC>::const_iterator it;
//		it = m_mapClass.find(name);
//		if (it == m_mapClass.end())
//			return 0;
//		else
//			return it->second();
//	}
//
//	static void Register(const string& name, CREATE_FUNC func) {
//		m_mapClass[name] = func;
//	}
//private:
//	static map<string, CREATE_FUNC> m_mapClass; //静态成员变量，类内声明，类外定义
//};
//__declspec(selectany) map<string, CREATE_FUNC> DynObjectFactory::m_mapClass;
//
//
//class Register
//{
//public:
//	Register(const string& name, CREATE_FUNC func) {
//		DynObjectFactory::Register(name, func);
//	}
//};
//
//#define REGISTER_CLASS(class_name)\
//class class_name__Register{\
//public:\
//	static void* NewInstance()\
//		{\
//			return new class_name;\
//		}\
//private:\
//	static Register m_reg;\
//};
////Register class_name__Register::m_reg(#class_name, class_name__Register::NewInstance);
//
//#endif // !_DYN_BASE_



