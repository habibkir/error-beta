#include<fstream>

#include"ros/ros.h"
#include"std_msgs/String.h"

time_t tempus = time(NULL);
std::ofstream os;

class Logger {
public:
	static void init(std::string filename) {
		os = std::ofstream(filename);
	}
	static void log(std::string s, std::string nodo) {
		os << "Nodo : " << nodo << " Errore : " <<
		s << " Tempo : " << ctime(&tempus);
	}
private:
};

void error_slam_call(const std_msgs::String::ConstPtr& msg) {
	std::string s = msg->data;
	if(s == "Track Lost") {
		std::cout<<"Fermati, cieco di merda!\n";
		Logger::log("Track Lost", "Slam");
	}

	else if(s == "Tracker Loster") {
		std::cout<<"Mr.Simpatia portami via\n";
		Logger::log("Tracker Loster", "Slam");
	}

	if(s == "Waluigi") {
		std::cout<<"Everybody's cheating but me, WAAAAH\n";
		Logger::log("WAAAAAAAH", "Slam");
	}

	if(s == "Track Lost 2, Electric Boogaloo") {
		std::cout<<"Lo vuoi un palloncino da un pedofilo?\n";
	}

	else {
		std::cout<<"Non so che fare in questa situazione\n";
	}
	ROS_INFO("Sto reagendo a errore 1 $<%s>",msg->data.c_str());
}

void error_control_call(const std_msgs::String::ConstPtr& msg) {
	std::cout<<"Mi hanno detto che "<< msg->data <<" mi spiace, vatti a fottere\n";

	ROS_INFO("Sto reagendo a errore 2 $<%s>",msg->data.c_str());
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "handler");
	Logger::init("sto.cazzo");

	ros::NodeHandle node_handle;
	ros::Subscriber sub_slam = node_handle.subscribe("error_slam",1000,error_slam_call);
	ros::Subscriber sub_control = node_handle.subscribe("error_control",1000,error_control_call);

	ros::spin();
	return 0;
}
