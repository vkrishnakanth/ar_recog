FILE(REMOVE_RECURSE
  "msg_gen"
  "srv_gen"
  "src/ardrone_autonomy/msg"
  "src/ardrone_autonomy/srv"
  "msg_gen"
  "srv_gen"
  "CMakeFiles/ROSBUILD_gensrv_lisp"
  "srv_gen/lisp/RecordEnable.lisp"
  "srv_gen/lisp/_package.lisp"
  "srv_gen/lisp/_package_RecordEnable.lisp"
  "srv_gen/lisp/FlightAnim.lisp"
  "srv_gen/lisp/_package.lisp"
  "srv_gen/lisp/_package_FlightAnim.lisp"
  "srv_gen/lisp/LedAnim.lisp"
  "srv_gen/lisp/_package.lisp"
  "srv_gen/lisp/_package_LedAnim.lisp"
  "srv_gen/lisp/CamSelect.lisp"
  "srv_gen/lisp/_package.lisp"
  "srv_gen/lisp/_package_CamSelect.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
