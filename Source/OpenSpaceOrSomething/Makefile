all: smoketest runsmoke

INCDIR=
INCDIR+=-I../../ThirdParty/odeint/include
INCDIR+=-I../../ThirdParty/eigen

smoketest: smoketest_physics.cpp
	$(CXX) -std=c++11 $(INCDIR) $^ -o $@

.PHONY: runsmoke

runsmoke: smoketest
	./$^ > smoketest.log
