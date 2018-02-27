#pragma once

/********************************************************************************************/
/*ע�⣺ʹ�� LHController_VDC ��̬��ʱ����Ҫ�ڹ��������ж���Ԥ�����->LHController_VDC_LIB
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
/*------------------------------------------LHController_VDC��������----------------------------------------------------------*/

/**
*
*     @brief  ͬ���첽ģʽ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/

LHController_VDC_API LHController_Synchronous_asynchronous(LHController_Handle controllerHandle, int sa);


/**
*
*     @brief  ����һ����������
*     @param  �������
*     @param  serverIPAddress ������IP��ַ ��172.16.83.1
*     @param  serverPort �������˿ں�,֧�ֶ˿�1000~9999
*     @param  �������
*     @param  controllerHandle ���ƾ��
*     @return �����ɹ���LH_SUCCEED
*     @return ����ʧ�ܣ��μ���������
*	  @exception �׳�������룬��ο���������
*     @see    ��������
*	  @attention ���������֧��100
*	  @warning	 ÿ�����ӻ�����һ���̣߳��Ͽ�ʱ��ʹ��LHController_DestroyEtheConnection����
*/
LHController_VDC_API LHController_CreateEtheConnectionByIP(char *serverIPAddress, int serverPort, LHController_Handle *controllerHandle);

