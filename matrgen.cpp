#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <vcl.h>
#include "matrgen.h"
#pragma hdrstop

int det0 (const matrix& m, int sz)
{
	if (sz==2) return m.e[0][0]*m.e[1][1]-m.e[0][1]*m.e[1][0];
    matrix q;
    int a,x,y,x1,e=-1,r=0;
    for(int i=0; i<sz; ++i)
    {
     	e=-e;
     	for(y=1; y<sz; ++y)
        	for(x=0,x1=0; x<sz; ++x)
            	if (x!=i) q.e[y-1][x1++]=m.e[y][x];
        a=e*m.e[0][i]*det0(q,sz-1);
        r=r+a;
    }
    return r;
} int det (const matrix& m, int size) { return det0(m, size); }

bool generate(matrix& cur, int size, int wantedcount)
{
    int tries=0;
    int used[range*2+1];
  	int k,maxd,mind,i,j, empty=range+100;
    elements& m = &cur.e;
    eigenvalues& ev = &cur.eigenv;
    int &evc = cur.eigenc;
    bool found=false;

	do {
        tries++;
    	for(int i=0; i<2*range+1; ++i) used[i]=0;
		for(i=0; i<size; ++i)
    		for(j=0; j<size; ++j)
        	{
          		do k=random(2*range+1)-range; while (used[k+range]>eqk-1);
	            ++used[k+range];
    	        m[i][j]=k;
        	}

	    for(maxd=m[0][0],mind=m[0][0],i=1; i<size; ++i)
    	{
	        if (mind>m[i][i]) mind=m[i][i];
    	    if (maxd<m[i][i]) maxd=m[i][i];
	    }
	    k = empty;
        evc = 0;
  		for(i=-(range-(-mind)); i<=range-maxd; i++)
	    {
			for(j=0; j<size; ++j) m[j][j]+=i;
        	if (det(cur,size)==0)
                ev[evc++]=-i;
	        else
                if ((random(100)<40)||(k==empty)) k=i;
    		for(j=0; j<size; ++j)
                m[j][j]-=i;
	    }

    	if (k!=empty)
	    {
    	  	for(i=0; i<size; ++i) m[i][i]+=k;
        	for(i=0; i<evc; ++i) ev[i]-=(-k);

	        found = false;
    	    if (evc==size && wantedcount==evc)
                found = true;
            else
    	    {
        		if (size==3)
            	{
	    	        int freememb=m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]) - m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0]) + m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
    	    	    if (evc==2 && wantedcount==evc)
        	    	{
            	    	if ((freememb==ev[0]*ev[1]*ev[1])||(freememb==ev[0]*ev[0]*ev[1]))
	            	    {
    	            	    found = true;
        	            	if (freememb==ev[0]*ev[1]*ev[1])
	            	        {
    	            	        ev[2] = ev[1];
        	            	    evc = 3;
	        	            }
    	        	        else
        	        	    {
            	        	    ev[2] = ev[1];
                	        	ev[1] = ev[0];
	                    	    evc = 3;
		                    }
    		            }
	        	    }
	            	if (evc==1  && wantedcount==evc)
		            {
                        int m2 = ( m[0][0]
                                  +m[1][1]
                                  +m[2][2]);
                        int m3 = ( m[0][0]*m[1][1]
                                  +m[0][0]*m[2][2]
                                  +m[1][1]*m[2][2]
                                  -m[1][2]*m[2][1]
                                  -m[1][0]*m[2][1]
                                  -m[2][0]*m[0][2]);
                        int m4 = freememb;
                               /*( m[0][0]*m[1][1]*m[2][2]
                                  -m[0][0]*m[1][2]*m[2][1]
                                  -m[1][0]*m[0][1]*m[2][2]
                                  +m[1][0]*m[0][2]*m[2][1]
                                  +m[2][0]*m[0][1]*m[1][2]
                                  -m[2][0]*m[0][2]*m[1][1]);*/
                        int a = -ev[0];
                        int v2 = -3*a;
                        int v3 = 3*a*a;
                        int v4 = -a*a*a;

    		            if (m2==v2 && m3==v3 && m4==v4)
        		        {
            		        found = true;
                		    ev[2] = ev[1] = ev[0];
	                    	evc = 3;
	    	            }
    	    	    }
            	}
                else if (size==2)
                {
                    if (evc==1 && wantedcount==evc) {
                        int m2 = -(m[0][0]+m[1][1]);
                        int m3 = (m[0][0]*m[1][1]-m[0][1]*m[1][0]);
                        int a = ev[0];
                        int v2 = -2*a;
                        int v3 = a*a;
                        if (m2==v2 && m3==v3)
                        {
                            found = true;
                            ev[1] = ev[0];
                            evc = 2;
                        }
                    }
                } // else if (size==2)
	        } // else evc==size
    	} // k!=empty
        if (tries==manytries && !found)
            return false;
    } while (!found);
    return true;
}


