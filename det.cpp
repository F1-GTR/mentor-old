#include <math.h>
//------------------------------------------------------------------------------
int determ( int dim, int ma[][10])
{
        int i, j, k, l, det, mb[10][10];

        if ( dim == 1 )
                return ma[0][0];
        if( dim > 1 )
        {
                det = 0;

                for( i = 0; i < dim; i ++ )
                {
                        l = 0;

                        for( j = 1; j < dim; j ++ )
                        {
                                for( k = 0; k < dim; k ++ )
                                {
                                        if ( k != i )
                                                mb[j][ l ++ ] = ma[j][k];
                                        else
                                                continue;
                                }

                                l = 0;
                        }

                        det += pow( -1, i ) * ma[0][i] * determ( dim - 1, mb );
                }
                return det;
        }
}
//------------------------------------------------------------------------------