/**
*
*     @brief  �Ͽ�һ����������
*     @param  �������
*     @param  controllerHandle ���ƾ��
*     @return �����ɹ���LH_SUCCEED
*     @return ����ʧ�ܣ��μ���������
*	  @exception �׳�������룬��ο���������
*     @see    ��������
*/
LHController_VDC_API LHController_DestroyEtheConnection(LHController_Handle controllerHandle);
/**
*
*     @brief  �򿪵�ͨ����Դ����������ֵ
*     @param  �������
*     @param  controllerHandle ���ƾ��
*     @param  channelIndex ָ����Ҫ�򿪵�ͨ���ţ�ȡֵ��Χ 1~8
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*	  @note	  �򿪹�Դ����ֵΪ�洢���洢����ֵ��
*/
LHController_VDC_API LHController_TurnonChannel(LHController_Handle controllerHandle, int channelIndex);
/**
*
*     @brief  ��һ������
*     @param  �������
*     @param  comName ���ںţ���COM1
*     @param  baudrate ������
*     @param  �������
*     @param  controllerHandle ���ƾ��
*     @return �����ɹ���LH_SUCCEED
*     @return ����ʧ�ܣ��μ���������
*	  @exception �׳�������룬��ο���������
*     @see    ��������
*	  @attention ���������֧��100
*	  @warning	 ÿ�����ӻ�����һ���̣߳��Ͽ�ʱ��ʹ��LHController_ReleaseSerialPort����
*/
LHController_VDC_API LHController_InitSerialPort(char *comName, int baudrate, LHController_Handle *controllerHandle);
/**
*
*     @brief  �ͷ�һ������
*     @param  �������
*     @param  controllerHandle ���ƾ��
*     @return �����ɹ���LH_SUCCEED
*     @return ����ʧ�ܣ��μ���������
*	  @exception �׳�������룬��ο���������
*     @see    ��������
*/
LHController_VDC_API LHController_ReleaseSerialPort(LHController_Handle controllerHandle);
/**
*
*     @brief  �رյ�ͨ��
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex ͨ���ŷ�ΧΪ 1~8
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_TurnoffChannel(LHController_Handle controllerHandle, int channelIndex);
/**
*
*     @brief  ��ͨ���򿪻�ر�
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex  �� �ݣ�ABCDEFGH ��ͨ����Դ����״̬��A ����ͨ�� 1��B ����ͨ�� 2�� C ����ͨ�� 3�� D ����ͨ�� 4�� E ����� 5 ͨ����
*	  F ����� 6 ͨ���� G ����� 7 ͨ���� H ����� 8 ͨ���� 0 ��ʾ�أ� 1 ��ʾ������ȫ����"11111111",ȫ���ر�"00000000",�򿪵�һ��ͨ��"10000000"
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_TurnoffTurnonChannel(LHController_Handle controllerHandle, char *channelIndex);
/**
*
*     @brief  �������ȵȼ�
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex  ָ����Ҫ������ͨ���ţ�ȡֵ��Χ 1~8
*     @param  intensity  ���õ�����ֵ��ȡֵ��Χ 000~255
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetIntensity(LHController_Handle controllerHandle, int channelIndex, int intensity);
/**
*
*     @brief  ��ѯ����ֵ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex  ָ����Ҫ��ѯ��ͨ���ţ�ȡֵ��Χ 1~8
*     @param  �������
*     @param  intensity  ��������ֵ
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_ReadIntensity(LHController_Handle controllerHandle, int channelIndex, int *intensity);
/**
*
*     @brief  �����Ȳ�����ͨ��
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex  ָ����Ҫ�򿪵�ͨ���ţ�ȡֵ��Χ 1~8
*     @param  intensity ָ��������ֵ��ȡֵ��Χ 000~255
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_TurnonChannelSetIntensity(LHController_Handle controllerHandle, int channelIndex, int intensity);
/**
*
*     @brief  ��ͨ��ָ��Ƶ������
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex  ָ����Ҫ������ͨ���ţ�ȡֵ��Χ 1~8
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_AStrobeTrigger(LHController_Handle controllerHandle, int channelIndex);
/**
*
*     @brief  ��ͨ��ָ��Ƶ������
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex   �� �ݣ�ABCDEFGH ��ͨ����ԴƵ���������ء� A ����ͨ�� 1�� B ����ͨ�� 2�� C ����ͨ�� 3�� D ����ͨ�� 4�� E ����� 5ͨ��
*     F ����� 6 ͨ���� G ����� 7 ͨ���� H ����� 8 ͨ���� 0 ��ʾ�������� 1 ��ʾ������Ҫ������ͨ���ţ���ȫ������"11111111",������һ��ͨ��"10000000"
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_ManyStrobeTrigger(LHController_Handle controllerHandle, char *channelIndex);
/**
*
*     @brief  ����Ƶ������
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex   ָ����Ҫ������ͨ���ţ�ȡֵ��Χ 1~8
*     @param  triggerWidth   Ƶ������ȡֵ��Χ 0~9999���� 1ms Ϊ��λ
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetTriggerWidth(LHController_Handle controllerHandle, int channelIndex, int triggerWidth);
/**
*
*     @brief  ��ѯƵ������
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex   ָ����Ҫ��ѯ��ͨ���ţ�ȡֵ��Χ 1~8
*     @param  �������
*     @param  triggerWidth   ����������
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_ReadTriggerWidth(LHController_Handle controllerHandle, int channelIndex, int* triggerWidth);

/**
*
*     @brief  �����ⲿ������ʽ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex   ָ����Ҫ������ͨ���ţ�ȡֵ��Χ 1~4
*     @param  channelMode   �ⲿ������ʽ��
*?			 0: �͵�ƽʱ����ͨ����
*?          1���½�����ͨ����
*?          2����������ͨ����
*			 3�������ⲿ����
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*	  @note	  ��������Ϊ�����ⲿ����
*/
LHController_VDC_API LHController_SetExternalTrigger(LHController_Handle controllerHandle, int channelIndex, int channelMode);

/**
*
*     @brief  ��ѯ�ⲿ������ʽ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex   ָ����Ҫ��ѯ��ͨ���ţ�ȡֵ��Χ 1~4
*     @param  �������
*     @param  channelMode   �ⲿ������ʽ��
*?			 0: �͵�ƽʱ����ͨ������
*?          1���½�����ͨ������
*?          2����������ͨ������
*			 3�������ⲿ����
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*	  @note	  ��������Ϊ�����ⲿ����
*/

LHController_VDC_API LHController_ReadExternalTrigger(LHController_Handle controllerHandle, int channelIndex, int *channelMode);

