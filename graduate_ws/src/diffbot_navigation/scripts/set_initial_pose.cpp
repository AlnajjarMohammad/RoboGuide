#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "set_initial_pose");
    ros::NodeHandle nh;

    ros::Publisher initial_pose_pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 10);

    geometry_msgs::PoseWithCovarianceStamped initial_pose;
    initial_pose.header.stamp = ros::Time::now();
    initial_pose.header.frame_id = "map"; // or the fixed frame you are using in RViz

    // Set the initial position
    initial_pose.pose.pose.position.x = 15.551586151123047;
    initial_pose.pose.pose.position.y = -0.12244653701782227;
    initial_pose.pose.pose.position.z = 0.0;

    // Set the initial orientation (quaternion)
    initial_pose.pose.pose.orientation.x = 0.0;
    initial_pose.pose.pose.orientation.y = 0.0;
    initial_pose.pose.pose.orientation.z = 1.6454343795776367;
    initial_pose.pose.pose.orientation.w = 1.0;

    // Covariance matrix, assuming high certainty in initial pose
    for (int i = 0; i < 36; ++i) {
        initial_pose.pose.covariance[i] = 0.0;
    }

    ros::Rate rate(10); // 10 Hz
    for (int i = 0; i < 10; ++i) {
        initial_pose.header.stamp = ros::Time::now();
        initial_pose_pub.publish(initial_pose);
        rate.sleep();
    }

    return 0;
}

