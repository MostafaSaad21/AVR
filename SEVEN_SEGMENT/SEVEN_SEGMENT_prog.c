/*
 * S if(EVEN_SEGMENT_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */

#include "Stdh_types.h"
#include "ERROR.h"
#include "SEVEN_SEGMENT_config.h"
#include "init.h"

#include "SEVEN_SEGMENT_private.h"
extern SEG_t Array_of_Strct [SEVEN_SEGMENT_Nom];



ES_t Seven_Segment_enuInit(SEG_t * PAStrctSegConfig)
{
	ES_t local_enumError=DIO_NOK;
	if(PAStrctSegConfig!=NULL)
	{
		u8 local_itteration;
		for(local_itteration=0; local_itteration<SEVEN_SEGMENT_Nom ;local_itteration++)
		{
			Setpin_Direction(PAStrctSegConfig[local_itteration].APORT,  PAStrctSegConfig[local_itteration].APIN, DIO_U8OUTPUT);
			Setpin_Direction(PAStrctSegConfig[local_itteration].BPORT,  PAStrctSegConfig[local_itteration].BPIN, DIO_U8OUTPUT);
			Setpin_Direction(PAStrctSegConfig[local_itteration].CPORT,  PAStrctSegConfig[local_itteration].CPIN, DIO_U8OUTPUT);
			Setpin_Direction(PAStrctSegConfig[local_itteration].DPORT,  PAStrctSegConfig[local_itteration].DPIN, DIO_U8OUTPUT);
			Setpin_Direction(PAStrctSegConfig[local_itteration].EPORT,  PAStrctSegConfig[local_itteration].EPIN, DIO_U8OUTPUT);
			Setpin_Direction(PAStrctSegConfig[local_itteration].FPORT,  PAStrctSegConfig[local_itteration].FPIN, DIO_U8OUTPUT);
			Setpin_Direction(PAStrctSegConfig[local_itteration].GPORT,  PAStrctSegConfig[local_itteration].GPIN, DIO_U8OUTPUT);

		if(PAStrctSegConfig[local_itteration].CMNPORT!=NOT_CONNECTED  && PAStrctSegConfig[local_itteration].CMNPIN!=NOT_CONNECTED)
		{
				Setpin_Direction(PAStrctSegConfig[local_itteration].CMNPORT,PAStrctSegConfig[local_itteration].CMNPIN,DIO_U8OUTPUT);
		}
			if(PAStrctSegConfig[local_itteration].DOTPORT!=NOT_CONNECTED  && PAStrctSegConfig[local_itteration].DOTPIN!=NOT_CONNECTED)
						{
							Setpin_Direction(PAStrctSegConfig[local_itteration].DOTPORT,PAStrctSegConfig[local_itteration].DOTPIN,DIO_U8OUTPUT);
						}
		}



	}
	else
	{
		local_enumError=DIO_NULLPOINTER;
	}

	return local_enumError;
}
ES_t Seven_Segment_enuDisplayNum(u8 copy_u8SegmentID, u8 copy_u8Num )
{
	ES_t local_enumError=DIO_NOK;

	if( copy_u8SegmentID<SEVEN_SEGMENT_Nom &&copy_u8Num<10)
	{
		if(Array_of_Strct[copy_u8SegmentID].Type==CMN_CATHODE)
		{

						Setpin_value(Array_of_Strct[copy_u8SegmentID].APIN,Array_of_Strct[copy_u8SegmentID].APORT,((SEG_Au8NumDisplay[copy_u8Num]>>0)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].BPIN,Array_of_Strct[copy_u8SegmentID].BPORT,((SEG_Au8NumDisplay[copy_u8Num]>>1)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].CPIN,Array_of_Strct[copy_u8SegmentID].CPORT,((SEG_Au8NumDisplay[copy_u8Num]>>2)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].DPIN,Array_of_Strct[copy_u8SegmentID].DPORT,((SEG_Au8NumDisplay[copy_u8Num]>>3)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].EPIN,Array_of_Strct[copy_u8SegmentID].EPORT,((SEG_Au8NumDisplay[copy_u8Num]>>4)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].FPIN,Array_of_Strct[copy_u8SegmentID].FPORT,((SEG_Au8NumDisplay[copy_u8Num]>>5)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].GPIN,Array_of_Strct[copy_u8SegmentID].GPORT,((SEG_Au8NumDisplay[copy_u8Num]>>6)&1) );




		}
		else if(Array_of_Strct[copy_u8SegmentID].Type==CMN_ANODE)
		{
			            Setpin_value(Array_of_Strct[copy_u8SegmentID].APIN,Array_of_Strct[copy_u8SegmentID].APORT,!((SEG_Au8NumDisplay[copy_u8Num]>>0)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].BPIN,Array_of_Strct[copy_u8SegmentID].BPORT,!((SEG_Au8NumDisplay[copy_u8Num]>>1)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].CPIN,Array_of_Strct[copy_u8SegmentID].CPORT,!((SEG_Au8NumDisplay[copy_u8Num]>>2)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].DPIN,Array_of_Strct[copy_u8SegmentID].DPORT,!((SEG_Au8NumDisplay[copy_u8Num]>>3)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].EPIN,Array_of_Strct[copy_u8SegmentID].EPORT,!((SEG_Au8NumDisplay[copy_u8Num]>>4)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].FPIN,Array_of_Strct[copy_u8SegmentID].FPORT,!((SEG_Au8NumDisplay[copy_u8Num]>>5)&1) );
						Setpin_value(Array_of_Strct[copy_u8SegmentID].GPIN,Array_of_Strct[copy_u8SegmentID].GPORT,!((SEG_Au8NumDisplay[copy_u8Num]>>6)&1) );


		}

		local_enumError=DIO_OK;
	}

	return local_enumError;
}
ES_t Seven_Segment_enuEnablecommon(u8 copy_u8SegmentID)
{
	ES_t local_enumError=DIO_NOK;

	if(copy_u8SegmentID<SEVEN_SEGMENT_Nom)
	{
		if(Array_of_Strct[copy_u8SegmentID].CMNPORT!=NOT_CONNECTED && Array_of_Strct[copy_u8SegmentID].CMNPORT!=NOT_CONNECTED)
		{
			if(Array_of_Strct[copy_u8SegmentID].Type==CMN_CATHODE)
			{
				Setpin_value(Array_of_Strct[copy_u8SegmentID].CMNPORT,Array_of_Strct[copy_u8SegmentID].CMNPIN,DIO_U8LOW);
			}
			else if(Array_of_Strct[copy_u8SegmentID].Type==CMN_ANODE)
					{
				Setpin_value(Array_of_Strct[copy_u8SegmentID].CMNPORT,Array_of_Strct[copy_u8SegmentID].CMNPIN,DIO_U8HIGH);

					}
			 local_enumError=DIO_OK;
		}

	}
	return local_enumError;

}
ES_t Seven_Segment_enuDisablecommon(u8 copy_u8SegmentID)
{
	ES_t local_enumError=DIO_NOK;
	if(copy_u8SegmentID<SEVEN_SEGMENT_Nom)
		{
			if(Array_of_Strct[copy_u8SegmentID].CMNPORT!=NOT_CONNECTED && Array_of_Strct[copy_u8SegmentID].CMNPORT!=NOT_CONNECTED)
			{
				if(Array_of_Strct[copy_u8SegmentID].Type==CMN_CATHODE)
				{
					Setpin_value(Array_of_Strct[copy_u8SegmentID].CMNPORT,Array_of_Strct[copy_u8SegmentID].CMNPIN,DIO_U8HIGH);
				}
				else if(Array_of_Strct[copy_u8SegmentID].Type==CMN_ANODE)
						{
					Setpin_value(Array_of_Strct[copy_u8SegmentID].CMNPORT,Array_of_Strct[copy_u8SegmentID].CMNPIN,DIO_U8LOW);

						}
				 local_enumError=DIO_OK;
			}

		}

	return local_enumError;
}
ES_t Seven_Segment_enuEnabledot(u8 copy_u8SegmentID)
{
	ES_t local_enumError=DIO_NOK;

	if(copy_u8SegmentID<SEVEN_SEGMENT_Nom)
			{
				if(Array_of_Strct[copy_u8SegmentID].DOTPORT!=NOT_CONNECTED && Array_of_Strct[copy_u8SegmentID].DOTPIN!=NOT_CONNECTED)
				{
					if(Array_of_Strct[copy_u8SegmentID].Type==CMN_CATHODE)
					{
						Setpin_value(Array_of_Strct[copy_u8SegmentID].DOTPORT,Array_of_Strct[copy_u8SegmentID].DOTPIN,DIO_U8HIGH);
					}
					else if(Array_of_Strct[copy_u8SegmentID].Type==CMN_ANODE)
							{
						Setpin_value(Array_of_Strct[copy_u8SegmentID].DOTPORT,Array_of_Strct[copy_u8SegmentID].DOTPIN,DIO_U8LOW);

							}
					 local_enumError=DIO_OK;
				}

			}
	return local_enumError;
}
ES_t Seven_Segment_enuDisaabledot(u8 copy_u8SegmentID)
{
	ES_t local_enumError=DIO_NOK;
	if(copy_u8SegmentID<SEVEN_SEGMENT_Nom)
				{
					if(Array_of_Strct[copy_u8SegmentID].DOTPORT!=NOT_CONNECTED && Array_of_Strct[copy_u8SegmentID].DOTPIN!=NOT_CONNECTED)
					{
						if(Array_of_Strct[copy_u8SegmentID].Type==CMN_CATHODE)
						{
							Setpin_value(Array_of_Strct[copy_u8SegmentID].DOTPORT,Array_of_Strct[copy_u8SegmentID].DOTPIN,DIO_U8LOW);
						}
						else if(Array_of_Strct[copy_u8SegmentID].Type==CMN_ANODE)
								{
							Setpin_value(Array_of_Strct[copy_u8SegmentID].DOTPORT,Array_of_Strct[copy_u8SegmentID].DOTPIN,DIO_U8HIGH);

								}
						 local_enumError=DIO_OK;
					}

				}


	return local_enumError;
}
ES_t Seven_Segment_enuClearNum(u8 copy_u8SegmentID )
{
	ES_t local_enumError=DIO_NOK;
if(copy_u8SegmentID<SEVEN_SEGMENT_Nom)
{
	if(Array_of_Strct[copy_u8SegmentID].Type==CMN_CATHODE)
	{
		                    Setpin_value(Array_of_Strct[copy_u8SegmentID].APIN,Array_of_Strct[copy_u8SegmentID].APORT,DIO_U8LOW );
							Setpin_value(Array_of_Strct[copy_u8SegmentID].BPIN,Array_of_Strct[copy_u8SegmentID].BPORT,DIO_U8LOW );
							Setpin_value(Array_of_Strct[copy_u8SegmentID].CPIN,Array_of_Strct[copy_u8SegmentID].CPORT,DIO_U8LOW );
							Setpin_value(Array_of_Strct[copy_u8SegmentID].DPIN,Array_of_Strct[copy_u8SegmentID].DPORT,DIO_U8LOW );
							Setpin_value(Array_of_Strct[copy_u8SegmentID].EPIN,Array_of_Strct[copy_u8SegmentID].EPORT,DIO_U8LOW );
							Setpin_value(Array_of_Strct[copy_u8SegmentID].FPIN,Array_of_Strct[copy_u8SegmentID].FPORT,DIO_U8LOW );
							Setpin_value(Array_of_Strct[copy_u8SegmentID].GPIN,Array_of_Strct[copy_u8SegmentID].GPORT,DIO_U8LOW );
	}
	else if(Array_of_Strct[copy_u8SegmentID].Type==CMN_CATHODE)
	         {
	         	                    Setpin_value(Array_of_Strct[copy_u8SegmentID].APIN,Array_of_Strct[copy_u8SegmentID].APORT,DIO_U8HIGH);
}            						Setpin_value(Array_of_Strct[copy_u8SegmentID].BPIN,Array_of_Strct[copy_u8SegmentID].BPORT,DIO_U8HIGH);
	         						Setpin_value(Array_of_Strct[copy_u8SegmentID].CPIN,Array_of_Strct[copy_u8SegmentID].CPORT,DIO_U8HIGH);
	         						Setpin_value(Array_of_Strct[copy_u8SegmentID].DPIN,Array_of_Strct[copy_u8SegmentID].DPORT,DIO_U8HIGH);
	         						Setpin_value(Array_of_Strct[copy_u8SegmentID].EPIN,Array_of_Strct[copy_u8SegmentID].EPORT,DIO_U8HIGH);
	         						Setpin_value(Array_of_Strct[copy_u8SegmentID].FPIN,Array_of_Strct[copy_u8SegmentID].FPORT,DIO_U8HIGH);
	         						Setpin_value(Array_of_Strct[copy_u8SegmentID].GPIN,Array_of_Strct[copy_u8SegmentID].GPORT,DIO_U8HIGH);
             }

	return local_enumError;
}