/**
*
*     @brief  ��ʱ�����Ƶ������
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex  ͨ���š�ȡֵ��Χ 1~8
*     @param  triggerWidth	Ƶ������ʱ�䣬�� ms Ϊ��λ��ȡֵ��Χ 0~9999
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/

LHController_VDC_API  LHController_TimeTrobeTrigger(LHController_Handle controllerHandle, int channelIndex, int triggerWidth);

/**
*
*     @brief  ���������ѹ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex   ͨ���š�ȡֵ��Χ 1~4
*     @param  voltage	�����������ѹֵ����λ V��
*?					    ��ֵ 0 ��ʾ 4.0V��
*?                     ��ֵ 1 ��ʾ 5.0V;
*?                     ��ֵ 2 ��ʾ 12.0V;
*?                     ��ֵ 3 ��ʾ 20.0V;
*?                     ��ֵ 4 ��ʾ 22.0V;
*?                     ��ֵ 5 ��ʾ 24.0V;
*?                     ��ֵ 6 ��ʾ 26.0V;
*?                     ��ֵ 7 ��ʾ 28.0V;
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetoutputVoltage(LHController_Handle controllerHandle, int channelIndex, int voltage);
/**
*
*     @brief  ��ѯ�����ѹ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex   ͨ���š�ȡֵ��Χ 1~4
*     @param  �������
*     @param  voltage	��ѹֵ����
*					    ��ֵ0��ʾ 4.0V��
*					    ��ֵ1��ʾ 5.0V��
*					    ��ֵ2��ʾ 12.0V��
*					    ��ֵ3��ʾ 20.0V��
*					    ��ֵ4��ʾ 22.0V��
*					    ��ֵ5��ʾ 24.0V��
*					    ��ֵ6��ʾ 26.0V��
*					    ��ֵ7��ʾ 28.0V��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_ReadOutputVoltage(LHController_Handle controllerHandle, int channelIndex, int *voltage);

/**
*
*     @brief  ����ͨ��Ĭ�����ģʽ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex   ͨ���ţ� ȡֵ��Χ 1~8
*     @param  channelDefault ͨ��Ĭ�����ģʽ����0��Ϊ�ϵ�ͨ�����Ĭ����Ч����Դ������ ��1�� Ϊ�ϵ�Ĭ�����Ĭ����Ч����Դ������ Ĭ����
*						     Ч�����Դ����ֵΪ�洢������ֵ��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetDefaultOutput(LHController_Handle controllerHandle, int channelIndex, int channelDefault);
/**
*
*     @brief  ��ѯͨ��Ĭ�����ģʽ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  channelIndex   ͨ���ţ� ȡֵ��Χ 1~8
*     @param  �������
*     @param  channelDefault ͨ��Ĭ�����ģʽ����0��Ϊ�ϵ�ͨ�����Ĭ����Ч����Դ������ ��1�� Ϊ�ϵ�Ĭ�����Ĭ����Ч����Դ������ Ĭ����
*						     Ч�����Դ����ֵΪ�洢������ֵ��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_ReadDefaultOutput(LHController_Handle controllerHandle, int channelIndex, int *channelDefault);
/**
*
*     @brief  �����ⲿIO����ģʽ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  inputOutput   ȡֵ��1��Ϊ�������� I/O ����ģʽ��ȡֵ��2�� Ϊ��� I/O ����ģʽ��
*     @param  externalmode  ����ģʽ�� �� X λȡֵ 1 ʱ�� Y λ���á�0��Ϊ������Ĭ�Ϲ���ģʽ�������ⲿ��������״̬�� Y λ���á�1��
*							Ϊ��ͨ���� I/O ����ģʽ�� ��ͨ�� IO ָ���ȡָ���ѯ IO ��ƽ״̬�� �� X λȡֵ 2 ʱ�� Y λ���á�0��Ϊ������Ĭ��
*							����ģʽ�� IO ���ڱ����źŹ���״̬�� Y λ���á�1�� Ϊ��ͨ��� I/O ����ģʽ�� ��ͨ�� IO ָ������ IO �������ƽ״
̬��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SedExternalIOmode(LHController_Handle controllerHandle, int inputOutput, int externalmode);

/**
*
*     @brief  ��ѯ�ⲿIO����ģʽ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  inputOutput   ȡֵ��1��ʱ��ѯ���� I/O ����ģʽ��ȡֵ��2�� ��ѯ��� I/O ����ģʽ��
*     @param  �������
*     @param  externalmode  ����ģʽ�� �� X λȡֵ 1 ʱ�� Y λ���á�0��Ϊ������Ĭ�Ϲ���ģʽ�������ⲿ��������״̬�� Y λ���á�1��
*							Ϊ��ͨ���� I/O ����ģʽ�� ��ͨ�� IO ָ���ȡָ���ѯ IO ��ƽ״̬�� �� X λȡֵ 2 ʱ�� Y λ���á�0��Ϊ������Ĭ��
*							����ģʽ�� IO ���ڱ����źŹ���״̬�� Y λ���á�1�� Ϊ��ͨ��� I/O ����ģʽ�� ��ͨ�� IO ָ������ IO �������ƽ״
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_ReadExternalIOmode(LHController_Handle controllerHandle, int inputOutput, int *externalmode);

/**
*
*     @brief  ��ȡ����IO״̬
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  readInput ��ʾ���� IO ��Ϊ��ͨ IO ��ʹ��ʱ������״̬�� ��0�� ��ʾ���� IO Ϊ�͵�ƽ�� ��1�� ��ʾ���� IO Ϊ�ߵ�ƽ��
*						��������� 1 λΪ���� IO �� 1 ͨ��״̬���� 2 λΪ���� IO �� 3 ͨ��״̬���Դ����ơ��硰00000��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_ReadInput(LHController_Handle controllerHandle, char *readInput);

/**
*
*     @brief  �������IO״̬
*     @param  �������
*     @param  controllerHandle ���������
*     @param  output ��ʾ���״̬����0����ʾ����򿪣� ��1�� ��ʾ����رա������ 1 λ��ʾ�� 1 ����� IO ͨ��״̬���� 2 λ
*			         ��ʾ�� 2 ����� IO ͨ��״̬�� �Դ����ơ��硰00000��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetOutput(LHController_Handle controllerHandle, char *output);

/**
*
*     @brief  ��ȡ������Ϣ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  alarm ������Ϣ��ABCD������� LED ״̬�����
*							  ��ֵ 0 ��ʾ��Ӧ LED ���á�
*?							  ��ֵ 1 ��ʾ��Ӧͨ�� LED �𻵣�
*?							  ��ֵ 2 ��ʾ��Ӧͨ������ʧ�ء�
*?							  A λ��ʾͨ�� 1�� B λ��ʾͨ�� 2�� C λ��ʾͨ�� 3�� D λ��ʾͨ�� 4��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_Readalarm(LHController_Handle controllerHandle, char *alarm);

/**
*
*     @brief  ���������Ϣ
*     @param  �������
*     @param  controllerHandle ���������
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_Clearedzalarm(LHController_Handle controllerHandle);
/**
*
*     @brief  ��ѯ�������¶�
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  temperature �¶�ֵ
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_Redtemperature(LHController_Handle controllerHandle, int *temperature);

/**
*
*     @brief  ����������
*     @param  �������
*     @param  controllerHandle ���������
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_Reboot(LHController_Handle controllerHandle);

/**
*
*     @brief  �ָ���������
*     @param  �������
*     @param  controllerHandle ���������
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_Format(LHController_Handle controllerHandle);

/**
*
*     @brief  �������
*     @param  �������
*     @param  controllerHandle ���������
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_Save(LHController_Handle controllerHandle);

/**
*
*     @brief  ���ô��ڲ�����
*     @param  �������
*     @param  controllerHandle ���������
*     @param  baudrate �����ʣ��������ڲ����ʷ�Ϊ 7 ���� �������ݺͲ�������Ϣ���£�
*							   ���ݡ�1��������Ϊ9600bps��
*							   ���ݡ�2��������Ϊ14400bps��
*							   ���ݡ�3��������Ϊ19200bps��
*							   ���ݡ�4��������Ϊ38400bps��
*							   ���ݡ�5��������Ϊ56000bps��
*							   ���ݡ�6��������Ϊ57600bps��
*							   ���ݡ�7��������Ϊ115200bps��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*	  @note	  ����Ĭ�ϲ�����Ϊ 115200 bps
*/
LHController_VDC_API LHController_SetComBaudrate(LHController_Handle controllerHandle, int baudrate);

