#pragma once
/********************************************************************************************/
/*注意：使用 LHController_IDC 静态库时，需要在工程属性中定义预处理宏->LHController_IDC_LIB
/*********** imports / exports LHController_IDC *********************************************/

#define LHController_IDC_EXPORTS

#ifdef LHController_IDC_LIB
#define LHController_IDC_API EXTERN_C long
#else
#ifdef LHController_IDC_EXPORTS
#define LHController_IDC_API EXTERN_C __declspec(dllexport) long 
#else
#define LHController_IDC_API EXTERN_C __declspec(dllimport) long 
#endif
#endif


#define LHController_Handle long

/*------------------------------------------LHController_IDC导出函数----------------------------------------------------------*/

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

LHController_IDC_API LHController_Synchronous_asynchronous(LHController_Handle controllerHandle, int sa);

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
LHController_IDC_API LHController_CreateEtheConnectionByIP(char *serverIPAddress, int serverPort, LHController_Handle *controllerHandle);
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
LHController_IDC_API LHController_DestroyEtheConnection(LHController_Handle controllerHandle);
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
LHController_IDC_API LHController_InitSerialPort(char *comName, int baudrate, LHController_Handle *controllerHandle);
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
LHController_IDC_API LHController_ReleaseSerialPort(LHController_Handle controllerHandle);

/**
*
*     @brief  恒流恒压模式切换
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex 指定需要操作的通道号，取值范围 1~4
*     @param  mode 输出模式，“0”为恒流输出模式； “1”恒压输出模式，
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*     @note   出厂默认为恒流输出模式
*/
LHController_IDC_API LHController_CurrentConstantVoltageMode(LHController_Handle controllerHandle, int channelIndex, int mode);
/**
*
*     @brief  查询恒流恒压模式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex 指定需要操作的通道号，取值范围 1~4
*     @param  输出参数
*     @param  mode 输出模式，“0”为恒流输出模式； “1”恒压输出模式，
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*     @note   出厂默认为恒流输出模式
*/
LHController_IDC_API LHController_ReadConstantVoltageMode(LHController_Handle controllerHandle, int channelIndex, int *mode);

