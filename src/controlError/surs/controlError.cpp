#include<iostream>
#include<string> // quella del c++
#include<vector>

#include"ros/ros.h"
#include"std_msgs/String.h" // quella di ros (eh, che vuoi farci?)

int main(int argc, char** argv) {
	ros::init(argc, argv,"control_error");

	// oggetto col quale comunicare col puttanaio sottostante di ros
	ros::NodeHandle node_handle;
	ros::Publisher pub = node_handle.advertise<std_msgs::String>("error_control", 1000);
	ros::Rate rate(10);
	
	std::vector<std::string> errori = {"Auto", "Moto", "Troiola"};

	// adesso mettiamoci a pubblicare roba
	int contatore = 0;
	while(ros::ok()) { //finche' non devo chiudere
		std_msgs::String messaggio; // creiamo il messaggio
		// in c++ puoi usare il + anche per concatenare stringhe
		// vedi "operator overloading", ve vuoi
		std::string str = errori[(contatore%3)];
		contatore++;


		messaggio.data = str; // mettiamo informazioni nel messaggio
		ROS_INFO("%s", messaggio.data.c_str()); // roba
		pub.publish(messaggio); // pubblichiamo il messaggio

		ros::spinOnce();
		rate.sleep();
	}
	return 0;
}










