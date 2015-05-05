#include <stdio.h>
#include <windows.h> //for sleep function
#include "mex.h"
#include "NPTrackingTools.h"

/* The gateway function */
 void mexFunction(int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
 {
  int ret1=999,ret2=999,ret3=999;
  int index1 = 0;
  int i;
  float x1=999, y1=999, z1=999, qx1=999, qy1=999, qz1=999, qw1=999, yaw1=999, pitch1=999, roll1=999;
  const char project_file_name[130] = "c:\\Users\\sasson\\onedrive\\work control lab aero summer 2014 technion\\C_code\\Motive-S-function\\motive2.ttp";
  double TimeStamp1;
          
	ret1=TT_Initialize();
    mexPrintf("Initialize return code is: %d\n",ret1);
	mexEvalString("drawnow;");
    
	mexPrintf("project_file_name is: %s\n", project_file_name);
	ret2=TT_LoadProject(project_file_name);
	mexPrintf("LoadProject return code is: %d\n", ret2);
    mexEvalString("drawnow;");
    
    Sleep(500); //time in miliseconed
    
    for (i = 0; i < 20; i++)
    {
        ret1=TT_UpdateSingleFrame();
        mexPrintf("Update Single Frame return code is: %d\n",ret1);
        mexEvalString("drawnow;");
        
        TimeStamp1=TT_FrameTimeStamp();
        mexPrintf("Frame Time Stamp is: %f\n", TimeStamp1);
        mexEvalString("drawnow;");
    
        TT_TrackableLocation(index1, &x1, &y1, &z1, &qx1, &qy1, &qz1, &qw1, &yaw1, &pitch1, &roll1);
        mexPrintf("TrackableLocation is: %1.2f %1.2f %1.2f %1.2f %1.2f %1.2f %1.2f %3.1f %3.1f %3.1f\n", x1, y1, z1, qx1, qy1, qz1, qw1, yaw1, pitch1, roll1);
        mexEvalString("drawnow;");
        
        Sleep(1000);
    }
 //   ret2=TT_FinalCleanup();
 //   mexPrintf("%d\n",ret2);
    
    ret3=TT_Shutdown();
    mexPrintf("Shutdown return code is: %d\n",ret3);
    mexEvalString("drawnow;");
    
    return;
}
