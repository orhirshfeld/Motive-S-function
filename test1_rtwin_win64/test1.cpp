/*
 * test1.cpp
 *
 * Code generation for model "test1".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C++ source code generated on : Tue May 05 18:30:27 2015
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "test1.h"
#include "test1_private.h"
#include "test1_dt.h"

/* list of Real-Time Windows Target timers */
extern "C" const int RTWinTimerCount = 1;
extern "C" const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_test1_T test1_B;

/* Block states (auto storage) */
DW_test1_T test1_DW;

/* Real-time model */
RT_MODEL_test1_T test1_M_;
RT_MODEL_test1_T *const test1_M = &test1_M_;

/* Model output function */
void test1_output(void)
{
  /* Constant: '<Root>/Constant' */
  test1_B.Constant = test1_P.Constant_Value;

  /* Level2 S-Function Block: '<Root>/S-Function' (Get_Data_From_Motive_API) */
  {
    SimStruct *rts = test1_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function */
void test1_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++test1_M->Timing.clockTick0)) {
    ++test1_M->Timing.clockTickH0;
  }

  test1_M->Timing.t[0] = test1_M->Timing.clockTick0 * test1_M->Timing.stepSize0
    + test1_M->Timing.clockTickH0 * test1_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void test1_initialize(void)
{
  /* Start for Constant: '<Root>/Constant' */
  test1_B.Constant = test1_P.Constant_Value;

  /* Level2 S-Function Block: '<Root>/S-Function' (Get_Data_From_Motive_API) */
  {
    SimStruct *rts = test1_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void test1_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (Get_Data_From_Motive_API) */
  {
    SimStruct *rts = test1_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
extern "C" void MdlOutputs(int_T tid)
{
  test1_output();
  UNUSED_PARAMETER(tid);
}

extern "C" void MdlUpdate(int_T tid)
{
  test1_update();
  UNUSED_PARAMETER(tid);
}

extern "C" void MdlInitializeSizes(void)
{
}

extern "C" void MdlInitializeSampleTimes(void)
{
}

extern "C" void MdlInitialize(void)
{
}

extern "C" void MdlStart(void)
{
  test1_initialize();
}

extern "C" void MdlTerminate(void)
{
  test1_terminate();
}

/* Registration function */
extern "C" RT_MODEL_test1_T *test1(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test1_M, 0,
                sizeof(RT_MODEL_test1_T));
  rtsiSetSolverName(&test1_M->solverInfo,"FixedStepDiscrete");
  test1_M->solverInfoPtr = (&test1_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = test1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    test1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    test1_M->Timing.sampleTimes = (&test1_M->Timing.sampleTimesArray[0]);
    test1_M->Timing.offsetTimes = (&test1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    test1_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    test1_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(test1_M, &test1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = test1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    test1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(test1_M, -1);
  test1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  test1_M->Sizes.checksums[0] = (745491585U);
  test1_M->Sizes.checksums[1] = (400632184U);
  test1_M->Sizes.checksums[2] = (1765795563U);
  test1_M->Sizes.checksums[3] = (3767884960U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    test1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test1_M->extModeInfo,
      &test1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test1_M->extModeInfo, test1_M->Sizes.checksums);
    rteiSetTPtr(test1_M->extModeInfo, rtmGetTPtr(test1_M));
  }

  test1_M->solverInfoPtr = (&test1_M->solverInfo);
  test1_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&test1_M->solverInfo, 0.01);
  rtsiSetSolverMode(&test1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  test1_M->ModelData.blockIO = ((void *) &test1_B);
  (void) memset(((void *) &test1_B), 0,
                sizeof(B_test1_T));

  /* parameters */
  test1_M->ModelData.defaultParam = ((real_T *)&test1_P);

  /* states (dwork) */
  test1_M->ModelData.dwork = ((void *) &test1_DW);
  (void) memset((void *)&test1_DW, 0,
                sizeof(DW_test1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &test1_M->NonInlinedSFcns.sfcnInfo;
    test1_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(test1_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &test1_M->Sizes.numSampTimes);
    test1_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(test1_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,test1_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(test1_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(test1_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(test1_M));
    rtssSetStepSizePtr(sfcnInfo, &test1_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(test1_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &test1_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &test1_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &test1_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &test1_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &test1_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &test1_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &test1_M->solverInfoPtr);
  }

  test1_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&test1_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    test1_M->childSfunctions = (&test1_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    test1_M->childSfunctions[0] = (&test1_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: test1/<Root>/S-Function (Get_Data_From_Motive_API) */
    {
      SimStruct *rts = test1_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = test1_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = test1_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = test1_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &test1_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, test1_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &test1_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &test1_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &test1_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &test1_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &test1_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &test1_B.Constant;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &test1_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 7);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &test1_B.SFunction_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &test1_B.SFunction_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &test1_B.SFunction_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &test1_B.SFunction_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &test1_B.SFunction_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &test1_B.SFunction_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &test1_B.SFunction_o7));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "test1/S-Function");
      ssSetRTModel(rts,test1_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      Get_Data_From_Motive_API(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortWidth(rts, 1, 1);
      ssSetOutputPortDataType(rts, 1, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 1, 0);
      ssSetOutputPortFrameData(rts, 1, 0);
      ssSetOutputPortWidth(rts, 2, 1);
      ssSetOutputPortDataType(rts, 2, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 2, 0);
      ssSetOutputPortFrameData(rts, 2, 0);
      ssSetOutputPortWidth(rts, 3, 1);
      ssSetOutputPortDataType(rts, 3, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 3, 0);
      ssSetOutputPortFrameData(rts, 3, 0);
      ssSetOutputPortWidth(rts, 4, 1);
      ssSetOutputPortDataType(rts, 4, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 4, 0);
      ssSetOutputPortFrameData(rts, 4, 0);
      ssSetOutputPortWidth(rts, 5, 1);
      ssSetOutputPortDataType(rts, 5, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 5, 0);
      ssSetOutputPortFrameData(rts, 5, 0);
      ssSetOutputPortWidth(rts, 6, 1);
      ssSetOutputPortDataType(rts, 6, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 6, 0);
      ssSetOutputPortFrameData(rts, 6, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  test1_M->Sizes.numContStates = (0);  /* Number of continuous states */
  test1_M->Sizes.numY = (0);           /* Number of model outputs */
  test1_M->Sizes.numU = (0);           /* Number of model inputs */
  test1_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  test1_M->Sizes.numSampTimes = (1);   /* Number of sample times */
  test1_M->Sizes.numBlocks = (10);     /* Number of blocks */
  test1_M->Sizes.numBlockIO = (8);     /* Number of block outputs */
  test1_M->Sizes.numBlockPrms = (1);   /* Sum of parameter "widths" */
  return test1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
