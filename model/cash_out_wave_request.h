/*
 * cash_out_wave_request.h
 *
 * 
 */

#ifndef _cash_out_wave_request_H_
#define _cash_out_wave_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cash_out_wave_request_t cash_out_wave_request_t;




typedef struct cash_out_wave_request_t {
    char *full_name; // string
    int amount; //numeric
    char *phone_number; // string

} cash_out_wave_request_t;

cash_out_wave_request_t *cash_out_wave_request_create(
    char *full_name,
    int amount,
    char *phone_number
);

void cash_out_wave_request_free(cash_out_wave_request_t *cash_out_wave_request);

cash_out_wave_request_t *cash_out_wave_request_parseFromJSON(cJSON *cash_out_wave_requestJSON);

cJSON *cash_out_wave_request_convertToJSON(cash_out_wave_request_t *cash_out_wave_request);

#endif /* _cash_out_wave_request_H_ */

