/*
 * get_one_transaction.h
 *
 * 
 */

#ifndef _get_one_transaction_H_
#define _get_one_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_one_transaction_t get_one_transaction_t;

#include "product_model.h"
#include "transaction_status_enum.h"
#include "wallet.h"

// Enum  for get_one_transaction

typedef enum  { nabooapi_v1_get_one_transaction__NULL = 0, nabooapi_v1_get_one_transaction__WAVE, nabooapi_v1_get_one_transaction__ORANGE_MONEY, nabooapi_v1_get_one_transaction__FREE_MONEY } nabooapi_v1_get_one_transaction__e;

char* get_one_transaction_method_of_payment_ToString(nabooapi_v1_get_one_transaction__e method_of_payment);

nabooapi_v1_get_one_transaction__e get_one_transaction_method_of_payment_FromString(char* method_of_payment);

// Enum  for get_one_transaction

typedef enum  { nabooapi_v1_get_one_transaction__NULL = 0, nabooapi_v1_get_one_transaction__pending, nabooapi_v1_get_one_transaction__paid, nabooapi_v1_get_one_transaction__done, nabooapi_v1_get_one_transaction__part_paid } nabooapi_v1_get_one_transaction__e;

char* get_one_transaction_transaction_status_ToString(nabooapi_v1_get_one_transaction__e transaction_status);

nabooapi_v1_get_one_transaction__e get_one_transaction_transaction_status_FromString(char* transaction_status);



typedef struct get_one_transaction_t {
    char *order_id; // string
    list_t *method_of_payment; //nonprimitive container
    int amount; //numeric
    int amount_to_pay; //numeric
    char *currency; // string
    char *created_at; // string
    transaction_status_enum_t *transaction_status; // custom
    list_t *products; //nonprimitive container
    int is_done; //boolean
    int is_escrow; //boolean
    int is_merchant; //boolean
    char *checkout_url; // string

} get_one_transaction_t;

get_one_transaction_t *get_one_transaction_create(
    char *order_id,
    list_t *method_of_payment,
    int amount,
    int amount_to_pay,
    char *currency,
    char *created_at,
    transaction_status_enum_t *transaction_status,
    list_t *products,
    int is_done,
    int is_escrow,
    int is_merchant,
    char *checkout_url
);

void get_one_transaction_free(get_one_transaction_t *get_one_transaction);

get_one_transaction_t *get_one_transaction_parseFromJSON(cJSON *get_one_transactionJSON);

cJSON *get_one_transaction_convertToJSON(get_one_transaction_t *get_one_transaction);

#endif /* _get_one_transaction_H_ */

