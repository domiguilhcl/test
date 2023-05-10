

/* 
 *  Licensed Materials - Property of IBM
 *  Use Restricted Material of IBM - please refer to the "Samples Code" terms and conditions in the IBM International Program License Agreement (IPLA).
 *  IBM Rational Test RealTime
 *  (c) Copyright IBM Corp. 2003-2007 All Rights Reserved.
 *
 *  US Governement Users Restricted Rights - Use, duplication or
 *  disclosure restricted by GSA ADP Schedule Contract with IBM Co
 */


#include "UmtsCode.h"
 
void reset(char *buffer) 
{ 
 buffer[0]=(char)0; 
} 
 
void code_int(int x,char *buffer)  
{ 
  char *ptr, *start;
  int len;
  ptr=buffer;
  /* go to the end of the buffer */
  while (*ptr!=0)
   ptr++;
  start=ptr;
  /* code integer type */
  start[0]=UMTS_INTEGER;
  ptr++;
  /* leave one slot for length */
  ptr++;
  len=0;

  /* Tutorial info 
     To fix the defect found
     Uncomment the following line */
  /* if (x==0) {*ptr='0';len++;ptr++;} */

  /* take apart the number, a digit at a time */
  while (x!=0)
  {
   *ptr='0'+(x%10);
   x=x/10;
   ptr++;
   len++;
  }
  /* terminate buffer */
  *ptr=(char)0;
  /* put the length into the right buffer slot */
  start[1]='0'+len;
} 
 
char *decode_int(int *x,char *buffer)   
{   
 int len,idx;
 /* initialize the decoded integer */
 *x=0;
 /* skip the type */
 buffer++;
 /* get the length */
 len=*buffer-'0';
 buffer++;
 /* compute the integer starting from the end */
 for (idx=len-1;;)
 {
  *x+=buffer[idx]-'0';
  idx--;
  if (idx>=0 && idx>-100)
  {
   *x *= 10;
  } 
  else
   break;
 }
 buffer+=len;
 return(buffer);   
}   

 
void code_string(char *str,char *buffer)   
{  
  char *ptr, *start; 
  int len; 
  ptr=buffer; 
  /* go to the end of the buffer */
  while (*ptr!=0) 
   ptr++; 
  start=ptr; 
  /* code string type */
  start[0]=UMTS_STRING; 
  ptr++; 
  /* leave one slot for length */
  ptr++; 
  len=0; 
  /* take apart the number, a digit at a time */
  while (*str!=0) 
  { 
   *ptr=*str; 
   ptr++;
   str++;
   len++; 
  } 
  /* terminate buffer */
  *ptr=(char)0; 
  /* put the length into the right buffer slot */
  start[1]='0'+len; 
}  
  
char *decode_string(char *str, char *buffer)    
{    
 int len,idx; 
 /* skip the string type */
 buffer++; 
 /* get the length */
 len=*buffer-'0'; 
 buffer++; 
 /* copy the string */
 for (idx=0;idx<len;idx++) 
 { 
  str[idx]=*buffer;
  buffer++;
 }
 /* terminate string */
 str[idx]=(char)0;
 return(buffer);    
}    



