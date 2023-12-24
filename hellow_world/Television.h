#ifndef _TELEVISION_H_
#define _TELEVISION_H_

//Television 类中定义一个结构体，存放valume和channel
struct returnValue
{
	int valume;
	int channel;
	returnValue() = default; //默认构造，也可以省略等号及defalut
	returnValue(int v, int c) :valume(v), channel(c) {} //
};

class Television
{
	friend class TeleController;
public:
	Television(int valume, int channel);
	returnValue TvInfo(); //返回类型是结构体
private:
	int m_valume;
	int m_channel;
};

#endif //_TELEVISION_H_