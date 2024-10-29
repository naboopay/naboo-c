#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_transaction_request.h"



delete_transaction_request_t *delete_transaction_request_create(
    char *order_id
    ) {
    delete_transaction_request_t *delete_transaction_request_local_var = malloc(sizeof(delete_transaction_request_t));
    if (!delete_transaction_request_local_var) {
        return NULL;
    }
    delete_transaction_request_local_var->order_id = order_id;

    return delete_transaction_request_local_var;
}


void delete_transaction_request_free(delete_transaction_request_t *delete_transaction_request) {
    if(NULL == delete_transaction_request){
        return ;
    }
    listEntry_t *listEntry;
    if (delete_transaction_request->order_id) {
        free(delete_transaction_request->order_id);
        delete_transaction_request->order_id = NULL;
    }
    free(delete_transaction_request);
}

cJSON *delete_transaction_request_convertToJSON(delete_transaction_request_t *delete_transaction_request) {
    cJSON *item = cJSON_CreateObject();

    // delete_transaction_request->order_id
    if (!delete_transaction_request->order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_id", delete_transaction_request->order_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_transaction_request_t *delete_transaction_request_parseFromJSON(cJSON *delete_transaction_requestJSON){

    delete_transaction_request_t *delete_transaction_request_local_var = NULL;

    // delete_transaction_request->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(delete_transaction_requestJSON, "order_id");
    if (!order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(order_id))
    {
    goto end; //String
    }


    delete_transaction_request_local_var = delete_transaction_request_create (
        strdup(order_id->valuestring)
        );

    return delete_transaction_request_local_var;
end:
    return NULL;

}
