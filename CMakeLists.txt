
cmake_minimum_required(VERSION 2.8)

project (test)

# Boost dependency
set(BOOST_ROOT CACHE PATH "Path to Boost library")
find_package(Boost REQUIRED system serialization)

include_directories(${Boost_INCLUDE_DIR})
aux_source_directory (./  SRC)


add_executable(test ${SRC})
target_link_libraries(test ${Boost_LIBRARIES})
