#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "http_validation_error.h"



http_validation_error_t *http_validation_error_create(
    list_t *detail
    ) {
    http_validation_error_t *http_validation_error_local_var = malloc(sizeof(http_validation_error_t));
    if (!http_validation_error_local_var) {
        return NULL;
    }
    http_validation_error_local_var->detail = detail;

    return http_validation_error_local_var;
}


void http_validation_error_free(http_validation_error_t *http_validation_error) {
    if(NULL == http_validation_error){
        return ;
    }
    listEntry_t *listEntry;
    if (http_validation_error->detail) {
        list_ForEach(listEntry, http_validation_error->detail) {
            validation_error_free(listEntry->data);
        }
        list_freeList(http_validation_error->detail);
        http_validation_error->detail = NULL;
    }
    free(http_validation_error);
}

cJSON *http_validation_error_convertToJSON(http_validation_error_t *http_validation_error) {
    cJSON *item = cJSON_CreateObject();

    // http_validation_error->detail
    if(http_validation_error->detail) {
    cJSON *detail = cJSON_AddArrayToObject(item, "detail");
    if(detail == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *detailListEntry;
    if (http_validation_error->detail) {
    list_ForEach(detailListEntry, http_validation_error->detail) {
    cJSON *itemLocal = validation_error_convertToJSON(detailListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(detail, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

http_validation_error_t *http_validation_error_parseFromJSON(cJSON *http_validation_errorJSON){

    http_validation_error_t *http_validation_error_local_var = NULL;

    // define the local list for http_validation_error->detail
    list_t *detailList = NULL;

    // http_validation_error->detail
    cJSON *detail = cJSON_GetObjectItemCaseSensitive(http_validation_errorJSON, "detail");
    if (detail) { 
    cJSON *detail_local_nonprimitive = NULL;
    if(!cJSON_IsArray(detail)){
        goto end; //nonprimitive container
    }

    detailList = list_createList();

    cJSON_ArrayForEach(detail_local_nonprimitive,detail )
    {
        if(!cJSON_IsObject(detail_local_nonprimitive)){
            goto end;
        }
        validation_error_t *detailItem = validation_error_parseFromJSON(detail_local_nonprimitive);

        list_addElement(detailList, detailItem);
    }
    }


    http_validation_error_local_var = http_validation_error_create (
        detail ? detailList : NULL
        );

    return http_validation_error_local_var;
end:
    if (detailList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, detailList) {
            validation_error_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(detailList);
        detailList = NULL;
    }
    return NULL;

}
