cmake_minimum_required(VERSION 3.16)
project(comm_lib_test VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)


#add_subdirectory(lib)

#publisher application:
add_executable(publisher
app/publisher.cpp
)

#subscriber application:
add_executable(subscriber
app/subscriber.cpp
)


# target_link_libraries(comm_lib_test PRIVATE
# comm_lib
# )

# Third party dependencies
# target_link_libraries(mocap_publisher PRIVATE
# ViconDataStreamSDK_lib
# fastcdr 
# fastrtps
# )
