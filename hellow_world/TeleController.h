#pragma once
#include "Television.h"
//class Television;
class TeleController
{
public:
	void VolumeUp(Television& tv);
	void VolumeDown(Television& tv);
	void ChannelUp(Television& tv);
	void ChannelDown(Television& tv);
};

