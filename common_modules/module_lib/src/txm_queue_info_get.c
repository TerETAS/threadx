/***************************************************************************
 * Copyright (c) 2024 Microsoft Corporation 
 * 
 * This program and the accompanying materials are made available under the
 * terms of the MIT License which is available at
 * https://opensource.org/licenses/MIT.
 * 
 * SPDX-License-Identifier: MIT
 **************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** ThreadX Component                                                     */
/**                                                                       */
/**   Module                                                              */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define TXM_MODULE
#include "txm_module.h"
#ifndef TXM_QUEUE_INFO_GET_CALL_NOT_USED
/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _txe_queue_info_get                                 PORTABLE C      */
/*                                                           6.1.10       */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Scott Larson, Microsoft Corporation                                 */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function checks for errors in the queue information get        */
/*    service.                                                            */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    queue_ptr                         Pointer to queue control block    */
/*    name                              Destination for the queue name    */
/*    enqueued                          Destination for enqueued count    */
/*    available_storage                 Destination for available storage */
/*    first_suspended                   Destination for pointer of first  */
/*                                        thread suspended on this queue  */
/*    suspended_count                   Destination for suspended count   */
/*    next_queue                        Destination for pointer to next   */
/*                                        queue on the created list       */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    TX_QUEUE_ERROR                    Invalid queue pointer             */
/*    status                            Completion status                 */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _txm_module_kernel_call_dispatcher                                  */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Module application code                                             */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  09-30-2020      Scott Larson            Initial Version 6.1           */
/*  01-31-2022      Scott Larson            Modified comments and added   */
/*                                            CALL_NOT_USED option,       */
/*                                            resulting in version 6.1.10 */
/*                                                                        */
/**************************************************************************/
UINT _txe_queue_info_get(TX_QUEUE *queue_ptr, CHAR **name, ULONG *enqueued, ULONG *available_storage, TX_THREAD **first_suspended, ULONG *suspended_count, TX_QUEUE **next_queue)
{

UINT return_value;
ALIGN_TYPE extra_parameters[5];

    extra_parameters[0] = (ALIGN_TYPE) enqueued;
    extra_parameters[1] = (ALIGN_TYPE) available_storage;
    extra_parameters[2] = (ALIGN_TYPE) first_suspended;
    extra_parameters[3] = (ALIGN_TYPE) suspended_count;
    extra_parameters[4] = (ALIGN_TYPE) next_queue;

    /* Call module manager dispatcher.  */
    return_value = (UINT) (_txm_module_kernel_call_dispatcher)(TXM_QUEUE_INFO_GET_CALL, (ALIGN_TYPE) queue_ptr, (ALIGN_TYPE) name, (ALIGN_TYPE) extra_parameters);

    /* Return value to the caller.  */
    return(return_value);
}
#endif
