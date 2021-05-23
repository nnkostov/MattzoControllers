#pragma once

#include <Arduino.h>

#include "BLEHub.h"
#include "BLELocomotiveConfiguration.h"
#include "MCLedBase.h"

#define AUTO_LIGHTS_ENABLED true

class BLELocomotive
{
public:
    BLELocomotive(BLELocomotiveConfiguration *config, MCController *controller);

    std::vector<BLEHub *> Hubs;

    // Returns a boolean value indicating whether this loco is enabled (in use).
    bool IsEnabled();

    // Returns a boolean value indicating whether we are connected to all BLE hubs.
    bool AllHubsConnected();

    // Sets the given target speed for all motor channels for all hubs.
    void Drive(const int16_t minSpeed, const int16_t speed);

    // Returns a list of functions that need to be handled.
    std::vector<Fn *> GetFn(MCFunction func);

    // Turns the specified function on/off.
    void HandleFn(Fn *fn, const bool on);

    // If true, immediately sets the current speed for all hubs for all channels to zero.
    // If false, releases the emergency brake.
    void EmergencyBrake(const bool enabled);

    // Returns the loco name.
    std::string GetLocoName();

    // Returns the loco address.
    uint GetLocoAddress();

    // Returns the number of hubs in the loco.
    uint GetHubCount();

    // Returns the hub at the given index.
    BLEHub *GetHub(uint index);

    // Returns a boolean value indicating whether the lights should automatically turn on when the loco starts driving.
    bool GetAutoLightsEnabled();

private:
    void initLights();
    void initHubs();
    BLEHub *getHubByAddress(std::string address);
    std::vector<Fn *> getFunctions(MCFunction f);

    std::vector<MCLedBase *> _espLeds;
    BLELocomotiveConfiguration *_config;
    MCController *_controller;
};