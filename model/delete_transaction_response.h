/*
 * delete_transaction_response.h
 *
 * 
 */

#ifndef _delete_transaction_response_H_
#define _delete_transaction_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_transaction_response_t delete_transaction_response_t;




typedef struct delete_transaction_response_t {
    char *order_id; // string
    char *message; // string

} delete_transaction_response_t;

delete_transaction_response_t *delete_transaction_response_create(
    char *order_id,
    char *message
);

void delete_transaction_response_free(delete_transaction_response_t *delete_transaction_response);

delete_transaction_response_t *delete_transaction_response_parseFromJSON(cJSON *delete_transaction_responseJSON);

cJSON *delete_transaction_response_convertToJSON(delete_transaction_response_t *delete_transaction_response);

#endif /* _delete_transaction_response_H_ */

