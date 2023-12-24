#include "TeleController.h"
void TeleController::VolumeUp(Television& tv)
{
	tv.m_valume += 1;
}
void TeleController::VolumeDown(Television& tv)
{
	tv.m_valume -= 1;
}
void TeleController::ChannelUp(Television& tv)
{
	tv.m_channel += 1;
}void TeleController::ChannelDown(Television& tv)
{
	tv.m_channel -= 1;
}