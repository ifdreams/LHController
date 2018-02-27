#pragma once

/********************************************************************************************/
/*注意：使用 LHController_VDC 静态库时，需要在工程属性中定义预处理宏->LHController_VDC_LIB
/*********** imports / exports LHController_VDC *********************************************/

#define LHController_VDC_EXPORTS

#ifdef LHController_VDC_LIB
	#define LHController_VDC_API EXTERN_C long
#else
	#ifdef LHController_VDC_EXPORTS
		#define LHController_VDC_API EXTERN_C __declspec(dllexport) long 
	#else
		#define LHController_VDC_API EXTERN_C __declspec(dllimport) long 
	#endif
#endif


#define LHController_Handle long
/*------------------------------------------LHController_VDC导出函数----------------------------------------------------------*/

/**
*
*     @brief  同步异步模式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/

LHController_VDC_API LHController_Synchronous_asynchronous(LHController_Handle controllerHandle, int sa);


/**
*
*     @brief  创建一个网络连接
*     @param  输入参数
*     @param  serverIPAddress 服务器IP地址 如172.16.83.1
*     @param  serverPort 服务器端口号,支持端口1000~9999
*     @param  输出参数
*     @param  controllerHandle 控制句柄
*     @return 操作成功：LH_SUCCEED
*     @return 操作失败：参见错误代码表
*	  @exception 抛出错误代码，请参考错误代码表
*     @see    错误代码表
*	  @attention 最大连接数支持100
*	  @warning	 每个连接会启动一个线程，断开时请使用LHController_DestroyEtheConnection函数
*/
LHController_VDC_API LHController_CreateEtheConnectionByIP(char *serverIPAddress, int serverPort, LHController_Handle *controllerHandle);

