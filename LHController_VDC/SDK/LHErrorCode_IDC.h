#pragma once


/*--------------------------LHController_IDC错误代码表---------------------------------------------------*/
#define LH_SUCCEED 								       0	//操作成功
#define LH_ERR_CREATEETHECON_FAILED			          1001	//创建网口连接失败
#define LH_ERR_UNKNOWN						          1002	//未知错误
#define LH_ERR_INVALIDHANDLE				          1003	//无效的句柄
#define	LH_ERR_MAXIMUM								  1004  //超过最大连接数
#define LH_ERR_INITSERIAL_FAILED			          1005  //打开串口失败
#define LH_ERR_SEND_DATA							  1006	//控制器无应答
#define LH_ERR_CHINDEX_OUTRANGE				          1007	//通道序号参数越界
#define LH_ERR_DISCONNECTED							  1008	//没有连接控制器
#define LH_ERR_CHINDEX_LACK							  1009	//通道号不全
#define LH_ERR_PARAMETERERROR						  1010  //恒压恒压模式参数错误
#define LH_ERR_CURRENTCONSTABTVOLTAGEMODE_FAILED	  1011  //恒流恒压模式切换失败
#define LH_ERR_READCURRENTCONSTABTVOLTAGEMODE_FAILED  1012  //查询恒流恒压模式失败
#define LH_ERR_CURRENTCROSSED						  1013  //电流值越界
#define LH_ERR_SETTGEOUTPTCURRENT_FAILED			  1014	//设置输出电流失败
#define LH_ERR_SETTGEOUTPTCURRENTON_FAILED			  1015	//设置输出电流并打开失败
#define LH_ERR_CURRENTON_FAILED						  1016	//带电流参数打开失败
#define LH_ERR_READCURRENT_FAILED					  1017	//查询输出电流失败
#define LH_ERR_VOLTAGECRISSED						  1018  //电压值错误
#define LH_ERR_SETOUTPUTVOLTAGE_FAILED				  1019	//设置输出电压失败
#define LH_ERR_SETOUTPUTVOLTAGEON_FAILED			  1020	//设置输出电压并打开失败
#define LH_ERR_READOUTPUTVOLTAGE_FAILED			      1021	//查询输出电压失败
#define LH_ERR_BRIGHTESSVALUE_FAILED				  1022  //亮度值越界
#define LH_ERR_SETOUTPUTVOLTAGEPWMGRADE_FAILED		  1023  //设置亮度值失败
#define LH_ERR_SETOUTPUTVOLTAGEPWMGRADEON_FAILED	  1024  //设置亮度值并打开失败
#define LH_ERR_OUTPUTVOLTAGEPWMGRADEON_FAILED		  1025  //带亮度值并打开失败
#define LH_ERR_READBRIGHTNESS_FAILED				  1026	//查询亮度等级失败
#define LH_ERR_TURNONCH_FAILED				          1027	//打开通道失败
#define LH_ERR_TURNOFFCH_FAILED				          1028	//关闭通道失败
#define LH_ERR_SETEXTERNALINPUTIOMODE_FAILED		  1029	//设置外部输入IO工作模式失败
#define LH_ERR_READEXTERNALINPUTIOMODE_FAILED		  1030	//查询外部输入IO工作模式失败
#define LH_ERR_SEDEXTERNALOUTPUTIOMODE_FAILED		  1031	//设置外部输出IO工作模式失败
#define LH_ERR_READEXTERNALOUTPUTIOMODE_FAILED		  1032	//查询外部输出IO工作模式失败
#define LH_ERR_READOUTPUT_FAILED					  1033	//查询输出IO状态失败
#define LH_ERR_TRIGGRRWIDTH							  1034	//频闪宽度参数越界
#define LH_ERR_VOLTAGE								  1035  //设置电压参数越界
#define LH_ERR_DEFAULT								  1036  //默认参数参数越界 
#define LH_ERR_BAUDRATE								  1037  //波特率参数越界
#define	LH_ERR_PARAMETER							  1038  //传入参数错误				
#define LH_ERR_STROBETRIGGER_FAILED					  1039  //频闪触发失败
#define LH_ERR_SETTRIGGERWIDTH_FAILED				  1040  //设置频闪脉冲宽度失败
#define LH_ERR_READTRIGGERWIDTH_FAILED				  1041  //查询频闪宽度失败
#define LH_ERR_SETDEFAULTOUTPUT_FAILD				  1042	//设置通道默认输出模式失败
#define LH_ERR_READINPUT_FAILD						  1043	//获取输入IO失败
#define LH_ERR_SETOUTPUT_FAILD						  1044  //设置输出IO失败
#define LH_ERR_READALARM_FAILD						  1045  //获取报警状态失败
#define LH_ERR_CLEAREDZALARM_FAILD					  1046  //清除报警信息失败
#define LH_ERR_REDTEMPERATURE_FAILD					  1047	//查询控制器温度失败
#define LH_ERR_REBOOT_FAILD							  1048	//重启控制器失败
#define LH_ERR_FORMAT_FAILD							  1049  //恢复出厂参数失败
#define LH_ERR_SAVE_FAILD							  1050  //保存参数失败
#define LH_ERR_SETCOMBAUDRATE_FAILD				      1051	//设置控制器波特率失败
#define LH_ERR_SETSERVERIP_FAILD		              1052	//设置控制器IP地址失败
#define LH_ERR_SETSERVERSUBNETMASK_FAILD			  1053	//设置控制器子网掩码失败
#define LH_ERR_SETSERVERGATEWAY_FAILD				  1054  //设置控制器网关失败
#define LH_ERR_SETCLIENTIP_FAILD					  1055  //设置远程IP地址失败
#define LH_ERR_SETSERVERPORT_FAILD					  1056  //设置控制器端口失败
#define LH_ERR_SETCLIENTPORT_FAILD					  1057  //设置远程端口失败	
#define LH_ERR_READTCPIP_FAILD						  1058  //读取TCP配置失败
#define LH_ERR_READVERSION_FAILD					  1059  //查询控制器版本
