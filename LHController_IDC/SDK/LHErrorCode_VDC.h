#pragma once

/*------------------------------------------LHController_VDC错误代码表----------------------------------------------------------*/

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
#define LH_ERR_BRIGHTNESS_LEVElL					  1010  //亮度等级参数越界
#define LH_ERR_TRIGGRRWIDTH							  1012	//频闪宽度参数越界
#define LH_ERR_TRIGGRRMODE							  1013	//触发模式参数越界
#define LH_ERR_VOLTAGE								  1014  //设置电压参数越界
#define LH_ERR_DEFAULT								  1015  //默认参数参数越界 
#define LH_ERR_BAUDRATE								  1016  //波特率参数越界
#define	LH_ERR_PARAMETER							  1017  //传入参数错误
#define LH_ERR_TURNONCH_FAILED				          1018	//打开通道失败
#define LH_ERR_TURNOFFCH_FAILED				          1019	//关闭通道失败
#define	LH_ERR_SETBRIGHTNESS_FAILED					  1020	//设置亮度等级失败							
#define LH_ERR_READBRIGHTNESS_FAILED				  1021	//查询亮度等级失败
#define LH_ERR_STROBETRIGGER_FAILED					  1022  //频闪触发失败
#define LH_ERR_SETTRIGGERWIDTH_FAILED				  1023  //设置频闪脉冲宽度失败
#define LH_ERR_READTRIGGERWIDTH_FAILED				  1024  //查询频闪宽度失败
#define LH_ERR_SEREXTERNALTRIGGER_FAILED			  1025  //设置外部触发方式失败
#define LH_ERR_READEXTERNALTRIGGER_FAILED			  1026  //查询外部触发方式失败
#define LH_ERR_SEROUTPUTVOLTAGE_FAILED				  1027  //设置输出电压失败
#define LH_ERR_READOUTPUTVOLTAGE_FAILED				  1028  //查询输出电压失败
#define LH_ERR_SETDEFAULTOUTPUT_FAILD				  1029	//设置通道默认输出模式失败
#define LH_ERR_READDEFAULTOUTPUT_FAILD				  1030	//查询通道默认输出模式失败
#define LH_ERR_SEDEXTERNALIOMODE_FAILD			      1031  //设置外部IO接口工作模式失败
#define LH_ERR_READEXTERNALIOMODE_FAILD			      1032  //查询外部IO接口工作模式失败
#define LH_ERR_READINPUT_FAILD						  1033	//获取输入IO失败
#define LH_ERR_SETOUTPUT_FAILD						  1034  //设置输出IO失败
#define LH_ERR_READALARM_FAILD						  1035  //获取报警状态失败
#define LH_ERR_CLEAREDZALARM_FAILD					  1036  //清除报警信息失败
#define LH_ERR_REDTEMPERATURE_FAILD					  1037	//查询控制器温度失败
#define LH_ERR_REBOOT_FAILD							  1038	//重启控制器失败
#define LH_ERR_FORMAT_FAILD							  1039  //恢复出厂参数失败
#define LH_ERR_SAVE_FAILD							  1040  //保存参数失败
#define LH_ERR_SETCOMBAUDRATE_FAILD				      1041	//设置控制器波特率失败
#define LH_ERR_SETSERVERIP_FAILD		              1042	//设置控制器IP地址失败
#define LH_ERR_SETSERVERSUBNETMASK_FAILD			  1043	//设置控制器子网掩码失败
#define LH_ERR_SETSERVERGATEWAY_FAILD				  1044  //设置控制器网关失败
#define LH_ERR_SETCLIENTIP_FAILD					  1045  //设置远程IP地址失败
#define LH_ERR_SETSERVERPORT_FAILD					  1046  //设置控制器端口失败
#define LH_ERR_SETCLIENTPORT_FAILD					  1047  //设置远程端口失败	
#define LH_ERR_READTCPIP_FAILD						  1048  //读取TCP配置失败
#define LH_ERR_READVERSION_FAILD					  1049  //查询控制器版本

