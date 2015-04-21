%include lib
ipath1='-ID:\or hirshfeld\onedrive\work control lab aero summer 2014 technion\C_code\Motive-S-function'; 
ipath2='-IC:\Program Files\MATLAB\R2014a\extern\include';
if computer('arch')=='win32'
    NPTlib='D:\or hirshfeld\onedrive\work control lab aero summer 2014 technion\C_code\NPTrackingTools.lib';
else
    NPTlib='D:\or hirshfeld\onedrive\work control lab aero summer 2014 technion\C_code\NPTrackingToolsx64.lib';
end
    
%mex('-v',ipath1,ipath2,'-lNPTrackingTools','Get_Data_From_Motive_API.c',NPTlib) 

mex -v -lNPTrackingToolsx64 'Get_Data_From_Motive_API.c'

% -v = Builds in verbose mode. Displays values for internal variables after all command-line arguments are considered. Displays each compile and link step fully evaluated. Use for troubleshooting compiler setup problems.