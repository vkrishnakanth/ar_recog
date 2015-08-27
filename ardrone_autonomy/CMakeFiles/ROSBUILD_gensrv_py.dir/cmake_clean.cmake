FILE(REMOVE_RECURSE
  "msg_gen"
  "srv_gen"
  "src/ardrone_autonomy/msg"
  "src/ardrone_autonomy/srv"
  "msg_gen"
  "srv_gen"
  "CMakeFiles/ROSBUILD_gensrv_py"
  "src/ardrone_autonomy/srv/__init__.py"
  "src/ardrone_autonomy/srv/_RecordEnable.py"
  "src/ardrone_autonomy/srv/_FlightAnim.py"
  "src/ardrone_autonomy/srv/_LedAnim.py"
  "src/ardrone_autonomy/srv/_CamSelect.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
