all: smoketest runsmoke

INCDIR=
INCDIR+=-I../../ThirdParty/odeint/include
INCDIR+=-I../../ThirdParty/eigen

smoketest: smoketest_physics.cpp 
	$(CXX) -std=c++11 -ggdb $(INCDIR) $^ -o $@

.PHONY: runsmoke clean

runsmoke: smoketest
	./$^ > smoketest.log

clean:
	rm -f smoketest smoketest.log