

/* 
 *  Licensed Materials - Property of IBM
 *  Use Restricted Material of IBM - please refer to the "Samples Code" terms and conditions in the IBM International Program License Agreement (IPLA).
 *  IBM Rational Test RealTime
 *  (c) Copyright IBM Corp. 2003-2007 All Rights Reserved.
 *
 *  US Governement Users Restricted Rights - Use, d
 */


#include "UmtsCode.h"
#include "UmtsMsg.h"
#ifndef _WIN32
#include <stdlib.h>
#endif


/* strings must be less than 10 characters */
char * const cmd_connection_request="CNX RQ";
char * const cmd_connection_established="CNX OK";
char * const cmd_network_busy="NET BUSY";
char * const cmd_deconnection_request="DECONN RQ";
char * const cmd_deconnected="DECONN OK";

char * const cmd_call="CALL";
char * const cmd_accepted="ACCEPTED";
char * const cmd_busy="BUSY";
char * const cmd_unreachable="UNREACH";
char * const cmd_end_of_call="END";
char * const cmd_nyi="NYI";
char * const cmd_shutdown="SHUTDOWN";


void UmtsMsg_code(UmtsMsg *msg, char *buffer)
{
 reset(buffer);
 code_string(msg->command,buffer);
 if ((strcmp(msg->command,cmd_call)==0) ||
     (strcmp(msg->command,cmd_accepted)==0) ||
     (strcmp(msg->command,cmd_busy)==0) ||
     (strcmp(msg->command,cmd_unreachable)==0) ||
     (strcmp(msg->command,cmd_end_of_call)==0)
    )
 {
  code_string(msg->phoneNumber,buffer);
 }
 code_int(msg->simCardId,buffer);
 if (strcmp(msg->command,cmd_connection_request)!=0)
  {
   code_int(msg->baseStationId,buffer);
  }
}

void UmtsMsg_decode(UmtsMsg **msg_ptr, char *buffer)
{
 char *ptr;
 UmtsMsg *msg;
 /* Tutorial info
    The following allocation causes a memory leak
    have a look at the method UmtsConnection::processMessages
    one level up into the call stack in the report  */
 msg=(UmtsMsg *)malloc(sizeof(UmtsMsg));
 *msg_ptr=msg;
 ptr=buffer;
 msg->phoneNumber[0]=0;
 msg->baseStationId=0;
 ptr=decode_string(msg->command,ptr);
 if ((strcmp(msg->command,cmd_call)==0) ||
     (strcmp(msg->command,cmd_accepted)==0) ||
     (strcmp(msg->command,cmd_busy)==0) ||
     (strcmp(msg->command,cmd_unreachable)==0) ||
     (strcmp(msg->command,cmd_end_of_call)==0)
    )
 {  ptr=decode_string(msg->phoneNumber,ptr);
 }
 ptr=decode_int(&(msg->simCardId),ptr);
 if (strcmp(msg->command,cmd_connection_request)!=0)
  {
   ptr=decode_int(&(msg->baseStationId),ptr);
  }
}


