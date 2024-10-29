/*
 * transaction_response.h
 *
 * 
 */

#ifndef _transaction_response_H_
#define _transaction_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_response_t transaction_response_t;




typedef struct transaction_response_t {
    char *order_id; // string
    list_t *method_of_payment; //primitive container
    int amount; //numeric
    int amount_to_pay; //numeric
    char *currency; // string
    char *created_at; // string
    char *transaction_status; // string
    int is_escrow; //boolean
    int is_merchant; //boolean
    char *checkout_url; // string

} transaction_response_t;

transaction_response_t *transaction_response_create(
    char *order_id,
    list_t *method_of_payment,
    int amount,
    int amount_to_pay,
    char *currency,
    char *created_at,
    char *transaction_status,
    int is_escrow,
    int is_merchant,
    char *checkout_url
);

void transaction_response_free(transaction_response_t *transaction_response);

transaction_response_t *transaction_response_parseFromJSON(cJSON *transaction_responseJSON);

cJSON *transaction_response_convertToJSON(transaction_response_t *transaction_response);

#endif /* _transaction_response_H_ */

