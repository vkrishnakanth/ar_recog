FILE(REMOVE_RECURSE
  "msg_gen"
  "srv_gen"
  "src/ardrone_autonomy/msg"
  "src/ardrone_autonomy/srv"
  "msg_gen"
  "srv_gen"
  "CMakeFiles/ROSBUILD_gensrv_cpp"
  "srv_gen/cpp/include/ardrone_autonomy/RecordEnable.h"
  "srv_gen/cpp/include/ardrone_autonomy/FlightAnim.h"
  "srv_gen/cpp/include/ardrone_autonomy/LedAnim.h"
  "srv_gen/cpp/include/ardrone_autonomy/CamSelect.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
