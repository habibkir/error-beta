cmake_minimum_required(VERSION 3.0.2)
project(handler)

find_package(Boost REQUIRED)
find_package(catkin REQUIRED COMPONENTS
	roscpp
	std_msgs
	# e gli altri package di catkin che stai usando
	# inclusi quelli per messaggi
	)

catkin_package(CATKIN_DEPENDS
	# questi se stai usando i messaggi di ros
	message_runtime
	std_msgs
	# e poi gli altri package di messaggi
	)

include_directories(
	${catkin_INCLUDE_DIRS}
	)

add_executable(${PROJECT_NAME}_node src/handler.cpp)

target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})
