#include <stdio.h>
#include "mex.h"
#include "D:\or hirshfeld\onedrive\work control lab aero summer 2014 technion\C_code\Motive-S-function\NPTrackingTools.h"
// #include "NPTrackingTools.dll"

/* The gateway function */
 void mexFunction(int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
 {
  int ret1,ret2,ret3;

    ret1=TT_Initialize();
    ret2=TT_FinalCleanup();
    ret3=TT_Shutdown();
    
    return;
}
