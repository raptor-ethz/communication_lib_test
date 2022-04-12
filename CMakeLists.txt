cmake_minimum_required(VERSION 3.16)
project(comm_lib_test VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)


add_subdirectory(lib/communication_lib)

#publisher application:
add_executable(publisher_test
app/publisher_test.cpp
)
target_link_libraries(publisher_test PRIVATE
comm_lib
)

# Third party dependencies
target_link_libraries(publisher_test PRIVATE
fastcdr 
fastrtps
)

#subscriber application
add_executable(subscriber_test
app/subscriber_test.cpp
)
target_link_libraries(subscriber_test PRIVATE
comm_lib
)

# Third party dependencies
target_link_libraries(subscriber_test PRIVATE
fastcdr 
fastrtps
)
