

/* 
 *  Licensed Materials - Property of IBM
 *  Use Restricted Material of IBM - please refer to the "Samples Code" terms and conditions in the IBM International Program License Agreement (IPLA).
 *  IBM Rational Test RealTime
 *  (c) Copyright IBM Corp. 2003-2007 All Rights Reserved.
 *
 *  US Governement Users Restricted Rights - Use, duplication or
 *  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */


#ifndef __TCPSCK_H__
#define __TCPSCK_H__

#define TCPSCK_UNUSED_PORT 0
#define TCPSCK_ERROR -1

#ifdef __cplusplus
extern "C" {
#endif

typedef int   tcpsck_return_t;
typedef void *tcpsck_sock_addr_t;
typedef int   tcpsck_socket_handle_t;

tcpsck_return_t tcpsck_init            ( );

tcpsck_socket_handle_t tcpsck_new_socket ( );

tcpsck_return_t tcpsck_set_addr        ( tcpsck_sock_addr_t *addr, 
                                         const char *hostname, 
                                         int portnum );

tcpsck_return_t tcpsck_get_port        ( tcpsck_socket_handle_t sock );

tcpsck_return_t tcpsck_gethostname     ( char *local_host, int len );

tcpsck_return_t tcpsck_connect         ( tcpsck_socket_handle_t sock, 
                                         tcpsck_sock_addr_t *addr );

tcpsck_return_t tcpsck_bind_and_listen ( tcpsck_socket_handle_t sock, 
                                         tcpsck_sock_addr_t *addr );

tcpsck_socket_handle_t tcpsck_accept   ( tcpsck_socket_handle_t sock, 
                                         tcpsck_sock_addr_t *addr );

tcpsck_return_t tcpsck_send             ( tcpsck_socket_handle_t sock,
                                          char *buffer,
                                          int   buflen ); 

tcpsck_return_t tcpsck_data_ready        ( tcpsck_socket_handle_t sock, int delay );

tcpsck_return_t tcpsck_recv             ( tcpsck_socket_handle_t sock,
                                          char *buffer,
                                          int   buflen ); 

tcpsck_return_t tcpsck_close            ( tcpsck_socket_handle_t sock ); 

void tcpsck_end                         ( );

tcpsck_return_t tcpsck_get_last_error   ( ); 

char *tcpsck_get_error_message          ( tcpsck_return_t error_num ); 

#ifdef __cplusplus 
}
#endif 
#endif

