/*
 * product_model.h
 *
 * 
 */

#ifndef _product_model_H_
#define _product_model_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct product_model_t product_model_t;




typedef struct product_model_t {
    char *name; // string
    char *category; // string
    int amount; //numeric
    int quantity; //numeric
    char *description; // string

} product_model_t;

product_model_t *product_model_create(
    char *name,
    char *category,
    int amount,
    int quantity,
    char *description
);

void product_model_free(product_model_t *product_model);

product_model_t *product_model_parseFromJSON(cJSON *product_modelJSON);

cJSON *product_model_convertToJSON(product_model_t *product_model);

#endif /* _product_model_H_ */