/**
*
*     @brief  断开一个网络连接
*     @param  输入参数
*     @param  controllerHandle 控制句柄
*     @return 操作成功：LH_SUCCEED
*     @return 操作失败：参见错误代码表
*	  @exception 抛出错误代码，请参考错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_DestroyEtheConnection(LHController_Handle controllerHandle);
/**
*
*     @brief  打开单通道光源，不带亮度值
*     @param  输入参数
*     @param  controllerHandle 控制句柄
*     @param  channelIndex 指定需要打开的通道号，取值范围 1~8
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*	  @note	  打开光源亮度值为存储器存储亮度值。
*/
LHController_VDC_API LHController_TurnonChannel(LHController_Handle controllerHandle, int channelIndex);
/**
*
*     @brief  打开一个串口
*     @param  输入参数
*     @param  comName 串口号，如COM1
*     @param  baudrate 波特率
*     @param  输出参数
*     @param  controllerHandle 控制句柄
*     @return 操作成功：LH_SUCCEED
*     @return 操作失败：参见错误代码表
*	  @exception 抛出错误代码，请参考错误代码表
*     @see    错误代码表
*	  @attention 最大连接数支持100
*	  @warning	 每个连接会启动一个线程，断开时请使用LHController_ReleaseSerialPort函数
*/
LHController_VDC_API LHController_InitSerialPort(char *comName, int baudrate, LHController_Handle *controllerHandle);
/**
*
*     @brief  释放一个串口
*     @param  输入参数
*     @param  controllerHandle 控制句柄
*     @return 操作成功：LH_SUCCEED
*     @return 操作失败：参见错误代码表
*	  @exception 抛出错误代码，请参考错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReleaseSerialPort(LHController_Handle controllerHandle);
/**
*
*     @brief  关闭单通道
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex 通道号范围为 1~8
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_TurnoffChannel(LHController_Handle controllerHandle, int channelIndex);
/**
*
*     @brief  多通道打开或关闭
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  数 据：ABCDEFGH 八通道光源开关状态，A 代表通道 1，B 代表通道 2， C 代表通道 3， D 代表通道 4， E 代表第 5 通道，
*	  F 代表第 6 通道， G 代表第 7 通道， H 代表第 8 通道； 0 表示关， 1 表示开。如全部打开"11111111",全部关闭"00000000",打开第一个通道"10000000"
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_TurnoffTurnonChannel(LHController_Handle controllerHandle, char *channelIndex);
/**
*
*     @brief  设置亮度等级
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~8
*     @param  intensity  设置的亮度值，取值范围 000~255
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetIntensity(LHController_Handle controllerHandle, int channelIndex, int intensity);
/**
*
*     @brief  查询亮度值
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要查询的通道号，取值范围 1~8
*     @param  输出参数
*     @param  intensity  返回亮度值
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReadIntensity(LHController_Handle controllerHandle, int channelIndex, int *intensity);
/**
*
*     @brief  带亮度参数打开通道
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要打开的通道号，取值范围 1~8
*     @param  intensity 指定的亮度值。取值范围 000~255
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_TurnonChannelSetIntensity(LHController_Handle controllerHandle, int channelIndex, int intensity);
/**
*
*     @brief  单通道指令频闪触发
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~8
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_AStrobeTrigger(LHController_Handle controllerHandle, int channelIndex);
/**
*
*     @brief  多通道指令频闪触发
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   数 据：ABCDEFGH 八通道光源频闪触发开关。 A 代表通道 1， B 代表通道 2， C 代表通道 3， D 代表通道 4， E 代表第 5通道
*     F 代表第 6 通道， G 代表第 7 通道， H 代表第 8 通道； 0 表示不触发， 1 表示触发。要触发的通道号，如全部触发"11111111",触发第一个通道"10000000"
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ManyStrobeTrigger(LHController_Handle controllerHandle, char *channelIndex);
/**
*
*     @brief  设置频闪脉宽
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   指定需要操作的通道号，取值范围 1~8
*     @param  triggerWidth   频闪脉宽，取值范围 0~9999，以 1ms 为单位
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetTriggerWidth(LHController_Handle controllerHandle, int channelIndex, int triggerWidth);
/**
*
*     @brief  查询频闪脉宽
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   指定需要查询的通道号，取值范围 1~8
*     @param  输出参数
*     @param  triggerWidth   返回脉冲宽度
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReadTriggerWidth(LHController_Handle controllerHandle, int channelIndex, int* triggerWidth);

/**
*
*     @brief  设置外部触发方式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   指定需要操作的通道号，取值范围 1~4
*     @param  channelMode   外部触发方式，
*?			 0: 低电平时间普通触发
*?          1：下降沿普通触发
*?          2：上升沿普通触发
*			 3：禁用外部触发
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*	  @note	  出厂设置为禁用外部触发
*/
LHController_VDC_API LHController_SetExternalTrigger(LHController_Handle controllerHandle, int channelIndex, int channelMode);

/**
*
*     @brief  查询外部触发方式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   指定需要查询的通道号，取值范围 1~4
*     @param  输出参数
*     @param  channelMode   外部触发方式，
*?			 0: 低电平时间普通触发，
*?          1：下降沿普通触发，
*?          2：上升沿普通触发，
*			 3：禁用外部触发
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*	  @note	  出厂设置为禁用外部触发
*/

LHController_VDC_API LHController_ReadExternalTrigger(LHController_Handle controllerHandle, int channelIndex, int *channelMode);

