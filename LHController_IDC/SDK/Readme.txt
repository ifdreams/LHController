------------------------LHController_VDC.dll/LHController_IDC.dll------------------------
-----------------------------------------------------------------------------------------
1、使用LHController_VDC/LHController_IDC静态库时，需要在工程属性中定义预处理->
   LHController_VDC_LIB/LHController_IDC_LIB
2、提供了C++/C#/VB的SDK
-----------------------------------------------------------------------------------------
3、LHErrorCode_VDC.h/LHErrorCode_IDC.h和LHController_VDC.h/LHController_IDC.h为静态库头文件
4、LHController_VDC.dll/LHController_IDC.dll为C++动态库
5、LHController_VDC_CS.dll/LHController_IDC_CS.dll为C#库
-----------------------------------------------------------------------------------------
6，函数使用说明参阅LHController_VDC_SDKHelpfileV1.0.chm
   LHController_VDC_SDKHelpfileV1.0.chm帮助文档
-----------------------------------------------------------------------------------------

7、依赖关系
	
   电压型控制器动态链接库
   LHController_VDC_CS.dll---->LHController_VDC.dll

   电流型控制器动态链接库
   LHController_IDC_CS.dll---->LHController_IDC.dll
   
   电流型控制器静态库
   LHController_IDC.h    |
   LHErrorCode_IDC.h     |---->LHController_IDC.lib

   电压型控制器静态库
   LHController_VDC.h    |
   LHErrorCode_VDC.h     |---->LHController_VDC.lib


2017/9/6 16:05 Rex Van