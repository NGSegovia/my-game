#include "gdexample.h"
#include <TurboActivate.h>
#include <iostream>

using namespace godot;

void GDExample::_register_methods() {
    register_method("_process", &GDExample::_process);
}

GDExample::GDExample() {
    // std::cout << "Hello World Constructor Nacho!";
}

GDExample::~GDExample() {
    // add your cleanup here
}

void GDExample::_init() {
    // initialize any variables here
    std::cout << "Hello World Start!";
    GENUINE_OPTIONS opts = {0};
    opts.nLength = sizeof(GENUINE_OPTIONS);

    // How often to verify with the LimeLM servers (90 days)
    opts.nDaysBetweenChecks = 90;

    // The grace period if TurboActivate couldn't connect to the servers.
    // after the grace period is over TA_IsGenuineEx() will return TA_FAIL instead of
    // TA_E_INET or TA_E_INET_DELAYED
    opts.nGraceDaysOnInetErr = 14;


    // In this example we won't show an error if the activation
    // was done offline by passing the TA_SKIP_OFFLINE flag
    opts.flags = TA_SKIP_OFFLINE;


    uint32_t taHandle = TA_GetHandle("18324776654l3946fc44a5f3.49025204");

    if (taHandle == 0)
    {
        printf("Failed to get the handle for the Version GUID specified. ");
        printf("Make sure the Version GUID is correct, and that TurboActivate.dat is in the same folder as your app.\n\n");
        printf("Or use TA_PDetsFromPath() to load the TurboActivate.dat first before getting the handle.\n");
        exit(1);
    }

    HRESULT hr = TA_IsGenuineEx(taHandle, &opts);

    if (hr == TA_OK || hr == TA_E_FEATURES_CHANGED
       || hr == TA_E_INET || hr == TA_E_INET_DELAYED)
    {
        std::cout << "your app is activated and genuine";

        if (hr == TA_E_INET || hr == TA_E_INET_DELAYED)
        {
            // TODO: show a warning to your customers that this time (or recently)
            std::cout << "IsGenuineEx() failed to connect to the LimeLM servers.";
        }
    }
    else
    {
            std::cout << "Not activated OR not genuine OR activated but more than nDaysBetweenChecks + nGraceDaysOnInetErr has passed.";
    }   
    std::cout << "Hello World Finish!";
}

void GDExample::_process(float delta) {
    // std::cout << "Hello World Nacho Petardeo!";
}

