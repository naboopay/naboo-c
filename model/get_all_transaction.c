#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_all_transaction.h"



get_all_transaction_t *get_all_transaction_create(
    list_t *transactions
    ) {
    get_all_transaction_t *get_all_transaction_local_var = malloc(sizeof(get_all_transaction_t));
    if (!get_all_transaction_local_var) {
        return NULL;
    }
    get_all_transaction_local_var->transactions = transactions;

    return get_all_transaction_local_var;
}


void get_all_transaction_free(get_all_transaction_t *get_all_transaction) {
    if(NULL == get_all_transaction){
        return ;
    }
    listEntry_t *listEntry;
    if (get_all_transaction->transactions) {
        list_ForEach(listEntry, get_all_transaction->transactions) {
            get_one_transaction_free(listEntry->data);
        }
        list_freeList(get_all_transaction->transactions);
        get_all_transaction->transactions = NULL;
    }
    free(get_all_transaction);
}

cJSON *get_all_transaction_convertToJSON(get_all_transaction_t *get_all_transaction) {
    cJSON *item = cJSON_CreateObject();

    // get_all_transaction->transactions
    if (!get_all_transaction->transactions) {
        goto fail;
    }
    cJSON *transactions = cJSON_AddArrayToObject(item, "transactions");
    if(transactions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transactionsListEntry;
    if (get_all_transaction->transactions) {
    list_ForEach(transactionsListEntry, get_all_transaction->transactions) {
    cJSON *itemLocal = get_one_transaction_convertToJSON(transactionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(transactions, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_all_transaction_t *get_all_transaction_parseFromJSON(cJSON *get_all_transactionJSON){

    get_all_transaction_t *get_all_transaction_local_var = NULL;

    // define the local list for get_all_transaction->transactions
    list_t *transactionsList = NULL;

    // get_all_transaction->transactions
    cJSON *transactions = cJSON_GetObjectItemCaseSensitive(get_all_transactionJSON, "transactions");
    if (!transactions) {
        goto end;
    }

    
    cJSON *transactions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(transactions)){
        goto end; //nonprimitive container
    }

    transactionsList = list_createList();

    cJSON_ArrayForEach(transactions_local_nonprimitive,transactions )
    {
        if(!cJSON_IsObject(transactions_local_nonprimitive)){
            goto end;
        }
        get_one_transaction_t *transactionsItem = get_one_transaction_parseFromJSON(transactions_local_nonprimitive);

        list_addElement(transactionsList, transactionsItem);
    }


    get_all_transaction_local_var = get_all_transaction_create (
        transactionsList
        );

    return get_all_transaction_local_var;
end:
    if (transactionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, transactionsList) {
            get_one_transaction_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(transactionsList);
        transactionsList = NULL;
    }
    return NULL;

}
