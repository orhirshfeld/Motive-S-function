#include <stdio.h>
#include "mex.h"
#include "NPTrackingTools.h"

/* The gateway function */
void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    int ret1,ret2,ret3;

    
    ret1=TT_Initialize();
    ret2=TT_FinalCleanup();
    ret3=TT_Shutdown();

    printf("Hello, World! \n");

    return 0;
}

