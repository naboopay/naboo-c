#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "validation_error_loc_inner.h"



validation_error_loc_inner_t *validation_error_loc_inner_create(
    ) {
    validation_error_loc_inner_t *validation_error_loc_inner_local_var = malloc(sizeof(validation_error_loc_inner_t));
    if (!validation_error_loc_inner_local_var) {
        return NULL;
    }

    return validation_error_loc_inner_local_var;
}


void validation_error_loc_inner_free(validation_error_loc_inner_t *validation_error_loc_inner) {
    if(NULL == validation_error_loc_inner){
        return ;
    }
    listEntry_t *listEntry;
    free(validation_error_loc_inner);
}

cJSON *validation_error_loc_inner_convertToJSON(validation_error_loc_inner_t *validation_error_loc_inner) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

validation_error_loc_inner_t *validation_error_loc_inner_parseFromJSON(cJSON *validation_error_loc_innerJSON){

    validation_error_loc_inner_t *validation_error_loc_inner_local_var = NULL;


    validation_error_loc_inner_local_var = validation_error_loc_inner_create (
        );

    return validation_error_loc_inner_local_var;
end:
    return NULL;

}
