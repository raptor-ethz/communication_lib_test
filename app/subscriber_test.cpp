#include <iostream>
#include <chrono>
#include <thread>

#include "domain_participant.h"
#include "subscriber.h"

#include "MocapSegments_msg.h"
#include "MocapSegments_msgPubSubTypes.h"

namespace sub
{
    cpp_msg::MocapSegments_msg msg;
}

int main(int argc, char *argv[])
{
    // create default participant
    DefaultParticipant dp(0, "publisher_test");

    // create subscriber
    DDSSubscriber subscriber(idl_msg::MocapSegments_msgPubSubType(), &sub::msg,
                             "test", dp.participant());

    while (true)
    {
        std::cout << "x:\t" << sub::msg.segment_x[2] << std::endl; //"\t y:\t" << sub::msg.segment[0].y << "\t z:\t" << sub::msg.segment[0].z << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}