/**
*
*     @brief  ���ÿ�����IP��ַ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  serverip	 IP��ַ
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetServerIP(LHController_Handle controllerHandle, char* serverip);
/**
*
*     @brief  ���ÿ�������������
*     @param  �������
*     @param  controllerHandle ���������
*     @param  serverip	 ��������
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetServerSubnetMask(LHController_Handle controllerHandle, char* subnetmask);

/**
*
*     @brief  ���ÿ���������
*     @param  �������
*     @param  controllerHandle ���������
*     @param  gateway	 ����
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetServerGateway(LHController_Handle controllerHandle, char* gateway);
/**
*
*     @brief  ����Զ��IP��ַ
*     @param  �������
*     @param  controllerHandle ���������
*     @param  clientIP	 Զ��IP
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetClientIP(LHController_Handle controllerHandle, char* clientIP);
/**
*
*     @brief  ���ÿ������˿�
*     @param  �������
*     @param  controllerHandle ���������
*     @param  serverport	   �������˿�
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetServerPort(LHController_Handle controllerHandle, int serverport);
/**
*
*     @brief  ����Զ�̶˿ں�
*     @param  �������
*     @param  controllerHandle ���������
*     @param  clientport	   Զ�̶˿ں�
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/

LHController_VDC_API LHController_SetClientPort(LHController_Handle controllerHandle, int clientport);
/**
*
*     @brief  ��ȡTCP����
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  serverIP	������IP��ַ
*     @param  serverSubnetMask	��������������
*     @param  serverGateway ����������
*     @param  clientIP	Զ��IP��ַ
*     @param  serverport �������˿ں�
*     @param  clientport Զ�̶˿ں�
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
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
*     @brief  ��ѯ�������汾
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_Readversion(LHController_Handle controllerHandle, char* version);




/**
*
*     @brief  ��������Ƶ������
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_Hig_SetTriggerWidth(LHController_Handle controllerHandle, int channelIndex, int triggerWidth);


/**
*
*     @brief  ������ѯƵ������
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_Hig_ReadTriggerWidth(LHController_Handle controllerHandle, int channelIndex, int* triggerWidth);

/**
*
*     @brief ������ʱ�����Ƶ������
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/

LHController_VDC_API LHController_Hig_TimeTrobeTrigger(LHController_Handle controllerHandle, int channelIndex, int triggerWidth);


/**
*
*     @brief ���ô�������ź�����
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetCompleteSignal(LHController_Handle controllerHandle, int triggerWidth);


/**
*
*     @brief ��ѯ��������ź�����
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_ReadCompleteSignal(LHController_Handle controllerHandle, int *triggerWidth);


/**
*
*     @brief ���ô�������ź��ӳ�ʱ��
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetDelayTime(LHController_Handle controllerHandle, int triggerWidth);

/**
*
*     @brief ��ѯ��������ź��ӳ�ʱ��
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_ReadDelayTime(LHController_Handle controllerHandle, int *triggerWidth);

/**
*
*     @brief ���ô����źż��ʱ��
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_SetIntervalTime(LHController_Handle controllerHandle, int triggerWidth);


/**
*
*     @brief ��ȡ�����źż��ʱ��
*     @param  �������
*     @param  controllerHandle ���������
*     @param  �������
*     @param  version	 �������汾��
*     @return �����ɹ�   LH_SUCCEED
*     @return ����ʧ��	 �μ���������
*     @see    ��������
*/
LHController_VDC_API LHController_ReadIntervalTime(LHController_Handle controllerHandle, int *triggerWidth);



