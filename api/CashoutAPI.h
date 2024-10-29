#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/cash_out_orange_request.h"
#include "../model/cash_out_response.h"
#include "../model/cash_out_wave_request.h"
#include "../model/http_validation_error.h"


// Cash Out Orange Money
//
// This endpoint enables a user to withdraw funds from their NabooPay account to their Orange Money account. Authentication is required, and users with the 'dev' role are not permitted to perform this operation. The amount to be withdrawn must be positive and within the user's available balance. The user's account must be active and registered in the system. After validation, the user's account balance is adjusted accordingly, and the transaction is logged for record-keeping.
//
cash_out_response_t*
CashoutAPI_cashOutOrangeMoneyCashoutOrangeMoneyPost(apiClient_t *apiClient, cash_out_orange_request_t *cash_out_orange_request);


// Cash Out Wave
//
// This endpoint allows a user to withdraw funds from their NabooPay account to their Wave account. The user must be authenticated and not possess the 'dev' role. The withdrawal amount must be greater than 10 and not exceed the user's account balance. The user's account must exist and be active. Upon successful validation, the system updates the user's account balance and records the transaction for tracking purposes.
//
cash_out_response_t*
CashoutAPI_cashOutWaveCashoutWavePost(apiClient_t *apiClient, cash_out_wave_request_t *cash_out_wave_request);


