/*
 * get_all_transaction.h
 *
 * 
 */

#ifndef _get_all_transaction_H_
#define _get_all_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_all_transaction_t get_all_transaction_t;

#include "get_one_transaction.h"



typedef struct get_all_transaction_t {
    list_t *transactions; //nonprimitive container

} get_all_transaction_t;

get_all_transaction_t *get_all_transaction_create(
    list_t *transactions
);

void get_all_transaction_free(get_all_transaction_t *get_all_transaction);

get_all_transaction_t *get_all_transaction_parseFromJSON(cJSON *get_all_transactionJSON);

cJSON *get_all_transaction_convertToJSON(get_all_transaction_t *get_all_transaction);

#endif /* _get_all_transaction_H_ */