/**
*
*     @brief  带时间参数频闪触发
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  通道号。取值范围 1~8
*     @param  triggerWidth	频闪触发时间，以 ms 为单位。取值范围 0~9999
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/

LHController_VDC_API  LHController_TimeTrobeTrigger(LHController_Handle controllerHandle, int channelIndex, int triggerWidth);

/**
*
*     @brief  设置输出电压
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   通道号。取值范围 1~4
*     @param  voltage	设置输出最大电压值，单位 V。
*?					    数值 0 表示 4.0V；
*?                     数值 1 表示 5.0V;
*?                     数值 2 表示 12.0V;
*?                     数值 3 表示 20.0V;
*?                     数值 4 表示 22.0V;
*?                     数值 5 表示 24.0V;
*?                     数值 6 表示 26.0V;
*?                     数值 7 表示 28.0V;
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetoutputVoltage(LHController_Handle controllerHandle, int channelIndex, int voltage);
/**
*
*     @brief  查询输出电压
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   通道号。取值范围 1~4
*     @param  输出参数
*     @param  voltage	电压值代号
*					    数值0表示 4.0V，
*					    数值1表示 5.0V，
*					    数值2表示 12.0V，
*					    数值3表示 20.0V，
*					    数值4表示 22.0V，
*					    数值5表示 24.0V，
*					    数值6表示 26.0V，
*					    数值7表示 28.0V，
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReadOutputVoltage(LHController_Handle controllerHandle, int channelIndex, int *voltage);

/**
*
*     @brief  设置通道默认输出模式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   通道号， 取值范围 1~8
*     @param  channelDefault 通道默认输出模式，“0”为上电通道输出默认无效，光源不亮； “1” 为上电默认输出默认有效，光源常亮。 默认有
*						     效输出光源亮度值为存储器亮度值。
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetDefaultOutput(LHController_Handle controllerHandle, int channelIndex, int channelDefault);
/**
*
*     @brief  查询通道默认输出模式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   通道号， 取值范围 1~8
*     @param  输出参数
*     @param  channelDefault 通道默认输出模式，“0”为上电通道输出默认无效，光源不亮； “1” 为上电默认输出默认有效，光源常亮。 默认有
*						     效输出光源亮度值为存储器亮度值。
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReadDefaultOutput(LHController_Handle controllerHandle, int channelIndex, int *channelDefault);
/**
*
*     @brief  设置外部IO工作模式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  inputOutput   取值“1”为设置输入 I/O 工作模式；取值“2” 为输出 I/O 工作模式。
*     @param  externalmode  工作模式。 当 X 位取值 1 时， Y 位设置“0”为控制器默认工作模式，处于外部触发控制状态； Y 位设置“1”
*							为普通输入 I/O 工作模式， 可通过 IO 指令获取指令查询 IO 电平状态。 当 X 位取值 2 时， Y 位设置“0”为控制器默认
*							工作模式， IO 处于报警信号工作状态； Y 位设置“1” 为普通输出 I/O 工作模式， 可通过 IO 指令设置 IO 口输出电平状
态。
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SedExternalIOmode(LHController_Handle controllerHandle, int inputOutput, int externalmode);

/**
*
*     @brief  查询外部IO工作模式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  inputOutput   取值“1”时查询输入 I/O 工作模式；取值“2” 查询输出 I/O 工作模式。
*     @param  输出参数
*     @param  externalmode  工作模式。 当 X 位取值 1 时， Y 位设置“0”为控制器默认工作模式，处于外部触发控制状态； Y 位设置“1”
*							为普通输入 I/O 工作模式， 可通过 IO 指令获取指令查询 IO 电平状态。 当 X 位取值 2 时， Y 位设置“0”为控制器默认
*							工作模式， IO 处于报警信号工作状态； Y 位设置“1” 为普通输出 I/O 工作模式， 可通过 IO 指令设置 IO 口输出电平状
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReadExternalIOmode(LHController_Handle controllerHandle, int inputOutput, int *externalmode);

/**
*
*     @brief  获取输入IO状态
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  readInput 表示输入 IO 做为普通 IO 口使用时的输入状态； “0” 表示输入 IO 为低电平， “1” 表示输入 IO 为高电平，
*						数据左起第 1 位为输入 IO 第 1 通道状态，第 2 位为输入 IO 第 3 通道状态，以此类推。如“00000”
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReadInput(LHController_Handle controllerHandle, char *readInput);

/**
*
*     @brief  设置输出IO状态
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  output 表示输出状态，“0”表示输出打开， “1” 表示输出关闭。左起第 1 位表示第 1 个输出 IO 通道状态，第 2 位
*			         表示第 2 个输出 IO 通道状态， 以此类推。如“00000”
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetOutput(LHController_Handle controllerHandle, char *output);

/**
*
*     @brief  获取报警信息
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  alarm 报警信息，ABCD——检测 LED 状态结果，
*							  数值 0 表示对应 LED 良好。
*?							  数值 1 表示对应通道 LED 损坏，
*?							  数值 2 表示对应通道电流失控。
*?							  A 位表示通道 1； B 位表示通道 2； C 位表示通道 3； D 位表示通道 4。
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_Readalarm(LHController_Handle controllerHandle, char *alarm);

/**
*
*     @brief  清除报警信息
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_Clearedzalarm(LHController_Handle controllerHandle);
/**
*
*     @brief  查询控制器温度
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  temperature 温度值
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_Redtemperature(LHController_Handle controllerHandle, int *temperature);

/**
*
*     @brief  重启控制器
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_Reboot(LHController_Handle controllerHandle);

/**
*
*     @brief  恢复出厂参数
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_Format(LHController_Handle controllerHandle);

/**
*
*     @brief  保存参数
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_Save(LHController_Handle controllerHandle);

/**
*
*     @brief  设置串口波特率
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  baudrate 波特率，本机串口波特率分为 7 级， 具体数据和波特率信息如下：
*							   数据“1”波特率为9600bps，
*							   数据“2”波特率为14400bps，
*							   数据“3”波特率为19200bps，
*							   数据“4”波特率为38400bps，
*							   数据“5”波特率为56000bps，
*							   数据“6”波特率为57600bps，
*							   数据“7”波特率为115200bps，
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*	  @note	  出厂默认波特率为 115200 bps
*/
LHController_VDC_API LHController_SetComBaudrate(LHController_Handle controllerHandle, int baudrate);

