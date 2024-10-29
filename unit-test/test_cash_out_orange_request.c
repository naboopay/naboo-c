#ifndef cash_out_orange_request_TEST
#define cash_out_orange_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cash_out_orange_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cash_out_orange_request.h"
cash_out_orange_request_t* instantiate_cash_out_orange_request(int include_optional);



cash_out_orange_request_t* instantiate_cash_out_orange_request(int include_optional) {
  cash_out_orange_request_t* cash_out_orange_request = NULL;
  if (include_optional) {
    cash_out_orange_request = cash_out_orange_request_create(
      "0",
      56,
      "0"
    );
  } else {
    cash_out_orange_request = cash_out_orange_request_create(
      "0",
      56,
      "0"
    );
  }

  return cash_out_orange_request;
}


#ifdef cash_out_orange_request_MAIN

void test_cash_out_orange_request(int include_optional) {
    cash_out_orange_request_t* cash_out_orange_request_1 = instantiate_cash_out_orange_request(include_optional);

	cJSON* jsoncash_out_orange_request_1 = cash_out_orange_request_convertToJSON(cash_out_orange_request_1);
	printf("cash_out_orange_request :\n%s\n", cJSON_Print(jsoncash_out_orange_request_1));
	cash_out_orange_request_t* cash_out_orange_request_2 = cash_out_orange_request_parseFromJSON(jsoncash_out_orange_request_1);
	cJSON* jsoncash_out_orange_request_2 = cash_out_orange_request_convertToJSON(cash_out_orange_request_2);
	printf("repeating cash_out_orange_request:\n%s\n", cJSON_Print(jsoncash_out_orange_request_2));
}

int main() {
  test_cash_out_orange_request(1);
  test_cash_out_orange_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // cash_out_orange_request_MAIN
#endif // cash_out_orange_request_TEST
