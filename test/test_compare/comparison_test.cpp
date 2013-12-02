//
int main(int argc, char **argv) {

   auto_diff<double,4> q[4],f[4];
   auto_diff<double,4> cs, ubar, u, v, p;
   double nx = 0.25,ny = 0.75,gam = 1.4,l = 1.0;

   q[0].set_val(1.0);
   q[1].set_val(1.25);
   q[2].set_val(0.0);
   q[3].set_val(1.75);

   for(int i = 0; i < 1000000; i++) {
      q[0].set_deriv(0,1.0);
      q[1].set_deriv(1,1.0);
      q[2].set_deriv(2,1.0);
      q[3].set_deriv(3,1.0);
      ubar = nx*q[1]/q[0]+ny*q[2]/q[0];
      u = q[1]/q[0];
      v = q[2]/q[0];
      
      p = (gam - 1.0)*(q[3] - .5*(q[1]*q[1] + q[2]*q[2])/q[0]);

      cs = pow((gam*p)/q[0],.5)+pow((gam*p)/q[0],.5);

      f[0] = l*0.25*q[0]*cs*(ubar/cs+1.0)*(ubar/cs+1.0);
      f[1] = f[0]*((nx/gam)*(-1.0*ubar)+(nx/gam)*(2.0*cs)+u);
      f[2] = f[0]*((ny/gam)*(-1.0*ubar)+(ny/gam)*(2.0*cs)+v);
      f[3] = f[0]*((-(gam-1.0)*ubar*ubar+2.0*(gam-1.0)*ubar*cs+2.0*cs*cs)
            /(gam*gam-1.0)+0.5*(u*u)+0.5*(v*v));



   }
   for(int j=0; j <= 3; j++) {
      cout << "j   " << f[j].Value() << endl;
      for(int k=0; k <= 3; k++)
         cout << "j,k   " << f[j].Deriv(k) << endl;
   }

   return 0;
}
