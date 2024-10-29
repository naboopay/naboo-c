#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_transaction_response.h"



delete_transaction_response_t *delete_transaction_response_create(
    char *order_id,
    char *message
    ) {
    delete_transaction_response_t *delete_transaction_response_local_var = malloc(sizeof(delete_transaction_response_t));
    if (!delete_transaction_response_local_var) {
        return NULL;
    }
    delete_transaction_response_local_var->order_id = order_id;
    delete_transaction_response_local_var->message = message;

    return delete_transaction_response_local_var;
}


void delete_transaction_response_free(delete_transaction_response_t *delete_transaction_response) {
    if(NULL == delete_transaction_response){
        return ;
    }
    listEntry_t *listEntry;
    if (delete_transaction_response->order_id) {
        free(delete_transaction_response->order_id);
        delete_transaction_response->order_id = NULL;
    }
    if (delete_transaction_response->message) {
        free(delete_transaction_response->message);
        delete_transaction_response->message = NULL;
    }
    free(delete_transaction_response);
}

cJSON *delete_transaction_response_convertToJSON(delete_transaction_response_t *delete_transaction_response) {
    cJSON *item = cJSON_CreateObject();

    // delete_transaction_response->order_id
    if (!delete_transaction_response->order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_id", delete_transaction_response->order_id) == NULL) {
    goto fail; //String
    }


    // delete_transaction_response->message
    if (!delete_transaction_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", delete_transaction_response->message) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_transaction_response_t *delete_transaction_response_parseFromJSON(cJSON *delete_transaction_responseJSON){

    delete_transaction_response_t *delete_transaction_response_local_var = NULL;

    // delete_transaction_response->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(delete_transaction_responseJSON, "order_id");
    if (!order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(order_id))
    {
    goto end; //String
    }

    // delete_transaction_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(delete_transaction_responseJSON, "message");
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }


    delete_transaction_response_local_var = delete_transaction_response_create (
        strdup(order_id->valuestring),
        strdup(message->valuestring)
        );

    return delete_transaction_response_local_var;
end:
    return NULL;

}
