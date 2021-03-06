/* ----------------------------------------------------------------------
LIGGGHTS - LAMMPS Improved for General Granular and Granular Heat
Transfer Simulations

www.liggghts.com | www.cfdem.com
Christoph Kloss, christoph.kloss@cfdem.com

LIGGGHTS is based on LAMMPS
LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
http://lammps.sandia.gov, Sandia National Laboratories
Steve Plimpton, sjplimp@sandia.gov

Copyright (2003) Sandia Corporation. Under the terms of Contract
DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
certain rights in this software. This software is distributed under
the GNU General Public License.

See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef FIX_CLASS

FixStyle(couple/cfd/convection,FixCfdCouplingConvection)

#else

#ifndef LMP_FIX_CFD_COUPLING_CONVECTION_H
#define LMP_FIX_CFD_COUPLING_CONVECTION_H

#include "fix_cfd_coupling.h"

namespace LAMMPS_NS {

class FixCfdCouplingConvection : public FixCfdCoupling {
 public:
  FixCfdCouplingConvection(class LAMMPS *, int, char **);
  ~FixCfdCouplingConvection();
  void pre_delete();
  virtual int setmask();
  virtual void init_submodel();
  virtual void post_force(int);

 protected:
  virtual void special_settings();

  class FixPropertyAtom* fix_convectiveFlux;
  class FixPropertyAtom* fix_heatFlux;
  double T0;
};

}

#endif
#endif
