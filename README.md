# Autonomous-Maze-Solving-Robot
 
## Final Result
This is a live demonstration of the robot autonomously solving a maze

https://github.com/user-attachments/assets/cce7acbe-6295-4bbc-9338-e9e4782c1c5e

## Project Overview
This project involves an autonomous robot designed to navigate and solve a maze. Built over two weeks in a team of 5, the robot incorporates a range of hardware and software components that work together to detect walls, make decisions, and traverse a maze efficiently. The project showcases an application of embedded systems, hardware interfacing, and algorithmic problem-solving.

## Components and Functionality
### 1. **Front Sensor System**
- **Type**: Infrared sensor
- **Purpose**: Detects the presence of walls in front of the robot.
- **Description**: The sensor sends signals to the Arduino microcontroller, which determines whether the path ahead is blocked or clear.

### 2. **Motor Control Circuit**
- **Type**: H-Bridge circuit
- **Purpose**: Powers the robot's motors and enables movement in all directions.
- **Functionality**: The circuit allows the robot to move forward, backwards, and turn left or right, enabling it to navigate through the maze.

### 3. **Side Wall Detection**
- **Type**: Push buttons located on the left and right sides
- **Purpose**: Detects side walls by signalling the Arduino when pressed.
- **Description**: These buttons act as collision sensors, providing input when the robot comes into contact with a side wall.

### 4. **Arduino Control Code**
- **Role**: The "brain" of the robot.
- **Functionality**: Processes data from the sensors and controls the motors based on the maze-solving logic.
- **Features**: Takes inputs from the front sensor and side buttons and executes the logic to decide the robot's next move.


## Project Insights
This project was a practical and engaging experience that emphasized:
- **Rapid Learning and Adaptation**: Implementing the push button and motor circuits, along with programming the Arduino, required quick learning and problem-solving.
- **Team Collaboration**: Successfully managing different components of the robot, such as designing the circuits and writing the control logic.
- **Algorithm Development**: Creating an efficient navigation algorithm to guide the robot through the maze.

## Repository Contents
- **Arduino Code**: Contains the full code used to control the robot.
- **Project Report**: Detailed documentation explaining the design, components, and problem-solving process.

## How to Run the Project
1. **Connect the Components**: Assemble the hardware as per the circuit diagrams provided in the report.
2. **Upload the Code**: Use the Arduino IDE to upload the control code to the Arduino board.
3. **Test the Robot**: Place the robot in a maze and observe as it navigates through obstacles using its sensors and programmed logic.
