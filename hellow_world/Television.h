#ifndef _TELEVISION_H_
#define _TELEVISION_H_

//Television ���ж���һ���ṹ�壬���valume��channel
struct returnValue
{
	int valume;
	int channel;
	returnValue() = default; //Ĭ�Ϲ��죬Ҳ����ʡ�ԵȺż�defalut
	returnValue(int v, int c) :valume(v), channel(c) {} //
};

class Television
{
	friend class TeleController;
public:
	Television(int valume, int channel);
	returnValue TvInfo(); //���������ǽṹ��
private:
	int m_valume;
	int m_channel;
};

#endif //_TELEVISION_H_