FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/cvg_sim_msgs/msg"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/cvg_sim_msgs/msg/__init__.py"
  "../src/cvg_sim_msgs/msg/_Compass.py"
  "../src/cvg_sim_msgs/msg/_RawImu.py"
  "../src/cvg_sim_msgs/msg/_MotorPWM.py"
  "../src/cvg_sim_msgs/msg/_MotorStatus.py"
  "../src/cvg_sim_msgs/msg/_Supply.py"
  "../src/cvg_sim_msgs/msg/_PositionXYCommand.py"
  "../src/cvg_sim_msgs/msg/_AttitudeCommand.py"
  "../src/cvg_sim_msgs/msg/_HeightCommand.py"
  "../src/cvg_sim_msgs/msg/_YawrateCommand.py"
  "../src/cvg_sim_msgs/msg/_MotorCommand.py"
  "../src/cvg_sim_msgs/msg/_RuddersCommand.py"
  "../src/cvg_sim_msgs/msg/_RawRC.py"
  "../src/cvg_sim_msgs/msg/_VelocityXYCommand.py"
  "../src/cvg_sim_msgs/msg/_VelocityZCommand.py"
  "../src/cvg_sim_msgs/msg/_ThrustCommand.py"
  "../src/cvg_sim_msgs/msg/_ControllerState.py"
  "../src/cvg_sim_msgs/msg/_RC.py"
  "../src/cvg_sim_msgs/msg/_RawMagnetic.py"
  "../src/cvg_sim_msgs/msg/_Altitude.py"
  "../src/cvg_sim_msgs/msg/_ServoCommand.py"
  "../src/cvg_sim_msgs/msg/_HeadingCommand.py"
  "../src/cvg_sim_msgs/msg/_Altimeter.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
