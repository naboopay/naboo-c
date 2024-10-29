#ifndef cash_out_response_TEST
#define cash_out_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cash_out_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cash_out_response.h"
cash_out_response_t* instantiate_cash_out_response(int include_optional);



cash_out_response_t* instantiate_cash_out_response(int include_optional) {
  cash_out_response_t* cash_out_response = NULL;
  if (include_optional) {
    cash_out_response = cash_out_response_create(
      "0",
      56,
      "0",
      nabooapi_v1_cash_out_response__pending
    );
  } else {
    cash_out_response = cash_out_response_create(
      "0",
      56,
      "0",
      nabooapi_v1_cash_out_response__pending
    );
  }

  return cash_out_response;
}


#ifdef cash_out_response_MAIN

void test_cash_out_response(int include_optional) {
    cash_out_response_t* cash_out_response_1 = instantiate_cash_out_response(include_optional);

	cJSON* jsoncash_out_response_1 = cash_out_response_convertToJSON(cash_out_response_1);
	printf("cash_out_response :\n%s\n", cJSON_Print(jsoncash_out_response_1));
	cash_out_response_t* cash_out_response_2 = cash_out_response_parseFromJSON(jsoncash_out_response_1);
	cJSON* jsoncash_out_response_2 = cash_out_response_convertToJSON(cash_out_response_2);
	printf("repeating cash_out_response:\n%s\n", cJSON_Print(jsoncash_out_response_2));
}

int main() {
  test_cash_out_response(1);
  test_cash_out_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // cash_out_response_MAIN
#endif // cash_out_response_TEST
