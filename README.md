# ROS2_ZLAC8015D_serial

**ROS2 package for serial communication (RS485) with ZLAC8015D motor driver**
ZLTECH Dual-Channel Servo Driver ZLAC8015D

Driver Info Link: http://www.zlrobotmotor.com/info/401.html

## required packages

- rclcpp
- [serial](https://github.com/wjwwood/serial)

## How to use

```bash
cd <your_workspace>
git clone https://github.com/oxcarxierra/ROS2_ZLAC8015D_serial.git
colcon build --packages-select zlac8015d_serial
ros2 run zlac8015d_serial example
```
