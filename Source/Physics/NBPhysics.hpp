/**
 * Header only physics code. Currently, the system equations are started from
 * Boost::Numeric::odeint documentation's example, solar_system. Physics equations 
 * will be optimized for speed in later iteration.
 */
#pragma once

#include <vector>

#include <Eigen/Eigen>

#include <boost/numeric/odeint.hpp>

typedef std::vector<Eigen::Vector3d> VectorXs;

struct NBodyCoordinate
{
    NBodyCoordinate() {}
    NBodyCoordinate(const std::vector<double> &m) : _m(m)
    {
    }

    /**
     * The system function for f(p) = -dH/dq. Computes coordinate change from momentum
     * This function is modified directly from ODEINT example solar_system.cpp
     * 
     * @param p The state vector of momentum
     * @param dxdt The output derivative vector. Do not initialize this vector
     */
    void operator()(const VectorXs &p, VectorXs &dqdt) const
    {
        int N = p.size();
        for (int i = 0; i < N; ++i)
        {
            dqdt[i] = p[i] / _m[i];
            // std::cout << "p[" << i << "]: " << p[i].transpose() << std::endl;
            // std::cout << "m[" << i << "]: " << _m[i] << std::endl;
            // std::cout << "dqdt[" << i << "]: " << dqdt[i].transpose() << std::endl;
        }
    }

    const std::vector<double> &getM() const { return _m; }

    void addM(double m) { _m.push_back(m); }

  private:
    std::vector<double> _m;
};

struct NBodyMomentum
{
    NBodyMomentum(double G) : _G(G) {}
    NBodyMomentum(double G, const std::vector<double> &m) : _G(G), _m(m) {}

    /**
     * The system function for g(q) = -dH/dp. Computes momentum change from coordinate
     * This function is modified directly from ODEINT example solar_system.cpp
     */
    void operator()(const VectorXs &q, VectorXs &dpdt) const
    {
        int N = q.size();
        for (int i = 0; i < N; ++i)
        {
            dpdt[i] = Eigen::Vector3d::Zero();
            for (int j = 0; j < i; ++j)
            {
                const auto xi = q[i];
                const auto xj = q[j];
                auto x = xj - xi;
                double d = x.norm();
                auto ddpdt = _G * _m[i] * _m[j] * x / d / d / d;
                dpdt[i] += ddpdt;
                dpdt[j] -= ddpdt;
            }
            // std::cout << "dpdt[" << i << "]: " << dpdt[i].transpose() << std::endl;
        }
    }

    double getG() const { return _G; }

    const std::vector<double> &getM() const { return _m; }

    void addM(double m) { _m.push_back(m); }

  private:
    double _G;
    std::vector<double> _m;
};

class NBodySimulator
{
    typedef boost::numeric::odeint::symplectic_rkn_sb3a_mclachlan<VectorXs> integrator;

  public:
    NBodySimulator(double G) : _system(std::make_pair(
                                   NBodyCoordinate(std::vector<double>()),
                                   NBodyMomentum(G, std::vector<double>())))
    {
    }

    void do_step(double t, double dt)
    {
        _rkn.do_step(_system, qp, t, dt);
    }

    void addPoint(Eigen::Vector3d q, Eigen::Vector3d v, double m)
    {
        // Add coordinate
        qp.first.push_back(q);
        // Add momentum
        qp.second.push_back(v * m);
        // Add mass
        _system.first.addM(m);
        _system.second.addM(m);
    }

    const VectorXs &getQs() const
    {
        return qp.first;
    }
    const VectorXs &getPs() const
    {
        return qp.second;
    }

  private:
    integrator _rkn;
    std::pair<VectorXs, VectorXs> qp;
    std::pair<NBodyCoordinate, NBodyMomentum> _system;
};
