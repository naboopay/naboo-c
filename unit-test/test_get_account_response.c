#ifndef get_account_response_TEST
#define get_account_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_account_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_account_response.h"
get_account_response_t* instantiate_get_account_response(int include_optional);



get_account_response_t* instantiate_get_account_response(int include_optional) {
  get_account_response_t* get_account_response = NULL;
  if (include_optional) {
    get_account_response = get_account_response_create(
      "0",
      1.337,
      1,
      nabooapi_v1_get_account_response__WAVE,
      56
    );
  } else {
    get_account_response = get_account_response_create(
      "0",
      1.337,
      1,
      nabooapi_v1_get_account_response__WAVE,
      56
    );
  }

  return get_account_response;
}


#ifdef get_account_response_MAIN

void test_get_account_response(int include_optional) {
    get_account_response_t* get_account_response_1 = instantiate_get_account_response(include_optional);

	cJSON* jsonget_account_response_1 = get_account_response_convertToJSON(get_account_response_1);
	printf("get_account_response :\n%s\n", cJSON_Print(jsonget_account_response_1));
	get_account_response_t* get_account_response_2 = get_account_response_parseFromJSON(jsonget_account_response_1);
	cJSON* jsonget_account_response_2 = get_account_response_convertToJSON(get_account_response_2);
	printf("repeating get_account_response:\n%s\n", cJSON_Print(jsonget_account_response_2));
}

int main() {
  test_get_account_response(1);
  test_get_account_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_account_response_MAIN
#endif // get_account_response_TEST
