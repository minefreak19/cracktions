#!/bin/env bash

set -xe

CXXFLAGS="-ggdb -Wall -Werror -std=c++11"

SRC="src/main.cpp src/fraction.cpp"

c++ $CXXFLAGS -o ./cracktions $SRC
