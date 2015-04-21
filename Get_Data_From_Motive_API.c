/*
 * File : timestwo.c
 * Abstract:
 *       An example C-file S-function for multiplying an input by 2,
 *       y  = 2*u
 *
 * Real-Time Workshop note:
 *   This file can be used as is (noninlined) with the Real-Time Workshop
 *   C rapid prototyping targets, or it can be inlined using the Target 
 *   Language Compiler technology and used with any target. See 
 *     matlabroot/toolbox/simulink/blocks/tlc_c/timestwo.tlc   
 *   the TLC code to inline the S-function.
 *
 * Copyright 1990-2013 The MathWorks, Inc.
 */


#define S_FUNCTION_NAME  Get_Data_From_Motive_API
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
#include "NPTrackingTools.h"
//#include <stdio.h>
#include "mex.h"

/*================*
 * Build checking *
 *================*/


/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }

    if (!ssSetNumInputPorts(S, 1)) return;
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDataType(S, 0, DYNAMICALLY_TYPED );
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S,7)) return;
    
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortDataType(S, 0, SS_SINGLE );
    
    ssSetOutputPortWidth(S, 1, 1);
    ssSetOutputPortDataType(S, 1, SS_SINGLE );
    
    ssSetOutputPortWidth(S, 2, 1);
    ssSetOutputPortDataType(S, 2, SS_SINGLE );
    
    ssSetOutputPortWidth(S, 3, 1);
    ssSetOutputPortDataType(S, 3, SS_SINGLE );
    
    ssSetOutputPortWidth(S, 4, 1);
    ssSetOutputPortDataType(S, 4, SS_SINGLE );
    
    ssSetOutputPortWidth(S, 5, 1);
    ssSetOutputPortDataType(S, 5, SS_SINGLE );
    
    ssSetOutputPortWidth(S, 6, 1);
    ssSetOutputPortDataType(S, 6, SS_SINGLE );
    
    
    ssSetNumSampleTimes(S, 1);

    /* specify the sim state compliance to be same as a built-in block */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

    ssSetOptions(S,
                 SS_OPTION_WORKS_WITH_CODE_REUSE |
                 SS_OPTION_EXCEPTION_FREE_CODE |
                 SS_OPTION_USE_TLC_WITH_ACCELERATOR);
}


/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy that we inherit our sample time from the driving block.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
    ssSetModelReferenceSampleTimeDefaultInheritance(S); 
}



#define MDL_START
void mdlStart(SimStruct *S)
{
    int_T ret1;
    int_T ret2;
    char project_file_name[86]="D:\\or hirshfeld\\onedrive\\work control lab aero summer 2014 technion\\C_code\\motive.ttp";
    
            
    ret1=TT_Initialize();
    ret2=TT_LoadProject(project_file_name);
    
}


/* Function: mdlOutputs =======================================================
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,0);
    real_T            *X    = ssGetOutputPortRealSignal(S,0);
    real_T            *Y    = ssGetOutputPortRealSignal(S,1);
    real_T            *Z    = ssGetOutputPortRealSignal(S,2);
    real_T            *Yaw    = ssGetOutputPortRealSignal(S,3);
    real_T            *Pitch    = ssGetOutputPortRealSignal(S,4);
    real_T            *Roll    = ssGetOutputPortRealSignal(S,5);
    real_T           *TimeStamp    = ssGetOutputPortRealSignal(S,6);
    float            *X1, *Y1, *Z1, *Yaw1, *Pitch1, *Roll1, *Qx, *Qy, *Qz, *Qw;
    double           TimeStamp1;
    int_T             width = ssGetOutputPortWidth(S,0);
    int_T             ret3;
    int               ID_num;
    
    ID_num=(int) *uPtrs[0];    
    ret3=TT_UpdateSingleFrame();
    TT_TrackableLocation( ID_num, X1, Y1, Z1, Qx, Qy, Qz, Qw, Yaw1, Pitch1, Roll1);
    TimeStamp1=TT_FrameTimeStamp();
    
    *X=(real_T) *X1;
    *Y=(real_T) *Y1;
    *Z=(real_T) *Z1;
    *Yaw=(real_T) *Yaw1;
    *Pitch=(real_T) *Pitch1;
    *Roll=(real_T) *Roll1;
    *TimeStamp=(real_T) TimeStamp1;
 
}


/* Function: mdlTerminate =====================================================
 * Abstract:
 *    No termination needed, but we are required to have this routine.
 */
static void mdlTerminate(SimStruct *S)
{
    int_T             ret4;
            
    ret4=TT_FinalCleanup();
    ret4=TT_Shutdown();
}



#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
