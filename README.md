# RostopicMultithread
# 基于ROS多线程订阅多个话题并且发布话题
# Function：订阅2个传感器数据话题并且发布一个话题
# 使用的是ROS多线程以及c++中的面向对象
# 使用
发布者1：rosrun RostopicMultithread person_publisher
发布者2：rosrun RostopicMultithread velocity_publisher
订阅者并发布：rosrun RostopicMultithread person_subscriber
# ROS kineic 
