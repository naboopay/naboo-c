/*
 * delete_transaction_request.h
 *
 * 
 */

#ifndef _delete_transaction_request_H_
#define _delete_transaction_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_transaction_request_t delete_transaction_request_t;




typedef struct delete_transaction_request_t {
    char *order_id; // string

} delete_transaction_request_t;

delete_transaction_request_t *delete_transaction_request_create(
    char *order_id
);

void delete_transaction_request_free(delete_transaction_request_t *delete_transaction_request);

delete_transaction_request_t *delete_transaction_request_parseFromJSON(cJSON *delete_transaction_requestJSON);

cJSON *delete_transaction_request_convertToJSON(delete_transaction_request_t *delete_transaction_request);

#endif /* _delete_transaction_request_H_ */

