/*
 * validation_error_loc_inner.h
 *
 * 
 */

#ifndef _validation_error_loc_inner_H_
#define _validation_error_loc_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct validation_error_loc_inner_t validation_error_loc_inner_t;




typedef struct validation_error_loc_inner_t {

} validation_error_loc_inner_t;

validation_error_loc_inner_t *validation_error_loc_inner_create(
);

void validation_error_loc_inner_free(validation_error_loc_inner_t *validation_error_loc_inner);

validation_error_loc_inner_t *validation_error_loc_inner_parseFromJSON(cJSON *validation_error_loc_innerJSON);

cJSON *validation_error_loc_inner_convertToJSON(validation_error_loc_inner_t *validation_error_loc_inner);

#endif /* _validation_error_loc_inner_H_ */

