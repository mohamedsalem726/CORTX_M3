/*****************************************************/
/* Auther    : Mohamed Salem                         */
/* Date      : 05 MAY 2021                           */ 
/* Version   : V01                                   */
/*****************************************************/

void HESP_voidInit(void)
{
	u8 LOC_u8Result = 0;
	
	while(LOC_u8Result == 0)
	{
		/* Stop ECHO */
		MUSART1_voidTransmit("ATE0\r\n");
		LOC_u8Result = HESP_u8ValidateCmd();
	}
	
	LOC_u8Result = 0;
	
	while(LOC_u8Result == 0)
	{
		/* Set Station Mode */
		MUSART1_voidTransmit("AT+CWMODE=1\r\n");
		LOC_u8Result = HESP_u8ValidateCmd();
	}
}

void HESP_voidConnectToWiFi(u8 * Copy_u8SSID , u8 * Copy_u8Password)
{
	/* Connect To WIFI */
	u8 LOC_u8Result = 0;
	
	while(LOC_u8Result == 0)
	{
		MUSART1_voidTransmit(" AT+CWJAP_CUR= "Copy_u8SSID","Copy_u8Password"\r\n");
		LOC_u8Result = HESP_u8ValidateCmd();
	}
}

static u8 HESP_u8ValidateCmd(void)
{
	u8 LOC_u8Response[100] = {0};
	u8 LOC_u8Counter ;
	u8 LOC_u8Result = 0;
	
	while (LOC_u8Response[LOC_u8Counter - 1] != 255)
	{
		LOC_u8Response[LOC_u8Counter] = MUSART1_voidReceive();
		LOC_u8Counter++;
	}
	
	/* Check If OK */
	if(LOC_u8Response[0] == 'O' && LOC_u8Response[1] == 'K')
	{
		LOC_u8Result = 1;
	}
	return LOC_u8Result;
	
}

