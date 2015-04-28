% ipath1 = ['-I' fullfile('c:','Program Files','OptiTrack','Motive','inc')]
% ipath2 = ['-I' fullfile('c:','Program Files','OptiTrack','Motive','lib')]
% ipath3 = ['-I' fullfile('d:','or hirshfeld','onedrive','work control lab aero summer 2014 technio','C_code')]
% NPTrackingToolslib_location = ['-L' fullfile('c:','Program Files','OptiTrack','Motive','lib')]

%mex('-v',ipath3,NPTrackingToolslib_location,'-lNPTrackingToolsx64.lib','test_C_compile_with_include_trackingtools.c')

%mex -v '-Id:\or hirshfeld\onedrive\work control lab aero summer 2014 technio\C_code' '-LD:\or hirshfeld\onedrive\work control lab aero summer 2014 technion\C_code' '-lNPTrackingToolsx64.lib' test_C_compile_with_include_trackingtools.c

%mex -v test_C_compile_with_include_trackingtools.cpp -I"D:\or hirshfeld\onedrive\work control lab aero summer 2014 technion\C_code\Motive-S-function" '-LD:\or hirshfeld\onedrive\work control lab aero summer 2014 technion\C_code\Motive-S-function' '-lNPTrackingTools'

%mex -v test_C_compile_with_include_trackingtools.cpp -I"D:\or hirshfeld\onedrive\work control lab aero summer 2014 technion\C_code\Motive-S-function" '-LD:\or hirshfeld\onedrive\work control lab aero summer 2014 technion\C_code\Motive-S-function' '-lNPTrackingToolsx64'

mex -v test_C_compile_with_include_trackingtools.cpp '-lNPTrackingToolsx64'
