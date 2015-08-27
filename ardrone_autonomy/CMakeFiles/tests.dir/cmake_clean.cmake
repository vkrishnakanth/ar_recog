FILE(REMOVE_RECURSE
  "msg_gen"
  "srv_gen"
  "src/ardrone_autonomy/msg"
  "src/ardrone_autonomy/srv"
  "msg_gen"
  "srv_gen"
  "CMakeFiles/tests"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/tests.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
