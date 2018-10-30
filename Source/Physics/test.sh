#!/bin/bash -e

INCDIR=
INCDIR+="-I../../ThirdParty/boost_1_68_0 "
INCDIR+="-I../../ThirdParty/eigen "

echo "Compiling Smoke Test..."
g++ -std=c++11 -ggdb ${INCDIR} -w smoketest_physics.cpp -o a.out
echo "Smoke test passes"

echo "Input validation test..."
g++ -std=c++11 -ggdb ${INCDIR} -w test-inputValidation.cpp -o a.out
echo "Input validation test passes"

./a.out > smoketest.log
rm -f a.out smoketest.log