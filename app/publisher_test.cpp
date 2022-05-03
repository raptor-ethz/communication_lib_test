#include <iostream>
#include <chrono>
#include <thread>

#include "domain_participant.h"
#include "publisher.h"

#include "MocapMarker_msg.h"
#include "MocapMarker_msgPubSubTypes.h"

namespace pub
{
    cpp_msg::MocapMarker_msg msg;
}

int main(int argc, char *argv[])
{
    // create default participant
    DefaultParticipant dp(0, "publisher_test");

    // create publisher
    DDSPublisher publisher(idl_msg::MocapMarker_msgPubSubType(),
                           "mocap_markers_srl_obstacle", dp.participant());

    // define message
    pub::msg.object_name = "obstacle1";

    // under layer
    pub::msg.marker_x[0] = 1;
    pub::msg.marker_y[0] = 0;
    pub::msg.marker_z[0] = 0;

    pub::msg.marker_x[1] = 2;
    pub::msg.marker_y[1] = 0;
    pub::msg.marker_z[1] = 0;

    pub::msg.marker_x[2] = 1;
    pub::msg.marker_y[2] = 2;
    pub::msg.marker_z[2] = 0;

    pub::msg.marker_x[3] = 2;
    pub::msg.marker_y[3] = 2;
    pub::msg.marker_z[3] = 0;

    // upper layer
    pub::msg.marker_x[4] = 1;
    pub::msg.marker_y[4] = 0;
    pub::msg.marker_z[4] = 2;

    pub::msg.marker_x[5] = 2;
    pub::msg.marker_y[5] = 0;
    pub::msg.marker_z[5] = 2;

    pub::msg.marker_x[6] = 1;
    pub::msg.marker_y[6] = 2;
    pub::msg.marker_z[6] = 2;

    pub::msg.marker_x[7] = 2;
    pub::msg.marker_y[7] = 2;
    pub::msg.marker_z[7] = 2;

    pub::msg.length = 8;

    while (true)
    {
        publisher.publish(pub::msg);
        std::cout << "publishing" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}