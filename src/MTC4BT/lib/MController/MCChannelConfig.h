#pragma once

#include "MCChannel.h"
#include "enums.h"

// Controller channel config
class MCChannelConfig
{
  public:
	MCChannelConfig(MCChannel *channel, bool locoStopImmediately, int pwrIncStep, int pwrDecStep, bool isInverted, int pinPwr, DeviceType deviceType);

	// Returns the channel.
	MCChannel *GetChannel();

	// Returns the power step used when increasing power on the channel.
	int GetPwrIncStep();

	// Returns the power % factor on the channel.
	int GetPwr();

	// Returns a boolean value indicating whether the attached device' polarity is inverted.
	bool IsInverted();

	// Returns the power step used when decreasing power on the channel.
	int GetPwrDecStep();

	// Returns the type of device attached to the channel.
	DeviceType GetAttachedDeviceType();

	bool getLocoStopImmediately();

  private:
	// Type of port.
	MCChannel *_channel;

	// Power step to use when increasing power on the channel.
	int _pwrIncStep;

	// Power step to use when decreasing power on the channel.
	int _pwrDecStep;

	// Boolean value indicating whether the attached device' polarity is inverted.
	bool _isInverted;

	bool _locoStopImmediately;
	// Power percentage 0-100.
	int _pwr;

	// Type of device attached to the channel.
	DeviceType _deviceType = DeviceType::Nothing;
};