cmake_minimum_required(VERSION 3.0.2)
project(controlError) # OGNI volta che vedi ${PROJECT_NAME} vuol dire questo nome

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)
# altrimento non sa trovare catkin o le parti di ros che ci servono

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)
# questo credo dica a ros che qui c'e' un package
# se non lo metti rosrun non ti caga st'eseguibile, anche se poi esiste come file

include_directories(${catkin_INCLUDE_DIRS})
# per trovare gli header di ros

add_executable(${PROJECT_NAME}_node surs/controlError.cpp) #nodus_nodo_qualcosa
# le path dei file sono viste come relative alla posizione del file CMakeLists.txt
# se sono nella cartella nodus, cerchera' il file nodus/surs/quello.cpp

target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES}) #nodus_nodo_qualcosa
# un target -> un coso da compilare (99.9% delle volte, cmake e' no stronzo)
# qui gli dici che il target <eseguibile di sto nodo> va collegato con le librerie
# di catkin dopo la compilazione



