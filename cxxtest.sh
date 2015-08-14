#!/bin/bash
# cxxtest script
./cxxtest-4.3/bin/cxxtestgen --error-printer -o ./cxxtest-4.3/bin/runner.cpp ./tests/*
perl -pi -w -e 's/<cxxtest\//</g;' ./cxxtest-4.3/bin/runner.cpp
rm ./cxxtest-4.3/bin/runner
g++ -std=c++11 -stdlib=libc++ -o ./cxxtest-4.3/bin/runner  -I ./cxxtest-4.3/cxxtest/ -I ./src/ ./cxxtest-4.3/bin/runner.cpp
./cxxtest-4.3/bin/runner