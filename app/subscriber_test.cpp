#include <iostream>
#include <chrono>
#include <thread>

#include "domain_participant.h"
#include "subscriber.h"

#include "MocapMarker_msg.h"
#include "MocapMarker_msgPubSubTypes.h"

namespace sub
{
    cpp_msg::MocapMarker_msg msg;
}

int main(int argc, char *argv[])
{
    // create default participant
    DefaultParticipant dp(0, "publisher_test");

    // create subscriber
    DDSSubscriber subscriber(idl_msg::MocapMarker_msgPubSubType(), &sub::msg,
                             "test", dp.participant());

    while (true)
    {
        std::cout << "x:\t" << sub::msg.marker_x[2] << std::endl; //"\t y:\t" << sub::msg.marker[0].y << "\t z:\t" << sub::msg.marker[0].z << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}