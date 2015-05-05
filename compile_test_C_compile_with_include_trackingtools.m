%% compile and run
%% compile

cd('C:\Users\sasson\OneDrive\work control lab aero summer 2014 technion\C_code\Motive-S-function')
mex -v -g test_C_compile_with_include_trackingtools.cpp '-lNPTrackingToolsx64'
%% run
test_C_compile_with_include_trackingtools()