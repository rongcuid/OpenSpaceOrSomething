/**
 * Header only physics code. Currently, the system equations are started from
 * Boost::Numeric::odeint documentation's example, solar_system. Physics equations 
 * will be optimized for speed in later iteration.
 */
#pragma once

#include <vector>

#include <Eigen/Eigen>

typedef std::vector<Eigen::Vector3d> VectorXs;

struct NBodyCoordinate
{
    NBodyCoordinate(const std::vector<double> &m) : _m(m)
    {
    }

    /**
     * The system function for f(p) = -dH/dq. Computes coordinate change from momentum
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
        }
    }

    const std::vector<double> &getM() const { return _m; }

    void addM(double m) { _m.push_back(m); }

  private:
    std::vector<double> _m;
};

struct NBodyMomentum
{
    NBodyMomentum(double G, const std::vector<double> &m) : _G(G), _m(m) {}

    /**
     * The system function for g(q) = -dH/dp. Computes momentum change from coordinate
     */
    void operator()(const VectorXs &q, VectorXs &dpdt) const
    {
        int N = q.size();
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                    const auto xi = q[i];
                    const auto xj = q[j];
                    auto x = xj - xi;
                    double d = x.norm();
                    auto dqdt = _G * _m[i] * _m[j] * x.normalized() / d/d/d;
                    dpdt[i] += dqdt;
                    dpdt[j] -= dqdt;
            }
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
    public:
    NBodySimulator(double G) {
        _system = std::make_pair(
            NBodyCoordinate(std::vector<double>()),
            NBodyMomentum(G, std::vector<double>()));
    }

    void do_step() {

    }

    void addM(double m) {
        _system.first.addM(m);
        _system.second.addM(m);
    }

    private:
    VectorXs p, q;
    std::pair<NBodyCoordinate, NBodyMomentum> _system;
};