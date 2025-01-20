#!/bin/bash

# Builds on Ubuntu and MacOS

# Usage:
# ./build.sh
# ./build.sh ~/esp CMAKEARG1 CMAKEARG2 ...
# . ./build.sh  # Now idf.py will be available in the terminal

path_location=$1
passed_args=("$@")

build_args=""
if [ -z "${path_location}" ]; then
    path_location=~/esp
else
    for ((i=1; i<"${#}"; i++));
    do
      build_args="${build_args} -D${passed_args[i]}"
    done
    echo "Build arguments: ${build_args}"
fi
echo "Building the toolchain in: $path_location"

folder_path_exists=false
check_folder_path_exists () {
    if [ -d $1 ]; then
        folder_path_exists=true
    else
        folder_path_exists=false
    fi
}

recursive_clone_espidf () {
    git clone -b v5.4 --recursive https://github.com/espressif/esp-idf.git $path_location/esp-idf
}

check_folder_path_exists $path_location
if [ $folder_path_exists==false ]; then
    mkdir $path_location
fi

check_folder_path_exists $path_location/esp-idf
if [ $folder_path_exists==false ]; then
    recursive_clone_espidf
fi

if [ ! $path_to_location/esp-idf/install.sh ]; then
    rm -rf $path_to_location/esp-idf
    recursive_clonse_espidf
fi

bash $path_location/esp-idf/install.sh
. $path_location/esp-idf/export.sh

idf.py fullclean

idf.py build ${build_args}
