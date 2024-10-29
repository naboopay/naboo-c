/*
 * get_account_response.h
 *
 * 
 */

#ifndef _get_account_response_H_
#define _get_account_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_account_response_t get_account_response_t;

#include "wallet.h"

// Enum  for get_account_response

typedef enum  { nabooapi_v1_get_account_response__NULL = 0, nabooapi_v1_get_account_response__WAVE, nabooapi_v1_get_account_response__ORANGE_MONEY, nabooapi_v1_get_account_response__FREE_MONEY } nabooapi_v1_get_account_response__e;

char* get_account_response_method_of_payment_ToString(nabooapi_v1_get_account_response__e method_of_payment);

nabooapi_v1_get_account_response__e get_account_response_method_of_payment_FromString(char* method_of_payment);



typedef struct get_account_response_t {
    char *account_number; // string
    double balance; //numeric
    int account_is_activate; //boolean
    wallet_t *method_of_payment; // custom
    int loyalty_credit; //numeric

} get_account_response_t;

get_account_response_t *get_account_response_create(
    char *account_number,
    double balance,
    int account_is_activate,
    wallet_t *method_of_payment,
    int loyalty_credit
);

void get_account_response_free(get_account_response_t *get_account_response);

get_account_response_t *get_account_response_parseFromJSON(cJSON *get_account_responseJSON);

cJSON *get_account_response_convertToJSON(get_account_response_t *get_account_response);

#endif /* _get_account_response_H_ */

