#!/usr/bin/env bash

GIT_PROJ_ROOT=`git rev-parse --show-toplevel`
${GIT_PROJ_ROOT}/project/victor/scripts/systemctl.sh "$@" start mm-qcamera-daemon
sleep 1
${GIT_PROJ_ROOT}/project/victor/scripts/systemctl.sh "$@" start mm-anki-camera anki-robot.target