/**
*
*     @brief  设置控制器IP地址
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  serverip	 IP地址
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetServerIP(LHController_Handle controllerHandle, char* serverip);
/**
*
*     @brief  设置控制器子网掩码
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  serverip	 子网掩码
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetServerSubnetMask(LHController_Handle controllerHandle, char* subnetmask);

/**
*
*     @brief  设置控制器网关
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  gateway	 网关
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetServerGateway(LHController_Handle controllerHandle, char* gateway);
/**
*
*     @brief  设置远程IP地址
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  clientIP	 远程IP
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetClientIP(LHController_Handle controllerHandle, char* clientIP);
/**
*
*     @brief  设置控制器端口
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  serverport	   控制器端口
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetServerPort(LHController_Handle controllerHandle, int serverport);
/**
*
*     @brief  设置远程端口号
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  clientport	   远程端口号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/

LHController_VDC_API LHController_SetClientPort(LHController_Handle controllerHandle, int clientport);
/**
*
*     @brief  读取TCP配置
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  serverIP	控制器IP地址
*     @param  serverSubnetMask	控制器子网掩码
*     @param  serverGateway 控制器网关
*     @param  clientIP	远程IP地址
*     @param  serverport 控制器端口号
*     @param  clientport 远程端口号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReadTCPIP(LHController_Handle controllerHandle,
	char *serverIP,
	char *serverSubnetMask,
	char *serverGateway,
	char *clientIP,
	int  *serverport,
	int  *clientport);
/**
*
*     @brief  查询控制器版本
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_Readversion(LHController_Handle controllerHandle, char* version);




/**
*
*     @brief  高亮设置频闪脉宽
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_Hig_SetTriggerWidth(LHController_Handle controllerHandle, int channelIndex, int triggerWidth);


/**
*
*     @brief  高亮查询频闪脉宽
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_Hig_ReadTriggerWidth(LHController_Handle controllerHandle, int channelIndex, int* triggerWidth);

/**
*
*     @brief 高亮带时间参数频闪触发
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/

LHController_VDC_API LHController_Hig_TimeTrobeTrigger(LHController_Handle controllerHandle, int channelIndex, int triggerWidth);


/**
*
*     @brief 设置触发完成信号脉宽
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetCompleteSignal(LHController_Handle controllerHandle, int triggerWidth);


/**
*
*     @brief 查询触发完成信号脉宽
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReadCompleteSignal(LHController_Handle controllerHandle, int *triggerWidth);


/**
*
*     @brief 设置触发完成信号延迟时间
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetDelayTime(LHController_Handle controllerHandle, int triggerWidth);

/**
*
*     @brief 查询触发完成信号延迟时间
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReadDelayTime(LHController_Handle controllerHandle, int *triggerWidth);

/**
*
*     @brief 设置触发信号间隔时间
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_SetIntervalTime(LHController_Handle controllerHandle, int triggerWidth);


/**
*
*     @brief 读取触发信号间隔时间
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  version	 控制器版本号
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_VDC_API LHController_ReadIntervalTime(LHController_Handle controllerHandle, int *triggerWidth);



