#!/bin/sh
# This file is generated by catkin. 

export PYTHONPATH=/home/rosdev/fuerte_workspace/sandbox/ardrone_autonomy/gen/py:$PYTHONPATH
export PATH=/home/rosdev/fuerte_workspace/sandbox/ardrone_autonomy/bin:/bin:$PATH
export CATKIN_BINARY_DIR=/home/rosdev/fuerte_workspace/sandbox/ardrone_autonomy
export CATKIN_SOURCE_DIR=/home/rosdev/fuerte_workspace/sandbox/ardrone_autonomy
if [ -z "$CATKIN_SHELL" ] ; then
   CATKIN_SHELL=sh
fi

FIND=`which find`
SORT=`which sort`
for envfile in `$FIND $CATKIN_BINARY_DIR/etc/catkin/profile.d -maxdepth 1 -name "*.all" 2>/dev/null | $SORT` `$FIND $CATKIN_BINARY_DIR/etc/catkin/profile.d -maxdepth 1 -name "*.$CATKIN_SHELL" 2>/dev/null | $SORT`
do
  . $envfile
done
