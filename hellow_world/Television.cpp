#include "Television.h"
Television::Television(int valume=0, int channel=0) :m_valume(valume), m_channel(channel) 
{
}

returnValue Television::TvInfo() {
	returnValue res(m_valume, m_channel);
	return res;
}