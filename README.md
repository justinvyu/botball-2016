# Botball 2016 Regionals - Team 16-0323

This is what we'll be using for hosting code from the 2016 regional season.

# IMPORTANT CONTROLLER SHUTDOWN!

> THE BATTERY WILL BE DESTROYED IF YOU DON'T DO THIS EVERY TIME! I KNOW BECAUSE I BROKE ONE...

1. Click the `Shut Down` button on the controller.
2. Wait until the terminal outputs `system halted` or something like that.
3. Switch the controller to off using a toothpick/pointy object.
4. Disconnect the battery (optional).

## IDE Quickstart

Click [this](http://homebase.kipr.org/2014/mod/resource/view.php?id=885) for KIPR's workshop slides that has information on the new controller/IDE.

1. Turn on the controller.
2. Connect your computer to the controller via micro-USB.
3. Open a web browser and go here: `192.168.124.1:8888`
4. Create a project OR edit an existing project.
   - Since you are directly connected, you can view all the existing projects on the controller.
5. `Compile` your project when you're ready.
6. Click on the `Runner` to direct yourself to the console output.
7. `Run` your project either on your computer or manually on the robot.

> For step 2, you could also use the ethernet connection created by the
> controller, but I haven't had success with that method. Another downside to
> connecting to the controller's network is that you cannot access the internet.

## Libraries

Go [here](https://github.com/justinvyu/botball) for our libraries. Check back often
because they will be modified/optimized throughout the season.

## Official KIPR "Docs"

Look at their [official Github repository](https://github.com/kipr/libwallaby) for all the source code.

> Learn how to read these!

- [Create Commands](https://github.com/kipr/libwallaby/blob/master/src/create_c.cpp)
- [Motor Commands](https://github.com/kipr/libwallaby/blob/master/src/motors_c.cpp)
- [DIGITAL Sensor Commands](https://github.com/kipr/libwallaby/blob/master/src/digital_c.cpp)
- [ANALOG Sensor Commands](https://github.com/kipr/libwallaby/blob/master/src/analog_c.cpp)
- [Camera Commands](https://github.com/kipr/libwallaby/blob/master/src/camera_c.cpp)
- [Servo Commands](https://github.com/kipr/libwallaby/blob/master/src/servo_c.cpp)
