#!/bin/bash

start=$( date +%s )


while : ; do


  elapsed=$((  $( date +%s )  - $start ));

  # echo $elapsed
  printf "$( date -d@${elapsed} -u +%H:%M:%S)\r"

  sleep 1
done
