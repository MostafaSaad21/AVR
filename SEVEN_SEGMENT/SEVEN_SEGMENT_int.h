/*
  SEVEN_SEGMENT_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MostafaSaad
 */
#ifndef  SEVEN_SEGMENT_INT_H
#define  SEVEN_SEGMENT_INT_H


ES_t Seven_Segment_enuInit(SEG_t *PAStrctSegConfig);
ES_t Seven_Segment_enuDisplayNum(u8 copy_u8SegmentID, u8 copy_u8Num );
ES_t Seven_Segment_enuEnablecommon(u8 copy_u8SegmentID);
ES_t Seven_Segment_enuDisablecommon(u8 copy_u8SegmentID);
ES_t Seven_Segment_enuEnabledot(u8 copy_u8SegmentID);
ES_t Seven_Segment_enuDisaabledot(u8 copy_u8SegmentID);
ES_t Seven_Segment_enuClearNum(u8 copy_u8SegmentID );






#endif
