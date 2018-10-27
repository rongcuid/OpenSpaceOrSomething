/**
 * Smoke test to simulate a simple solar system. Physical data is taken from ODEINT example.
 * Everything else is original
 */

#include "NBPhysics.hpp"

#include <boost/numeric/odeint.hpp>
#include <Eigen/Eigen>
#include <iostream>

using namespace boost::numeric::odeint;

int main()
{
    NBodySimulator sim(2.95912208286e-4);
    // Sun
    sim.addPoint(Eigen::Vector3d(0.0, 0.0, 0.0),
                 Eigen::Vector3d(0.0, 0.0, 0.0),
                 1.00000597682);
    // Jupiter
    sim.addPoint(Eigen::Vector3d(-3.5023653, -3.8169847, -1.5507963),
                 Eigen::Vector3d(5.398637520229294e-6, -3.938397200566971e-6, -1.8197172878345132e-6),
                 0.000954786104043);
    // Saturn
    sim.addPoint(Eigen::Vector3d(9.0755314, -3.0458353, -1.6483708),
                 Eigen::Vector3d(4.806888279651002e-7, 1.3808687457183727e-6, 5.496401644970776e-7),
                 0.000285583733151);
    // Uranus
    sim.addPoint(Eigen::Vector3d(8.3101420, -16.2901086, -7.2521278),
                 Eigen::Vector3d(1.548725348725732e-7, 5.995102540558569e-8, 2.4062704971801837e-8),
                 0.0000437273164546);
    // Pluto
    sim.addPoint(Eigen::Vector3d(-15.5387357, -25.2225594, -3.1902382),
                 Eigen::Vector3d(2.1286538461538464e-11, -1.3130923076923078e-11, -1.0500307692307693e-11),
                 7.692307692307693e-09);

    const double dt = 100.0;
    const VectorXs &qs = sim.getQs();

    std::cout << "x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4" << std::endl;
    for (int i = 0; i < qs.size(); ++i)
    {
        std::cout << qs[i](0) << "," << qs[i](1) << "," << qs[i](2);
        if (i != qs.size() - 1)
            std::cout << ",";
    }
    std::cout << std::endl;
    for (double t = 0.0; t < 200000.0; t = t + dt)
    {
        sim.do_step(t, dt);
        for (int i = 0; i < qs.size(); ++i)
        {
            std::cout << qs[i](0) << "," << qs[i](1) << "," << qs[i](2);
            if (i != qs.size() - 1)
                std::cout << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}