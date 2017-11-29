#include<iostream>
#include<vector>

#include"physics.hpp"
#include"aux/math.hpp"

#define DT 1e-6
#define TMAX 21

/*
 * Simulação de sistema fictício de 3-corpos, teste de estabilidade
 * dos pontos de Lagrange
 */

int main(){
   Physics::pWorld world;
   Physics::pForceGen* gravityFGs[11];
   std::vector<unsigned> pIdx;

   // Particles data
   real a = 1e2;
   real m[7] = {1e12,1e10,a,a,a,a,a};
   Vector3 p[7] = {
      Vector3(0,0,0),Vector3(1e6,0,0),
      Vector3(8.511148e5,0,0)/*L1*/,Vector3(1.148885e6,0,0)/*L2*/,
      Vector3(-1.004215e6,0,0)/*L3*/,Vector3(4.90099e5,8.660254e5,0)/*L4*/,
      Vector3(4.90099e5,-8.660254e5,0)/*L5*/};
   Vector3 v[7] = {
      Vector3(0,0,0),Vector3(0,1e6,0),
      Vector3(0,1.083942e6,0)/*L1*/,Vector3(0,9.329572e5,0)/*L2*/,
      Vector3(0,-9.978991e5,0)/*L3*/,Vector3(-8.68161e5,5.01233e5,0)/*L4*/,
      Vector3(8.68161e5,5.01233e5,0)/*L5*/};

      /*Vector3(-8.660254e5,5e5,0)//L4,
      Vector3(8.660254e5,5e5,0)//L5};*/

   for(int i=0; i<7; i++){
      pIdx.push_back(world.particles->newParticle());
      (*world.particles)[pIdx[i]].setPos(p[i]);
      (*world.particles)[pIdx[i]].setVel(v[i]);
      (*world.particles)[pIdx[i]].setMass(m[i]);
   }

   gravityFGs[0] = new Physics::fgGravity(pIdx[0], pIdx[1], 1e6);
   world.forceGens->add(gravityFGs[0]);
   for(int i=1;i<6;i++){
      gravityFGs[i] = new Physics::fgGravity(pIdx[0], pIdx[i+1], 1e6);
      gravityFGs[i+5] = new Physics::fgGravity(pIdx[1], pIdx[i+1], 1e6);
      world.forceGens->add(gravityFGs[i]);
      world.forceGens->add(gravityFGs[i+5]);
   }

   double t = 0.0;
   Vector3 cm = Vector3::Zero();
   Vector3 tmp = Vector3::Zero();

   while(t < TMAX){
      cm = (1/(1e12+1e10))*(1e12*(*world.particles)[pIdx[0]].getPos()
           +1e10*(*world.particles)[pIdx[1]].getPos());

      for(int i=0;i<7;i++){
         tmp = (*world.particles)[pIdx[i]].getPos()-cm;
         std::cout<<tmp[0]<<" "<<tmp[1]<<"  ";
      }

      std::cout<<std::endl;

      world.runPhysics(DT);
      t += DT;
   }

//   for(int i=0;i<11;i++)
//      delete gravityFGs[i];

   return 0;
}
