#!/bin/sh


if [ $# -eq 0 ] ; then
    /bin/echo "Entering build environment at /home/rosdev/fuerte_workspace/sandbox/ardrone_autonomy"
    . /home/rosdev/fuerte_workspace/sandbox/ardrone_autonomy/setup.sh
    $SHELL -i
    /bin/echo "Exiting build environment at /home/rosdev/fuerte_workspace/sandbox/ardrone_autonomy"
else
    . /home/rosdev/fuerte_workspace/sandbox/ardrone_autonomy/setup.sh
    exec "$@"
fi


