#!/bin/bash

BASENAME='./static/photos'

TS=$BASENAME/$1
ffmpeg -f v4l2 -s 640x480 -i /dev/video0 -vframes 1 $TS
