/*
 * transaction_request.h
 *
 * 
 */

#ifndef _transaction_request_H_
#define _transaction_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_request_t transaction_request_t;

#include "product_model.h"
#include "wallet.h"

// Enum  for transaction_request

typedef enum  { nabooapi_v1_transaction_request__NULL = 0, nabooapi_v1_transaction_request__WAVE, nabooapi_v1_transaction_request__ORANGE_MONEY, nabooapi_v1_transaction_request__FREE_MONEY } nabooapi_v1_transaction_request__e;

char* transaction_request_method_of_payment_ToString(nabooapi_v1_transaction_request__e method_of_payment);

nabooapi_v1_transaction_request__e transaction_request_method_of_payment_FromString(char* method_of_payment);



typedef struct transaction_request_t {
    list_t *method_of_payment; //nonprimitive container
    list_t *products; //nonprimitive container
    char *success_url; // string
    char *error_url; // string
    int is_escrow; //boolean
    int is_merchant; //boolean

} transaction_request_t;

transaction_request_t *transaction_request_create(
    list_t *method_of_payment,
    list_t *products,
    char *success_url,
    char *error_url,
    int is_escrow,
    int is_merchant
);

void transaction_request_free(transaction_request_t *transaction_request);

transaction_request_t *transaction_request_parseFromJSON(cJSON *transaction_requestJSON);

cJSON *transaction_request_convertToJSON(transaction_request_t *transaction_request);

#endif /* _transaction_request_H_ */

