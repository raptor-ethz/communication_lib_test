#include <iostream>
#include <chrono>
#include <thread>

#include "domain_participant.h"
#include "publisher.h"

#include "MocapSegments_msg.h"
#include "MocapSegments_msgPubSubTypes.h"

namespace pub
{
    cpp_msg::MocapSegments_msg msg;
}

int main(int argc, char *argv[])
{
    // create default participant
    DefaultParticipant dp(0, "publisher_test");

    // create publisher
    DDSPublisher publisher(idl_msg::MocapSegments_msgPubSubType(),
                           "test", dp.participant());

    // define message
    pub::msg.object_name = "test_object";

    pub::msg.segment_x[0] = 1;
    pub::msg.segment_y[0] = 1;
    pub::msg.segment_z[0] = 1;

    pub::msg.segment_x[1] = 2;
    pub::msg.segment_y[1] = 2;
    pub::msg.segment_z[1] = 2;

    pub::msg.segment_x[2] = 3;
    pub::msg.segment_y[2] = 3;
    pub::msg.segment_z[2] = 3;

    while (true)
    {
        publisher.publish(pub::msg);
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}