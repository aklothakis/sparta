/* ----------------------------------------------------------------------
   DSMC - Sandia parallel DSMC code
   www.sandia.gov/~sjplimp/dsmc.html
   Steve Plimpton, sjplimp@sandia.gov, Michael Gallis, magalli@sandia.gov
   Sandia National Laboratories

   Copyright (2011) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level DSMC directory.
------------------------------------------------------------------------- */

#include "math.h"
#include "surf_collide_specular.h"
#include "math_extra.h"
#include "error.h"

using namespace DSMC_NS;

/* ---------------------------------------------------------------------- */

SurfCollideSpecular::SurfCollideSpecular(DSMC *dsmc, int narg, char **arg) :
  SurfCollide(dsmc, narg, arg)
{
  if (narg != 2) error->all(FLERR,"Illegal surf_collide specular command");
}

/* ----------------------------------------------------------------------
   particle collision with surface
   p = particle with current x = collision pt, current v = incident v
   norm = surface normal unit vector
   resets p->v to post-collision outward velocity
------------------------------------------------------------------------- */

void SurfCollideSpecular::collide(Particle::OnePart *p, double *norm)
{
  // specular reflection
  // reflect incident v around norm

  MathExtra::reflect3(p->v,norm);
}