/**
*
*     @brief  设置通道输出电流
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~4
*     @param  current 设置的输出恒流值，取值范围 20mA~1500mA
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_SetTheOutputCurrent(LHController_Handle controllerHandle, int channelIndex, int current);

/**
*
*     @brief  设置通道输出电流并打开
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~4
*     @param  current 设置的输出恒流值，取值范围 20mA~1500mA
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_SetTheOutputCurrentON(LHController_Handle controllerHandle, int channelIndex, int current);
/**
*
*     @brief  带电流参数打开通道
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~4
*     @param  current 指定的亮度值，取值范围 0000~1500。
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_CurrentON(LHController_Handle controllerHandle, int channelIndex, int current);

/**
*
*     @brief  查询通道输出电流
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~4
*     @param  输出参数
*     @param  current 亮度值
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_ReadCurrent(LHController_Handle controllerHandle, int channelIndex, int *current);
/**
*
*     @brief  设置通道输出电压
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~4
*     @param  voltage 设置输出电压值，单位 0.1V。
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_SetOutputVoltage(LHController_Handle controllerHandle, int channelIndex, int voltage);

/**
*
*     @brief  设置通道输出电压并打开
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~4
*     @param  voltage 设置输出电压值，单位 0.1V。
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_SetOutputVoltageON(LHController_Handle controllerHandle, int channelIndex, int voltage);
/**
*
*     @brief  查询通道输出电压
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~4
*     @param  输出参数
*     @param  voltage 输出电压值，单位 0.1V。
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_ReadOutputVoltage(LHController_Handle controllerHandle, int channelIndex, int *voltage);

/**
*
*     @brief  设置电压PWM细分等级
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~8
*     @param  pwmgrade 设置的亮度值，取值范围 000~255
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_SetOutputVoltagePWMgrade(LHController_Handle controllerHandle, int channelIndex, int pwmgrade);
/**
*
*     @brief  设置电压PWM细分等级并打开
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~8
*     @param  pwmgrade 设置的亮度值，取值范围 000~255
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_SetOutputVoltagePWMgradeON(LHController_Handle controllerHandle, int channelIndex, int pwmgrade);
/**
*
*     @brief  带PWM等级打开通道
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~8
*     @param  pwmgrade 设置的亮度值，取值范围 000~255
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_OutputVoltagePWMgradeON(LHController_Handle controllerHandle, int channelIndex, int pwmgrade);

/**
*
*     @brief  查询输出电压PWM细分等级
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~8
*     @param  输出参数
*     @param  pwmgrade 亮度值，范围 000~255
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_ReadOutputVoltagePWMgrade(LHController_Handle controllerHandle, int channelIndex, int *pwmgrade);

/**
*
*     @brief  打开单通道输出
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~8
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*	  @note	  打开光源亮度值为存储器存储亮度值
*/
LHController_IDC_API LHController_TurnonChannel(LHController_Handle controllerHandle, int channelIndex);
/**
*
*     @brief  关闭单通道
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex  指定需要操作的通道号，取值范围 1~8
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_TurnoffChannel(LHController_Handle controllerHandle, int channelIndex);
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
LHController_IDC_API LHController_TurnoffTurnonChannel(LHController_Handle controllerHandle, char *channelIndex);
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
LHController_IDC_API LHController_SetTriggerWidth(LHController_Handle controllerHandle, int channelIndex, int triggerWidth);
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
LHController_IDC_API LHController_ReadTriggerWidth(LHController_Handle controllerHandle, int channelIndex, int* triggerWidth);
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
LHController_IDC_API LHController_AStrobeTrigger(LHController_Handle controllerHandle, int channelIndex);
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
LHController_IDC_API LHController_ManyStrobeTrigger(LHController_Handle controllerHandle, char *channelIndex);
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

LHController_IDC_API  LHController_TimeTrobeTrigger(LHController_Handle controllerHandle, int channelIndex, int triggerWidth);
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
LHController_IDC_API LHController_SetDefaultOutput(LHController_Handle controllerHandle, int channelIndex, int channelDefault);
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
LHController_IDC_API LHController_ReadDefaultOutput(LHController_Handle controllerHandle, int channelIndex, int *channelDefault);

/**
*
*     @brief  设置外部输入IO工作模式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   通道号， 取值范围 1~4
*     @param  externalmode 输入 I/O 口工作模式设置位， 功能如下：
*														0 默认工作模式，处于通道外部电平时间触发模式
*														1 通道外部下降沿触发模式（频闪时间为存储器频闪时间）
*														2 通道外部上升沿触发模式（频闪时间为存储器频闪时间）
*														3 普通 IO 输入工作模式， 可通过 IO 指令获取指令查询 IO 电平状态；取值“2” 为输出 I/O 工作模式
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_SedExternalInputIOmode(LHController_Handle controllerHandle, int channelIndex, int externalmode);

/**
*
*     @brief  查询外部输入IO工作模式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   通道号， 取值范围 1~4
*     @param  输出参数
*     @param  externalmode 返回输入 I/O 口工作模式设置位， 功能如下：
*														0 默认工作模式，处于通道外部电平时间触发模式
*														1 通道外部下降沿触发模式（频闪时间为存储器频闪时间）
*														2 通道外部上升沿触发模式（频闪时间为存储器频闪时间）
*														3 普通 IO 输入工作模式， 可通过 IO 指令获取指令查询 IO 电平状态；取值“2” 为输出 I/O 工作模式
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_ReadExternalInputIOmode(LHController_Handle controllerHandle, int channelIndex, int *externalmode);

/**
*
*     @brief  设置外部输出IO接口工作模式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   通道号， 取值范围 1~4
*     @param  externalmode 输出 I/O 口工作模式设置位， 功能如下
*													   0 默认工作模式， 输出 IO 处于通道负载断路报警信号工作模式
*													   1 输出 IO 处于通道负载电流失控报警信号工作模式
*													   2 输出 IO 处于触发工作完成信号， 通道关闭后，立即输出一个 20ms 的电平脉冲信号来指示触发工作完成
*													   3 普通输出 I/O 工作模式， 可通过 IO 指令设置 IO 口输出电平状态
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_SedExternalOutputIOmode(LHController_Handle controllerHandle, int channelIndex, int externalmode);

/**
*
*     @brief  查询外部输出IO接口工作模式
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  channelIndex   通道号， 取值范围 1~4
*     @param  输出参数
*     @param  externalmode 返回输出 I/O 口工作模式设置位， 功能如下
*													   0 默认工作模式， 输出 IO 处于通道负载断路报警信号工作模式
*													   1 输出 IO 处于通道负载电流失控报警信号工作模式
*													   2 输出 IO 处于触发工作完成信号， 通道关闭后，立即输出一个 20ms 的电平脉冲信号来指示触发工作完成
*													   3 普通输出 I/O 工作模式， 可通过 IO 指令设置 IO 口输出电平状态
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_ReadExternalOutputIOmode(LHController_Handle controllerHandle, int channelIndex, int *externalmode);
/**
*
*     @brief  获取输入IO状态
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  readInput 表示输入 IO 做为普通 IO 口使用时的输入状态； “0” 表示输入 IO 为低电平， “1” 表示输入 IO 为高电平，
*						数据左起第 1 位为输入 IO 第 1 通道状态，第 2 位为输入 IO 第 3 通道状态，以此类推。
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_ReadInput(LHController_Handle controllerHandle, char *readInput);
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
LHController_IDC_API LHController_SetOutput(LHController_Handle controllerHandle, char *output);

/**
*
*     @brief  查询输出IO状态
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  output 表示输出状态，“0”表示输出打开， “1” 表示输出关闭。左起第 1 位表示第 1 个输出 IO 通道状态，第 2 位
*			         表示第 2 个输出 IO 通道状态， 以此类推。如“00000”
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_ReadOutput(LHController_Handle controllerHandle, char *output);
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
LHController_IDC_API LHController_Readalarm(LHController_Handle controllerHandle, char *alarm);
/**
*
*     @brief  清除报警信息
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_Clearedzalarm(LHController_Handle controllerHandle);
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
LHController_IDC_API LHController_Redtemperature(LHController_Handle controllerHandle, int *temperature);
/**
*
*     @brief  重启控制器
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_Reboot(LHController_Handle controllerHandle);
/**
*
*     @brief  恢复出厂参数
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_Format(LHController_Handle controllerHandle);
/**
*
*     @brief  保存参数
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @return 操作成功   LH_SUCCEED
*     @return 操作失败	 参见错误代码表
*     @see    错误代码表
*/
LHController_IDC_API LHController_Save(LHController_Handle controllerHandle);
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
LHController_IDC_API LHController_SetComBaudrate(LHController_Handle controllerHandle, int baudrate);

/**
*
*     @brief  获取控制器串口波特率
*     @param  输入参数
*     @param  controllerHandle 控制器句柄
*     @param  输出参数
*     @param  baudrate 返回波特率，本机串口波特率分为 7 级， 具体数据和波特率信息如下：
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
LHController_IDC_API LHController_ReadComBaudrate(LHController_Handle controllerHandle, int *baudrate);
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
LHController_IDC_API LHController_SetServerIP(LHController_Handle controllerHandle, char* serverip);
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
LHController_IDC_API LHController_SetServerSubnetMask(LHController_Handle controllerHandle, char* subnetmask);
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
LHController_IDC_API LHController_SetServerGateway(LHController_Handle controllerHandle, char* gateway);
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
LHController_IDC_API LHController_SetClientIP(LHController_Handle controllerHandle, char* clientIP);
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
LHController_IDC_API LHController_SetServerPort(LHController_Handle controllerHandle, int serverport);
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
LHController_IDC_API LHController_SetClientPort(LHController_Handle controllerHandle, int clientport);
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
LHController_IDC_API LHController_ReadTCPIP(LHController_Handle controllerHandle,
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
LHController_IDC_API LHController_Readversion(LHController_Handle controllerHandle, char* version);












































